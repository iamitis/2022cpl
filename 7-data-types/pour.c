//
// Created by 10054 on 2022/11/23.
//
#include <stdio.h>
#include <stdbool.h>

bool Pour(int k, int a, int b, int c, int Va, int Vb, int Vc, int a0, int b0, int c0);

int main() {
    int k = 0;
    int a = 0, b = 0, c = 0;
    int Va = 0, Vb = 0, Vc = 0;
    int a0 = 0, b0 = 0, c0 = 0;

    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &Va, &Vb, &Vc, &a, &b, &c, &a0, &b0, &c0);

    bool pour = Pour(k, a, b, c, Va, Vb, Vc, a0, b0, c0);

    printf(pour ? "Yes" : "No");

    return 0;
}

bool Pour(int k, int a, int b, int c, int Va, int Vb, int Vc, int a0, int b0, int c0) {
    if (k == 0 && !(a == a0 && b == b0 && c == c0)) {
        return false;
    }
    if (a == a0 && b == b0 && c == c0) {
        return true;
    } else {
        if (Pour(k - 1, 0, (b + a <= Vb) ? b + a : Vb, c, Va, Vb, Vc, a0, b0, c0)) {
            return true;
        } else if (Pour(k - 1, 0, b, (c + a <= Vc) ? c + a : Vc, Va, Vb, Vc, a0, b0, c0)) {
            return true;
        } else if (Pour(k - 1, (b + a <= Va) ? b + a : Va, 0, c, Va, Vb, Vc, a0, b0, c0)) {
            return true;
        } else if (Pour(k - 1, a, 0, (b + c <= Vc) ? b + c : Vc, Va, Vb, Vc, a0, b0, c0)) {
            return true;
        } else if (Pour(k - 1, (c + a <= Va) ? c + a : Va, b, 0, Va, Vb, Vc, a0, b0, c0)) {
            return true;
        } else if (Pour(k - 1, a, (b + c <= Vb) ? b + c : Vb, 0, Va, Vb, Vc, a0, b0, c0)) {
            return true;
        }
    }
}