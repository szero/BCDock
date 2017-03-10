# BCDock
This is a binary-coded-decimal clock made in ncurses. Intended purpouse is to run it as a widged in terminal that is constantly on desktop, but do whatever you want with it.

# Dependencies
* libncurses5-dev

# Installation
* Install by typing `make install`. Installing with sudo puts binary into /usr/local/bin directory and without into current directory.
* Uninstall by typing `make remove` or `sudo make remove`.

# Usage
* Start with no parameters to use default terminal colors for clock.
* Possible start parameters `-bk`,`-rd`,`-gr`,`-yl`,`-bl`,`-mg`,`-cy`,`-wh`
* Exit by pressing `Q`
