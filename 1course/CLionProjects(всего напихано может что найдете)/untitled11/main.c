#include<stdio.h>
#include<stdbool.h>
int main() {
    int i, j, n;
    int b[30][30];
    printf("Vvedite n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            printf("Vvedite element [%d,%d]\n", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        bool stolb = true;
        for ( i = 0; i < n; i++)
            if (b[i][j] < 0) {
                stolb = false;
            }
        if (stolb == true) {
            for ( i = 0; i < n; i++)
                sum += b[i][j];
        }
        printf("Summa elementov %d-stolbtsa bez otrizatelnih elementov: %d \n", j, sum);
    }

    int sum, k = 0, min = 0;
    int abs (int sum);
    sum = b[n - 1][0];
    for (i = n; i > 0; i--)
    {
        for (j = 0; j < n - i + 1; j++)
            sum += abs(b[n - i - j][j]);
        k++;
        if (sum < min || min == 0)
        min = sum;
    }

    for (i = 1; i < n - 1; i++)
    {
        sum = 0;
        for (j = n - 1; j >= i; j--)
            sum += abs(b[n - 1 + i - j][j]);
        k++;
        if (sum < min || min == 0)
        min = sum;
    }
    printf("Minimum sredi sum modulei elementov diagonalei, paralelnih pobochnoi diagonali matrici: %d", min);
}