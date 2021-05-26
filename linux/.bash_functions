
# cd to clipboard
function cdc {
    local CLIP="$(xclip -selection c -o)"
    cd "$CLIP"
}

