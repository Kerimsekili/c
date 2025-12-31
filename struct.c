#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int          value;
    struct node* next;
};

void add_node(struct node* list, struct node* new_node)
{
    struct node* last = list;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void add_node_to(struct node* list, struct node* new_node, int index)
{
    struct node* temp = list;

    int i = 0;
    while (temp->next != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    new_node->next = temp->next;
    temp->next     = new_node;
}

void remove_at(struct node* list, int index)
{
    struct node* temp = list;

    int i = 0;
    while (temp->next != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    struct node* del = temp->next;
    temp->next       = temp->next->next;
    
    free(del);
}

void print_list(struct node* list)
{
    struct node* temp = list;

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    puts("");
}

void delete_list(struct node* list)
{
    struct node* temp = list;

    while (temp != NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main(void)
{
    struct node* list = malloc(sizeof(struct node));

    list->value = 0;
    list->next  = NULL;

    for (size_t i = 0; i < 9; i++) {
        struct node* temp = malloc(sizeof(struct node));

        temp->value = i + 1;
        temp->next  = NULL;

        add_node(list, temp);
    }

    print_list(list);

    struct node* node = malloc(sizeof(struct node));

    node->value = 31;
    node->next  = NULL;

    add_node_to(list, node, 5);
    print_list(list);

    remove_at(list, 3);
    print_list(list);

    delete_list(list);
    list = NULL;
}

