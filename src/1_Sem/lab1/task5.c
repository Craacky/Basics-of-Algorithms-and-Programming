#include <stdio.h>
#include <stdlib.h>
#define ITEMS_COUNT 3

void error()
{
    printf("Error in input data. Please re-enter.\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main(void)
{
    int years[ITEMS_COUNT];
    char names[ITEMS_COUNT][100];
    float diameters[ITEMS_COUNT];
    int mHzs[ITEMS_COUNT];

    for (int i = 0; i < ITEMS_COUNT;)
    {
        printf("%d. Input Year, Scientific director, Antenna diameter, Working frequency\n", i + 1);
        const int r = scanf("%d %99s %f %d", &years[i], names[i], &diameters[i], &mHzs[i]);
        if (r != 4)
        {
            error();
            continue;
        }
        ++i;
    }
    printf("______________________________________________________________________________\n");
    printf("|                       Extraterrestrial Trace Projects                      |\n");
    printf("|____________________________________________________________________________|\n");
    printf("|Year |       Sepurvisor       |Antenna Diameter(M) |Working frequency(MHz)  |\n");
    printf("|____________________________________________________________________________|\n");
    for (int i = 0; i < ITEMS_COUNT; ++i)
    {
        printf("|%-5d|%-24s|%20.2f|%24d|\n", years[i], names[i], diameters[i], mHzs[i]);
    }
    printf("|____________________________________________________________________________|\n");
    printf("|Note: Objects from 2 stars to several galaxies were observed                |\n");
    printf("|____________________________________________________________________________|\n");
}