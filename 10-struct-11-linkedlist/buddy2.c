//
// Created by 10054 on 2023/2/17.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    bool is_free;
    int size;
    int id;
    struct node *next_node;
    struct node *last_node;
} Node;

Node *init_buddy;
Node *first_node;
int node_num = 1;

void query();

void allocate(int size, int id);

int fit_size(int m);

void free_list();

int main() {
    init_buddy = calloc(1, sizeof(struct node));
    first_node = init_buddy;
    int q;
    scanf("%d%d", &init_buddy->size, &q);
    init_buddy->is_free = true;

    for (int i = 0; i < q; ++i) {
        char ord[2];
        scanf("%s", ord);
        if (*ord == 'Q') {
            query();
        } else {
            int id, m;
            scanf("%d%d", &id, &m);
            allocate(fit_size(m), id);
        }
    }

    free_list();
    return 0;
}

void query() {
    printf("%d\n", node_num);
    Node *nd = first_node;
    while (nd != NULL) {
        printf("%d ", nd->id);
        nd = nd->next_node;
    }
    printf("\n");
}

void allocate(int size, int id) {
    while (1) {
        Node *nd = first_node;
        while (nd != NULL) {
            if (nd->size == size && nd->is_free) {
                nd->is_free = false;
                nd->id = id;
                return;
            }
            nd = nd->next_node;
        }

        nd = first_node;
        while (nd != NULL) {
            if (nd->size > size && nd->is_free)
                break;
            nd = nd->next_node;
        }

        node_num++;
        Node *new_nd = calloc(1, sizeof(struct node));
        new_nd->is_free = true;
        new_nd->size = nd->size = nd->size - 1;
        if (nd == first_node) {
            first_node = new_nd;
        } else {
            nd->last_node->next_node = new_nd;
            new_nd->last_node = nd->last_node;
        }
        nd->last_node = new_nd;
        new_nd->next_node = nd;
    }
}

int fit_size(int m) {
    for (int i = 0; i < 32; ++i) {
        if (pow(2, i) >= m)
            return i;
    }
}

void free_list() {
    Node *nd = first_node;
    while (nd != NULL) {
        first_node = nd->next_node;
        free(nd);
        nd = first_node;
    }
    first_node = NULL;
    init_buddy = NULL;
}