#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "projet.h"
#include "window.h"
#include "reservation.h"


GtkWidget *treeviewReservationClient;

char *reservationFileDirectory = "reservation.txt";
char *reservationDisplayFileDirectory = "displayReservation.txt";

int a,aa,mm;
char num_carte[50],code[5];
char file_directory_citoyen[300]="citoyen.txt",
file_directory_vehicule[300]="vehicule.txt"
,matricule20[300];
citoyen c={0};
vehicule v={0};

 GtkListStore *list_store;  // Declare the list store globally
 GtkListStore *list_store2; 
gboolean search_filter_function(GtkTreeModel *model, GtkTreeIter *iter, gpointer data);

char CIN[20],MDP[20];




void
on_asbuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ascheckbutton1a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ascheckbutton2a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ascheckbutton3a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_astreeviewafficher_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_asbuttonafficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_astreeviewparking_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_asbuttonmodifier1_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_asbuttonmodifier2_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_asradiobutton1a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_EA_button_modifier_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_EA_button_recherche_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_EA_button_supprimer_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_EA_button_actualiser_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_EA_button_ajouter_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_EA_button_annuler_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_EA_checkbutton_agent_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_EA_radiobutton_homme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_EA_radiobutton_femme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_EA_checkbutton_service_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_Administrateur_map                  (GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void
on_YBFiltreRadiobuttonOui_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreRadiobuttonNon_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreRadioButtonAucun_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreCheckboxVelo_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreCheckboxCamion_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreCheckboxVoiture_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreCheckboxMoto_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreRadiobuttonAdresse_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreRadiobuttonID_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBFiltreRadiobuttonMunic_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBClearButton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YBButtonChercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YBNouveauRadiobuttonNon_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBNouveauCheckboxCamion_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBNouveauCheckboxVoiture_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBNouveauRadiobuttonOui_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBNouveauCheckboxMoto_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBNouveauCheckboxVelo_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBButtonAjouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YBParkingRadiobuttonOui_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBParkingCheckboxVoiture_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBParkingRadiobuttonNon_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBParkingCheckboxCamion_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBParkingCheckboxMoto_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBParkingCheckboxVelo_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBButtonModifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YBButtonConfirmer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YBButtonSupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YBTreeviewParking_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_YBComboboxTrier_changed             (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_YBcomboboxTrieOption_changed        (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_YBTreeviewAgent_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_YBButtonRevoquer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YBButtonAffecter_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_mfbuttonchercherajout_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_mfbuttonconfirmer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_mfbuttonsupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_mfradiobuttonhommemodifier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfradiobuttonfemmemodifier_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonagentsecuritemodifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonresponsableparkingmodifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttontechnicienmodifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonagententretienmodifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonagentparkingmodifier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfbuttonmodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_mfbuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_mfradiobuttonfemmeajout_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfradiobuttonhommeajout_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonagentdesecurite_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonresponsableparkingajout_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttontechnicienmaintenanceajout_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonagententretienajout_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mfcheckbuttonagentparkingajout_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_mftreeviewafficheragents_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_AKTreeviewService_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_AKButtonChercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AKServiceCheckbuttonJoursOrdinaire_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKServiceCheckboxWeekend_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKServiceCheckboxJoursFeries_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKServiceRadiobutton1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AkServiceRadiobutton2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKButtonModifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AKButtonConfirmer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AKButtonSupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AKNouveauCheckboxJoursordinaires_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKNouveauCheckboxDispoWeekend_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKNouveauCheckboxJoursferies_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKNouveauRadiobutton1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKNouveauRadiobutton2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_AKButtonAjouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AKTreeviewReservation_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_AKButtonAffecter_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_mfbuttonappliquerreservation_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}



void transform_space_to_underscore(const char *text1) {
    
    char* text= strdup(text1);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            text[i] = '_';
        }
    }
}

void transform_underscore_to_space(const char *text1) {
    char* text= strdup(text1);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '_') {
            text[i] = ' ';
        }
    }
}
void
on_ab_button_login_s_inscrire_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
windows_show_window(enregistrer);
}


void
on_ab_button_login_connexion_clicked   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *cin , *mdp,*label;
int x=0;
char cin1[50], mdp1[50];
cin = lookup_widget(objet_graphique,"ab_entry_login_cin");
mdp = lookup_widget(objet_graphique,"ab_entry_login_MDP");
label = lookup_widget(objet_graphique,"label4");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(MDP,gtk_entry_get_text(GTK_ENTRY(mdp)));
FILE *f=fopen(file_directory_citoyen,"r");

  if (!f )
    {
        gtk_label_set_text(GTK_LABEL(label), "Erreur: Impossible d'ouvrir le fichier!");
        return;
    }
 
 while(fscanf(f,"%19s %*s %*s %*s %*s %*s %19s %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d",cin1,mdp1)!=EOF){

    if (strcmp(CIN,cin1)==0 && strcmp(MDP,mdp1)==0)
    {   
        
        windows_show_window(Citoyen);
        x=1;
        break;
    }  
    else if (strcmp(CIN,cin1)==0 && strcmp(MDP,mdp1)!=0)
    {
        x=2;
    }
   
 }
  fclose(f);
 if (x==0){
  gtk_label_set_text(GTK_LABEL(label),"cin introuvable!");
 }
 if (x==2)
 {
    gtk_label_set_text(GTK_LABEL(label),"Mot de passe introuvable!");
 }

}


void
on_ab_button_register1_enregistrer_clicked
                                        (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nom ,*prenom, *cin,*tel,*email,*adresse,*mdp,*marquevehicule,*label,
*dnj,*dna,*dnm,*type_v, *type_mat;
label = lookup_widget(objet_graphique,"label22");
nom = lookup_widget(objet_graphique,"ab_entry_register_nom");
prenom = lookup_widget(objet_graphique,"ab_entry_register_prenom");
cin = lookup_widget(objet_graphique,"ab_entry_register_cin");
tel = lookup_widget(objet_graphique,"ab_entry_register_tel");
email = lookup_widget(objet_graphique,"ab_entry_register_email");
adresse= lookup_widget(objet_graphique,"ab_entry_register_adresse");
mdp= lookup_widget(objet_graphique,"ab_entry_register_MDP");
marquevehicule= lookup_widget(objet_graphique,"ab_entry_register_marque");
dnj = lookup_widget(objet_graphique,"ab_sb_register_DNj");
dnm = lookup_widget(objet_graphique,"ab_sb_register_DNm");
dna= lookup_widget(objet_graphique,"ab_sb_register_DNa");
type_v = lookup_widget(objet_graphique,"ab_combo_register_typevehicule");
type_mat= lookup_widget(objet_graphique, "ab_combo_register_typemat");
 


v.type=gtk_combo_box_get_active(GTK_COMBO_BOX(type_v));
v.type_matricule=gtk_combo_box_get_active(GTK_COMBO_BOX(type_mat));
strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom))); 
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(c.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
strcpy(v.marque,gtk_entry_get_text(GTK_ENTRY(marquevehicule)));
transform_space_to_underscore(c.prenom);
transform_space_to_underscore(c.adresse);
transform_space_to_underscore(c.nom);


//strcpy(v.matricule,"okok");
c.dn[0] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dnj));
c.dn[1] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dnm));
c.dn[2] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dna));

if(strlen(c.cin)<8 || strlen(c.prenom)==0 || strlen(c.adresse)==0 || strlen(c.tel)<8 || strlen(c.nom)==0 || strlen(c.email)==0 || strlen(c.mdp)==0
  || strlen(v.marque)==0){
  gtk_label_set_markup(GTK_LABEL(label),
                         "<span foreground='purple' size='large'><b>Veuillez remplir toutes les entrées convenablement.</b></span>\n");
  }
  else{
windows_show_window(Login);
ajouter_citoyen(file_directory_citoyen,c);
ajouter_vehicule(file_directory_vehicule,v);

  }
}



void
on_ab_button_register1_quitter_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
windows_show_window(Login);
}


void
on_ab_cb_register_1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[0] = 1;
    else
        c.options[0] = 0;
}


void
on_ab_cb_register_2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[1] = 1;
    else
        c.options[1] = 0;
}


void
on_ab_cb_register_3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[2] = 1;
    else
        c.options[2] = 0;
}


void
on_ab_cb_register_4_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[3] = 1;
    else
        c.options[3] = 0;
}


void
on_ab_cb_register_5_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[4] = 1;
    else
        c.options[4] = 0;
}


void
on_ab_cb_register_6_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[5] = 1;
    else
        c.options[5] = 0;
}


void
on_ab_rb_register_homme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){c.genre =0;}
}


void
on_ab_rb_register_femme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){c.genre =1;}
}


void
on_ab_button_register1_confirme_clicked
                                        (GtkWidget  *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *type_mat;
    type_mat= lookup_widget(objet_graphique, "ab_combo_register_typemat");
if (gtk_combo_box_get_active(GTK_COMBO_BOX(type_mat))==0){gtk_widget_show(Tun);}
if (gtk_combo_box_get_active(GTK_COMBO_BOX(type_mat))==1){gtk_widget_show(RS);}
if (gtk_combo_box_get_active(GTK_COMBO_BOX(type_mat))==2){gtk_widget_show(Moto);}
}



void
on_ab_button_vehicule_chercher_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *search_entry = lookup_widget(objet, "ab_entry_vehicule_chercher");
    const gchar *search_marque = gtk_entry_get_text(GTK_ENTRY(search_entry));

    GtkTreeModel *filter_model = gtk_tree_model_filter_new(GTK_TREE_MODEL(list_store), NULL);
    gtk_tree_model_filter_set_visible_func(GTK_TREE_MODEL_FILTER(filter_model),
                                           (GtkTreeModelFilterVisibleFunc)search_filter_function,
                                           (gpointer)search_marque,
                                           NULL);

    GtkWidget *treeview = lookup_widget(objet, "ab_treeview_vehicule_listvehicule");
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), filter_model);
    if ( strcmp(search_marque,"")==0){
        GtkTreeModel *model = GTK_TREE_MODEL(list_store);
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }
}

gboolean search_filter_function(GtkTreeModel *model, GtkTreeIter *iter, gpointer data) {
    const gchar *search_marque = (const gchar *)data;
    gchar *marque;
    gtk_tree_model_get(model, iter, 0, &marque, -1);

    gboolean visible = (g_strcmp0(marque, search_marque) == 0);
    g_free(marque);
    return visible;
}


void
on_ab_button_vehicule_confirme_clicked (GtkWidget  *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *type_mat;
    type_mat= lookup_widget(objet_graphique,"combobox4");
if (gtk_combo_box_get_active(GTK_COMBO_BOX(type_mat))==0){gtk_widget_show(Tun);}
if (gtk_combo_box_get_active(GTK_COMBO_BOX(type_mat))==1){gtk_widget_show(RS);}
if (gtk_combo_box_get_active(GTK_COMBO_BOX(type_mat))==2){gtk_widget_show(Moto);}
}



void
on_ab_button_vehicule_annuler_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_vehicule_enregistrer_clicked
                                        (GtkWidget      *widget,
                                        gpointer         user_data)
{
   // vehicule v={0};
GtkWidget *entry,*cb1,*cb2,*entry_cin,*label;
char marque[30],cin[10];
entry=lookup_widget(widget,"ab_entry_vehicule_marque");
cb1=lookup_widget(widget,"ab_combo_vehicule_typev");
cb2=lookup_widget(widget,"combobox4");
entry_cin=lookup_widget(widget,"ab_entry_profile_cin");
label=lookup_widget(widget,"label50");

if(strlen(gtk_entry_get_text(GTK_ENTRY(entry)))==0 || gtk_combo_box_get_active(GTK_COMBO_BOX(cb1))==-1 || 
gtk_combo_box_get_active(GTK_COMBO_BOX(cb2))==-1 || strlen(v.matricule) <2)
{
  gtk_label_set_text(GTK_LABEL(label),"remplir tout !");
}
else{
strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin)));
strcpy(v.marque,gtk_entry_get_text(GTK_ENTRY(entry)));
if(gtk_combo_box_get_active(GTK_COMBO_BOX(cb1))==0){v.type=0;}
if(gtk_combo_box_get_active(GTK_COMBO_BOX(cb1))==1){v.type=1;}
if(gtk_combo_box_get_active(GTK_COMBO_BOX(cb1))==2){v.type=2;}

if(gtk_combo_box_get_active(GTK_COMBO_BOX(cb2))==0){ v.type_matricule=0;}
if(gtk_combo_box_get_active(GTK_COMBO_BOX(cb2))==1){ v.type_matricule=1;}
if(gtk_combo_box_get_active(GTK_COMBO_BOX(cb2))==2){ v.type_matricule=2;}


modifier_vehicule(file_directory_vehicule,matricule20,v);

}


// Destroy the current window
        GtkWidget *Citoyen = lookup_widget(widget, "Citoyen");
        if (GTK_IS_WIDGET(Citoyen)) {
            gtk_widget_destroy(Citoyen);
        }

        // Recreate and show the updated window
        Citoyen = create_Citoyen();
        gtk_widget_show_all(Citoyen);
}

/*
void on_ab_button_vehicule_enregistrer_clicked(GtkWidget *widget, gpointer user_data) {
    GtkWidget *entry, *cb1, *cb2, *entry_cin, *label;
    char marque[30], cin[10];
    vehicule v = {0};  // Initialize vehicule structure

    // Lookup widgets
    entry = lookup_widget(widget, "ab_entry_vehicule_marque");
    cb1 = lookup_widget(widget, "ab_combo_vehicule_typev");
    cb2 = lookup_widget(widget, "combobox4");
    entry_cin = lookup_widget(widget, "ab_entry_profile_cin");
    label = lookup_widget(widget, "label50");

    // Validate input fields
    if (strlen(gtk_entry_get_text(GTK_ENTRY(entry))) == 0 || 
        gtk_combo_box_get_active(GTK_COMBO_BOX(cb1)) == -1 || 
        gtk_combo_box_get_active(GTK_COMBO_BOX(cb2)) == -1 || 
        strlen(v.matricule) < 2) {
        gtk_label_set_text(GTK_LABEL(label), "Remplir tout !");
    } else {
        // Populate vehicule structure
        strcpy(v.cin, gtk_entry_get_text(GTK_ENTRY(entry_cin)));
        strcpy(v.marque, gtk_entry_get_text(GTK_ENTRY(entry)));
        v.type = gtk_combo_box_get_active(GTK_COMBO_BOX(cb1));
        v.type_matricule = gtk_combo_box_get_active(GTK_COMBO_BOX(cb2));

        // Add/modify vehicule in the file
        modifier_vehicule(file_directory_vehicule, matricule20, v);

        // Destroy the current window
        GtkWidget *Citoyen = lookup_widget(widget, "Citoyen");
        if (GTK_IS_WIDGET(Citoyen)) {
            gtk_widget_destroy(Citoyen);
        }

        // Recreate and show the updated window
        Citoyen = create_Citoyen();
        gtk_widget_show_all(Citoyen);
    }
}
*/

void
on_ab_button_profile_modifier_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    GtkWidget *nom ,*prenom, *cin,*tel,*email,*adresse,*mdp,
*dnj,*dna,*dnm,*mdpc,*radiobutton1,*radiobutton2,*cb1,*cb2,*cb3,*cb4,*cb5,*cb6;

nom = lookup_widget(objet_graphique,"ab_entry_profile_nom");
prenom = lookup_widget(objet_graphique,"ab_entry_profile_prenom");
tel = lookup_widget(objet_graphique,"ab_entry_profile_tel");
cin = lookup_widget(objet_graphique,"ab_entry_profile_cin");
email = lookup_widget(objet_graphique,"ab_entry_profile_email");
adresse= lookup_widget(objet_graphique,"ab_entry_profile_adresse");
mdp= lookup_widget(objet_graphique,"ab_entry_profile_MDP");
mdpc= lookup_widget(objet_graphique,"ab_entry_profile_MDPc");
dnj = lookup_widget(objet_graphique,"ab_sb_profile_DNj");
dnm = lookup_widget(objet_graphique,"ab_sb_profile_DNm");
dna= lookup_widget(objet_graphique,"ab_sb_profile_DNa");
radiobutton1 = lookup_widget(objet_graphique,"ab_rb_profile_femme");
radiobutton2 = lookup_widget(objet_graphique,"ab_rb_profile_homme");
cb1 = lookup_widget(objet_graphique,"checkbutton8");
cb2 = lookup_widget(objet_graphique,"checkbutton9");
cb3 = lookup_widget(objet_graphique,"checkbutton10");
cb4 = lookup_widget(objet_graphique,"checkbutton11");
cb5 = lookup_widget(objet_graphique,"checkbutton12");
cb6 = lookup_widget(objet_graphique,"checkbutton13");



  gtk_editable_set_editable(GTK_EDITABLE(nom), TRUE);
  gtk_editable_set_editable(GTK_EDITABLE(prenom), TRUE);
  gtk_editable_set_editable(GTK_EDITABLE(tel), TRUE);
  gtk_editable_set_editable(GTK_EDITABLE(email), TRUE);
  gtk_editable_set_editable(GTK_EDITABLE(adresse), TRUE);
  gtk_editable_set_editable(GTK_EDITABLE(mdp), TRUE);
  gtk_editable_set_editable(GTK_EDITABLE(mdpc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(dna), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(dnm), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(dnj), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(radiobutton1), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(radiobutton2), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb1), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb2), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb3), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb4), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb5), TRUE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb6), TRUE); 

}


void
on_ab_button_profile_confirmer_clicked (GtkWidget   *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nom ,*prenom, *cin,*tel,*email,*adresse,*mdp,*mdpc,
*dnj,*dna,*dnm,*label,*radiobutton1,*radiobutton2,*cb1,*cb2,*cb3,*cb4,*cb5,*cb6;
char MDPC[50],MDP[52],filemdp[52],filecin[20];
nom = lookup_widget(objet_graphique,"ab_entry_profile_nom");
prenom = lookup_widget(objet_graphique,"ab_entry_profile_prenom");
cin = lookup_widget(objet_graphique,"ab_entry_profile_cin");
tel = lookup_widget(objet_graphique,"ab_entry_profile_tel");
email = lookup_widget(objet_graphique,"ab_entry_profile_email");
adresse= lookup_widget(objet_graphique,"ab_entry_profile_adresse");
mdp= lookup_widget(objet_graphique,"ab_entry_profile_MDP");
mdpc= lookup_widget(objet_graphique,"ab_entry_profile_MDPc");
dnj = lookup_widget(objet_graphique,"ab_sb_profile_DNj");
dnm = lookup_widget(objet_graphique,"ab_sb_profile_DNm");
dna= lookup_widget(objet_graphique,"ab_sb_profile_DNa");
label= lookup_widget(objet_graphique,"label1208");
radiobutton1 = lookup_widget(objet_graphique,"ab_rb_profile_femme");
radiobutton2 = lookup_widget(objet_graphique,"ab_rb_profile_homme");
cb1 = lookup_widget(objet_graphique,"checkbutton8");
cb2 = lookup_widget(objet_graphique,"checkbutton9");
cb3 = lookup_widget(objet_graphique,"checkbutton10");
cb4 = lookup_widget(objet_graphique,"checkbutton11");
cb5 = lookup_widget(objet_graphique,"checkbutton12");
cb6 = lookup_widget(objet_graphique,"checkbutton13");
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(MDPC,gtk_entry_get_text(GTK_ENTRY(mdpc)));
strcpy(MDP,gtk_entry_get_text(GTK_ENTRY(mdp)));

transform_space_to_underscore(gtk_entry_get_text(GTK_ENTRY(nom)));
transform_space_to_underscore(gtk_entry_get_text(GTK_ENTRY(prenom)));
transform_space_to_underscore(gtk_entry_get_text(GTK_ENTRY(adresse)));

FILE *f=fopen(file_directory_citoyen,"r");
while(fscanf(f,"%s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",filecin,filemdp)!=EOF)
{
 if(strcmp(c.cin,filecin)==0)
 {
    if ( strcmp(filemdp,MDP)==0 && strlen(MDPC)==0) //password did not change : update the citoyen file
    {
       strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
       strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom))); 
       strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
       strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(email)));
       strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
       strcpy(c.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
       c.dn[0] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dnj));
       c.dn[1] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dnm));
       c.dn[2] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dna));
       modifier_citoyen(file_directory_citoyen,c.cin,c);
         gtk_editable_set_editable(GTK_EDITABLE(nom), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(prenom), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(tel), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(email), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(adresse), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(mdp), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(mdpc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(dna), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(dnm), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(dnj), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(radiobutton1), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(radiobutton2), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb1), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb2), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb3), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb4), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb5), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb6), FALSE);
  gtk_label_set_text(GTK_LABEL(label),"modification effectue avec succes");
       break;
    }
    if (strcmp(filemdp,MDP)==0 && strlen(MDPC)!=0){
        gtk_label_set_text(GTK_LABEL(label),"veuillez confirmer le mot de passe");
        break;
    }
    else  //password did change 
    {
       if (strcmp(MDP,MDPC)==0)  //confirmation is right updaate file
       {
       strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
       strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom))); 
       strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
       strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(email)));
       strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
       strcpy(c.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
       c.dn[0] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dnj));
       c.dn[1] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dnm));
       c.dn[2] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dna));
       modifier_citoyen(file_directory_citoyen,c.cin,c);
       gtk_entry_set_text(GTK_ENTRY(mdpc),"");
        gtk_editable_set_editable(GTK_EDITABLE(nom), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(prenom), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(tel), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(email), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(adresse), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(mdp), FALSE);
  gtk_editable_set_editable(GTK_EDITABLE(mdpc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(dna), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(dnm), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(dnj), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(radiobutton1), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(radiobutton2), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb1), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb2), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb3), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb4), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb5), FALSE); 
  gtk_widget_set_sensitive(GTK_WIDGET(cb6), FALSE);
  gtk_label_set_text(GTK_LABEL(label),"modification effectue avec succes");
       break;
       } 
       else    //confirmation is wrong
       {
        gtk_label_set_text(GTK_LABEL(label),"veuillez confirmer le mot de passe");
        break;
       }
    }
 }
}
fclose(f);


}


void
on_ab_button_vehicule_modifier_clicked (GtkWidget *widget,
                                        gpointer         user_data)
{
    char matricule1[20],marque[20];
    int type , type_mat;
GtkWidget *treeview = lookup_widget(widget, "ab_treeview_vehicule_vehiculelist");
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
    GtkTreeModel *model;
    GtkWidget *entry_marque,*cb1,*cb2;

    cb1=lookup_widget(widget,"ab_combo_vehicule_typev");
cb2=lookup_widget(widget,"combobox4");
    entry_marque=lookup_widget(widget,"ab_entry_vehicule_marque");
   // strcpy(matricule,gtk_entry_get_text(GTK_ENTRY(cin_entry)));
    FILE *f=fopen(file_directory_vehicule,"r");
    if(!f){
        g_print("file couldn't get opened");
        return;
    }
    while( fscanf(f, "%*s %s %s %d %d",matricule1,marque,&type,&type_mat)!=EOF){
        if ( strcmp(matricule1,matricule20)==0){
            gtk_entry_set_text(GTK_ENTRY(entry_marque),marque);
            if (type==0){gtk_combo_box_set_active(GTK_COMBO_BOX(cb1),0);}
        if (type==1){gtk_combo_box_set_active(GTK_COMBO_BOX(cb1),1);}
        if (type==2){gtk_combo_box_set_active(GTK_COMBO_BOX(cb1),2);}

        if (type_mat==0){gtk_combo_box_set_active(GTK_COMBO_BOX(cb2),0);}
        if (type_mat==1){gtk_combo_box_set_active(GTK_COMBO_BOX(cb2),1);}
        if (type_mat==2){gtk_combo_box_set_active(GTK_COMBO_BOX(cb2),2);}

        strcpy(v.matricule,matricule20);
        }
    } fclose(f);
/*
    // Get the selected row
    if (gtk_tree_selection_get_selected(selection, &model, &selected_iter)) {
        gchar *marque, *matricule, *type;

        // Retrieve data from the selected row
        gtk_tree_model_get(model, &selected_iter, 0, &marque, 1, &matricule, 2, &type, -1);

        // Fill the text entries with the row's data
        GtkWidget *entry_marque= lookup_widget(GTK_WIDGET(button), "ab_entry_vehicule_marque");
        GtkWidget *cb1= lookup_widget(GTK_WIDGET(button), "ab_combo_vehicule_typev");
        GtkWidget *cb2 = lookup_widget(GTK_WIDGET(button), "combobox4");

        gtk_entry_set_text(GTK_ENTRY(entry_marque), marque);
        
        if (strcmp(type_mat,))

        is_row_selected = TRUE; // Mark that a row is selected for modification

        g_free(marque);
        g_free(matricule);
        g_free(type);
    } else {
        g_print("No row selected for modification!\n");
    }*/
}



void
on_ab_button_moto_ok_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    GtkWidget *moto1,*moto2,*label;
    char mat[20],matc[20],moto[30]="MOTO_";
    moto1= lookup_widget(objet_graphique,"ab_entry_moto_mat");
    moto2= lookup_widget(objet_graphique,"ab_entry_moto_matc");
    label= lookup_widget(objet_graphique,"label101");
    strcpy(mat,gtk_entry_get_text(GTK_ENTRY(moto1)));
    strcpy(matc,gtk_entry_get_text(GTK_ENTRY(moto2)));
   
if (strcmp(mat,matc)==0)
{
    gtk_widget_hide(Moto);
    strcat(moto,mat);
    strcpy(v.matricule,moto);
}
else
{
    gtk_label_set_text(GTK_LABEL(label),"ERROR de confirmation");
}
}


void
on_ab_button_rs_ok_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rs1,*rs2,*label;
char mat[20],matc[20],rs[30]="RS_";
rs1= lookup_widget(objet_graphique,"ab_entry_rs_mat");
rs2= lookup_widget(objet_graphique,"ab_entry_rs_matc");
label= lookup_widget(objet_graphique,"label107");
strcpy(mat,gtk_entry_get_text(GTK_ENTRY(rs1)));
strcpy(matc,gtk_entry_get_text(GTK_ENTRY(rs2)));
if (strcmp(mat,matc)==0)
{
    strcat(rs,mat);
    strcpy(v.matricule,rs);
    gtk_widget_hide(RS);
}
else
{
    gtk_label_set_text(GTK_LABEL(label),"ERROR de confirmation");
}
}


void
on_ab_button_tun_ok_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *mat2,*mat2c,*mat1,*mat1c,*label,*label2;
int m1,m1c,m2,m2c;
char matricule1[20],matricule2[20];
label = lookup_widget(objet_graphique,"label96");
 //label = lookup_widget(objet_graphique,"label94");
 mat1= lookup_widget(objet_graphique,"ab_sb_tun_mat1");
 mat1c= lookup_widget(objet_graphique,"ab_sb_tun_mat1c");
 mat2= lookup_widget(objet_graphique,"ab_sb_tun_mat2");
 mat2c= lookup_widget(objet_graphique,"ab_sb_tun_mat2c");
     m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mat1));
    m1c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mat1c));
    m2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mat2));
    m2c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mat2c));
if (m1==m1c && m2==m2c)
{
    sprintf(matricule1,"%d",m1);
    sprintf(matricule2,"%d",m2);
    strcat(matricule1,"_TUN_");
    strcat(matricule1,matricule2);
    strcpy(v.matricule,matricule1);
    gtk_label_set_text(GTK_LABEL(label2),matricule1);
    gtk_widget_hide(Tun);
    
}
else
{
 gtk_label_set_text(GTK_LABEL(label),"ERROR de confirmation");
}

}


void
on_ab_button_oublier_ok_clicked        (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{/*
GtkWidget *MDPc, *MDP, *label,*cin;
char cin1[50], mdp1[50], nom1[50], prenom1[50], tel1[50], email1[50], adresse1[100],matricule[50],marque[50];
char mdpc[20],mdp[20];
cin= lookup_widget(objet_graphique,"ab_entry_oublie_cin")
MDPc = lookup_widget(objet_graphique,"ab_entry_oublie_nmdp");
MDP= lookup_widget(objet_graphique,"ab_entry_oublie_nmdpc");
label = lookup_widget(objet_graphique,"label126");
strcpy(cin2,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(MDP)));
strcpy(mdpc,gtk_entry_get_text(GTK_ENTRY(MDPc)));
if (strcmp(mdp,mdpc)==0)
{
FILE *f = fopen(file_directory_citoyen,"r");
if (!f){
    g_print("file didn't open");
}
while(fscanf(f,"%19s %s %s %s %s %s %19s %d %d %d %d %d %d %d %d %d %d",cin1,nom1,prenom1,tel1,email1,adresse1,mdp1, &dn[0],&dn[1],&dn[2] , &genre ,&options[0]
 ,&options[1],&options[2],&options[3],&options[4],&options[5])!=EOF)
{
    if(strcmp(cin1,cin2)==0)
    {

    }
}
}
else
{
 gtk_label_set_text(GTK_LABEL(label),"Le mot de passe ne correspond pas");
}
*/
}


void
on_ab_button_oublier_annuler_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
windows_show_window(Login);
}


void
on_ab_button_login_oublie_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
windows_show_window(mdp_oublie);

}


void
on_checkbutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[5] = 1;
    else
        c.options[5] = 0;
}


void
on_checkbutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
        c.options[4] = 1;
    else
        c.options[4] = 0;
}


void
on_checkbutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[3] = 1;
    else
        c.options[3] = 0;
}


void
on_checkbutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
        c.options[0] = 1;
    else
        c.options[0] = 0;
}


void
on_checkbutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[1] = 1;
    else
        c.options[1] = 0;
}


void
on_checkbutton10_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
        c.options[2] = 1;
    else
        c.options[2] = 0;
}


void
on_Citoyen_map                         (GtkWidget       *widget,
                                        gpointer         user_data)
{

GtkWidget *nom,*prenom,*email,*adresse,*tel,*mdp,*mdpc,*cin,*sb1,*sb2,*sb3,*cb1,*cb2,*cb3,*cb4,*cb5,*cb6,*rb1,*rb2,*tv,*tv2
,*entry1,*entry2,*spin1,*spin2;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
char cin1[50], mdp1[50], nom1[50], prenom1[50], tel1[50], email1[50], adresse1[100],matricule[50],marque[50];
int x=0,dn[3],options[6],genre,type;

nom = lookup_widget(widget,"ab_entry_profile_nom");
prenom = lookup_widget(widget,"ab_entry_profile_prenom");
email = lookup_widget(widget,"ab_entry_profile_email");
adresse = lookup_widget(widget,"ab_entry_profile_adresse");
tel = lookup_widget(widget,"ab_entry_profile_tel");
mdp = lookup_widget(widget,"ab_entry_profile_MDP");
mdpc = lookup_widget(widget,"ab_entry_profile_MDPc");
cin = lookup_widget(widget,"ab_entry_profile_cin");
sb1 = lookup_widget(widget,"ab_sb_profile_DNj");
sb2 = lookup_widget(widget,"ab_sb_profile_DNm");
sb3 = lookup_widget(widget,"ab_sb_profile_DNa");
cb1 = lookup_widget(widget,"checkbutton8");
cb2 = lookup_widget(widget,"checkbutton9");
cb3 = lookup_widget(widget,"checkbutton10");
cb4 = lookup_widget(widget,"checkbutton11");
cb5 = lookup_widget(widget,"checkbutton12");
cb6 = lookup_widget(widget,"checkbutton13");
rb1 = lookup_widget(widget,"ab_rb_profile_femme");
rb2 = lookup_widget(widget,"ab_rb_profile_homme");
tv = lookup_widget(widget,"ab_treeview_vehicule_listvehicule");
tv2 = lookup_widget(widget,"ab_treeview_facture_options");
spin1= lookup_widget(widget,"spinbutton1");
spin2= lookup_widget(widget,"spinbutton2");
entry1 = lookup_widget(widget,"ab_entry_facture_numcarte");
entry2 = lookup_widget(widget,"ab_entry_facture_code");


list_store = gtk_list_store_new(3,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING); // Declare the list store globally   
list_store2 = gtk_list_store_new(1,G_TYPE_STRING);  


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",0,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(tv), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Options",renderer,"text",0,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(tv2), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Matricule", renderer, "text", 1, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(tv), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text", 2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(tv), column);

GtkTreeModel *model = GTK_TREE_MODEL(list_store);
gtk_tree_view_set_model(GTK_TREE_VIEW(tv), model);

GtkTreeModel *model2 = GTK_TREE_MODEL(list_store2);
gtk_tree_view_set_model(GTK_TREE_VIEW(tv2), model2);

GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);

GtkTreeSelection *selection2 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv2));
gtk_tree_selection_set_mode(selection2, GTK_SELECTION_SINGLE);
g_signal_connect(selection, "changed", G_CALLBACK(on_row_selected), NULL);
//g_signal_connect(tv, "row-activated", G_CALLBACK(on_row_double_clicked), NULL);




FILE *f=fopen(file_directory_citoyen,"r");
if (!f)
    {
        g_print( "Erreur: Impossible d'ouvrir le fichier!");
        return;
    }
while(fscanf(f,"%19s %s %s %s %s %s %19s %d %d %d %d %d %d %d %d %d %d",cin1,nom1,prenom1,tel1,email1,adresse1,mdp1, &dn[0],&dn[1],&dn[2] , &genre ,&options[0]
 ,&options[1],&options[2],&options[3],&options[4],&options[5])!=EOF){
    

    if (strcmp(CIN,cin1)==0 && strcmp(MDP,mdp1)==0)
    {   transform_underscore_to_space(nom1);
        gtk_entry_set_text(GTK_ENTRY(nom),nom1);
        gtk_editable_set_editable(GTK_EDITABLE(nom), FALSE);
        gtk_entry_set_text(GTK_ENTRY(tel),tel1);
        gtk_editable_set_editable(GTK_EDITABLE(tel), FALSE);
        transform_underscore_to_space(prenom1);
        gtk_entry_set_text(GTK_ENTRY(prenom),prenom1);
        gtk_editable_set_editable(GTK_EDITABLE(prenom), FALSE);
        transform_underscore_to_space(adresse1);
        gtk_entry_set_text(GTK_ENTRY(adresse),adresse1);
        gtk_editable_set_editable(GTK_EDITABLE(adresse), FALSE);
        gtk_entry_set_text(GTK_ENTRY(email),email1);
        gtk_editable_set_editable(GTK_EDITABLE(email), FALSE);
        gtk_entry_set_text(GTK_ENTRY(mdp),mdp1);
        gtk_editable_set_editable(GTK_EDITABLE(mdp), FALSE);
        gtk_entry_set_text(GTK_ENTRY(mdpc),"");
        gtk_editable_set_editable(GTK_EDITABLE(mdpc), FALSE);
        gtk_entry_set_text(GTK_ENTRY(adresse),adresse1);
        gtk_editable_set_editable(GTK_EDITABLE(adresse), FALSE);
        gtk_entry_set_text(GTK_ENTRY(cin),cin1);
        gtk_editable_set_editable(GTK_EDITABLE(cin), FALSE);
        gtk_widget_set_sensitive(GTK_WIDGET(rb1), FALSE);
        gtk_widget_set_sensitive(GTK_WIDGET(rb2), FALSE);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(sb1),dn[0]);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(sb2),dn[1]);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(sb3),dn[2]);
        gtk_widget_set_sensitive(GTK_WIDGET(sb1), FALSE);
        gtk_widget_set_sensitive(GTK_WIDGET(sb2), FALSE);
        gtk_widget_set_sensitive(GTK_WIDGET(sb3), FALSE);
        GtkTreeIter iter;
             if (options[0] == 0) {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "NULL", -1);
} else {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "parking a etages", -1);
}

if (options[1] == 0) {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "NULL", -1);
} else {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "Handicape", -1);
}

if (options[2] == 0) {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "NULL", -1);
} else {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "Lavage", -1);
}

if (options[3] == 0) {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "NULL", -1);
} else {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "Service client", -1);
}

if (options[4] == 0) {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "NULL", -1);
} else {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "Agent de securite", -1);
}

if (options[5] == 0) {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "NULL", -1);
} else {
    gtk_list_store_append(list_store2, &iter);
    gtk_list_store_set(list_store2, &iter, 0, "Technicien de maintenance", -1);
}

        

  if(genre==0)
  {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rb2) , TRUE);
  }
  else
  {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rb1) , TRUE);
  }
  gtk_widget_set_sensitive(GTK_WIDGET(cb6), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(cb5), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(cb4), FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(cb1), FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(cb2), FALSE);
      gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb3),options[2]);
  gtk_widget_set_sensitive(GTK_WIDGET(cb3), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb2),options[1]);
      gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb1),options[0]);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb5),options[4]);
      gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb6),options[5]);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb4),options[3]);

        gtk_entry_set_text(GTK_ENTRY(entry1),num_carte);
        gtk_entry_set_text(GTK_ENTRY(entry2),code);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin1),mm);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin2),aa);

        break;
    }  
}
fclose(f);
FILE *f1=fopen(file_directory_vehicule,"r");
if (!f1)
    {
        g_print( "Erreur: Impossible d'ouvrir le fichier!");
        return;
    }
while(fscanf(f1,"%s %s %s %d %*s",cin1,matricule,marque,&type)!=EOF)
{ 
  if (strcmp(CIN,cin1)==0)
  {  char type1[50];
    if(type==0){strcpy(type1,"Camion");}
    if(type==1){strcpy(type1,"Sedan");}
    if(type==2){strcpy(type1,"Moto");}
    GtkTreeIter iter;
    gtk_list_store_append(list_store,&iter);
    gtk_list_store_set(list_store,&iter,0,marque,1,matricule,2,type1,-1);

  }

}
fclose(f1);

initReservationClientTreeview(widget);
}


void on_row_selected(GtkTreeSelection *selection, gpointer user_data) {
    GtkTreeModel *model;
    GtkTreeIter iter;

    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gchar *marque, *matricule, *type;

        gtk_tree_model_get(model, &iter, 0, &marque, 1, &matricule, 2, &type, -1);
        strcpy(matricule20,matricule);
        
        g_free(marque);
        g_free(matricule);
        g_free(type);
    }
}
/*
void on_row_double_clicked(GtkTreeView *treeview, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data) {
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    GtkTreeIter iter;

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        if (GTK_IS_TREE_MODEL_FILTER(model)) {
            // Get the original list_store from the filter model
            GtkTreeModel *child_model = gtk_tree_model_filter_get_model(GTK_TREE_MODEL_FILTER(model));
            GtkTreeIter child_iter;

            // Map the filter iterator to the original list_store iterator
            gtk_tree_model_filter_convert_iter_to_child_iter(GTK_TREE_MODEL_FILTER(model), &child_iter, &iter);

            // Remove the row from the original list_store
            gtk_list_store_remove(GTK_LIST_STORE(child_model), &child_iter);
        } else if (GTK_IS_LIST_STORE(model)) {
            // Remove the row from the list_store
            gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
        }
        g_print("Row deleted on double-click.\n");
    }
}
*/
void
on_ab_button_vehicule_Supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *treeview = lookup_widget(GTK_WIDGET(button), "ab_treeview_vehicule_listvehicule");
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
    GtkTreeModel *model;
    GtkTreeIter iter;

    // Get the selected row
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        char *Matricule_a_supprimer = NULL; // Pointer to store the matricule value
        gtk_tree_model_get(model, &iter, 1, &Matricule_a_supprimer, -1); 

        // FILE HANDLING
        FILE *file = fopen(file_directory_vehicule, "r");
        FILE *temp = fopen("/home/vboxuser/Projects/project435/temporary.txt", "w");
        if (file && temp) {
            char line[500];
            while (fgets(line, sizeof(line), file)) {
                char cin[9], matricule[100], marque[40], type[2], type_mat[2];
                // Read CIN, matricule, marque, type, and type_mat from each line
                if (sscanf(line, "%s %s %s %s %s", cin, matricule, marque, type, type_mat) == 5) {

                    // Write the line to the temp file only if the matricule is different
                    if (g_strcmp0(matricule, Matricule_a_supprimer) != 0) {
                        fprintf(temp, "%s %s %s %s %s\n", cin, matricule, marque, type, type_mat);
                    }
                }
            }
            fclose(file);
            fclose(temp);

            // Replace the original file with the temporary file
            remove(file_directory_vehicule);
            rename("/home/vboxuser/Projects/project435/temporary.txt", file_directory_vehicule);
        } else {
            g_print("Error opening file for update!\n");
        }

        // Remove the selected row from the TreeView
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

        g_free(Matricule_a_supprimer); // Free the retrieved matricule string
    } else {
        g_print("No row selected!\n");
    }
}

void
on_button1_clicked                     (GtkWidget *widget,
                                        gpointer         user_data)
{
    GtkWidget *entry1,*entry2,*sb1,*sb2,*rb1,*rb2,*rb3,*label,*cb;
    
    entry1=lookup_widget(widget,"ab_entry_facture_numcarte");
    entry2 = lookup_widget(widget,"ab_entry_facture_code");
    sb1= lookup_widget(widget,"spinbutton1");
    sb2= lookup_widget(widget,"spinbutton2");
    rb1=lookup_widget(widget,"radiobutton5");
    rb2=lookup_widget(widget,"radiobutton6");
    rb3=lookup_widget(widget,"radiobutton7");
    label = lookup_widget(widget,"label137");
    cb=lookup_widget(widget,"checkbutton14");

    a=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb));

    if (strlen(gtk_entry_get_text(GTK_ENTRY(entry1)))==0 || strlen(gtk_entry_get_text(GTK_ENTRY(entry2)))==0)
    {
         gtk_label_set_text(GTK_LABEL(label),"remplir tout les champs!");
    }
    else{
         if(a==0){
            gtk_entry_set_text(GTK_ENTRY(entry1),"");
            gtk_entry_set_text(GTK_ENTRY(entry2),"");
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(sb1),1);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(sb2),2000);
         }
         else{
            strcpy(num_carte,gtk_entry_get_text(GTK_ENTRY(entry1)));
            strcpy(code,gtk_entry_get_text(GTK_ENTRY(entry2)));
            mm=gtk_spin_button_get_value(GTK_SPIN_BUTTON(sb1));
            aa=gtk_spin_button_get_value(GTK_SPIN_BUTTON(sb2));

         }
    }
}

void initReservationClientTreeview(GtkWidget *object) {
    int i;
    GtkCellRenderer *rendererArray[15];
    GtkTreeViewColumn *columnArray[15];
    const char header[15][30] = {
        "ID Reservation", "cin", "parkingID", 
        "jours", "mois", "annee", "heureh", "heuremin",
        "dureeh", "dureemin", "mat", "methpai",
        "demspec1", "demspec2", "type"
        };
    updateReservationDisplayFile(reservationFileDirectory, reservationDisplayFileDirectory);
    updateReservationClientTreeview(object);

    for (i = 0; i < 15; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewReservationClient), columnArray[i]);
    }
}


void updateReservationClientTreeview(GtkWidget *object) {
    Reservation reservation;
    int i;
    GtkTreeStore *storeReservationClient = gtk_tree_store_new(15,
    G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_STRING);
    treeviewReservationClient = lookup_widget(object, "ab_treeview_facture_datereserve");
    
    filterReservationByCIN(reservationDisplayFileDirectory, CIN);
    FILE *reservationFile = fopen(reservationDisplayFileDirectory, "r");
    while (scanReservation(reservationFile, &reservation) != EOF) {
        GtkTreeIter iter;
        gtk_tree_store_append(storeReservationClient, &iter, NULL); // Add a new row
        gtk_tree_store_set(storeReservationClient, &iter, 
            0, reservation.idreservation,
            1, reservation.cin,
            2, reservation.parkingID,
            3, reservation.jours,
            4, reservation.mois,
            5, reservation.annee,
            6, reservation.heureh,
            7, reservation.heuremin,
            8, reservation.dureeh,
            9, reservation.dureemin,
            10, reservation.mat,
            11, reservation.methpai,
            12, reservation.demspec[0],
            13, reservation.demspec[1],
            14, reservation.type,
            -1);
    }
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewReservationClient), GTK_TREE_MODEL(storeReservationClient));
}
