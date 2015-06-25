/**************************************************************
    Nome: Bárbara Coelho.
    Programação de Computadores.
    Engenharia Eletrônica.
    IFSC.

                    Atividade -Ordenação de vetores

    -> Criar 3 vetores : 1 int, 1 float e 1 char.
    -> Chamar função bolha_gen para ordenalos.
    -> Mostrar o resultado.
**************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Protótipo de função */

void* acessa (void* v, int i, int tam);
void troca (void* a, void* b, int tam);
void bolha_gen (int n, void* v, int tam, int(*cmp)(void*,void*));
int compara_float (void* a, void* b);
int compara_int (void* a, void* b);
int compara_char (void* a, void* b);

int main()
{
    int i;
    char v_c[3] = {'a', 'c', 'b'};
    float v_f[5] = {12.4, 16.7, 13.7, 3.9, 7.2};
    int v_i[8] = {25, 48, 37, 12, 57, 86, 33, 92};
    bolha_gen(3, v_c, sizeof(char), compara_char);
    printf("Vetor ordenado 'char': ");
    for (i=0; i<3; i++)
        printf("%c ",v_c[i]);
    printf("\n");
    bolha_gen(5, v_f, sizeof(float), compara_float);
    printf("Vetor ordenado 'float': ");
    for (i=0; i<5; i++)
        printf("%.1f  ",v_f[i]);
    printf("\n");
    bolha_gen(8, v_i, sizeof(int), compara_int);
    printf("Vetor ordenado 'int': ");
    for (i=0; i<8; i++)
        printf("%d ",v_i[i]);
    printf("\n");
    return 0;
}

/* Funções */

void* acessa (void* v, int i, int tam)
{
    char* t = (char*)v;
    t += tam*i;         // t = t + tam*i;
    return (void*)t;
}
/* Troca ordem do vetor*/
void troca (void* a, void* b, int tam)
{
    char* v1 = (char*) a;
    char* v2 = (char*) b;
    int i;
    for (i=0; i<tam; i++)
    {
        char temp = v1[i];
        v1[i] = v2[i];
        v2[i] = temp;
    }
}
/* Ordenação bolha (genérica) */
void bolha_gen (int n, void* v, int tam, int(*cmp)(void*,void*))
{
    int i, j;
    for (i=n-1; i>0; i--)
    {
        int fez_troca = 0;
        for (j=0; j<i; j++)
        {
            void* p1 = acessa(v,j,tam);
            void* p2 = acessa(v,j+1,tam);
            if (cmp(p1,p2))
            troca(p1,p2,tam);
            fez_troca = 1;
        }
        if (fez_troca == 0) /* nao houve troca */
            return;
    }
}
/* Compara float */
int compara_float (void* a, void* b)
{
    float* p1 = (float*) a;
    float* p2 = (float*) b;
    float f1 = *p1;
    float f2 = *p2;
    if (f1 > f2)
        return 1;
    else
        return 0;
}
/* Compara int */
int compara_int (void* a, void* b)
{
    int* p1 = (int*) a;
    int* p2 = (int*) b;
    int f1 = *p1;
    int f2 = *p2;
    if (f1 > f2)
        return 1;
    else
        return 0;
}
/* Compara char */
int compara_char (void* a, void* b)
{
    char* p1 = (char*) a;
    char* p2 = (char*) b;
    char f1 = *p1;
    char f2 = *p2;
    if (f1 > f2)
        return 1;
    else
        return 0;
}
