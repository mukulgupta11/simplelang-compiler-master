# SimpleLang Compiler for 8-bit CPU

## Introduction
**SimpleLang** is a minimalistic high-level language designed to run on an 8-bit CPU. It supports variable declarations, assignments, arithmetic operations, and conditional statements. The language is simple and easy to understand, making it ideal for educational purposes.

This project implements a **SimpleLang compiler** that translates SimpleLang code into assembly code for an 8-bit CPU. The 8-bit CPU simulator can then execute the generated assembly code.

## Features
The SimpleLang compiler supports:
- Variable declarations (e.g., `int a;`)
- Assignment operations (e.g., `a = b + c;`)
- Arithmetic operations (`+` and `-`)
- Conditional statements (`if (a == b) { ... }`)


## Getting Started

### Prerequisites
- A working C/C++ environment (GCC, MinGW, or Clang)
- The 8-bit CPU simulator, which can be cloned from the [8-bit CPU repository](https://github.com/lightcode/8bit-computer)
- Basic knowledge of C/C++ and assembly language

### Installing the 8-bit CPU Simulator
    cd 8bit-computer

1. Follow the instructions in the `README.md` of the 8-bit CPU repository to set up and run the simulator.

### Compiling the SimpleLang Compiler>
    cd simplelang-compiler

1. Compile the compiler using the provided `Makefile`:
   This will compile the `lexer.c`, `parser.c`, and `codegen.c` files and generate an executable named `compiler`.

### Running the Compiler
1. Write your SimpleLang program in the `input.txt` file. For example:
  plaintext
   
    int a;
    int b;
    int c;
    
    a = 10;
    b = 20;
    c = a + b;

    if (c == 30) {
      c = c + 1;
    }

2. Run the compiler to generate assembly code:
    ./compiler input.txt output.asm

3. The generated assembly code will be saved in `output.asm`. You can load this file into the 8-bit CPU simulator to execute it.

### Running the Assembly Code in the 8-bit CPU Simulator
1. Copy the contents of `output.asm` into the 8-bit CPU simulator.
2. Run the simulator as described in the 8-bit CPU repository's README to see the output.

### Example Output
For the input program:
plaintext

int a;
int b;
int c;

a = 10;
b = 20;
c = a + b;

if (c == 30) {
  c = c + 1;
}

The generated assembly code (output.asm) will look like:


MOV R1, 10    ; a = 10
MOV R2, 20    ; b = 20
ADD R3, R1, R2  ; c = a + b
CMP R3, 30    ; if (c == 30)
JE .L1
JMP .END
.L1:
ADD R3, R3, 1  ; c = c + 1
.END:

How the Compiler Works

Lexer: Tokenizes the SimpleLang code, identifying keywords, operators, variables, and literals.
Parser: Converts the tokens into an Abstract Syntax Tree (AST), which represents the structure of the program.
Code Generator: Traverses the AST and produces assembly code for the 8-bit CPU.
Assembly Output: The generated assembly code can be executed on the 8-bit CPU simulator.

Contributing
If you wish to contribute to this project, feel free to fork the repository and submit pull requests. Any improvements or bug fixes are welcome.


### Key Points to Customize:
1. Replace `<your-repo-url>` with the actual URL of your repository.
2. If you modify the project structure or add/remove files, update the project structure section in the `README.md`.
3. If needed, add more detailed instructions for specific sections, such as advanced features or debugging.

This `README.md` will guide users through setting up the project, running the compiler, and using the 8-bit CPU simulator. Let me know if you'd like further customization!





Thank you........




