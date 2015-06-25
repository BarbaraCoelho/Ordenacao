/**************************************************************
    Nome: Bárbara Coelho.
    Programação de Computadores.
    Engenharia Eletrônica.
    IFSC.

                    Atividade -Ordenação Bolha
**************************************************************/

#include <stdio.h>
#include <stdlib.h>

void bolha (int n, int* v);
void bolha2 (int n, int* v);
void bolha_rec (int n, int* v);

int main()
{
    int i;
    int v[8] = {25,48,37,12,57,86,33,92};
    bolha2(8,v);
    printf("Vetor ordenado: ");
    for (i=0; i<8; i++)
        printf("%d ",v[i]);
    printf("\n");
    return 0;
}

/* Ordenação bolha */
void bolha (int n, int* v)
{
    int i,j,k;
    for (i=n-1; i>=1; i--)
        for (j=0; j<i; j++)
            if (v[j]>v[j+1]) /* troca */
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                for (k=0; k<8; k++)     // para visualizar a troca
                    printf("%d ",v[k]); // "
                printf("\n");           // "
            }
}


/* Ordenação bolha (2a. versão) */
void bolha2 (int n, int* v)
{
    int i, j, k;
    for (i=n-1; i>0; i--)
    {
        int troca = 0;
        for (j=0; j<i; j++)
            if (v[j]>v[j+1]) /* troca */
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

/* Ordenação bolha recursiva */
void bolha_rec (int n, int* v)
{
    int j,k;
    int troca = 0;
    for (j=0; j<n-1; j++)
        if (v[j]>v[j+1])  /* troca */
        {
            int temp = v[j];
            v[j] = v[j+1];
            v[j+1] = temp;
            troca = 1;
        }
    for (k=0; k<8; k++)     // para visualizar a troca
        printf("%d ",v[k]); // "
    printf("\n");           // "
    if (troca != 0) /* houve troca */
        bolha_rec(n-1,v);
}

