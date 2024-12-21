/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"
#include "window.h"

int
main (int argc, char *argv[])
{
  GtkWidget *Administrateur;


#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);
  windows_init();

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  windows_show_window(Login);
  Administrateur = create_Administrateur ();
<<<<<<< HEAD
  gtk_widget_show (Administrateur);
=======
  //gtk_widget_show (Administrateur);
  Login = create_Login ();
  //gtk_widget_show (Login);
  enregistrer = create_enregistrer ();
  //gtk_widget_show (enregistrer);
  Moto = create_Moto ();
  //gtk_widget_show (Moto);
  RS = create_RS ();
  //gtk_widget_show (RS);
  Tun = create_Tun ();
  //gtk_widget_show (Tun);
  mdp_oublie = create_mdp_oublie ();
  //gtk_widget_show (mdp_oublie);
>>>>>>> avis

  gtk_main ();
  return 0;
}

