typedef struct no {
    int dado;
    struct no *prox;
} No;

No* insere_inicio(No *head, int val);
void imprime_lista(const char *mensagem, No *head);
void libera_lista(No **head);