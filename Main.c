#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define lenght 100

void printDir()
{
    DIR *dir;
    struct dirent *sdir;
    dir = opendir(".");
    if (dir == NULL)
    {
        printf("Erro Somthing Bad Happened :(\n");
        return;
    }
    while ((sdir = readdir(dir)) != NULL)
    {
        if (sdir->d_name[0] != '.')
        {
            printf("%s\t", sdir->d_name);
        }
    }
    printf("\n");
    closedir(dir);
}
void updateLocation(char *location)
{
    if (getcwd(location, lenght) == NULL)
    {
        printf("Erro Somthing Bad Happened :(\n");
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    char command[lenght];
    char location[lenght];

    while (strcmp(command, "EXIT"))
    {
        updateLocation(location);
        // printf("yes master>$ ");
        printf("%s>", location);
        gets(command);
        if (strncmp(command, "ECHO ", 5) == 0)
        {
            for (int i = 5; i < lenght && command[i] != '\0'; i++)
            {
                printf("%c", command[i]);
            }
            printf("\n");
        }
        else if (strcmp(command, "DIR") == 0)
        {
            printDir();
        }
        else if (strncmp(command, "CD ", 3) == 0)
        {
            if (chdir(&(command[3])) != 0)
            {
                printf("Erro Somthing Bad Happened :(\n");
                return 1;
            }
            // chdir היא פונקצית קריאה למערכת
        }
        else if (strncmp(command, "COPY ", 5) == 0)
        {
        
        }
        else
        {
            //system(command);
            // system היא פונקצית קריאה למערכת

            int check = fork();
            if(check<0){
                printf("Erro Somthing Bad Happened :(\n");
                return 1;
            }
            if (check==0){
                char str1[lenght]="/bin/??";
                strcat(str1,command);
                printf("cdddass");
                execlp(command,command,NULL);
            }
            wait();
        }
            
        
    }
    return 0;
}
