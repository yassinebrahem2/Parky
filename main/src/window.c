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
}
