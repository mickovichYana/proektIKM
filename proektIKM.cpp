#include <iostream>
#include <string>
using namespace std;

// Функция для умножения двух чисел 
string multiply(const string& a, int b) {
    int perenos = 0; 
    string result = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int prod = (a[i] - '0') * b + perenos; // Умножение каждой цифры
        perenos = prod / 10; 
        result.insert(result.begin(), (prod % 10) + '0'); // Добавляю к результату
    }
    while (perenos) {
        result.insert(result.begin(), (perenos % 10) + '0'); // Добавляю перенос, если есть
        perenos /= 10; 
    }
    return result;
}

// Функция для вычисления a^m 
string power(int a, int m) {
    string result = "1"; 
    for (int i = 0; i < m; i++) {
        result = multiply(result, a); // Умножаю текущее значение на a
    }
    return result;
}

// Функция для сравнения больших чисел в виде строк
int compare(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() > b.size() ? 1 : -1; // Сравниваю длину
    }
    return a > b ? 1 : (a < b ? -1 : 0); // Сравниваю строки
}

// Функция для вычитания двух чисел в виде строк
string subtract(const string& a, const string& b) {
    string result = "";
    int borrow = 0; 
    int A = a.size();
    int B = b.size();

    // Начинаю вычитание с конца строк
    for (int i = 0; i < A; ++i) {
        int digitA = a[A - 1 - i] - '0'; 
        int digitB = (i < B) ? b[B - 1 - i] - '0' : 0;
        int diff = digitA - digitB - borrow; 
        if (diff < 0) {
            diff += 10; 
            borrow = 1; 
        }
        else {
            borrow = 0;
        }
        result.insert(result.begin(), diff + '0'); 
    }

    // Удаляю возможные ведущие нули
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result.empty() ? "0" : result; 
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
            cin.clear();
            cin.ignore(10000, '\n');
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

