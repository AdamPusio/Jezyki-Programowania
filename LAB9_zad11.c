#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Point {
  int x;
  int y;
}point_1 = {2,2},
ll = {INT_MAX, INT_MAX}, //lower left point
ur = {INT_MIN, INT_MIN},
rectangle[4]; //upper right point


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

  /*Znajdź najniższy lewy punkt i najwyższy prawy punkt*/
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

    if (point_1.x>=ll.x && point_1.x<=ur.x && point_1.y>=ll.y && point_1.y<=ur.y)
      printf("Punkt jest w kwadracie!\n");
    else
      printf("Punkt jest poza kwadratem\n");

}
