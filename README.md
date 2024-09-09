![Screenshot 2024-09-08 234924](https://github.com/user-attachments/assets/daef0a02-444f-461b-839e-90d0c5c856b8)
![Screenshot 2024-09-08 235042](https://github.com/user-attachments/assets/828bd9b7-b16f-4169-96be-a9d9edaee814)
![Screenshot 2024-09-08 235030](https://github.com/user-attachments/assets/3610e1ee-722a-4ea6-87da-3e6bc9f4669c)
![Screenshot 2024-09-08 234951](https://github.com/user-attachments/assets/e76acc1a-1071-45eb-8b46-ee3cfac586b6)
![Screenshot 2024-09-08 234931](https://github.com/user-attachments/assets/3b6ef1fe-00cb-4f02-b6fc-df00017a2ea3)
# **Tic-Tac-Toe**

This repo contains a the classic Tic-Tac-Toe gmae on terminal, written in C. 
The game is played between two players, (no machine v player). The screen contains 5 grids so you can play best of 5, but the game can be continued even after 5 times.
There is even a scorecard to count the wins of each player.
Press hold any key to enter into the game.(It actually is a bug. More down below.)

## Implementation details
The program is written is pure C. The only external library used is `ncurses`. `stdlib` and `stdio` are the other library used.
Each grid is locked into a paticular range of rows and coloums. The range of this rows and coloumns is determined by the max rows and columns.
First the range of middle grid is calculated and then a constant value is added, to calculate and fix other grids' rows and columns

A 3x3 2d array is used to record player moves.This array is reset every time the match ends.

## Installation and Running
Recommeded to use gcc complier. Not tested on other compilers.

### First install the ncurses library.

For linux users intsallation is fairly simple. Use your package manager to install ncurses library. For example:
`sudo apt install lib32ncursesw5`
Note: package name may vary for different package managers.

For windows users this is a bit tricky.
You may download the ncurses library from [here](url), unzip it. Alternatively you can use the ncurses folder provided from this repo to do the below steps.
Place the bin folder's files in your complier's bin folder. For example if you use MingW complier `C:\MinGW\bin` folder.
Similary place lib folder's file in compiler's lib folder
Finally place `ncursesw` folder into compiler's include folder.

Note `#include` ncurses for windows and linux are diffrent.

### Clone this repo
Change directory into the cloned repo
Compile all the files in the repo and dont forget to add `-lncurses` option in case of linux envand `-lncursesw` in case of windows.
This is what i use
`gcc main.c animation.h game_grid.h include.h menu.h message.h movement.h player_turn.h score_table.h -lncursesw -o a.exe`

### Execute the compiled program.

Note: Ncurses library for windows has a problem. Refer this [post](https://stackoverflow.com/questions/67656787/cannot-static-link-ncurses-with-mingw).

TL;DR

Add one more option `-DNCURSES_STATIC` if there is an error.

## Problems and Bugs
-As mentioned above since the grid's are fixed in screen this causes a bug when screen is resized(zoomed in or out)

-Not fully compatible with other os.(Developed in windows)

-Original version had a dependency of `conio.h` a DOS header file. So not compitable with linux systems. So the intro animaation is erratic.(Anyone any idea to solve this?)

## TODO
-Add a cmake file

-Restrict user from resizing screen

-Add a feature to let user change the max rows and columns, so to fit their screen perfectly

## Background
It all started when my friend and I were bored in class.

So we started playing tictactoe, but soon got bored of that too...
So i suggested why not just utilize our time and program a tictactoe game instead...(my friend looked at me funnily...that aside) that first thing he did was to ask
chatgpt how to program the game (yes chatgpt)....

Maybe if chatgpt had done a decent job of designing the game I would have not come down this rabbit hole of overengineered game....
Instead it gave a game that where player needs to enter the co-ordinates of the grid like 1, 1 (second row, second coloumn)...yes it was 0 indexed on user side...
This itself says lot about the output

So i took it upon myself to create this....and it was even my first relatively big scale project....and so there may be some unwise design choice...or not the best practice..
I Apologize for that.

But well this was a good experience for the days ahead...This helped me deeply understand C but still I can't say I have mastered it... especially where I was strugling to install ncurses on windows
(windows really is not for programing) I think i almost spent four hours doing it...Thankfully I saw the above mentioned post (btw answered by C guru) and didn't waste time figuring out what is wrong
with the lib...

**Even though with all of this C is and always be the programing language ever.**
