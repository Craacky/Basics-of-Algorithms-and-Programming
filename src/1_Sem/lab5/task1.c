#define ARR_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;
    int count = 0;
    int x[ARR_SIZE], y[ARR_SIZE];
    time_t t;
    srand((unsigned)time(&t));

    for (i = 0; i < ARR_SIZE; ++i)
    {
        y[i] = rand() % 10 + 1;
        printf("%d) [x][y] = [%d][%d]\n", i + 1, x[i], y[i]);
    }
    for (i = 0; i < ARR_SIZE; ++i)
    {
        for (int j = i + 1; j < ARR_SIZE; ++j)
        {
            if (x[i] == x[j] && y[i] == y[j])
            {
                x[i] = 0;
                y[i] = 0;
                count++;
            }
        }
    }
    for (i = 0; i < ARR_SIZE; ++i)
    {
        printf("%d) [x][y] = [%d][%d]\n", i + 1, x[i], y[i]);
    }
    printf("Count repeat = %d\n", count);
    const int new_size = ARR_SIZE - count;
    int ni = 0;
    int *const x1 = (int *)malloc(new_size * sizeof(int));
    int *const y1 = (int *)malloc(new_size * sizeof(int));
    for (i = 0; i < ARR_SIZE; ++i)
    {
        if (x[i] != 0 && y[i] != 0 && ni < new_size)
        {
            x1[ni] = x[i];
            y1[ni] = y[i];
            ++ni;
        }
    }
    for (i = 0; i < new_size; ++i)
    {
        printf("%d) [x1][y1] = [%d][%d]\n", i + 1, x1[i], y1[i]);
    }
    free(x1);
    free(y1);
    system("pause");
    return 0;
}