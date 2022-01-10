#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sem.h>


#define FIFONAME "YourTooSlow"
#define FIFONAME_JUG1 "YourTooSlow_j1"
#define FIFONAME_JUG2 "YourTooSlow_j2"
#define FIFONAME_JUG3 "YourTooSlow_j3"
#define FIFONAME_JUG4 "YourTooSlow_j4"

int main(){
    int n, g, t1;
    int jug=0;
    char buffer[1024];

    do{
        printf ("Indique su numero de jugador ");
        scanf ("%d", &jug);
    }while(jug<1 || jug>4);
    if ((g = open(FIFONAME, O_RDWR)) < 0){
        perror("open FDG");
        exit(1);
    }
    switch(jug){
        case 1:
            if ((t1 = open(FIFONAME_JUG1, O_RDWR)) < 0){
                perror("open C1");
                exit(1);
            }
            break;
        case 2:
            if ((t1 = open(FIFONAME_JUG2, O_RDWR)) < 0){
                perror("open C2");
                exit(1);
            }
            break;
        case 3:
            if ((t1 = open(FIFONAME_JUG3, O_RDWR)) < 0){
                perror("open C3");
                exit(1);
            }
            break;
        case 4:
            if ((t1 = open(FIFONAME_JUG4, O_RDWR)) < 0){
                perror("open C4");
                exit(1);
            }
            break;
    }
    while(1){ //Envío de datos al server
        printf("Coordenada x : \n");
        if ((n = read(0, buffer, sizeof(buffer))) > 0){
            write(g, buffer, n);
        }

        printf("Coordenada y : \n");
        if ((n = read(0, buffer, sizeof(buffer))) > 0){
            write(g, buffer, n);
        }
        sleep(1);
        if ((n = read(t1, buffer, sizeof(buffer))) > 0){
            write(1, buffer, n);
        }
        sleep(1);
    }
}