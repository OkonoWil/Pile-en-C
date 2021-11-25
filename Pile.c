#include "Pile.h"
#include <stdio.h>
#include <stdlib.h>

Pile P;

//Fonction taille() qui retourne le nombre d'élément dans la pile
int taille(){
    Pile L=P;
    int s = 0; //Compteur
    while(L!=NULL){
        //Tantque la pile pointe vers un élément on incrémente le compteur
        s++;
        L=L->next;
    }
    return s;
}

//Fonction pleine()
int pleine(){
    int bool = 0;//la pile nest pas pleine
    if(TAILLE==taille(P))
        bool = 1;//la boule est pleine
    return bool;
}

//Fonction empiler()
void empiler(int x){
    if(!pleine(P)){
        //la pile n'est pas pleine
        Pile new =malloc(sizeof(Pile));
        new->element=x;
        new->next=P;
        P=new;
        }
    else
    //On ne peut plus empiler
        printf("Erreur : la pile est deja pleine\n");
}

//Fonction Vide()
int vide(){
        int bool = 0;//n'est pas vide
        if(P==NULL)
            bool = 1;//est vide
        return bool;
}

//Fonction depiler()
int depiler(){
        int result;
        //Si la pile n'est pas vide on dépile
        if(!vide(P)){
            Pile L=P; //Sauvegade de la tête de pile
            P=P->next;
            L->next=NULL;
            result=L->element;
            free(L);
        }
        else{//depiler retourne zero si la pile est vide
            printf("Erreur : La pile est deja vide \n");
            //exit(EXIT_FAILURE);
        }
        return result;
}

//Fonction d'affichage()
void afficher(){
        Pile L = P; //Sauvegade de la tête de pile
        while(L!=NULL){
            printf("[%d]\n", L->element);
            L=L->next;
        }
}

//Menu à 5 option 
void menu(){
   int choix, elt, choix2;

   /*Le menu doit être afficher au moins une fois et 
    se repéte tant que l'utilisateur ne décide pas de sortir de la boucle*/
  do{
        //Liste des options
        printf("\n\nMENU\n");
        printf("1.Empiler\n");
        printf("2.Depiler\n");
        printf("3.Est Pleine\n");
        printf("4.Est Vide\n");
        printf("5.Affiche\n");
        printf("entrer votre choix : ");
        //Récupération du choix de l'utilisateur
        scanf("%d",&choix);
        //Exécution d'un bout de code en fonction du choix
        switch(choix){
            case 1:
                printf("quel element voulez vous empiler ");
                scanf("%d",&elt);
                empiler(elt);
                break;
            case 2:
                elt=depiler(P);
                printf("l element depiler est [%d]\n", elt);
                break;
            case 3:
                if(pleine(P))
                    printf("la pile est pleine\n");
                else
                    printf("le pile nest pas pleine\n");
                break;
            case 4:
                if(vide(P))
                    printf("la pile est vide\n");
                else
                    printf("la pile n est pas vide\n");
                break;
            case 5:
                afficher(P);
                break;
            default:
                printf("le choix est incorrect\n");
        }
        //On démande à l'utisateur s'il veut sortir du menu
        printf("voulez vous continuer (1-oui,0-non)");
        scanf("%d",&choix2);

    } while(choix2==1);//L'utilisateur doit saisir un nombre != 1pour quitter
}
