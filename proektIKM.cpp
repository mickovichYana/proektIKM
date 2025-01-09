#include <iostream>
using namespace std; 

// Функция для вычисления a^m 
unsigned long long power(int a, int m) {
    if (m == 0) { // Любое число в степени 0 = 1
        return 1; 
    }

    unsigned long long result = 1; 
    for (int i = 0; i < m; i++) { 
        result *= a;
    }
    return result; 
}

int main() {
    int a, b; 
    int m, n; 

    // Цикл для ввода a
    while (true) {
        cout << "Введите a (a <= 40000): "; 
        cin >> a; 
        if (cin.good() && a >= 0 && a <= 40000 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear(); // Сбрасываю флаг ошибки
            cin.ignore(10000, '\n'); // Игнорирую неправильный ввод
            cout << "Некорректный ввод. Пожалуйста, введите a снова." << endl;
        }
    }

    // Цикл для ввода b
    while (true) {
        cout << "Введите b (b <= 40000): "; 
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
        cout << "Введите m (m <= 10): "; 
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
        cout << "Введите n (n <= 10): "; 
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
    unsigned long long a_power_m = power(a, m);
    unsigned long long b_power_n = power(b, n);
    cout << "Результат a^m: " << a_power_m << endl;
    cout << "Результат b^n: " << b_power_n << endl;

    // Сравниваю и вывожу результат
    if (a_power_m > b_power_n) {
        cout << a_power_m << " больше " << b_power_n << " на " << (a_power_m - b_power_n) << endl;
    }
    else if (a_power_m < b_power_n) {
        cout << b_power_n << " больше " << a_power_m << " на " << (b_power_n - a_power_m) << endl;
    }
    else {
        cout << "a^m и b^n равны " << a_power_m << endl; 
    }

    return 0; 
}
