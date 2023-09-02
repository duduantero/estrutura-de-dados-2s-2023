#include <stdio.h>
#include <stdlib.h> 

typedef struct P{
    int x;
    int y;
}Ponto;



int main(int argc, char const *argv[])
{
   Ponto ponto;
    ponto.x = 1;
    ponto.y =2;
    printf("%d %d",ponto.x, ponto.y);

    int qtd_pontos = atoi(argv[1]);
    Ponto* pontos = malloc(sizeof(ponto)*qtd_pontos);

    for (int i = 0; i < qtd_pontos; i++)
    {
        scanf("%d",&pontos[i]);
        scanf("%d",&pontos[i]);
    }
    for (int  i = 0; i < qtd_pontos; i++)
    {
        printf("(%d,%d)",pontos[i],pontos[i]);
    
    }
    
    



    return 0; 
}
