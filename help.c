#include <gtk/gtk.h>
#include "help_screen.h"
#include "game_board.h"

//function that quits the game from the help screen
void prequit(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

//loading the CSS rules
void console_help_load_css(){
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
        "    font-size: 35px;" //font of the buttons
        "    margin: 40px;" //adding spacing between the buttons
        "}"
        "button.blue-button:hover {"
        "    background: #236ead;"
        "    border-color: #236ead;"
        "    box-shadow: none;"
        "}"
        ".welcome-label {"
        "    color: white;"
        "    font-size: 35px;" //text size for the labels
        "    margin: 20px;"    //adding some spacing
        "}", -1, NULL);

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

//creating a button with CSS
GtkWidget* console_button_style(const gchar *label_text, const gchar *css_class, GCallback callback, gpointer data) {
    GtkWidget *button = gtk_button_new_with_label(label_text);

    //applying the CSS rules to the button
    GtkStyleContext *context = gtk_widget_get_style_context(button);
    gtk_style_context_add_class(context, css_class);

    //the callback function that applies to when the button is clicked
    g_signal_connect(button, "clicked", callback, data);

    return button;
}

void create_help(){
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button_grid;
    GtkWidget *label1, *label2, *label3, *label4, *label5;
    GtkWidget *help_quit_button;
    GtkWidget *help_start_button;
    GdkRGBA background_colour;

    gdk_rgba_parse(&background_colour, "#4682B4");

    gtk_init(NULL, NULL);

    //loading CSS for this function
    console_help_load_css();

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

    //a new grid to hold the buttons for better formatting
    button_grid = gtk_grid_new();
    gtk_widget_set_halign(button_grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(button_grid, GTK_ALIGN_CENTER);
    gtk_grid_attach(GTK_GRID(grid), button_grid, 0, 6, 1, 1);

    //creating texts with labels
    label1 = gtk_label_new("connect_4 v2.0.2");
    label2 = gtk_label_new("Overview: This tool is used to play the popular game connect 4\n where you have to make 4 of your pieces connect in a row");
    label3 = gtk_label_new("Usage console: connect_4 launches the game connect_4 --help gives this screen");
    label4 = gtk_label_new("Usage in Gui: quit game button closes the gui, how to play button will describe\n the rules of connect 4, start game button pulls up game board");
    label5 = gtk_label_new("Usage how to play: click one of seven buttons in the game screen to place piece\n when one player wins you are taken to the win screen from where you can restart or quit");

    //the labels are made with CSS
    GtkStyleContext *label1_context = gtk_widget_get_style_context(label1);
    gtk_style_context_add_class(label1_context, "welcome-label");

    GtkStyleContext *label2_context = gtk_widget_get_style_context(label2);
    gtk_style_context_add_class(label2_context, "welcome-label");

    GtkStyleContext *label3_context = gtk_widget_get_style_context(label3);
    gtk_style_context_add_class(label3_context, "welcome-label");

    GtkStyleContext *label4_context = gtk_widget_get_style_context(label4);
    gtk_style_context_add_class(label4_context, "welcome-label");

    GtkStyleContext *label5_context = gtk_widget_get_style_context(label5);
    gtk_style_context_add_class(label5_context, "welcome-label");

    //attatching the labels to the grid and formatting them correctly
    gtk_grid_attach(GTK_GRID(grid), label1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label2, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label3, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label4, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label5, 0, 4, 1, 1);

    //adjusting the spacing between the rows and the columns
    gtk_grid_set_row_spacing(GTK_GRID(grid), 20); 
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20); 

    //creating the button to quit the game, attatching it to the grid
    help_quit_button = console_button_style("Quit", "blue-button", G_CALLBACK(prequit), NULL);
    gtk_widget_set_size_request(help_quit_button, 200, 50);
    gtk_grid_attach(GTK_GRID(button_grid), help_quit_button, 0, 6, 1, 1);

    gtk_widget_show_all(window);
   
    gtk_main();
}