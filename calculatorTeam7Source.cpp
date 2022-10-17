#include <iostream> 
#include <string> 
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


Operation askForOperation();

int main() {
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