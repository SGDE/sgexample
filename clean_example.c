#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
int nocsd = 0;

for(int i = 1; i < argc; i++)
{
	if(strcmp(argv[i], "--nocsd") == 0)
	{
	nocsd = 1;
	printf("CSD Disabled, using fallback display \n");
	}
}

	gtk_init(&argc, &argv);


	// Create the main window
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "TestRoom");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	// Create the header bar
	GtkWidget *headerbar = gtk_header_bar_new();
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerbar), TRUE);
	
	// Create the button with an icon
	GtkWidget *button = gtk_menu_button_new();
	GtkWidget *wicon = gtk_image_new_from_icon_name("start-here", GTK_ICON_SIZE_BUTTON);
	gtk_container_add(GTK_CONTAINER(button), wicon);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), button);

	// Create the title
	GtkWidget *label = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label), "<b>Example - TestRoom</b>");
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), label);



	// Create the submenu
	GtkWidget *submenu = gtk_menu_new();


	// Show all the submenu items
	gtk_widget_show_all(submenu);

	// Connect the button to the submenu
	gtk_menu_button_set_popup(GTK_MENU_BUTTON(button), submenu);

	
	if (nocsd == 0 )
	{
	// Add the header bar to the main window
	gtk_window_set_titlebar(GTK_WINDOW(window), headerbar);
	}
	
	// Create grid
	GtkWidget *grid = gtk_grid_new();
	gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
	gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
	gtk_container_add(GTK_CONTAINER(window), grid);


	// Show the main window and start the main loop
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
