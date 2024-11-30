#include <gtk/gtk.h>
#include "help_screen.h"
#include "game_board.h"

//function that starts the game from the help screen
void begin_game(GtkWidget *widget, gpointer data) {
    GtkWidget *help_window = GTK_WIDGET(data);
    //closes the help screen window, then starts the game
    gtk_widget_destroy(help_window); 
    create_game_board(); 
}

//function that quits the game from the help screen
void prequit_game(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

//loading the CSS rules
void help_load_css(){
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);

    //these are the same rules from the other GUI screens
    gtk_css_provider_load_from_data(provider,
        "button.blue-button {"
        "    background: #4682B4;"
        "    color: white;"
        "    border: 2px solid #4682B4;"
        "    border-radius: 10px;"
        "    padding: 10px;"
        "    box-shadow: none;"
        "    background-image: none;"
        "}"
        "button.blue-button:hover {"
        "    background: #236ead;"
        "    border-color: #236ead;"
        "    box-shadow: none;"
        "}"
        ".welcome-label {"
        "    color: white;"
        "    font-size: 20px;" //text size for the labels
        "    margin: 10px;"    //adding some spacing
        "}", -1, NULL);

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

//creating a button with CSS
GtkWidget* button_style(const gchar *label_text, const gchar *css_class, GCallback callback, gpointer data) {
    GtkWidget *button = gtk_button_new_with_label(label_text);

    //applying the CSS rules to the button
    GtkStyleContext *context = gtk_widget_get_style_context(button);
    gtk_style_context_add_class(context, css_class);

    //the callback function that applies to when the button is clicked
    g_signal_connect(button, "clicked", callback, data);

    return button;
}

void create_help_screen(){
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label1, *label2, *label3, *label4;
    GtkWidget *help_quit_button;
    GtkWidget *help_start_button;
    GdkRGBA background_colour;

    gdk_rgba_parse(&background_colour, "#4682B4");

    gtk_init(NULL, NULL);

    //loading CSS for this function
    help_load_css();

    //create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Connect Four");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_maximize(GTK_WINDOW(window));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL, &background_colour);

    //creating a grid to format the labels
    grid = gtk_grid_new();
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(window), grid);

    //creating texts with labels
    label1 = gtk_label_new("Welcome to Connect Four!");
    label2 = gtk_label_new("Use the seven buttons at the top of the board to place a piece in that coresponding column.");
    label3 = gtk_label_new("The current players turn is displayed on the top of the screen.");
    label4 = gtk_label_new("Connect four of your pieces in a row either vertically, horizontally or diagonally.");

    //the labels are made with CSS
    GtkStyleContext *label1_context = gtk_widget_get_style_context(label1);
    gtk_style_context_add_class(label1_context, "welcome-label");

    GtkStyleContext *label2_context = gtk_widget_get_style_context(label2);
    gtk_style_context_add_class(label2_context, "welcome-label");

    GtkStyleContext *label3_context = gtk_widget_get_style_context(label3);
    gtk_style_context_add_class(label3_context, "welcome-label");

    GtkStyleContext *label4_context = gtk_widget_get_style_context(label4);
    gtk_style_context_add_class(label4_context, "welcome-label");

    //attatching the labels to the grid and formatting them correctly
    gtk_grid_attach(GTK_GRID(grid), label1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label2, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label3, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label4, 0, 3, 1, 1);

    //creating the button to quit the game, attatching it to the grid
    help_quit_button = button_style("Quit Game", "blue-button", G_CALLBACK(prequit_game), NULL);
    gtk_widget_set_size_request(help_quit_button, 200, 50);
    gtk_grid_attach(GTK_GRID(grid), help_quit_button, 0, 3, 1, 1);

    //creating the button to start the game and attatching it to the grid
    help_start_button = button_style("Start Game", "blue-button", G_CALLBACK(begin_game), window);
    gtk_widget_set_size_request(help_start_button, 200, 50);
    gtk_grid_attach(GTK_GRID(grid), help_start_button, 2, 3, 1, 1);

    gtk_widget_show_all(window);
   
    gtk_main();

    return 0;
}