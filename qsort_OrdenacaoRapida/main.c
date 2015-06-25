/**************************************************************
    Nome: Bárbara Coelho.
    Programação de Computadores.
    Engenharia Eletrônica.
    IFSC.

                Ordenação de vetores por qsort

**************************************************************/

#include <stdio.h>
#include <stdlib.h>

int comp_float (const void* p1, const void* p2);
int comp_int (const void* p1, const void* p2);
int comp_char (const void* p1, const void* p2);

int main (void)
{
    int i;
    char v_c[6] = {'a', 'u', 'c', 'b', 't', 'f'};
    int v_i[8] = {25, 48, 37, 12, 57, 86, 33, 92};
    float v_f[8] = {25.6,48.3,37.7,12.1,57.4,86.6,33.3,92.8};

    qsort(v_f,8,sizeof(float),comp_float);    // função da bibiloteca padrão
    printf("Vetor ordenado float: ");
    for (i=0; i<8; i++)
        printf("%g ",v_f[i]);
    printf("\n");

    qsort(v_i,8,sizeof(int),comp_int);       // função da bibiloteca padrão
    printf("Vetor ordenado int: ");
    for (i=0; i<8; i++)
        printf("%d ",v_i[i]);
    printf("\n");

    qsort(v_c,6,sizeof(char),comp_char);    // função da bibiloteca padrão
    printf("Vetor ordenado char: ");
    for (i=0; i<6; i++)
        printf("%c ",v_c[i]);
    printf("\n");

    return 0;
}

/* função de comparação de reais */
int comp_float (const void* p1, const void* p2)
{
    /* converte ponteiros genéricos para ponteiros de float */
    float *f1 = (float*)p1;
    float *f2 = (float*)p2;
    /* dados os ponteiros de float, faz a comparação */
    if (*f1 < *f2) return -1;
    else if (*f1 > * f2) return 1;
    else return 0;
}

int comp_int (const void* p1, const void* p2)
{
    /* converte ponteiros genéricos para ponteiros de int */
    int *f1 = (int*)p1;
    int *f2 = (int*)p2;
    /* dados os ponteiros de float, faz a comparação */
    if (*f1 < *f2) return -1;
    else if (*f1 > * f2) return 1;
    else return 0;
}

int comp_char (const void* p1, const void* p2)
{
    /* converte ponteiros genéricos para ponteiros de char */
    char *f1 = (char*)p1;
    char *f2 = (char*)p2;
    /* dados os ponteiros de float, faz a comparação */
    if (*f1 < *f2) return -1;
    else if (*f1 > * f2) return 1;
    else return 0;
}
