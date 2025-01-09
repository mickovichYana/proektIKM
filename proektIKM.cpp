#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main() {
    int a, b;
    int m, n;

    // Цикл для ввода a
    while (true) {
        cout << "Введите a (0<= a <= 40000): ";
        cin >> a;
        if (cin.good() && a >= 0 && a <= 40000 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод. Пожалуйста, введите a снова." << endl;
        }
    }

    // Цикл для ввода b
    while (true) {
        cout << "Введите b (0<= b <= 40000): ";
        cin >> b;
        if (cin.good() && b >= 0 && b <= 40000 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод. Пожалуйста, введите b снова." << endl;
        }
    }

    // Цикл для ввода m
    while (true) {
        cout << "Введите m (0<= m <= 10): ";
        cin >> m;
        if (cin.good() && m >= 0 && m <= 10 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод. Пожалуйста, введите m снова." << endl;
        }
    }

    // Цикл для ввода n
    while (true) {
        cout << "Введите n (0<= n <= 10): ";
        cin >> n;
        if (cin.good() && n >= 0 && n <= 10 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод. Пожалуйста, введите n снова." << endl;
        }
    }

    // Рассчитываю a^m и b^n
    string a_power_m = power(a, m);
    string b_power_n = power(b, n);

    cout << "Результат a^m: " << a_power_m << endl;
    cout << "Результат b^n: " << b_power_n << endl;

    // Сравниваю и вывожу результат
    int comparison = compare(a_power_m, b_power_n);
    if (comparison > 0) {
        string difference = subtract(a_power_m, b_power_n);
        cout << a_power_m << " больше " << b_power_n << " на " << difference << endl;
    }
    else if (comparison < 0) {
        string difference = subtract(b_power_n, a_power_m);
        cout << b_power_n << " больше " << a_power_m << " на " << difference << endl;
    }
    else {
        cout << "a^m и b^n равны " << a_power_m << endl;
    }

    return 0;
}

