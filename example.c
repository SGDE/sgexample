#include <gtk/gtk.h>

void on_submenu_item_selected(GtkMenuItem *menuitem, gpointer userdata)
{
	g_print("%s was selected\n", gtk_menu_item_get_label(menuitem));
}

void on_submenu_item2_toggled(GtkCheckMenuItem *menu_item, GtkWidget *scacombo)
{
	if (gtk_check_menu_item_get_active(menu_item))
	{
		// Checkbox is checked, show the combo box
		g_print("Checkbox is checked\n");
		gtk_widget_show(scacombo);
	} 
	else 
	{
		// Checkbox is unchecked, hide the combo box
		g_print("Checkbox is unchecked\n");
		gtk_widget_hide(scacombo);
	}
}

void on_testetr_clicked(GtkCheckMenuItem *menu_item, GtkWidget *scacombo)
{
		gtk_main_quit();
}

int main(int argc, char *argv[])
{

int nocsd = 0;

for(int i = 1; i < argc; i++)
{
	if(strcmp(argv[i], "--nocsd")== 0)
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

	// Create the submenu items
	GtkWidget *submenu_item1 = gtk_menu_item_new_with_label("1.- This is a Option");
	GtkWidget *submenu_item2 = gtk_check_menu_item_new_with_label("2.- This is a \"Checkbox \" option");
	GtkWidget *submenu_item3 = gtk_menu_item_new_with_label("About");

	// Add the submenu items to the submenu
	gtk_menu_shell_append(GTK_MENU_SHELL(submenu), submenu_item1);
	gtk_menu_shell_append(GTK_MENU_SHELL(submenu), submenu_item2);
	gtk_menu_shell_append(GTK_MENU_SHELL(submenu), submenu_item3);

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
	
		GtkWidget *testcombo = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(testcombo), "A");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(testcombo), "B");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(testcombo), "C");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(testcombo), "D");
	
	   /// Widgets
	
	GtkWidget *testetr = gtk_entry_new();
		
	GtkWidget *testchk0 = gtk_check_button_new(); 
	GtkWidget *testchk1 =  gtk_check_button_new();
	GtkWidget *testchk2 =  gtk_check_button_new(); 
		
	GtkWidget *testbtn    = gtk_button_new_with_label("gtk_button_with_label");

	

	gtk_combo_box_set_active(GTK_COMBO_BOX(testcombo), 0);

	//Items Grid position
	

	gtk_grid_attach(GTK_GRID(grid), testetr, 1, 2, 1, 1);


 
	gtk_grid_attach(GTK_GRID(grid), testchk0, 1, 4, 1, 1);
 
	gtk_grid_attach(GTK_GRID(grid), testchk1,   1, 5, 1, 1);
	

	gtk_grid_attach(GTK_GRID(grid), testchk2,   1, 6, 1, 1);
	
	gtk_grid_attach(GTK_GRID(grid), testbtn,   0, 7, 1, 1);
	
	gtk_entry_set_placeholder_text(GTK_ENTRY(testetr), "this is a gtk_entry ");
	
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("gtk_label:"), 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), testcombo, 1, 0, 1, 1);


	// Connect the submenu items to the callback function
	g_signal_connect(submenu_item1, "activate", G_CALLBACK(on_submenu_item_selected), NULL);
	g_signal_connect(submenu_item1, "clicked", G_CALLBACK(on_testetr_clicked), NULL);
	g_signal_connect(submenu_item2, "toggled", G_CALLBACK(on_submenu_item2_toggled), testcombo);
	g_signal_connect(submenu_item3, "activate", G_CALLBACK(on_submenu_item_selected), NULL);

	// Show the main window and start the main loop
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
