#include <gtk/gtk.h>

//this function makes the game board itself, creating the window
void create_help_screen(){
   
    //creating a new window, requires new variables
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;

    //creating the window using the init, but no arguments passed
    gtk_init(NULL, NULL);
   
    //create game board window just like the main menu, same proccess
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Connect Four");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_maximize(GTK_WINDOW(window));

    //this is the grid that is used to organize the board
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), "<span font='40'>Connect Four in a row before your opponent\nDo This by connecting on a diagonal, vertical, or horizontal\nTo place a piece click on the corresponding collumns button</span>");
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(label, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    //showing the game board window
    gtk_widget_show_all(window);

    //running the gtk main loop
    gtk_main();
}
