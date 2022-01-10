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

int main(){
    int a, g, t1;
    char buffer[1024];
    if ((t1 = open(FIFONAME_JUG1, O_RDWR)) < 0)
    {
       perror("open T1");
       exit(1);
    }
    if ((g = open(FIFONAME, O_RDWR)) < 0)
    {
        perror("open FDG");
        exit(1);
    }
    while(1){
        //Envía coordenadas al servidor
        printf("Coordenada x : \n");
        if ((a = read(0, buffer, sizeof(buffer))) > 0)
        {
            write(g, buffer, a);
        }

        printf("Coordenada y : \n");
        if ((a = read(0, buffer, sizeof(buffer))) > 0)
        {
            write(g, buffer, a);
        }

        if ((a = read(t1, buffer, sizeof(buffer))) > 0)
        {
            write(1, buffer, a);
        }
    }
}