#include <stdio.h>
#include <conio.h>
int main() {
    int i, j, n, m, nummax2, nummin2;
    float b[30][30];
    printf("Vvedite n: ");
    scanf_s("%d", &n);
    printf("Vvedite m: ");
    scanf_s("%d", &m);
    float max, min;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            printf("Vvedite element [%d,%d]\n", i + 1, j + 1);
            scanf_s("%f", &b[i][j]);
        }

    for (i = 0; i < n; i++)
    {
        max = b[i][0]; min = b[i][0];
        nummax2 = 0; nummin2 = 0;
        for (j = 0; j < m; j++) {
            if (max < b[i][j]) {
                max = b[i][j];
                nummax2 = j;
            }
            if (min > b[i][j]) {
                min = b[i][j];
                nummin2 = j;
            }
        }
        printf("Max element %d-stroki matrici = %.f\n", i + 1, max);
        printf("Min element %d-stroki matrici = %.f\n", i + 1, min);
        float temp = b[i][nummax2];
        b[i][nummax2] = b[i][nummin2];
        b[i][nummin2] = temp;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%.f ", b[i][j]);
        printf("\n");

    }
    float s = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if(i = j)
                s += b[i][j];
        }
    printf("Summa elementov glavnoi diagonali: %.f ", s);
return 0;
}