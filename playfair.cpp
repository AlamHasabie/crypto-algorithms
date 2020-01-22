/*
Playfair cipher
*/

#include "playfair.hpp"
#include <iostream>

using namespace std;



void convertToPlayfairString(string &text);
void encryptPlayfairCipher(string& plaintext, string& ciphertext, string&key){

    string table[5] = {"","","","",""};
    string plaintext_alphabet = string(plaintext);
    string bufferstring;

    // Assume table are all alphabets and capital

    toUpper(key);
    toAlphabet(key);

    ciphertext.clear();
    bufferstring.clear();

    for (int i=0; i < key.length() ; i++) {
        table[i/5].push_back(key[i]);
    }

    // Works on the alphabet version of the cipher
    // Later the words in the ciphertext is changed
    toAlphabet(plaintext_alphabet);
    toUpper(plaintext_alphabet);

    // Change the alphabet in the string
    // Assume no consecutive x

    convertToPlayfairString(plaintext_alphabet);
    cout << plaintext_alphabet << endl;


    



}
void decrpytPlayfairCipher(string& plaintext, string& ciphertext, string&key){



}


void convertToPlayfairString(string &text){

    string buffer = string(text);
    char c1, c2;

    text.clear();

    for (string::iterator i = buffer.begin(); i<buffer.end(); i++){
        c1 = *i;
        if (c1=='J') c1='I';
        i++;
        if(i==buffer.end()){
            text.push_back(c1);
            break;
        }
        c2 = *i;
        if (c1=='J') c1='I';

        text.push_back(c1);
        if (c1==c2) text.push_back('X');
        text.push_back(c2);
    }

    if (text.size()%2==1) text.push_back('X');

}

