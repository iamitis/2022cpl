#include "ramfs.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/* modify this file freely */

#define FD_NUM 4096
#define MIN(a, b) (a) > (b) ? (b) : (a)

typedef struct node {
    enum {
        FILE_NODE, DIR_NODE
    } type;
    struct node **dirents;
    struct node *high;
    char *content;
    char *name;
    int num_in_high;
    int max_numinhigh;
    union {
        int nrde;
        int size;
    };
    int level;
} node;
node root;

int level = 1;
int levels[1500];

typedef struct FD {
    int offset;
    int flags;
    node *f;
} FD;
FD file_d[FD_NUM];

char *prj[500];
int prj_count = 2;

bool check_word(const char *pathname) {
    int len = (int)strlen(pathname);

    if (pathname[0] != '/')
        return false;

    for (int i = 1; i < len; ++i) {
        if (!(pathname[i] >= 'a' && pathname[i] <= 'z')
            && !(pathname[i] >= 'A' && pathname[i] <= 'Z')
            && !(pathname[i] >= '0' && pathname[i] <= '9')
            && pathname[i] != '/'
            && pathname[i] != '.')
            return false;
    }

    return true;

}

void read_path(const char *pathname) {
    // divide nodes of path
    int len = (int) strlen(pathname);
    for (int i = 1; i < len; i++) {
        if (*(pathname + i) != '/' && *(pathname + i - 1) == '/') {
            const char *next = strchr(pathname + i, '/');
            if (next == NULL) {
                prj[prj_count] = calloc(len - i + 1, sizeof(char));
                memcpy(prj[prj_count], pathname + i, len - i);
                prj_count++;
                if (len - i > 32) {
                    *prj[2] = '=';
                    break;
                }
                break;
            }

            else {
                int prj_len = (int) (next - pathname - i);
                prj[prj_count] = calloc(prj_len + 1, sizeof(char));
                memcpy(prj[prj_count], pathname + i, prj_len);
                prj_count++;
                i += prj_len;

                if (prj_len > 32) {
                    *prj[2] = '=';
                    break;
                }
            }
        }
    }
}

typedef enum {
    OLD_DIR, OLD_FILE, NEW, WRONG_P
} prj_type;

typedef struct the_node {
    node *n;
    prj_type type;
} the_node;

the_node check_path(int n, char *p[], const char *pathname) {
    the_node nd;

    if (*pathname != '/' || n > level + 1 || *prj[2] == '=') {
        nd.type = WRONG_P;
        return nd;
    }

    if (!check_word(pathname)) {
        nd.type = WRONG_P;
        return nd;
    }

    nd.n = &root;
    bool legal = true;
    for (int i = 2; i <= n - 1; i++) {
        legal = false;

        for (int j = 1; j <= nd.n->max_numinhigh + 1; ++j) {
            if ((nd.n->dirents == NULL || nd.n->dirents[j] != NULL) && nd.n->dirents[j]->type == DIR_NODE && strcmp(nd.n->dirents[j]->name, p[i]) == 0) {
                legal = true;
                nd.n = nd.n->dirents[j];
                break;
            }
        }

        if (!legal) {
            break;
        }
    }

    if (legal) {
        for (int i = 1; i <= nd.n->max_numinhigh; ++i) {
            if (nd.n->dirents[i] != NULL && strcmp(nd.n->dirents[i]->name, p[n]) == 0) {
                nd.n = nd.n->dirents[i];
                nd.type = (nd.n->type == DIR_NODE) ? OLD_DIR : OLD_FILE;
                return nd;
            }
        }

        nd.type = NEW;
        return nd;
    }

    nd.type = WRONG_P;
    return nd;
}

void clean_prj() {
    for (int i = 2; i < prj_count; i++) {
        free(prj[i]);
        prj[i] = NULL;
    }
    prj_count = 2;
}

int allocate_fd() {
    for (int i = 0; i < FD_NUM; ++i) {
        if (file_d[i].f == NULL)
            return i;
    }
    return -1;
}

void deal_oflags(int fd, int flags) {
    file_d[fd].flags = flags;
    file_d[fd].offset = 0;

    int append_bit = 1024 & flags;
    int trunc_bit = 512 & flags;
    int rw_bit = 2 & flags;
    int rowo_bit = 1 & flags;

    if (trunc_bit && (rowo_bit || rw_bit)) {
        file_d[fd].f->size = 0;
        free(file_d[fd].f->content);
        file_d[fd].f->content = NULL;
    }

    if (append_bit) {
        file_d[fd].offset = file_d[fd].f->size;
    }
}

int creat_newnode(node *high_node) {
    if (high_node->max_numinhigh != 0) {
        high_node->dirents = realloc(high_node->dirents, high_node->max_numinhigh * sizeof(struct node*));
    } else {
        high_node->dirents = calloc(1, sizeof(node*));
    }

    high_node->nrde++;
    int num_in_high = 0;
    for (int i = 1; i <= high_node->max_numinhigh + 1; ++i) {
        if (high_node->dirents[i] == NULL) {
            num_in_high = i;
            break;
        }
    }

    if (high_node->max_numinhigh < num_in_high) {
        high_node->max_numinhigh = num_in_high;
    }

    high_node->dirents[num_in_high] = calloc(1,sizeof(struct node));
    node *new_node = high_node->dirents[num_in_high];
    new_node->dirents == NULL;
    new_node->level = high_node->level + 1;
    new_node->num_in_high = num_in_high;
    new_node->high = high_node;
    new_node->name = calloc(strlen(prj[prj_count - 1]), sizeof(char));
    strcpy(new_node->name, prj[prj_count - 1]);

    levels[new_node->level]++;
    if (high_node->level == level)
        level++;

    return num_in_high;
}

void close_fd(int fd) {
    file_d[fd].f = NULL;
    file_d[fd].flags = 0;
    file_d[fd].offset = 0;
}


int ropen(const char *pathname, int flags) {
    read_path(pathname);
    the_node nd = check_path(prj_count - 1, prj, pathname);

    if (nd.type == WRONG_P) {
        clean_prj();
        return -1;
    }
    else {
        int fd = allocate_fd();
        if (nd.type == OLD_DIR) {
            file_d[fd].f = nd.n;
            clean_prj();
            return fd;
        } else if (nd.type == OLD_FILE) {
            file_d[fd].f = nd.n;
            deal_oflags(fd, flags);
            clean_prj();
            return fd;
        } else {
            int creat_bit = 64 & flags;
            if (!creat_bit || pathname[strlen(pathname) - 1] == '/') {
                close_fd(fd);
                clean_prj();
                return -1;
            }

            int num_in_high = creat_newnode(nd.n);

            file_d[fd].f = nd.n->dirents[num_in_high];
            file_d[fd].f->type = FILE_NODE;
            file_d[fd].flags = flags;
            file_d[fd].offset = 0;

            clean_prj();
            return fd;
        }
    }
}

int rclose(int fd) {
    if (file_d[fd].f == NULL)
        return -1;

    close_fd(fd);
    return 0;
}

ssize_t rwrite(int fd, const void *buf, size_t count) {
    if (file_d[fd].f == NULL) {
        return -1;
    }

    int first_bit = 1 & file_d[fd].flags;
    int second_bit = 2 & file_d[fd].flags;
    // is dir or cannot be written
    if (file_d[fd].f->type == DIR_NODE || (!first_bit && !second_bit)) {
        return -1;
    }

    int of = file_d[fd].offset;
    int old_size = file_d[fd].f->size;
    // 文件扩容
    if (old_size < of + count) {
        file_d[fd].f->size = file_d[fd].offset + (int)count;

        if (old_size == 0) {
            file_d[fd].f->content = calloc(of + count + 1, sizeof(char));
            file_d[fd].f->size = (int)count + of;
        } else {
            file_d[fd].f->content = realloc(file_d[fd].f->content, of + count + 1);
            file_d[fd].f->size = of + (int)count;
        }
    }

    // set "\0" if offset is over old_file's size
    if (of > old_size) {
        for (int i = old_size; i < of; ++i) {
            file_d[fd].f->content[i] = '\0';
        }
    }

    memcpy(file_d[fd].f->content + of, buf, (int)count);

    file_d[fd].offset += (int)count;

    return (ssize_t)count;
}

ssize_t rread(int fd, void *buf, size_t count) {
    if (fd < 0 || file_d[fd].f == NULL || file_d[fd].f->content == NULL || file_d[fd].offset < 0) {
        return -1;
    }

    if (file_d[fd].offset > file_d[fd].f->size) {
        return 0;
    }

    int first_bit = 1 & file_d[fd].flags;
    int second_bit = 2 & file_d[fd].flags;
    // 01 || 11 cannot be read
    if ((!second_bit && first_bit) || first_bit != 0) {
        return -1;
    }

    int of = file_d[fd].offset;
    int copy_size = file_d[fd].f->size - of;

    memcpy(buf, file_d[fd].f->content + of, count);

    file_d[fd].offset += MIN(copy_size, (int)count);

    return MIN((int)count, copy_size);
}

off_t rseek(int fd, off_t offset, int whence) {
    if (file_d[fd].f == NULL) {
        return -1;
    }

    if (whence == SEEK_SET) {
        file_d[fd].offset = offset;
        return file_d[fd].offset;
    }

    if (whence == SEEK_CUR) {
        file_d[fd].offset += offset;
        return file_d[fd].offset;
    }

    if (whence == SEEK_END) {
        file_d[fd].offset = file_d[fd].f->size + offset;
        return file_d[fd].offset;
    }

    return file_d[fd].offset;
}

int rmkdir(const char *pathname) {
    read_path(pathname);
    the_node nd = check_path(prj_count - 1, prj, pathname);

    if (nd.type != NEW) {
        clean_prj();
        return -1;
    }

    int num_in_high = creat_newnode(nd.n);

    nd.n->dirents[num_in_high]->type = DIR_NODE;

    clean_prj();
    return 0;
}

int rrmdir(const char *pathname) {
    read_path(pathname);
    the_node nd = check_path(prj_count - 1, prj, pathname);

    if (nd.type != OLD_DIR || nd.n->nrde != 0) {
        clean_prj();
        return -1;
    }

    nd.n->high->nrde--;
    levels[nd.n->level]--;
    if (levels[nd.n->level] == 0)
        level--;

    int numinhigh = nd.n->num_in_high;
    free(nd.n->name);
    free(nd.n->high->dirents[numinhigh]);
    nd.n->high->dirents[numinhigh] = NULL;

    clean_prj();
    return 0;
}

int runlink(const char *pathname) {
    read_path(pathname);
    the_node nd = check_path(prj_count - 1, prj, pathname);

    if (nd.type != OLD_FILE) {
        clean_prj();
        return -1;
    }

    nd.n->high->nrde--;
    levels[nd.n->level]--;
    if (levels[nd.n->level] == 0)
        level--;

    int numinhigh = nd.n->num_in_high;
    free(nd.n->name);
    free(nd.n->content);
    free(nd.n->high->dirents[numinhigh]);
    nd.n->high->dirents[numinhigh] = NULL;

    clean_prj();
    return 0;
}

void init_ramfs() {
    root.type = DIR_NODE;
    root.content = NULL;
    root.high = NULL;
    root.num_in_high = 0;
    root.nrde = 0;
    root.level = 1;
    root.name = calloc(2, sizeof(char));
    *root.name = '/';

    prj[1] = calloc(2, sizeof(char));
    *prj[1] = '/';
}