#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    // változók deklarálása
    char * binaryPath;
    char parancs[30];
    char args[3][30];
    int i = 0;
    
    // parancs bekérése
    printf("Add meg a SHELL parancsot: ");
    fgets(parancs, sizeof(parancs), stdin);
    
    //parancs feldarabolása
    char * token = strtok(parancs, " ");
    while(token != NULL)
    {
        strcpy(args[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    
    //a program hozzáfűzése az elérési útjához
    if (asprintf(&binaryPath, "/bin/%s", args[0]) == -1)
    {
        perror("asprintf");
        return 1;
    }

    //különböző tagszámú parancsok lekezelése
    switch(i)
    {
        case 1:
            execl(binaryPath, binaryPath, NULL, NULL, NULL);
            break;
        case 2:
            execl(binaryPath, binaryPath, args[1], NULL, NULL);
            break;
        case 3:
            execl(binaryPath, binaryPath, args[1], args[2], NULL);
            break;
        default:
            break;
    }

    return 0;
}