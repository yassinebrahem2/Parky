#include "agent.h"
#include <string.h>



#include "agent.h"
#include <string.h>


 // Fonction pour ajouter un agent dans un fichier.

int ajouter_agent(char *filename, Agent a) {
    FILE *f = fopen(filename, "r"); // Ouvre le fichier en mode lecture
    Agent agent_fichier; // Structure temporaire pour stocker les données lues du fichier
    int cin_existe = 0;  // Variable pour vérifier si le CIN existe déjà
    int numtel_existe = 0; // Variable pour vérifier si le numéro de téléphone existe déjà

    // Vérification si le CIN ou le numéro de téléphone existe déjà dans le fichier
    if (f != NULL) {
        // Parcourt chaque ligne du fichier pour lire les données des agents
        while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s\n",
                      agent_fichier.cin, agent_fichier.nom, agent_fichier.prenom,
                      &agent_fichier.date_naissance.jour, &agent_fichier.date_naissance.mois,
                      &agent_fichier.date_naissance.annee, agent_fichier.salaire,
                      agent_fichier.adresse, &agent_fichier.sexe, &agent_fichier.services[0],
                      &agent_fichier.services[1], &agent_fichier.services[2], &agent_fichier.services[3],
                      &agent_fichier.services[4], agent_fichier.id_parking, agent_fichier.numtel) != EOF) {
            
            // Vérifie si le CIN correspond à celui de l'agent à ajouter
            if (strcmp(agent_fichier.cin, a.cin) == 0) {
                cin_existe = 1; // Le CIN existe déjà
            }
            // Vérifie si le numéro de téléphone correspond à celui de l'agent à ajouter
            if (strcmp(agent_fichier.numtel, a.numtel) == 0) {
                numtel_existe = 1; // Le numéro de téléphone existe déjà
            }
            // Si l'un des deux critères est trouvé, on arrête la lecture
            if (cin_existe || numtel_existe) {
                break;
            }
        }
        fclose(f); // Ferme le fichier après la lecture
    }

    // Si le CIN ou le numéro de téléphone existe déjà, on retourne une erreur
    if (cin_existe) {
        return -1; // Erreur : CIN déjà existant
    }
    if (numtel_existe) {
        return -2; // Erreur : numéro de téléphone déjà existant
    }

    // Si le CIN et le numéro de téléphone n'existent pas, on ajoute l'agent au fichier
    f = fopen(filename, "a"); // Ouvre le fichier en mode ajout
    if (f != NULL) {
        // Écrit les informations de l'agent dans le fichier
        fprintf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s\n",
                a.cin, a.nom, a.prenom, a.date_naissance.jour, a.date_naissance.mois,
                a.date_naissance.annee, a.salaire, a.adresse, a.sexe,
                a.services[0], a.services[1], a.services[2], a.services[3], a.services[4],
                a.id_parking, a.numtel);
        fclose(f); // Ferme le fichier après l'écriture
        return 1; // Succès de l'ajout
    } else {
        return 0; // Échec : problème d'ouverture du fichier
    }
}




// Fonction pour modifier un agent dans un fichier.
 
int modifier_agent(char *filename, char *cin, Agent nouv) {
    int tr = 0; // Variable pour suivre le statut de la modification (1 : succès, 0 : échec)
    Agent a;    // Structure temporaire pour lire les agents depuis le fichier
    FILE *f = fopen(filename, "r");   // Ouvre le fichier en mode lecture
    FILE *f2 = fopen("temp.txt", "w"); // Ouvre un fichier temporaire en mode écriture

    if (f == NULL || f2 == NULL) {
        return 0; // Erreur d'ouverture des fichiers
    }

    // Vérification si le numéro de téléphone existe déjà
    int numtel_exists = 0;
    while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s",
                  a.cin, a.nom, a.prenom, &a.date_naissance.jour, &a.date_naissance.mois,
                  &a.date_naissance.annee, a.salaire, a.adresse, &a.sexe,
                  &a.services[0], &a.services[1], &a.services[2], &a.services[3],
                  &a.services[4], a.id_parking, a.numtel) != EOF) {
        // Si un autre agent a déjà le même numéro de téléphone
        if (strcmp(a.numtel, nouv.numtel) == 0 && strcmp(a.cin, cin) != 0) {
            numtel_exists = 1;
            break;
        }
    }

    if (numtel_exists) {
        // Si le numéro de téléphone est déjà pris, nettoyer et retourner une erreur
        fclose(f);
        fclose(f2);
        remove("temp.txt"); // Supprime le fichier temporaire
        return -1; // Retourne une erreur (numéro de téléphone déjà pris)
    }

    // Revenir au début pour parcourir à nouveau le fichier et modifier l'agent
    f = fopen(filename, "r"); // Rouvrir le fichier en mode lecture
    while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s",
                  a.cin, a.nom, a.prenom, &a.date_naissance.jour, &a.date_naissance.mois,
                  &a.date_naissance.annee, a.salaire, a.adresse, &a.sexe,
                  &a.services[0], &a.services[1], &a.services[2], &a.services[3],
                  &a.services[4], a.id_parking, a.numtel) != EOF) {
        if (strcmp(a.cin, cin) == 0) {
            // Remplace les données de l'agent avec celles de l'agent modifié
            fprintf(f2, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s\n",
                    nouv.cin, nouv.nom, nouv.prenom, nouv.date_naissance.jour,
                    nouv.date_naissance.mois, nouv.date_naissance.annee,
                    nouv.salaire, nouv.adresse, nouv.sexe,
                    nouv.services[0], nouv.services[1], nouv.services[2], nouv.services[3],
                    nouv.services[4], nouv.id_parking, nouv.numtel);
            tr = 1; // Modification réussie
        } else {
            // Copie les données des autres agents sans les modifier
            fprintf(f2, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s\n",
                    a.cin, a.nom, a.prenom, a.date_naissance.jour, a.date_naissance.mois,
                    a.date_naissance.annee, a.salaire, a.adresse, a.sexe,
                    a.services[0], a.services[1], a.services[2], a.services[3],
                    a.services[4], a.id_parking, a.numtel);
        }
    }

    fclose(f); // Ferme le fichier original
    fclose(f2); // Ferme le fichier temporaire

    if (tr == 1) {
        // Si la modification a réussi, remplace l'ancien fichier par le nouveau
        remove(filename); // Supprime l'ancien fichier
        rename("temp.txt", filename); // Renomme le fichier temporaire
    } else {
        // Si aucune modification n'a eu lieu, nettoie le fichier temporaire
        remove("temp.txt");
    }

    return tr; // Retourne 1 si succès, 0 sinon
}




// Fonction pour supprimer un agent en utilisant son CIN
int supprimer_agent(char *filename, char *cin) {
    int tr = 0;  // Indicateur de succès (1 si l'agent est trouvé et supprimé)
    Agent a;  // Déclaration d'une variable de type Agent pour stocker les données lues
    FILE *f = fopen(filename, "r");  // Ouverture du fichier original en lecture
    FILE *f2 = fopen("temp.txt", "w");  // Ouverture d'un fichier temporaire en écriture
    
    // Vérification de l'ouverture des fichiers
    if (f != NULL && f2 != NULL) {
        // Lecture du fichier ligne par ligne
        while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s",
                      a.cin, a.nom, a.prenom, &a.date_naissance.jour, &a.date_naissance.mois,
                      &a.date_naissance.annee, a.salaire, a.adresse, &a.sexe,
                      &a.services[0], &a.services[1], &a.services[2], &a.services[3],
                      &a.services[4], a.id_parking, a.numtel) != EOF) {
            
            // Si le CIN de l'agent ne correspond pas à celui à supprimer, on le conserve
            if (strcmp(a.cin, cin) != 0) {
                fprintf(f2, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s\n",
                        a.cin, a.nom, a.prenom, a.date_naissance.jour, a.date_naissance.mois,
                        a.date_naissance.annee, a.salaire, a.adresse, a.sexe,
                        a.services[0], a.services[1], a.services[2], a.services[3],
                        a.services[4], a.id_parking, a.numtel);
            } else {
                tr = 1;  // L'agent a été trouvé et marqué pour suppression
            }
        }
    }

    // Fermeture des fichiers
    fclose(f);
    fclose(f2);

    // Si l'agent a été supprimé, on remplace le fichier original par le fichier temporaire
    remove(filename);  // Suppression du fichier original
    rename("temp.txt", filename);  // Renommage du fichier temporaire pour qu'il remplace l'original

    // Retourne 1 si l'agent a été trouvé et supprimé, sinon 0
    return tr;
}


// Fonction pour chercher un agent dans le fichier selon un critère donné
int chercher_agent(char *filename, const char *valeur, int critere, Agent *agents_trouves, int *compteur) {
    Agent a;  // Déclaration de la structure pour stocker les données de l'agent
    int trouve = 0;  // Indicateur de succès, 1 si l'agent est trouvé, 0 sinon
    FILE *f = fopen(filename, "r");  // Ouverture du fichier en lecture
    
    // Vérification de l'ouverture du fichier
    if (f == NULL) {
        return 0;  // Retourne 0 si le fichier ne peut pas être ouvert
    }

    // Lecture du fichier agent par agent
    while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s",
                  a.cin, a.nom, a.prenom, &a.date_naissance.jour, &a.date_naissance.mois,
                  &a.date_naissance.annee, a.salaire, a.adresse, &a.sexe,
                  &a.services[0], &a.services[1], &a.services[2], &a.services[3],
                  &a.services[4], a.id_parking, a.numtel) != EOF) {
        
        // Vérification du critère de recherche
        if ((critere == 1 && strcmp(a.cin, valeur) == 0) ||  // Recherche par CIN
            (critere == 2 && strcmp(a.nom, valeur) == 0) ||  // Recherche par nom
            (critere == 3 && strcmp(a.numtel, valeur) == 0)) {  // Recherche par numéro de téléphone
            // Si l'agent est trouvé, on l'ajoute à la liste des agents trouvés
            agents_trouves[*compteur] = a;
            (*compteur)++;  // Incrémentation du compteur d'agents trouvés
            trouve = 1;  // L'agent a été trouvé
        }
    }

    // Fermeture du fichier
    fclose(f);
    
    // Retourne 1 si un ou plusieurs agents ont été trouvés, sinon 0
    return trouve;
}

   
// Fonction pour afficher la liste des agents dans un GtkTreeView
void afficher_agents(GtkTreeView *treeview, char *agentFile) {
    GtkListStore *list_store;  // Modèle de données pour le GtkTreeView
    GtkTreeIter iter;  // Itérateur pour ajouter des éléments dans le modèle
    FILE *f;  // Pointeur vers le fichier contenant les données des agents
    Agent a;  // Structure pour stocker les informations d'un agent

    // Supprimer les anciennes colonnes si elles existent
    GtkTreeViewColumn *col;
    GList *column_list = gtk_tree_view_get_columns(treeview);
    for (GList *l = column_list; l != NULL; l = l->next) {
        col = GTK_TREE_VIEW_COLUMN(l->data);
        gtk_tree_view_remove_column(treeview, col);
    }

    // Vérifier si un modèle est déjà attaché et le supprimer si nécessaire
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    if (model) {
        g_object_unref(model);  // Libération du modèle précédent
    }

    // Créer un nouveau GtkListStore si nécessaire
    list_store = GTK_LIST_STORE(gtk_tree_view_get_model(treeview));
    if (list_store == NULL) {
        GtkCellRenderer *renderer = gtk_cell_renderer_text_new();  // CellRenderer pour afficher du texte
        GtkTreeViewColumn *column;

        // Création du modèle de données avec 10 colonnes de type chaîne de caractères
        list_store = gtk_list_store_new(10, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
                                       G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        // Ajouter les colonnes au GtkTreeView
        column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text", 2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Téléphone", renderer, "text", 3, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Date de Naissance", renderer, "text", 4, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Salaire", renderer, "text", 5, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", 6, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text", 7, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Services", renderer, "text", 8, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("ID_parking", renderer, "text", 9, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        // Attacher le modèle de données à l'arbre
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(list_store));
    }

    // Effacer les anciens éléments dans le GtkTreeView
    gtk_list_store_clear(list_store);

    // Ouvrir le fichier "agent.txt" pour lire les données des agents
    f = fopen(agentFile, "r");
    if (f != NULL) {
        // Lire chaque ligne du fichier et ajouter les agents au modèle
        while (fscanf(f, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %s %s\n",
                      a.cin, a.nom, a.prenom, &a.date_naissance.jour, &a.date_naissance.mois,
                      &a.date_naissance.annee, a.salaire, a.adresse, &a.sexe,
                      &a.services[0], &a.services[1], &a.services[2], &a.services[3], &a.services[4],
                      a.id_parking, a.numtel) != EOF) {
            char sexe_str[10];
            char services_str[100];
            char date_naissance_str[20];

            // Conversion des données pour les afficher dans un format lisible
            strcpy(sexe_str, (a.sexe == 1) ? "Homme" : "Femme");  // Conversion du sexe en texte
            sprintf(services_str, "%s%s%s%s%s",
                    a.services[0] ? "Sécurité " : "",
                    a.services[1] ? "Maintenance " : "",
                    a.services[2] ? "Parking " : "",
                    a.services[3] ? "Responsable " : "",
                    a.services[4] ? "Entretien " : "");
            sprintf(date_naissance_str, "%02d/%02d/%04d",
                    a.date_naissance.jour, a.date_naissance.mois, a.date_naissance.annee);

            // Ajouter l'agent au GtkListStore
            gtk_list_store_append(list_store, &iter);
            gtk_list_store_set(list_store, &iter,
                               0, a.cin,
                               1, a.nom,
                               2, a.prenom,
                               3, a.numtel,
                               4, date_naissance_str,
                               5, a.salaire,
                               6, a.adresse,
                               7, sexe_str,
                               8, services_str,
                               9, a.id_parking,  // Placeholder pour l'ID de parking
                               -1);
        }
        fclose(f);  // Fermer le fichier après la lecture
    }
}



