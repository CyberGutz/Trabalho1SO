#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    pid_t task;
    int status, retorno;
    
    char comando[50];
    char *stoken;
    
    char path[PATH_MAX];
    getcwd(path, sizeof(path));

    system("clear");
    printf("\n*->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->*\n");
    printf("\n**************************** RUSH !!! ************************\n");
    printf("\n**************************************************************\n");
    printf("\n*********************** SEJA BEM VINDO ***********************\n");
    printf("\n*->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->*\n\n");

    
    

    while(1){
        sleep(1);
        argc = 0;
        printf("\n%s $ ",path);
        fgets(comando, 50, stdin);
        comando[strcspn(comando,"\n")] = '\0';

        if(strcmp(comando, "exit") == 0){
            printf("\n****************************LOGOUT****************************\n");
            printf("\n                         ->System log:\n\n");
            system("uptime");
            printf("\n");
            break;
        }

        stoken = strtok(comando, " ");

        while(stoken != NULL){
            argc++;
            argv[argc] = stoken;
            stoken = strtok (NULL, " \n");
            printf("\nArgc\t\t%d\n\nArgv\t\t%s\n\nToken\t\t%s\n\n",argc, argv[argc], stoken);
        }
        argv[argc++] = stoken;
        printf("\nArgc\t\t%d\n\nArgv\t\t%s\n\nToken\t\t%s\n\n",argc, argv[argc], stoken);
        
        task = fork();

        if(task < 0){      
            perror("Error:");
            exit(1);
        }

        else if(task == 0 && strcmp(comando, "exit") != 0){
            execvp(comando, argv);

            printf("\nError: it was not possible to execute %s\n",comando);
            exit(1);
        }

        else{
            retorno = waitpid(task, &status, 1);
        }
            
    }

    exit(0);
}