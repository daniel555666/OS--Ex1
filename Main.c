#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>


#define lenght 50

void printDir(){
    DIR * dir;
    struct dirnet *sdir;
     dir=opendir(".");
     if(dir==NULL){
         printf("Erro Somthing Bad Happened :(\n");
         return;
     }
    while((sdir=readdir(sdir))!=NULL){
        printf("%s/t", sdir->d_name);

    }
    printf("/n");
    closedir(dir);


}

int main(int argc, char const *argv[])
{
    char command[lenght];
    char location[lenght];
    if(getcwd(location, lenght) == NULL)
    {
        printf("Erro Somthing Bad Happened :(\n");
        return 1;
    }
    while (strcmp(command, "EXIT"))
    {
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
        else if(strcmp(command,"DIR")==0){
            printDir();
        }
    }
    return 0;
}
