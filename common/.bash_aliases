
# formatting
alias tidy-xml='tidy -m -xml -indent'
alias tidy-html='tidy -m -w 200 -i'
alias tidy-json='python -m json.tool'

alias day='date +%F'
alias now='date +%T'
alias mini-server='python3 -m http.server'

alias st='git status'
alias last-tag='git describe --tags --abbrev=0'
alias last-commit='git rev-parse HEAD'
alias origin='git config --get remote.origin.url'

alias dc='cd'
