//SUELLEN TEODORICO DOS SANTOS SILVA
//          15489275

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void le_arquivo(Lista* li, const char* nome_arquivo) {
    FILE* file = fopen(nome_arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    char linha[2];  // ler um dígito por linha
    while (fscanf(file, "%s", linha) != EOF) {
        if (linha[0] == 'I' || linha[0] == 'D') { // se for 'I' ou 'D', termina a leitura
            break;
        }
        insere_final(li, linha[0] - '0');  // converte e coloca na lista
    }

    fclose(file);
}

void alinhar_listas(Lista* li1, Lista* li2, char tipo) {
    int len1 = 0, len2 = 0;
    Nodo* n1 = li1->inicio;
    Nodo* n2 = li2->inicio;

    while (n1) { len1++; n1 = n1->prox; }
    while (n2) { len2++; n2 = n2->prox; }

    if (tipo == 'I') {
        while (len1 > len2) {
            insere_inicio(li2, 0);
            len2++;
        }
        while (len2 > len1) {
            insere_inicio(li1, 0);
            len1++;
        }
    } else if (tipo == 'D') {
        while (len1 > len2) {
            insere_final(li2, 0);
            len2++;
        }
        while (len2 > len1) {
            insere_final(li1, 0);
            len1++;
        }
    }
}

int main() {
    Lista* nro1 = cria_lista();
    Lista* nro2 = cria_lista();
    Lista* resultado = cria_lista();
    char tipo;

    le_arquivo(nro1, "nro1.txt");
    le_arquivo(nro2, "nro2.txt");

    // Leitura do tipo (I ou D)
    FILE* file1 = fopen("nro1.txt", "r");
    fscanf(file1, "%*s %*s %*s %*s %*s %c", &tipo);
    fclose(file1);

    // Alinhamento das listas
    alinhar_listas(nro1, nro2, tipo);

    // Exibição das listas
    exibe_lista(nro1);
    exibe_lista(nro2);

    int vai_um_final = soma_listas(nro1, nro2, resultado);

    exibe_lista(resultado);
    printf("%d\n", vai_um_final);

    libera_lista(nro1);
    libera_lista(nro2);
    libera_lista(resultado);

    return 0;
}
