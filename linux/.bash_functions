
# cd to clipboard
function cdc {
    CLIP="$(xclip -selection c -o)"
    cd "$CLIP"
}
