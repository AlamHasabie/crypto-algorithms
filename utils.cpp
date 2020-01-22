#include "utils.hpp"



void toAlphabet(std::string& text){

    std::string buffer(text);
    int ascii;
    text.clear();
    for (int i = 0; i < buffer.length(); i++){
        ascii = (int) buffer[i];
        if((65<=ascii&&90>=ascii)||(97<=ascii&&122>=ascii)){
            text.push_back((char) ascii);
        }
    }
}

void toUpper(std::string& text){
    transform(text.begin(), text.end(), text.begin(), ::toupper);
}

bool isAlphabet(char c){
    return ((int) c <= 90) && ((int) c >= 65);
}