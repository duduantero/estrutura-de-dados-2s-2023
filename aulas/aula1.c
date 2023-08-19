#include <stdio.h>
#include <locale.h>


int  main (int arg, char* argv[]){
    setlocale(LC_ALL,  'Portuguese');
    printf("Olá, mundo");
}