#include <iostream>
#include <string>
using namespace std;

// �㭪�� ��� 㬭������ ���� �ᥫ 
string multiply(const string& a, int b) {
    int perenos = 0; 
    string result = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int prod = (a[i] - '0') * b + perenos; // ��������� ������ ����
        perenos = prod / 10; 
        result.insert(result.begin(), (prod % 10) + '0'); // �������� � १�����
    }
    while (perenos) {
        result.insert(result.begin(), (perenos % 10) + '0'); // �������� ��७��, �᫨ ����
        perenos /= 10; 
    }
    return result;
}

// �㭪�� ��� ���᫥��� a^m 
string power(int a, int m) {
    string result = "1"; 
    for (int i = 0; i < m; i++) {
        result = multiply(result, a); // ������� ⥪�饥 ���祭�� �� a
    }
    return result;
}

// �㭪�� ��� �ࠢ����� ������ �ᥫ � ���� ��ப
int compare(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() > b.size() ? 1 : -1; // �ࠢ����� �����
    }
    return a > b ? 1 : (a < b ? -1 : 0); // �ࠢ����� ��ப�
}

// �㭪�� ��� ���⠭�� ���� �ᥫ � ���� ��ப
string subtract(const string& a, const string& b) {
    string result = "";
    int borrow = 0; 
    int A = a.size();
    int B = b.size();

    // ��稭�� ���⠭�� � ���� ��ப
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

    // ������ �������� ����騥 �㫨
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result.empty() ? "0" : result; 
}

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

