#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "parking.h"


GtkWidget *treeviewParking;
GtkWidget *treeviewParkingAgents;
GtkTreeStore *storeAgent;

GtkWidget *entryParkingID;
GtkWidget *entryParkingNbSpots;
GtkWidget *entryParkingAddress;
GtkWidget *entryParkingMunic;
GtkWidget *entryParkingPrice;
GtkWidget *checkboxParkingCar;
GtkWidget *checkboxParkingTruck;
GtkWidget *checkboxParkingBike;
GtkWidget *checkboxParkingBicycle;
GtkWidget *radiobuttonParkingHasElectric;
GtkWidget *radiobuttonParkingNotHasElectric;

GtkWidget *entryNewID;
GtkWidget *entryNewNbSpots;
GtkWidget *entryNewAddress;
GtkWidget *entryNewMunic;
GtkWidget *entryNewPrice;
GtkWidget *checkboxNewCar;
GtkWidget *checkboxNewTruck;
GtkWidget *checkboxNewBike;
GtkWidget *checkboxNewBicycle;
GtkWidget *radiobuttonNewNotHasElectric;

GtkWidget *comboboxEntryAgent;

GtkWidget *entrySearchParking;
GtkWidget *spinbuttonSearchPriceFrom;
GtkWidget *spinbuttonSearchSpotsFrom;
GtkWidget *spinbuttonSearchPriceTo;
GtkWidget *spinbuttonSearchSpotsTo;
int entrySearchSetting = 0;
int searchHasElectricCharger = -1;
int checkboxSearchVehicules[4] = {1, 1, 1, 1};

int parkingSortBy = 0;
int parkingSortOption = 0;


GtkWidget *labelNewParkingNotification;
GtkWidget *labelParkingNotification;
GtkWidget *labelAgentNotification;

Parking parking;
Parking newParking;
GtkTreeStore *store;
Agent agent;


char municipality[20][100] = {"munic1", "munic2", "munic3", "munic4", "munic5"};
char *parkingFileDirectory = "Data/parking.txt";
char *agentFileDirectory = "Data/agent.txt";
char *parkingDisplayFileDirectory = "Cashe/parkingDisplay.txt";
char *parkingAgentsDisplayFileDirectory = "Cashe/parkingAgentsDisplay.txt";


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
    initFiles();
    initParkingTreeview(widget);
    initParkingAgentsTreeview(widget);
    fillComboboxAvailableAgents(widget);
}


void
on_YBButtonChercher_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
    char searchText[50];
    float searchPrice[2] = {0, 0};
    int searchNumberOfSpots[2] = {0, 0};
    updateParkingDisplayFile(parkingFileDirectory, parkingDisplayFileDirectory);
    entrySearchParking = lookup_widget(object, "YBEntryFiltre");
    spinbuttonSearchPriceFrom = lookup_widget(object, "YBSpinbuttonPrixDe");
    spinbuttonSearchPriceTo = lookup_widget(object, "YBSpinbuttonPrixA");
    spinbuttonSearchSpotsFrom = lookup_widget(object, "YBSpinbuttonNbplaceDe");
    spinbuttonSearchSpotsTo = lookup_widget(object, "YBSpinbuttonNbplaceA");
    strcpy(searchText, gtk_entry_get_text(GTK_ENTRY(entrySearchParking)));
    searchPrice[0] = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbuttonSearchPriceFrom));
    searchPrice[1] = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbuttonSearchPriceTo));
    searchNumberOfSpots[0] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonSearchSpotsFrom));
    searchNumberOfSpots[1] = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonSearchSpotsTo));
    
    filterByText(parkingDisplayFileDirectory, searchText, entrySearchSetting);
    if (searchHasElectricCharger != -1) {
        filterbyHasElectricCharger(parkingDisplayFileDirectory, searchHasElectricCharger);
    }
    filterbyVehicule(parkingDisplayFileDirectory, checkboxSearchVehicules);

    if (searchPrice[0] != 0 || searchPrice[1] != 0) {
        filterByPrice(parkingDisplayFileDirectory, searchPrice[0], searchPrice[1]);
    }
    if (searchNumberOfSpots[0] != 0 || searchNumberOfSpots[1] != 0) {
        filterBySpots(parkingDisplayFileDirectory, searchNumberOfSpots[0], searchNumberOfSpots[1]);
    }
    

    
    
    updateParkingTreeview(object);
}

void initParkingTreeview(GtkWidget *object) {
    int i;
    GtkCellRenderer *rendererArray[10];
    GtkTreeViewColumn *columnArray[10];
    const char header[10][20] = {
        "ID", "Nombre de places", "Adresse", 
        "Municipalite", "Prix", "Chargeur Electrique", 
        "Voiture", "Camion", "Moto", "Velo"};

    updateParkingTreeview(object);

    for (i = 0; i < 10; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewParking), columnArray[i]);
    }
}

void updateParkingTreeview(GtkWidget *object) {
    Parking parking;
    int i;
    store = gtk_tree_store_new(10, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
    treeviewParking = lookup_widget(object, "YBTreeviewParking");

    sortParkingDisplay();
    FILE *parkingFile = fopen(parkingDisplayFileDirectory, "r");
    while (scanParking(parkingFile, &parking) != EOF) {
        GtkTreeIter iter;
        gtk_tree_store_append(store, &iter, NULL); // Add a new row
        gtk_tree_store_set(store, &iter, 
            0, parking.ID,
            1, parking.numberOfSpots,
            2, parking.address,
            3, parking.municipality,
            4, parking.price,
            5, parking.hasElectricCharger,
            6, parking.vehicules[0],
            7, parking.vehicules[1],
            8, parking.vehicules[2],
            9, parking.vehicules[3],
            -1);
    }
    fclose(parkingFile);
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewParking), GTK_TREE_MODEL(store));
}

void sortParkingDisplay() {
    int (*sortFunction)(Parking, Parking, int);
    if (parkingSortBy == 0) {
        sortFunction = IDInRange;
    } else if (parkingSortBy == 1) {
        sortFunction = spotsInRange;
    } else if (parkingSortBy == 2) {
        sortFunction = addressInRange;
    } else if (parkingSortBy == 3) {
        sortFunction = municipalityInRange;
    } else if (parkingSortBy == 4) {
        sortFunction = priceInRange;
    }
    sortParking(parkingDisplayFileDirectory, sortFunction, parkingSortOption);
}


void
on_YBButtonModifier_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
    setSensitivityParkingInputs(TRUE);
    GtkWidget *confirmButton = lookup_widget(object, "YBButtonConfirmer");
    gtk_widget_set_sensitive(confirmButton, TRUE);
}


void
on_YBButtonConfirmer_clicked           (GtkWidget       *object,
                                        gpointer         user_data)
{
    char notification[50] = "Selected Parking Has Been Modified Successfully";
    GtkWidget * labelParkingNotification = lookup_widget(object, "YBParkingLabelNotif");
    GtkWidget *confirmButton = lookup_widget(object, "YBButtonConfirmer");
    gtk_widget_set_sensitive(confirmButton, FALSE);
    setSensitivityParkingInputs(FALSE);
    getParkingInputs(object, &parking);
    int error = modifyParking(parkingFileDirectory, parking);
    updateParkingDisplayFile(parkingFileDirectory, parkingDisplayFileDirectory);
    
    updateParkingTreeview(object);
    if (error) {
        strcpy(notification, "An Error Has Occurred");
    }
    gtk_label_set_text(GTK_LABEL(labelParkingNotification),notification);
}

void setSensitivityParkingInputs(gboolean sensitivity) {
    gtk_widget_set_sensitive(entryParkingID, sensitivity);
    gtk_widget_set_sensitive(entryParkingNbSpots, sensitivity);
    gtk_widget_set_sensitive(entryParkingAddress, sensitivity);
    gtk_widget_set_sensitive(entryParkingMunic, sensitivity);
    gtk_widget_set_sensitive(entryParkingPrice, sensitivity);
    gtk_widget_set_sensitive(checkboxParkingCar, sensitivity);
    gtk_widget_set_sensitive(checkboxParkingTruck, sensitivity);
    gtk_widget_set_sensitive(checkboxParkingBike, sensitivity);
    gtk_widget_set_sensitive(checkboxParkingBicycle, sensitivity);
    gtk_widget_set_sensitive(radiobuttonParkingHasElectric, sensitivity);
    gtk_widget_set_sensitive(radiobuttonParkingNotHasElectric, sensitivity);
}

void
on_YBButtonSupprimer_clicked           (GtkWidget       *object,
                                        gpointer         user_data)
{
    char notification[50] = "Selected Parking Has Been Deleted Successfully";
    GtkWidget * labelParkingNotification = lookup_widget(object, "YBParkingLabelNotif");
    GtkWidget *confirmButton = lookup_widget(object, "YBButtonConfirmer");
    GtkWidget *deleteButton = lookup_widget(object, "YBButtonSupprimer");
    GtkWidget *modifyButton = lookup_widget(object, "YBButtonModifier");
    gtk_widget_set_sensitive(confirmButton, FALSE);
    gtk_widget_set_sensitive(confirmButton, FALSE);
    gtk_widget_set_sensitive(confirmButton, FALSE);
    setSensitivityParkingInputs(FALSE);
    int error = deleteParking(parkingFileDirectory, parking.ID);

    updateParkingDisplayFile(parkingFileDirectory, parkingDisplayFileDirectory);
    updateParkingTreeview(object);
    if (error) {
        strcpy(notification, "An Error Has Occurred");
    }
    gtk_label_set_text(GTK_LABEL(labelParkingNotification),notification);
}


void
on_YBButtonAjouter_clicked             (GtkWidget       *object,
                                        gpointer         user_data)
{
    char notification[30];
    int value;
    
    getNewParkingInputs(object, &newParking);
    int isValid = isValidParking(newParking);

    value = 0;
    if (isValid) {
        value = addParking(parkingFileDirectory, newParking);
        if (value > 0) {
            strcpy(notification, "Parking Added Successfully");
            clearNewParkingEntries(object);
        } else {
            strcpy(notification, "An Error Has Occurred");
        }
    } else {
        strcpy(notification, "An Error Has Occurred");
    }

    gtk_label_set_text(GTK_LABEL(labelNewParkingNotification),notification);
    updateParkingDisplayFile(parkingFileDirectory, parkingDisplayFileDirectory);
    updateParkingTreeview(object);
}

int isValidParking(Parking parking) { 
    if ((strcmp(parking.ID, "") == 0) || (strcmp(parking.address, "") == 0) || (strcmp(parking.municipality, "") == 0) ||
        (parking.price == 0) || (parking.numberOfSpots == 0)) {
        return 0;
    }
    if (!((parking.vehicules[0] != 0) || (parking.vehicules[1] != 0) || (parking.vehicules[2] != 0) || (parking.vehicules[3] != 0))) {
        return 0;
    }
    return 1;
}

int getNewParkingInputs(GtkWidget *object, Parking *newParking) {
    entryNewID = lookup_widget(object, "YBNouveauEntryID");
    entryNewNbSpots = lookup_widget(object, "YBNouveauSpinButtonNbplace");
    entryNewAddress = lookup_widget(object, "YBNouveauEntryAdresse");
    entryNewMunic = lookup_widget(object, "YBNouveauComboboxentryMunic");
    entryNewPrice = lookup_widget(object, "YBNouveauSpinButtonPrix");
    
    checkboxNewCar = lookup_widget(object, "YBNouveauCheckboxVoiture");
    checkboxNewTruck = lookup_widget(object, "YBNouveauCheckboxCamion");
    checkboxNewBike = lookup_widget(object, "YBNouveauCheckboxMoto");
    checkboxNewBicycle = lookup_widget(object, "YBNouveauCheckboxVelo");

    radiobuttonNewNotHasElectric = lookup_widget(object, "YBNouveauRadiobuttonNon");

    labelNewParkingNotification = lookup_widget(object, "YBNouveauLabelNotif");

    strcpy(newParking->ID, gtk_entry_get_text(GTK_ENTRY(entryNewID)));
    newParking->numberOfSpots = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryNewNbSpots));
    strcpy(newParking->address, gtk_entry_get_text(GTK_ENTRY(entryNewAddress)));
    strcpy(newParking->municipality, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryNewMunic)));
    newParking->price = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryNewPrice));
    return 0;
}

void clearNewParkingEntries(GtkWidget *object) {
    gtk_entry_set_text(GTK_ENTRY(entryNewID), "");
    gtk_entry_set_text(GTK_ENTRY(entryNewAddress), "");
    gtk_combo_box_set_active(GTK_COMBO_BOX(entryNewMunic), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewNbSpots), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewPrice), 0);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxNewCar), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxNewTruck), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxNewBicycle), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxNewBike), FALSE);
    gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobuttonNewNotHasElectric), TRUE);
}


void
on_YBFiltreRadiobuttonOui_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton)) {
        searchHasElectricCharger = 1;
    }
}


void
on_YBFiltreRadiobuttonNon_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton)) {
        searchHasElectricCharger = 0;
    }
}


void
on_YBFiltreCheckboxVoiture_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    checkboxSearchVehicules[0] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBFiltreCheckboxCamion_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    checkboxSearchVehicules[1] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBFiltreCheckboxMoto_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    checkboxSearchVehicules[2] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBFiltreCheckboxVelo_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    checkboxSearchVehicules[3] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBFiltreRadiobuttonID_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton)) {
        entrySearchSetting = 0;
    }
}


void
on_YBFiltreRadiobuttonAdresse_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton)) {
        entrySearchSetting = 1;
    }
}


void
on_YBFiltreRadiobuttonMunic_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton)) {
        entrySearchSetting = 2;
    }
}


void
on_YBParkingCheckboxVoiture_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    parking.vehicules[0] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBParkingCheckboxCamion_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    parking.vehicules[1] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBParkingCheckboxMoto_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    parking.vehicules[2] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBParkingCheckboxVelo_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    parking.vehicules[3] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBParkingRadiobuttonOui_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    parking.hasElectricCharger = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBParkingRadiobuttonNon_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBNouveauCheckboxVoiture_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newParking.vehicules[0] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBNouveauCheckboxCamion_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newParking.vehicules[1] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBNouveauCheckboxMoto_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newParking.vehicules[2] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBNouveauCheckboxVelo_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newParking.vehicules[3] = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBNouveauRadiobuttonOui_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    newParking.hasElectricCharger = gtk_toggle_button_get_active(togglebutton);
}


void
on_YBNouveauRadiobuttonNon_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_YBButtonRevoquer_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
    char notification[50] = "Selected Agent Has Been Revoqued Successfully";
    GtkWidget * labelParkingNotification = lookup_widget(object, "YBAgentLabelNotif");
    char agentCIN[20];
    
    strcpy(agentCIN, agent.cin);
    searchAgentByCIN(agentFileDirectory, agentCIN, &agent);
    strcpy(agent.id_parking, "-1");

    int error = modifyAgent(agentFileDirectory, agent);
    filterParkingAgents(agentFileDirectory, parkingAgentsDisplayFileDirectory, parking);
    updateParkingAgentsTreeview(object);

    if (error) {
        strcpy(notification, "An Error Has Occurred");
    }
    gtk_label_set_text(GTK_LABEL(labelParkingNotification),notification);
    
}


void
on_YBButtonAffecter_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
    char notification[50] = "Selected Agent Has Been Assigned Successfully";
    GtkWidget * labelParkingNotification = lookup_widget(object, "YBAgentLabelNotif");
    comboboxEntryAgent = lookup_widget(object, "YBComboboxentryAgent");
    char agentCIN[20];
    Agent agent;
    
    strcpy(agentCIN, gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxEntryAgent)));
    searchAgentByCIN(agentFileDirectory, agentCIN, &agent);
    strcpy(agent.id_parking, gtk_entry_get_text(GTK_ENTRY(entryParkingID)));

    int error = modifyAgent(agentFileDirectory, agent);
    filterParkingAgents(agentFileDirectory, parkingAgentsDisplayFileDirectory, parking);
    updateParkingAgentsTreeview(object);

    if (error) {
        strcpy(notification, "An Error Has Occurred");
    }
    gtk_label_set_text(GTK_LABEL(labelParkingNotification),notification);
    
}

void initFiles() {
    FILE *parkingFile = fopen(parkingFileDirectory, "a");
    fclose(parkingFile);
    FILE *agentFile = fopen(agentFileDirectory, "a");
    fclose(agentFile);
    FILE *parkingAgentsDisplayFile = fopen(parkingAgentsDisplayFileDirectory, "w");
    fclose(parkingAgentsDisplayFile);
    updateParkingDisplayFile(parkingFileDirectory, parkingDisplayFileDirectory);
}


void
on_YBTreeviewParking_row_activated     (GtkWidget     *object,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    GtkTreeModel *model = gtk_tree_view_get_model(object);
    GtkTreeIter iter;
    char *id, *address, *munic;
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 
        0, &id,
        1, &parking.numberOfSpots,
        2, &address,
        3, &munic,
        4, &parking.price,
        5, &parking.hasElectricCharger,
        6, &parking.vehicules[0],
        7, &parking.vehicules[1],
        8, &parking.vehicules[2],
        9, &parking.vehicules[3],
        -1);
        strcpy(parking.ID, id);
        strcpy(parking.address, address);
        strcpy(parking.municipality, munic);
        g_free(id); g_free(address); g_free(munic);
        setParkingInputs(object, parking);
        GtkWidget *modifyButton = lookup_widget(object, "YBButtonModifier");
        GtkWidget *deleteButton = lookup_widget(object, "YBButtonSupprimer");
        gtk_widget_set_sensitive(modifyButton, TRUE);
        gtk_widget_set_sensitive(deleteButton, TRUE);
    
        filterParkingAgents(agentFileDirectory, parkingAgentsDisplayFileDirectory, parking);
        updateParkingAgentsTreeview(object);

    }
}

void fillComboboxAvailableAgents(GtkWidget *object) {
    int numAvailableAgents = getNumAvailableAgents(agentFileDirectory);
    Agent *availableAgents = filterAvailableAgents(agentFileDirectory, numAvailableAgents);
    int i;
    comboboxEntryAgent = lookup_widget(object, "YBComboboxentryAgent");
    for (i = 0; i < numAvailableAgents; i++) {
        gtk_combo_box_append_text(GTK_COMBO_BOX(comboboxEntryAgent), availableAgents[i].cin);
    }
    free(availableAgents);
}

void initParkingAgentsTreeview(GtkWidget *object) {
    int i;
    GtkCellRenderer *rendererArray[6];
    GtkTreeViewColumn *columnArray[6];
    const char header[6][30] = {
        "CIN", "Nom", "Prenom", 
        "Service", "Salaire", "Numero telephone"
        };
    updateParkingAgentsTreeview(object);

    for (i = 0; i < 6; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewParkingAgents), columnArray[i]);
    }
}


void updateParkingAgentsTreeview(GtkWidget *object) {
    Agent agent;
    int i;
    storeAgent = gtk_tree_store_new(6,
    G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_STRING);
    treeviewParkingAgents = lookup_widget(object, "YBTreeviewAgent");
    
    FILE *parkingAgentsFile = fopen(parkingAgentsDisplayFileDirectory, "r");
    while (scanAgent(parkingAgentsFile, &agent) != EOF) {
        GtkTreeIter iter;
        char services[100];
        getServicesChar(services, agent);
        gtk_tree_store_append(storeAgent, &iter, NULL); // Add a new row
        gtk_tree_store_set(storeAgent, &iter, 
            0, agent.cin,
            1, agent.nom,
            2, agent.prenom,
            3, services,
            4, agent.salaire,
            5, agent.numtel,
            -1);
    }
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewParkingAgents), GTK_TREE_MODEL(storeAgent));
}



void setParkingInputs(GtkWidget *object, Parking parking) {
    int i;
    entryParkingID = lookup_widget(object, "YBParkingEntryID");
    
    entryParkingNbSpots = lookup_widget(object, "YBParkingSpinButtonNbplace");
    entryParkingAddress = lookup_widget(object, "YBParkingEntryAdresse");
    entryParkingMunic = lookup_widget(object, "YBParkingComboboxentryMunic");
    entryParkingPrice = lookup_widget(object, "YBParkingSpinButtonPrix");
    
    checkboxParkingCar = lookup_widget(object, "YBParkingCheckboxVoiture");
    checkboxParkingTruck = lookup_widget(object, "YBParkingCheckboxCamion");
    checkboxParkingBike = lookup_widget(object, "YBParkingCheckboxMoto");
    checkboxParkingBicycle = lookup_widget(object, "YBParkingCheckboxVelo");

    radiobuttonParkingHasElectric = lookup_widget(object, "YBParkingRadiobuttonOui");
    radiobuttonParkingNotHasElectric = lookup_widget(object, "YBParkingRadiobuttonNon");

    gtk_entry_set_text(GTK_ENTRY(entryParkingID), parking.ID);
    gtk_entry_set_text(GTK_ENTRY(entryParkingAddress), parking.address);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryParkingNbSpots), parking.numberOfSpots);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryParkingPrice), parking.price);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxParkingCar), parking.vehicules[0]);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxParkingTruck), parking.vehicules[1]);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxParkingBike), parking.vehicules[2]);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkboxParkingBicycle), parking.vehicules[3]);
    gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobuttonParkingNotHasElectric), !parking.hasElectricCharger);
    gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobuttonParkingHasElectric), parking.hasElectricCharger);

    for(i = 0; i < 5; i++) {
        if(strcmp(municipality[i], parking.municipality) == 0) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(entryParkingMunic), i);
            break;
        }
    }
    
}


void getParkingInputs(GtkWidget *object, Parking *parking) {
    strcpy(parking->ID, gtk_entry_get_text(GTK_ENTRY(entryParkingID)));
    parking->numberOfSpots = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryParkingNbSpots));
    strcpy(parking->address, gtk_entry_get_text(GTK_ENTRY(entryParkingAddress)));
    strcpy(parking->municipality, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryParkingMunic)));
    parking->price = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryParkingPrice));
}


void
on_YBClearButton_clicked               (GtkWidget       *object,
                                        gpointer         user_data)
{
    updateParkingDisplayFile(parkingFileDirectory, parkingDisplayFileDirectory);
    updateParkingTreeview(object);
}

void
on_YBFiltreRadioButtonAucun_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton)) {
        searchHasElectricCharger = -1;
    }
    
}


void
on_YBcomboboxTrieOption_changed        (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
    parkingSortOption = gtk_combo_box_get_active(combobox);
    updateParkingTreeview(GTK_WIDGET(combobox));
}


void
on_YBComboboxTrier_changed             (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
    parkingSortBy = gtk_combo_box_get_active(combobox);
    updateParkingTreeview(GTK_WIDGET(combobox));
    
}



void
on_YBTreeviewAgent_row_activated       (GtkWidget     *object,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    GtkTreeModel *model = gtk_tree_view_get_model(object);
    GtkTreeIter iter;
    char *cin;

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 
        0, &cin,
        -1);
        strcpy(agent.cin, cin);
        g_free(cin);
    }
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

