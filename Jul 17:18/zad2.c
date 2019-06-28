#include <stdio.h>
#include <stdlib.h>
#define MAX_DUZ_LINIJE 20

typedef struct skand
{
    int sifra;
    double poeni;
}kandidat;

typedef struct scvor
{
    kandidat inf;
    struct scvor *next;
}cvor;

void dodaj_sort(cvor **first,kandidat k)
{
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->inf = k;

    if(*first == NULL)
    {
        *first = novi;
        novi->next = NULL;
        return;
    }
    cvor *t = *first;
    if(novi->inf.poeni > t->inf.poeni)
    {
        *first = novi;
        novi->next = t;
        return;
    }

    while(t->next != NULL && novi->inf.poeni < (t->next)->inf.poeni)
    {
        t = t->next;
    }
    novi->next = t->next;
    t->next = novi;
}

void brisi(cvor *first)
{
    cvor *t;
    while(first!= NULL)
    {
        t = first;
        first = first->next;
        free(t);
    }
}

void pisi(cvor *first)
{
    while(first != NULL)
    {
        printf("%d %.2lf\n",first->inf.sifra, first->inf.poeni);
        first = first->next;
    }
}

void citaj(FILE *in,FILE *ocene, cvor **first)
{
    kandidat k;
    double mat; double fiz;
    char s[MAX_DUZ_LINIJE];
    while(  fgets(s,MAX_DUZ_LINIJE,in) != NULL)
    {
        sscanf(s , "%d %lf %lf", &k.sifra,&mat,&fiz);
        if(mat > fiz)
        {
            k.poeni = mat;
        }
        else
        {
            k.poeni = fiz;
        }
        dodaj_sort(first,k);
    }
}

cvor *nadji_kandidata(cvor *first, int sifra)
{
    while(first != NULL)
    {
        if(first->inf.sifra == sifra)
        {
            return first;
        }
        first = first->next;
    }
    return NULL;
}


void dodaj_poene_ocena(FILE *ocene,cvor *first)
{
    double oc1,oc2,oc3,oc4;
    int sifra;
    char s[MAX_DUZ_LINIJE];
    while(  fgets(s,MAX_DUZ_LINIJE,ocene) != NULL)
    {
        sscanf(s , "%d%lf%lf%lf%lf", &sifra,&oc1,&oc2,&oc3,&oc4);
        
        cvor *kandidat = nadji_kandidata(first, sifra);
        if(kandidat != NULL)
        {
            kandidat->inf.poeni += 2 * (oc1 + oc2 + oc3 + oc4);
        }
    }
}

int main()
{
    cvor *head = NULL;
    FILE *ulaz = fopen("prijemni.txt","r");
    FILE *ocene = fopen("ocene.txt","r");
    if(ulaz == NULL)
    {
        fprintf(stderr,"Freska pri ucitavanju fajla.\n");
        exit(1);
    }
    citaj(ulaz, &head);
    dodaj_poene_ocena(ocene, head);

    pisi(head);
    brisi(head);
}