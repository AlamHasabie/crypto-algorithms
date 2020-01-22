#include "display.hpp"


using namespace std;

void displayPlainCiphertext(string& ciphertext){
    cout << ciphertext << endl;
}

void displayNoSpaceCiphertext(string& ciphertext){
    for (string::iterator it = ciphertext.begin(); it != ciphertext.end(); it++){
        if (*it != 32) cout << *it;
    }
    cout << endl;
}

void displayBlockCiphertext(string& ciphertext, int b_size){

    int idx=0;
    for(string::iterator it = ciphertext.begin(); it!=ciphertext.end(); it++){
        if (*it!=32){
            cout << * it;
            if(idx%b_size==(b_size-1)) cout << " ";
            idx++;
        }
    }

    cout << endl;


}