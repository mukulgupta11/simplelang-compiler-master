#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct Node {
    TokenType type;
    char value[MAX_TOKEN_LEN];
    struct Node *left;
    struct Node *right;
} Node;

Node* parseProgram(FILE *file);
void freeAST(Node *node);

#endif // PARSER_H
