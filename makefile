connect_4: main_menu.c game_board.c game_board.h help_screen.c help_screen.h
	gcc main_menu.c game_board.c help_screen.c -o connect_4 `pkg-config --cflags --libs gtk+-3.0`
