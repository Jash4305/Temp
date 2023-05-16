/*
Person Romil(x)
private key = babu, public key = romil
x = (jash_publicKey ^ romil_privatekey) % jash_publickey
person Jash (y)
private key = rabbit, public key = Jash
y = (jash_public ^ jash_privatekey) % romil_public

secretKey_romil(ka) = y ^ romil_privatekey % romil_publickey
secretkey_jash(kb) = x ^ jash_privatekey % romil_publickey

if (ka == kb)

*/

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main() {
    int p1PrivateKey,p2PrivateKey;
    // taking private key input
    cout<<"Enter the private key of Person one : ";
    cin>>p1PrivateKey;
    cout<<"Enter the private key of Person two : ";
    cin>>p2PrivateKey;
    cout<<"Generating public keys..\n";
    int p1PublicKey = 23;
    int p2PublicKey = 9;

    int x = (p2PublicKey^p1PrivateKey) % p1PublicKey;
    int y = (p2PublicKey^p2PrivateKey) % p1PublicKey;

    int ka = (y^p1PrivateKey) % p1PublicKey;
    int kb = (x^p2PrivateKey) % p1PublicKey;

    cout<<"Person One Secret Key is "<<ka<<endl;
    cout<<"Person Two Secret Key is "<<kb;
    return 0;
}
