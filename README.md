# Tetris
This is a **console** Tetris. Works on Linux and Windows operating systems.  
Linux screenshot:  
![alt text](/../<mater>Screenshots/TetriScreenLinux.png)
## How to install
To do :(
## How to start the game
You need to include a headers: "Tetris.h"(path: "src/Play/Tetris.h") and "GameMenu.h" (path: "src/Menu/GameMenu.h").   
**first way** (without menu) :Create a pointer of type Tetris. The game can be started without a menu by calling the play method(in parameters takes an integer as the difficulty level).  
**Another way**: create an object of the GameMenu and call the mainMenu method, in the parameters of which you need to pass a pointer to the Tetris.
## Game control
'A' - left,   
'S' - down,   
'D' - right,   
'Q' - inverse.  
## 



