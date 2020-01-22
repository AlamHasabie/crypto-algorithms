#include "display.hpp"


using namespace std;

void displayPlainCiphertext(string& ciphertext){

    cout << ciphertext << endl;



}

void displayNoSpaceCiphertext(string& ciphertext){

    for (string::iterator it = ciphertext.begin(); it != ciphertext.end(); it++){
        if (*it != 32){
            cout << *it;
        }
    }

    cout << endl;

}