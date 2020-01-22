/*
Utils class
class for helper function

*/

#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <algorithm>



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
    transform(text.begin(), text.end(), text.begin(), std::toupper);
}



#endif