#include "calculatorTeam7.h"
#include <iostream>
#include <string>
#include <cassert>


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

int unaryMinus(const int& a) {
    return a - 1;
}

int bitwiseAnd(const int& a, const int& b) {
    return a & b;
}

int bitwiseExclusiveOr(const int& a, const int& b) {
    return a ^ b;
}

int rightShift(const int& a, const int& b) {
    return a >> b;
}

int bitwiseDisjunctionNegation(const int& a, const int& b) {
    return ~(a | b); //TODO
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

double unaryMinus(const double& a) {
    return a - 1;
}

double CalcSqrt(const double& a) {
    return sqrtf(a);
}

// bool arguements
bool conjunction(const bool& a, const bool& b) {
    return  a && b;
}

bool exclusiveOr(const bool& a, const bool& b) {
    return a ^ b;
}

bool disjunctionNegation(const bool& a, const bool& b) {
    return !(a || b);
}

Operation askForOperation() {
    std::string menu = "Sum - 0, \nSub - 1, \nMult - 2,\nDivision - 3,\nMod - 4, \nBitwiseAnd - 5,";
    menu += " \nBitwiseExclusiveOr - 6, \nBitwiseDisjunctionNegation - 7, \nRightShift - 8, \nConjunction - 9, \nExclusiveOr - 10,";
    menu += " \nDisjunctionNegation - 11";
    menu += " \nExp - 100, \n\nUnaryPlus - 101, \nUnaryMinus - 102, \nSqrt - 103, \n";

    int numberOfOperation;

    std::cout << "operation?";
    std::cout << "enter number" << menu;
    std::cin >> numberOfOperation;

    //return (Operation) numberOfOperation; 
    return static_cast<Operation>(numberOfOperation);
}
bool isUnary(Operation operation) {
    return operation > 99 ? true : false;
}

double applyUnaryOperation(Operation operation, double x) {
    double result;
    switch (operation)
    {
    case Exp:
        break;
    case UnaryPlus: result = unaryPlus(x);
        break;
    case UnaryMinus: result = unaryMinus(x);
        break;
    case Sqrt: result = CalcSqrt(x);
        break;
    default:
        break;
    }
    return result;
}

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
    case Mod: result = mod(a, b);
        break;
    case BitwiseAnd: result = bitwiseAnd(a, b);
        break;
    case BitwiseExclusiveOr: result = bitwiseExclusiveOr(a, b);
        break;
    case BitwiseDisjunctionNegation: result = bitwiseDisjunctionNegation(a, b);
        break;
    case RightShift: result = rightShift(a, b);
        break;
    case Ñonjunction: result = conjunction(a, b);
        break;
    case ExclusiveOr: result = exclusiveOr(a, b);
        break;
    case DisjunctionNegation: result = disjunctionNegation(a, b);
        break;
    default:
        break;
    }
    return result;
}

void printResult(double r) {
    std::cout << r << std::endl;
}

void printResult(int r) {
    std::cout << r << std::endl;
}

void printResult(bool r) {
    if (r) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

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
    assert(sub(7, 4) == 3);
    assert(sub(-1, -3) == 2);
    assert(sub(-5, -2) == -3);
}
