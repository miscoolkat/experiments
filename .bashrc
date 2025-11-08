# Exports
export PATH="$PATH:/usr/local/bin"

# some ls aliases
alias ll='ls -alF && echo "Total files: $(ls -1 | wc -l)"'
alias la='ls -A'
alias l='ls -alF && echo "Total files: $(ls -1 | wc -l)"'

# dir change aliases
alias apps='cd ~/Apps/'
alias tusse='cd /Users/cb/Apps/cbroberg/playwithmathilde/experiments'

# Misc aliases
alias cls='clear'
alias cl='clear'
alias c='clear'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi


# http://bashrcgenerator.com/

export PS1="\[\033[38;5;3m\]\u@\[$(tput sgr0)\]\[\033[38;5;13m\]\h\[$(tput sgr0)\]\[\033[38;5;2m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]> \[$(tput sgr0)\]"
export CLICOLOR=1
export LSCOLORS=cxfxcxdxbxegedabagacad

