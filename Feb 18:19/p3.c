#include <stdio.h>
#include <stdlib.h>
typedef struct elem { int broj;struct elem *sled; } Elem;
Elem* obradi(Elem* lst, int k);

Elem* citaj()
{
    Elem *prvi = NULL;
    for(int i = 0; i < 6; i++)
    {
        Elem* novi = (Elem*)malloc(sizeof(Elem));
        novi->sled = prvi;
        scanf("%d",&novi->broj);
        prvi = novi;
    }
    return prvi;
}

void brisi(Elem *t)
{
    while(t)
    {
        Elem* p = t;
        t = t->sled;
        free(p);
    }
}

int main () {
    Elem *lst, *tek;lst = citaj();
    tek= obradi(lst, 2);
    printf("%d", tek->broj);
    brisi(lst); 
    return 0;
}
Elem* obradi(Elem* lst, int k) 
{
    Elem *tek1 = lst, *tek2 = lst;
    while (tek1) {
        if (!k) tek2 = tek2->sled;
        else k--;
        tek1 = tek1->sled;
    }
    return k ? tek1 : tek2;
}