#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;

        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;

        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;

        case '/':
            if (num2 == 0) {
                cout << "Error! Division by zero is not allowed." << endl;
                return 0;
            }
            result = num1 / num2;
            cout << "Result: " << result << endl;
            break;

        default:
            cout << "Error! Invalid operation." << endl;
            return 0;
    }

    return 0;
}