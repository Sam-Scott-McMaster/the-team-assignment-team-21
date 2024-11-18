#include <gtk/gtk.h>

void start_game(GtkWidget *widget, gpointer data){
    //doesnt do anything for now
    //should contain a new window for the game board
}

void helpFlag(GtkWidget *widget, gpointer data){
    //doesnt do anything for now
    //should contain a new window with the help information
}

//quits the application
void quit_game(GtkWidget *widget, gpointer data){

    gtk_main_quit(); //just closes the program

}

int main(int argc, char *argv[]){

    //making a bunch of widgets for buttons, and text that will be on the main menu window
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *quit_button;
    GtkWidget *start_button;
    GtkWidget *help_button;
    //this grid is just to be able to place things in a structured order on the window
    GtkWidget *grid; 

    //initializing the window using the init function
    gtk_init(&argc, &argv);

    //making the new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Connect Four");
    //ends program when window closed
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //opens to a size then maximizes the window
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_maximize(GTK_WINDOW(window));

    //grid to arrange buttons and text
    grid = gtk_grid_new();
    //centering the grid vertically and horizontally
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(window), grid);

    //welcome text
    label = gtk_label_new(NULL);
    //this is just to make the font bigger
    gtk_label_set_markup(GTK_LABEL(label), "<span font='40'>Connect 4 - Main Menu</span>");
    //formatting the label
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_size_request(label, 200, 50); //min size for label
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 5, 1); //the title will span the entire column

    //adding empty row for spacing 
    GtkWidget *spacer = gtk_label_new(NULL); //this is just an empty label
    gtk_grid_attach(GTK_GRID(grid), spacer, 0, 2, 5, 1);

    //making the start game button
    start_button = gtk_button_new();
    GtkWidget *start_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(start_label), "<span font='30'>Start Game</span>");
    gtk_container_add(GTK_CONTAINER(start_button), start_label);

    g_signal_connect(start_button, "clicked", G_CALLBACK(start_game), NULL);

    gtk_widget_set_halign(start_button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(start_button, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(start_button, 600, 100); 
    gtk_grid_attach(GTK_GRID(grid), start_button, 2, 3, 1, 1); 

    //making the help button
    help_button = gtk_button_new();
    GtkWidget *help_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(help_label), "<span font='30'>How To Play</span>");
    gtk_container_add(GTK_CONTAINER(help_button), help_label);

    g_signal_connect(help_button, "clicked", G_CALLBACK(helpFlag), NULL);

    gtk_widget_set_halign(help_button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(help_button, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(help_button, 600, 100);
    gtk_grid_attach(GTK_GRID(grid), help_button, 2, 4, 1, 1); 



    //making the quit game button
    quit_button = gtk_button_new();
    GtkWidget *quit_label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(quit_label), "<span font='30'>Quit Game</span>");
    gtk_container_add(GTK_CONTAINER(quit_button), quit_label);

    g_signal_connect(quit_button, "clicked", G_CALLBACK(quit_game), NULL);

    gtk_widget_set_halign(quit_button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(quit_button, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(quit_button, 600, 100);
    gtk_grid_attach(GTK_GRID(grid), quit_button, 2, 5, 1, 1); 


    //making all widgets visible
    gtk_widget_show_all(window);

    //another gtk function
    //this function calls the main loop from gtk which lets the window listen for interaction
    gtk_main();

    return 0;
}