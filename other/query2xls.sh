#!/usr/bin/env bash

# boss friendly data processing
# get data from a remote sql db and save it to a local xlsx file
# needs Python XlsxWriter
# http://xlsxwriter.readthedocs.org/en/latest/getting_started.html

# config
USER=
SERVER=
MYSQL_USER=
MYSQL_PW=
MYSQL_DB=

# sql query
QUERY=$(cat <<EOF
SELECT column_name1,column_name2
FROM table_name
EOF
)

# prepare
TODAY=$(date +20%y%m%d)
CSV="$TEMP/${TODAY}_query.csv"
XLS="$TEMP/${TODAY}_query.xlsx"

# get data from server
DATA=$(ssh "$USER@$SERVER" "echo \"$QUERY\" | mysql --user=\"$MYSQL_USER\" --password=\"$MYSQL_PW\" \"$MYSQL_DB\" --default-character-set=UTF8")
echo "$DATA" | tee /dev/tty | iconv  -f utf-8 -t iso-8859-1 | putclip
echo "$DATA" > "$CSV"

# convert to xlsx
ENCODER=$( cat <<EOF
# -*- coding: utf-8 -*-

import os
import glob
import csv
import sys
from xlsxwriter.workbook import Workbook

# fill new spreadsheet with data
csvfile = str( "$CSV" )
workbook = Workbook( "$XLS" )
worksheet = workbook.add_worksheet()
with open( csvfile, 'rb' ) as f:
    reader = csv.reader( f, delimiter='\t' )
    for r, row in enumerate( reader ):
        for c, col in enumerate( row ):
            worksheet.write( r+1, c+1, col.decode( 'utf-8' ) )

# set width of columns B-E
worksheet.set_column( 'B:B', 20 )
worksheet.set_column( 'C:C', 11 )
worksheet.set_column( 'D:D', 50 )
worksheet.set_column( 'E:E', 50 )

workbook.close()
EOF
)

python -c "$ENCODER"

