//
// Created by 10054 on 2022/12/28.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 500000
#define LEN 1000

typedef struct node {
    struct node *next_node;
    char *str;
} Node;

typedef struct link {
    Node *head;
    Node *tail;
} Link;
Link str_link[NUM];

typedef struct string {
    char str[LEN];
    int val;
} String;
String string;
String ord;

int Hash(const char *s);

void Append(const String *s);

void Search(const String *s);

void Free(Link *s);

int main() {
    int m = 0, q = 0;
    scanf("%d%d", &m, &q);

    for (int i = 0; i < NUM; i++) {
        str_link[i].head = NULL;
    }

    for (int i = 0; i < m; i++) {
        scanf("%s", string.str);
        string.val = Hash(string.str);
        Append(&string);
        memset(&string, 0, sizeof(string));
    }

    for (int i = 0; i < q; i++) {
        scanf("%s", ord.str);
        ord.val = Hash(ord.str);
        Search(&ord);
        memset(&ord, 0, sizeof(ord));
    }

    Free(str_link);

    return 0;
}

int Hash(const char *s) {
    int len = (int) strlen(s);
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret = (ret + s[i] * (i + 1)) % NUM;
    }
    return ret;
}

void Append(const String *s) {
    if (str_link[s->val].head == NULL) {
        str_link[s->val].head = malloc(sizeof(Node));
        str_link[s->val].head->str = malloc(strlen(s->str) + 1);
        strcpy(str_link[s->val].head->str, s->str);
        str_link[s->val].tail = malloc(sizeof(Node));
        str_link[s->val].head->next_node = str_link[s->val].tail;
    } else {
        str_link[s->val].tail->str = malloc(strlen(s->str) + 1);
        strcpy(str_link[s->val].tail->str, s->str);
        str_link[s->val].tail->next_node = malloc(sizeof(Node));
        str_link[s->val].tail = str_link[s->val].tail->next_node;
    }
}

void Search(const String *s) {
    if (str_link[s->val].head == NULL) {
        printf("No\n");
    } else {
        Node *ss = str_link[s->val].head;
        while (ss != str_link[s->val].tail) {
            if (strcmp(ss->str, s->str) == 0) {
                printf("Yes\n");
                return;
            }
            ss = ss->next_node;
        }
        printf("No\n");
    }
}

void Free(Link *s) {
    for (int i = 0; i < NUM; i++) {
        Node *ss = s->head;
        while (ss != s->tail) {
            Node *sss = ss->next_node;
            ss->next_node = ss->next_node->next_node;
            free(sss);
        }
    }
}