#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main() {
    int a, b;
    int m, n;

    // ���� ��� ����� a
    while (true) {
        cout << "������ a (a <= 40000): ";
        cin >> a;
        if (cin.good() && a >= 0 && a <= 40000 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "�����४�� ����. ��������, ������ a ᭮��." << endl;
        }
    }

    // ���� ��� ����� b
    while (true) {
        cout << "������ b (b <= 40000): ";
        cin >> b;
        if (cin.good() && b >= 0 && b <= 40000 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "�����४�� ����. ��������, ������ b ᭮��." << endl;
        }
    }

    // ���� ��� ����� m
    while (true) {
        cout << "������ m (m <= 10): ";
        cin >> m;
        if (cin.good() && m >= 0 && m <= 10 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "�����४�� ����. ��������, ������ m ᭮��." << endl;
        }
    }

    // ���� ��� ����� n
    while (true) {
        cout << "������ n (n <= 10): ";
        cin >> n;
        if (cin.good() && n >= 0 && n <= 10 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "�����४�� ����. ��������, ������ n ᭮��." << endl;
        }
    }

    // ������뢠� a^m � b^n
    string a_power_m = power(a, m);
    string b_power_n = power(b, n);

    cout << "������� a^m: " << a_power_m << endl;
    cout << "������� b^n: " << b_power_n << endl;

    // �ࠢ����� � �뢮�� १����
    int comparison = compare(a_power_m, b_power_n);
    if (comparison > 0) {
        string difference = subtract(a_power_m, b_power_n);
        cout << a_power_m << " ����� " << b_power_n << " �� " << difference << endl;
    }
    else if (comparison < 0) {
        string difference = subtract(b_power_n, a_power_m);
        cout << b_power_n << " ����� " << a_power_m << " �� " << difference << endl;
    }
    else {
        cout << "a^m � b^n ࠢ�� " << a_power_m << endl;
    }

    return 0;
}

