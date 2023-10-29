//
// Created by 10054 on 2022/12/15.
//
#include <stdio.h>
#include <stdlib.h>

struct {
    char name[20];
    struct {
        char player_name[20];
        int scores[3];
    } players[11];
    int total_points[3];
} team[1000];

void Sort(int *points, int len);

int main() {
    int n = 0;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", team[i].name);
        for (int j = 0; j < 11; j++) {
            scanf("%s", team[i].players[j].player_name);
            scanf("%d%d%d",
                  &team[i].players[j].scores[0],
                  &team[i].players[j].scores[1],
                  &team[i].players[j].scores[2]);
        }
    }

    int total_points[3][1000] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 11; k++) {
                total_points[i][j] += team[j].players[k].scores[i];
            }
            team[j].total_points[i] = total_points[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        Sort(total_points[i], n);
        for (int j = n - 1; j >= 0; j--) {
            for (int k = 0; k < n; k++) {
                if (team[k].total_points[i] == total_points[i][j]) {
                    printf("%s ", team[k].name);
                }
            }
        }
        printf("\n");
    }

    return 0;
}

void Sort(int points[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (points[j] < points[i]) {
                int temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}