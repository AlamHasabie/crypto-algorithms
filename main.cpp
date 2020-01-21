#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



void encryptAlphabetVignere(string& plaintext, string& key);
void decryptAlphabetVignere(string& ciphertext, string& key);
void encryptAsciiVignere(string &plaintext, string&key);
void decryptAsciiVignere(string& ciphertext, string& key);
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



// Input byte character (ASCII)
// produces no output, but change the inputs to uppercase
// Throw exception in case of invalid character (beyond [a-zA-Z])

void encryptAlphabetVignere(string& plaintext, string& key){

    int ascii_dec;

    transform(key.begin(), key.end(), key.begin(), ::toupper);
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

    for (int i=0; i < plaintext.length() ; i++) {
        // Ignore encoding non-alphabet characters
        ascii_dec = plaintext[i];
        if (65<=ascii_dec && 90>=ascii_dec){
            plaintext[i] = (char) (((int) plaintext[i] + (int) key[i%key.length()])%26 + 65);
        }
    }

    cout << plaintext << endl;


}


// Input byte character (ASCII)
// produces no output, but change the inputs to uppercase
// Throw exception in case of invalid character (beyond [a-zA-Z])
void decryptAlphabetVignere(string& ciphertext, string& key){

    int ascii_dec;

    transform(key.begin(), key.end(), key.begin(), ::toupper);
    transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::toupper);

    for (int i=0; i < ciphertext.length() ; i++) {
        // Ignore encoding non-alphabet characters
        ascii_dec = ciphertext[i];
        if (65<=ascii_dec && 90>=ascii_dec){
            ascii_dec = ((int) ciphertext[i] - (int) key[i%key.length()])%26;
            if (ascii_dec<0) ascii_dec += 26;
            ciphertext[i] = (char) ascii_dec+65;
        }
    }

    cout << ciphertext << endl;

}

void encryptAsciiVignere(string& plaintext, string& key){

    for (int i=0 ; i < plaintext.length() ; i++){
        plaintext[i] = (char) ((int)plaintext[i] + (int) key[i%key.length()])%256;
    }

    cout << plaintext << endl;
}

void decryptAsciiVignere(string& ciphertext, string& key){

    int mod_result;
    for (int i=0 ; i < ciphertext.length() ; i++){
        mod_result = ((int) ciphertext[i] - (int) key[i%key.length()])%256;
        if (mod_result < 0) mod_result += 256;
        ciphertext[i] = (char) mod_result;
    }

    cout << ciphertext << endl;


}