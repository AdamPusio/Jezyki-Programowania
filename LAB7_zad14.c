#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int podzbiory(int num, int size_tab, int *table, int *table_out);

int main(void){
  int *tab1; //tablica jednowymiarowa
  int *tab2; //druga tablica
  unsigned int size;
  printf("Podaj wyraz n-ty, do wyznaczenia podzbiorów {1,2,...,n}\n");
  scanf("%d", &size);
  int number = pow(2, size); //ilość wywołań rekurencji, gcc plik.c -lm

  tab1 = (int*)malloc(size * sizeof(*tab1));
  tab2 = (int*)malloc(size * sizeof(*tab2));

  if (tab1 == NULL || tab2 == NULL) {
   perror("Error in malloc");
   exit (1);
  }
/*Wypełnienie jednej tablicy zbiorem liczb <1;n>, drugiej zerami*/
  for (int i = 0; i <size; i++) {
    tab1[i] = i+1;
    tab2[i] = 0;
  }
/*Użycie funkcji rekurencyjnej*/
  printf("Twoje podzbiory: \n");
  printf("{pusty zbiór} \n");
  podzbiory(number, size, tab1, tab2);
/*Czyszczenie tablic*/
  free(tab1);
  free(tab2);
  return EXIT_SUCCESS;
}

int podzbiory(int num, int size_tab, int *table, int *table_out){
  int max = INT_MIN;
/*Szukaj jak największej liczby w tablicy*/
if (num > 1) {
  for (int i = 0; i <size_tab; i++) {
    if (table[i]>=max) {
      max = table[i];
    }
  }
  table[max-1]=0; /*Znajdź i wyzeruj*/
  table_out[max-1] = max; /*Przerzuć max. liczbę do drugiej tablicy*/

/*Jeżeli posiadasz w drugiej tablicy liczby większe od wziętej, to je oddaj do pierwszej tablicy*/
  for (int i = 0; i < size_tab; i++) {
    if (table_out[max-1]<table_out[i]) {
      table[i] = table_out[i];
      table_out[i] = 0;
    }
  }
/*Wypisz podzbiory*/
  printf("{ ");
  for (int i = 0; i < size_tab; i++) {
    if (table_out[i] != 0) { //oczywiście bez wyrazów wyzerowanych
      printf("%d ", table_out[i]);
      }
  }
  printf("}");
  printf("\n");

  return podzbiory(num - 1, size_tab, table, table_out); //zastosowana rekurencja
 }
}
