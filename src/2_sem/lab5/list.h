#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left, *right;
    int index;
    char *string;
} tree;
// -------------------------------------------------------------
tree *new_node(int index, char *string)
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->index = index;
    temp->string = string;
    temp->left = temp->right = NULL;
    return temp;
}
// -------------------------------------------------------------
tree *insert_node(tree *pointer, int index, char *string)
{
    if (pointer == NULL)
        return new_node(index, string);

    if (index < pointer->index)
        pointer->left = insert_node(pointer->left, index, string);
    else
        pointer->right = insert_node(pointer->right, index, string);

    return pointer;
}
// -------------------------------------------------------------
tree *search_node(tree *pointer, int index)
{
    if (pointer == NULL || pointer->index == index)
    {
        printf("%3d %3s\n", pointer->index, pointer->string);
        return pointer;
    }

    if (pointer->index < index)
        return search_node(pointer->right, index);

    return search_node(pointer->left, index);
}
// -------------------------------------------------------------
tree *delete_node(tree *pointer, int index)
{
    if (pointer == NULL)
        return pointer;
    if (index < pointer->index)
        pointer->left = delete_node(pointer->left, index);
    else if (index > pointer->index)
        pointer->right = delete_node(pointer->right, index);
    else
    {
        if (pointer->left == NULL)
        {
            tree *node = pointer->right;
            free(pointer);
            return node;
        }
        else if (pointer->right == NULL)
        {
            tree *node = pointer->left;
            free(pointer);
            return node;
        }
    }
    return pointer;
}
// -------------------------------------------------------------
void in_order(tree *pointer)
{
    if (pointer != NULL)
    {
        in_order(pointer->left);
        printf("%3d %3s\n", pointer->index, pointer->string);
        in_order(pointer->right);
    }
}
// -------------------------------------------------------------
void pre_order(tree *pointer)
{
    if (pointer != NULL)
    {
        printf("%3d %3s\n", pointer->index, pointer->string);
        pre_order(pointer->left);
        pre_order(pointer->right);
    }
}
// -------------------------------------------------------------
void post_order(tree *pointer)
{
    if (pointer != NULL)
    {
        post_order(pointer->left);
        post_order(pointer->right);
        printf("%3d %3s\n", pointer->index, pointer->string);
    }
}
// -------------------------------------------------------------
void print_tree(tree *pointer, int level)
{
    if (pointer != NULL)
    {
        print_tree(pointer->right, level + 1);
        for (int i = 0; i < level; i++)
            printf("    ");
        printf("%3d %3s\n", pointer->index, pointer->string);
        print_tree(pointer->left, level + 1);
    }
}
// -------------------------------------------------------------