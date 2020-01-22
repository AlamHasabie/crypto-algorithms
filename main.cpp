#include "vigenere.hpp"
#include "display.hpp"

using namespace std;


int main(){

    string in_plaintext;
    string ciphertext;
    string key;

    getline(cin, in_plaintext);
    getline(cin, key);

    encryptAlphabetVigenere(in_plaintext,ciphertext,key);
    displayPlainCiphertext(ciphertext);
    displayNoSpaceCiphertext(ciphertext);
    displayBlockCiphertext(ciphertext);
    
    decryptAlphabetVigenere(ciphertext,in_plaintext,key);
    cout << in_plaintext << endl;


    return 0;
}
