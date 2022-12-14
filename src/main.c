#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

int separaEsp(char *comando, char *argv[]){
    int argc = 0;
    char *token = strtok(comando, " ");

    printf("\ncomando: %s \ttoken: %s\targc: %d \targv[%d]: %s\n",comando, token, argc, argc, argv[argc]);
    while(token != NULL){
        argv[argc] = token;
        argc++;
        token= strtok (NULL, " \n");
        printf("\ncomando: %s \ttoken: %s\targc: %d \targv[%d]: %s\n",comando, token, argc, argc, argv[argc]);
    }
    argv[argc++] = token;

    printf("\ncomando: %s \ttoken: %s\targc: %d \targv[%d]: %s\n",comando, token, argc, argc, argv[argc]);

    return argc;
}

int separaPipe(char *comando, char *argv[]){
    int argc = 0;
    char *token = strtok(comando, " | ");

    printf("\ncomando: %s \ttoken: %s\targc: %d \targv[%d]: %s\n",comando, token, argc, argc, argv[argc]);
    while(token != NULL){
        argv[argc] = token;
        argc++;
        token= strtok (NULL, " \n");
        printf("\ncomando: %s \ttoken: %s\targc: %d \targv[%d]: %s\n",comando, token, argc, argc, argv[argc]);
    }
    argv[argc++] = token;
    printf("\ncomando: %s \ttoken: %s\targc: %d \targv[%d]: %s\n",comando, token, argc, argc, argv[argc]);

    return argc;
}

int main(int argc, char *argv[]){
    pid_t task;
    int status, retorno, indice;
    
    char comando[50];
    char *comandos[256];

    char path[PATH_MAX];
    getcwd(path, sizeof(path));

    system("clear");
    printf("\n*->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->*\n");
    printf("\n**************************** RUSH !!! ************************\n");
    printf("\n**************************************************************\n");
    printf("\n*********************** SEJA BEM VINDO ***********************\n");
    printf("\n*->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->*\n\n");

    
    

    while(1){
        //O sleep evita que o exec execute no lugar errado (depois do $)
        sleep(1);
        argc = 0;
        indice = 0;

        printf("\n%s $ ",path);

        //Pega o comando
        fgets(comando, 50, stdin);
        comando[strcspn(comando,"\n")] = '\0';

        //Exit vem antes pra n??o sair duplicado
        if(strcmp(comando, "exit") == 0){
            printf("\n****************************LOGOUT****************************\n");
            printf("\n                         ->System log:\n\n");
            system("uptime");
            printf("\n");
            break;
        }

        //clear funciona as vezes
        if(strcmp(comando, "clear") == 0){
            system("clear");
        }

        //indice = separaPipe(comando, comandos);

        argc = separaEsp(comando, argv);


        //Segue o padr??o pai/filho mostrados em aula
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