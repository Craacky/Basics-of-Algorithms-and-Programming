// #include <stdio.h>

// int main()
// {
//     FILE *doc;
//     char checker;

//     if ((doc = fopen("sentence.txt", "r")) == NULL)
//     {
//         printf("File is empty today");
//         return 1;
//     }
//     else
//     {
//         printf("File open!\n");
//         while ((checker = fgetc(doc)) != EOF)
//         {
//             if (checker == '!' || checker == '?' || checker == '.' || checker == ',')
//             {
//                 printf("%c\n", checker);
//             }
//             else
//             {
//                 printf("%c", checker);
//             }
//         }
//         fclose(doc);
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define N 10

int main()
{
    // creating binary files and filling in
    FILE *firstDoc, *secondDoc, *thirdDoc;
    firstDoc = fopen("firstDoc.bin", "wb");
    secondDoc = fopen("secondDoc.bin", "wb");
    const int sz_int = sizeof(int);

    // making a random dependent on real time
    time_t t;
    srand((unsigned)time(&t));

    for (int i = 0; i < N; i++)
    {
        // filling in the firstDoc
        int rnd = rand() % 50 + 1;
        fwrite(&rnd, sz_int, 1, firstDoc);
        // filling in the secondDoc
        rnd = rand() % 50 + 1;
        fwrite(&rnd, sz_int, 1, secondDoc);
    }

    fclose(firstDoc);
    fclose(secondDoc);

    firstDoc = fopen("firstDoc.bin", "a+");
    secondDoc = fopen("secondDoc.bin", "rb");
    thirdDoc = fopen("thirdDoc.bin", "w+b");

    int element;
    // merge the secondDoc with the firstDoc
    while (fread(&element, sz_int, 1, secondDoc))
    {
        fwrite(&element, sz_int, 1, firstDoc);
    }

    rewind(firstDoc);
    // first search min
    int min = INT_MAX;
    while (fread(&element, sz_int, 1, firstDoc))
    {
        if (element < min)
        {
            min = element;
        }
    }

    // finally min check
    for (int i = 0; i < N * 2; i++)
    {
        rewind(firstDoc);
        int min_check = INT_MAX;
        while (fread(&element, sz_int, 1, firstDoc))
        {
            if (element == min)
            {
                fwrite(&element, sz_int, 1, thirdDoc);
            }
            if (element < min_check && element > min)
            {
                min_check = element;
            }
        }
        min = min_check;
    }
    rewind(thirdDoc);
    // result in dec
    while (fread(&element, sz_int, 1, thirdDoc))
    {
        printf("%d\t", element);
    }

    fclose(firstDoc);
    fclose(secondDoc);
    fclose(thirdDoc);
}
