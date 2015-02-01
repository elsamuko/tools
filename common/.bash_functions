
# full posix path
function filename {
    echo $(cd $(dirname "$1"); pwd)/$(basename "$1");
}

# prepend argument to PATH
function add_to_path {
    if [ -d "$1" ]; then
        PATH="$1":$PATH
    else
        echo "Could not add $1 to path."
    fi
}
