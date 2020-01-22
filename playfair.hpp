#ifndef PLAYFAIR_HPP
#define PLAYFAIR_HPP

#include "utils.hpp"


/* Playfair cipher
    Assumption :
    1. Key is a permutation of 26 alphabets except for letter J
    2. decrypt produces only the deciphered text, but no I's and X's are changed/removed
*/ 

void encryptPlayfairCipher(std::string& plaintext, std::string& ciphertext, std::string&key);
void decrpytPlayfairCipher(std::string& plaintext, std::string& ciphertext, std::string&key);