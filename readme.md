#BCDock
This is a binary-coded-decimal clock made in ncurses. Intended purpouse is to run it as a widged in terminal that is constantly on desktop, but do whatever you want with it.

# Dependiencies

* libncurses5-dev

# Installation

* Install by typeing `sudo make`
* Uninstall by typeing `sudo make remove`
* Program installs in `/usr/local/bin`. This directory is in `$PATH` variable on most Linux systems. So you can run it from terminal by writing `BCDock` from any location.
# Usage

* Start as usual to use default terminal colors for clock.
* Possible start parameters `-bk`,`-rd`,`-gr`,`-yl`,`-bl`,`-mg`,`-cy`,`wh`
* Exit by pressing `Q`

## TODO

* Add date as start parameter
