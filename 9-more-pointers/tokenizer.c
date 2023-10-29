//
// Created by 10054 on 2022/11/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char Type(const char *word, unsigned long long len);

bool Reserved(const char *word);

bool Operator(const char *word);

bool Float(const char *word, unsigned long long len);

bool Integer(const char *word, unsigned long long len);


int main() {
    char *type = malloc(5000);
    for (int i = 0; i < 5000; i++) {
        *(type + i) = 0;
    }
    int index = 0;

    bool legal = true;
    char *word = malloc(1000 * sizeof(*word));
    while (scanf("%s", word) != EOF) {
        const char *position = strchr(word, ';');
        if (position == NULL) {
            //there is no ';'
            unsigned long long len = strlen(word);
            *(type + index) = Type(word, len);
            if (*(type + index) == 'e') {
                legal = false;
                break;
            }
            index++;
        } else {
            //left of ';'
            unsigned long long lenL = position - word;
            if (lenL > 0) {
                char *wordL = malloc(lenL * sizeof(*wordL));
                strncpy(wordL, word, lenL);
                *(type + index) = Type(wordL, lenL);
                if (*(type + index) == 'e') {
                    legal = false;
                    break;
                }
                index += 1;
            }

            *(type + index) = 's';
            index += 1;
            //right of ';'
            unsigned long long lenR = strlen(position + 1);
            if (lenR > 0) {
                *(type + index) = Type(position + 1, lenR);
                if (*(type + index) == 'e') {
                    legal = false;
                    break;
                }
                index += 1;
            }
        }

    }
    free(word);

    if (legal) {
        for (int i = 0; i < index; i++) {
            if (*(type + i) == 'r') {
                printf("reserved ");
            } else if (*(type + i) == 'o') {
                printf("operator ");
            } else if (*(type + i) == 'i') {
                printf("integer ");
            } else if (*(type + i) == 'v') {
                printf("variable ");
            } else if (*(type + i) == 'f') {
                printf("float ");
            } else if (*(type + i) == 's') {
                printf("\n");
            }
        }
    } else {
        printf("Compile Error");
    }

    free(type);
    return 0;
}

char Type(const char *word, unsigned long long len) {
    if (Reserved(word)) {
        return 'r';
    } else if (Operator(word)) {
        return 'o';
    } else if (Integer(word, len)) {
        return 'i';
    } else if (*word == '_' || (*word >= 'A' && *word <= 'Z') || (*word >= 'a' && *word <= 'z')) {
        return 'v';
    } else if (Float(word, len)) {
        return 'f';
    } else return 'e';
}

bool Reserved(const char *word) {
    return (strcmp(word, "const") == 0 || strcmp(word, "int") == 0 || strcmp(word, "float") == 0 ||
            strcmp(word, "double") == 0
            || strcmp(word, "long") == 0 || strcmp(word, "static") == 0 || strcmp(word, "void") == 0 ||
            strcmp(word, "char") == 0
            || strcmp(word, "extern") == 0 || strcmp(word, "return") == 0 || strcmp(word, "break") == 0 ||
            strcmp(word, "enum") == 0
            || strcmp(word, "struct") == 0 || strcmp(word, "typedef") == 0 || strcmp(word, "union") == 0 ||
            strcmp(word, "goto") == 0);
}

bool Operator(const char *word) {
    return (*word == '+' || *word == '-' || *word == '*' || *word == '/' || *word == '=' || strcmp(word, "==") == 0
            || strcmp(word, "!=") == 0 || strcmp(word, ">=") == 0 || strcmp(word, "<=") == 0 || *word == '>' ||
            *word == '<');

}

bool Float(const char *word, unsigned long long len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (*(word + i) == '.') {
            count++;
        }
    }
    return (len >= 2 && count == 1);
}

bool Integer(const char *word, unsigned long long len) {
    for (int i = 0; i < len; i++) {
        if (*(word + i) < '0' || *(word + i) > '9') {
            return false;
        }
    }
    if (len < 1) return false;
    return true;
}