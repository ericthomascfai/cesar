#include <stdio.h>
#include <string.h>
#include <ctype.h>

char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int decalage;
char direction;
char chainesaisie[255];
char chainecrypted[255];
char chaineuncrypted[255];

char* cryptuncryptchar(char* ,int*, char ); //crypt ou decrypte un caractère avec un décalage donné
char* saisirchaine(); //saisie la chaine a crypter
int* saisirdecalage(); //saisie du décalage
char* crypt_withcesar(char[],int *); //crypte chaine saisie en fonction d'un décalage et une direction
char* uncrypt_withcesar(char[],int *); //decrype chaine saisie en fonction d'un décalage et une direction
void afficherchaine(char []); //affiche une chaine de caractère

char* cryptuncryptchar(char *caract,int *decalage,char type)
{
    for(int i=0;i<26;i++) // boucle de 0 à 25
    {
        if(*caract==alphabet[i])// on verifie que le caractere est bien dans le tableau
        {
                if(type=='c') {  //si on crypte
                    if (i + *decalage > 25) { //si on sort du tableau côté droit

                        return &alphabet[i- 25 + *decalage - 1]; // je reviens au début
                    }
                    else
                        return &alphabet[i + *decalage]; //  décalage classique positif
                }
                else
                {
                    if (i - *decalage <0) //dépassement du tableau vers la gauche
                        return &alphabet[i+ 25 - *decalage+1]; // je reviens à  la fin
                    else
                        return &alphabet[i- *decalage]; //déclage classique négatif
                }

        }
    }

}
char *saisirchaine() {

    printf("Veuillez saisir une chaine");
    scanf(" %[^\n]s",&chainesaisie);
    return &chainesaisie;
}

int *saisirdecalage() {
    printf("Veuillez saisir le décalage");
    scanf("%d",&decalage);
    return &decalage;
}

char *saisirdirection() {
    printf("Veuillez saisir la direction");
    scanf(" %c",&direction);
    return &direction;
}

char* crypt_withcesar(char chaine[], int *decalage) {



        for(int i=0;i<strlen(chaine);i++) //boucle de 0 à longueur de la chaine
        {
            if(chaine[i]!=' ') {  //si blanc dans la chaine

                chainecrypted[i] = *cryptuncryptchar(&chaine[i],decalage,'c');
            }
            else
                chainecrypted[i]=chaine[i]; //on ne crypte pas les blancs

        }

    return chainecrypted;  //retourne le tableau complet
}

char *uncrypt_withcesar(char chaine[], int *decalage) {



    for(int i=0;i<strlen(chaine);i++)
    {
        if(chaine[i]!=' ') {

            chaineuncrypted[i] = *cryptuncryptchar(&chaine[i],decalage,'u');
        }
        else
            chaineuncrypted[i]=chaine[i];

    }


    return chaineuncrypted;
}

void afficherchaine(char chaine[]) {

    printf("%s\n",chaine);

}


int main() {

    afficherchaine(crypt_withcesar(saisirchaine(),saisirdecalage()));
    afficherchaine(uncrypt_withcesar(saisirchaine(),saisirdecalage()));

    return 0;
}