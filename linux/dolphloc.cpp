#!/usr/bin/env cppsh

//! /note This script returns the last location of KDE's dolphin

// cppsh::LIBS -lsqlite3

#include <iostream>
#include <sqlite3.h>

#define LOG( A ) std::cerr << A << std::endl;

std::string dbFilename() {
    char* home = getenv( "HOME" );

    if( home ) {
        return std::string( home ) + "/.kde/share/apps/activitymanager/resources/database";
    } else {
        return std::string();
    }
}

int callback( void* unused, int argc, char** argv, char** argn ) {

    if( argc && argv[0] ) {
        std::string loc( argv[0] );

        if( loc.size() > 7 ) {
            std::cout << loc.substr( 7 ) << std::endl;
        }
    }

    return 0;
};


int main() {

    std::string sql =   "SELECT targettedResource\n"
                        "FROM nuao_DesktopEvent\n"
                        "WHERE usedActivity == \"e8a0c6bd-30c6-4f80-8032-0d0b1b8dbc6f\"\n"
                        "AND initiatingAgent == \"dolphin\"\n"
                        "ORDER BY Start DESC\n"
                        "LIMIT 1";

    int status = SQLITE_OK;
    char* msg = 0;
    sqlite3* db = nullptr;

    // open db
    status = sqlite3_open( dbFilename().c_str(), &db );

    if( status != SQLITE_OK ) {
        LOG( "Can't open database: " << sqlite3_errmsg( db ) );
        return 0;
    }

    // execute query
    status = sqlite3_exec( db, sql.c_str(), callback, nullptr, &msg );

    if( status != SQLITE_OK ) {
        LOG( "Error : " << msg );
        sqlite3_free( msg );
        msg = 0;
    }

    sqlite3_close( db );

    return 0;
}
