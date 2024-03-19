#include <stdio.h>

// Function to calculate the coefficient of Y
float gf(float p, int n) {
    float temp = p;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1)
            temp *= (p - i);
        else
            temp *= (p + i);
    }
    return temp;
}

// Function to calculate factorial
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int n = 6;

    // Storing available data
    float x[] = {2.5,3.0,3.5,4.0,4.5,5.0};
    float y[6][6];

    y[0][0] = 24.145;
    y[1][0] = 22.043;
    y[2][0] = 20.225;
    y[3][0] = 18.644;
    y[4][0] = 17.262;
    y[5][0] = 16.047;

    // Generating Gauss's triangle
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]);
        }
    }
   

    // Value of Y to predict
    float value = 3.75;
    float sum = y[n / 2][0];
    float p = (value - x[n / 2]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++) {
        sum = sum + (gf(p, i) * y[(n - i) / 2][i]) / fact(i);
    }

    printf("\nValue at %f is %f\n", value, sum);

    return 0;
}
