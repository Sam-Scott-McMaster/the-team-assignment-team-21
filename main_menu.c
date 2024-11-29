#include <gtk/gtk.h>
#include "game_board.h"
#include "help_screen.h"

//start the game
void start_game(GtkWidget *widget, gpointer data){
    GtkWidget *main_menu_window = GTK_WIDGET(data);
    gtk_widget_destroy(main_menu_window);
    create_game_board();
}

//Help screen callback
void helpFlag(GtkWidget *widget, gpointer data){
    GtkWidget *main_menu_window = GTK_WIDGET(data);
    gtk_widget_destroy(main_menu_window);
    create_help_screen();
}

//quit game
void quit_game(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

//creating a button with CSS
GtkWidget* create_coloured_button(const gchar *label_text, const gchar *css_class, GCallback callback, gpointer data){
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
void load_css() {
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
        ".welcome-label {"
        "    color: white;"  //this is for the main text to be white
        "}", -1, NULL);

    //add the CSS provider to the screen
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

int main(int argc, char *argv[]){
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *grid;
    GtkWidget *start_button;
    GtkWidget *help_button;
    GtkWidget *quit_button;
    GtkWidget *spacer;
    GdkRGBA background_colour;

    gdk_rgba_parse(&background_colour, "#4682B4");

    //Initialize GTK
    gtk_init(&argc, &argv);

    // Load CSS
    load_css();

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Connect Four");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_maximize(GTK_WINDOW(window));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_override_background_color(window, GTK_STATE_NORMAL, &background_colour);

    //creating the gridd for the layout of the menu
    grid = gtk_grid_new();
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(window), grid);

    //welcome label
    label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), "<span font='40'>Connect 4 - Main Menu</span>");
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    //applying CSS to the welcome text
    GtkStyleContext *label_context = gtk_widget_get_style_context(label);
    gtk_style_context_add_class(label_context, "welcome-label");

    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 5, 1);

    //just a spcaer for formatting
    spacer = gtk_label_new(NULL);
    gtk_grid_attach(GTK_GRID(grid), spacer, 0, 2, 5, 1);

    //creating the buttons using CSS
    start_button = create_coloured_button("Start Game", "blue-button", G_CALLBACK(start_game), window);
    gtk_widget_set_size_request(start_button, 600, 100);
    gtk_grid_attach(GTK_GRID(grid), start_button, 2, 3, 1, 1);

    help_button = create_coloured_button("How To Play", "blue-button", G_CALLBACK(helpFlag), window);
    gtk_widget_set_size_request(help_button, 600, 100);
    gtk_grid_attach(GTK_GRID(grid), help_button, 2, 4, 1, 1);

    quit_button = create_coloured_button("Quit Game", "blue-button", G_CALLBACK(quit_game), NULL);
    gtk_widget_set_size_request(quit_button, 600, 100);
    gtk_grid_attach(GTK_GRID(grid), quit_button, 2, 5, 1, 1);

    //shows the widgets
    gtk_widget_show_all(window);
    //for CSS
    gtk_widget_queue_draw(window);

    //starting the main loop from gtk
    gtk_main();

    return 0;
}