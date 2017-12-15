#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int min(int a, int b);
int max(int a, int b);

int main(void){
  int **mytab; //dwuwymiarowa tablica
  int n,m;
  printf("Podaj dwie liczby do macierzy[n][m]\n" );
  scanf("%d %d", &n, &m);

  mytab = (int**)malloc(n * sizeof(int*)); //rezerwuje pamięć dla kolumn
  if (mytab == NULL){ //jeżeli kolumny są puste (zarezerwowana pamięć równa zero)
    perror("Error in malloc");
    exit (1);
  }
  for (int i=0; i<n; i++){ //chodzi po kolejnych kolumnach
    mytab[i] = (int*)malloc(m * sizeof(int)); //rezerwuje pamięć dla kolejnych wierszy[n]
    if(mytab[i] == NULL){ //jeżeli wiersz[i] jest pusty (zarezerwowana pamięć równa zero)
      perror("Error in malloc2");
      exit (1);
    }
  }

  srand(time(NULL)); // ziarno ustawione na zero
  int minimum = min(n, m);
  int maximum = max(n, m);
  maximum = maximum+1-minimum; //tym działaniem reszta z modulo da oczekiwany zakres, zaraz po dodaniu minimum
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      mytab[i][j] = (rand() % maximum) + minimum; //losowa liczba z przedziału <minimum ; maximum>
    }
  }

  printf("Macierz[%d][%d]:\n", n, m); //wypisanie macierzy
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", mytab[i][j]);
    }
    printf("\n");
  }


  for (int i = 0; i<n; i++){ //chodzi po kolejnych kolumnach, zwalnia pamięć z kolejnych wierszy
      free(mytab[i]);
  }
  free(mytab); //zwalnia pamięć z pozostałości (z długości kolumny)
  putchar('\n');
  return EXIT_SUCCESS;
}

int min(int a, int b){ //funkcja zwracająca minimum
  if (a<b) return a;
  else return b;
}

int max(int a, int b){ //funkcja zwracająca maximum
  if (a<b) return b;
  else return a;
}
