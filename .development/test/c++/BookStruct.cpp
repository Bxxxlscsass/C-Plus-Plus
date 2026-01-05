#include <stdio.h>
#include <string.h>

struct Livro
{
    char titulo[50];
    char autor[50];
    int ano;
    int emprestado;
};

struct Usuario {
    char nome[50];
    int id;
};

int main() {
    struct Livro livros[2];
    struct Usuario usuarios[2];

    for (int i = 0; i < 2; i++) {
        printf("Cadastro de livro %d: \n", i + 1);

        printf("Titulo: ");
        fgets(livros[i].titulo, 50, stdin);

        printf("Autor: ");
        fgets(livros[i].autor, 50, stdin);

        printf("Ano: ");
        scanf_s("%d", &livros[i].ano);

        livros[i].emprestado = 0;
        getchar();
    }

    for (int i = 0; i < 2; i++) {
        printf("Cadastro do usuario %d:\n", i + 1);

        printf("Nome: ");
        fgets(usuarios[i].nome, 50, stdin);

        printf("ID: ");
        scanf_s("%d", &usuarios[i].id);
        getchar();
    }
    printf("\nEmprestado livro 1 ao usuario 1...\n");
    livros[0].emprestado = usuarios[0].id;

    printf("Livro emprestado: %s para usuario %s\n",
        livros[0].titulo, usuarios[0].nome);

    printf("\nDevolvendo livro 1...\n");
    livros[0].emprestado = 0;
    printf("Livro devolvido.\n");

    return 0;
}

