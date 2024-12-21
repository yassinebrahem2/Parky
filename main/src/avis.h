#ifndef AVIS_H_INCLUDED
#define AVIS_H_INCLUDED
#include <gtk/gtk.h>

// Structure représentant un avis
typedef struct {
    char nom[20];
    char prenom[20];
    char CIN[9];
    char ID_Parking[10];
    char ID_avis[10];
    char text[200];
    int sexe;
    int jour, mois, annee;
    int note;
    int type_avis;
    int service[2];
} avis;

// Prototypes des fonctions
int ajouter_avis(char *filename, avis a);
int modifier_avis(char *filename, char *ID_avis, avis nouv);
int supprimer_avis(char* filename, char* ID_avis);
avis chercher_avis (char*filename,char*ID_avis); 
void afficher_avis(GtkTreeView *treeview);
void afficher_avis_par_note(GtkTreeView *treeview); // Afficher les avis triés par note décroissante 
#endif


