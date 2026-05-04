#define MAX 100

typedef struct {
    int topo;
    int dados[MAX];
} Pilha;

void inicializa_pilha(Pilha *p);
int esta_cheia(Pilha *p);
int esta_vazia(Pilha *p);
int push(Pilha *p, int val);
int pop(Pilha *p, int *val);
int peek(Pilha *p);
void imprime_pilha(const char *mensagem, Pilha *p);