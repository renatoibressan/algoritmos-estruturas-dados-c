typedef struct no {
    int dado;
    struct no *esquerda;
    struct no *direita;
} No;

void menu();
No* criar(int val);
No* inserir(No *raiz, int val);
No* buscar(No *raiz, int val);
No* minimo(No *no);
No* remover(No *raiz, int val);
void percursos(No *raiz);
void liberar(No **raiz);