#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
  struct list_item *head;
} list;

typedef struct list_mark_item
{
  int mark;
  struct list_mark_item *next, *prev;
} list_mark_item;

typedef struct list_marks
{
  struct list_mark_item *head;
} list_marks;

typedef struct list_item
{
  const char *subject;
  list_marks *marks;
  struct list_item *next, *prev;
} list_item;

list *createSinglyArray()
{
  list *array = (list *)malloc(sizeof(list));
  array->head = NULL;
  return array;
}

//---------------------------------------------------------------------------------------------------
list_item *addNode(list *array, const char *name)
{
  list_item *node = (list_item *)malloc(sizeof(list_item));

  node->subject = name;
  list_marks *array_marks = (list_marks *)malloc(sizeof(list_marks));
  array_marks->head = NULL;
  node->marks = array_marks;
  node->next = NULL;
  node->prev = NULL;

  if (array->head != NULL)
  {
    list_item *find_node = array->head;
    while (find_node->next != NULL)
    {
      find_node = find_node->next;
    }
    find_node->next = node;
  }
  else
  {
    array->head = node;
  }

  return node;
}

//---------------------------------------------------------------------------------------------------
void addMark(list_item *node, const int mark)
{
  list_mark_item *mark_node = (list_mark_item *)malloc(sizeof(list_mark_item));
  mark_node->mark = mark;
  mark_node->next = NULL;
  mark_node->prev = NULL;
  if (node->marks->head)
  {
    list_mark_item *find_node = node->marks->head;
    while (find_node->next != NULL)
    {
      find_node = find_node->next;
    }
    find_node->next = mark_node;
    find_node->prev = find_node;
  }
  else
  {
    node->marks->head = mark_node;
  }
}

//---------------------------------------------------------------------------------------------------
void print_array(list *array)
{
  list_item *cur_node = array->head;

  while (cur_node)
  {

    printf("Subject: %s ", cur_node->subject);
    if (cur_node->marks)
    {
      list_mark_item *ptr_mark = cur_node->marks->head;
      while (ptr_mark)
      {
        printf("-> Marks: ");
        int i = 0;
        while (ptr_mark)
        {
          if (i++ > 0)
          {
            printf(", ");
          }
          printf("%d", ptr_mark->mark);
          ptr_mark = ptr_mark->next;
        }
      }
      printf("\n");
    }
    else
    {
      printf("No marks\n");
    }
    cur_node = cur_node->next;
  }
}

//---------------------------------------------------------------------------------------------------
int count_head(list *array)
{
  int count = 0;

  if (array->head && array->head->marks)
  {
    list_mark_item *cur_mark = array->head->marks->head;

    while (cur_mark)
    {
      ++count;
      cur_mark = cur_mark->next;
    }
  }

  return count;
}

//---------------------------------------------------------------------------------------------------
list_item *find_subject(list *array, char *key)
{
  list_item *item = array->head;
  if (!item)
    return NULL;

  while (item)
  {
    if (strcmpi(item->subject, key) == 0)
    {
      return item;
    }
    item = item->next;
  }

  return NULL;
}

//---------------------------------------------------------------------------------------------------
double average_by_key(list *array, char *key)
{
  double average = 0.0;

  list_item *subject = find_subject(array, key);
  if (!subject)
    return average;

  int count = 0;
  list_mark_item *ptr_marks = subject->marks->head;

  while (ptr_marks)
  {
    ++count;
    average += ptr_marks->mark;
    ptr_marks = ptr_marks->next;
  }

  if (count > 0)
    average /= count;
  return average;
}

//---------------------------------------------------------------------------------------------------
void delete_by_key(list *array, char *key)
{
  list_item *item = array->head;
  if (!item)
    return;

  list_item *prev_item = item->prev;
  item->prev = NULL;

  while (item)
  {
    if (strcmpi(item->subject, key) == 0)
    {
      break;
    }
    prev_item = item;
    item = item->next;
  }

  list_mark_item *ptr_marks = item->marks->head;
  int marks_count = 0;
  while (ptr_marks)
  {
    ++marks_count;
    ptr_marks = ptr_marks->next;
  }

  if (marks_count > 0)
  {
    list_mark_item **marks_ptrs = (list_mark_item **)malloc(sizeof(list_mark_item *) * marks_count);

    ptr_marks = item->marks->head;
    int ptr_index = 0;
    while (ptr_marks)
    {
      marks_ptrs[ptr_index++] = ptr_marks;
      ptr_marks = ptr_marks->next;
    }

    for (int i = 0; i < ptr_index; ++i)
    {
      free(marks_ptrs[i]);
    }

    free(marks_ptrs);
  }

  free(item->marks);

  if (prev_item)
  {
    prev_item->next = item->next;
  }
  else
  {
    array->head = item->next;
  }

  free(item);
}

//---------------------------------------------------------------------------------------------------
void add_marks(list_item *subject, int count)
{
  int value;
  for (int i = 0; i < count; i++)
  {
    printf("Enter %d mark = ", i + 1);
    scanf("%d", &value);
    addMark(subject, value);
  }
  printf("\n");
}

//---------------------------------------------------------------------------------------------------
// Main Entry
//---------------------------------------------------------------------------------------------------
int main()
{
  int count;
  char key[255];
  printf("Enter how much marks:");
  scanf("%d", &count);

  list *array = createSinglyArray();

  list_item *algebra = addNode(array, "Algebra");
  add_marks(algebra, count);
  list_item *russian = addNode(array, "Russian");
  add_marks(russian, count);
  list_item *biology = addNode(array, "Biology");
  add_marks(biology, count);

  print_array(array);

  // print how much elements
  const int marks_count = count_head(array);
  printf("Mark elements in head %d\n", marks_count);
  // avarage for key subject
  printf("Enter name of subject for average calculations: ");
  scanf("%s", key);
  double marks_counts = average_by_key(array, key);
  printf("Average %s = %.3f\n", key, marks_counts);
  // delete subject by key
  delete_by_key(array, key);
  print_array(array);
  return 0;
}