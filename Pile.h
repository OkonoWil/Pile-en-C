#include<stdio.h>
#include <stdlib.h>
#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#define TAILLE 5

    //D�finition  du type structur� Pile
    typedef struct Pile{
        int element;
        struct Pile *next;
    }*Pile;

    //Signature des fonctions.
    int taille();
    int pleine();
    void empiler(int x);
    int vide();
    int depiler();
    void afficher();
    void menu();


#endif // PILE_H_INCLUDED
