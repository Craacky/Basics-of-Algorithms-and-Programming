#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospital
{
    char hospital_department[255];
    double total_salary;
    int number_of_staff;
} medecine;

void enter_department(medecine **str, int *size)
{
    printf("Enter hospital department: ");
    scanf("%s", (*str)[*size].hospital_department);
}
void enter_salary(medecine **str, int *size)
{
    printf("Enter total salary: ");
    scanf("%lf", &(*str)[*size].total_salary);
}
void enter_staff(medecine **str, int *size)
{
    printf("Enter number of staff: ");
    scanf("%d", &(*str)[*size].number_of_staff);
}
void task1(medecine **str, int *size, int *volume)
{
    enter_department(str, size);
    enter_salary(str, size);
    enter_staff(str, size);
    (*size)++;

    if (*size >= *volume)
    {
        *volume *= 2;

        *str = (medecine *)realloc(*str, *volume * sizeof(medecine));
    }
}
void task2(medecine *str, int *size, int index)
{
    for (int i = index; i < *size; i++)
    {
        str[i] = str[i + 1];
    }
    *size -= 1;
}
void task3(medecine *str, int size)
{
    printf("---------------------------------------------\n");
    printf("|      department     |    salary   | staff |\n");
    printf("---------------------------------------------\n");

    if (size == 0)
        printf("|            No goods was added...          |\n");

    for (int i = 0; i < size; i++)
        printf("| %19s | %11.2lf | %5d |\n", str[i].hospital_department, str[i].total_salary, str[i].number_of_staff);

    printf("---------------------------------------------\n");
}
void task4(medecine **str, int *tracker)
{
    int key = 0;
    do
    {
        printf("Select item of struct for edit:\n");
        printf("0.Hospital depatment\n");
        printf("1.Total salary\n");
        printf("2.Number of staff\n");
        printf("3.EXIT\n");
        printf("Enter your option: ");
        scanf("%d", &key);
        switch (key)
        {
        case 0:
            enter_department(str, tracker);
            break;
        case 1:
            enter_salary(str, tracker);

            break;
        case 2:
            enter_staff(str, tracker);
            break;
        }
    } while (key != 3);
}

int main()
{
    int task = 0;
    int size = 0;
    int volume = 1;
    int index = 0;
    int tracker = 0;
    medecine *str = (medecine *)malloc(volume * sizeof(medecine));
    do
    {
        printf("Option 12\n");
        printf("1. Add an entry\n");
        printf("2. Delete an entry\n");
        printf("3. Output of all records\n");
        printf("4. Edit an entry\n");
        printf("5. Exit\n");
        printf(">");
        if (scanf("%d", &task) != 1)
        {
            scanf("%*s");
            continue;
        }
        switch (task)
        {
        case 1:
            task1(&str, &size, &volume);
            break;
        case 2:
            printf("Enter index for delete, max index = %d and min index = 0:", size - 1);
            scanf("%d", &index);
            task2(str, &size, index);
            break;
        case 3:
            task3(str, size);
            break;
        case 4:
            printf("Enter index for edit, max index = %d and min index = 0:", size - 1);
            scanf("%d", &tracker);
            task4(&str, &tracker);
            break;
        }

    } while (task != 5);

    return 0;
}
