#define TAMANHO 10

typedef struct no {
    int chave, dado;
    struct no *prox;
} No;

int hash(int chave);
void inicializar_tabela(No *tabela[]);
void inserir(No *tabela[], int chave, int val);
int buscar(No *tabela[], int chave);
void imprimir(const char *mensagem, No *tabela[]);
void liberar(No *tabela[]);