//
// Created by 10054 on 2022/11/23.
//
#include <stdio.h>
#include <math.h>

int tot = 1;
int size[400005] = {0}, ID[400005] = {0};

int FitSize(int m);

void Query();

void Allocate(int id, int s);

int FindFree(int s);

int main() {
    int n = 0, q = 0;
    scanf("%d%d\n", &n, &q);

    size[1] = n;
    ID[1] = 0;

    for (int i = 0; i < q; i++) {
        char op[3];
        scanf("%s", op);
        if (op[0] == 'A') {
            int id = 0, m = 0;
            scanf("%d%d", &id, &m);
            Allocate(id, FitSize(m));
        } else {
            Query();
        }
    }


    return 0;
}

void Allocate(int id, int s) {
    while (1) {
        int pos = FindFree(s);
        if (size[pos] == s) {
            ID[pos] = id;
            return;
        } else {
            size[pos] -= 1;
            tot += 1;
            for (int i = tot; i > pos; i--) {
                size[i] = size[i - 1];
                ID[i] = ID[i - 1];
            }
        }
    }
}

int FindFree(int s) {
    for (int i = 1; i <= tot; i++) {
        if (s == size[i] && ID[i] == 0) {
            return i;
        }
    }
    for (int i = 1; i <= tot; i++) {
        if (size[i] > s && ID[i] == 0) {
            return i;
        }
    }
}

int FitSize(int m) {
    for (int i = 0; i < 31; i++) {
        if (pow(2, i) >= m) {
            return i;
        }
    }
}

void Query() {
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) {
        printf("%d ", ID[i]);
    }
    printf("\n");
}