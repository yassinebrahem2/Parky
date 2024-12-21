#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "service.h"



GtkWidget *entryIDParking;
GtkWidget *entryIDService;
GtkWidget *entryIDres;
GtkWidget *entryIDservice;
GtkWidget *ComboboxType;
GtkWidget *spinButtonDays;
GtkWidget *spinButtonHours;
GtkWidget *spinButtonCost;
GtkWidget *checkboxWeekend;
GtkWidget *checkboxJoursFeries;
GtkWidget *checkboxJoursOrdinaire;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;

GtkWidget *entryNewIDParking;
GtkWidget *entryNewIDService;
GtkWidget *entryNewIDres;
GtkWidget *entryNewIDservice;
GtkWidget *ComboboxNewType;
GtkWidget *spinButtonNewDays;
GtkWidget *spinButtonNewHours;
GtkWidget *spinButtonNewCost;
GtkWidget *checkboxNewWeekend;
GtkWidget *checkboxNewJoursFeries;
GtkWidget *checkboxNewJoursOrdinaire;
GtkWidget *radiobuttonNew1;
GtkWidget *radiobuttonNew2;

GtkWidget *ComboboxTypeFiltrer;
GtkWidget *output;
GtkWidget *togglebutton1, *togglebutton2, *togglebutton3;
GtkWidget *treeviewaffich;
GtkWidget *notif1;
GtkWidget *notif2;
GtkWidget *notif3;

GtkWidget *treeviewService;
GtkWidget *treeviewReservation;
GtkTreeStore *storeService;
GtkTreeStore *storeReservation;

Service service = {0};
Reservation reservation={0};
Service newService = {0};
char *serviceFileDirectory = "Data/service.txt";
char *serviceDisplayFileDirectory = "Cashe/serviceDisplay.txt";
char *reservationFileDirectory = "Data/reservation.txt";
char *reservationDisplayFileDirectory = "Cashe/reservationDisplay.txt";

char typeService[7][50] = {"Agent de sécurité",
                "Voiturier",
                "Lavage",
                "Technicien de maintenance",
                "Entretien de véhicule",
                "Service client",
                "Service de navette"};

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
    initServiceTreeview(widget);
    initReservationTreeview(widget);
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
on_AKTreeviewService_row_activated     (GtkWidget     *object,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    GtkTreeModel *model = gtk_tree_view_get_model(object);
    GtkTreeIter iter;
    char *ID, *ID_Parking, *reservationID, *type;
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 
            0, &ID,
            1, &ID_Parking,
            2, &reservationID,
	    3, &type,
            4, &service.tarif,
            5, &service.dispo[0],
            6, &service.dispo[1],
            7, &service.dispo[2],
            8, &service.horaire,
            9, &service.dureeJ,
            10, &service.dureeH,
            -1);
        strcpy(service.ID, ID);
        strcpy(service.ID_Parking, ID_Parking);
	strcpy(service.reservationID, reservationID);
        strcpy(service.type, type);
        g_free(ID); g_free(ID_Parking); g_free(type), g_free(reservationID);
        setServiceInputs(object, service);
        GtkWidget *modifyButton = lookup_widget(object, "AKButtonModifier");
        GtkWidget *deleteButton = lookup_widget(object, "AKButtonSupprimer");
        gtk_widget_set_sensitive(modifyButton, TRUE);
        gtk_widget_set_sensitive(deleteButton, TRUE);

    }
}

void setServiceInputs(GtkWidget *object, Service service) {
    int i;
    entryIDParking = lookup_widget(object, "AKServiceEntryIDParking");
    entryIDService = lookup_widget(object, "AKServiceEntryIDService");

    spinButtonDays = lookup_widget(object, "AKServiceSpinbuttonNbJours");
    spinButtonHours = lookup_widget(object, "AKServiceSpinbuttonNbHeures");
    spinButtonCost = lookup_widget(object, "AKServiceSpinbuttonTarif");

    ComboboxType = lookup_widget(object, "AKServiceComboboxentryType");

    checkboxWeekend = lookup_widget(object, "AKServiceCheckboxWeekend");
    checkboxJoursFeries = lookup_widget(object, "AKServiceCheckboxJoursFeries");
    checkboxJoursOrdinaire = lookup_widget(object, "AKServiceCheckbuttonJoursOrdinaire");

    radiobutton1 = lookup_widget(object, "AKServiceRadiobutton1");
    radiobutton2 = lookup_widget(object, "AkServiceRadiobutton2");

    gtk_entry_set_text(GTK_ENTRY(entryIDParking), service.ID_Parking);
    gtk_entry_set_text(GTK_ENTRY(entryIDService), service.ID);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonDays), service.dureeJ);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonHours), service.dureeH);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonCost), service.tarif);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxJoursOrdinaire), service.dispo[0]);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxWeekend), service.dispo[1]);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxJoursFeries), service.dispo[2]);

    gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton1), !service.horaire);
    gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton2), service.horaire);

    for(i = 0; i < 7; i++) {
        if(strcmp(typeService[i], service.type) == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(ComboboxType), i);
            break;
        }
    }
    
}

void initServiceTreeview(GtkWidget *object) {
    int i;
    GtkCellRenderer *rendererArray[11];
    GtkTreeViewColumn *columnArray[11];
    const char header[11][30] = {
        "ID Service", "ID Parking", "ID Reservation", "Type", 
        "tarif", "Jours ordinaires", "Weekend", "Jours Feries", 
		"Horaire", "Duree Jour", "Duree Heur"
        };
    updateServiceDisplayFile();
    updateServiceTreeview(object);

    for (i = 0; i < 11; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewService), columnArray[i]);
    }
}


void updateServiceTreeview(GtkWidget *object) {
    Service service;
    int i;
    storeService = gtk_tree_store_new(11,
    G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_FLOAT,
    G_TYPE_INT, G_TYPE_INT,
	G_TYPE_INT, G_TYPE_INT,
	G_TYPE_INT, G_TYPE_INT);
    treeviewService = lookup_widget(object, "AKTreeviewService");
    FILE *serviceFile = fopen(serviceDisplayFileDirectory, "r");
    while (scanService(serviceFile, &service) != EOF) {
        GtkTreeIter iter;
        gtk_tree_store_append(storeService, &iter, NULL); // Add a new row
        gtk_tree_store_set(storeService, &iter, 
            0, service.ID,
            1, service.ID_Parking,
	    2, service.reservationID,
            3, service.type,
            4, service.tarif,
	    5, service.dispo[0],
	    6, service.dispo[1],
	    7, service.dispo[2],
            8, service.horaire,
	    9, service.dureeJ,
	    10, service.dureeH,
            -1);
    }
	fclose(serviceFile);
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewService), GTK_TREE_MODEL(storeService));
}

void updateServiceDisplayFile() {
    Service service;
    FILE *serviceFile = fopen(serviceFileDirectory, "r");
    FILE *serviceDisplayFile = fopen(serviceDisplayFileDirectory, "w");
    while (scanService(serviceFile, &service) != EOF) {
        printService(serviceDisplayFile, service);
    }
    fclose(serviceFile);
    fclose(serviceDisplayFile);
}


void
on_AKButtonChercher_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
    char type[30];
    GtkWidget *comboboxentryType = lookup_widget(object, "AKComboboxentryTypeFiltrer");
    strcpy(type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryType)));

    searchService(serviceFileDirectory, serviceDisplayFileDirectory, type);

    updateServiceTreeview(object);
}


void
on_AKTreeviewReservation_row_activated (GtkWidget     *object,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeModel *model = gtk_tree_view_get_model(object);
	GtkTreeIter iter;
	char *idreservation, *cin, *parkingID, *mat, *type;
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 
            0, &idreservation,
            1, &cin,
	    2, &parkingID,
            3, &reservation.jours,
	    4, &reservation.mois,
	    5, &reservation.annee,
            6, &reservation.heureh,
	    7, &reservation.heuremin,
            8, &reservation.dureeh,
            9, &reservation.dureemin,
            10, &mat,
            11, &reservation.methpai,
            12, &reservation.demspec,
            13, &type,
            -1);
        strcpy(reservation.idreservation, idreservation);
        strcpy(reservation.cin, cin);
	strcpy(reservation.parkingID, parkingID);
	strcpy(reservation.mat, mat);
        strcpy(reservation.type, type);
        g_free(idreservation); g_free(parkingID); g_free(cin); g_free(mat); g_free(type);

        GtkWidget *affecterButton = lookup_widget(object, "AKButtonAffecter");
        gtk_widget_set_sensitive(affecterButton, TRUE);
    
    }
}

void initReservationTreeview(GtkWidget *object) {
    int i;
    GtkCellRenderer *rendererArray[14];
    GtkTreeViewColumn *columnArray[14];
    const char header[13][30] = {
        "ID Reservation", "CIN", "ID Parking", "Jours", "Mois", "Annee",
        "HeureH", "HeureMin", "DureeH", "DureeMin", 
		"mat", "methpai", "demspec", "type"
        };
    updateReservationDisplayFile();
    updateReservationTreeview(object);

    for (i = 0; i < 14; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewReservation), columnArray[i]);
    }
}
void updateReservationDisplayFile() {
    Reservation reservation;
    FILE *reservationFile = fopen(reservationFileDirectory, "r");
    FILE *reservationDisplayFile = fopen(reservationDisplayFileDirectory, "w");
    while (scanReservation(reservationFile, &reservation) != EOF) {
        printReservation(reservationDisplayFile, reservation);
    }
    fclose(reservationFile);
    fclose(reservationDisplayFile);
}
char idreservation[8];
    char parkingID[8];
    char cin[8];
    int jours, mois, annee;
    int heureh, heuremin;
    int dureeh, dureemin;
    char mat[15];
    int methpai;
    int demspec[2];
    char type[50];

void updateReservationTreeview(GtkWidget *object) {
    int i;
    storeReservation = gtk_tree_store_new(14,
    G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_STRING
    );

    treeviewReservation = lookup_widget(object, "AKTreeviewReservation");
    FILE *reservationDisplayFile = fopen(reservationDisplayFileDirectory, "r");
    while (scanReservation(reservationDisplayFile, &reservation) != EOF) {
        GtkTreeIter iter;
        gtk_tree_store_append(storeReservation, &iter, NULL); // Add a new row
        gtk_tree_store_set(storeReservation, &iter, 
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
            11,reservation.methpai,
            12, reservation.demspec,
            13, reservation.type,
            -1);
    }
    fclose(reservationDisplayFile);
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewReservation), GTK_TREE_MODEL(storeReservation));
}


void
on_AKButtonAffecter_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
    notif2=lookup_widget(object,"AKReservationLabelNotif");


    affecter_service(serviceFileDirectory, service, reservation);
    updateServiceDisplayFile();
    updateServiceTreeview(object);

    if ((strcmp(reservation.idreservation, "") == 0)) { 
        gtk_label_set_text(GTK_LABEL(notif2), "Erreur: aucune reservation selectionnée");
    }
    else {
	if ((strcmp(service.ID, "") == 0)) { 
        	gtk_label_set_text(GTK_LABEL(notif2), "Erreur: aucun service selectionné");
    	}
	else { 
    		gtk_label_set_text(GTK_LABEL(notif2), "service affecté avec succès");} }
	
}


void
on_AKServiceCheckboxWeekend_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    service.dispo[1] = gtk_toggle_button_get_active(togglebutton);
}


void
on_AKServiceCheckbuttonJoursOrdinaire_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    service.dispo[0] = gtk_toggle_button_get_active(togglebutton);
}


void
on_AKServiceCheckboxJoursFeries_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    service.dispo[2] = gtk_toggle_button_get_active(togglebutton);
}


void
on_AKServiceRadiobutton1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
		service.horaire=0;}
    
}


void
on_AkServiceRadiobutton2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
		service.horaire=1;}
}


void
on_AKButtonConfirmer_clicked           (GtkWidget       *object,
                                        gpointer         user_data)
{
    getServiceInputs(object, &service);
    modifyService(serviceFileDirectory, service);
    setSensitivityServiceInputs(FALSE);
    GtkWidget *confirmButton = lookup_widget(object, "AKButtonConfirmer");
    gtk_widget_set_sensitive(confirmButton, FALSE);

    updateServiceDisplayFile();
    updateServiceTreeview(object);

    notif1 = lookup_widget(object, "AKServiceLabelNotif");
    gtk_label_set_text(GTK_LABEL(notif1), "service modifié avec succès");
}


void
on_AKButtonModifier_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
	setSensitivityServiceInputs(TRUE);
	GtkWidget *confirmButton = lookup_widget(object, "AKButtonConfirmer");
	gtk_widget_set_sensitive(confirmButton, TRUE);	
}

void setSensitivityServiceInputs(gboolean sensitivity) {
    gtk_widget_set_sensitive(entryIDParking, sensitivity);
    gtk_widget_set_sensitive(entryIDService, sensitivity);
    gtk_widget_set_sensitive(spinButtonDays, sensitivity);
    gtk_widget_set_sensitive(spinButtonHours, sensitivity);
    gtk_widget_set_sensitive(spinButtonCost, sensitivity);
    gtk_widget_set_sensitive(ComboboxType, sensitivity);
    gtk_widget_set_sensitive(checkboxWeekend, sensitivity);
    gtk_widget_set_sensitive(checkboxJoursFeries, sensitivity);
    gtk_widget_set_sensitive(checkboxJoursOrdinaire, sensitivity);
    gtk_widget_set_sensitive(radiobutton1, sensitivity);
    gtk_widget_set_sensitive(radiobutton2, sensitivity);
}

void
on_AKButtonSupprimer_clicked           (GtkWidget       *object,
                                        gpointer         user_data)
{
    getServiceInputs(object, &service);
    supprimer(serviceFileDirectory, service.ID);

    updateServiceDisplayFile();
    updateServiceTreeview(object);
    
    notif1 = lookup_widget(object, "AKServiceLabelNotif");
    gtk_label_set_text(GTK_LABEL(notif1), "service supprimé avec succès");
}

void getServiceInputs(GtkWidget *object, Service *service) {
    entryIDParking = lookup_widget(object, "AKServiceEntryIDParking");
	entryIDService = lookup_widget(object, "AKServiceEntryIDService");

    spinButtonDays = lookup_widget(object, "AKServiceSpinbuttonNbJours");
    spinButtonHours = lookup_widget(object, "AKServiceSpinbuttonNbHeures");
	spinButtonCost = lookup_widget(object, "AKServiceSpinbuttonTarif");

	ComboboxType= lookup_widget(object, "AKServiceComboboxentryType");

	strcpy(service->ID, gtk_entry_get_text(GTK_ENTRY(entryIDService)));
	strcpy(service->ID_Parking, gtk_entry_get_text(GTK_ENTRY(entryIDParking)));
	
	service->dureeJ = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonDays));
	service->dureeH = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonHours));
	service->tarif = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonCost));

    strcpy(service->type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxType)));
	
	
}


void
on_AKNouveauCheckboxJoursordinaires_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newService.dispo[0]= gtk_toggle_button_get_active(togglebutton);
}


void
on_AKNouveauCheckboxDispoWeekend_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newService.dispo[1]= gtk_toggle_button_get_active(togglebutton);
}


void
on_AKNouveauCheckboxJoursferies_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newService.dispo[2]= gtk_toggle_button_get_active(togglebutton);
}


void
on_AKNouveauRadiobutton1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(togglebutton)) {
            newService.horaire=0;}
}


void
on_AKNouveauRadiobutton2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(togglebutton)) {
            newService.horaire=1;}
}


void
on_AKButtonAjouter_clicked             (GtkWidget       *object,
                                        gpointer         user_data)
{
    char text[100];
    int value;
    getNewServiceInputs(object, &newService);
    strcpy(newService.reservationID, "-1");
    int isValid = isValidService(newService);
    notif3 = lookup_widget(object, "AKNouveauLabelNotif");

    value = 0;
    if (isValid) {
   	 value= addService(serviceFileDirectory, newService);
	 if (value>0){
		strcpy(text, "Service ajouté avec succès");
		clearNewServiceEntries(object);
	 } else {
		strcpy(text, "Erreur");
	 }
     } else {
         strcpy(text, "Erreur");
     }

    gtk_label_set_text(GTK_LABEL(notif3), text);
    updateServiceDisplayFile();
    updateServiceTreeview(object);
}
int isValidService(Service newService) { 
    int value;
    if ((strcmp(newService.ID, "") == 0) || (strcmp(newService.ID_Parking, "") == 0) || (strcmp(newService.type, "") == 0) ){
        value=0;;
    } else{
    	value= 1;}
    return value;
}


void getNewServiceInputs(GtkWidget *object, Service *service) {
    entryNewIDParking = lookup_widget(object, "AKNouveauEntryIDParking");
	entryNewIDService = lookup_widget(object, "AKNouveauEntryIDService");

        spinButtonNewDays = lookup_widget(object, "AKNouveauSpinbuttonNbjours");
	spinButtonNewHours = lookup_widget(object, "AKNouveauSpinbuttonNbheures");
	spinButtonNewCost = lookup_widget(object, "AKNouveauSpinbuttonTarif");
	ComboboxNewType = lookup_widget(object, "AKNouveauComboboxentryType");

   	 checkboxNewWeekend = lookup_widget(object, "AKNouveauCheckboxDispoWeekend");
    	 checkboxNewJoursFeries = lookup_widget(object, "AKNouveauCheckboxJoursferies");
   	 checkboxNewJoursOrdinaire = lookup_widget(object, "AKNouveauCheckboxJoursordinaires");

          radiobuttonNew1 = lookup_widget(object, "AKNouveauRadiobutton1");


	strcpy(service->ID, gtk_entry_get_text(GTK_ENTRY(entryNewIDService)));
	strcpy(service->ID_Parking, gtk_entry_get_text(GTK_ENTRY(entryNewIDParking)));
	
	service->dureeJ = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonNewDays));
	service->dureeH = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonNewHours));
	service->tarif = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonNewCost));

	strcpy(service->type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxNewType)));
}

void clearNewServiceEntries(GtkWidget *object) {
    gtk_entry_set_text(GTK_ENTRY(entryNewIDParking), "");
    gtk_entry_set_text(GTK_ENTRY(entryNewIDService), "");

    gtk_combo_box_set_active(GTK_COMBO_BOX(ComboboxNewType), 0);

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonNewDays), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonNewHours), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonNewCost), 0);

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxNewWeekend), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxNewJoursFeries), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxNewJoursOrdinaire), FALSE);

    gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobuttonNew1), TRUE);
}

void
on_AKButtonDisplayServiceTreeview_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
    initServiceTreeview(object);
    initReservationTreeview(object);
}


void
on_AKButtonAnnuler_clicked             (GtkWidget       *object,
                                        gpointer         user_data)
{
    updateServiceDisplayFile();
    updateServiceTreeview(object);
}


void
on_mfbuttonappliquerreservation_clicked
                                        (GtkButton       *button,
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


void
on_mflistedesagents_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}




