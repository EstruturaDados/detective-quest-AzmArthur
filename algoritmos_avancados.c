#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// sala
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// conectar salas
void conectarSalas(Sala* origem, Sala* esquerda, Sala* direita) {
    origem->esquerda = esquerda;
    origem->direita = direita;
}

// funcoes andar
void explorarSalas(Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\n Você está em: %s\n", atual->nome);

        // Se for uma sala sem saídas, terminou
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("🚪 Fim do caminho! Não há mais saídas.\n");
            break;
        }

        printf("Escolha seu caminho:\n");
        if (atual->esquerda) printf("  (e) Ir para a esquerda: %s\n", atual->esquerda->nome);
        if (atual->direita) printf("  (d) Ir para a direita: %s\n", atual->direita->nome);
        printf("  (s) Sair da exploração\n");
        printf(" Sua escolha: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (opcao == 's') {
            printf("\n Você decidiu sair da mansão.\n");
            break;
        } else {
            printf("\n Caminho inválido! Tente novamente.\n");
        }
    }
}

// programa
int main() {
    // Todas as Salas
    Sala* entrada = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sótão");
    Sala* laboratorio = criarSala("Laboratório Secreto");

    // 
    conectarSalas(entrada, biblioteca, cozinha);
    conectarSalas(cozinha, sotao, laboratorio);

    // Mensagem
    printf("Bem-vindo à Mansão do Mistério!!\n");
    explorarSalas(entrada);

    // Mem
    free(entrada);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(laboratorio);

    printf("\nFim do jogo.\n");
    return 0;
}
