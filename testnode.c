#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* new_node(int value, Node* next) {
    Node* node = calloc(1, sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

int node_length_rec(Node* list) {
    if (list == NULL) {
        return 0;
    }
    else {
        return 1 + node_length_rec(list->next);
    }
}

void print_length_rec(Node* list) {
    printf("Das ist die Länge der Liste, rekursiv ermittelt: %d \n", node_length_rec(list));
}

Node* prepend_list (int value, Node* list) {
    Node* new_list = new_node(value, list);
    return list;
}

int node_length_iterative(Node* list) {
    int i = 0;
    for(list = list; list != NULL; list = list->next) {
        i++;
    }
    return i;
}

void print_length_iter(Node* list) {
    printf("Das ist die Länge der Liste, iterativ ermittelt: %d \n", node_length_iterative(list));
}

void print_list(Node* list) {
    if (list == NULL) return;
    else if (list->next == NULL) {
        printf("%d", list->value);
        return;
    } else {
        printf("%d  ", list->value);
        print_list(list->next);
    }
}

void print_list_itre(Node* list) {
    if (list == NULL) {
        printf("[]\n");
    } else {
        printf("[ ");
        for (list = list; list != NULL; list = list->next) {
            printf("%d ", list->value);
        }
        printf("]\n");
    }
}

void print_list_with_brackets(Node* list) {
    printf("[ ");
    print_list(list);
    printf(" ]\n");
}

Node* last_element(Node* list) {
    if (list->next == NULL) {
        return list;
    }
    else {
        return last_element(list->next);
    }
}

void print_last_element(Node* list) {
    printf("This is the last element of your list: %d \n", last_element(list)->value);
}

Node* append_list(int value, Node* list) {
    if (list == NULL) {
        list = new_node(value, NULL);
    }
    else {
        Node* last = last_element(list);
        Node* appended_element = new_node(value, NULL);
        last->next = appended_element;
    }
    return list;
}

Node* append_list_recursively(int value, Node *list) {
    if (list == NULL) {
        return new_node(value, NULL);
    } else {
        list->next = append_list_recursively(value, list->next);
        return list;
    }
}

int main(){
    Node* list = new_node(24, new_node(1, new_node(20, new_node(100, NULL))));
    print_list_with_brackets(list);
    print_last_element(list);
    append_list_recursively(1000, list);
    print_last_element(list);
    return 0;
}

