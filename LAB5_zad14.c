#include <stdio.h>
#include <stdlib.h>

int main() {
  int n,m;
  printf("Podaj dwie liczby do tablicy\n");
  scanf("%d", &n); //wczytuje rozmiar n
  scanf("%d", &m); //wczytuje rozmiar m
  int macierz [4][4]; //stała tablica dwuwymiarowa

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      macierz [i][j] = i; //przykładowa zawartość tablicy
      macierz [0][0] = n; // wczytuje te liczby do tabeli ?
      macierz [0][1] = m;
      printf("%d ", macierz[i][j]); //wypisuje zawartość podobnie jak w przykładzie
    }
    printf("\n");
  }

  //kolejność odwrócona:

  printf("Kolejność odwrócona:\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <  4; j++) {
      printf("%d ", macierz[j][i]); //wypisuje odwróconą zawartość podobnie jak w przykładzie
    }
    printf("\n");
  }
}
