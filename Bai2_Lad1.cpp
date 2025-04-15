#include <iostream>
using namespace std;

// Thu?t to�n Euclid th�?ng �? t�nh gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Thu?t to�n Euclid m? r?ng �? t?m x, y sao cho: a*x + b*y = gcd(a, b)
int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// H�m t�nh ngh?ch �?o modulo
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclid(a, m, x, y);
    if (g != 1) {
        // Kh�ng t?n t?i ngh?ch �?o modulo
        return -1;
    } else {
        // �?m b?o k?t qu? d��ng
        return (x % m + m) % m;
    }
}

// H�m main
int main() {
    int a, m;
    cout << "Nhap a, m: ";
    cin >> a >> m;

    if (gcd(a, m) != 1) {
        cout << "Khong ton tai nghich dao modulo vi gcd(a, m) != 1.\n";
        return 0;
    }

    int inv = mod_inverse(a, m);
    cout << "Nghich dao cua " << a << " mod " << m << " la: " << inv << endl;
    cout << "Kiem tra: " << a << " * " << inv << " % " << m << " = " << (1LL * a * inv % m) << endl;

    return 0;
}
