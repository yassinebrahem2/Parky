#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
#include <stdio.h>

typedef struct {
  char  cin[10],nom[20],prenom[20],tel[10],email[150],adresse[150],mdp[20];
  int   dn[3], genre,options[6];} citoyen;
typedef struct {
    char cin[10],matricule[20], marque[50];
    int  type ,type_matricule;
} vehicule;


void ajouter_citoyen(char *,citoyen);
void modifier_citoyen(char *, char cin[10] ,citoyen new);
void supprimer_citoyen(char *, char cin[10]);
void chercher_citoyen(char *,char cin[10]);
void ajouter_vehicule(char *,vehicule);
void modifier_vehicule(char *,char matricule[20], vehicule new);
void supprimer_vehicule(char *,char cin[10]);
void chercher_vehicule(char *,char cin[10]);
void calcul_facture_mensuelle(char *, char *,char cin[10], int jours_resevee);

#endif