/*Zadanie 11(1 pkt)
Napisz funkcję textOnEnd(string,text), który będzie sprawdzał czy napis
string znajduje się na końcu tekstu. Przetestuj tę funkcję w programie.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //dla bool-a

bool textOnEnd(char *string, char *text);

int main() {
  char tekst[] = "Siemano kolano i kolowrotek";
  char wyraz[] = "kolowrotek";
  if (textOnEnd(wyraz, tekst))
    printf("Jest wyraz w tekście\n");
  else
    printf("Nie ma wyrazu\n");
}

bool textOnEnd(char *string, char *text){ 
  /*długość wyrazu string*/
  int len_str = 0;
  for (; string[len_str] != '\0'; len_str++);
  /*długość textu*/
  int len_text = 0;
  for (; text[len_text] != '\0'; len_text++);

  len_text -= 1;
  len_str -= 1;
  while (len_str >= 0) {
    if (string[len_str] != text[len_text])
      return false;
    len_str--;
    len_text--;
  }
  return true;
}
