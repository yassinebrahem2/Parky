#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "parking.h"
#include "reservation.h"

GtkWidget *treeviewParkingReservation;
GtkWidget *treeviewReservation;
int met=1;
int dem_spec[2]={0,0};
int agree=0;
Parking parkingReservation;
char loggedCIN[8] = "333";

char *parkingFileDirectory = "Data/parking.txt";
char *parkingReservationDisplayFileDirectory = "Cashe/parkingReservationDisplay.txt";

char *reservationFileDirectory = "Data/reservation.txt";
char *reservationDisplayFileDirectory = "Cashe/displayReservation.txt";

void
on_Citoyen_map                         (GtkWidget       *widget,
                                        gpointer         user_data)
{
	initReservationParkingTreeview(widget);
    initReservationTreeview(widget);

    GtkWidget *entry_cin = lookup_widget(GTK_WIDGET(widget), "asentrycina");
    gtk_entry_set_text(GTK_ENTRY(entry_cin), loggedCIN);
    GtkWidget *entry_idpa = lookup_widget(GTK_WIDGET(widget), "asentryidpa");
    gtk_entry_set_text(GTK_ENTRY(entry_idpa), "-1");

    GtkWidget *entry_cinm = lookup_widget(GTK_WIDGET(widget), "asentrycinm");
    gtk_entry_set_text(GTK_ENTRY(entry_cinm), loggedCIN);
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


// Appel de la fonction ajouter_reservation pour sauvegarder les données
resultat = ajouter_reservation(reservationFileDirectory, r);
if (resultat == 1)
    {
        sprintf(message, "Ajout réussi");
        gtk_label_set_text(GTK_LABEL(label_ajout), message);
    }
else
    {
        gtk_label_set_text(GTK_LABEL(label_ajout), "Erreur : Impossible d'ajouter l'agent!");
    }
    updateReservationTreeview(GTK_WIDGET(button));
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
    GtkWidget *entry_cin, *treeview1, *label_afficher;
    char cin[8];
    Reservation reservation;
    entry_cin = lookup_widget(GTK_WIDGET(button), "asentrycinaf");

    treeview1 = lookup_widget(GTK_WIDGET(button), "astreeviewafficher");
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
            supp=supprimer_reservation(reservationFileDirectory,idreservation);
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

