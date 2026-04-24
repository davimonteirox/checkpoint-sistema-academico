#include <stdio.h>
#include <string.h>

#define MAX 5

char nomes[MAX][50];
float nota1[MAX], nota2[MAX], media[MAX];
int total = 0;

float calcularMedia(float n1, float n2) {
    return (n1 + n2) / 2;
}

void situacao(float m) {
    if (m >= 6)
        printf("Aprovado\n");
    else
        printf("Reprovado\n");
}

void cadastrar() {
    if (total >= MAX) {
        printf("Limite atingido\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", nomes[total]);

    printf("Nota 1: ");
    scanf("%f", &nota1[total]);

    printf("Nota 2: ");
    scanf("%f", &nota2[total]);

    media[total] = calcularMedia(nota1[total], nota2[total]);
    total++;

    printf("Aluno cadastrado!\n");
}

void listar() {
    for (int i = 0; i < total; i++) {
        printf("\nAluno: %s\n", nomes[i]);
        printf("Media: %.2f\n", media[i]);
        printf("Situacao: ");
        situacao(media[i]);
    }
}

int main() {
    int op;

    do {
        printf("\n1 - Cadastrar\n2 - Listar\n0 - Sair\nOpcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
        }

    } while(op != 0);

    return 0;
}
