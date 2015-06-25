#include <stdio.h>
#include <stdlib.h>

int compara (int a, int b);
void bolha (int n, int* v);

int main()
{
    int i;
    int v[8] = {25,48,37,12,57,86,33,92};
    bolha(8,v);
    printf("Vetor ordenado: ");
    for (i=0; i<8; i++)
        printf("%d ",v[i]);
    printf("\n");
    return 0;
}

/* Função auxiliar de comparação */
int compara (int a, int b)
{
    if (a > b)
        return 1;
    else
        return 0;
}

/* Ordenação bolha (3a. versão) */
void bolha (int n, int* v)
{
    int i, j, k;
    for (i=n-1; i>0; i--)
    {
        int troca = 0;
        for (j=0; j<i; j++)
            if (compara(v[j],v[j+1])) /* troca */
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                troca = 1;
            }
        for (k=0; k<8; k++)     // para visualizar a troca
            printf("%d ",v[k]); // "
        printf("\n");           // "
        if (troca == 0) /* nao houve troca */
            return;
    }
}
