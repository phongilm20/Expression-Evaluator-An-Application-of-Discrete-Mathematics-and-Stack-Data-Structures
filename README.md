# Expression Evaluator — An Application of Discrete Mathematics and Stack Data Structures

This project implements a full arithmetic **expression evaluator in C++**, applying concepts from **Discrete Mathematics** and **Stack data structures**.  
It supports Infix → Postfix conversion using the **Shunting Yard Algorithm** and evaluates the postfix expression using a stack.  
The project demonstrates how arithmetic expressions are parsed and computed programmatically.

---

## Features
- Infix → Postfix conversion  
- Postfix evaluation  
- Supports operators: +, -, *, /, ^  
- Handles parentheses and multi-digit numbers  
- Detects invalid expressions  
- Fully modular C++ implementation with functions for tokenization, conversion, and evaluation

---

## How It Works

### 1. Tokenization  
The input expression is scanned and split into numbers, operators, and parentheses.

### 2. Infix → Postfix Conversion (Shunting Yard Algorithm)  
Uses operator precedence, associativity, and a stack to generate postfix notation.

### 3. Postfix Evaluation  
Evaluates the postfix tokens using a stack to compute the final numeric result.

---

## Operator Precedence Table
| Operator | Precedence | Associativity |
|---------|------------|---------------|
| ^       | 3          | Right         |
| * /     | 2          | Left          |
| + -     | 1          | Left          |

---

## Example Usages (copy & paste directly)

### Example 1
**Input:**  
3 + 4 * 2 / (1 - 5) ^ 2  
**Output:**  
3.5

### Example 2
**Input:**  
(10 + 2) * (8 - 3)  
**Output:**  
60

### Example 3
**Input:**  
100 / (5 * 5)  
**Output:**  
4

### Example 4
**Input:**  
2^3 * (4 + 6) - 7 / (3 - 2)  
**Output:**  
79

---

## Project Structure
Expression-Evaluator/  
│── calculator.cpp  
│── README.md  

---

## Running the Program

Compile:  
```bash
g++ calculator.cpp -o calculator
