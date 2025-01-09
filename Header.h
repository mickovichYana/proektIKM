#pragma once
#ifndef HEADER_H 
#define HEADER_H
#include <string>
using namespace std;

// Функция для умножения большого числа (в виде строки) на целое число
string multiply(const string& a, int b);

// Функция для вычисления a в степени m
string power(int a, int m);

// Функция для сравнения двух чисел 
int compare(const string& a, const string& b);

// Функция для вычитания двух чисел 
string subtract(const string& a, const string& b);

#endif 

