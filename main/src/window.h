#ifndef WINDOWS_H
#define WINDOWS_H

#include <gtk/gtk.h>

extern GtkWidget *Login;
extern GtkWidget *enregistrer;
extern GtkWidget *Citoyen;
extern GtkWidget *Moto;
extern GtkWidget *RS;
extern GtkWidget *Tun;
extern GtkWidget *mdp_oublie;
extern GtkWidget *Administrateur;


extern GtkWidget* current_window;

void windows_init(void);
void windows_show_window(GtkWidget* window);


#endif // WINDOWS_H