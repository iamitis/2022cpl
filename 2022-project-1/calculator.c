//
// Created by 10054 on 2022/12/3.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define LEN_OF_STRING 3000

// set the tokens of input
struct {
    int type;
    char str[32];
} tokens[LEN_OF_STRING];
int count_of_tokens = 0;

int Type(const char str[], int len);

bool Integer(const char str[], int len);

bool Float(const char str[], int len);

bool Variable(const char str[], int len);

struct {
    char name[50];
    bool be_assigned;
    enum {
        INT1, FLOAT1, ERROR1
    } type;
    union {
        long long iVal;
        double fVal;
        bool error;
    } val;
} variable[130];
int v = 0;

typedef struct {
    enum {
        INT, FLOAT, ERROR
    } type;
    struct {
        long long iVal;
        double fVal;
    } val;
} Value;

Value EvalAssign(int l, int r);

typedef struct {
    int index;
    bool exist;
} EqualSign;

EqualSign ExistEqualSign(int l, int r);

void VariableAssign(Value end_value);

bool CheckGrammar(int l, int r);

Value Eval(int l, int r);

bool CheckParentheses(int l, int r);

bool LegalBrackets(int l, int r);

int FindOp(int l, int r);

Value MeetValue(Value v1, Value v2, int op);

bool NewVariable(int a);


int main() {
    // set FALSE for be_assign in variable[]
    for (int i = 0; i < 130; i++) {
        variable[i].be_assigned = false;
    }

    Value end_value = {ERROR, 1};
    char string[LEN_OF_STRING] = {0};
    while (gets(string) != NULL) {
        // set tokens
        // before that, we should reset the tokens[].str of the last turn
        for (int i = 0; i < LEN_OF_STRING; i++) {
            for (int j = 0; j < 32; j++) {
                tokens[i].str[j] = '\000';
            }
        }
        //now read the new line of input stream
        int len_of_str = (int) strlen(string);
        for (int i = 0; i < len_of_str; i++) {
            if (string[i] != ' ') {
                const char *next_space = strchr(string + i, ' ');
                if (next_space != NULL && next_space != string + len_of_str - 1) {
                    strncpy(tokens[count_of_tokens].str, string + i, next_space - (string + i));
                    count_of_tokens++;
                    i += (int) (next_space - (string + i));
                } else {
                    if (*(string + len_of_str - 1) == ' ') {
                        strncpy(tokens[count_of_tokens].str, string + i, len_of_str - 1 - i);
                    } else {
                        strcpy(tokens[count_of_tokens].str, string + i);
                    }
                    break;
                }
            }
        }
        for (int i = 0; i <= count_of_tokens; i++) {
            tokens[i].type = Type(tokens[i].str, (int) strlen(tokens[i].str));
        }

        int l = 0, r = count_of_tokens;

        int wrong = 0;
        for (int i = l; i <= r; i++) {
            if (tokens[i].type == 4) {
                wrong++;
            }
        }
        if (wrong > 0 || !LegalBrackets(l, r)) {
            printf("Error\n");
            continue;
        }

        VariableAssign(end_value);

        end_value = EvalAssign(l, r);

        if (end_value.type == ERROR) {
            printf("Error\n");
        } else if (end_value.type == INT) {
            printf("%lld\n", end_value.val.iVal);
        } else {
            printf("%lf\n", end_value.val.fVal);
        }

        count_of_tokens = 0;
        scanf("\n");
    }

    return 0;
}


int Type(const char str[], int len) {
    if (len == 1 &&
        (*str == '=' || *str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '(' || *str == ')')) {
        return 0;
    } else if (Integer(str, len)) {
        return 1;
    } else if (Float(str, len)) {
        return 2;
    } else if (Variable(str, len)) {
        return 3;
    } else {
        return 4;
    }
}

bool Integer(const char str[], int len) {
    for (int i = 0; i < len; i++) {
        if (*(str + i) < '0' || *(str + i) > '9') {
            return false;
        }
    }
    // 前导 0
    if (*str == '0' && len > 1) {
        return false;
    }
    return true;
}

bool Float(const char str[], int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (*(str + i) == '.') {
            count++;
        } else if (*(str + i) > '9' || *(str + i) < '0') {
            return false;
        }
    }
    if (count != 1 || len < 3) {
        return false;
    }
    const char *position = strchr(str, '.');
    // 前导 0
    if (position - str > 1 && *str == '0') {
        return false;
    }
    // 点位
    if (position == str || position == str + len - 1) {
        return false;
    }
    return true;
}

bool Variable(const char str[], int len) {
    if (*str != '_' && !(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z')) {
        return false;
    }
    for (int i = 1; i < len; i++) {
        if (*(str + i) != '_' && !(*(str + i) >= 'A' && *(str + i) <= 'Z') &&
            !(*(str + i) >= 'a' && *(str + i) <= 'z') &&
            !(*(str + i) >= '0' && *(str + i) <= '9')) {
            return false;
        }
    }
    return true;
}

void VariableAssign(Value end_value) {
    for (int i = 0; i < v; i++) {
        if (!variable[i].be_assigned) {
            if (end_value.type == INT) {
                variable[i].type = INT1;
                variable[i].val.iVal = end_value.val.iVal;
            } else if (end_value.type == FLOAT) {
                variable[i].type = FLOAT1;
                variable[i].val.fVal = end_value.val.fVal;
            } else {
                variable[i].type = ERROR1;
            }
            variable[i].be_assigned = true;
        }
    }
}

Value EvalAssign(int l, int r) {
    Value p;
    if (ExistEqualSign(l, r).exist) {
        int equal_index = ExistEqualSign(l, r).index;
        // firstly check grammar
        if (!CheckGrammar(l, r)) {
            p.type = ERROR;
            return p;
        }
        // creat a new variable
        if (tokens[equal_index - 1].type == 3) {
            if (NewVariable(equal_index - 1)) {
                strcpy(variable[v].name, tokens[equal_index - 1].str);
                v++;
            }
            // compute the value of the variable
            return EvalAssign(equal_index + 1, r);
        } else {
            p.type = ERROR;
            return p;
        }
    } else {
        return Eval(l, r);
    }
}

EqualSign ExistEqualSign(int l, int r) {
    EqualSign p = {0, false};
    for (int i = l; i <= r; i++) {
        if (strcmp(tokens[i].str, "=") == 0) {
            p.exist = true;
            p.index = i;
            return p;
        }
    }
    return p;
}

bool CheckGrammar(int l, int r) {
    // as continuous assignment
    int a = ExistEqualSign(l, r).index;
    if (ExistEqualSign(a + 1, r).exist) {
        int b = ExistEqualSign(a + 1, r).index;
        if (b - a > 2) {
            return false;
        }
    }
    if (!ExistEqualSign(0, a - 1).exist && a > 1) {
        return false;
    }
    if (a == count_of_tokens) {
        return false;
    }

    return true;
}

bool NewVariable(int a) {
    for (int i = 0; i < v; i++) {
        if (strcmp(tokens[a].str, variable[i].name) == 0) {
            variable[i].be_assigned = false;
            return false;
        }
    }
    return true;
}

Value Eval(int l, int r) {
    Value p;
    if (l > r) {
        p.type = ERROR;
        p.val.iVal = 0;
        return p;
    } else if (l == r) {
        if (tokens[l].type == 1) {
            p.type = INT;
            p.val.iVal = strtoll(tokens[l].str, NULL, 10);
            return p;
        } else if (tokens[l].type == 2) {
            p.type = FLOAT;
            p.val.fVal = strtod(tokens[l].str, NULL);
            return p;
        } else if (tokens[l].type == 3) {
            for (int i = 0; i < v; i++) {
                if (strcmp(tokens[l].str, variable[i].name) == 0) {
                    if (variable[i].type == INT1) {
                        p.type = INT;
                        p.val.iVal = variable[i].val.iVal;
                        return p;
                    } else if (variable[i].type == FLOAT1) {
                        p.type = FLOAT;
                        p.val.fVal = variable[i].val.fVal;
                        return p;
                    }
                }
            }
        }
        p.type = ERROR;
        p.val.iVal = 0;
        return p;
    } else if (CheckParentheses(l, r)) {
        return Eval(l + 1, r - 1);
    } else {
        int op = FindOp(l, r);
        if (op < 0) {
            p.type = ERROR;
            return p;
        }
        // check minus
        while (op > l && *tokens[op].str == '-' &&
               (*tokens[op - 1].str == '+' || *tokens[op - 1].str == '-' || *tokens[op - 1].str == '*' ||
                *tokens[op - 1].str == '/')) {
            op--;
        }
        if (op == 0 || *tokens[op - 1].str == '(' || *tokens[op - 1].str == '=' || op == l) {
            Value val = Eval(op + 1, r);
            val.val.iVal *= -1;
            val.val.fVal *= -1;
            return val;
        } else {
            Value val1 = Eval(l, op - 1);
            Value val2 = Eval(op + 1, r);
            return MeetValue(val1, val2, op);
        }
    }
}

bool CheckParentheses(int l, int r) {
    if (*tokens[l].str == '(' && *tokens[r].str == ')') {
        return LegalBrackets(l + 1, r - 1) ? true : false;
    }
    return false;
}

bool LegalBrackets(int l, int r) {
    char brk[1000] = {0};
    int b = 0;
    for (int i = l; i <= r; i++) {
        if (*tokens[i].str == '(' || *tokens[i].str == ')') {
            strcpy(brk + b, tokens[i].str);
            b++;
        }
    }
    char stack[1000] = {0};
    int floor = 0;
    for (int i = 0; i < b; i++) {
        if (stack[0] == 0 && brk[i] == ')') {
            return false;
        }
        if (brk[i] == '(') {
            stack[floor] = brk[i];
            floor += 1;
        } else {
            if (floor > 0 && brk[i] - 1 == stack[floor - 1]) {
                stack[floor - 1] = 0;
                floor -= 1;
            }
        }
    }
    return stack[0] == 0 ? true : false;
}

int FindOp(int l, int r) {
    for (int p = r; p >= l; p--) {
        if (*tokens[p].str == '+' || *tokens[p].str == '-') {
            if (LegalBrackets(p, r)) {
                return p;
            }
        }
    }
    for (int p = r; p >= l; p--) {
        if (*tokens[p].str == '*' || *tokens[p].str == '/') {
            if (LegalBrackets(p, r)) {
                return p;
            }
        }
    }
    return -1;
}

Value MeetValue(Value v1, Value v2, int op) {
    Value p;
    if (v1.type == ERROR || v2.type == ERROR) {
        p.type = ERROR;
        return p;
    }
    // 类型提升
    if (v1.type != v2.type) {
        if (v1.type == INT) {
            v1.type = FLOAT;
            v1.val.fVal = (double) v1.val.iVal;
        } else {
            v2.type = FLOAT;
            v2.val.fVal = (double) v2.val.iVal;
        }
    }
    p.type = v1.type;
    if (p.type == INT) {
        if (*tokens[op].str == '+') {
            p.val.iVal = v1.val.iVal + v2.val.iVal;
        } else if (*tokens[op].str == '-') {
            p.val.iVal = v1.val.iVal - v2.val.iVal;
        } else if (*tokens[op].str == '*') {
            p.val.iVal = v1.val.iVal * v2.val.iVal;
        } else if (*tokens[op].str == '/') {
            p.val.iVal = v1.val.iVal / v2.val.iVal;
        }
    } else {
        if (*tokens[op].str == '+') {
            p.val.fVal = v1.val.fVal + v2.val.fVal;
        } else if (*tokens[op].str == '-') {
            p.val.fVal = v1.val.fVal - v2.val.fVal;
        } else if (*tokens[op].str == '*') {
            p.val.fVal = v1.val.fVal * v2.val.fVal;
        } else if (*tokens[op].str == '/') {
            p.val.fVal = v1.val.fVal / v2.val.fVal;
        }
    }
    return p;
}