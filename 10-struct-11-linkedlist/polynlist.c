//
// Created by 10054 on 2022/12/26.
//
#include <stdio.h>
#include <string.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

int a = 0;
int b = 0;

void Plus(int power[], int p[][10000], int MaxP);

void Minus(int power[], int p[][10000], int MaxP);

void Multiply(int power[], int p[][10000]);

void Print(const int power[], int MaxP, char name[]);

int main() {
    int power[3][20000] = {0};
    int polynomial[2][10000] = {0};
    char name[11] = {0};

    scanf("%d%d%s", &a, &b, name);
    for (int i = a; i >= 0; i--) {
        scanf("%d", &polynomial[0][i]);
    }
    for (int i = b; i >= 0; i--) {
        scanf("%d", &polynomial[1][i]);
    }

    Plus(power[0], polynomial, MAX(a, b));
    Print(power[0], MAX(a, b), name);

    Minus(power[1], polynomial, MAX(a, b));
    Print(power[1], MAX(a, b), name);

    Multiply(power[2], polynomial);

    Print(power[2], a + b, name);

    return 0;
}

void Plus(int power[], int p[][10000], int MaxP) {
    for (int i = MaxP; i >= 0; i--) {
        if (i <= a) {
            power[i] += p[0][i];
        }
        if (i <= b) {
            power[i] += p[1][i];
        }
    }
}

void Minus(int power[], int p[][10000], int MaxP) {
    for (int i = MaxP; i >= 0; i--) {
        if (i <= a) {
            power[i] += p[0][i];
        }
        if (i <= b) {
            power[i] -= p[1][i];
        }
    }
}

void Multiply(int power[], int p[][10000]) {
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            power[i + j] += p[0][i] * p[1][j];
        }
    }
}

void Print(const int power[], int MaxP, char name[]) {
    int initial = 0;
    for (int i = MaxP; i >= 0; i--) {
        if (power[i] != 0) {
            initial = i;
            break;
        }
    }

    if (initial > 0) {
        if (initial == 1) {
            if (power[initial] == 1) {
                printf("%s", name);
            } else if (power[initial] == -1) {
                printf("-%s", name);
            } else if (power[initial] != 0) {
                printf("%d%s", power[initial], name);
            }
        }

        if (initial > 1) {
            if (power[initial] == 1) {
                printf("%s^%d", name, initial);
            } else if (power[initial] == -1) {
                printf("-%s^%d", name, initial);
            } else if (power[initial] != 0) {
                printf("%d%s^%d", power[initial], name, initial);
            }

            for (int i = MaxP - 1; i > 1; i--) {
                if (power[i] == 1) {
                    printf("+%s^%d", name, i);
                } else if (power[i] == -1) {
                    printf("-%s^%d", name, i);
                } else if (power[i] > 0) {
                    printf("+%d%s^%d", power[i], name, i);
                } else if (power[i] < 0) {
                    printf("%d%s^%d", power[i], name, i);
                }
            }

            if (power[1] == 1) {
                printf("+%s", name);
            } else if (power[1] == -1) {
                printf("-%s", name);
            } else if (power[1] > 0) {
                printf("+%d%s", power[1], name);
            } else if (power[1] < 0) {
                printf("%d%s", power[1], name);
            }
        }

        if (power[0] == 1 || power[0] == -1) {
            printf(power[0] == 1 ? "+1" : "-1");
        } else if (power[0] > 0) {
            printf("+%d", power[0]);
        } else if (power[0] < 0) {
            printf("%d", power[0]);
        }
    }
    if (initial == 0) {
        printf("%d", power[0]);
    }

    printf("\n");
}