#include <stdio.h>
#include <stdlib.h>
#include "arvore_patricia.h"

int main() {
    No *arvore = NULL;
    printf("1. Inserindo as chaves:\n");
    char *nomes[] = {"Renato", "Fabricio", "Felipe", "Frederico", "Sergio"};
    int n = sizeof(nomes) / sizeof(nomes[0]);
    for (int i = 0; i < n; i++) {
        printf("Inserindo %s\n", nomes[i]);
        inserir(&arvore, nomes[i]);
    }
    printf("\n2. Percorrendo a arvore (exibindo as chaves armazenadas)\n");
    exibir(arvore);
    printf("\n3. Testando buscas\n");
    char *testes[] = {"Renato", "Flavio", "Sergio", "Juliano"};
    int busca = sizeof(testes) / sizeof(testes[0]);
    for (int i = 0; i < busca; i++) {
        No *resultado = buscar(arvore, testes[i]);
        if (resultado) printf("[SUCESSO] A chave %s esta no endereco %p da arvore\n", testes[i], (void*)resultado);
        else printf("[ERRO] A chave %s nao existe na arvore\n", testes[i]);
    }
    printf("\n4. Liberando a memoria da arvore\n");
    liberar(&arvore);
    if (!arvore) printf("\nPrograma encerrado com sucesso\n");
    return 0;
}