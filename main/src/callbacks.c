#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "parking.h"
#include "reservation.h"
#include "projet.h"
#include "window.h"
#include "avis.h"
#include "agent.h"
#include "service.h"


GtkWidget *treeviewParking;
GtkWidget *treeviewParkingAgents;
GtkWidget *treeviewParkingReservation;
GtkWidget *treeviewReservation;
GtkWidget *treeviewReservationClient;
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

GtkWidget *entryNom;
GtkWidget *entryPrenom;
GtkWidget *entryCin;
GtkWidget *entryID_parking;
GtkWidget *entryID_avis;
GtkWidget *text_view_avis;
GtkWidget *spinButtonJour;
GtkWidget *spinButtonMois;
GtkWidget *spinButtonAnnee;
GtkWidget *spinButtonNote;
GtkWidget *comboboxEntryType;

GtkWidget *radiobutton_homme;
GtkWidget *radiobutton_femme;
GtkWidget *checkbutton_agent;
GtkWidget *checkbutton_service;

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
GtkWidget *treeviewReservationService;
GtkTreeStore *storeService;
GtkTreeStore *storeReservation;

Service service = {0};
Reservation reservation={0};
Service newService = {0};

int entrySearchSetting = 0;
int searchHasElectricCharger = -1;
int checkboxSearchVehicules[4] = {1, 1, 1, 1};

int parkingSortBy = 0;
int parkingSortOption = 0;

int met=1;
int dem_spec[2]={0,0};
int agree=0;
Parking parkingReservation;


GtkWidget *labelNewParkingNotification;
GtkWidget *labelParkingNotification;
GtkWidget *labelAgentNotification;

Parking parking;
Parking newParking;
GtkTreeStore *store;
Agent agent;
avis av;

GtkWidget *treeviewAdminReservation;
extern GtkWidget *mftreeviewafficheragents;
int sexe_selectionne = -1;
int sexe_modifie_selectionne = -1;

int services[5] = {0, 0, 0, 0, 0};

char typeService[7][50] = {"Agent de sécurité",
                "Voiturier",
                "Lavage",
                "Technicien de maintenance",
                "Entretien de véhicule",
                "Service client",
                "Service de navette"};





int a,aa,mm;
char num_carte[50],code[5];
char file_directory_citoyen[300]="Data/citoyen.txt",
file_directory_vehicule[300]="Data/vehicule.txt"
,matricule20[300];
citoyen c={0};
vehicule v={0};

 GtkListStore *list_store;  // Declare the list store globally
 GtkListStore *list_store2; 
gboolean search_filter_function(GtkTreeModel *model, GtkTreeIter *iter, gpointer data);

char loggedCIN[20],MDP[20];


char municipality[20][100] = {"munic1", "munic2", "munic3", "munic4", "munic5"};
char *parkingFileDirectory = "Data/parking.txt";
char *agentFileDirectory = "Data/agent.txt";
char *parkingDisplayFileDirectory = "Cashe/parkingDisplay.txt";
char *parkingAgentsDisplayFileDirectory = "Cashe/parkingAgentsDisplay.txt";
char *parkingReservationDisplayFileDirectory = "Cashe/parkingReservationDisplay.txt";
char *serviceFileDirectory = "Data/service.txt";
char *serviceDisplayFileDirectory = "Cashe/serviceDisplay.txt";
char *reservationFileDirectory = "Data/reservation.txt";
char *reservationDisplayFileDirectory = "Cashe/displayReservation.txt";
char *reservationServiceDisplayFileDirectory = "Cashe/displayReservationService.txt";




void
on_Citoyen_map                         (GtkWidget       *widget,
                                        gpointer         user_data)
{
    initReservationParkingTreeview(widget);
    initReservationTreeview(widget);
    initCitoyen(widget);

    GtkWidget *entry_cin = lookup_widget(GTK_WIDGET(widget), "asentrycina");
    gtk_entry_set_text(GTK_ENTRY(entry_cin), loggedCIN);
    GtkWidget *entry_idpa = lookup_widget(GTK_WIDGET(widget), "asentryidpa");
    gtk_entry_set_text(GTK_ENTRY(entry_idpa), "-1");

    GtkWidget *entry_cinm = lookup_widget(GTK_WIDGET(widget), "asentrycinm");
    gtk_entry_set_text(GTK_ENTRY(entry_cinm), loggedCIN);

}



void
on_asbuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
// 1. Déclaration des widgets
GtkWidget *entry_idr, *entry_cin, *entry_idpa, *entry_mat;
GtkWidget *label_ajout;
GtkWidget *spinbutton_mois, *spinbutton_annee, *spinbutton_jour ; 
GtkWidget *spinbutton_heureh, *spinbutton_heuremin, *spinbutton_dureeh, *spinbutton_dureemin ;
GtkWidget *combobox ;
// 2. Déclaration des variables
char message[200];
Reservation r = {0};
int resultat;

// 3. Association des widgets aux objets graphiques
entry_idr = lookup_widget(GTK_WIDGET(button), "asentryida");
entry_cin = lookup_widget(GTK_WIDGET(button), "asentrycina");
entry_idpa = lookup_widget(GTK_WIDGET(button), "asentryidpa");
entry_mat = lookup_widget(GTK_WIDGET(button), "asentrymata");

label_ajout = lookup_widget(GTK_WIDGET(button), "aslabelajouter");

spinbutton_jour = lookup_widget(GTK_WIDGET(button), "asspinbuttonjoursa");
spinbutton_mois = lookup_widget(GTK_WIDGET(button), "asspinbuttonmoisa");
spinbutton_annee = lookup_widget(GTK_WIDGET(button), "asspinbuttonanneea");

spinbutton_heureh = lookup_widget(GTK_WIDGET(button), "asspinbuttonh1a");
spinbutton_heuremin = lookup_widget(GTK_WIDGET(button), "asspinbuttonin1a");

spinbutton_dureeh = lookup_widget(GTK_WIDGET(button), "asspinbuttonh2a");
spinbutton_dureemin = lookup_widget(GTK_WIDGET(button), "asspinbuttonmin2a");

combobox = lookup_widget(GTK_WIDGET(button), "ascomboboxa");
// 4. Récupération des données des champs
strcpy(r.idreservation, gtk_entry_get_text(GTK_ENTRY(entry_idr)));
strcpy(r.cin, gtk_entry_get_text(GTK_ENTRY(entry_cin)));
strcpy(r.parkingID, gtk_entry_get_text(GTK_ENTRY(entry_idpa))); 
strcpy(r.mat, gtk_entry_get_text(GTK_ENTRY(entry_mat)));

r.jours = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour));
r.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois));
r.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee));

r.heureh = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_heureh));
r.heuremin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_heuremin));

r.dureeh = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_dureeh));
r.dureemin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_dureemin));

strcpy(r.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

if (strcmp(r.parkingID, "") == 0) {
    strcpy(r.parkingID, "-1");
}

r.methpai = met;
for (int i = 0; i < 2; i++)
{
        r.demspec[i] = dem_spec[i];
}


if (strcmp(r.parkingID, "-1") != 0) {
    
    // Appel de la fonction ajouter_reservation pour sauvegarder les données
    resultat = ajouter_reservation(reservationFileDirectory, r);
    updateReservationDisplayFile(reservationFileDirectory, reservationDisplayFileDirectory);
    updateReservationTreeview(GTK_WIDGET(button));
    if (resultat == 1)
        {
            sprintf(message, "Ajout réussi");
            gtk_label_set_text(GTK_LABEL(label_ajout), message);
        }
    else
        {
            gtk_label_set_text(GTK_LABEL(label_ajout), "Erreur : Impossible d'ajouter l'agent!");
        }
    
} else
    {
        gtk_label_set_text(GTK_LABEL(label_ajout), "Erreur : Impossible d'ajouter l'agent!");
    }
}
void
on_asradiobutton1a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      met=1;
}


void
on_asradiobutton2a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      met=2;
}


void
on_ascheckbutton1a_toggled             (GtkToggleButton *togglebutton,
                                       gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
    dem_spec[0] = 1;
}

}
void
on_ascheckbutton2a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
    dem_spec[1] = 1;
}
}


void
on_ascheckbutton3a_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
     agree= 1;
}
}


void
on_asbuttonmodifier1_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
 // 1. Déclaration des widgets
    GtkWidget *entry_idr, *entry_cin, *entry_idpa, *entry_mat;
    GtkWidget *spinbutton_jour, *spinbutton_mois, *spinbutton_annee;
    GtkWidget *spinbutton_heureh, *spinbutton_heuremin, *spinbutton_dureeh, *spinbutton_dureemin;
    GtkWidget *combobox, *label_valider;
    GtkWidget *radiobutton1, *radiobutton2, *checkbutton1, *checkbutton2;


    Reservation r;
    char idr[8];

    // 2. Association des widgets aux objets graphiques
    entry_idr = lookup_widget(GTK_WIDGET(button), "asentryidm"); //idr entry field for validation
    label_valider = lookup_widget(GTK_WIDGET(button), "aslabelmodifier"); // Label to show validation messages

    // 3. Récupération du idreservation
    strcpy(idr, gtk_entry_get_text(GTK_ENTRY(entry_idr)));

    // 4. Chercher la réservation par idreservation
    int value = getReservationByID(reservationFileDirectory, &r, idr); 
    // Utilisation d'une nouvelle fonction de recherche par Reservation



    if (value == 1) { // Vérifier si la réservation existe"
        gtk_label_set_text(GTK_LABEL(label_valider), "Erreur: Réservation introuvable!");
        return;
    }else{
    // 5. Association des autres widgets
    entry_cin = lookup_widget(GTK_WIDGET(button), "asentrycinm");
    entry_idpa = lookup_widget(GTK_WIDGET(button), "asentryidpm");
    entry_mat = lookup_widget(GTK_WIDGET(button), "asentrymatm");

    spinbutton_jour = lookup_widget(GTK_WIDGET(button), "asspinbuttonjoursm");
    spinbutton_mois = lookup_widget(GTK_WIDGET(button), "asspinbuttonmoism");
    spinbutton_annee = lookup_widget(GTK_WIDGET(button), "asspinbuttonanneem");

    spinbutton_heureh = lookup_widget(GTK_WIDGET(button), "asspinbuttonh1m");
    spinbutton_heuremin = lookup_widget(GTK_WIDGET(button), "asspinbuttonmin1m");

    spinbutton_dureeh = lookup_widget(GTK_WIDGET(button), "asspinbuttonh2m");
    spinbutton_dureemin = lookup_widget(GTK_WIDGET(button), "asspinbuttonmin2m");

    combobox = lookup_widget(GTK_WIDGET(button), "ascomboboxm");

    radiobutton1 = lookup_widget(GTK_WIDGET(button), "asradiobutton1m");
    radiobutton2 = lookup_widget(GTK_WIDGET(button), "asradiobutton2m");

    checkbutton1 = lookup_widget(GTK_WIDGET(button), "ascheckbutton1m");
    checkbutton2 = lookup_widget(GTK_WIDGET(button), "ascheckbutton2m");
// 6. Afficher les données récupérées dans les champs
    gtk_entry_set_text(GTK_ENTRY(entry_cin), r.cin);
    gtk_entry_set_text(GTK_ENTRY(entry_idpa), r.parkingID);
    gtk_entry_set_text(GTK_ENTRY(entry_mat), r.mat);

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_jour), r.jours);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_mois), r.mois);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_annee), r.annee);

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_heureh), r.heureh);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_heuremin), r.heuremin);

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_dureeh), r.dureeh);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_dureemin), r.dureemin);


    char matricecombo[3][10]={"Voiture","Camion", "Moto"};
    
    char typecombo[10];
    strcpy(typecombo, r.type);    
    int i = 0;

    // Set the active text based on r.type
    while (i<3 && strcmp(matricecombo[i],typecombo)!=0)
    {
          i++;  
          
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox), i);

    // 7. Mettre à jour les boutons radio
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton1), r.methpai == 1);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton2), r.methpai == 2);

    // 8. Mettre à jour les cases à cocher
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton1), r.demspec[0]);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton2), r.demspec[1]);

    // 9. Afficher un message de succès
    gtk_label_set_text(GTK_LABEL(label_valider), "Données chargées avec succès!");

}
}


void
on_asbuttonmodifier2_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    // 1. Déclaration des widgets
    GtkWidget *entry_idr,*entry_cin, *entry_idpa, *entry_mat;
    GtkWidget *spinbutton_jour, *spinbutton_mois, *spinbutton_annee;
    GtkWidget *spinbutton_heureh, *spinbutton_heuremin, *spinbutton_dureeh, *spinbutton_dureemin;
    GtkWidget *combobox, *label_modifier;
    GtkWidget *checkbutton_spec1, *checkbutton_spec2;
    GtkWidget *radiobutton_pai1, *radiobutton_pai2;

    Reservation r;
    int resultat;

    // 2. Association des widgets aux objets graphiques
    entry_cin = lookup_widget(GTK_WIDGET(button), "asentrycinm");
    entry_idr = lookup_widget(GTK_WIDGET(button), "asentryidm");
    entry_idpa = lookup_widget(GTK_WIDGET(button), "asentryidpm");
    entry_mat = lookup_widget(GTK_WIDGET(button), "asentrymatm");

    label_modifier = lookup_widget(GTK_WIDGET(button), "aslabelmodifier");

    spinbutton_jour = lookup_widget(GTK_WIDGET(button), "asspinbuttonjoursm");
    spinbutton_mois = lookup_widget(GTK_WIDGET(button), "asspinbuttonmoism");
    spinbutton_annee = lookup_widget(GTK_WIDGET(button), "asspinbuttonanneem");

    spinbutton_heureh = lookup_widget(GTK_WIDGET(button), "asspinbuttonh1m");
    spinbutton_heuremin = lookup_widget(GTK_WIDGET(button), "asspinbuttonmin1m");

    spinbutton_dureeh = lookup_widget(GTK_WIDGET(button), "asspinbuttonh2m");
    spinbutton_dureemin = lookup_widget(GTK_WIDGET(button), "asspinbuttonmin2m");
    combobox = lookup_widget(GTK_WIDGET(button), "ascomboboxm");

    // Checkbuttons and radiobuttons
    checkbutton_spec1 = lookup_widget(GTK_WIDGET(button), "ascheckbutton1m");
    checkbutton_spec2 = lookup_widget(GTK_WIDGET(button), "ascheckbutton2m");
    radiobutton_pai1 = lookup_widget(GTK_WIDGET(button), "asradiobutton1m");
    radiobutton_pai2 = lookup_widget(GTK_WIDGET(button), "asradiobutton2m");

    // 3. Récupérer le CIN pour identifier la réservation à modifier
    strcpy(r.idreservation, gtk_entry_get_text(GTK_ENTRY(entry_idr)));
    strcpy(r.parkingID, gtk_entry_get_text(GTK_ENTRY(entry_idpa)));

    // 4. Récupérer les données des champs
    strcpy(r.cin, gtk_entry_get_text(GTK_ENTRY(entry_cin)));
    strcpy(r.mat, gtk_entry_get_text(GTK_ENTRY(entry_mat)));

    r.jours = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour));
    r.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois));
    r.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee));

    r.heureh = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_heureh));
    r.heuremin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_heuremin));

    r.dureeh = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_dureeh));
    r.dureemin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_dureemin));

    strcpy(r.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

    // Récupérer les valeurs des checkbuttons
    r.demspec[0] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbutton_spec1));
    r.demspec[1] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbutton_spec2));

    // Récupérer les valeurs des radiobuttons
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_pai1))) {
        r.methpai = 1; // Par exemple, méthode 1
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_pai2))) {
        r.methpai = 2; // Par exemple, méthode 2
    }

    // 5. Validation des champs obligatoires
    if (strlen(r.cin) == 0 || strlen(r.mat) == 0) {
        gtk_label_set_text(GTK_LABEL(label_modifier), "Erreur: Tous les champs sont obligatoires!");
        return;
    }

    // 6. Appeler la fonction de modification en utilisant le CIN comme identifiant
    resultat = modifyReservation(reservationFileDirectory, r); // Utilisation d'une nouvelle fonction de modification par CIN

    if (resultat == 0) {
        gtk_label_set_text(GTK_LABEL(label_modifier), "Modification réussie!");
    } else {
        gtk_label_set_text(GTK_LABEL(label_modifier), "Erreur : Modification échouée!");
    }

    updateReservationDisplayFile(reservationFileDirectory, reservationDisplayFileDirectory);
    updateReservationTreeview(GTK_WIDGET(button));


}


void
on_asbuttonafficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *entry_cin, *label_afficher;
    char cin[8];
    Reservation reservation;
    entry_cin = lookup_widget(GTK_WIDGET(button), "asentrycinaf");

    label_afficher = lookup_widget(GTK_WIDGET(button), "aslabelsupprimer");

    strcpy(cin, gtk_entry_get_text(GTK_ENTRY(entry_cin)));
    //updateReservationDisplayFile(reservationFileDirectory, reservationDisplayFileDirectory);
    //filterReservationByCIN(reservationDisplayFileDirectory, cin);

    if (strcmp(reservation.idreservation, "-10") == 0) {
        gtk_label_set_text(GTK_LABEL(label_afficher), "Erreur: Réservation introuvable!");
    }
}





void
on_astreeviewafficher_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        int supp;

        GtkTreeIter iter;
        Reservation r;
        gchar *idreservation, *cin, *mat, *type;
        gchar *charjours;
        gchar *charmois;
        gchar *charannee;
        gchar *charheureh;
        gchar *charheuremin;
        gchar *chardureeh;
        gchar *chardureemin;
        gchar *charmeth;
        gchar *chardem1;
        gchar *chardem2;

        GtkTreeModel *model = gtk_tree_view_get_model(treeview);
        if (gtk_tree_model_get_iter(model, &iter, path))
        {
            // Obtain values from the selected row
            gtk_tree_model_get(GTK_LIST_STORE(model), &iter,
                               0, &idreservation,
                               1, &cin,
                               2, &charjours,
                               3, &charmois,
                               4, &charannee,
                               5, &charheureh,
                               6, &charheuremin,
                               7, &chardureeh,
                               8, &chardureemin,
                               9, &mat,
                               10, &charmeth,
                               11, &chardem1,
                               12, &chardem2,
                               13, &type,
                               -1);

            strcpy(r.idreservation,idreservation);
            printf("%s\n", r.idreservation);
            supp=supprimer_reservation(reservationFileDirectory,idreservation);
            updateReservationDisplayFile(reservationFileDirectory, reservationDisplayFileDirectory);
            updateReservationTreeview(GTK_WIDGET(treeview));
        }
    
}



void
on_astreeviewparking_row_activated     (GtkWidget     *object,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data) {
    GtkTreeModel *model = gtk_tree_view_get_model(object);
    GtkTreeIter iter;
    char *id, *address, *munic;
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 
        0, &id,
        1, &parkingReservation.numberOfSpots,
        2, &address,
        3, &munic,
        4, &parkingReservation.price,
        5, &parkingReservation.hasElectricCharger,
        6, &parkingReservation.vehicules[0],
        7, &parkingReservation.vehicules[1],
        8, &parkingReservation.vehicules[2],
        9, &parkingReservation.vehicules[3],
        -1);
        strcpy(parkingReservation.ID, id);
        strcpy(parkingReservation.address, address);
        strcpy(parkingReservation.municipality, munic);
        g_free(id); g_free(address); g_free(munic);
    }
    GtkWidget *entry_idpa = lookup_widget(GTK_WIDGET(object), "asentryidpa");
    gtk_entry_set_text(GTK_ENTRY(entry_idpa), parkingReservation.ID);
}

void initReservationTreeview(GtkWidget *object) {
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
    updateReservationTreeview(object);

    for (i = 0; i < 15; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewReservation), columnArray[i]);
    }
}


void updateReservationTreeview(GtkWidget *object) {
    Reservation reservation;
    int i;
    GtkTreeStore *storeReservation = gtk_tree_store_new(15,
    G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_STRING, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT,
    G_TYPE_STRING);
    treeviewReservation = lookup_widget(object, "astreeviewafficher");
    
    filterReservationByCIN(reservationDisplayFileDirectory, loggedCIN);
    FILE *reservationFile = fopen(reservationDisplayFileDirectory, "r");
    while (scanReservation(reservationFile, &reservation) != EOF) {
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
            11, reservation.methpai,
            12, reservation.demspec[0],
            13, reservation.demspec[1],
            14, reservation.type,
            -1);
    }
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewReservation), GTK_TREE_MODEL(storeReservation));
}

void initReservationParkingTreeview(GtkWidget *object) {
    int i;
    GtkCellRenderer *rendererArray[10];
    GtkTreeViewColumn *columnArray[10];
    const char header[10][20] = {
        "ID", "Nombre de places", "Adresse", 
        "Municipalite", "Prix", "Chargeur Electrique", 
        "Voiture", "Camion", "Moto", "Velo"};
    updateParkingDisplayFile(parkingFileDirectory, parkingReservationDisplayFileDirectory);
    sortParking(parkingReservationDisplayFileDirectory, spotsInRange, 1);
    updateReservationParkingTreeview(object);

    for (i = 0; i < 10; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewParkingReservation), columnArray[i]);
    }
}

void updateReservationParkingTreeview(GtkWidget *object) {
    Parking parkingReservation;
    int i;
    GtkTreeStore *store = gtk_tree_store_new(10, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
    treeviewParkingReservation = lookup_widget(object, "astreeviewparking");

    FILE *parkingFile = fopen(parkingReservationDisplayFileDirectory, "r");
    while (scanParking(parkingFile, &parkingReservation) != EOF) {
        GtkTreeIter iter;
        gtk_tree_store_append(store, &iter, NULL); // Add a new row
        gtk_tree_store_set(store, &iter, 
            0, parkingReservation.ID,
            1, parkingReservation.numberOfSpots,
            2, parkingReservation.address,
            3, parkingReservation.municipality,
            4, parkingReservation.price,
            5, parkingReservation.hasElectricCharger,
            6, parkingReservation.vehicules[0],
            7, parkingReservation.vehicules[1],
            8, parkingReservation.vehicules[2],
            9, parkingReservation.vehicules[3],
            -1);
    }
    fclose(parkingFile);
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewParkingReservation), GTK_TREE_MODEL(store));
}



void on_EA_button_modifier_clicked(GtkWidget *object, gpointer user_data) {
     // Récupérer les widgets
    GtkWidget *entry_ID_avis = lookup_widget(object, "EA_entry_idavis");
    GtkWidget *entry_ID_parking = lookup_widget(object, "EA_entry_idparking");
    GtkWidget *spinbutton_note = lookup_widget(object, "EA_spinbutton_note");
    GtkWidget *textview_text = lookup_widget(object, "EA_textviewvis");

    GtkWidget *entry_nom = lookup_widget(object, "EA_entry_nom");
    GtkWidget *entry_prenom = lookup_widget(object, "EA_entry_prenom");
    GtkWidget *entry_CIN = lookup_widget(object, "EA_entry_cin");

    GtkWidget *radiobutton_sexe_homme = lookup_widget(object, "EA_radiobutton_homme");
    GtkWidget *radiobutton_sexe_femme = lookup_widget(object, "EA_radiobutton_femme");

    GtkWidget *checkbuttons_service[2] = {
        lookup_widget(object, "EA_checkbutton_agent"),
        lookup_widget(object, "EA_checkbutton_service")
    };

    GtkWidget *spinbutton_jour = lookup_widget(object, "EA_spinbutton_jour");
    GtkWidget *spinbutton_mois = lookup_widget(object, "EA_spinbutton_mois");
    GtkWidget *spinbutton_annee = lookup_widget(object, "EA_spinbutton_annee");

    // Activer tous les widgets pour permettre la modification
    gtk_widget_set_sensitive(entry_ID_avis, TRUE);
    gtk_widget_set_sensitive(entry_ID_parking, TRUE);
    gtk_widget_set_sensitive(spinbutton_note, TRUE);
    gtk_widget_set_sensitive(textview_text, TRUE);
    gtk_widget_set_sensitive(entry_nom, TRUE);
    gtk_widget_set_sensitive(entry_prenom, TRUE);
    gtk_widget_set_sensitive(entry_CIN, TRUE);
    gtk_widget_set_sensitive(radiobutton_sexe_homme, TRUE);
    gtk_widget_set_sensitive(radiobutton_sexe_femme, TRUE);
    gtk_widget_set_sensitive(spinbutton_jour, TRUE);
    gtk_widget_set_sensitive(spinbutton_mois, TRUE);
    gtk_widget_set_sensitive(spinbutton_annee, TRUE);
    gtk_widget_set_sensitive(checkbuttons_service[0], TRUE);
    gtk_widget_set_sensitive(checkbuttons_service[1], TRUE);
}


void
on_EA_button_recherche_clicked(GtkButton       *button,
                               gpointer         user_data)
{
 // Déclaration des widgets nécessaires
    GtkWidget *entryRecherche, *treeview, *labelErreur;
    GtkWidget *entryNom, *entryPrenom, *entryCin, *entryID_parking, *entryID_avis, *textViewAvis;
    GtkWidget *spinButtonJour, *spinButtonMois, *spinButtonAnnee, *spinButtonNote, *comboBoxTypeAvis;
    char id_recherche[20];
    avis av;

    // Récupérer les widgets depuis l'interface graphique (Glade)
    entryRecherche = lookup_widget(button, "EA_entry_recherche");
    treeview = lookup_widget(gtk_widget_get_toplevel(button), "EA_treeview_avis");
    labelErreur = lookup_widget(button, "labelErreurRecherche");

    entryNom = lookup_widget(button, "EA_entry_nom");
    entryPrenom = lookup_widget(button, "EA_entry_prenom");
    entryCin = lookup_widget(button, "EA_entry_cin");
    entryID_parking = lookup_widget(button, "EA_entry_idparking");
    entryID_avis = lookup_widget(button, "EA_entry_idavis");
    textViewAvis = lookup_widget(button, "EA_textview_avis");

    spinButtonJour = lookup_widget(button, "EA_spinbutton_jour");
    spinButtonMois = lookup_widget(button, "EA_spinbutton_mois");
    spinButtonAnnee = lookup_widget(button, "EA_spinbutton_annee");
    spinButtonNote = lookup_widget(button, "EA_spinbutton_note");
    comboBoxTypeAvis = lookup_widget(button, "EA_comboboxentry_type");

    // Récupérer l'ID d'avis saisi par l'utilisateur
    strcpy(id_recherche, gtk_entry_get_text(GTK_ENTRY(entryRecherche)));

    // Vérification si l'ID av été saisi
    if (strlen(id_recherche) == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Veuillez entrer un ID d'avis !");
        return;
    }

    // Chercher l'avis dans le fichier
    av = chercher_avis("avis.txt", id_recherche);

    // Si l'avis n'est pas trouvé
    if (strcmp(av.ID_avis, "") == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Aucun avis trouvé avec cet ID !");
        return;
    }

    // Si l'avis est trouvé, mettre à jour les champs
    gtk_label_set_text(GTK_LABEL(labelErreur), "Avis trouvé !");
    gtk_entry_set_text(GTK_ENTRY(entryNom), av.nom);
    gtk_entry_set_text(GTK_ENTRY(entryPrenom), av.prenom);
    gtk_entry_set_text(GTK_ENTRY(entryCin), av.CIN);
    gtk_entry_set_text(GTK_ENTRY(entryID_parking), av.ID_Parking);
    gtk_entry_set_text(GTK_ENTRY(entryID_avis), av.ID_avis);

    // Remplir le TextView avec le texte de l'avis
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textViewAvis));
    gtk_text_buffer_set_text(buffer, av.text, -1);

    // Mettre à jour les spin buttons
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonJour), av.jour);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonMois), av.mois);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonAnnee), av.annee);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonNote), av.note);

    // Mettre à jour le combo box en fonction du type d'avis
    gtk_combo_box_set_active(GTK_COMBO_BOX(comboBoxTypeAvis), av.type_avis == 1 ? 0 : 1);

    // Mettre à jour le TreeView avec les informations de l'avis (ID, ID de parking, note, texte)
    GtkListStore *store = gtk_list_store_new(4,  // ID d'avis, ID de parking, note, texte
                                             G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);

    GtkTreeIter iter;
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,
                       0, av.ID_avis,
                       1, av.ID_Parking,
                       2, av.note,
                       3, av.text,
                       -1);

    // Mettre le modèle du TreeView à jour
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));
    g_object_unref(store);

    // Connecter la sélection de la ligne dans le TreeView
    g_signal_connect(treeview, "row-activated", G_CALLBACK(on_treeview_avis_row_activated), user_data);
}

void on_treeview_avis_row_activated(GtkWidget *object, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data)
{
    GtkTreeIter iter;
    GtkTreeModel *model;

    // Widgets pour afficher les données
    GtkWidget *entry_ID_avis = lookup_widget(object, "EA_entry_idavis");
    GtkWidget *entry_ID_parking = lookup_widget(object, "EA_entry_idparking");
    GtkWidget *spinbutton_note = lookup_widget(object, "EA_spinbutton_note");
    GtkWidget *textview_text = lookup_widget(object, "EA_textviewvis");

    GtkWidget *entry_nom = lookup_widget(object, "EA_entry_nom");
    GtkWidget *entry_prenom = lookup_widget(object, "EA_entry_prenom");
    GtkWidget *entry_CIN = lookup_widget(object, "EA_entry_cin");

    GtkWidget *radiobutton_sexe_homme = lookup_widget(object, "EA_radiobutton_homme");
    GtkWidget *radiobutton_sexe_femme = lookup_widget(object, "EA_radiobutton_femme");

    GtkWidget *checkbuttons_service[2] = {
        lookup_widget(object, "EA_checkbutton_agent"),
        lookup_widget(object, "EA_checkbutton_service")
    };

    GtkWidget *spinbutton_jour = lookup_widget(object, "EA_spinbutton_jour");
    GtkWidget *spinbutton_mois = lookup_widget(object, "EA_spinbutton_mois");
    GtkWidget *spinbutton_annee = lookup_widget(object, "EA_spinbutton_annee");

    // Obtenir la ligne sélectionnée
    model = gtk_tree_view_get_model(GTK_TREE_VIEW(object));
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        gchar *ID_avis, *ID_Parking, *note, *text;

        // Désactiver tous les widgets immédiatement
        gtk_widget_set_sensitive(entry_ID_avis, FALSE);
        gtk_widget_set_sensitive(entry_ID_parking, FALSE);
        gtk_widget_set_sensitive(spinbutton_note, FALSE);
        gtk_widget_set_sensitive(textview_text, FALSE);
        gtk_widget_set_sensitive(entry_nom, FALSE);
        gtk_widget_set_sensitive(entry_prenom, FALSE);
        gtk_widget_set_sensitive(entry_CIN, FALSE);
        gtk_widget_set_sensitive(radiobutton_sexe_homme, FALSE);
        gtk_widget_set_sensitive(radiobutton_sexe_femme, FALSE);
        gtk_widget_set_sensitive(spinbutton_jour, FALSE);
        gtk_widget_set_sensitive(spinbutton_mois, FALSE);
        gtk_widget_set_sensitive(spinbutton_annee, FALSE);
        gtk_widget_set_sensitive(checkbuttons_service[0], FALSE);
        gtk_widget_set_sensitive(checkbuttons_service[1], FALSE);

        // Récupérer les données de la ligne sélectionnée
        gtk_tree_model_get(model, &iter,
                           0, &ID_avis,
                           1, &ID_Parking,
                           2, &note,
                           3, &text,
                           -1);

        // Charger les données complètes depuis avis.txt
        FILE *file = fopen("avis.txt", "r");
        if (file != NULL)
        {
            avis avis_data;
            gboolean found = FALSE;

            while (fscanf(file, "%s %s %s %s %s %d %d %02d/%02d/%04d %d %d %d %[^\n]",
                avis_data.nom, avis_data.prenom, avis_data.CIN,
                avis_data.ID_Parking, avis_data.ID_avis, &avis_data.note, &avis_data.sexe,
                &avis_data.jour, &avis_data.mois, &avis_data.annee,
                &avis_data.service[0], &avis_data.service[1], &avis_data.type_avis, avis_data.text) != EOF)
            {
                if (strcmp(avis_data.ID_avis, ID_avis) == 0)
                {
                    found = TRUE;

                    // Remplir les champs avec les données lues depuis le fichier
                    gtk_entry_set_text(GTK_ENTRY(entry_ID_avis), avis_data.ID_avis);
                    gtk_entry_set_text(GTK_ENTRY(entry_ID_parking), avis_data.ID_Parking);
                    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_note), avis_data.note);

                    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview_text));
                    gtk_text_buffer_set_text(buffer, avis_data.text, -1);

                    gtk_entry_set_text(GTK_ENTRY(entry_nom), avis_data.nom);
                    gtk_entry_set_text(GTK_ENTRY(entry_prenom), avis_data.prenom);
                    gtk_entry_set_text(GTK_ENTRY(entry_CIN), avis_data.CIN);

                    if (avis_data.sexe == 1)
                    {
                        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_sexe_homme), TRUE);
                    }
                    else
                    {
                        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_sexe_femme), TRUE);
                    }

                    // Remplir les champs de date
                    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_jour), avis_data.jour);
                    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_mois), avis_data.mois);
                    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_annee), avis_data.annee);

                    // Remplir les checkbuttons pour les services
                    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons_service[0]), avis_data.service[0]);
                    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons_service[1]), avis_data.service[1]);

                    // Réactiver les widgets
                    gtk_widget_set_sensitive(entry_ID_avis, FALSE);
                    gtk_widget_set_sensitive(entry_ID_parking, FALSE);
                    gtk_widget_set_sensitive(spinbutton_note, FALSE);
                    gtk_widget_set_sensitive(textview_text, FALSE);
                    gtk_widget_set_sensitive(entry_nom, FALSE);
                    gtk_widget_set_sensitive(entry_prenom, FALSE);
                    gtk_widget_set_sensitive(entry_CIN, FALSE);
                    gtk_widget_set_sensitive(radiobutton_sexe_homme, FALSE);
                    gtk_widget_set_sensitive(radiobutton_sexe_femme, FALSE);
                    gtk_widget_set_sensitive(spinbutton_jour, FALSE);
                    gtk_widget_set_sensitive(spinbutton_mois, FALSE);
                    gtk_widget_set_sensitive(spinbutton_annee, FALSE);
                    gtk_widget_set_sensitive(checkbuttons_service[0], FALSE);
                    gtk_widget_set_sensitive(checkbuttons_service[1], FALSE);

                    break;
                }
            }

            fclose(file);

            if (!found)
            {
                g_print("Avis avec ID %s non trouvé dans le fichier.\n", ID_avis);
                // Réinitialiser les champs en cas d'ID non trouvé
                gtk_entry_set_text(GTK_ENTRY(entry_ID_avis), "");
                gtk_entry_set_text(GTK_ENTRY(entry_ID_parking), "");
                gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_note), 0);
                gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview_text)), "", -1);
                gtk_entry_set_text(GTK_ENTRY(entry_nom), "");
                gtk_entry_set_text(GTK_ENTRY(entry_prenom), "");
                gtk_entry_set_text(GTK_ENTRY(entry_CIN),"");
                gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_sexe_homme), FALSE);
                gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_sexe_femme), FALSE);
                gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_jour), 0);
                gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_mois), 0);
                gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_annee), 0);
                gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons_service[0]), FALSE);
                gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons_service[1]), FALSE);
            }
        }
        else
        {
            g_print("Erreur lors de l'ouverture du fichier avis.txt\n");
        }

        // Libérer la mémoire des chaînes récupérées
        g_free(ID_avis);
        g_free(ID_Parking);
        g_free(note);
        g_free(text);
    }

}

   
   
    




void on_EA_button_supprimer_clicked(GtkWidget *object, gpointer user_data) {
    GtkWidget *treeview_avis = lookup_widget(object, "EA_treeview_avis");

    // Obtenir la sélection
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_avis));
    GtkTreeModel *model;
    GtkTreeIter iter;

    // Vérifier si une ligne est sélectionnée
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        gchar *id_avis;

        // Lire l'ID de l'avis de la ligne sélectionnée
        gtk_tree_model_get(model, &iter, 0, &id_avis, -1);

        // Appeler la fonction pour supprimer l'avis
        if (supprimer_avis("avis.txt", id_avis)) {
            // Supprimer la ligne du TreeView
            gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
        }

        // Libérer la mémoire
        g_free(id_avis);
    }
}




void
on_EA_button_actualiser_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *treeview;
    treeview = lookup_widget(button, "EA_treeview_avis");  // Récupérer le GtkTreeView
    afficher_avis_par_note(GTK_TREE_VIEW(treeview));  // Appeler la fonction pour trier et afficher les avis
}


void on_EA_button_ajouter_clicked(GtkWidget *object, gpointer user_data) {
    GtkWidget *entryNom, *entryPrenom, *entryCin, *entryID_parking, *entryID_avis;
    GtkWidget *spinButtonJour, *spinButtonMois, *spinButtonAnnee, *spinButtonNote;
    GtkWidget *comboboxEntryType, *text_view_avis, *treeview, *labelErreur;
    avis av;

    // Récupération des widgets
    entryNom = lookup_widget(object, "EA_entry_nom");
    entryPrenom = lookup_widget(object, "EA_entry_prenom");
    entryCin = lookup_widget(object, "EA_entry_cin");
    entryID_parking = lookup_widget(object, "EA_entry_idparking");
    entryID_avis = lookup_widget(object, "EA_entry_idavis");
    text_view_avis = lookup_widget(object, "EA_textview_avis");
    spinButtonJour = lookup_widget(object, "EA_spinbutton_jour");
    spinButtonMois = lookup_widget(object, "EA_spinbutton_mois");
    spinButtonAnnee = lookup_widget(object, "EA_spinbutton_annee");
    spinButtonNote = lookup_widget(object, "EA_spinbutton_note");
    comboboxEntryType = lookup_widget(object, "EA_comboboxentry_type");
    labelErreur = lookup_widget(object, "EAlabelerreur");

   

    // Récupération des autres champs
    strcpy(av.nom, gtk_entry_get_text(GTK_ENTRY(entryNom)));
    strcpy(av.prenom, gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
    strcpy(av.CIN, gtk_entry_get_text(GTK_ENTRY(entryCin)));
    strcpy(av.ID_Parking, gtk_entry_get_text(GTK_ENTRY(entryID_parking)));
    strcpy(av.ID_avis, gtk_entry_get_text(GTK_ENTRY(entryID_avis)));

    av.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonJour));
    av.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonMois));
    av.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonAnnee));
    av.note = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonNote));
  // Vérification de l'initialisation de text_view_avis
    if (text_view_avis == NULL) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Erreur : Le widget text_view_avis est NULL !");
        return;
    }

    // Vérification de l'initialisation du buffer
    GtkTextView *text_view = GTK_TEXT_VIEW(text_view_avis);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
    if (buffer == NULL) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Erreur : Le buffer du TextView est NULL !");
        return;
    }

    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);

    // Vérification du texte contenu dans le buffer
    gchar *comment = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (comment == NULL || strlen(comment) == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Erreur : Le texte dans le TextView est vide !");
        return;
    }

    // Debug : Affichage du texte récupéré pour vérifier
    g_print("Texte récupéré : '%s'\n", comment);

    // Si le texte est vide après cette étape, cela signifie que le widget TextView est toujours vide
    /*if (strlen(comment) == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Erreur : Le texte dans le TextView est vide !");
        g_free(comment);
        return;
    }*/

    // Traitement du texte pour enlever les retours à la ligne et autres caractères inutiles
    for (int i = 0; comment[i] != '\0'; i++) {
        if (comment[i] == '\r' || comment[i] == '\n' || comment[i] == 0x7f) {
            comment[i] = ' '; // Remplacer par un espace
        }
    }

    // Copie sécurisée du texte dans la structure
    g_strlcpy(av.text, comment, sizeof(av.text));

    // Libération de la mémoire allouée
    g_free(comment);

    // Récupération du type d'avis
    if (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxEntryType)), "Reclamation") == 0) {
        av.type_avis = 1;
    } else {
        av.type_avis = 0;
    }

    // Vérification des champs obligatoires
    if (strlen(av.nom) == 0 || strlen(av.prenom) == 0 || strlen(av.CIN) == 0 ||
        strlen(av.ID_Parking) == 0 || strlen(av.ID_avis) == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Veuillez remplir tous les champs obligatoires !");
        return;
    }

    // Ajout de l'avis dans le fichier
    if (ajouter_avis("avis.txt", av)) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Avis ajouté avec succès !");
    } else {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Erreur lors de l'ajout de l'avis !");
    }

    // Mise à jour du TreeView
    treeview = lookup_widget(gtk_widget_get_toplevel(object), "EA_treeview_avis");
    afficher_avis(GTK_TREE_VIEW(treeview));
}
void on_EA_treeview_avis_row_activated(GtkWidget *object,
                                       GtkTreePath *path,
                                       GtkTreeViewColumn *column,
                                       gpointer user_data)
{
    GtkTreeIter iter;
    GtkTreeModel *model;

    // Widgets for the form to display data
    GtkWidget *entry_ID_avis = lookup_widget(object, "EA_entry_idavis");
    GtkWidget *entry_ID_parking = lookup_widget(object, "EA_entry_idparking");
    GtkWidget *entry_note = lookup_widget(object, "EA_entry_note_modifier");
    GtkWidget *entry_text = lookup_widget(object, "EA_textview_avis");

    GtkWidget *entry_nom = lookup_widget(object, "EA_entry_nom");
    GtkWidget *entry_prenom = lookup_widget(object, "EA_entry_prenom");
    GtkWidget *entry_CIN = lookup_widget(object, "EA_entry_cin");

    GtkWidget *radiobutton_sexe_homme = lookup_widget(object, "EA_radiobutton_homme");
    GtkWidget *radiobutton_sexe_femme = lookup_widget(object, "EA_radiobutton_femme");

    GtkWidget *checkbuttons_service[2] = {
        lookup_widget(object, "EA_checkbutton_agent"),
        lookup_widget(object, "EA_checkbutton_service")
    };

    GtkWidget *spinbutton_jour = lookup_widget(object, "EA_spinbutton_jour");
    GtkWidget *spinbutton_mois = lookup_widget(object, "EA_spinbutton_mois");
    GtkWidget *spinbutton_annee = lookup_widget(object, "EA_spinbutton_annee");

    // Get the selected row
    model = gtk_tree_view_get_model(GTK_TREE_VIEW(object));
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        gchar *ID_avis, *ID_Parking, *note, *text;
        gchar *nom, *prenom, *CIN;
        gint sexe, jour, mois, annee;
        gint service[2];
        
        // Retrieve data from the selected row
        gtk_tree_model_get(model, &iter,
                           0, &ID_avis,
                           1, &ID_Parking,
                           2, &note,
                           3, &text,
                           -1);

        // Fill in the fields with the retrieved values
        gtk_entry_set_text(GTK_ENTRY(entry_ID_avis), ID_avis);
        gtk_entry_set_text(GTK_ENTRY(entry_ID_parking), ID_Parking);
        gtk_entry_set_text(GTK_ENTRY(entry_note), note);
        gtk_entry_set_text(GTK_ENTRY(entry_text), text);
        gtk_entry_set_text(GTK_ENTRY(entry_nom), nom);
        gtk_entry_set_text(GTK_ENTRY(entry_prenom), prenom);
        gtk_entry_set_text(GTK_ENTRY(entry_CIN), CIN);

        // Set all radio buttons for sexe to inactive (FALSE)
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_sexe_homme), FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_sexe_femme), FALSE);

        // Set the date to default values or specific values (if needed)
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_jour), 1);  // Default: 1
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_mois), 1);  // Default: January
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_annee), 2024); // Default: current year

        // Set all checkboxes for services to inactive (FALSE)
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons_service[0]), FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons_service[1]), FALSE);

        // Free the memory for the retrieved strings
        g_free(ID_avis);
        g_free(ID_Parking);
        g_free(note);
        g_free(text);
        g_free(nom);
        g_free(prenom);
        g_free(CIN);
    }
}



void
on_EA_button_annuler_clicked           (GtkWidget       *object,
                                        gpointer         user_data)
{
	 // Liste des widgets d'entrée de texte
    GtkWidget *entry_nom = lookup_widget(object, "EA_entry_nom");
    GtkWidget *entry_prenom = lookup_widget(object, "EA_entry_prenom");
    GtkWidget *entry_cin = lookup_widget(object, "EA_entry_cin");
    GtkWidget *entry_id_avis = lookup_widget(object, "EA_entry_idavis");
    GtkWidget *entry_text = lookup_widget(object, "EA_textviewvis");

    // Widgets pour les boutons radio ou autres sélections
    GtkWidget *radiobutton_homme = lookup_widget(object, "EA_radiobutton_homme");
    GtkWidget *radiobutton_femme = lookup_widget(object, "EA_radiobutton_femme");
    GtkWidget *spinbutton_jour = lookup_widget(object, "EA_spinbutton_jour");
    GtkWidget *spinbutton_mois = lookup_widget(object, "EA_spinbutton_mois");
    GtkWidget *spinbutton_annee = lookup_widget(object, "EA_spinbutton_annee");

    GtkWidget *combobox_type_avis = lookup_widget(object, "EA_comboboxentry_type");

    // Vider les champs d'entrée
    gtk_entry_set_text(GTK_ENTRY(entry_nom), "");
    gtk_entry_set_text(GTK_ENTRY(entry_prenom), "");
    gtk_entry_set_text(GTK_ENTRY(entry_cin), "");
    gtk_entry_set_text(GTK_ENTRY(entry_id_avis), "");
    gtk_entry_set_text(GTK_ENTRY(entry_text), "");

    // Réinitialiser les boutons radio
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_homme), TRUE); // Par défaut Homme
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_femme), FALSE);

    // Réinitialiser les spin buttons
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_jour), 1);  // Par défaut jour = 1
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_mois), 1); // Par défaut mois = 1
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_annee), 2024); // Par défaut année = 2024

    // Réinitialiser la combobox
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_type_avis), 0); // Premier élément par défaut
}


void
on_EA_checkbutton_agent_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	av.service[0] = gtk_toggle_button_get_active(togglebutton);
}


void
on_EA_radiobutton_homme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) {
		av.sexe = 0;
	}
}


void
on_EA_radiobutton_femme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) {
		av.sexe = 1;
	}
}


void
on_EA_checkbutton_service_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	av.service[1] = gtk_toggle_button_get_active(togglebutton);
}


void
on_Administrateur_map                  (GtkWidget       *widget,
                                        gpointer         user_data)
{
    initFiles();
    initParkingTreeview(widget);
    initParkingAgentsTreeview(widget);
    fillComboboxAvailableAgents(widget);
    initServiceTreeview(widget);
    initReservationServiceTreeview(widget);

    // Récupérer le GtkTreeView à partir de l'interface
    GtkTreeView *treeview = GTK_TREE_VIEW(lookup_widget(gtk_widget_get_toplevel(widget), "mftreeviewafficheragents"));
    
    // Réinitialiser l'affichage du GtkTreeView
    gtk_tree_view_set_model(treeview, NULL);  // Enlever le modèle précédent

    // Appeler la fonction pour afficher les agents dans le GtkTreeView
    afficher_agents(treeview, agentFileDirectory);

    initAdminReservationTreeview(widget);
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


void afficher_dialog(GtkWidget *parent, const gchar *message) {
    GtkWidget *dialog;
    
    // Créer la boîte de dialogue
    dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(parent)),
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "%s",
                                    message);

    // Afficher la boîte de dialogue et attendre la réponse
    gtk_dialog_run(GTK_DIALOG(dialog));
    
    // Détruire la boîte de dialogue
    gtk_widget_destroy(dialog);
}

void
on_mfbuttonlisteagent_clicked          (GtkWidget       *object,
                                        gpointer         user_data)
{
	// Récupérer le GtkTreeView à partir de l'interface
    GtkTreeView *treeview = GTK_TREE_VIEW(lookup_widget(gtk_widget_get_toplevel(object), "mftreeviewafficheragents"));
    
    // Réinitialiser l'affichage du GtkTreeView
    gtk_tree_view_set_model(treeview, NULL);  // Enlever le modèle précédent

    // Appeler la fonction pour afficher les agents dans le GtkTreeView
    afficher_agents(treeview, agentFileDirectory);
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

void afficher_message_dialog(GtkWidget *parent, const gchar *message, GtkMessageType type) {
    GtkWidget *dialog;

    // Créer la boîte de dialogue
    dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(parent)),
                                    GTK_DIALOG_MODAL,
                                    type,
                                    GTK_BUTTONS_OK,
                                    "%s",
                                    message);

    // Afficher la boîte de dialogue et attendre la réponse
    gtk_dialog_run(GTK_DIALOG(dialog));
    
    // Détruire la boîte de dialogue
    gtk_widget_destroy(dialog);
}

void on_mfbuttonajouter_clicked(GtkWidget *object, gpointer user_data) {
    GtkWidget *entry_cin, *entry_nom, *entry_prenom, *entry_num, *entry_salaire, *entry_adresse;
    GtkWidget *radiobutton_homme, *radiobutton_femme;
    GtkWidget *checkbuttons[5];
    GtkWidget *spinbutton_jour, *spinbutton_mois, *spinbutton_annee;
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
        afficher_message_dialog(object, "Erreur : Veuillez sélectionner un sexe.", GTK_MESSAGE_ERROR);
        return;
    }

    // Récupération des services
    for (int i = 0; i < 5; i++) {
        a.services[i] = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbuttons[i])) ? 1 : 0;
    }

    // Validation des champs obligatoires
    if (strlen(a.cin) == 0 || strlen(a.nom) == 0 || strlen(a.prenom) == 0 ||
        strlen(a.numtel) == 0 || strlen(a.salaire) == 0 || strlen(a.adresse) == 0) {
        afficher_message_dialog(object, "Erreur : Tous les champs sont obligatoires.", GTK_MESSAGE_ERROR);
        return;
    }

    // 5. Appel de la fonction ajouter_agent pour sauvegarder les données
    resultat = ajouter_agent(agentFileDirectory, a);

    // Gérer le résultat
    if (resultat == 1) {
        sprintf(message, "Ajout réussi : %s %s %s", a.prenom, a.nom, a.cin);
        afficher_message_dialog(object, message, GTK_MESSAGE_INFO);

        // Mise à jour du TreeView
        treeview = lookup_widget(gtk_widget_get_toplevel(object), "mftreeviewafficheragents");
        afficher_agents(treeview, agentFileDirectory);

        // Réinitialiser les champs
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

        for (int i = 0; i < 5; i++) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttons[i]), FALSE);
        }
    } else if (resultat == -1) {
        afficher_message_dialog(object, "Erreur : Le CIN existe déjà.", GTK_MESSAGE_ERROR);
    } else if (resultat == -2) {
        afficher_message_dialog(object, "Erreur : Le numéro de téléphone existe déjà.", GTK_MESSAGE_ERROR);
    } else {
        afficher_message_dialog(object, "Erreur : Échec de l'ajout de l'agent.", GTK_MESSAGE_ERROR);
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
            afficher_dialog(object, "Agent supprimé avec succès.");
        } else {
            afficher_dialog(object, "Erreur lors de la suppression.");
        }

        // Libérer la mémoire
        g_free(cin);
    } else {
        afficher_dialog(object, "Veuillez sélectionner une ligne.");
    }
}

void on_mfbuttonchercherajout_clicked(GtkWidget *object, gpointer user_data) {
    // Déclaration des variables nécessaires
    GtkWidget *combobox_criteres, *entry_valeur, *label_error, *treeview_agents;
    const char *valeur;
    int critere = 0;
    char critere_texte[20];

    // Récupération des widgets
    combobox_criteres = lookup_widget(object, "mfcomboboxrecherche");
    entry_valeur = lookup_widget(object, "mfentryajoutchercher");
    label_error = lookup_widget(object, "mflabelmessagerecherche");
    treeview_agents = lookup_widget(object, "mftreeviewafficheragents");

    // Récupérer l'index du critère sélectionné dans le combobox
    critere = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_criteres));

    // Vérification si un critère a été sélectionné
    if (critere == -1) {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : aucun critère sélectionné.");
        return;
    }

    // Récupérer la valeur entrée par l'utilisateur dans le champ de texte
    valeur = gtk_entry_get_text(GTK_ENTRY(entry_valeur));

    // Vérification si le champ de texte est vide
    if (valeur == NULL || strlen(valeur) == 0) {
        gtk_label_set_text(GTK_LABEL(label_error), "Erreur : veuillez entrer une valeur à rechercher.");
        return;
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
    Agent agent_trouves[100];
    int compteur = 0;

    // Appel à la fonction de recherche avec le critère et la valeur
    if (chercher_agent(agentFileDirectory, valeur, critere + 1, agent_trouves, &compteur)) {
        gtk_label_set_text(GTK_LABEL(label_error), "Agents trouvés et affichés.");

        // Création du GtkTreeStore et ajout des agents trouvés
        GtkTreeStore *store = gtk_tree_store_new(10, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        GtkTreeIter iter;
        int i;
        gchar date_naissance_str[20];
        
        // Créer la chaîne de date
        for (i = 0; i < compteur; i++) {
            // Formater la date
            sprintf(date_naissance_str, "%02d/%02d/%d", agent_trouves[i].date_naissance.jour, agent_trouves[i].date_naissance.mois, agent_trouves[i].date_naissance.annee);

            gchar services_str[256] = "";
            for (int j = 0; j < 5; j++) {
                if (agent_trouves[i].services[j]) {
                    if (strlen(services_str) > 0) strcat(services_str, ", ");
                    strcat(services_str, (j == 0) ? "Agent sécurité" :
                                        (j == 1) ? "Technicien" :
                                        (j == 2) ? "Agent parking" :
                                        (j == 3) ? "Responsable parking" :
                                                   "Agent entretien");
                }
            }

            // Ajouter les agents trouvés dans le GtkTreeStore
            gtk_tree_store_append(store, &iter, NULL); // Ajouter une ligne
            gtk_tree_store_set(store, &iter,
                               0, agent_trouves[i].cin,
                               1, agent_trouves[i].nom,
                               2, agent_trouves[i].prenom,
                               3, agent_trouves[i].numtel,
                               4, date_naissance_str,
                               5, agent_trouves[i].salaire,
                               6, agent_trouves[i].adresse,
                               7, (agent_trouves[i].sexe == 1 ? "Homme" : "Femme"),
                               8, services_str,
                               9, "-1", // Remplacer par la donnée appropriée si nécessaire
                               -1);
        }

        // Assigner le modèle à la vue
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_agents), GTK_TREE_MODEL(store));
    } else {
        gtk_label_set_text(GTK_LABEL(label_error), "Aucun agent trouvé.");
    }
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

void initReservationServiceTreeview(GtkWidget *object) {
    int i;
    GtkCellRenderer *rendererArray[14];
    GtkTreeViewColumn *columnArray[14];
    const char header[13][30] = {
        "ID Reservation", "CIN", "ID Parking", "Jours", "Mois", "Annee",
        "HeureH", "HeureMin", "DureeH", "DureeMin", 
		"mat", "methpai", "demspec", "type"
        };
    updateReservationDisplayFile(reservationFileDirectory, reservationServiceDisplayFileDirectory);

    updateReservationServiceTreeview(object);
    for (i = 0; i < 14; i++) {
        rendererArray[i] = gtk_cell_renderer_text_new();
        columnArray[i] = gtk_tree_view_column_new();
        gtk_tree_view_column_pack_start(columnArray[i], rendererArray[i], TRUE);
        gtk_tree_view_column_set_attributes(columnArray[i], rendererArray[i], "text", i, NULL);
        gtk_tree_view_column_set_title(columnArray[i], header[i]);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewReservationService), columnArray[i]);
    }
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

void updateReservationServiceTreeview(GtkWidget *object) {
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

    treeviewReservationService = lookup_widget(object, "AKTreeviewReservation");
    FILE *reservationDisplayFile = fopen(reservationServiceDisplayFileDirectory, "r");
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
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewReservationService), GTK_TREE_MODEL(storeReservation));
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
    initReservationServiceTreeview(object);
}


void
on_AKButtonAnnuler_clicked             (GtkWidget       *object,
                                        gpointer         user_data)
{
    updateServiceDisplayFile();
    updateServiceTreeview(object);
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
on_ab_button_login_connexion_clicked   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *cin , *mdp,*label;
int x=0;
char cin1[50], mdp1[50];
cin = lookup_widget(objet_graphique,"ab_entry_login_cin");
mdp = lookup_widget(objet_graphique,"ab_entry_login_MDP");
label = lookup_widget(objet_graphique,"label4");
strcpy(loggedCIN,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(MDP,gtk_entry_get_text(GTK_ENTRY(mdp)));
FILE *f=fopen(file_directory_citoyen,"r");

  if (!f )
    {
        gtk_label_set_text(GTK_LABEL(label), "Erreur: Impossible d'ouvrir le fichier!");
        return;
    }
 
 while(fscanf(f,"%19s %*s %*s %*s %*s %*s %19s %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d",cin1,mdp1)!=EOF){

    if (strcmp(loggedCIN,cin1)==0 && strcmp(MDP,mdp1)==0)
    {   
        if(strcmp(loggedCIN,"admin")==0 && strcmp(MDP,"admin")==0){
        windows_show_window(Administrateur);}

        else{windows_show_window(Citoyen);}
        x=1;
        break;
    }  
    else if (strcmp(loggedCIN,cin1)==0 && strcmp(MDP,mdp1)!=0)
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
on_ab_button_login_s_inscrire_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
windows_show_window(enregistrer);
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

void initCitoyen(GtkWidget *widget) {
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
        

        if (strcmp(loggedCIN,cin1)==0 && strcmp(MDP,mdp1)==0)
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
    if (strcmp(loggedCIN,cin1)==0)
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
    
    filterReservationByCIN(reservationDisplayFileDirectory, loggedCIN);
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






