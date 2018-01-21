#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct osobaLepsza {
char imie[20]; //pozwoliłem sobie dodać 2 pozycje w strukturze
char nazwisko[20];
int wiek;
int pensja;
}osobaLepsza;

int main() {
  //struct osobaLepsza *osobaLepsza; //tablica na 5 pracowników
  int size = 0;
  char str1[10];
  char str2[10];
  char str3[10];
  FILE *plik;
  plik = fopen("tekstoweDane.txt","r");
  if(plik == NULL){
    perror("Blad otwarcia pliku!");
  }
  else{
    fscanf(plik, "%d", &size); //pobiera czwórkę z pliku
    /*malloc*/
    struct osobaLepsza *osobaLepsza = malloc(size * sizeof(*osobaLepsza));
    /*warunek*/
    if (osobaLepsza == NULL) {
      perror("Error in malloc");
      exit (1);
    }
    /*nadaj wartości strukturze*/
    for (int i = 0; i < size; i++) {
      fscanf(plik, "%s %s %d %d", osobaLepsza[i].imie, osobaLepsza[i].nazwisko, &osobaLepsza[i].wiek, &osobaLepsza[i].pensja);
      printf("%s %s %d %d\n", osobaLepsza[i].imie, osobaLepsza[i].nazwisko, osobaLepsza[i].wiek, osobaLepsza[i].pensja);
    }
    /*porównaj pensje i wiek pracowników*/
    int youngest_age = INT_MAX;
    int biggest_salary = INT_MIN;
    int a;
    int b;
    for (int i = 0; i < size; i++) {
      if (osobaLepsza[i].wiek<youngest_age){
        youngest_age = osobaLepsza[i].wiek;
        a = i;
      }
      if (osobaLepsza[i].pensja>biggest_salary){
        biggest_salary = osobaLepsza[i].pensja;
        b = i;
      }
    }
    printf("Najlepiej zarabiajaca osoba to: %s %s z pensją %d\n", osobaLepsza[b].imie, osobaLepsza[b].nazwisko, osobaLepsza[b].pensja );
    printf("Najmłodsza osoba to: %s %s z wiekiem %d\n", osobaLepsza[a].imie, osobaLepsza[a].nazwisko, osobaLepsza[a].wiek);
    fclose(plik);
  }
}
