#include "vigenere.hpp"
#include <algorithm>
#include <iostream>

using namespace std;



void encryptAlphabetVignere(string& plaintext, string& ciphertext, string& key){

    int ascii_dec;

    ciphertext.clear();

    transform(key.begin(), key.end(), key.begin(), ::toupper);
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

    for (int i=0; i < plaintext.length() ; i++) {
        // Ignore encoding non-alphabet characters
        ascii_dec = plaintext[i];
        if (65<=ascii_dec && 90>=ascii_dec){
            ascii_dec = (char) (((int) plaintext[i] + (int) key[i%key.length()])%26 + 65);
            ciphertext.push_back(ascii_dec);
        }
    }

}
void decryptAlphabetVignere(string& ciphertext, string& plaintext, string& key){

    int ascii_dec;
    plaintext.clear();

    transform(key.begin(), key.end(), key.begin(), ::toupper);
    transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::toupper);

    for (int i=0; i < ciphertext.length() ; i++) {
        // Ignore non-alphabet characters
        ascii_dec = ciphertext[i];
        if (65<=ascii_dec && 90>=ascii_dec){
            ascii_dec = ((int) ciphertext[i] - (int) key[i%key.length()])%26;
            if (ascii_dec<0) ascii_dec += 26;
            plaintext.push_back((char) ascii_dec+65);
        }
    }

}


void encryptFullKeyAlphabetVignere(string& plaintext, string& ciphertext, string& key){
    int diff;
    if (key.length()  < plaintext.length()) {
        diff = plaintext.length() - key.length();
        for (int i = 0 ; i < diff ; i++){
            key.push_back(plaintext[i]);
        }
    }
    encryptAlphabetVignere(plaintext,ciphertext,key);
}

void decryptFullKeyAlphabetVignere(string& ciphertext, string& plaintext, string& key){
    
    // Assume that key length equals plaintext length
    // If not , then throw an exception

    if (key.length()!=ciphertext.length()){
        throw "Key length does not match ciphertext length !";
    }

    decryptAlphabetVignere(ciphertext,plaintext,key);
}

void encryptSuperAlphabetVignere(string& plaintext, string& ciphertext, string& key){

    char hash = (char) 0x00;
    char temp;

    encryptAlphabetVignere(plaintext,ciphertext, key);


    for (int i = 0; i < key.length() ; i++){
        hash = hash^key[i];
    }

    for (int i = 0 ; i < ciphertext.length() ; i++){
        temp = ciphertext[i];
        ciphertext[i] = ciphertext[(i+ (int)hash)%ciphertext.length()];
        ciphertext[(i+(int)hash)%ciphertext.length()] = temp;
    }


}
void decryptSuperAlphabetVignere(string& ciphertext, string& plaintext, string& key){
    
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


    decryptAlphabetVignere(ciphertext, plaintext, key);


}

void encryptAsciiVignere(string& plaintext, string& ciphertext, string& key){

    int ascii_dec;
    ciphertext.clear();
    for (int i=0 ; i < plaintext.length() ; i++){

        ascii_dec = ((int)plaintext[i] + (int) key[i%key.length()])%256;
        ciphertext.push_back((char) ascii_dec);
    }

}
void decryptAsciiVignere(string& ciphertext, string& plaintext, string& key){

    int mod_result;
    plaintext.clear();

    for (int i=0 ; i < ciphertext.length() ; i++){
        mod_result = ((int) ciphertext[i] - (int) key[i%key.length()])%256;
        if (mod_result < 0) mod_result += 256;
        plaintext.push_back((char) mod_result);
    }
}
