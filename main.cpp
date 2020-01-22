#include "vigenere.hpp"
#include <iostream>

using namespace std;


int main(){

    string in_plaintext;
    string ciphertext;
    string key;

    getline(cin, in_plaintext);
    getline(cin, key);

    encryptFullVigenere(in_plaintext, ciphertext ,key);
    cout << ciphertext << endl;
    decryptFullVigenere(ciphertext, in_plaintext, key);
    cout << in_plaintext << endl;


    return 0;
}
