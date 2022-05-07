#pragma once
#ifndef MAIN_H
#define MAIN_H

struct list;
struct list_item;

struct list_marks;
struct list_mark_item;

struct list *createSinglyArray();
struct list_item *addNode(struct list *array, const char *name);
void addMark(struct list_item *node, const int mark);
void print_array(struct list *array);
int count_head(struct list *array);
struct list_item *find_subject(struct list *array, char *key);
double average_by_key(struct list *array, char *key);
void delete_by_key(struct list *array, char *key);
void add_marks(struct list_item *subject, int count);

#endif