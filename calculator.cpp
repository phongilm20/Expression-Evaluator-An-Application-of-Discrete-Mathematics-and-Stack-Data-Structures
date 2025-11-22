#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>
using namespace std;

int priority (char operation){
    if(operation == '+' || operation == '-'){ 
        return 1;
    }
    if(operation == '*' || operation == '/') {
        return 2;
    }
    return 0;
}

bool isOperation(char c){
    if(c == '+' || c=='-' || c == '*' || c== '/') return true;
    return false;
}

string toPostfix (string input){
    stack <char> operationSave;
    string output = "";

    for (int i = 0 ; i < input.length() ; i ++){
        char c = input[i];

        // Ignore any space
        if(c == ' ') continue;
        
        // if it is '/' we add to stack
        if (c == '('){
            operationSave.push(c);
        }
        else if (isdigit(c)){
            while( isdigit(c) && i < input.length() ){
                output += input[i];
                i++;
                c = input[i];
            }
            i--; // this decrease for turn back to the next possition after that number
            output += " "; // add a space for seperate the next number or anything
        }

        else if ( c == ')'){
            // Push all the operators to output and remove the '(' at the top of stack
            while( !operationSave.empty() && operationSave.top() != '(' ){
                output += operationSave.top(); // take the operation at the top of stack
                output += " "; // to sepearate 
                operationSave.pop(); // remove that operation 
            }
            operationSave.pop(); // remove '('
        }

        else if (isOperation(c)){
            while (!operationSave.empty() && priority(operationSave.top()) >= priority(c) ) {
                // Push operators to output 
                output += operationSave.top();
                output += " ";
                operationSave.pop();
            }
            operationSave.push(c);
        }
        // 5 + 5  - 2  * 3  + 1 

    }
    while (!operationSave.empty()){
        output += operationSave.top();
        output += " ";
        operationSave.pop();
    }
    return output;
    /* input : 5 + 5 - 2 * 3 + 1 
    stack :    +                -           * -                                         +                    +      
    output: 5    5 5   5 5 +       5 5 + 2            5 5 + 2 3         5 5 + 2 3 * -       5 5 + 2 3 * - 1     5 5 + 2 3 * 1 + 
    
    */

}

int calculatePostfix (string input){
    stack <int> stack; 
    string token;
    stringstream ss(input);
    for (; ss >> token ;){
        if(isdigit(token[0])){ //If it is the number 
            stack.push( stoi(token) ); // Move it to the stack and remove from the stack input
        }
        else{ // If it is operator 
            int b = stack.top();  //we take the second number 
            stack.pop(); // remove it from input
            int a = stack.top(); //we take the first number
            stack.pop(); //remove it from input

            // Calculation
            switch (token[0])
            {
            case '+':
                stack.push(a+b);
                break;
            case '-':
                stack.push(a-b);
                break;
            case '*':
                stack.push(a*b);
                break;
            case '/':
                stack.push(a/b);
                break;
            default:
                break;
            }
        }
        
    }
//  5 5 + 2 3 * - 1 + 
/**
 * stack: 5 5 + 2 3 * - 1 +             10 2 3 * - 1 +              10 6 - 1 +                 4 1 +           5
 *                              5 5 +                       3 2 *                      6 10 -          1 4 +
 * 
 * 
 */
    if (stack.empty()) {
        return 0; 
    }
    if (stack.size() != 1) { 
        return 0; 
    }
    
    return stack.top();
}

// Starting Caculation
int main () {
    string input;
    cout << "Type your calculation: ";
    getline (cin , input);
    
    string outputPostfix = toPostfix(input);
    // cout << "Postfix: " << outputPostfix << endl;

    int result = calculatePostfix(outputPostfix);
    cout << "Result: " << result << endl;


}


