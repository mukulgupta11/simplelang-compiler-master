#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"

int main() {
    FILE *file = fopen("examples/sample.sl", "r");
    if (!file) {
        perror("Failed to open input file");
        return 1;
    }

    Node *ast = parseProgram(file);
    fclose(file);

    printf("Generated Assembly:\n");
    generateCode(ast);

    freeAST(ast);
    return 0;
}
