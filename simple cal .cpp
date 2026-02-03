#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the Internship Calculator!" << endl;

    double num1, num2, result;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
                return 0;
            }
            break;
        default:
            cout << "Invalid operator! Use +, -, *, or /." << endl;
            return 0;
    }

    cout << "The result of " << num1 << " " << op << " " << num2 << " = " << result << endl;

    return 0;
}
