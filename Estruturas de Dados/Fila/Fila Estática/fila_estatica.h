#define MAX 100

typedef struct {
    int inicio, fim, tam;
    int dados[MAX];
} Fila;

void inicializa_fila(Fila *f);
int esta_cheia(Fila *f);
int esta_vazia(Fila *f);
int enqueue(Fila *f, int val);
int dequeue(Fila *f, int *val);
void imprime_fila(const char *mensagem, Fila *f);