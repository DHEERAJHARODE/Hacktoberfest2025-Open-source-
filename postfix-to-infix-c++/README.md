# Postfix to Infix Converter (C++)

## Description
This program converts a postfix (Reverse Polish Notation) expression
to its equivalent infix expression using a stack.

It demonstrates stack-based expression parsing, operator/operand handling,
and outputs fully parenthesized infix expressions.

## How to Compile
```bash
g++ postfix_to_infix.cpp -o postfix_to_infix
```
## How to Run
```bash
./postfix_to_infix
```
## Example

Input: `AB+C*`
Output: `((A + B) * C)`

## Features
- Stack-based implementation
- Fully parenthesized infix expression
- Handles single-letter/numeric operands