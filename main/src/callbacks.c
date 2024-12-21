#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"
#include "reservation.h"


GtkWidget *treeviewAdminReservation;
extern GtkWidget *mftreeviewafficheragents;
int sexe_selectionne = -1;
int sexe_modifie_selectionne = -1;

int services[5] = {0, 0, 0, 0, 0};

char agentFileDirectory[] = "Data/agent.txt";
char *reservationFileDirectory = "Data/reservation.txt";
char *reservationDisplayFileDirectory = "Cashe/displayReservation.txt";



void
on_Citoyen_map                         (GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void
on_checkbutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton10_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_button_profile_modifier_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_profile_confirmer_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_vehicule_confirme_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_vehicule_annuler_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_vehicule_enregistrer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_vehicule_chercher_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_vehicule_Supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_vehicule_modifier_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


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
    // Récupérer le GtkTreeView à partir de l'interface
    GtkTreeView *treeview = GTK_TREE_VIEW(lookup_widget(gtk_widget_get_toplevel(widget), "mftreeviewafficheragents"));
    
    // Réinitialiser l'affichage du GtkTreeView
    gtk_tree_view_set_model(treeview, NULL);  // Enlever le modèle précédent

    // Appeler la fonction pour afficher les agents dans le GtkTreeView
    afficher_agents(treeview);

    initAdminReservationTreeview(widget);
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


void on_mftreeviewafficheragents_row_activated(GtkWidget *object, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data)
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    
    GtkWidget *entry_cin = lookup_widget(object, "mfentrycinmodifier");
    GtkWidget *entry_nom = lookup_widget(object, "mfentrynommodifier");
    GtkWidget *entry_prenom = lookup_widget(object, "mfentryprenommodifier");
    GtkWidget *entry_telephone = lookup_widget(object, "mfentrynumtelmodifier");
    GtkWidget *entry_adresse = lookup_widget(object, "mfentryadressemodifier");
    GtkWidget *entry_salaire = lookup_widget(object, "mfentrysalairemodifier");

    GtkWidget *radiobutton_homme = lookup_widget(object, "mfradiobuttonhommemodifier");
    GtkWidget *radiobutton_femme = lookup_widget(object, "mfradiobuttonfemmemodifier");
    GtkWidget *label_error = lookup_widget(object, "mflabelerreurmodifier");

    // Déclaration du tableau des checkbuttons
    GtkWidget *checkbuttons[5];
    checkbuttons[0] = lookup_widget(object, "mfcheckbuttonagentsecuritemodifier");
    checkbuttons[1] = lookup_widget(object, "mfcheckbuttontechnicienmodifier");
    checkbuttons[2] = lookup_widget(object, "mfcheckbuttonagentparkingmodifier");
    checkbuttons[3] = lookup_widget(object, "mfcheckbuttonresponsableparkingmodifier");
    checkbuttons[4] = lookup_widget(object, "mfcheckbuttonagententretienmodifier");

    // Association des SpinButtons pour la date de naissance
    GtkWidget *spinbutton_jour = lookup_widget(object, "mfspinbuttonjourmodifier");
    GtkWidget *spinbutton_mois = lookup_widget(object, "mfspinbuttonmoismodifier");
    GtkWidget *spinbutton_annee = lookup_widget(object, "mfspinbuttonanneemodifier");

    // Récupérer la ligne sélectionnée
    model = gtk_tree_view_get_model(GTK_TREE_VIEW(object));
    if (gtk_tree_selection_get_selected(gtk_tree_view_get_selection(GTK_TREE_VIEW(object)), &model, &iter)) {
        gchar *cin, *nom, *prenom, *numtel, *date_naissance_str, *adresse, *salaire, *services_str, *sexe_str;
        gint jour, mois, annee;
        
        // Récupération des valeurs dans les colonnes selon l'ordre défini
        gtk_tree_model_get(model, &iter,
                           0, &cin,
                           1, &nom,
                           2, &prenom,
                           3, &numtel,
                           4, &date_naissance_str,  // Assuming date is a string representation
                           5, &salaire,
                           6, &adresse,
                           7, &sexe_str,
                           8, &services_str,
                           9, NULL); // The "-1" column is not needed for retrieval

        // Remplir les champs du formulaire avec les données de l'agent sélectionné
        gtk_entry_set_text(GTK_ENTRY(entry_cin), cin);
        gtk_entry_set_text(GTK_ENTRY(entry_nom), nom);
        gtk_entry_set_text(GTK_ENTRY(entry_prenom), prenom);
        gtk_entry_set_text(GTK_ENTRY(entry_telephone), numtel);
        gtk_entry_set_text(GTK_ENTRY(entry_adresse), adresse);  // Adresse
        gtk_entry_set_text(GTK_ENTRY(entry_salaire), salaire);

        // Remplir les services
        char *token = strtok(services_str, " ");
        int i = 0;
        while (token != NULL && i < 5) {
            if (g_strcmp0(token, "Sécurité") == 0) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons[0]), TRUE);
            if (g_strcmp0(token, "Maintenance") == 0) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons[1]), TRUE);
            if (g_strcmp0(token, "Parking") == 0) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons[2]), TRUE);
            if (g_strcmp0(token, "Responsable") == 0) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons[3]), TRUE);
            if (g_strcmp0(token, "Entretien") == 0) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons[4]), TRUE);
            token = strtok(NULL, " ");
            i++;
        }

        // Sélectionner le sexe
        if (g_strcmp0(sexe_str, "Homme") == 0) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_homme), TRUE);
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_femme), FALSE);
        } else if (g_strcmp0(sexe_str, "Femme") == 0) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_homme), FALSE);
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_femme), TRUE);
        }

        // Remplir la date de naissance
        sscanf(date_naissance_str, "%02d/%02d/%04d", &jour, &mois, &annee);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_jour), jour);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_mois), mois);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_annee), annee);

	
        // Désactiver tous les champs sauf CIN pour les empêcher d'être modifiés
	gtk_widget_set_sensitive(entry_cin, FALSE);
        gtk_widget_set_sensitive(entry_nom, FALSE);
        gtk_widget_set_sensitive(entry_prenom, FALSE);
        gtk_widget_set_sensitive(entry_telephone, FALSE);
        gtk_widget_set_sensitive(entry_adresse, FALSE);
        gtk_widget_set_sensitive(entry_salaire, FALSE);
        gtk_widget_set_sensitive(spinbutton_jour, FALSE);
        gtk_widget_set_sensitive(spinbutton_mois, FALSE);
        gtk_widget_set_sensitive(spinbutton_annee, FALSE);
        int j;
        for (j = 0; j < 5; j++) {
            gtk_widget_set_sensitive(checkbuttons[j], FALSE);
        }
        gtk_widget_set_sensitive(radiobutton_homme, FALSE);
        gtk_widget_set_sensitive(radiobutton_femme, FALSE);
    }
}




void on_mfradiobuttonhommemodifier_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) {
        sexe_modifie_selectionne = 1; 
    }
}

void on_mfradiobuttonfemmemodifier_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) {
        sexe_modifie_selectionne = 0; 
    }
}

void on_mfcheckbuttonagentsecuritemodifier_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    services[0] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttonagentparkingmodifier_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    services[1] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttontechnicienmodifier_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    services[2] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttonresponsableparkingmodifier_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    services[3] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttonagententretienmodifier_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    services[4] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfbuttonmodifier_clicked(GtkWidget *object, gpointer user_data) {
    GtkWidget *window = GTK_WIDGET(user_data);  // Obtient la fenêtre ou le conteneur principal

    // Liste des widgets à activer
    GtkWidget *entry_cin = lookup_widget(object, "mfentrycinmodifier");
    GtkWidget *entry_nom = lookup_widget(object, "mfentrynommodifier");
    GtkWidget *entry_prenom = lookup_widget(object, "mfentryprenommodifier");
    GtkWidget *entry_telephone = lookup_widget(object, "mfentrynumtelmodifier");
    GtkWidget *entry_adresse = lookup_widget(object, "mfentryadressemodifier");
    GtkWidget *entry_salaire = lookup_widget(object, "mfentrysalairemodifier");
    
    GtkWidget *radiobutton_homme = lookup_widget(object, "mfradiobuttonhommemodifier");
    GtkWidget *radiobutton_femme = lookup_widget(object, "mfradiobuttonfemmemodifier");

    GtkWidget *checkbuttons[5];
    checkbuttons[0] = lookup_widget(object, "mfcheckbuttonagentsecuritemodifier");
    checkbuttons[1] = lookup_widget(object, "mfcheckbuttontechnicienmodifier");
    checkbuttons[2] = lookup_widget(object, "mfcheckbuttonagentparkingmodifier");
    checkbuttons[3] = lookup_widget(object, "mfcheckbuttonresponsableparkingmodifier");
    checkbuttons[4] = lookup_widget(object, "mfcheckbuttonagententretienmodifier");

    GtkWidget *spinbutton_jour = lookup_widget(object, "mfspinbuttonjourmodifier");
    GtkWidget *spinbutton_mois = lookup_widget(object, "mfspinbuttonmoismodifier");
    GtkWidget *spinbutton_annee = lookup_widget(object, "mfspinbuttonanneemodifier");

    // Activer tous les widgets
    gtk_widget_set_sensitive(entry_cin, FALSE);
    gtk_widget_set_sensitive(entry_nom, TRUE);
    gtk_widget_set_sensitive(entry_prenom, TRUE);
    gtk_widget_set_sensitive(entry_telephone, TRUE);
    gtk_widget_set_sensitive(entry_adresse, TRUE);
    gtk_widget_set_sensitive(entry_salaire, TRUE);
    

    gtk_widget_set_sensitive(radiobutton_homme, TRUE);
    gtk_widget_set_sensitive(radiobutton_femme, TRUE);

    for (int i = 0; i < 5; i++) {
        gtk_widget_set_sensitive(checkbuttons[i], TRUE);
    }

    gtk_widget_set_sensitive(spinbutton_jour, TRUE);
    gtk_widget_set_sensitive(spinbutton_mois, TRUE);
    gtk_widget_set_sensitive(spinbutton_annee, TRUE);
}

    

void on_mfradiobuttonhommeajout_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) {
        sexe_selectionne = 1; // Homme
    }
}

void on_mfradiobuttonfemmeajout_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) {
        sexe_selectionne = 0; // Femme
    }
}

void on_mfcheckbuttonagentdesecurite_toggled(GtkToggleButton *togglebutton, gpointer user_data)

{
    services[0] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttontechnicienmaintenanceajout_toggled(GtkToggleButton *togglebutton, gpointer user_data) 
{
    services[1] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttonagentparkingajout_toggled(GtkToggleButton *togglebutton, gpointer user_data) 
{
    services[2] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttonresponsableparkingajout_toggled(GtkToggleButton *togglebutton, gpointer user_data) 
{
    services[3] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfcheckbuttonagententretienajout_toggled(GtkToggleButton *togglebutton, gpointer user_data) 
{
    services[4] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));
}

void on_mfbuttonajouter_clicked(GtkWidget *object, gpointer user_data) {
    GtkWidget *entry_cin, *entry_nom, *entry_prenom, *entry_num, *entry_salaire, *entry_adresse;
    GtkWidget *radiobutton_homme, *radiobutton_femme;
    GtkWidget *checkbuttons[5];
    GtkWidget *spinbutton_jour, *spinbutton_mois, *spinbutton_annee;
    GtkWidget *label_error;
    GtkWidget *treeview;

    // 2. Déclaration des variables
    Agent a;
    char message[200];
    Date date_naissance;
    int resultat;

    // 3. Association des widgets aux objets graphiques
    entry_cin = lookup_widget(object, "mfentrycinajout");
    entry_nom = lookup_widget(object, "mfentrynomajout");
    entry_prenom = lookup_widget(object, "mfentryprenomajout");
    entry_num = lookup_widget(object, "mfentrynumajout");
    entry_salaire = lookup_widget(object, "mfentrysalaireajout");
    entry_adresse = lookup_widget(object, "mfentryadresseajout");
    radiobutton_homme = lookup_widget(object, "mfradiobuttonhommeajout");
    radiobutton_femme = lookup_widget(object, "mfradiobuttonfemmeajout");
    label_error = lookup_widget(object, "mflabelerrorajout");

    // Association des checkbuttons
    checkbuttons[0] = lookup_widget(object, "mfcheckbuttonagentdesecurite");
    checkbuttons[1] = lookup_widget(object, "mfcheckbuttontechnicienmaintenanceajout");
    checkbuttons[2] = lookup_widget(object, "mfcheckbuttonagentparkingajout");
    checkbuttons[3] = lookup_widget(object, "mfcheckbuttonresponsableparkingajout");
    checkbuttons[4] = lookup_widget(object, "mfcheckbuttonagententretienajout");

    spinbutton_jour = lookup_widget(object, "mfspinbuttonjourajout");
    spinbutton_mois = lookup_widget(object, "mfspinbuttonmoisajout");
    spinbutton_annee = lookup_widget(object, "mfspinbuttonanneeajout");

    // 4. Récupération des données des champs
    strcpy(a.cin, gtk_entry_get_text(GTK_ENTRY(entry_cin)));
    strcpy(a.nom, gtk_entry_get_text(GTK_ENTRY(entry_nom)));
    strcpy(a.prenom, gtk_entry_get_text(GTK_ENTRY(entry_prenom)));
    strcpy(a.numtel, gtk_entry_get_text(GTK_ENTRY(entry_num)));
    strcpy(a.salaire, gtk_entry_get_text(GTK_ENTRY(entry_salaire)));
    strcpy(a.adresse, gtk_entry_get_text(GTK_ENTRY(entry_adresse)));

    date_naissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour));
    date_naissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois));
    date_naissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee));
    a.date_naissance = date_naissance;

    // Vérification du sexe (radio boutons)
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_homme))) {
        a.sexe = 1; // Homme
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_femme))) {
        a.sexe = 0; // Femme
    } else {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : Veuillez sélectionner un sexe.");
        return; // Arrête l'exécution si le sexe n'est pas sélectionné
    }

    // Récupération des services
    for (int i = 0; i < 5; i++) {
        a.services[i] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbuttons[i])) ? 1 : 0;
    }

    // Validation des champs obligatoires
    if (strlen(a.cin) == 0 || strlen(a.nom) == 0 || strlen(a.prenom) == 0 ||
        strlen(a.numtel) == 0 || strlen(a.salaire) == 0 || strlen(a.adresse) == 0 ) {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : Tous les champs sont obligatoires.");
        return; // Arrête l'exécution si les champs ne sont pas remplis
    }

    // 5. Appel de la fonction ajouter_agent pour sauvegarder les données
    resultat = ajouter_agent(agentFileDirectory, a);

    // Mise à jour du label pour afficher le résultat
    if (resultat == 1) {
        sprintf(message, "Ajout réussi : %s %s %s", a.prenom, a.nom, a.cin);
        gtk_label_set_text(GTK_LABEL(label_error), message);

        // Afficher les agents dans le TreeView
        treeview = lookup_widget(gtk_widget_get_toplevel(object), "mftreeviewafficheragents");
        afficher_agents(treeview);

        // Vider les champs après un ajout réussi
        gtk_entry_set_text(GTK_ENTRY(entry_cin), "");
        gtk_entry_set_text(GTK_ENTRY(entry_nom), "");
        gtk_entry_set_text(GTK_ENTRY(entry_prenom), "");
        gtk_entry_set_text(GTK_ENTRY(entry_num), "");
        gtk_entry_set_text(GTK_ENTRY(entry_salaire), "");
        gtk_entry_set_text(GTK_ENTRY(entry_adresse), "");

        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_jour), 1);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_mois), 1);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_annee), 2024);

        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_homme), TRUE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_femme), FALSE);

        // Désélectionner les services
        for (int i = 0; i < 5; i++) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons[i]), FALSE);
        }
    } else if (resultat == -1) {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : Le CIN existe déjà.");
    } else if (resultat == -2) {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : Le numéro de téléphone existe déjà.");
    } else {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : Échec de l'ajout de l'agent.");
    }
}





void on_mfbuttonconfirmer_clicked(GtkWidget *object, gpointer user_data) {
    // Créer un nouvel objet Agent pour recevoir les données modifiées
    Agent nouv;

    // Récupérer les widgets du formulaire
    GtkWidget *entry_cin = lookup_widget(object, "mfentrycinmodifier");
    GtkWidget *entry_nom = lookup_widget(object, "mfentrynommodifier");
    GtkWidget *entry_prenom = lookup_widget(object, "mfentryprenommodifier");
    GtkWidget *entry_telephone = lookup_widget(object, "mfentrynumtelmodifier");
    GtkWidget *entry_adresse = lookup_widget(object, "mfentryadressemodifier");
    GtkWidget *entry_salaire = lookup_widget(object, "mfentrysalairemodifier");

    GtkWidget *radiobutton_homme = lookup_widget(object, "mfradiobuttonhommemodifier");
    GtkWidget *radiobutton_femme = lookup_widget(object, "mfradiobuttonfemmemodifier");

    GtkWidget *checkbuttons[5] = {
        lookup_widget(object, "mfcheckbuttonagentsecuritemodifier"),
        lookup_widget(object, "mfcheckbuttontechnicienmodifier"),
        lookup_widget(object, "mfcheckbuttonagentparkingmodifier"),
        lookup_widget(object, "mfcheckbuttonresponsableparkingmodifier"),
        lookup_widget(object, "mfcheckbuttonagententretienmodifier")
    };

    GtkWidget *spinbutton_jour = lookup_widget(object, "mfspinbuttonjourmodifier");
    GtkWidget *spinbutton_mois = lookup_widget(object, "mfspinbuttonmoismodifier");
    GtkWidget *spinbutton_annee = lookup_widget(object, "mfspinbuttonanneemodifier");

    // Récupérer les valeurs des champs modifiés
    strcpy(nouv.cin, gtk_entry_get_text(GTK_ENTRY(entry_cin)));
    strcpy(nouv.nom, gtk_entry_get_text(GTK_ENTRY(entry_nom)));
    strcpy(nouv.prenom, gtk_entry_get_text(GTK_ENTRY(entry_prenom)));
    strcpy(nouv.numtel, gtk_entry_get_text(GTK_ENTRY(entry_telephone)));
    strcpy(nouv.adresse, gtk_entry_get_text(GTK_ENTRY(entry_adresse)));
    strcpy(nouv.salaire, gtk_entry_get_text(GTK_ENTRY(entry_salaire)));

    // Récupérer la date de naissance
    nouv.date_naissance.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour));
    nouv.date_naissance.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois));
    nouv.date_naissance.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee));

    // Récupérer le sexe
    nouv.sexe = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_homme)) ? 1 : 0;

    // Récupérer les services
    for (int i = 0; i < 5; i++) {
        nouv.services[i] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbuttons[i])) ? 1 : 0;
    }

    // Vérifier si le numtel existe déjà dans le fichier
    FILE *f = fopen(agentFileDirectory, "r");
    if (f != NULL) {
        Agent a;
        while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s", 
                      a.cin, a.nom, a.prenom, &a.date_naissance.jour, &a.date_naissance.mois, &a.date_naissance.annee,
                      a.salaire, a.adresse, &a.sexe, 
                      &a.services[0], &a.services[1], &a.services[2], &a.services[3], &a.services[4], 
                      a.id_parking, a.numtel) != EOF) {
            // Vérifier si le numtel existe déjà
            if (strcmp(a.numtel, nouv.numtel) == 0 && strcmp(a.cin, nouv.cin) != 0) {
                gtk_label_set_text(GTK_LABEL(lookup_widget(object, "mflabelerreurmodifier")), "Ce numéro de téléphone existe déjà.");
                fclose(f);
                return;  // Sortir de la fonction si le numéro de téléphone existe déjà
            }
        }
        fclose(f);
    }

    // Modifier l'agent dans le fichier
    if (modifier_agent(agentFileDirectory, nouv.cin, nouv) == 1) {
        // Si la modification est réussie
        gtk_label_set_text(GTK_LABEL(lookup_widget(object, "mflabelerreurmodifier")), "Modification réussie");

        // Rafraîchir le TreeView
        GtkWidget *treeview_agents = lookup_widget(object, "mftreeviewafficheragents");
        GtkListStore *store = gtk_list_store_new(10, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
                                                 G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
                                                 G_TYPE_STRING, G_TYPE_STRING);
        GtkTreeIter iter;
        f = fopen(agentFileDirectory, "r");

        if (f != NULL) {
            Agent a;
            while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s", 
                          a.cin, a.nom, a.prenom, &a.date_naissance.jour, &a.date_naissance.mois, &a.date_naissance.annee,
                          a.salaire, a.adresse, &a.sexe, 
                          &a.services[0], &a.services[1], &a.services[2], &a.services[3], &a.services[4], 
                          a.id_parking, a.numtel) != EOF) {
                gchar date_naissance_str[20];
                sprintf(date_naissance_str, "%02d/%02d/%d", a.date_naissance.jour, a.date_naissance.mois, a.date_naissance.annee);

                gchar services_str[256] = "";
                for (int i = 0; i < 5; i++) {
                    if (a.services[i]) {
                        if (strlen(services_str) > 0) strcat(services_str, ", ");
                        strcat(services_str, (i == 0) ? "Agent sécurité" :
                                              (i == 1) ? "Technicien" :
                                              (i == 2) ? "Agent parking" :
                                              (i == 3) ? "Responsable parking" :
                                                         "Agent entretien");
                    }
                }

                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter,
                                   0, a.cin,
                                   1, a.nom,
                                   2, a.prenom,
                                   3, a.numtel,
                                   4, date_naissance_str,
                                   5, a.salaire,
                                   6, a.adresse,
                                   7, (a.sexe == 1 ? "Homme" : "Femme"),
                                   8, services_str,
                                   9, "-1",
                                   -1);
            }
            fclose(f);
        }

        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_agents), GTK_TREE_MODEL(store));
        g_object_unref(store);
    } else {
        // Si la modification échoue
        gtk_label_set_text(GTK_LABEL(lookup_widget(object, "mflabelerreurmodifier")), "Erreur de modification");
    }
}


void on_mfbuttonsupprimer_clicked(GtkWidget *object, gpointer user_data) {
    GtkWidget *treeview_agents = lookup_widget(object, "mftreeviewafficheragents");

    // Obtenir la sélection
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_agents));
    GtkTreeModel *model;
    GtkTreeIter iter;

    // Vérifier si une ligne est sélectionnée
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gchar *cin;

        // Lire le CIN de la ligne sélectionnée
        gtk_tree_model_get(model, &iter, 0, &cin, -1);

        // Appeler la fonction pour supprimer l'agent
        if (supprimer_agent(agentFileDirectory, cin)) {
            // Supprimer la ligne du TreeView
            gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
            gtk_label_set_text(GTK_LABEL(lookup_widget(object, "mflabelmessagerecherche")), "Agent supprimé avec succès.");
        } else {
            gtk_label_set_text(GTK_LABEL(lookup_widget(object, "mflabelmessagerecherche")), "Erreur lors de la suppression.");
        }

        // Libérer la mémoire
        g_free(cin);
    } else {
        gtk_label_set_text(GTK_LABEL(lookup_widget(object, "mflabelmessagerecherche")), "Veuillez sélectionner une ligne.");
    }
}

void on_mfbuttonchercherajout_clicked(GtkWidget *object, gpointer user_data) {
    // Déclaration des variables nécessaires
    GtkWidget *combobox_criteres, *entry_valeur, *label_error, *treeview_agents;
    const char *valeur;
    int critere = 0;
    char critere_texte[20];

    // Récupération des widgets
    combobox_criteres = lookup_widget(object, "mfcomboboxrecherche");  // À adapter selon votre ID
    entry_valeur = lookup_widget(object, "mfentryajoutchercher");    // ID du champ de texte pour la valeur
    label_error = lookup_widget(object, "mflabelmessagerecherche");  // ID du label d'erreur
    treeview_agents = lookup_widget(object, "mftreeviewafficheragents"); // ID de votre treeview

    // Récupérer l'index du critère sélectionné dans le combobox
    critere = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_criteres));

    // Vérification si un critère a été sélectionné
    if (critere == -1) {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : aucun critère sélectionné.");
        return; // Quitte la fonction si aucun critère n'est sélectionné
    }

    // Récupérer la valeur entrée par l'utilisateur dans le champ de texte
    valeur = gtk_entry_get_text(GTK_ENTRY(entry_valeur));

    // Vérification si le champ de texte est vide
    if (valeur == NULL || strlen(valeur) == 0) {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : veuillez entrer une valeur à rechercher.");
        return; // Quitte la fonction si la valeur est vide
    }

    // Affichage du critère sélectionné pour debug
    switch (critere) {
        case 1:
            strcpy(critere_texte, "CIN");
            break;
        case 2:
            strcpy(critere_texte, "Nom");
            break;
        case 3:
            strcpy(critere_texte, "Numéro de téléphone");
            break;
        default:
            strcpy(critere_texte, "Inconnu");
    }

    // Pour le debug, afficher le critère et la valeur
    g_print("Critère sélectionné : %s\n", critere_texte);
    g_print("Valeur à rechercher : %s\n", valeur);

    // Tableau pour stocker les agents trouvés
    Agent agents_trouves[100];
    int compteur = 0;

    // Appel à la fonction de recherche avec le critère et la valeur
    if (chercher_agent(agentFileDirectory, valeur, critere + 1, agents_trouves, &compteur)) {
        gtk_label_set_text(GTK_LABEL(label_error), "Agents trouvés et affichés.");

        // Création du GtkTreeStore et ajout des agents trouvés
        GtkTreeStore *store = gtk_tree_store_new(10, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING,G_TYPE_STRING);
        GtkTreeIter iter;
        int i;
        // Ajouter les agents trouvés dans le GtkTreeStore
        for ( i = 0; i < compteur; i++) {
            gtk_tree_store_append(store, &iter, NULL); // Ajouter une ligne
            gtk_tree_store_set(store, &iter,
                               0, agents_trouves[i].cin,
                               1, agents_trouves[i].nom,
                               2, agents_trouves[i].prenom,
                               3, agents_trouves[i].date_naissance.jour,
                               4, agents_trouves[i].salaire,
                               5, agents_trouves[i].adresse,
                               6, agents_trouves[i].sexe,
                               7, agents_trouves[i].services[0], // exemple de service, vous pouvez ajouter plus de services si nécessaire
                               8, agents_trouves[i].numtel,
			       9, "-1",
                               -1);
        }

        // Assigner le modèle à la vue
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_agents), GTK_TREE_MODEL(store));
    } else {
        gtk_label_set_text(GTK_LABEL(label_error), "Aucun agent trouvé.");
    }
}

void on_mflistedesagents__clicked(GtkWidget *object, gpointer user_data) {
    
}


void on_mfbuttonappliquerreservation_clicked(GtkWidget *object, gpointer user_data) {


    // Get the calendar widget
    GtkCalendar *calendar = GTK_CALENDAR(lookup_widget(gtk_widget_get_toplevel(object), "mfcalendarreservation"));

    // Variables to hold day, month, and year
    guint year, month, day;

    // Retrieve the selected date from the calendar
    gtk_calendar_get_date(GTK_CALENDAR(calendar), &year, &month, &day);
    month++;
    // Continue with your existing logic to apply the reservation
    GtkTreeView *treeview = GTK_TREE_VIEW(lookup_widget(gtk_widget_get_toplevel(object), "mftreeviewaffichagereservations"));
    GtkLabel *label_erreur = GTK_LABEL(lookup_widget(gtk_widget_get_toplevel(object), "mflabelerreurres"));

    // Reset the GtkTreeView
    gtk_tree_view_set_model(treeview, NULL); 

    // Call the function to display reservations in the GtkTreeView
    updateReservationDisplayFile(reservationFileDirectory, reservationDisplayFileDirectory);
    filterReservationByDate(reservationDisplayFileDirectory, day, month, year);
    updateAdminReservationTreeview(object);
    
}

void initAdminReservationTreeview(GtkWidget *object) {
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
    updateAdminReservationTreeview(object);

    for (i = 0; i < 15; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAdminReservation), columnArray[i]);
    }
}


void updateAdminReservationTreeview(GtkWidget *object) {
    Reservation reservation;
    int i;
    GtkTreeStore *storeAdminReservation = gtk_tree_store_new(15,
    G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_STRING);
    treeviewAdminReservation = lookup_widget(object, "mftreeviewaffichagereservations");
    FILE *reservationFile = fopen(reservationDisplayFileDirectory, "r");
    while (scanReservation(reservationFile, &reservation) != EOF) {
        GtkTreeIter iter;
        gtk_tree_store_append(storeAdminReservation, &iter, NULL); // Add a new row
        gtk_tree_store_set(storeAdminReservation, &iter, 
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
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewAdminReservation), GTK_TREE_MODEL(storeAdminReservation));
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
on_ab_button_login_s_inscrire_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_login_oublie_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_login_connexion_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_rb_register_femme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_rb_register_homme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_cb_register_1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_cb_register_2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_cb_register_3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_cb_register_4_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_cb_register_5_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_cb_register_6_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ab_button_register1_enregistrer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_register1_quitter_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_register1_confirme_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_moto_ok_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_rs_ok_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_tun_ok_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_oublier_ok_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ab_button_oublier_annuler_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}

