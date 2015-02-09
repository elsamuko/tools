cde()
{
    read -d '' SCRIPT <<"EOF"
        # get explorer object
        $explorer = New-Object -com "Shell.Application"

        # sort explorer windows by Top value
        $windows = $explorer.windows() | Sort { $_.Top }
        $windows = $windows | ? {$_.LocationURL}

        # get location of topmost
        $location = $windows[-1].LocationURL

        # url decode
        [Reflection.Assembly]::LoadWithPartialName( "System.Web" ) | Out-Null
        $location = [web.httputility]::urldecode( $location )

        # remove "file:///"
        if( $location.StartsWith( "file:///" ) ) {
            Echo $location.Substring( 8 )
        } elseif ( $location.StartsWith( "file://" ) ) {
            Echo $location.Substring( 5 )
        } else {
            Echo $location
        }
EOF

    WLOC=$(powershell -Command "$SCRIPT")
    LOC=$(cygpath "$WLOC")
    cd "$LOC"
}

last-tag()
{
    git describe --tags $(git rev-list --tags --max-count=1) | tr -d '\n' | tee /dev/tty | putclip; echo
}
