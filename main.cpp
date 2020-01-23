#include "vigenere.hpp"
#include "display.hpp"
#include "playfair.hpp"

using namespace std;


int main(){

    string in_plaintext;
    string ciphertext;
    string key;

    getline(cin, in_plaintext);
    getline(cin, key);

    encryptPlayfairCipher(in_plaintext, ciphertext, key);
    displayPlainCiphertext(ciphertext);
    displayNoSpaceCiphertext(ciphertext);
    displayBlockCiphertext(ciphertext);
    decryptPlayfairCipher(ciphertext,in_plaintext,key);
    displayPlainCiphertext(in_plaintext);
    displayNoSpaceCiphertext(in_plaintext);
    displayBlockCiphertext(in_plaintext);


    


    return 0;
}
