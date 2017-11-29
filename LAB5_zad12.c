#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // do wykorzystania INT_MIN, INT_MAX

void min_max_table(int *tab, int len);
int substract(int *max, int *min);

int main() {
  int table[] = {5, 43, -15, 6, 0, 23, 3, 0}; //przykładowa tablica
  int length = sizeof(table)/sizeof(table[0]); //jej rozmiar
  min_max_table(table, length);

}

void min_max_table(int *tab, int len){
  int result = 0;
  int max = INT_MIN;
  int min = INT_MAX;
  for (int i = 0; i < len; i++) { //wyznaczenie min i max z tablicy
    if (tab[i] > max)
      max = tab[i];
    if (tab[i] < min)
      min = tab[i];
  }
  printf("Roznica: %d\n", substract(&max, &min)); //wywołanie różnicy
}

int substract(int *max, int *min){
  //*min_max_table(*table, *length);
  int result;
  result = *max - *min;
  return result;
}
