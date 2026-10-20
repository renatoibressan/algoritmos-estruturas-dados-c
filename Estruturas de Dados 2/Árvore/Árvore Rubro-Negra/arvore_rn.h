typedef enum { VERMELHO, PRETO } Cor;

typedef struct no {
    int dado;
    Cor cor;
    struct no *esquerda;
    struct no *direita;
    struct no *pai;
} No;

No* criar(int val);
void rotacionar_esquerda(No **raiz, No *x);
void rotacionar_direita(No **raiz, No *y);
void corrigir_insercao(No **raiz, No *z);
void inserir(No **raiz, int val);
void percursos(No *raiz);
void liberar(No **raiz);