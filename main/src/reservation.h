#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct {
    char idreservation[8];
    char cin[9];
    char parkingID[8];
    int jours, mois, annee;
    int heureh, heuremin;
    int dureeh, dureemin;
    char mat[15];
    int methpai;
    int demspec[2];
    char type[50];
} Reservation;

int printReservation(FILE *reservationFile, Reservation r);
int scanReservation(FILE *reservationFile, Reservation *r);
int ajouter_reservation(char *filename, Reservation r);
int modifyReservation(char *filename, Reservation modifiedReservation);
int supprimer_reservation(char *filename, char *idreservation);
void updateReservationDisplayFile(char *reservationFileDirectory, char *reservationDisplayFileDirectory);
int getReservationByID(char *filename, Reservation *reservation,char *id);
void filterReservationByCIN(char *filename, char *cin);
void afficher_reservations(GtkWidget *liste ,char *reservationDisplayFileDirectory, const char *cin);
void vider(GtkWidget *liste);

#endif // RESERVATION_H_INCLUDED


