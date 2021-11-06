
# cd to active Finder location
function cdf {
    local SCRIPT="tell application \"Finder\"
                if ( 1 <= (count Finder windows)) then
                    get POSIX path of (target of window 1 as alias)
                else
                    get POSIX path of (desktop as alias)
                end if
            end tell"

    local CURRENT_FOLDER=$(osascript -e "$SCRIPT")
    cd "$CURRENT_FOLDER"
}

# cd to clipboard
function cdc {
    local CLIP="$(pbpaste)"
    cd "$CLIP"
}

function locate {
    mdfind "kMDItemDisplayName == '$@'wc"
}
