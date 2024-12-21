#include "avis.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>


// Fonction pour comparer les avis par note (tri décroissant)
int comparer_avis_par_note(const void *a, const void *b) {
    avis *avis_a = (avis *)a;
    avis *avis_b = (avis *)b;
    return avis_b->note - avis_a->note;  // Tri décroissant par note
}

// Fonction pour afficher les avis triés par note décroissante dans un GtkTreeView
void afficher_avis_par_note(GtkTreeView *treeview) {
    FILE *f = fopen("avis.txt", "r");
    avis avis_liste[100];
    int i = 0;

    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        return;
    }

    // Lire les avis depuis le fichier
    while (fscanf(f, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                  avis_liste[i].nom, avis_liste[i].prenom, avis_liste[i].CIN,
                  avis_liste[i].ID_Parking, avis_liste[i].ID_avis, avis_liste[i].text,
                  &avis_liste[i].sexe, &avis_liste[i].jour, &avis_liste[i].mois,
                  &avis_liste[i].annee, &avis_liste[i].note, &avis_liste[i].type_avis,
                  &avis_liste[i].service[0], &avis_liste[i].service[1]) != EOF) {
        i++;
    }

    fclose(f);

    // Trier les avis par note décroissante
    qsort(avis_liste, i, sizeof(avis), comparer_avis_par_note);

    // Mise à jour du GtkTreeView avec les avis triés
    GtkListStore *list_store = GTK_LIST_STORE(gtk_tree_view_get_model(treeview));
    gtk_list_store_clear(list_store);

    for (int j = 0; j < i; j++) {
        GtkTreeIter iter;
        gtk_list_store_append(list_store, &iter);
        gtk_list_store_set(list_store, &iter,
                           0, avis_liste[j].nom,
                           1, avis_liste[j].prenom,
                           2, avis_liste[j].ID_avis,
                           3, avis_liste[j].note,
                           -1);
    }
}









// Fonction pour ajouter un avis
int ajouter_avis(char *filename, avis a) {
    FILE *f = fopen(filename, "a"); // Ouverture en mode ajout
    if (f != NULL) {
        fprintf(f, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                a.nom, a.prenom, a.CIN, a.ID_Parking, a.ID_avis, a.text,
                a.sexe, a.jour, a.mois, a.annee, a.note, a.type_avis,
                a.service[0], a.service[1]);
        fclose(f);

    } else {
        perror("Erreur lors de l'ouverture du fichier");
        return 0; // Échec
    }
}
// Fonction pour modifier un avis

int modifier_avis(char *filename, char *ID_avis, avis nouv) {
    int tr = 0; // Indicateur de succès
    avis a;     // Déclaration correcte de la variable a

    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new_avis.txt", "w");

    if (f != NULL && f2 != NULL) {
        // Lecture ligne par ligne du fichier
        while (fscanf(f, "%s %s %s %s %s %199[^\n] %d %d/%d/%d %d %d %d %d\n",
                      a.nom, a.prenom, a.CIN, a.ID_Parking, a.ID_avis, a.text,
                      &a.sexe, &a.jour, &a.mois, &a.annee, &a.note, &a.type_avis,
                      &a.service[0], &a.service[1]) != EOF) {
            // Si l'ID correspond, écrire les nouvelles données
            if (strcmp(a.ID_avis, ID_avis) == 0) {
                fprintf(f2, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                        nouv.nom, nouv.prenom, nouv.CIN, nouv.ID_Parking,
                        nouv.ID_avis, nouv.text, nouv.sexe, nouv.jour,
                        nouv.mois, nouv.annee, nouv.note, nouv.type_avis,
                        nouv.service[0], nouv.service[1]);
                tr = 1; // Marquer que la modification a réussi
            } else {
                // Sinon, réécrire les anciennes données
                fprintf(f2, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                        a.nom, a.prenom, a.CIN, a.ID_Parking, a.ID_avis, a.text,
                        a.sexe, a.jour, a.mois, a.annee, a.note, a.type_avis,
                        a.service[0], a.service[1]);
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);              // Supprimer l'ancien fichier
        rename("new_avis.txt", filename); // Renommer le fichier temporaire
    } else {
        perror("Erreur lors de l'ouverture des fichiers");
        if (f) fclose(f);
        if (f2) fclose(f2);
    }
    return tr;
}
int supprimer_avis(char* filename, char* ID_avis) {
    int tr = 0;
    avis a;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new_avis.txt", "w");

    if (f != NULL && f2 != NULL) {
        // Lire chaque avis du fichier
        while (fscanf(f, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                      a.nom, a.prenom, a.CIN, a.ID_Parking, a.ID_avis, a.text,
                      &a.sexe, &a.jour, &a.mois, &a.annee, &a.note, &a.type_avis,
                      &a.service[0], &a.service[1]) != EOF) {
            // Si l'ID_avis correspond, on saute cet avis (ne pas l'écrire dans f2)
            if (strcmp(a.ID_avis, ID_avis) != 0) {
                fprintf(f2, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                        a.nom, a.prenom, a.CIN, a.ID_Parking, a.ID_avis, a.text,
                        a.sexe, a.jour, a.mois, a.annee, a.note, a.type_avis,
                        a.service[0], a.service[1]);
            } else {
                tr = 1;  // Avis trouvé et supprimé
            }
        }
        fclose(f);
        fclose(f2);

        // Si l'avis a été supprimé, on remplace l'ancien fichier par le nouveau
        if (tr) {
            remove(filename);
            rename("new_avis.txt", filename);
        } else {
            remove("new_avis.txt");
        }
    }
    return tr;
}
// Fonction pour chercher un avis par ID_avis
avis chercher_avis(char *filename, char *ID_avis) {
    avis a;
    int found = 0;  // Indicateur pour vérifier si l'avis a été trouvé
    FILE *f = fopen(filename, "r");

    if (f != NULL) {
        // Lire chaque ligne du fichier
        while (!found && fscanf(f, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                                a.nom, a.prenom, a.CIN, a.ID_Parking, a.ID_avis, a.text,
                                &a.sexe, &a.jour, &a.mois, &a.annee, &a.note, &a.type_avis,
                                &a.service[0], &a.service[1]) != EOF) {
            // Si l'ID correspond, on marque comme trouvé
            if (strcmp(a.ID_avis, ID_avis) == 0) {
                found = 1;
            }
        }
        fclose(f);
    } else {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
    }

    // Si l'avis n'est pas trouvé, initialiser une structure vide
    if (!found) {
        strcpy(a.ID_avis, "");  // ID vide pour indiquer l'absence d'avis
    }

    return a;
}
void afficher_avis(GtkTreeView *treeview) {
    GtkListStore *list_store;  
    GtkTreeIter iter;  
    FILE *f;  
    avis a;  

    // Créer un nouveau GtkListStore si nécessaire
    list_store = GTK_LIST_STORE(gtk_tree_view_get_model(treeview));
    if (list_store == NULL) {
        GtkCellRenderer *renderer = gtk_cell_renderer_text_new();  
        GtkTreeViewColumn *column;

        // Créer un nouveau GtkListStore avec 4 colonnes (ID_avis, ID_Parking, Note, Texte)
        list_store = gtk_list_store_new(4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        // Ajouter les colonnes au TreeView
        GtkTreeViewColumn *column_avis = gtk_tree_view_column_new_with_attributes("ID Avis", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column_avis);

        column = gtk_tree_view_column_new_with_attributes("ID Parking", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Note", renderer, "text", 2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Texte", renderer, "text", 3, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        // Associer le modèle de données à l'arbre
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(list_store));
    }

    // Vider la liste avant de la remplir avec les nouvelles données
    gtk_list_store_clear(list_store);

    // Ouvrir le fichier et lire les avis
    f = fopen("avis.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s %s %s %s %s %d %d/%d/%d %d %d %d %d\n",
                      a.nom, a.prenom, a.CIN, a.ID_Parking, a.ID_avis, a.text,
                      &a.sexe, &a.jour, &a.mois, &a.annee, &a.note, &a.type_avis,
                      &a.service[0], &a.service[1]) != EOF) {
            // Ajouter une nouvelle ligne dans le modèle
            gtk_list_store_append(list_store, &iter);

            // Remplir les colonnes du modèle avec les données de l'avis
            gtk_list_store_set(list_store, &iter,
                               0, a.ID_avis,         // ID de l'avis
                               1, a.ID_Parking,      // ID du parking
                               2, g_strdup_printf("%d", a.note),  // Note de l'avis
                               3, a.text,            // Texte de l'avis
                               -1);  // Fin des paramètres
        }
        fclose(f);
    }
}




