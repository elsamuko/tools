
# cd to clipboard
function cdc {
    local CLIP="$(xclip -selection c -o)"
    cd "$CLIP"
}

# cd to dolphin
function cdd {
    cd "$(~/bin/dolphloc.cpp)"
}

