#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int find_max(int tab[], int size);

int main(void){
  int table [] = {2, 4, 7, -3, 24, 3, 2, 1, 19, -12}; // przykładowa tablica 10-cio elementowa
  int size_table = sizeof(table)/sizeof(table[0]);
  printf("Rozmiar tablicy: %d\n", size_table);
  /*Wywołaniee funkcji*/
  printf("Maksymalna z tablicy: %d\n", find_max(table, size_table));
}

int find_max(int tab[], int size){
  static int max = INT_MIN;
  static int i = 0;
  if (i < size) {
    if (tab[i]>max) {
      max = tab[i];
    }
    i++;
    return find_max(tab, size-1);
  }
  else if (i == size) {
    return max;
  }
}
