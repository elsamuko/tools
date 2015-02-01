
# limit update speed to 1MBit and accept updates
alias upgrade='sudo apt-get update -o Acquire::http::Dl-Limit=1000 && echo "Y" | sudo apt-get dist-upgrade -o Acquire::http::Dl-Limit=1000'

# clipboard
alias getclip='xclip -selection c -o'
alias putclip='xclip -selection c -i'
alias pwd2clip="pwd | tr -d '\n' | xclip -selection c -i"

# system
alias hostkeyid='sudo ssh-keygen -l -f /etc/ssh/ssh_host_rsa_key'
