#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define entropia_forte 60
#include <math.h>

int main()
{
    FILE *arq;
    FILE *senhaFraca;
    arq = fopen("senhas.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo.\n");
    } else {
        printf("Arquivo aberto com sucesso!\n\n");
    }

    char senha[tam_senha];
    double entropia;

    while (fgets(senha, tam_senha, arq) != NULL) {
        entropia = calculaEntropia(senha);

        printf("Entropia da senha %s", senha);
        printf("%f\n", entropia);

        if (entropia < entropia_forte) {
            senhaFraca = fopen("senhasFracas.txt", "a");
            printf("Sua senha é fraca.\n\n");

            if(verificaSenhaExiste(senha) == 0) {
                fprintf(senhaFraca, senha);
            }
            fclose(senhaFraca);
        } else {
            printf("Sua senha é forte!\n\n");
        }
    }

    return 0;
}
