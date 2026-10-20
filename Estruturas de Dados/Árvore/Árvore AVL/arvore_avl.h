typedef struct no {
    int dado;
    struct no *esquerda;
    struct no *direita;
    int altura;
} No;

int altura(No *raiz);
int maior(int a, int b);
No* criar(int val);
int fator_balanceamento(No *raiz);
No* rotacionar_esquerda(No *x);
No* rotacionar_direita(No *y);
No* inserir(No *raiz, int val);
void percursos(No *raiz);
void liberar(No **raiz);