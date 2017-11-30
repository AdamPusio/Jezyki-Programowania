/*wercja z gcc -Wall -ascii*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n,m;
  printf("Podaj dwie liczby do tablicy\n");
  scanf("%d", &n);
  scanf("%d", &m);
  int macierz [4][4];
  int i = 0;
  int j = 0;

  while (i < 4) {
    while (j < 4) {
      macierz [i][j] = i;
      macierz [0][0] = n;
      macierz [0][1] = m;
      printf("%d ", macierz[i][j]);
      j++;
    }
    printf("\n");
    i++;
    j=0;
  }

  printf("Kolejność odwrócona:\n");
  i = 0;
  j = 0;
  while (i < 4) {
    while (j < 4) {
      printf("%d ", macierz[j][i]);
      j++;
    }
    printf("\n");
    i++;
    j=0;
  }
  return 0;
}
