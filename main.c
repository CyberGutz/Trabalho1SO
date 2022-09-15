#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]){
    pid_t task;
    int status, retorno;
    char comando[50];
    char path[PATH_MAX];
    getcwd(path, sizeof(path));

    while(1){
        printf("\n%s $ ",path);
        fgets(comando, 50, stdin);
        comando[strcspn(comando,"\n")] = '\0';
        
        task = fork();

        if(task < 0){      
            perror("Error:");
            exit(1);
        }
        else if(task == 0 && strcmp(comando, "exit") != 0){
            execlp(comando, comando,(char *) NULL);
            printf("Error: it was not possible to execute %s",comando);
            exit(1);
        }
        else{
            retorno = wait(&status);
        }


        fflush(stdin);

        if(strcmp(comando, "exit") == 0){
            printf("\nlogout\n");
            printf("System log: \n");
            system("uptime");
            break;
        }
            
    }

    exit(0);
}