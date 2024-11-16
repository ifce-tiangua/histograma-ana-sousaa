#include <stdio.h>
#include <stdlib.h>

void povoa_histograma(char* h[], int valor, int categorias) {
    
    for (int i = 0; i < valor; i++) {
        h[categorias][i] = '*';
    }
}

void imprimir_histograma(char* h[], int valores[], int categorias) {
    if (categorias == 0) {
        printf("vazio\n");
        return;
    }
    for (int i = 0; i < categorias; i++) {
        printf("%d ", valores[i]);
        if (valores[i] > 0) {
            for (int j = 0; j < valores[i]; j++) {
                printf("%c", h[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int categorias;
    scanf("%d", &categorias);
    
    int valores[categorias];
    char* histograma[categorias];

    for (int i = 0; i < categorias; i++) {
        scanf("%d", &valores[i]);
        if (valores[i] == 0) {
            histograma[i] = NULL;
        } else {
            histograma[i] = (char*)malloc(valores[i] * sizeof(char)); 
            povoa_histograma(histograma, valores[i], i); 
        }
    }

    imprimir_histograma(histograma, valores, categorias); 

    
    for (int i = 0; i < categorias; i++) {
        if (histograma[i] != NULL) {
            free(histograma[i]);
        }
    }

    return 0;
}
