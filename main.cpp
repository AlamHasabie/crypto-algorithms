#include "vigenere.hpp"
#include "display.hpp"
#include "playfair.hpp"

using namespace std;


int main(){


    string choice;
    string in_plaintext;
    string ciphertext;
    string key;



    cout << "Simple terminal-based classic cryptography program v1.0" << endl;
    cout << "Open source, written in C++" << endl;
    cout << "Author : Alam Hasabie(GitHub: @alamhasabie" << endl << endl;
    cout << "What do you want to do ?" << endl;
    cout << "1. Encrypt (type '1')" << endl;
    cout << "2. Decrypt (type '2')" << endl << endl;;
    getline(cin,choice);
    if(choice=="1"){

        while((choice!="Y")&&(choice!="N")){
            cout << "Do you want to get the plaintext from external file ? (Y/N) ";
            getline(cin,choice);
            cout << endl;
            if(choice=="Y"){
                cout << "Please type in the filename : ";
                cout << endl;
            } else if (choice=="N"){
                cout << "Please type in the plaintext : ";
                getline(cin,in_plaintext);
                cout << endl;
            } else {
                cout << "Sorry, I don't understand the answer. Let me repeat" << endl;
            }
        }
        cout << "What is the key ?" << endl;
        getline(cin, key);
        while(true){

            cout << "What algorithm you want to use ?" << endl;
            cout << "1. Standard Vigenere Cipher - 26 Alphabet (type '1')" << endl;
            cout << "2. Extended Vigenere Cipher - ASCII (type '2')" << endl;
            cout << "3. Auto Key Vigenere Cipher (type '3')" << endl;
            cout << "4. Full Key Vigenere Cipher (type '4')" << endl;
            cout << "5. Playfair Cipher (type '5')" << endl;
            cout << "6. Superkey Vigenere Cipher (type '6')" << endl;
            getline(cin,choice);
            if (choice=="1"){
                encryptAlphabetVigenereCipher(in_plaintext,ciphertext,key);
                break;
            } else if (choice=="2"){
                encryptAsciiVigenere(in_plaintext,ciphertext,key);
                break;
            } else if (choice=="3"){
                encryptAutoKeyAlphabetVigenere(in_plaintext,ciphertext,key);
                break;
            } else if (choice=="4"){
                encryptFullVigenere(in_plaintext,ciphertext,key);
                break;
            } else if (choice=="5"){
                encryptPlayfairCipher(in_plaintext, ciphertext, key);
                break;
            } else if (choice=="6"){
                encryptSuperAlphabetVigenere(in_plaintext,ciphertext,key);
                break;
            } else {
                cout << "Command not available. Let me try again.";
            }
        }
        
        displayPlainCiphertext(ciphertext);
        displayNoSpaceCiphertext(ciphertext);
        displayBlockCiphertext(ciphertext);
        decryptPlayfairCipher(ciphertext,in_plaintext,key);
        displayPlainCiphertext(in_plaintext);
        displayNoSpaceCiphertext(in_plaintext);
        displayBlockCiphertext(in_plaintext);

    }





    


    return 0;
}
