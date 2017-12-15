#include <stdio.h>
#include <stdlib.h>

int **create_table(int n, int m);
void get_table(int **table, int a, int b);
void print_table(int **table, int a, int b);
void free_table(int **table, int n, int m);

int main(void){
  int n, m;
  printf("Podaj dwie liczby do stworzenia tablicy[n][m]\n" );
  scanf("%d %d", &n, &m);
  int **table = create_table(n, m); //tworzona tablica dynamiczna z pomocą funkcji
  get_table(table, n, m); //pobierze tablice i da jej pewne wartości
  print_table(table, n, m); //wypisze tablice
  free_table(table, n, m); //zwolni pamięć z tablicy

  return EXIT_SUCCESS;
}

int **create_table(int n, int m){ //stwórz tablicę
  int **mytab;
  mytab = (int**)malloc(n * sizeof(int*));
  if (mytab == NULL){
    perror("Error in malloc");
    exit (1);
  }
  for (int i=0; i<n; i++){
    mytab[i] = (int*)malloc(m * sizeof(int));
    if(mytab[i] == NULL){
      perror("Error in malloc2");
      exit (1);
    }
  }
  return mytab;

}
void get_table(int **table, int a, int b){ //weź tablicę i daj jakieś wartości
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      table[i][j] = i+j; //przykładowe liczby
    }
  }
}
void print_table(int **table, int a, int b){ //wypisz pobraną tablicę
  printf("Macierz[%d][%d]:\n", a, b);
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}
void free_table(int **table, int n, int m){ //zwalnia pamięć z tablicy
  for (int i=0; i<n; i++){
      free(table[i]);
  }
  free(table);
  putchar('\n');

}
