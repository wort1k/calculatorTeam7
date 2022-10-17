#include <iostream>
#include <string>
#include <cassert>
using std::string;

enum Operation {
    Sum,
    Sub,
    Mult,
    Division,
    Mod,
    Exp = 100,
    UnaryPlus,
};

int sum(const int&, const int&);
int sub(const int&, const int&);
int mult(const int&, const int&);
int division(const int&, const int&);
int mod(const int&, const int&);
int unaryPlus(const int&);

double sum(const double&, const double&);
double sub(const double&, const double&);
double mult(const double&, const double&);
double division(const double&, const double&);
bool isUnary(Operation);
double applyUnaryOperation(Operation, double x);
double applyBinaryOperation(Operation, double a, double b);
double unaryPlus(const double&);

void printResult(double);
void askForNumber(const string&, int&);
void askForNumber(const string&, double&);
// —читаем, что бинарные - 0 - 99, унарные - 100+ 

void testSum();
void testMult();
void testSub();

Operation askForOperation();

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
        }

    }

    return 0;
}
int sum(const int& a, const int& b) {
    return a + b;
}
int sub(const int& a, const int& b) {
    return a - b;
}
int mult(const int& a, const int& b) {
    return a * b;
}
int division(const int& a, const int& b) {
    return a / b;
}
int mod(const int& a, const int& b) {
    return a % b;
}
int unaryPlus(const int& a){
    return a + 1;
}

// double arguements 
double sum(const double& a, const double& b) {
    return a + b;
}
double sub(const double& a, const double& b) {
    return a - b;
}
double mult(const double& a, const double& b) {
    return a * b;
}
double division(const double& a, const double& b) {
    return a / b;
}
double unaryPlus(const double& a) {
    return a + 1;
}
Operation askForOperation() {
    std::string menu = "Sum - 0, \nSub - 1, \nMult - 2,\nDivision - 3,\nMod - 4, \nExp - 5,\nUnaryPlus = 101 ";

    int numberOfOperation;

    std::cout << "operation?";
    std::cout << "enter number" << menu;
    std::cin >> numberOfOperation;

    //return (Operation) numberOfOperation; 
    return static_cast<Operation>(numberOfOperation);
}
bool isUnary(Operation operation) {
    return operation > 99 ? true : false;
};
double applyUnaryOperation(Operation operation, double x) {
    double result;
    switch (operation)
    {
    case UnaryPlus:
        result = unaryPlus(x);
        break;
    default:
        break;
    }
    return result;
};
double applyBinaryOperation(Operation operation, double a, double b) {

    double result;
    switch (operation) {
    case Sum: result = sum(a, b);
        break;
    case Sub: result = sub(a, b);
        break;
    case Mult: result = mult(a, b);
        break;
    case Division: result = division(a, b);
        break;
    default: break;
    }
    return result;
};
void printResult(double r) {
    std::cout << r << std::endl;
};
void askForNumber(const string& label, int& arg) {
    std::cout << label;
    std::cin >> arg;
}
void askForNumber(const string& label, double& arg) {
    std::cout << label;
    std::cin >> arg;
}

void testSum() {
    assert (sum(0, 0) == 0);
    assert (sum(2, 4) == 6);
    assert (sum(-6, -9) == -15);
    assert (sum(-6, 7) == 1);
    assert (sum(0, 7) == 7);
    assert (sum(0, -9) == -9);
    assert (sum(-1, 5) == 4);
    assert (sum(1, 2) == 3);
    assert (sum(0.3, 0.7) == 1.0);
}
void testMult() {
    assert(mult(0, 7) == 0);
    assert(mult(2, 3) == 6);
    assert(mult(-6, 4) == -24);
    assert(mult(-2, -3) == 6);
    assert(mult(-1, 7) == -7);
    assert(mult(1, 3) == 3);
    assert(mult(1.2, 1.3) == 1.56);
    
}
void testSub() {
    assert(sub(0, 3) == -3);
    assert(sub(1, 3) == -2);
    assert(sub(-2, 3) == -5);
    assert(sub(7, 4) == -3);
    assert(sub(-1, -3) == 2);
    assert(sub(-5, -2) == -3);
}