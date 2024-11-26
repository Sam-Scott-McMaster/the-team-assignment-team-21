#include <gtk/gtk.h>
#include "GameLogic.h"

#define HEIGHT 6
#define WIDTH 7

int player = 1;
int **game_board;
GtkWidget *label;

void quit(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void place_piece(GtkWidget *widget, gpointer data){
    //holds the value of which column was selected
    int column = GPOINTER_TO_INT(data);

    //updates the array game_board
    //printf("%d\n", column); debugging
    int placement_height = 0;
    int hide_button = 0;
    game_board = updateGameBoard(column, player, game_board, &hide_button, &placement_height);
    playerSelection(&player);
    /*for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",game_board[j][k]);
        }
        printf("\n");
    } debugging*/
    
    char player_text[50];

    // Format the string to display the player
    snprintf(player_text, sizeof(player_text), "Player %d", player);

    // Set the label text to the formatted player text
    gtk_label_set_text(GTK_LABEL(label), player_text);

    if (hide_button == 1) {
        //hides button with full collumn
    }
}

//this function makes the game board itself, creating the window
void create_game_board(){
    game_board = createGameBoard();
    //creating a new window, requires new variables
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *board_grid;

    //creating the window using the init, but no arguments passed
    gtk_init(NULL, NULL);

    //create game board window just like the main menu, same proccess
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Connect Four");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //for fullscreen effect
    gtk_window_fullscreen(GTK_WINDOW(window));

    //this is the grid that is used to organize the board
    grid = gtk_grid_new();
    //formatting the main grid, vertically and horizontally
    gtk_widget_set_halign(grid, GTK_ALIGN_FILL); 
    gtk_widget_set_valign(grid, GTK_ALIGN_FILL); 
    gtk_widget_set_hexpand(grid, TRUE);
    gtk_widget_set_vexpand(grid, TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);

    //Quit game button
    GtkWidget *quit_button = gtk_button_new_with_label("Quit Game");
    gtk_widget_set_halign(quit_button, GTK_ALIGN_START);
    gtk_widget_set_valign(quit_button, GTK_ALIGN_START);
    g_signal_connect(quit_button, "clicked", G_CALLBACK(quit), NULL);
    gtk_grid_attach(GTK_GRID(grid), quit_button, 0, 0, 1, 1);


    //for player turn displayer
    label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), ("<span font='20'>Player 1</span>"));
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(label, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    //creating a grid to hold the 7 buttons at the top that the user can interact with
    GtkWidget *placement_button_grid = gtk_grid_new();
    //just allignment statements
    gtk_widget_set_hexpand(placement_button_grid, TRUE);
    gtk_widget_set_halign(placement_button_grid, GTK_ALIGN_FILL);
    gtk_widget_set_valign(placement_button_grid, GTK_ALIGN_START);
    //these are to make sure each row and column is allocated equal amounts of space on the grid
    gtk_grid_set_row_homogeneous(GTK_GRID(placement_button_grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(placement_button_grid), TRUE);
    //for spacing between the buttons.
    gtk_grid_set_column_spacing(GTK_GRID(placement_button_grid), 10);
    //adding the grid to the main grid
    gtk_grid_attach(GTK_GRID(grid), placement_button_grid, 0, 1, 1, 1);

    //a for loop to create the 7 buttons at the top
    for(int col = 0; col < 7; col++){

        //the button has a label with what column it places it in
        GtkWidget *button = gtk_button_new_with_label(g_strdup_printf("%d", col + 1));

        //calls the function to place a piece if the button is clicked, sends the column its clicked on
        g_signal_connect(button, "clicked", G_CALLBACK(place_piece), GINT_TO_POINTER(col));

        //buttons can expand
        gtk_widget_set_hexpand(button, TRUE);

        //attaching said button to the button panel
        gtk_grid_attach(GTK_GRID(placement_button_grid), button, col, 0, 1, 1);

    }

    //creating the grid that serves as the visual for the game board itself
    board_grid = gtk_grid_new();
    //more formatting
    gtk_widget_set_hexpand(board_grid, TRUE);
    gtk_widget_set_vexpand(board_grid, TRUE);
    gtk_widget_set_halign(board_grid, GTK_ALIGN_FILL);
    gtk_widget_set_valign(board_grid, GTK_ALIGN_FILL);
    //these are to make sure each row and column is allocated equal amounts of space on the grid
    gtk_grid_set_row_homogeneous(GTK_GRID(board_grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(board_grid), TRUE);

    //spacing between rows and columns
    gtk_grid_set_row_spacing(GTK_GRID(board_grid), 5); 
    gtk_grid_set_column_spacing(GTK_GRID(board_grid), 5); 

    //adding the board to the main grid to display taking up 75% of the screen
    gtk_grid_attach(GTK_GRID(grid), board_grid, 0, 2, 1, 1);
    gtk_widget_set_size_request(board_grid, 800, 450);

    //adding frames to act as the spaces where are playable
    for(int row = 0; row < 6; row++){
        for(int col = 0; col < 7; col++){

            GtkWidget *position = gtk_frame_new(NULL);
            gtk_widget_set_size_request(position, 30, 30);
            gtk_widget_set_name(position, "position");
            gtk_grid_attach(GTK_GRID(board_grid), position, col, row, 1, 1);

        }
    }

    //showing the game board window
    gtk_widget_show_all(window);

    //running the gtk main loop
    gtk_main();
}