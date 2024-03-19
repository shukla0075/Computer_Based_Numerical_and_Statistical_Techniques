#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x, float y) {
  return x * y;
}

float rk4(float x0, float y0, float xn, float h) {
  float k1, k2, k3, k4, y;

  for (; x0 < xn; x0 += h) {
    k1 = h * f(x0, y0);
    k2 = h * f(x0 + h / 2.0, y0 + k1 / 2.0);
    k3 = h * f(x0 + h / 2.0, y0 + k2 / 2.0);
    k4 = h * f(x0 + h, y0 + k3);

    y = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

    printf("%f\t%f\n", x0, y);
    y0 = y;
  }

  return y;
}

int main() {
  float x0 = 1, y0 = 2, xn = 1.4, h = 0.2;


  rk4(x0, y0, xn, h);

  return 0;
}
