#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, int argv){

    char comando[50];
    char path[PATH_MAX];
    getcwd(path, sizeof(path));

    while(1){
        printf("%s $",path);
        fgets(comando, 50, stdin);
        comando[strcspn(comando,"\n")] = '\0';
        fflush(stdin);

        if(strcmp(comando, "exit") == 0){
            printf("\nSession log: \n");
            system("uptime");
            break;
        }
            
    }

    exit(0);
}