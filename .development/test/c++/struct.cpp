#include <stdio.h>
#include <string.h>

struct Candidato {
    char nome[50];
    int numero;
    char partido[20];
    int votos;
};

struct Eleitor {
    char nome[50];
    int titulo;
};

int main() {
    struct Candidato candidatos[2] = {
        {"Joao", 10, "ABC", 0},
        {"maria", 20, "XYZ", 0}
    };
    struct Eleitor eleitores[3] = {
        {"Carlos", 111},
        {"Ana", 222},
        {"Pedro", 333}
    };

    int titulos_votados[3] = { 0 };
    for (int i = 0; i < 3; i++) {
        int titulo, voto;
        printf("Eleitor %s, digite seu titulo: ", eleitores[i].nome);
        scanf_s("%d", &titulo);
        int valido = 0;
        for (int j = 0; j < 3; j++) {
            if (eleitores[j].titulo == titulo && titulos_votados[j] == 0) {
                valido = 1;
                titulos_votados[j] = 1;
                break;
            }
        }
        if (valido) {
            printf("Digite o numero do candidato");
            scanf_s("%d", &voto);
            for (int k = 0; k < 2; k++) {
                if (candidatos[k].numero == voto) {
                    candidatos[k].votos++;
                }
            }
        }
        else {
            printf("Titulo invalido ou ja votou.\n");
        }
    }
    printf("\nresultado da eleicao:\n");
    for (int i = 0; i < 2; i++) {
        printf("Candidato %s (%s) - votos: %d\n", candidatos[i].nome, \
            candidatos[i].partido, candidatos[i].votos);
    }

    return 0;
}

