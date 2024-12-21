#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "avis.h"


avis a;


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
    avis a;

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

    // Vérification si l'ID a été saisi
    if (strlen(id_recherche) == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Veuillez entrer un ID d'avis !");
        return;
    }

    // Chercher l'avis dans le fichier
    a = chercher_avis("avis.txt", id_recherche);

    // Si l'avis n'est pas trouvé
    if (strcmp(a.ID_avis, "") == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Aucun avis trouvé avec cet ID !");
        return;
    }

    // Si l'avis est trouvé, mettre à jour les champs
    gtk_label_set_text(GTK_LABEL(labelErreur), "Avis trouvé !");
    gtk_entry_set_text(GTK_ENTRY(entryNom), a.nom);
    gtk_entry_set_text(GTK_ENTRY(entryPrenom), a.prenom);
    gtk_entry_set_text(GTK_ENTRY(entryCin), a.CIN);
    gtk_entry_set_text(GTK_ENTRY(entryID_parking), a.ID_Parking);
    gtk_entry_set_text(GTK_ENTRY(entryID_avis), a.ID_avis);

    // Remplir le TextView avec le texte de l'avis
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textViewAvis));
    gtk_text_buffer_set_text(buffer, a.text, -1);

    // Mettre à jour les spin buttons
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonJour), a.jour);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonMois), a.mois);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonAnnee), a.annee);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButtonNote), a.note);

    // Mettre à jour le combo box en fonction du type d'avis
    gtk_combo_box_set_active(GTK_COMBO_BOX(comboBoxTypeAvis), a.type_avis == 1 ? 0 : 1);

    // Mettre à jour le TreeView avec les informations de l'avis (ID, ID de parking, note, texte)
    GtkListStore *store = gtk_list_store_new(4,  // ID d'avis, ID de parking, note, texte
                                             G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);

    GtkTreeIter iter;
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,
                       0, a.ID_avis,
                       1, a.ID_Parking,
                       2, a.note,
                       3, a.text,
                       -1);

    // Mettre le modèle du TreeView à jour
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));
    g_object_unref(store);

    // Connecter la sélection de la ligne dans le TreeView
    g_signal_connect(treeview, "row-activated", G_CALLBACK(on_treeview_avis_row_activated), user_data);
}

void on_treeview_avis_row_activated(GtkTreeView *treeview, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data)
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
    avis a;

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
    strcpy(a.nom, gtk_entry_get_text(GTK_ENTRY(entryNom)));
    strcpy(a.prenom, gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
    strcpy(a.CIN, gtk_entry_get_text(GTK_ENTRY(entryCin)));
    strcpy(a.ID_Parking, gtk_entry_get_text(GTK_ENTRY(entryID_parking)));
    strcpy(a.ID_avis, gtk_entry_get_text(GTK_ENTRY(entryID_avis)));

    a.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonJour));
    a.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonMois));
    a.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonAnnee));
    a.note = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinButtonNote));
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
    g_strlcpy(a.text, comment, sizeof(a.text));

    // Libération de la mémoire allouée
    g_free(comment);

    // Récupération du type d'avis
    if (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxEntryType)), "Reclamation") == 0) {
        a.type_avis = 1;
    } else {
        a.type_avis = 0;
    }

    // Vérification des champs obligatoires
    if (strlen(a.nom) == 0 || strlen(a.prenom) == 0 || strlen(a.CIN) == 0 ||
        strlen(a.ID_Parking) == 0 || strlen(a.ID_avis) == 0) {
        gtk_label_set_text(GTK_LABEL(labelErreur), "Veuillez remplir tous les champs obligatoires !");
        return;
    }

    // Ajout de l'avis dans le fichier
    if (ajouter_avis("avis.txt", a)) {
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
on_EA_button_annuler_clicked           (GtkButton       *button,
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
	a.service[0] = gtk_toggle_button_get_active(togglebutton);
}


void
on_EA_radiobutton_homme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) {
		a.sexe = 0;
	}
}


void
on_EA_radiobutton_femme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) {
		a.sexe = 1;
	}
}


void
on_EA_checkbutton_service_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	a.service[1] = gtk_toggle_button_get_active(togglebutton);
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

