#include <gtk/gtk.h>
#include <stdbool.h>
#include "GameLogic.h"
#include "check_win.h"
#include "win_screen.h"

#define HEIGHT 6
#define WIDTH 7

int player = 1;
int **game_board;
GtkWidget *label;
GtkWidget *window;
GtkWidget *frames[6][7];

//creating a button with CSS
GtkWidget* create_button(const gchar *label_text, const gchar *css_class, GCallback callback, gpointer data){
    GtkWidget *button = gtk_button_new();
    GtkWidget *label = gtk_label_new(NULL);

    //formatted text, passed through from the callback
    gchar *markup = g_strdup_printf("<span font='30'>%s</span>", label_text);
    gtk_label_set_markup(GTK_LABEL(label), markup);
    g_free(markup);

    gtk_container_add(GTK_CONTAINER(button), label);

    //adding the CSS to the button
    GtkStyleContext *context = gtk_widget_get_style_context(button);
    gtk_style_context_add_class(context, css_class);

    //the callback signal, with data passed through.
    g_signal_connect(button, "clicked", callback, data);

    return button;
}

//loading CSS (this is where the rules for CSS are)
void upload_css() {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);

    // Load CSS into the provider
    gtk_css_provider_load_from_data(provider,
        "button.blue-button {"
        "    background: #4682B4;" //backround colour is a blue, the number is a hex code
        "    color: white;" //chnages the text
        "    border: 2px solid #4682B4;" //changes the border of the buttons to blue as well from white
        "    border-radius: 10px;" //rounded corners
        "    padding: 10px;"
        "    box-shadow: none;" //stopping the button shadows
        "    background-image: none;"
        "}"
        "button.blue-button:hover {"
        "    background: #236ead;" //royal blue for hover colour
        "    border-color: #236ead;" //border colour on hover
        "    box-shadow: none;"  //no shadows effects on hover
        "}"
        ".player-label {"
        "    color: white;"  //this is for the main text to be white
        "}", -1, NULL);

    //add the CSS provider to the screen
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

void quit(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void place_piece(GtkWidget *widget, gpointer data){
    //holds the value of which column was selected
    int column = GPOINTER_TO_INT(data);
    GdkRGBA piece_color;

    //upload css
    upload_css();

    //updates the array game_board
    printf("%d\n", column); //debugging
    int placement_height = 0;
    int hide_button = 0;
    game_board = updateGameBoard(column, player, game_board, &hide_button, &placement_height);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",game_board[j][k]);
        }
        printf("\n");
    } //debugging

    if (player == 1) {
        gdk_rgba_parse (&piece_color, "yellow");
    } else {
        gdk_rgba_parse (&piece_color, "red");
    }
    gtk_widget_override_background_color (frames[HEIGHT-1-placement_height][column], GTK_STATE_NORMAL, &piece_color);

    //essentially this will disable the button and hide the label on it
    if (hide_button == 1) {
        gtk_widget_set_sensitive(widget, FALSE);
    }

    if (check_vertical(game_board, placement_height, column) == true) {
        printf("Player %d wins\n", player); //debugging
        gtk_widget_destroy(window);
        create_win_screen(player);
    } else if (check_horizontal(game_board, placement_height, column) == true) {
        printf("Player %d wins\n", player); //debugging
        gtk_widget_destroy(window);
        create_win_screen(player);
    } else if (check_diagonal_descending(game_board, placement_height, column) == true) {
        printf("Player %d wins\n", player); //debugging
        gtk_widget_destroy(window);
        create_win_screen(player);
    } else if (check_diagonal_ascending(game_board, placement_height, column) == true) {
        printf("Player %d wins\n", player); //debugging
        gtk_widget_destroy(window);
        create_win_screen(player);
    }

    playerSelection(&player);

    char player_text[50];

    // Format the string to display the player with CSS
    snprintf(player_text, sizeof(player_text), "<span font='20'>Player %d</span>", player);
    // Set the label text to the formatted player text
    gtk_label_set_markup(GTK_LABEL(label), player_text);
}

//this function makes the game board itself, creating the window
void create_game_board() {
    game_board = createGameBoard();
    //creating a new window, requires new variables
    GtkWidget *grid;
    GtkWidget *board_grid;
    GdkRGBA background_colour;

    //uploading css
    upload_css();

    gdk_rgba_parse(&background_colour, "#4682B4");

    //creating the window using the init, but no arguments passed
    gtk_init(NULL, NULL);

    //create game board window just like the main menu, same proccess
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Connect Four");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_override_background_color(window, GTK_STATE_NORMAL, &background_colour);
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
    GtkWidget *quit_button = create_button("Quit Game", "blue-button", G_CALLBACK(quit), NULL);
    gtk_widget_set_halign(quit_button, GTK_ALIGN_START);
    gtk_widget_set_valign(quit_button, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), quit_button, 0, 0, 1, 1);


    //for player turn displayer
    label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), ("<span font='20'>Player 1</span>"));
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(label, GTK_ALIGN_START);

    //applying CSS to the player text
    GtkStyleContext *label_context = gtk_widget_get_style_context(label);
    gtk_style_context_add_class(label_context, "player-label");


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
        //calls the function to place a piece if the button is clicked, sends the column its clicked on
        //this loop uses CSS to style the buttons
        GtkWidget *button = create_button(g_strdup_printf("%d", col + 1), "blue-button", G_CALLBACK(place_piece), GINT_TO_POINTER(col));

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
    for(int row = 0; row < 6; row++) {
        for(int col = 0; col < 7; col++) {
            GtkWidget *position = gtk_frame_new(NULL);
            gtk_widget_set_size_request(position, 30, 30);

            // Give each frame a unique name
            char frame_name[50];
            snprintf(frame_name, sizeof(frame_name), "position_%d_%d", row, col);
            gtk_widget_set_name(position, frame_name);

            // Attach the frame to the grid
            gtk_grid_attach(GTK_GRID(board_grid), position, col, row, 1, 1);

            // Store a reference to the frame in the 2D array
            frames[row][col] = position;
        }
    }

    //showing the game board window
    gtk_widget_show_all(window);

    //running the gtk main loop
    gtk_main();
}