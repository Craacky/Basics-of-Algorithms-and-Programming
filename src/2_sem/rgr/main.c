#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    theatre *head = NULL;
    int pointer = 0;
    int delete_pointer = 0;
    int edit_pointer = 0;
    char string[255];
    double price = 0;
   
    do
    {
        console_help();
        scanf("%d", &pointer);
        switch (pointer)
        {
        case 1:
            add_node(&head, 1, "Naruto", 4.2);
            add_node(&head, 2, "Bleach", 5.7);
            add_node(&head, 2, "One Piece", 6.1);
            add_node(&head, 2, "Hunter x Hunter", 8.3);
            add_node(&head, 5, "Death Node", 9.6);
            add_node(&head, 6, "Samurai Champloo", 10.5);
            add_node(&head, 7, "Death Note", 4.2);
            add_node(&head, 8, "Dragon Ball", 5.7);
            add_node(&head, 9, "Ghost in the Shell", 3.8);
            add_node(&head, 10, "Seven Samurai", 12.7);
            add_node(&head, 11, "Durara", 18.8);
            add_node(&head, 12, "Princess Mononoke", 8.3);
            add_node(&head, 13, "Attack on Titan", 12.7);
            add_node(&head, 14, "Evangelion", 4.2);
            add_node(&head, 15, "Apple Seed", 6.1);
            add_node(&head, 16, "JoJo Bizarre Adventure", 18.8);
            add_node(&head, 17, "Fullmetal Alvhemist", 72.9);
            push_file(head);
            break;
        case 2:
            printf("Enter index for delete");
            scanf("%d", &delete_pointer);
            delete_node(&head, delete_pointer);
            push_file(head);
            break;
        case 3:
            printf("Enter index for edit:");
            scanf("%d", &edit_pointer);
            edit_node(&head, edit_pointer, string, price);
            push_file(head);
            break;
        case 4:
            printList(head);
            break;
        case 5:
            filter_node(head);
            break;
        case 6:
            printf("in ascending order:\n");
            printList(head);
            printf("in descending order:\n");
            sort_node(head);
            break;
        }

    } while (pointer != 7);

    return 0;
}


