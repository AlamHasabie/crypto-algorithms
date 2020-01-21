#include "vigenere.hpp"
#include <iostream>

using namespace std;


int main(){

    string in_plaintext;
    string key;

    getline(cin, in_plaintext);
    getline(cin, key);

    encryptSuperAlphabetVignere(in_plaintext,key);
    decryptSuperAlphabetVignere(in_plaintext,key);


    return 0;
}
