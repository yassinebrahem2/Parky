#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"
#include <gtk/gtk.h>
enum
{
    IDR,
    CINR,
    IDPR,
    JOURSR,
    MOISR,
    ANNEER,
    HEUREHR,
    HEUREMINR,
    DUREEHR,
    DUREEMINR,
    MATR,
    METHR,
    DEMR1,
    DEMR2,
    TYPER,
    COLUMNS
};




// Ajouter une réservation
int ajouter_reservation(char *filename, Reservation r) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        printReservation(f, r);
        fclose(f);
        return 1;
    }
    return 0;
}

// Modifier une réservation
int modifyReservation(char *filename, Reservation modifiedReservation) {
    Reservation reservation;
    int notModified = 1;
    FILE* reservationFile = fopen(filename, "r");
    if (reservationFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    FILE* tempFile = fopen("temp.txt", "w");

    while(scanReservation(reservationFile, &reservation) != EOF) {
            if (strcmp(reservation.idreservation, modifiedReservation.idreservation) != 0) {
                printReservation(tempFile, reservation);
            } else {
                printReservation(tempFile, modifiedReservation);
                notModified = 0;
            }
        }
    fclose(reservationFile);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
    return notModified;
}


int supprimer_reservation(char *filename, char *idreservation) {
    int supprime = 0;
    Reservation r;
    FILE *f = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (f != NULL && temp != NULL) {
        while (scanReservation(f, &r) != EOF) {
            if (strcmp(r.idreservation, idreservation) != 0) {
                printReservation(temp, r);
            } else {
                supprime = 1;
            }
        }
        fclose(f);
        fclose(temp);
        remove(filename);
        rename("temp.txt", filename);
    }
    return supprime;
}

void updateReservationDisplayFile(char *reservationFileDirectory, char *reservationDisplayFileDirectory) {
    Reservation reservation;
    FILE* reservationFile = fopen(reservationFileDirectory, "r");
    FILE *reservationDisplayFile = fopen(reservationDisplayFileDirectory, "w");
    while (scanReservation(reservationFile, &reservation) != EOF) {
        printReservation(reservationDisplayFile, reservation);
    }
    fclose(reservationFile);
    fclose(reservationDisplayFile);
}

// Chercher une réservation par son id
int getReservationByID(char *filename, Reservation *reservation,char *id) {
    FILE *f = fopen(filename, "r");
    while (scanReservation(f, reservation) != EOF) {
        if (strcmp(reservation->idreservation, id) == 0) {
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;

}
// Chercher une réservation par son cin pour le treeview 
void filterReservationByCIN(char *filename, char *cin) {
<<<<<<< HEAD
=======
     
>>>>>>> client
    Reservation r;
    FILE *displayFile = fopen("temp.txt", "w");
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (scanReservation(f, &r) != EOF) {
<<<<<<< HEAD
=======
            printf("batata\n");
>>>>>>> client
            if (strcmp(r.cin, cin) == 0) {
                printReservation(displayFile, r);
            }
        }
    fclose(f);
	fclose(displayFile);
    remove(filename);
    rename("temp.txt", filename);
    }
<<<<<<< HEAD
}

void filterReservationByDate(char *filename, int jour, int mois, int annee) {
    Reservation r;
    FILE *displayFile = fopen("temp.txt", "w");
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (scanReservation(f, &r) != EOF) {
            if ((r.jours == jour) && (r.mois == mois) && (r.annee == annee)) {
                printReservation(displayFile, r);
            }
        }
    fclose(f);
	fclose(displayFile);
    remove(filename);
    rename("temp.txt", filename);
    }
=======
    
>>>>>>> client
}



int scanReservation(FILE *reservationFile, Reservation *r) {
	return fscanf(reservationFile, "%s %s %s %d %d %d %d %d %d %d %s %d %d %d %s\n",
                         r->idreservation, r->cin, r->parkingID, &r->jours, &r->mois, &r->annee,
                         &r->heureh, &r->heuremin, &r->dureeh, &r->dureemin,
                         r->mat, &r->methpai, &r->demspec[0], &r->demspec[1], r->type);

}

int printReservation(FILE *reservationFile, Reservation r) {
	return fprintf(reservationFile, "%s %s %s %d %d %d %d %d %d %d %s %d %d %d %s\n",
                        r.idreservation, r.cin, r.parkingID, r.jours, r.mois, r.annee,
                        r.heureh, r.heuremin, r.dureeh, r.dureemin,
                        r.mat, r.methpai, r.demspec[0], r.demspec[1], r.type);
}




  




