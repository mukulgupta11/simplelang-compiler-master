#include <stdio.h>
#include "codegen.h"

void generateCode(Node *root) {
    if (!root) return;

    // Traversing the AST to generate assembly instructions
    if (root->type == TOKEN_IDENTIFIER) {
        printf("LOAD %s\n", root->value);
    }

    // Generate code for left and right nodes (if any)
    generateCode(root->left);
    generateCode(root->right);
}
