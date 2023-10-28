struct Objeto{
    char valor;
    struct Objeto* objeto_anterior;
    
};

struct Fila{
    struct Objeto* inicio;
    struct Objeto* final;
    int qtd_objetos;
};

struct Fila* fila();
void enfileirar (struct Objeto* o, struct Fila* F);
struct Objeto* desenfileirar(struct Fila* F);