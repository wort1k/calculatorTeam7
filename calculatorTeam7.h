#pragma once
#include <string>
using std::string;

enum Operation {
    Sum,
    Sub,
    Mult,
    Division,
    Mod,
    BitwiseAnd,
    BitwiseExclusiveOr,
    BitwiseDisjunctionNegation,
    RightShift,
    Сonjunction,
    ExclusiveOr,
    DisjunctionNegation,
    Exp = 100,
    UnaryPlus,
    UnaryMinus,
    Sqrt,
};

int sum(const int&, const int&);
int sub(const int&, const int&);
int mult(const int&, const int&);
int division(const int&, const int&);
int mod(const int&, const int&);
int unaryPlus(const int&);
int unaryMinus(const int&);
int bitwiseAnd(const int&, const int&);
int bitwiseExclusiveOr(const int&, const int&);
int rightShift(const int&, const int&);
int bitwiseDisjunctionNegation(const int&, const int&);

bool conjunction( const bool&, const bool&);
bool exclusiveOr(const bool&, const bool&);
bool disjunctionNegation(const bool&, const bool&);

double sum(const double&, const double&);
double sub(const double&, const double&);
double mult(const double&, const double&);
double division(const double&, const double&);
bool isUnary(Operation);
double applyUnaryOperation(Operation, double x);
double applyBinaryOperation(Operation, double a, double b);
double unaryPlus(const double&);
double unaryMinus(const double&);
double CalcSqrt(const double&);

void printResult(double);
void printResult(int);
void printResult(bool);
void askForNumber(const string&, int&);
void askForNumber(const string&, double&);
// Считаем, что бинарные - 0 - 99, унарные - 100+ 

void testSum();
void testMult();
void testSub();

Operation askForOperation();