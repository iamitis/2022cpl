//
// Created by 10054 on 2022/12/28.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct team {
    char name[20];
    struct {
        char player_name[20];
        int scores[3];
    } players[11];
    int total_points[3];
} Team;
Team team[1000];

int atk_cmp(const void *l, const void *r);

int def_cmp(const void *l, const void *r);

int tac_cmp(const void *l, const void *r);

int main() {
    int n = 0;
    scanf("%d", &n);

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

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 11; k++) {
                team[j].total_points[i] += team[j].players[k].scores[i];
            }
        }
    }

    qsort(team, n, sizeof(*team), atk_cmp);
    for (int i = 0; i < n; ++i) {
        printf("%s ", team[i].name);
    }
    printf("\n");

    qsort(team, n, sizeof(*team), def_cmp);
    for (int i = 0; i < n; ++i) {
        printf("%s ", team[i].name);
    }
    printf("\n");

    qsort(team, n, sizeof(*team), tac_cmp);
    for (int i = 0; i < n; ++i) {
        printf("%s ", team[i].name);
    }

    return 0;
}

int atk_cmp(const void *l, const void *r) {
    return ((Team *) r)->total_points[0] - ((Team *) l)->total_points[0];
}

int def_cmp(const void *l, const void *r) {
    return ((Team *) r)->total_points[1] - ((Team *) l)->total_points[1];
}

int tac_cmp(const void *l, const void *r) {
    return ((Team *) r)->total_points[2] - ((Team *) l)->total_points[2];
}