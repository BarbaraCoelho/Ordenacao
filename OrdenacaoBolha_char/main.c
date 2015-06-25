/**********************************************************************

    Nome: Bárbara Coelho
    IFSC - Câmpus Florianópolis
    Engenharia Eletrônica
    Programação de Computadores II

                        Ordenação Bolha Alunos

**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
typedef struct lista Lista;

struct aluno
{
    char nome[21];
    char mat[8];
    char turma;
    char email[41];
};

struct lista
{
    Aluno* info;
    Lista* prox;
};

Lista* inicializada (void);
void insere(Lista**lst, char *nome, char *mat, char *turma, char *email);
void imprime(Lista* lst);
void libera(Lista* lst);
int compara (char* a, char* b);
void bolha (int n, Lista* lst0);

int main()
{
    Lista*lst = inicializada();
                /* Alunos da LISTA */
    insere(&lst,"Barbara","m1","1","ba@gmail.com");
    insere(&lst,"Joice"  ,"m2","5","jo@gmail.com");
    insere(&lst,"Geovana","m3","3","ge@gmail.com");
    insere(&lst,"Jessica","m4","4","je@gmail.com");
    insere(&lst,"Bruna"  ,"m5","2","bru@gmail.com");
    insere(&lst,"Thais"  ,"m6","7","tha@gmail.com");
    insere(&lst,"Murilo" ,"m7","6","mu@gmail.com");
    bolha(7,lst);
    imprime(lst);
    return 0;
}

Lista* inicializada (void)
{
    return NULL;
}

/*Insere elementos na lista*/
void insere(Lista**lst, char *nome, char *mat, char *turma, char *email)
{
    Aluno* a = (Aluno*)malloc(sizeof(Aluno));
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->info = a;
    strcpy(a->nome,nome);
    strcpy(a->mat, mat);
    a->turma = *turma;
    strcpy(a->email, email);
    novo->prox = *lst;
    *lst = novo;
}

/*Imprime os valores*/
void imprime(Lista* lst)
{
    Lista *p;
    for (p=lst; p!=NULL; p=p->prox)
    {
        printf("\nNome: %s\nMatricula: %s\nTurma: %c\nE-mail: %s\n",p->info->nome,p->info->mat,p->info->turma,p->info->email);
    }
    printf("--------------------------------------------------------------------------------\n");
}

/*Libera*/
void libera(Lista* lst)
{
    Lista* p = lst;
    while(p!=NULL)
    {
        Lista* t=p->prox;
        free(p);
        p=t;
    }
}

int compara (char* a, char* b)
{
    if (strcmp(a,b) > 0)
        return 1;
    else
        return 0;
}

/* Ordenação bolha */
void bolha (int n, Lista* lst)
{
    Aluno* A = NULL; // estrutura temporaria
    Lista* p = lst;
    int i;
    for (i=n-1; i>0; i--)
    {
        int troca = 0;
        for (p=lst; p->prox!=NULL; p=p->prox)
            if (compara(p->info->nome,p->prox->info->nome)) /* troca */
            {
                A = p->info;
                p->info = p->prox->info;
                p->prox->info = A;
                troca = 1;
            }
        if(troca == 0)
            return;
    }
}

