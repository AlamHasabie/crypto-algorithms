/*
Playfair cipher
*/

#include "playfair.hpp"

using namespace std;


void encryptPlayfairCipher(string& plaintext, string& ciphertext, string&key){

    string table[5] = {"","","","",""};
    string buffer_string;
    bool stop_iterate;

    for (int i=0; i < key.length() ; i++) {
        table[i/5].push_back(key[i]);
    }

    stop_iterate = false;
    while(!stop_iterate){
        



    }

    



}
void decrpytPlayfairCipher(string& plaintext, string& ciphertext, string&key){



}

