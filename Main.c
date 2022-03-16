#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define lenght 30

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
        scanf("%s", comand);

        if (strncmp(comand, "ECHO", 5) == 0)
        {
            printf("\nDANIEL");
            // printf("%d\n", len);
            for (int i = 4; i < 50 /*&& comand[i] != '\0'*/; i++)
            {
                
                printf("%c", comand[i]);
            }

            printf("\n");
        }
    }
    return 0;
}
