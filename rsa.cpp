#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    base %= mod;

    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {

    int p = 3, q = 11, n, z, d;
    n = p * q;
    z = (p - 1) * (q - 1);

    int e;
    cout << "Enter a number such that 1>num> " <<z<< " and it is coprime to " << z << ": ";
    cin >> e;

    if(gcd(e, z) != 1) {
        cout << "Error:" << e << " is not a coprime of " << z << endl;
        return 0;
    }

    d = modExp(e, z-1, z);

    int message;
    cout << "Enter message to be encrypted: ";
    cin >> message;

    int c = modExp(message, e, n);

    int dec = modExp(c, d, n);

    cout << "Encrypted Message: " << c << endl;
    cout << "Decrypted Message: " << dec << endl;

    return 0;
}
