#include "window.h"
#include "interface.h"

GtkWidget *Login = NULL;
GtkWidget *enregistrer = NULL;
GtkWidget *Citoyen = NULL;
GtkWidget *Moto = NULL;
GtkWidget *RS = NULL;
GtkWidget *Tun = NULL;
GtkWidget *mdp_oublie = NULL;
GtkWidget *Administrateur = NULL;

GtkWidget* current_window = NULL;


void set_window_colors(GtkWidget *widget, gpointer data) {
  GdkColor backgroundColor, fontColor, entryColor, entryTextColor, borderColor,
  buttonColor, hoverColor, frameColor, scrolledBarColor, treeviewColor, headerColor,
  headerBackgroundColor, checkboxColor, comboboxColor, insensitiveColor,
  notebookBackgroundColor, notebookTextColor;


  gdk_color_parse("#16161A", &backgroundColor);
  gdk_color_parse("#FFFFFE", &fontColor);
  gdk_color_parse("#72757E", &entryColor);
  gdk_color_parse("#FFFFFE", &entryTextColor);
  gdk_color_parse("#FFFFFF", &borderColor);
  gdk_color_parse("#7F5AF0", &buttonColor);
  gdk_color_parse("#7F5AF0", &hoverColor);
  gdk_color_parse("#7F5AF0", &frameColor);
  gdk_color_parse("#16161A", &scrolledBarColor);
  gdk_color_parse("#7F5AF0", &treeviewColor);
  gdk_color_parse("#7F5AF0", &headerColor);
  gdk_color_parse("#7F5AF0", &headerBackgroundColor);
  gdk_color_parse("#7F5AF0", &checkboxColor);
  gdk_color_parse("#7F5AF0", &comboboxColor);
  gdk_color_parse("#7F5AF0", &insensitiveColor);
  gdk_color_parse("#16161A", &notebookBackgroundColor);
  gdk_color_parse("#FFFFFE", &notebookTextColor);

  char *font_desc = "Courier New 9";
  PangoFontDescription *font = pango_font_description_from_string(font_desc);
  
  gtk_widget_modify_font(GTK_WIDGET(widget), font);
  
  
  if (GTK_IS_EVENT_BOX(widget)) {
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &backgroundColor);
  }

  if (GTK_IS_LABEL(widget)) {
    gtk_widget_modify_fg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &fontColor);
    gtk_widget_modify_font(GTK_WIDGET(widget), font);
  }

  if (GTK_IS_ENTRY(widget)) {
    gtk_widget_modify_base(GTK_WIDGET(widget), GTK_STATE_NORMAL, &entryColor);
    gtk_widget_modify_text(GTK_WIDGET(widget), GTK_STATE_NORMAL, &entryTextColor);
    gtk_widget_modify_base(GTK_WIDGET(widget), GTK_STATE_INSENSITIVE, &insensitiveColor);
    gtk_widget_modify_text(GTK_WIDGET(widget), GTK_STATE_INSENSITIVE, &entryTextColor);
  }

  if (GTK_IS_BUTTON(widget)) {
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &buttonColor);
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_INSENSITIVE, &insensitiveColor);
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_PRELIGHT, &hoverColor);
  }

  if (GTK_IS_CHECK_BUTTON(widget)) {
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &checkboxColor);
    gtk_widget_modify_fg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &checkboxColor);
    gtk_widget_modify_base(GTK_WIDGET(widget), GTK_STATE_NORMAL, &checkboxColor);
    //gtk_widget_modify_text(GTK_WIDGET(widget), GTK_STATE_NORMAL, &checkboxColor);
  }

  if (GTK_IS_COMBO_BOX(widget) || GTK_IS_COMBO_BOX_ENTRY(widget)) {
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &comboboxColor);
    gtk_widget_modify_fg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &comboboxColor);
    gtk_widget_modify_text(GTK_WIDGET(widget), GTK_STATE_NORMAL, &fontColor);
    gtk_widget_modify_base(GTK_WIDGET(widget), GTK_STATE_NORMAL, &comboboxColor);
  }

  if (GTK_IS_NOTEBOOK(widget)) {
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &notebookBackgroundColor);
    
    gint page_count = gtk_notebook_get_n_pages(GTK_NOTEBOOK(widget));

    for (gint i = 0; i < page_count; i++) {
        GtkWidget *tab_label = gtk_notebook_get_tab_label(GTK_NOTEBOOK(widget), gtk_notebook_get_nth_page(GTK_NOTEBOOK(widget), i));

        if (tab_label) {
            gtk_widget_modify_bg(tab_label, GTK_STATE_NORMAL, &notebookBackgroundColor);
            gtk_widget_modify_fg(tab_label, GTK_STATE_NORMAL, &notebookTextColor);
        }
    }
  }
    
  if (GTK_IS_FRAME(widget)) {
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &frameColor);
  }

  if (GTK_IS_SCROLLED_WINDOW(widget)) {
    GtkWidget *hscrollbar = gtk_scrolled_window_get_hscrollbar(GTK_SCROLLED_WINDOW(widget));
    GtkWidget *vscrollbar = gtk_scrolled_window_get_vscrollbar(GTK_SCROLLED_WINDOW(widget));
    gtk_widget_modify_bg(hscrollbar, GTK_STATE_NORMAL, &scrolledBarColor);
    gtk_widget_modify_bg(vscrollbar, GTK_STATE_NORMAL, &scrolledBarColor);
  }


  if (GTK_IS_TREE_VIEW(widget)) {
    gtk_widget_modify_base(GTK_WIDGET(widget), GTK_STATE_NORMAL, &treeviewColor);
    gtk_widget_modify_text(GTK_WIDGET(widget), GTK_STATE_NORMAL, &entryTextColor);
    gtk_widget_modify_font(GTK_WIDGET(widget), font);

    GList *columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(widget));
    for (GList *iter = columns; iter != NULL; iter = iter->next) {
        GtkTreeViewColumn *column = GTK_TREE_VIEW_COLUMN(iter->data);
        GtkWidget *header = gtk_tree_view_column_get_widget(column);

        if (!header) {
            header = gtk_label_new(gtk_tree_view_column_get_title(column));
            gtk_tree_view_column_set_widget(column, header);
            gtk_widget_show(header);
        }


        gtk_widget_modify_fg(header, GTK_STATE_NORMAL, &headerColor);
        gtk_widget_modify_bg(header, GTK_STATE_NORMAL, &headerBackgroundColor);
        gtk_widget_modify_font(header, font);
    }
    g_list_free(columns);
  }

  if (GTK_IS_WINDOW(widget)) {
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &backgroundColor);
  }
  if (GTK_IS_CONTAINER(widget)) {
    gtk_container_foreach(GTK_CONTAINER(widget), set_window_colors, NULL);
  }
}

void windows_init(void)
{
    Login = create_Login();
    enregistrer = create_enregistrer();
    Citoyen = create_Citoyen();
    Moto = create_Moto();
    RS = create_RS();
    Tun = create_Tun();
    mdp_oublie = create_mdp_oublie();
    Administrateur = create_Administrateur();

    // Connect destroy signals
    g_signal_connect(G_OBJECT(Login), "destroy", G_CALLBACK(gtk_main_quit), NULL);
   g_signal_connect(G_OBJECT(enregistrer), "destroy", G_CALLBACK(gtk_main_quit), NULL);
   g_signal_connect(G_OBJECT(Administrateur), "destroy", G_CALLBACK(gtk_main_quit), NULL);
   //g_signal_connect(G_OBJECT(Citoyen), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // Hide all windows initially, except for the main window
    gtk_widget_hide(enregistrer);
    gtk_widget_hide(Moto);
    gtk_widget_hide(RS);
    gtk_widget_hide(Tun);
    gtk_widget_hide(mdp_oublie);
    gtk_widget_hide(Citoyen);
     gtk_widget_hide(Administrateur);



}

void windows_show_window(GtkWidget* window)
{
    if (current_window != NULL)
    {
        gtk_widget_hide(current_window);
    }
 
    current_window = window;
    gtk_widget_show(window);
    set_window_colors(window, NULL);
}
