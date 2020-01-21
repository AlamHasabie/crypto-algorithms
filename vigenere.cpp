#include "vigenere.hpp"
#include <algorithm>
#include <iostream>

using namespace std;



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

void encryptSuperAlphabetVignere(std::string& plaintext, std::string& key){

    char hash = (char) 0x00;
    char temp;

    encryptAlphabetVignere(plaintext,key);

    for (int i = 0; i < key.length() ; i++){
        hash = hash^key[i];
    }

    for (int i = 0 ; i < plaintext.length() ; i++){
        temp = plaintext[i];
        plaintext[i] = plaintext[(i+ (int)hash)%plaintext.length()];
        plaintext[(i+(int)hash)%plaintext.length()] = temp;
    }

    cout << plaintext << endl;

}
void decryptSuperAlphabetVignere(std::string& ciphertext, std::string& key){
    
    char hash = (char) 0x00;
    char temp;


    for (int i = 0; i < key.length() ; i++){
        hash = hash^key[i];
    }

    for (int i=ciphertext.length()-1 ; i >= 0; i--){
        temp = ciphertext[i];
        ciphertext[i] = ciphertext[(i+(int)hash)%ciphertext.length()];
        ciphertext[(i+(int)hash)%ciphertext.length()] = temp;
    }

    cout << ciphertext << endl;

    decryptAlphabetVignere(ciphertext,key);


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
