/**
Header for Vigenere encrypt/decypt and its variations

Author : alamhasabie

**/

#include <string>


#ifndef VIGENERE_H
#define VIGENERE_H

void encryptAlphabetVignere(std::string& plaintext, std::string& key);
void decryptAlphabetVignere(std::string& ciphertext, std::string& key);
void encryptAsciiVignere(std::string& plaintext, std::string& key);
void decryptAsciiVignere(std::string& ciphertext, std::string& key);




#endif