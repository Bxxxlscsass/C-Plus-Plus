#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
};

void listar(struct Produto produtos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Produto: %sCodigo: %d\n", produtos[i].nome, \
            produtos[i].codigo);
    }
}

void buscar(struct Produto produtos[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Encontrado: %s, Preço: %.2f, Quantidade: %d\n", \
                produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

int main() {
    struct Produto produtos[3];
    for (int i = 0; i < 3; i++) {
        printf("Nome do produto %d: ", i + 1);
        fgets(produtos[i].nome, 50, stdin);
        printf("Codigo: ");
        scanf_s("%d", &produtos[i].codigo);
        printf("Preço: ");
        scanf_s("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf_s("%d", &produtos[i].quantidade);
        getchar(); //Limpar o buffer
    }
    listar(produtos, 3);
    int cod;
    printf("Digite o codigo para buscar: ");
    scanf_s("%d", &cod);
    buscar(produtos, 3, cod);
}


