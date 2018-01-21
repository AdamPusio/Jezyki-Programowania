#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Point {
  int x;
  int y;
}point_1 = {2,2},
ll = {INT_MAX, INT_MAX}, //lower left point dla prostokąta 1
ur = {INT_MIN, INT_MIN}, //upper right point dla prostokąta 1
rectangle[4],
rectangle_2[4];

int main() {
  /*Jakieś tam punkty*/
  rectangle[0].x = 1;
  rectangle[0].y = 1;
  rectangle[1].x = 1;
  rectangle[1].y = 4;
  rectangle[2].x = 4;
  rectangle[2].y = 4;
  rectangle[3].x = 4;
  rectangle[3].y = 1;

  rectangle_2[0].x = 2;
  rectangle_2[0].y = 2;
  rectangle_2[1].x = 1;
  rectangle_2[1].y = 4;
  rectangle_2[2].x = 5;
  rectangle_2[2].y = 5;
  rectangle_2[3].x = 4;
  rectangle_2[3].y = 1;

  /*Znajdź najniższy lewy punkt i najwyższy prawy punkt dla prostokąta 1*/
  for (int i = 0; i < 4; i++) {
    if (rectangle[i].x>ur.x)
      ur.x = rectangle[i].x;
    if (rectangle[i].y>ur.y)
      ur.y = rectangle[i].y;
    if (rectangle[i].x<ll.x)
      ll.x = rectangle[i].x;
    if (rectangle[i].y<ll.y)
      ll.y = rectangle[i].y;
    }
  /*Zobacz jakie współrzędne wybrało */
  printf("ll: (%d;%d)\n", ll.x, ll.y);
  printf("ur: (%d;%d)\n", ur.x, ur.y);


  /*Sprawdza 4 punkty dla ll i ur, jeżeli któryś z nich będzie w prostokącie_1 lub na jego obwodzie, to oznacza że na siebie nachodzą
  Jedyny warunek jaki nie jest sprawdzony, to gdy ten drugi prostokąt będzie "połykał" ten pierwszy, wtedy jego krawędzie zostaną na zewnątrz i warunek go ominie*/
  for (int i = 0; i < 4; i++) {
    if (rectangle_2[i].x>=ll.x && rectangle_2[i].x<=ur.x && rectangle_2[i].y>=ll.y && rectangle_2[i].y<=ur.y) {
      printf("Prostokąty nakładają się na siebie.\n");
      break;
    }
    else
      printf("Prostokąty są od siebie oddalone.\n");
  }
}
