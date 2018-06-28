/* Eric Paulz
 * epaulz
 * CPSC 1021-004
 * Lab #4
 * TA: Nick Glyder
 */

#include "functions.h"

// function implementation
int checkPoint(point_t *p, point_t *test){
  double a, b, c;

  a = ((p[1].y-p[2].y)*(test->x-p[2].x)+(p[2].x-p[1].x)*(test->y-p[2].y))
  		/ ((p[1].y-p[2].y)*(p[0].x-p[2].x)+(p[2].x-p[1].x)*(p[0].y-p[2].y));

  b = ((p[2].y-p[0].y)*(test->x-p[2].x)+(p[0].x-p[2].x)*(test->y-p[2].y))
  		/ ((p[1].y-p[2].y)*(p[0].x-p[2].x)+(p[2].x-p[1].x)*(p[0].y-p[2].y));

  c = 1 - a - b;

  if((a >= 0 && a <= 1) && (b >= 0 && b <= 1) && (c >= 0 && c <= 1)){
    return 1;
  }
  else{
    return 0;
  }
}
