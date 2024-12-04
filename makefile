connect_4: main_menu.c game_board.c game_board.h help_screen.c help_screen.h win_screen.c win_screen.h GameLogic.c GameLogic.h win_check_utilities.c check_win.h help.c help.h
	gcc main_menu.c game_board.c help_screen.c help.c win_screen.c GameLogic.c win_check_utilities.c -o connect_4 `pkg-config --cflags --libs gtk+-3.0`

coverageTest: main.c GameLogic.c  GameLogic.h
	gcc -o ctest --coverage main.c GameLogic.c

check: win_check_test.c win_check_utilities.c check_win.h
	gcc -o check win_check_test.c win_check_utilities.c

ctest: win_check_test.c win_check_utilitiesi.c check_win.h
	gcc -o ctest --coverage win_check_test.c win_check_utilities.c

clean:
	rm -f check ctest connect_4 *.gcda *.gcno *.gcov
