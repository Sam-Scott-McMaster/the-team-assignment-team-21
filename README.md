# Connect Four

## Description

This application is a recreation of the popular game, Connect Four, using C with the GTK toolkit to create an interactive GUI.

Connect Four is a two-player turn-based game in which the players take turns "dropping" coloured pieces into a board containing six rows and seven columns. Each player is assigned a certain colour and the goal of the game is to connect four of the same coloured pieces in a row, either diagonally, vertically, or horizontally.

## Getting Started
### 1. Clone the Repository
```console
git clone https://github.com/Sam-Scott-McMaster/the-team-assignment-team-21.git
```

### 2. Installing GTK
The Connect Four game requires you to install GTK.

Run the following command in the Linux terminal:
```console
sudo apt install libgtk-3-dev
```

### 3. Generating the connect_4 Executable
Run the following command in the Linux terminal:
```console
make connect_4
```
Note: Ignore the warnings generated after executing the command. These warnings have no effect on the functionality of the game.

### 4. Launching the Game
Run the following command in the Linux terminal:
```console
./connect_4
```

## How to Play
### 1. Starting the Game
Click Start Game.

<img src="https://github.com/Sam-Scott-McMaster/the-team-assignment-team-21/blob/main/images/MenuScreenUpdated.jpg?raw=true" width=50%>

### 2. Placing a Piece
Click any of the buttons numbered 1 to 7 to place a piece in its respective column.
Hovering over the button highlights it.

<img src="https://github.com/Sam-Scott-McMaster/the-team-assignment-team-21/blob/main/images/PlayingGameUpdated.jpg?raw=true" width=50%>

### 3. How to Win
Each time a piece is placed, the player turn alternates. The goal of the game is for a player to connect four of their own pieces in a row, either diagonally, vertically, or horizontally.

### 4. Restarting the Game
On the win screen, click the Restart Game option.

<img src="https://github.com/Sam-Scott-McMaster/the-team-assignment-team-21/blob/main/images/EndScreenUpdated.jpg?raw=true" width=50%>

## Features
- Interactive GUI using GTK
- Hover effects for column buttons
- Restart functionality for continuous gameplay

## Credits
[Sameer Khichi](https://github.com/sameerkhichi)

[Josh Engel](https://github.com/Josh-Engel)

[Patrick Lee](https://github.com/leep48)