#define columns 16
#define rows 16
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int arr[rows][columns];
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = rand() % 10 + 1;
            printf("%-3d", arr[i][j]);
        }
        printf("\n");
    }
    printf("sorted\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            for (int k = 0; k < columns - j - 1; k++)
            {
                const int left = arr[i][k];
                const int right = arr[i][k + 1];
                if (left > right)
                {
                    arr[i][k] = right;
                    arr[i][k + 1] = left;
                }
            }
        }
        for (int j = 0; j < columns; j++)
        {
            printf("%-3d", arr[i][j]);
        }
        printf("\n");
    }
    printf("packed\n");
    int b[rows];
    for (int i = 0; i < rows; i++)
    {
        int k = 0;
        for (int j = 1; j < columns; j++)
        {
            const int left = arr[i][j - k - 1];
            const int right = arr[i][j];

            if (left == right)
            {
                ++k;
            }
            else
            {
                arr[i][j - k] = right;
            }
        }
        b[i] = columns - k;
        for (int j = 0; j < b[i]; j++)
        {
            printf("%-3d", arr[i][j]);
        }
        printf("\n");
    }
    int max_mnozhestvo_index = -1;
    int max_mnozhestvo = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            const int m1 = b[i];
            const int m2 = b[j];
            if (m1 > max_mnozhestvo)
            {
                max_mnozhestvo = m1;
                max_mnozhestvo_index = i;
            }
            if (m2 > max_mnozhestvo)
            {
                max_mnozhestvo = m2;
                max_mnozhestvo_index = j;
            }
            break;
        }
    }
    printf("max mnozhestvo final %d\n", max_mnozhestvo);
    if (max_mnozhestvo_index >= 0)
    {
        printf("max mnozhestvo values: ");
        for (int j = 0; j < b[max_mnozhestvo_index]; j++)
        {
            printf("%-3d", arr[max_mnozhestvo_index][j]);
        }
        printf("\n");
    }
    return 0;
}