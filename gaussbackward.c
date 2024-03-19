#include <stdio.h>

// Function to calculate the coefficient of Y
float gf(float p, int n) {
    float temp = p;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1)
            temp *= (p + i / 2.0);
        else
            temp *= (p - i / 2.0);
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
    int n = 2;

    // Storing available data
    float x[] = {4,5};
    float y[2][2];

    y[0][0] = 270;
    y[1][0] = 648;
    //y[2][0] = 20;
    //y[3][0] = 27;
    //y[4][0] = 39;
    //y[5][0] = 52;

    // Generating Gauss's triangle
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]);
        }
    }

    // Value of Y to predict
    float value = 5.8;
    float sum = y[n - 1][0];
    float p = (value - x[n - 1]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++) {
        sum = sum + (gf(p, i) * y[(n - 1) - i][i]) / fact(i);
    }

    printf("\nValue at %f is %f\n", value, sum);

    return 0;
}
