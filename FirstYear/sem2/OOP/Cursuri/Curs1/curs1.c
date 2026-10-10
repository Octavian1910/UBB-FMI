
#include <stdio.h>
#include <string.h>
/*Vectori*/

/*


int main(){
    int a[5];
    a[0] = 1;
    a[1] = 2;
    printf("a [0] = %d \n" , a[0]);
    printf("a [1] = %d \n" , a[1]);
    printf("a [2] = %d \n" , a[2]); //uninitialized

    int b[] = {1,2,3,5,7};
    printf("b[0] = %d \n",b[0]);
    b[0] = 10;
    printf("b[0] = %d \n",b[0]);
    return 0;
}
*/

/*C String*/
/*-sunt reprezentate ca un vector de caractere char,ultimul caracter '\0'
marcheazas sf sirului
- C include un modul pt a manupula C stringuri : #include <string.h>

srtlen - lungimea sirului
srtcpy - copiaza caractere de la sursa in C stringul destinatie
OBS NU PUTEM FOLOSI =  PT A COPIA SI NICI VECTORI NORMALI INTRE EI

strcmp -   0 a == b
           0<  a < b
           0> a > b

strcat - concateneaza sursa cu destinatie

NICI O METODA NU ALOCA MEMORIE SAU VERIFICA DACA EXISTA
 SUFICIENT LOC PT OPERATIE




int main(){
    char name[100];
    strcpy(name,"Popescu");
    printf("name:%s  l = %d \n" , name ,strlen(name));

    char name2[100];
    strcpy(name2,name);
    printf("name:%s l = %d", name2,strlen(name2));

    return 0;
}
*/

/*Structuri(Record)
-e o colectie de elemente de tipuri diferite
-permite gruparea diferitelor tipuri de date simple intr o strucutra

ex:

strct name{
typ1 field1;
type2 field2;
}

struct car{
int year;
int nrKm;
}

car c;
c.year = 2010
c.nrKm - 30000




typedef struct{
    int year;
    int km;
}Car;

int main(){
    Car car,car2;

    car.year = 2001;
    car.km = 20000;

    printf("Car 1 fabricated : %d Km : %d \n",car.year,car.km);

    //sunt initializate pt car2 !!!
    printf("Car 2 fabricated : %d Km : %d",car2.year,car2.km);
}
    */

/*POINTERI
-pointer este un tip de date special , folosit pt a lucra cu adrese de memorie
-poate stoca adresa unei variabile , adresa unei locatii de memorie

Declarare:

int *a,long *a etc

OPERATORI
-addres of & - returneaza adresa de memorie unde este sotcata valoarea
dintr o variabila

-dereferencing '*' - returneasza valoarea stocata in locatia de memorie specificata
*/

int main()
{
    int a = 7;
    int *pa;

    printf("Value of a: %d address of a: %p \n",a,&a);
    pa = &a;
    a = 10;
    printf("Value of pa: %d addres of pa : %p \n",*pa,pa);
    return 0;

}