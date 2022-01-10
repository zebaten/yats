#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <pthread.h>
#define max_size 50

#define TX 5
#define TY 5

#define FIFONAME "YourTooSlow"
#define FIFONAME_JUG1 "YourTooSlow_j1"
#define FIFONAME_JUG2 "YourTooSlow_j2"
#define FIFONAME_JUG3 "YourTooSlow_j3"
#define FIFONAME_JUG4 "YourTooSlow_j4"
 
void printTablero();
int numeros[max_size];

sem_t semaforos;

void run1 (int jug1, int jug2, int t1, int t2, int g, int *x, int *y, int *j);

void run2 (int jug1, int jug2, int jug3, int t1, int t2, int t3, int g, int *x, int *y, int *j);

void run3 (int jug1, int jug2, int jug3, int jug4, int t1, int t2, int t3, int t4, int g, int *x, int *y, int *j);

void main (){

    unlink(FIFONAME);
    unlink(FIFONAME_JUG1);
    unlink(FIFONAME_JUG2);
    unlink(FIFONAME_JUG3);
    unlink(FIFONAME_JUG4);

    int jugadores;
    int i;
    int tamTabla;
    int num;
    int x=0, y=0, j=0;

    printf("Cuantos jugadores? ");
    scanf("%d", &jugadores);
        
        if(jugadores>4){
            printf("el numero de jugadores maximo es 4");
        }  

        switch (jugadores){
        case 1:
            printf("se necesitan al menos 2 jugadores, máximo 4");
            break;
        case 2:
            tamTabla=8;
            num = 16;
            int tablero[tamTabla][tamTabla];
            int valores[30];

            int numeros = malloc(num * sizeof(int));
            for(int i = 0; i < num; i++){
                if(numeros[i] != numeros[i-1] && i > 0){
                    numeros[i] = rand() %max_size +1;
                }else if(i==0){
                    numeros[i] = rand() %max_size +1;
                }
                
            }
            /*
            for(i=0; i<tamTabla; i++){
                for (j = 0; j < tamTabla; j++)
                {
                    printf("test1");
                    if(*arrayNumerosAleatorios(16)!=0){
                        printf("test2");
                        tablero[i][j]=*arrayNumerosAleatorios(16); 
                    }
                    else{
                        tablero[i][j]=0; 
                    }
                        printf("test3");
                }
                
            }*/
            printTablero(tablero,tamTabla);
            break;
        case 3:
            tamTabla=10;
            num = 25;
            int tablero[tamTabla][tamTabla];
            int valores[30];

            int numeros = malloc(num * sizeof(int));
            for(int i = 0; i < num; i++){
                if(numeros[i] != numeros[i-1] && i > 0){
                    numeros[i] = rand() %max_size +1;
                }else if(i==0){
                    numeros[i] = rand() %max_size +1;
                }
                
            }
            /*
            for(int i=0; i<tamTabla; i++){
                for (int j = 0; j < tamTabla; j++)
                {
                    if(*arrayNumerosAleatorios(25)!=0){
                        
                        tablero[i][j]=*arrayNumerosAleatorios(25); 
                    }
                    else{
                        tablero[i][j]=0; 
                    }
                        
                }
                
            }*/
            printTablero(tablero,tamTabla);
            break;

        case 4:
            tamTabla=12;
            num = 36;
            int tablero[tamTabla][tamTabla];
            int valores[30];

            int numeros = malloc(num * sizeof(int));
            for(int i = 0; i < num; i++){
                if(numeros[i] != numeros[i-1] && i > 0){
                    numeros[i] = rand() %max_size +1;
                }else if(i==0){
                    numeros[i] = rand() %max_size +1;
                }
                
            }
            /*
            for(int i=0; i<tamTabla; i++){
                for (int j = 0; j < tamTabla; j++)
                {
                    if(*arrayNumerosAleatorios(36)!=0){
                    
                        
                        tablero[i][j]=*arrayNumerosAleatorios(36); 
                    }
                    else{
                        tablero[i][j]=0; 
                    }
                        
                }
                
            }*/

            printTablero(tablero,tamTabla);
            break;

            default: break;
    }


    int jug1, jug2, jug3, jug4;
    int fd_g, fd_t1, fd_t2, fd_t3, fd_t4;

    if(jugadores >= 2){
        if(mkfifo(FIFONAME,666)){ 
            perror("mkfifo");
            return(1);
        }
        if(mkfifo(FIFONAME_JUG1,666)){ 
            perror("mkfifo");
            return(1);
        }
        if(mkfifo(FIFONAME_JUG2,666)){ 
            perror("mkfifo");
            return(1);
        }


        if(fd_t1 = open(FIFONAME_JUG1, O_RDWR)) < 0) { 
            perror("Open t1");
            exit(1);
        }
        if(fd_t2 = open(FIFONAME_JUG2, O_RDWR)) < 0) { 
            perror("Open t2");
            exit(1);
        }
        if(fd_g = open(FIFONAME, O_RDWR)) < 0) { 
            perror("Open FDG");
            exit(1);
        }
        jug1 = fork();
        if(jug1 == 0){ 
            printf("Jugador 1: %d\n", getpid());
        }else{
            printf("PID jugador 1: %d\n", jug1);
            jug2 = fork();
            if(jug2 == 0){ 
                printf("Jugador 2: %d\n", getpid());
            }else{
                printf("PID jugador 2: %d\n", jug2);  
            }
        }
    }
    if(jugadores >= 3){
        if(mkfifo(FIFONAME_JUG3,666)){ 
            perror("mkfifo");
            return(1);
        }
        if(fd_t3 = open(FIFONAME_JUG3, O_RDWR)) < 0) { 
            perror("Open t3");
            exit(1);
        }
        jug3 = fork();
        if(jug3 == 0){ 
            printf("Jugador 3: %d\n", getpid());
        }else{
            printf("PID jugador 3: %d\n", jug3);
        } 
    }

    if(jugadores == 4){
        if(mkfifo(FIFONAME_JUG4,666)){ 
            perror("mkfifo");
            return(1);
        }
        if(fd_t3 = open(FIFONAME_JUG4, O_RDWR)) < 0) { 
            perror("Open t4");
            exit(1);
        }
        jug3 = fork();
        if(jug3 == 0){ 
            printf("Jugador 4: %d\n", getpid());
        }else{
            printf("PID jugador 4: %d\n", jug4);
        } 
    }

    if(jugadores == 2){ 
        if(jug1 > 0 && jug2 >0){ 
            while(1);
        }
        else{
            while(1){
                run1(jug1,jug2,fd_t1,fd_t2,fd_g, &x,&y,&j);
                printf("coordenada x: %d y:%d jugador:%d",x,y,j);
            }
        }
    }
    if(jugadores == 3){ 
        if(jug1 > 0 && jug2 >0 &jug3){ 
            while(1);
        }
        else{
            run2(jug1,jug2,jug3,fd_t1,fd_t2,fd_t3,fd_g, &x,&y,&j);
        }
    }
    if(jugadores == 4){ 
        if(jug1 > 0 && jug >0){ 
            while(1);
        }
        else{
            run3(jug1,jug2,jug3,jug4,fd_t1,fd_t2,fd_t3,fd_t4,fd_g, &x,&y,&j);
        }
    }
    return 0;
}

void printTablero(int **tablero, int Max){
    
    for(int i=0; i<Max;i++){
        for (int j = 0; j < Max; j++)
        {
            printf("[%d] ", tablero[i][j]);
            printf("\n");
        }
        printf("\n");     
    }

}

void run1 (int jug1, int jug2, int t1, int t2, int g, int *x, int *y, int *j){
    printf("2 jugadores\n");
    int a;
    char buffer[1024];
    t1 = open(FIFONAME_JUG1, O_RDWR);
    t2 = open(FIFONAME_JUG2, O_RDWR);
    if((a = read(g,buffer, sizeof(buffer))) > 0){
        write(1, buffer, a);
        x* = buffer[0] - "0";
        close(g);
    }
    g = open(FIFONAME, O_RDWR);
    if((a = read(g,buffer, sizeof(buffer))) > 0){
        write(1, buffer, a);
        y* = buffer[0] - "0";
        close(g);
    }
    if(jug1 == 0){
        write(t1, "muy lento", 21);
        close(t1);
        *j=2;
    }
    else{
        write(t2, "muy lento", 21);
        close(t2);
        *j=1;
    }
}

void run2 (int jug1, int jug2,int jug3, int t1, int t2, int t3, int g, int *x, int *y, int *j){
    printf("3 jugadores\n");
    int a x=0,y=0;
    char buffer[1024];
    t1 = open(FIFONAME_JUG1, O_RDWR);
    t2 = open(FIFONAME_JUG2, O_RDWR);
    while(1){
        if((a = read(g,buffer, sizeof(buffer))) > 0){
            write(1, buffer, a);
            *x = buffer[0] - "0";
            close(g);
        }
        
        if((a = read(g,buffer, sizeof(buffer))) > 0){
            write(1, buffer, a);
            *y = buffer[0] - "0";
            
        }
        if(jug1 == 0){
            write(t1, "muy lento", 21);
            
        }
        else if(jug2==0){
            write(t2, "muy lento", 21);
        }
        else{
            write(t3, "muy lento", 21);
        }  
    }
}
void run3 (int jug1, int jug2,int jug3,int jug3, int t1, int t2, int t3,int t4, int g, int *x, int *y, int *j){
    printf("3 jugadores\n");
    int a, x=0,y=0;
    char buffer[1024];
  
    while(1){
        if((a = read(g,buffer, sizeof(buffer))) > 0){
            write(1, buffer, a);
            *x = buffer[0] - "0";
        }
        
        if((a = read(g,buffer, sizeof(buffer))) > 0){
            write(1, buffer, a);
            *y = buffer[0] - "0";
            
        }
        if(jug1 == 0){
            write(t1, "muy lento", 21);
            
        }
        else if(jug2==0){
            write(t2, "muy lento", 21);
        }
        else if(jug3==0){
            write(t3, "muy lento", 21);
        }else{
            write(t4, "muy lento", 21);
        } 
    }
}