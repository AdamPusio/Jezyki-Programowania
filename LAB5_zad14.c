#include <stdio.h>
#include <stdlib.h>

int main() {
  int n,m;
  printf("Podaj rozmiar tablicy dwuwymiarowej: \n");
  printf("Kolumny: ");
  scanf("%d", &n); //wczytuje rozmiar n
  printf("Wiersze: ");
  scanf("%d", &m); //wczytuje rozmiar m

  int macierz [n][m]; //wczytuje rozmiar n, m do tabeli

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <  m; j++) {
      macierz [i][j] = i; //przykładowa zawartość tablicy
      printf("%d", macierz[i][j]); //wypisuje zawartość podobnie jak w przykładzie
    }
    printf("\n");
  }

  //kolejność odwrócona:

  printf("Kolejność odwrócona:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <  m; j++) {
      printf("%d", macierz[j][i]); //wypisuje odwróconą zawartość podobnie jak w przykładzie
    }
    printf("\n");
  }
}
