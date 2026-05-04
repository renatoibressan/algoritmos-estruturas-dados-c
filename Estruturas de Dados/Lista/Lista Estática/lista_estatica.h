#define MAX 100

typedef struct {
    int qtd;
    int dados[MAX];
} Lista;

void inicializa_lista(Lista *l);
int insere_final(Lista *l, int val);
void imprime_lista(const char *mensagem, Lista *l);