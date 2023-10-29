//
// Created by 10054 on 2022/10/22.
//
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9
int chart[SIZE][SIZE] = {0};

int main() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            scanf("%d", &chart[row][col]);
        }
    }

    bool right = true;


    for (int row = 0; row < SIZE; row++) {
        int count[10] = {1};
        for (int col = 0; col < SIZE; col++) {
            count[chart[row][col]]++;
        }
        for (int i = 1; i <= SIZE; i++) {
            if (count[i]) continue;
            else {
                right = false;
                break;
            }
        }
        if (right) continue;
        else break;
    }


    if (right) {
        for (int col = 0; col < SIZE; col++) {
            int count[10] = {0};
            for (int row = 0; row < SIZE; row++) {
                count[chart[row][col]]++;
            }
            for (int i = 1; i <= SIZE; i++) {
                if (count[i]) continue;
                else {
                    right = false;
                    break;
                }
            }
            if (right) continue;
            else break;
        }
    }

    if (right) {
        for (int col = 0; col < SIZE; col += 3) {
            for (int row = 0; row < SIZE; row += 3) {
                int count[10] = {0};
                for (int col2 = col; col2 < col + 3; col2++) {
                    for (int row2 = row; row2 < row + 3; row2++) {
                        count[chart[row2][col2]]++;
                    }
                }
                for (int i = 1; i <= SIZE; i++) {
                    if (count[i]) continue;
                    else {
                        right = false;
                        break;
                    }
                }
            }
        }
    }

    printf(right ? "YES" : "NO");
    return 0;
}