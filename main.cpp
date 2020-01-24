#include "vigenere.hpp"
#include "display.hpp"
#include "playfair.hpp"

#include <fstream>
#include <streambuf>

using namespace std;


int main(){


    string choice;
    string filename;

    string in_plaintext;
    string ciphertext;
    string key;
    bool is_quitting;

    // File I/O
    ifstream* file;
    ofstream* file_o;
    string* file_buffer;
    



    cout << "Simple terminal-based classic cryptography program v1.0" << endl;
    cout << "Open source, written in C++" << endl;
    cout << "Author : Alam Hasabie(GitHub: @alamhasabie" << endl << endl;

    is_quitting = false;
    while(!is_quitting){
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
                    getline(cin,filename);
                    file = new ifstream(filename.c_str());
                    file_buffer = new string((istreambuf_iterator<char>(*file)),
                        istreambuf_iterator<char>());
                    in_plaintext = *file_buffer;
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

                cout << "What algorithm do you want to use ?" << endl;
                cout << "1. Standard Vigenere Cipher - 26 Alphabet (type '1')" << endl;
                cout << "2. Extended Vigenere Cipher - ASCII (type '2')" << endl;
                cout << "3. Auto Key Vigenere Cipher (type '3')" << endl;
                cout << "4. Full Key Vigenere Cipher (type '4')" << endl;
                cout << "5. Playfair Cipher (type '5')" << endl;
                cout << "6. Superkey Vigenere Cipher (type '6')" << endl;
                getline(cin,choice);
                if (choice=="1"){
                    encryptAlphabetVigenere(in_plaintext,ciphertext,key);
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
            
            cout << "Finished...";
            while(true){
                cout << "Do you want the cipher to be displayed ? (Y/N) ";
                getline(cin,choice);
                if(choice=="Y"){
                    displayPlainCiphertext(ciphertext);
                    displayNoSpaceCiphertext(ciphertext);
                    displayBlockCiphertext(ciphertext);
                    break;
                } else if (choice=="N"){
                    break;
                } else {
                    cout << endl << "Sorry, command not understood. Let me try again.";
                }
            }

            while(true){
                cout << "Do you want the cipher to be saved to external file ? (Y/N) ";
                getline(cin,choice);
                if(choice=="Y"){

                    cout << "Type the filename : ";
                    getline(cin,filename);
                    file_o = new ofstream(filename.c_str());
                    *file_o << ciphertext;
                    file_o->close();

                    break;
                } else if (choice=="N"){
                    break;
                } else {
                    cout << endl << "Sorry, command not understood. Let me try again.";
                }
            }

            while(true){
                cout << "Do you need another service ? (Y/N) ";
                getline(cin,choice);
                if(choice=="Y"){
                    // Do nothing
                    break;
                } else if (choice=="N"){
                    is_quitting=true;
                    cout << "Thanks..." << endl;
                    break;
                } else {
                    cout << endl << "Sorry, command not understood. Let me try again.";
                }
            }
        } else if(choice=="2"){

            while((choice!="Y")&&(choice!="N")){
                cout << "Do you want to get the ciphertext from external file ? (Y/N) ";
                getline(cin,choice);
                cout << endl;
                if(choice=="Y"){
                    cout << "Please type in the filename : ";
                    getline(cin,filename);
                    file = new ifstream(filename.c_str());
                    file_buffer = new string((istreambuf_iterator<char>(*file)),
                        istreambuf_iterator<char>());
                    ciphertext = *file_buffer;
                    cout << endl;
                } else if (choice=="N"){
                    cout << "Please type in the ciphertext : ";
                    getline(cin,in_plaintext);
                    cout << endl;
                } else {
                    cout << "Sorry, I don't understand the answer. Let me repeat" << endl;
                }
            }
            cout << "What is the key ?" << endl;
            getline(cin, key);
            while(true){

                cout << "What algorithm do you want to use ?" << endl;
                cout << "1. Standard Vigenere Cipher - 26 Alphabet (type '1')" << endl;
                cout << "2. Extended Vigenere Cipher - ASCII (type '2')" << endl;
                cout << "3. Auto Key Vigenere Cipher (type '3')" << endl;
                cout << "4. Full Key Vigenere Cipher (type '4')" << endl;
                cout << "5. Playfair Cipher (type '5')" << endl;
                cout << "6. Superkey Vigenere Cipher (type '6')" << endl;
                getline(cin,choice);
                if (choice=="1"){
                    decryptAlphabetVigenere(ciphertext,in_plaintext,key);
                    break;
                } else if (choice=="2"){
                    decryptAsciiVigenere(ciphertext,in_plaintext,key);
                    break;
                } else if (choice=="3"){
                    decryptAutoKeyAlphabetVigenere(ciphertext,in_plaintext,key);
                    break;
                } else if (choice=="4"){
                    decryptFullVigenere(ciphertext,in_plaintext,key);
                    break;
                } else if (choice=="5"){
                    decryptPlayfairCipher(ciphertext,in_plaintext,key);
                    break;
                } else if (choice=="6"){
                    decryptSuperAlphabetVigenere(ciphertext,in_plaintext,key);
                    break;
                } else {
                    cout << "Command not available. Let me try again.";
                }
            }
            
            cout << "Finished...";
            while(true){
                cout << "Do you want the plaintext to be displayed ? (Y/N) ";
                getline(cin,choice);
                if(choice=="Y"){
                    displayPlainCiphertext(in_plaintext);
                    displayNoSpaceCiphertext(in_plaintext);
                    displayBlockCiphertext(in_plaintext);
                    break;
                } else if (choice=="N"){
                    break;
                } else {
                    cout << endl << "Sorry, command not understood. Let me try again.";
                }
            }

            while(true){
                cout << "Do you want the plaintext to be saved to external file ? (Y/N) ";
                getline(cin,choice);
                if(choice=="Y"){

                    cout << "Type the filename : ";
                    getline(cin,filename);
                    file_o = new ofstream(filename.c_str());
                    *file_o << in_plaintext;
                    file_o->close();

                    
                    break;
                } else if (choice=="N"){
                    break;
                } else {
                    cout << endl << "Sorry, command not understood. Let me try again.";
                }
            }

            while(true){
                cout << "Do you need another service ? (Y/N) ";
                getline(cin,choice);
                if(choice=="Y"){
                    // Do nothing
                    break;
                } else if (choice=="N"){
                    is_quitting=true;
                    cout << "Thanks..." << endl;
                    break;
                } else {
                    cout << endl << "Sorry, command not understood. Let me try again.";
                }
            }
        } else {
            cout << "Command not understood. Let me try again.";
        }
        
    }

    return 0;
}
