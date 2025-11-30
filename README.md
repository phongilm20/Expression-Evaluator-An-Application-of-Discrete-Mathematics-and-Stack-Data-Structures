# Expression Evaluator — An Application of Discrete Mathematics and Stack Data Structures

This project implements a full arithmetic expression evaluator using Discrete Mathematics concepts and Stack Data Structures. It supports Infix → Postfix conversion using the Shunting Yard Algorithm and Postfix evaluation using a stack. The project demonstrates how compilers interpret mathematical expressions with operator precedence, associativity, and parenthesis handling.

---

## Features
- Infix → Postfix conversion  
- Postfix evaluation  
- Supports +, -, *, /, ^  
- Handles parentheses and multi-digit numbers  
- Detects invalid expressions  
- Fully modular OOP structure (Tokenizer, Parser, Evaluator)

---

## How It Works

### 1. Tokenization  
The input string is split into numbers, operators, and parentheses.

### 2. Infix → Postfix Conversion (Shunting Yard Algorithm)  
Uses operator precedence, associativity, and stacks to output postfix notation.

### 3. Postfix Evaluation  
A stack-based evaluator processes postfix tokens to compute the final numeric value.

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
Input:
3 + 4 * 2 / (1 - 5) ^ 2  
Output:
3.5

### Example 2
Input:
(10 + 2) * (8 - 3)  
Output:
60

### Example 3
Input:
100 / (5 * 5)  
Output:
4

### Example 4
Input:
2^3 * (4 + 6) - 7 / (3 - 2)  
Output:
79

---

## Project Structure
ExpressionEvaluator/  
│── src/  
│   ├── Tokenizer.java  
│   ├── InfixToPostfix.java  
│   ├── PostfixEvaluator.java  
│   ├── ExpressionEvaluator.java  
│── README.md  

---

## Running the Program

Compile:
javac ExpressionEvaluator.java

Run:
java ExpressionEvaluator

---

## Author
Levi-Phong  
Email: phongilm20@gmail.com  
GitHub: https://github.com/phongilm20
