//
// Created by 10054 on 2022/12/27.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n = 0, q = 0;

typedef struct file {
    char name[12];
    struct file *higher_file;
    int nums;
} File;
File files[10000];

int Count(const File *file);

void Remove(const char name[]);

void Query(const char name[]);

int main() {
    scanf("%d%d", &n, &q);

    struct {
        char name[12];
        char higher_name[12];
    } ties[10000];

    for (int i = 1; i <= n; i++) {
        scanf("%s%s", ties[i].name, ties[i].higher_name);
    }

    struct {
        char ord[12];
        char target[12];
    } ords[500];

    for (int i = 0; i < q; i++) {
        scanf("%s%s", ords[i].ord, ords[i].target);
    }

    // the highest file
    strcpy(files[1].name, ties[1].name);
    files[1].higher_file = &files[1];
    // names of other files
    for (int i = 2; i <= n; i++) {
        strcpy(files[i].name, ties[i].name);
    }
    // higher_file of other files
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (strcmp(files[j].name, ties[i].higher_name) == 0) {
                files[i].higher_file = &files[j];
            }
        }
    }

    // count the numbers of files
    files[1].nums = n;
    for (int i = 2; i <= n; i++) {
        files[i].nums = Count(files + i);
    }

    for (int i = 0; i < q; i++) {
        if (strncmp(ords[i].ord, "remove", 6) == 0) {
            Remove(ords[i].target);
        } else if (strncmp(ords[i].ord, "query", 5) == 0) {
            Query(ords[i].target);
        }
    }

    return 0;
}

int Count(const File *file) {
    int num_of_lower = 0;
    for (int i = 2; i <= n; i++) {
        if (files[i].higher_file == file) {
            num_of_lower++;
        }
    }

    if (num_of_lower == 0) {
        return 1;
    }

    int next_file = 0;
    for (int i = 2; i <= n; i++) {
        if (files[i].higher_file == file) {
            next_file += Count(files + i);
        }
    }

    return next_file + 1;
}

void Remove(const char name[]) {
    for (int i = 1; i <= n; i++) {
        if (strcmp(name, files[i].name) == 0) {
            File *highers = files[i].higher_file;
            while (highers != &files[1]) {
                highers->nums -= files[i].nums;
                highers = highers->higher_file;
            }
            files[1].nums -= files[i].nums;
            break;
        }
    }
}

void Query(const char name[]) {
    for (int i = 1; i <= n; ++i) {
        if (strcmp(name, files[i].name) == 0) {
            printf("%d\n", files[i].nums);
            break;
        }
    }
}