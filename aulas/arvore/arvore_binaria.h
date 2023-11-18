typedef struct No{
    int valor;
    struct No* no_esquerda;
    struct No* no_direita;
}No;

void ab_inserir_no(No** raiz, int valor);
void ab_imprimir_em_ordem(No* raiz);