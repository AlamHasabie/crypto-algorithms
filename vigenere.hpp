/**
Header for Vigenere encrypt/decypt and its variations

Author : alamhasabie

**/

#include <string>


#ifndef VIGENERE_H
#define VIGENERE_H


// Standard Vigenere
void encryptAlphabetVigenere(std::string& plaintext, std::string& ciphertext, std::string& key);
void decryptAlphabetVigenere(std::string& ciphertext, std::string& plaintext, std::string& key);

// Super-encryption standard Vigenere
// Adding an additional superposition cryption

/*

Superposition algorithm :
1. Create a XOR hash number from the key, for example k
2. For every character i in [0..n] , trade string[i] with string [i+k]

*/
void encryptSuperAlphabetVigenere(std::string& plaintext, std::string& ciphertext, std::string& key);
void decryptSuperAlphabetVigenere(std::string& ciphertext, std::string& plaintext, std::string& key);

// auto-key Vigenere
void encryptAutoKeyAlphabetVigenere(std::string& plaintext, std::string& ciphertext, std::string& key);
void decryptAutoKeyAlphabetVigenere(std::string& ciphertext, std::string& plaintext, std::string& key);

// full - key Vigenere
void encryptFullVigenere(std::string& plaintext, std::string& ciphertext, std::string& key);
void decryptFullVigenere(std::string& ciphertext, std::string& plaintext, std::string& key);


// ASCII Vigenere
void encryptAsciiVigenere(std::string& plaintext, std::string& ciphertext ,std::string& key);
void decryptAsciiVigenere(std::string& ciphertext, std::string& plaintext ,std::string& key);




#endif