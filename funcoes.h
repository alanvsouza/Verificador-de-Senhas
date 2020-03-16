#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <string.h>
#define tam_senha 20

double calculaEntropia(char senha[tam_senha]);
int comparaString(char string1[tam_senha], char string2[tam_senha]);
int verificaSenhaExiste(char senha[tam_senha]);

#endif // FUNCOES_H_INCLUDED
