//
// Created by 10054 on 2022/11/23.
//
#include <stdio.h>
#include <string.h>

int main() {
    int a = 0, b = 0, c = 0, codx = 0, cody = 0;
    char ord[1003] = {0};
    scanf("%d%d%d\n", &a, &b, &c);
    gets(ord);
    int len = strlen(ord);

    int pose = 1;
    for (int i = 0; i < len; i++) {
        if (ord[i] == 'W') {
            if (pose == 1) {
                codx -= c;
                pose = 3;
            } else if (pose == 2) {
                codx -= b;
                pose = 4;
            } else if (pose == 3) {
                codx -= a;
                pose = 1;
            } else if (pose == 4) {
                codx -= a;
                pose = 2;
            } else if (pose == 5) {
                codx -= c;
                pose = 6;
            } else {
                codx -= b;
                pose = 5;
            }
        } else if (ord[i] == 'S') {
            if (pose == 1) {
                codx += a;
                pose = 3;
            } else if (pose == 2) {
                codx += a;
                pose = 4;
            } else if (pose == 3) {
                codx += c;
                pose = 1;
            } else if (pose == 4) {
                codx += b;
                pose = 2;
            } else if (pose == 5) {
                codx += b;
                pose = 6;
            } else {
                codx += c;
                pose = 5;
            }
        } else if (ord[i] == 'A') {
            if (pose == 1) {
                cody -= c;
                pose = 2;
            } else if (pose == 2) {
                cody -= b;
                pose = 1;
            } else if (pose == 3) {
                cody -= a;
                pose = 6;
            } else if (pose == 4) {
                cody -= a;
                pose = 5;
            } else if (pose == 5) {
                cody -= c;
                pose = 4;
            } else {
                cody -= b;
                pose = 3;
            }
        } else if (ord[i] == 'D') {
            if (pose == 1) {
                cody += b;
                pose = 2;
            } else if (pose == 2) {
                cody += c;
                pose = 1;
            } else if (pose == 3) {
                cody += b;
                pose = 6;
            } else if (pose == 4) {
                cody += c;
                pose = 5;
            } else if (pose == 5) {
                cody += a;
                pose = 4;
            } else {
                cody += a;
                pose = 3;
            }
        }
    }

    if (pose == 1) {
        printf("%d %d %d %d", codx, codx + a, cody, cody + b);
    } else if (pose == 2) {
        printf("%d %d %d %d", codx, codx + a, cody, cody + c);
    } else if (pose == 3) {
        printf("%d %d %d %d", codx, codx + c, cody, cody + b);
    } else if (pose == 4) {
        printf("%d %d %d %d", codx, codx + b, cody, cody + c);
    } else if (pose == 5) {
        printf("%d %d %d %d", codx, codx + b, cody, cody + a);
    } else {
        printf("%d %d %d %d", codx, codx + c, cody, cody + a);
    }

    return 0;
}