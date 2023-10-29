//
// Created by 10054 on 2022/11/9.
//
#include <stdio.h>
#include <math.h>

double Func(int n, int p, const int arr[], double x);

double Itg(int n, int p, const int arr[], double a, double b);

double Dev(int n, int p, const int arr[], double l, double r, double e);

int main(){
    int n = 0, p = 0;
    double a = 0; double b = 0;
    int num[10000] = {0};
    scanf("%d%d\n", &n, &p);
    for (int i = 0; i <= n; i++) {
        scanf("%d\n", &num[i]);
    }
    scanf("%lf%lf", &a, &b);
    double e = pow(10, -4);

    printf("%lf", Dev(n, p, num, a, b, e));

    return 0;
}

double Func(int n, int p, const int arr[], double x) {
    double rst = 0;
    for (int i = 0; i <= n; i++ ) {
        rst += arr[i] * pow(x, i);
    }
    return  pow(rst, p);
}

double Itg(int n, int p, const int arr[], double a, double b) {
    return (4 * Func(n, p, arr, (a + b) / 2.0) + Func(n, p, arr, a) + Func(n, p, arr, b)) / 6.0 * (b - a);
}

double Dev(int n, int p, const int arr[], double l, double r, double e) {
    double dev = fabs(Itg(n, p, arr, l, (l + r) / 2.0) + Itg(n, p, arr, (l + r) / 2.0, r) - Itg(n, p, arr, l, r));
    double SL = Itg(n, p, arr, l, (l + r) / 2.0);
    double SR = Itg(n, p, arr, (l + r) / 2.0, r);
    double S = Itg(n, p, arr, l, r);
    if (dev <= e * 15) {
        return SL + SR + (SL +SR - S) / 15.0;
    }

    return Dev(n, p, arr, l, (l + r) / 2.0, e / 2.0) + Dev(n, p, arr, (l + r) / 2.0, r, e / 2.0);
}