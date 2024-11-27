GameLogic: GameLogic.c
	gcc -o GameLogic GameLogic.c

connect_4: main_menu.c game_board.c game_board.h help_screen.c help_screen.h GameLogic.c GameLogic.h win_check_utilities.c check_win.h win_screen.c win_screen.h
	gcc main_menu.c game_board.c help_screen.c GameLogic.c win_check_utilities.c win_screen.c -o connect_4 `pkg-config --cflags --libs gtk+-3.0`

coverageTest: main.c GameLogic.c  GameLogic.h
	gcc -o ctest --coverage main.c GameLogic.c
