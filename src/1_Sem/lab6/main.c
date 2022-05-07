#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void task1();
void task2();
void task3();

int main()
{
    int a;
    while (a)
    {
        printf("Option 4\n");
        printf("1. Replace the order of characters in the entered string with the reverse.\n");
        printf("2. Print the position numbers of the beginning of the entered substring in the entered line.\n");
        printf("3. Delete the same words of the sentence running in a row.\n");
        int key;
        printf("Select an item from the menu: ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        }
        printf("You want continue ?\nIf no, enter 0.\n");
        printf("Your choose:");
        scanf("%d", &a);
    }

    return 0;
}

void task1()
{
    char str[255];
    printf("Enter string:");
    scanf("%s", &str);
    printf("%s\n", strrev(str));
}

void task2()
{
    const char *str1 = "Visual studio powerful IDE for students";
    const char *str2 = " and CodeBlocks ";
    char str3[255];
    int x;
    printf("enter x:");
    scanf("%d", &x);
    strncpy(str3, str1, x);
    str3[x] = '\0';
    strcat(str3, str2);
    strcat(str3, str1 + x);
    printf("%s\n", str3);
    printf("Substring position number = %d\n", x);
}
void task3()
{
    char s[] = "1 1 1 2 2 2 3 3 3 4 4 4 5 5 5";
    char s1[256] = {'\0'};
    char *buf = NULL;
    char *cur = strtok(s, " ");
    while (cur != 0)
    {
        if (buf ? strcmp(cur, buf) : 1)
        {
            strcat(s1, cur);
            strcat(s1, " ");
            buf = cur;
        }
        cur = strtok(NULL, " ");
    }
    printf("%s\n", s1);
}