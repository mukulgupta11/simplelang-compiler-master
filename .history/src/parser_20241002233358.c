#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"

// Function to create a new AST node
Node* createNode(TokenType type, const char *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    strcpy(node->value, value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* parseStatement(FILE *file) {
    Token token;
    getNextToken(file, &token);
    
    if (token.type == TOKEN_INT) {
        // Handle variable declaration
        getNextToken(file, &token); // Expecting identifier
        if (token.type == TOKEN_IDENTIFIER) {
            Node *node = createNode(TOKEN_IDENTIFIER, token.text);
            getNextToken(file, &token); // Expecting semicolon
            if (token.type == TOKEN_SEMICOLON) {
                return node;
            }
        }
    } else if (token.type == TOKEN_IF) {
        // Handle conditional
        // Parsing logic for condition and block goes here
    }
    
    return NULL;  // Fallback if the statement is not recognized
}

// Entry point for parsing the program
Node* parseProgram(FILE *file) {
    Node *root = createNode(TOKEN_UNKNOWN, "program");
    
    while (!feof(file)) {
        Node *stmt = parseStatement(file);
        if (stmt) {
            // Attach parsed statement to the AST
            // (You can handle linking nodes here)
        }
    }
    
    return root;
}

void freeAST(Node *node) {
    if (!node) return;
    freeAST(node->left);
    freeAST(node->right);
    free(node);
}
