/*
Helpers to display ciphertexts in required format
*/
#ifndef DISPLAY_H
#define DISPLAY_H

#include "utils.hpp"
#include <iostream>


void displayPlainCiphertext(std::string& ciphertext);
void displayNoSpaceCiphertext(std::string& ciphertext);
void displayBlockCiphertext(std::string& ciphertext, int b_size = 5);

#endif
