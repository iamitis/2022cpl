//
// Created by 10054 on 2022/11/19.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool PushPop(const char *brk, int len);

int main() {
    int n = 0;
    scanf("%d\n", &n);
    char brk[31][1005] = {0};
    for (int i = 0; i < n; i++) {
        gets(brk[i]);
    }

    for (int i = 0; i < n; i++) {
        int len = (int) strlen(brk[i]);
        bool legal = PushPop(brk[i], len);
        printf(legal ? "True\n" : "False\n");
    }

    return 0;
}

bool PushPop(const char *brk, int len) {
    char stack[50004] = {0};
    int floor = 0;

    if (brk[0] == ')' || brk[0] == ']' || brk[0] == '}') {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (brk[i] == '(' || brk[i] == '[' || brk[i] == '{') {
            stack[floor] = brk[i];
            floor += 1;
        } else {
            if (floor > 0 && (brk[i] - 1 == stack[floor - 1] || brk[i] - 2 == stack[floor - 1])) {
                stack[floor - 1] = 0;
                floor -= 1;
            }
        }
        if (stack[0] == 0 && (brk[i + 1] == ')' || brk[i + 1] == ']' || brk[i + 1] == '}')) {
            return false;
        }
    }

    return stack[0] == 0 ? true : false;
}