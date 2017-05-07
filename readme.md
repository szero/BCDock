BCDock
======
This is a binary-coded-decimal clock made in ncurses. 
Intended purpouse is to run it as a widged in terminal that is constantly on desktop, 
but do whatever you want with it.

Dependencies
------------
* libncurses5-dev

Installation
------------
* Create objects and binary by typing `make`. Type `sudo make install` to install into 
`/usr/local/bin`
* Uninstall by typing `sudo make uninstall`
* Remove objects and binary by typing `make clean`

Usage
-----
* Start with no parameters to use default terminal colors for clock.
* Possible start parameters `-bk`,`-rd`,`-gr`,`-yl`,`-bl`,`-mg`,`-cy`,`-wh`
* Exit by pressing `Q`
