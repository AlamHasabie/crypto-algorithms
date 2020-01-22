/**
Header for Vigenere encrypt/decypt and its variations

Author : alamhasabie

**/

#include <string>


#ifndef VIGENERE_H
#define VIGENERE_H

// Standard Vigenere
void encryptAlphabetVignere(std::string& plaintext, std::string& ciphertext, std::string& key);
void decryptAlphabetVignere(std::string& ciphertext, std::string& plaintext, std::string& key);

// Super-encryption standard Vigenere
// Adding an additional superposition cryption

/*

Superposition algorithm :
1. Create a XOR hash number from the key, for example k
2. For every character i in [0..n] , trade string[i] with string [i+k]

*/
void encryptSuperAlphabetVignere(std::string& plaintext, std::string& ciphertext, std::string& key);
void decryptSuperAlphabetVignere(std::string& ciphertext, std::string& plaintext, std::string& key);

// auto-key Vigenere
void encryptAutoKeyAlphabetVignere(std::string& plaintext, std::string& ciphertext, std::string& key);
void decryptAutoKeyAlphabetVignere(std::string& ciphertext, std::string& plaintext, std::string& key);


// ASCII Vignere
void encryptAsciiVignere(std::string& plaintext, std::string& ciphertext ,std::string& key);
void decryptAsciiVignere(std::string& ciphertext, std::string& plaintext ,std::string& key);




#endif