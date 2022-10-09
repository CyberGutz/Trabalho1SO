#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[256]){
    pid_t task;
    int status, retorno;
    char comando[50];
    char path[PATH_MAX];
    getcwd(path, sizeof(path));
    argc = 0;
    char *token;

    while(1){
        fflush(stdin);
        printf("\n%s $ ",path);
        fgets(comando, 50, stdin);
        comando[strcspn(comando,"\n")] = '\0';
        token = strtok(comando, " ");


        /*
        while(token != 0){
            argv[argc++] = token;
        }
        argv[argc] = NULL;

        */
        
        task = fork();

        if(task < 0){      
            perror("Error:");
            exit(1);
        }
        else if(task == 0 && strcmp(comando, "exit") != 0){
            printf("\n");
            execvp(comando, argv);
            printf("\nError: it was not possible to execute %s\n",comando);
            exit(1);
        }
        else{
            retorno = waitpid(task, &status, 1);
        }


        if(strcmp(comando, "clear") == 0){
            system("clear");
        }

        if(strcmp(comando, "exit") == 0){
            printf("\nlogout\n");
            printf("System log: \n");
            system("uptime");
            break;
        }
            
    }

    exit(0);
}