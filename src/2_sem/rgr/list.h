#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct theatre
{
    int index;
    char *cinema_name;
    double price;
    struct theatre *next;
} theatre;

FILE *data_base;

void *add_node(theatre **head, int index, char *cinema_name, double price)
{
    theatre *node = (theatre *)malloc(sizeof(theatre));
    theatre *last = *head;

    node->index = index;
    node->cinema_name = cinema_name;
    node->price = price;
    node->next = NULL;

    if (*head == NULL)
    {
        *head = node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = node;
    return;
}
void printList(theatre *node)
{

    printf("---------------------------------------------\n");
    printf("|index|         movie name        |  price  |\n");
    printf("---------------------------------------------\n");
    if (node == NULL)
        printf("------------------Nothing--------------------\n");
    while (node != NULL)
    {
        printf("| %-3d | %-25s | %-7.2lf |\n", node->index, node->cinema_name, node->price);
        node = node->next;
    }
    printf("---------------------------------------------\n");
}
void push_file(theatre *head)
{
    data_base = fopen("text.txt", "w");
    while (head != NULL)
    {
        fprintf(data_base, " %d %s %.2lf\n", head->index, head->cinema_name, head->price);
        head = head->next;
    }
    fclose(data_base);
}
void console_help()
{
    printf("console help:\n");
    printf("!!!ATTENTION!!!\n");
    printf("If you enter numbers that are not\nin help then the menu pops up again\n");
    printf("press 1 -> calling the add node function\n");
    printf("press 2 -> calling the delete node function\n");
    printf("press 3 -> calling the edit node function\n");
    printf("press 4 -> calling the print function\n");
    printf("press 5 -> calling the filter function\n");
    printf("press 6 -> calling the sorting function\n");
    printf("press 7 -> exit\n");
    printf("Input line: ");
}

void delete_node(theatre **head, int index)
{
    theatre *temp = *head, *prev;
    if (*head == NULL)
    {
        printf("\nEmpty List\n");
    }
    if (temp != NULL && temp->index == index)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->index != index)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
void edit_node(theatre **head, int key, char *string, double price)
{
    theatre *current = *head;
    char check[255];
    while (current != NULL)
    {
        if (current->index == key)
        {
            printf("%d %s %.2lf\n", current->index, current->cinema_name, current->price);
            break;
        }
        else
        {
            current = current->next;
        }
    }
    printf("Enter what you want edit (name) or (price): ");
    scanf("%s", check);
    if (strcmp(check, "price") == 0)
    {
        printf("enter variant of price:");
        scanf("%lf", &price);
        current->price = price;
    }
    if (strcmp(check, "name") == 0)
    {
        printf("enter variant of name:\n");
        scanf("%s", string);
        current->cinema_name = string;
    }
}

void sort_node(theatre *head)
{
    theatre *cur = head;
    theatre *prev = NULL;
    theatre *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    printf("---------------------------------------------\n");
    printf("|index|         movie name        |  price  |\n");
    printf("---------------------------------------------\n");
    while (prev != NULL)
    {
        printf("| %-3d | %-25s | %-7.2lf |\n", prev->index, prev->cinema_name, prev->price);
        prev = prev->next;
    }
    printf("---------------------------------------------\n");
}

void filter_node(theatre *head)
{
    char filter_check[255];
    int filter_index = 0;
    char filter_name[255];
    double filter_price = 0;

    printf("Enter parameter for filter:\n");
    printf("-index\n");
    printf("-name\n");
    printf("-price\n");
    scanf("%s", filter_check);
    if (strcmp(filter_check, "index") == 0)
    {
        printf("Enter index parameter for filter:");
        scanf("%d", &filter_index);
        while (head->next != NULL)
        {
            if (filter_index == head->index)
            {
                printf("| %-3d | %-25s | %-7.2lf |\n", head->index, head->cinema_name, head->price);
                head = head->next;
            }
            else
            {
                head = head->next;
            }
        }
    }
    if (strcmp(filter_check, "name") == 0)
    {
        printf("Enter name parameter for filter:");
        scanf("%s", filter_name);
        while (head->next != NULL)
        {
            if (strstr(head->cinema_name, filter_name))
            {
                printf("| %-3d | %-25s | %-7.2lf |\n", head->index, head->cinema_name, head->price);
                head = head->next;
            }
            else
            {
                head = head->next;
            }
        }
    }
    if (strcmp(filter_check, "price") == 0)
    {
        printf("Enter index parameter for filter:");
        scanf("%lf", &filter_price);
        while (head->next != NULL)
        {
            if (filter_price == head->price)
            {
                printf("| %-3d | %-25s | %-7.2lf |\n", head->index, head->cinema_name, head->price);
                head = head->next;
            }
            else
            {
                head = head->next;
            }
        }
    }
}
