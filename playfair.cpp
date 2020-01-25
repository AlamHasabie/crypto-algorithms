/*
Playfair cipher
*/

#include "playfair.hpp"
#include <iostream>

using namespace std;



void convertToPlayfairString(string &text);
int alphabetIndex(char* table, char c);
void encryptPlayfairCipher(string& plaintext, string& ciphertext, string&key){

    char table[25];
    string plaintext_alphabet = string(plaintext);
    string::iterator it1,it2;
    string bufferstring;

    int idx1,idx2;

    // Assume table are all alphabets and capital

    toUpper(key);
    toAlphabet(key);

    ciphertext.clear();
    bufferstring.clear();

    for (int i = 0 ; i < 25 ; i++) {
        table[i] = key[i];
    }

    // Works on the alphabet version of the cipher
    // Later the words in the ciphertext is changed
    toAlphabet(plaintext_alphabet);
    toUpper(plaintext_alphabet);

    // Change the alphabet in the string
    // Assume no consecutive x

    convertToPlayfairString(plaintext_alphabet);
    cout << plaintext_alphabet << endl;
    
    for (string::iterator i = plaintext_alphabet.begin() ; i< plaintext_alphabet.end(); i+=2){
        idx1 = alphabetIndex(table,*i);
        idx2 = alphabetIndex(table,*(i+1));

        // Check for Playfair cipher conditions
        // Assume that all cases are exclusive (and it should be)

        if ((idx1/5)==(idx2/5)){
            *i = table[(idx1+1)%5];
            *(i+1) = table[(idx2+1)%5];
        } else if ((idx1%5)==(idx2%5)){
            *i = table[(idx1+5)%25];
            *(i+1) = table[(idx2+5)%25];
        } else {
            *i = table[5*(idx1/5) + (idx2%5)];
            *(i+1) = table[5*(idx2/5) + (idx1%5)];
        }
    }

    // put together ciphertext
    ciphertext += plaintext_alphabet;


}

// Assume no symbolic characters, 
// Assume capitalized letter,
// i.e. valid Playfair string
void decryptPlayfairCipher(string& ciphertext, string& plaintext, string& key){
    
    int idx1,idx2;
    toAlphabet(ciphertext);
    toUpper(ciphertext);
    toAlphabet(key);
    toUpper(key);
    plaintext.clear();

    char table[25];

    for (int i = 0 ; i < 25 ; i++) {
        table[i] = key[i];
    }


    for (string::iterator i = ciphertext.begin(); i < ciphertext.end(); i+=2){
        idx1 = alphabetIndex(table, *i);
        idx2 = alphabetIndex(table, *(i+1));
        
        if ((idx1/5)==(idx2/5)){
            plaintext.push_back(table[(idx1+4)%5]);
            plaintext.push_back(table[(idx2+4)%5]);
        } else if ((idx1%5)==(idx2%5)){
            plaintext.push_back(table[(idx1+20)%25]);
            plaintext.push_back(table[(idx2+20)%25]);
        } else {
            plaintext.push_back(table[5*(idx1/5) + (idx2%5)]);
            plaintext.push_back(table[5*(idx2/5) + (idx1%5)]);
        }

    }
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


int alphabetIndex(char* table, char c){
    int idx = 0;
    while(idx<25){
        if(table[idx]==c) break;
        idx++;
    }
    return idx;
}

