**#Tic-Tac-Toe**

This repo contains a the classic Tic-Tac-Toe gmae on terminal, written in C. 
The game is played between two players, (no machine v player). The screen contains 5 grids so you can play best of 5, but the game can be continued even after 5 times.
There is even a scorecard to count the wins of each player.
Press hold any key to enter into the game.(It actually is a bug. More down below.)

##Implementation details
The program is written is pure C. The only external library used is `ncurses`. `stdlib` and `stdio` are the other library used.
Each grid is locked into a paticular range of rows and coloums. The range of this rows and coloumns is determined by the max rows and columns.
First the range of middle grid is calculated and then a constant value is added, to calculate and fix other grids' rows and columns

A 3x3 2d array is used to record player moves.This array is reset every time the match ends.

##Installation
Recommeded to use gcc complier. Not tested on other compilers.

###First install the ncurses library.

For linux users intsallation is fairly simple. Use your package manager to install ncurses library. For example:
`sudo apt install ncurses`
Note: package name may vary for different package managers.

For windows users this is a bit tricky.
You may download the ncurses library from [here](url), unzip it. Alternatively you can use the ncurses folder provided from this repo to do the below steps.
Place the bin folder's files in your complier's bin folder. For example if you use MingW complier `C:\MinGW\bin` folder.
Similary place lib folder's file in compiler's lib folder
Finally place `ncursesw` folder into compiler's include folder.

Note `#include` ncurses for windows and linux are diffrent.

###Clone this repo
Change directory into the cloned repo
Compile all the files in the repo and dont forget to add `-lncurses` option in case of linux envand `-lncursesw` in case of windows.

###Execute the compiled program.

Note: Ncurses library for windows has a problem. Refer this [post](https://stackoverflow.com/questions/67656787/cannot-static-link-ncurses-with-mingw).
TL;DR
Add one more option `-DNCURSES_STATIC` if there is error.

##Problems and Bugs
-As mentioned above since the grid's are fixed in screen this causes a bug when screen is resized(zoomed in or out)
-Not fully compatible with other os.(Developed in windows)
-Original version had a dependency of `conio.h` a DOS header file. So not compitable with linux systems. So the intro animaation is erratic.(Anyone any idea to solve this?)

##TODO
-Add a cmake file
-Restrict user from resizing screen
-Add a feature to let user change the max rows and columns, so to fit their screen perfectly
