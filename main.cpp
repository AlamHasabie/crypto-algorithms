#include "vigenere.hpp"
#include <iostream>

using namespace std;


int main(){

    string in_plaintext;
    string key;

    getline(cin, in_plaintext);
    getline(cin, key);

    encryptAsciiVignere(in_plaintext,key);
    decryptAsciiVignere(in_plaintext,key);

    encryptAlphabetVignere(in_plaintext,key);
    decryptAlphabetVignere(in_plaintext,key);

    return 0;
}
