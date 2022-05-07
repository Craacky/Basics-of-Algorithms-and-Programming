#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *element;
    struct stack *next;
} stack;

stack *head = NULL;

void push(char *el)
{
    stack *pointer;
    pointer = (stack *)malloc(sizeof(stack));
    if (pointer)
    {
        pointer->element = el;
        pointer->next = head;
        head = pointer;
        printf("push element %s \n", el);
    }
    else
    {
        puts("error! not free memory!");
    }
}

char *pop()
{
    char *current = head->element;
    stack *pointer = head;
    head = head->next;
    free(pointer);
    printf("pop element %s \n", current);
    return current;
}

int is_operation(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int priority(char operation)
{
    if (operation == '+' || operation == '-')
        return 1;
    if (operation == '*' || operation == '/')
        return 2;
    return 0;
}

double calculate(char postfix[][255])
{
    double a, b;
    double result = 0.0;
    char results[100][255] = {0};
    const size_t rsize = 255;
    int r = 0;

    for (int index = 0; *postfix[index] != '\0'; ++index)
    {
        switch (*postfix[index])
        {
        case '+':
            b = atof(pop());
            a = atof(pop());
            result = a + b;
            snprintf(results[r], rsize, "%.2f", result);
            push(results[r]);
            ++r;
            break;
        case '-':
            b = atof(pop());
            a = atof(pop());
            result = a - b;
            snprintf(results[r], rsize, "%.2f", result);
            push(results[r]);
            ++r;
            break;
        case '*':
            b = atof(pop());
            a = atof(pop());
            result = a * b;
            snprintf(results[r], rsize, "%.2f", result);
            push(results[r]);
            ++r;
            break;
        case '/':
            b = atof(pop());
            a = atof(pop());
            result = a / b;
            snprintf(results[r], rsize, "%.2f", result);
            push(results[r]);
            ++r;
            break;
        default:
            push(postfix[index]);
            break;
        }
    }
    return result;
}

int main()
{
    char infix[100];
    char postfix[100][255] = {0};
    char *buffer;
    int length = 0;
    int i = 0;
    int j = 0;
    double result = 0.0;
    int n = 0;
    strcpy(infix, "(((3.3+3.3)+(2.2*2.2))*0.5)");
    push("(");
    length = strlen(infix);
    infix[length] = ')';
    infix[length + 1] = '\0';
    while (head)
    {
        for (; infix[i] != '\0'; i++)
        {
            if (infix[i] == '(')
            {
                push("(");
            }
            else
            {
                if (infix[i] == ')')
                {
                    while (strcmp((buffer = pop()), "("))
                    {
                        ++j;
                        n = 0;
                        postfix[j][0] = *buffer;
                    }
                }
                else if (is_operation(infix[i]))
                {
                    ++j;
                    n = 0;
                    while (1)
                    {
                        buffer = pop();
                        if (priority(*buffer) >= priority(infix[i]))
                        {
                            strcpy(postfix[j++], buffer);
                        }
                        else
                        {
                            push(buffer);
                            break;
                        }
                    };
                    push(&infix[i]);
                }
                else
                {
                    postfix[j][n++] = infix[i];
                }
            }
        }
    }
    result = calculate(postfix); 
    printf("\n");
    printf("postfix = ");
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            printf("%c",postfix[i][j]);
        }
        
    }
    printf("\n");
    printf("result = %.2f", result);
    return 0;
}