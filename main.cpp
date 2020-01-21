#include "vigenere.hpp"
#include <iostream>

using namespace std;


int main(){

    string in_plaintext;
    string ciphertext;
    string key;

    getline(cin, in_plaintext);
    getline(cin, key);

    encryptAsciiVignere(in_plaintext, ciphertext ,key);
    cout << ciphertext << endl;
    decryptAsciiVignere(ciphertext, in_plaintext, key);
    cout << in_plaintext << endl;


    return 0;
}
