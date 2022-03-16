#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define lenght 50

int main(int argc, char const *argv[])
{
    char comand[lenght];
    char location[lenght];
    if(getcwd(location, lenght) == NULL)
    {
        printf("Erro Somthing Bad Happened :(\n");
        return 1;
    }
    while (strcmp(comand, "EXIT"))
    {
        // printf("yes master>$ "); 
        printf("%s>", location);
        gets(comand);

        if (strncmp(comand, "ECHO ", 5) == 0)
        {
            for (int i = 5; i < lenght && comand[i] != '\0'; i++)
            {    
                printf("%c", comand[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
