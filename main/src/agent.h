



#ifndef AGENT_H
#define AGENT_H

#include <gtk/gtk.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;


typedef struct {
    char cin[20];
    char nom[50];
    char prenom[50];
    Date date_naissance;
    char salaire[20];
    char adresse[100];
    int sexe; // 0 for Female, 1 for Male
    int services[5]; // 5 services with 0 or 1
    char id_parking[20];
    char numtel[20];
} Agent;


typedef struct {
    char idreservation[8];
    char cin[8];
    Date date;
    int heureh, heuremin;
    int dureeh, dureemin;
    char mat[15];
    int methpai;
    int demspec[2];
} reservation;



int ajouter_agent(char *filename, Agent a);
int modifier_agent(char *filename, char *cin, Agent nouv);
int supprimer_agent(char *filename, char *cin);
int chercher_agent(char *filename, const char *valeur, int critere, Agent *agents_trouves, int *compteur);
void afficher_agents(GtkTreeView *treeview);

#endif // AGENT_H

