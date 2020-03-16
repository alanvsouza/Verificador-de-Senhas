#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double calculaEntropia(char senha[tam_senha]){
    int grupos[8] = {0};
    int num_caracteres = 0;
    double entropia;
    for(int i=0; i<strlen(senha); i++) {
        if (senha[i] >= 33 && senha[i] <= 47 && grupos[0] == 0) {
            num_caracteres += 15;
            grupos[0] == 1;
        }
        else if (senha[i] >= 48 && senha[i] <= 57 && grupos[1] == 0) {
            num_caracteres += 10;
            grupos[1] == 1;
        }
        else if (senha[i] >= 58 && senha[i] <= 64 && grupos[2] == 0) {
            num_caracteres += 7;
            grupos[2] == 1;
        }
        else if (senha[i] >= 65 && senha[i] <= 90 && grupos[3] == 0) {
            num_caracteres += 26;
            grupos[3] == 1;
        }
        else if (senha[i] >= 91 && senha[i] <= 96 && grupos[4] == 0) {
            num_caracteres += 6;
            grupos[4] == 1;
        }
        else if (senha[i] >= 97 && senha[i] <= 122 && grupos[5] == 0) {
            num_caracteres += 26;
            grupos[5] == 1;
        }
        else if (senha[i] >= 123 && senha[i] <= 126 && grupos[6] == 0) {
            num_caracteres += 4;
            grupos[6] == 1;
        }
        else if (senha[i] >= 128 && senha[i] <= 255 && grupos[7] == 0) {
            num_caracteres += 128;
            grupos[7] == 1;
        }
    }
    double log_base2 = log(pow(num_caracteres, strlen(senha))) / log(2);

    entropia = log_base2;

    return entropia;
}

//compara duas strings
int comparaString(char string1[tam_senha], char string2[tam_senha]) {
    int teste = 0;

    if (strlen(string1) == strlen(string2)) { //comparando o tamanho das duas strings
        for(int i = 0; i < strlen(string1); i++) {
            if (string1[i] == string2[i]) {
                teste = 1;
            } else teste = 0;
        }
    } else {
        return 0;
    }

    return teste;
}

//verifica se a senha fraca já existe no arquivo
int verificaSenhaExiste(char senha[tam_senha]) {
    FILE *arq;
    arq = fopen("senhasFracas.txt", "r");
    char senhaFraca[tam_senha];

    while(fgets(senhaFraca, tam_senha, arq) != NULL) {
        if(comparaString(senha, senhaFraca) == 1) //se for igual a 1 significa que a senha já existe no arquivo
            return 1;
    }

    return 0;
}
