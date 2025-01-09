#include "Header.h"
#include <string>
using namespace std; 

string multiply(const string& a, int b) {
    int perenos = 0;
    string result = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int prod = (a[i] - '0') * b + perenos; // ��������� ������ �����
        perenos = prod / 10;
        result.insert(result.begin(), (prod % 10) + '0');// �������� � ����������
    }
    while (perenos) {
        result.insert(result.begin(), (perenos % 10) + '0');// �������� �������, ���� ����
        perenos /= 10;
    }
    return result;
}

string power(int a, int m) {
    string result = "1";
    for (int i = 0; i < m; i++) {
        result = multiply(result, a); // ������� ������� �������� �� a
    }
    return result;
}

int compare(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() > b.size() ? 1 : -1;// ��������� �����
    }
    return a > b ? 1 : (a < b ? -1 : 0);// ��������� ������
}

string subtract(const string& a, const string& b) {
    string result = "";
    int borrow = 0;
    int A = a.size();
    int B = b.size();

    for (int i = 0; i < A; ++i) {// ������� ��������� � ����� �����
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

    // ������ ��������� ������� ����
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result.empty() ? "0" : result;
}
