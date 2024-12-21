#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include <gtk/gtk.h>

typedef struct{
	char ID[30];
	char ID_Parking[30];
	char reservationID[8];
	char type[30];
	float tarif;
	int dispo[3];
	int horaire;
	int dureeJ;
	int dureeH;
}Service;

typedef struct {
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
} Reservation;



int scanService(FILE *serviceFile, Service *service);
int printService(FILE *serviceFile, Service service);
int addService(char* filename, Service Sv);
int modifyService(char* filename, Service modifiedService);
int supprimer( char *filename ,char *ID);
int searchService(char *filename, char*displayFile, char *type);
int affecter_service(char *fileName, Service service, Reservation reservation);
void afficher_service(GtkWidget *liste ,char* filename);


#endif
