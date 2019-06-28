#include <stdio.h>
#include <stdlib.h>

typedef struct svreme
{
    int h,m;
}vreme;

typedef struct scvor
{
    vreme t;
    struct scvor *next;
}cvor;

void dodaj_prvi(cvor **head, vreme inf)
{
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->next = *head;
    novi->t = inf;
    *head = novi;
}

void dodaj_poslednji(cvor **head,cvor **last, vreme inf)
{
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->next = NULL;
    novi->t = inf;
    
    if(*head == NULL)
    {
        *head = novi;
        *last = novi;
    }
    else
    {
        (*last)->next = novi;
        *last = novi;
    }
}
void brisi(cvor *head)
{
    while(head != NULL)
    {
        cvor *t = head;
        head = head->next;
        free(t);
    }
}

void pisi(cvor *head)
{
    while(head != NULL)
    {
        printf("%.2d:%.2d\n",head->t.h,head->t.m);
        head = head->next;
    }
}

void ucitaj_liste(FILE *in,cvor **polasci, cvor **odlasci)
{
    char c;
    vreme v;

    cvor *polasci_last = NULL;
    while((c = fgetc(in)) != '\n')
    {
        v.h = (c - '0') * 10;
        c = fgetc(in);
        v.h += (c - '0');
        
        c = fgetc(in); //proguta :

        c = fgetc(in);
        v.m = (c - '0') * 10;
        c = fgetc(in);
        v.m += (c - '0');

        
        dodaj_poslednji(polasci,&polasci_last,v);

        if((c = fgetc(in)) == '\n')
            break;
    }
    while((c = fgetc(in)) != EOF)
    {
        v.h = (c - '0') * 10;
        c = fgetc(in);
        v.h += (c - '0');
        
        c = fgetc(in); //proguta :

        c = fgetc(in);
        v.m = (c - '0') * 10;
        c = fgetc(in);
        v.m += (c - '0');

        
        dodaj_prvi(odlasci,v);

        if((c = fgetc(in)) == EOF)
            break;
    }
}

int cmp_vreme(vreme t1, vreme t2)
{
    if(t1.h < t2.h)
        return 1;

    if(t1.h > t2.h)
        return 0;
    
    return t1.m < t2.m;
}

void obradi(cvor **polasci, cvor **odlasci, vreme pocetak, vreme kraj)
{
    cvor *t = *polasci;
    cvor *last = NULL;

    while(t != NULL)
    {
        if(cmp_vreme(pocetak,t->t))
        {
            brisi(t);
            if(last == NULL)
            {
                *polasci = NULL;
            }
            else
            {
                last->next = NULL;
            }
            break;
        }
        last = t;
        t = t->next;
    }

    t = *odlasci;
    last = NULL;
    while(t != NULL)
    {
        if(cmp_vreme(t->t,kraj))
        {
            brisi(t);
            if(last == NULL)
            {
                *odlasci = NULL;
            }
            else
            {
                last->next = NULL;
            }
            break;
        }
        last = t;
        t = t->next;
    }
}

void pisi_u_fajl(FILE *out,cvor *polasci, cvor *odlasci)
{
    while(polasci != NULL)
    {
        cvor *t = odlasci;
        while(t != NULL)
        {
            fprintf(out,"%d:%d %d:%d\n",polasci->t.h,polasci->t.m,t->t.h,t->t.m);
            t = t ->next;
        }
        polasci = polasci->next;
    }
}

int main()
{
    FILE *ulaz = fopen("redvoznje.txt","r");
    FILE *izlaz = fopen("prevoz.txt","w");
    cvor *polasci = NULL, *odlasci = NULL;
    vreme pocetak, kraj;

    if(ulaz == NULL)
    {
        fprintf(stderr,"Greska pri uctivanju fajla redvoznje.txt.\n");
        exit(1);
    }
   
    scanf("%d:%d",&pocetak.h,&pocetak.m);
    scanf("%d:%d",&kraj.h,&kraj.m);

    ucitaj_liste(ulaz,&polasci,&odlasci);
    obradi(&polasci,&odlasci,pocetak,kraj);
    pisi_u_fajl(izlaz,polasci,odlasci);

    brisi(polasci);
    brisi(odlasci);

    fclose(ulaz);
}