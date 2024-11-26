GameLogic: GameLogic.c
	gcc -o GameLogic GameLogic.c

connect_4: main_menu.c game_board.c game_board.h help_screen.c help_screen.h GameLogic.c GameLogic.h
	gcc main_menu.c game_board.c help_screen.c GameLogic.c -o connect_4 `pkg-config --cflags --libs gtk+-3.0`
