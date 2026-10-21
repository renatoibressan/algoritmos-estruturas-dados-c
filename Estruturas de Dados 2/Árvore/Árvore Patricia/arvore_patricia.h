typedef struct no {
    int bit_idx;
    char *chave;
    struct no *esquerda;
    struct no *direita;
} No;

int get_bit(const char *chave, int bit_idx);
No* criar(int bit_idx, char *chave);
int primeiro_bit_diferente(const char *k1, const char *k2);
No* inserir(No **raiz, char *chave);
No* buscar(No *raiz, const char *chave);
void percursos(No *atual, int bit_idx_pai);
void exibir(No *raiz);
void liberar_nos(No *atual, int bit_idx_pai);
void liberar(No **raiz);