#include "calculatorTeam7.h"
#include <iostream>

int main() {
    testSum();
    testMult();
    testSub();
    std::string varType;
    Operation operation;

    while (true) {
        std::cout << "type? ";
        std::cin >> varType;
        if (varType == "double") {
            operation = askForOperation();
            double result;
            if (isUnary(operation)) {
                double x;
                askForNumber("Input the number ", x);
                result = applyUnaryOperation(operation, x);
            }
            else {
                double a;
                askForNumber("Input the 1st number ", a);
                double b;
                askForNumber("Input the 2nd number ", b);
                result = applyBinaryOperation(operation, a, b);
            }
            printResult(result);
        } else if (varType == "integer" || varType == "int") {
            operation = askForOperation();
           int result;
            if (isUnary(operation)) {
                int x;
                askForNumber("Input the number ", x);
                result = applyUnaryOperation(operation, x);
            }
            else {
                int a;
                askForNumber("Input the 1st number ", a);
                int b;
                askForNumber("Input the 2nd number ", b);
                result = applyBinaryOperation(operation, a, b);
            }
            printResult(result);
        }
        else if ( varType == "bool") {
            operation = askForOperation();
            bool result;
            if (isUnary(operation)) {
                int x;
                askForNumber("Input the number ", x);
                result = applyUnaryOperation(operation, x);
            }
            else {
                int a;
                askForNumber("Input the 1st number ", a);
                int b;
                askForNumber("Input the 2nd number ", b);
                result = applyBinaryOperation(operation, a, b);
            }
            printResult(result);
        }

    }

    return 0;
}