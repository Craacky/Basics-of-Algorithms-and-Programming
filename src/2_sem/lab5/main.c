#include "list.h"
#include <stdio.h>

int main()
{
    tree *pointer = NULL;
    pointer = insert_node(pointer, 5, "Kolya Yakutin");
    pointer = insert_node(pointer, 6, "Ilya Yurkevich");
    pointer = insert_node(pointer, 7, "Dasha Leonovets");
    pointer = insert_node(pointer, 1, "Uliana Chaykovckaya");
    pointer = insert_node(pointer, 2, "Egor Moroz");
    print_tree(pointer, 0);
    int index = 0;
    printf("Enter index for search = ");
    scanf("%d", &index);
    search_node(pointer, index);
    printf("in order:\n");
    in_order(pointer);
    printf("pre order:\n");
    pre_order(pointer);
    printf("post order:\n");
    post_order(pointer);

    delete_node(pointer, 2);
    printf("after deleting in order:\n");
    in_order(pointer);
    printf("after deleting pre order:\n");
    pre_order(pointer);
    printf("after deleting post order:\n");
    post_order(pointer);
    print_tree(pointer, 0);
    return 0;
}