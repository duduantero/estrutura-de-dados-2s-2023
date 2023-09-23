#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *f;

    fopen("teste.txt","a");
    if(f == NULL){
        perror("Não foi possível abrir o arquivo");
        exit(1);
    }

   int r =  fprintf(f,"texto na tela \n");

   if (r < 0){
    perror("Não foi possível escrever no arquivo");
    exit(1);
   }

    fclose(f);

    f = fopen("teste.txt","a");
    if(f == NULL){
        perror("Não foi possível abrir o arquivo");
        exit(1);
    }
char txt[100];
char txt[100];
char txt[100];

while (!feof(f))
{
    fscanf(f,"%s",&txt);
    printf("%s",&txt);
}


    exit(0);
}
