#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  printf("Podaj tekst: \n");
  char zdanie[10]; //zdanie do 10 znaków
  char ASCII[128]; //przechowuje podstawowe znaki ASCII 


//wypełnia tablicę ASCII
  for (int i = 0; i < 128; i++) {
    ASCII[i] = i;
  }

//tablica ze zdaniem podanyn
  for (int i = 0; i<10; i++) {
      scanf("%c", &zdanie[i]);
    }

printf("Oto twój histogram: \n");
printf("--------------------\n");

//wypisanie znaków
int ilosc = 0;

  for (int a = 0; a < 128; a++) {
    for (int b = 0; b < 10; b++) {
      if (zdanie[b]==ASCII[a])
      ilosc++;
    }
    if (ilosc>0){
      printf("Znak: '%c', ilość: %d, gwiazdki: ", ASCII[a], ilosc);
      for (int  c = 0; c < ilosc; c++) {
        putchar('*');
      }
      puts("\n");
    }
    ilosc = 0;
  }
  return 0;
}
