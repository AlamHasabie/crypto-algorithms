#include "vigenere.hpp"
#include <iostream>

using namespace std;



const string tabula[26] = {
    "QWERTYUIOPASDFGHJKLZXCVBNM",
    "MNBVCXZASDFGHJKLPOIUYTREWQ",
    "QAZXSWEDCVFRTGBNHYUJMKILOP",
    "MLPOKNBJIUHVCGYTFXZDRQWESA",
    "QACRFVTGBZWNUJMISXEDYHKOLP",
    "ZXCVBNMLKJHGFDSAQWERTYUIOP",
    "ASDFGHJKLPOIUYTREWQZXCVBNM",
    "LKJHGFDSAPOIUYTREWQMNBVCXZ",
    "PLMNKOIJBVHUYGCXFTRDZSEWQA",
    "LOPIKMNJUYHBTGVRFCEDXZASQW",
    "WSXEDCRBYHNUJMQAZIKOLPFVTG",
    "LKJHGWQMCXFDSAPOIUNBVYTREZ",
    "JKLFGHYTREWQZXCVBIUASNMPOD",
    "QCVBNTYUWERZXISDFGHOPAJKLM",
    "SAPOMNLKFDJHGBTREWQIUYVCXZ",
    "CAPOIUNBVLQMYTREZXFDSKJHGW",
    "BVCXZASDFMTREWNGHJKLPOIUYQ",
    "DFGASHJKLRUYTCVEWQZXPOIBNM",
    "EHGBTRLKFDWQIPOMUYVCSANJXZ",
    "NBJIUHMTFXZDRGYEQWLPOKVCSA",
    "FDSABVYTREKJPOILXUNHGWQMCZ",
    "GHTREWQZSNXCVBIUAMPODJKLFY",
    "HSKJGBAPOIUVLQMYTRCNZXFDEW",
    "ISXEDQWKOLNUJMYHACRFVTGBZP",
    "QUICKBROWNFXJMPVERTHLAZYDG",
    "RBMFVTGYQAZIKOLPHNUJWSXEDC"
};


void encryptAlphabetVigenere(string& plaintext, string& ciphertext, string& key){

    int ascii_dec;

    ciphertext.clear();

    //Assume key would contains alphabet ONLY
    toAlphabet(key);

    toUpper(key);
    toUpper(plaintext);

    for (int i=0; i < plaintext.length() ; i++) {
        // Ignore encoding non-alphabet characters
        ascii_dec = plaintext[i];
        if (isAlphabet(ascii_dec)){
            ascii_dec = (char) (((int) plaintext[i] + (int) key[i%key.length()])%26 + 65);
        }
        ciphertext.push_back((char)ascii_dec);
    }

}

// Precondtion : Uppercase alphabet key ONLY
void decryptAlphabetVigenere(string& ciphertext, string& plaintext, string& key){

    int ascii_dec;
    plaintext.clear();


    toUpper(key);
    toUpper(ciphertext);

    toAlphabet(key);

    for (int i=0; i < ciphertext.length() ; i++) {
        // Ignore non-alphabet characters
        ascii_dec = ciphertext[i];
        if (isAlphabet(ascii_dec)){
            ascii_dec = ((int) ciphertext[i] - (int) key[i%key.length()])%26;
            if (ascii_dec<0) ascii_dec += 26;
            ascii_dec +=65;
        }

        plaintext.push_back((char) ascii_dec);
    }

}


void encryptAutoKeyAlphabetVigenere(string& plaintext, string& ciphertext, string& key){
    
    int diff;
    string buffer(plaintext);

    toAlphabet(buffer);
    toAlphabet(key);

    ciphertext.clear();

    if (key.length()  < buffer.length()) {
        diff = buffer.length() - key.length();
        for (int i = 0 ; i < diff ; i++){
            key.push_back(plaintext[i]);
        }
    }
    encryptAlphabetVigenere(plaintext,ciphertext,key);
}

void decryptAutoKeyAlphabetVigenere(string& ciphertext, string& plaintext, string& key){
    
    // Assume that key length equals plaintext length
    // If not , then throw an exception

    if (key.length()!=ciphertext.length()){
        throw "Key length does not match ciphertext length !";
    }

    decryptAlphabetVigenere(ciphertext,plaintext,key);
}

void encryptSuperAlphabetVigenere(string& plaintext, string& ciphertext, string& key){

    char hash = (char) 0x00;
    char temp;

    encryptAlphabetVigenere(plaintext,ciphertext, key);


    for (int i = 0; i < key.length() ; i++){
        hash = hash^key[i];
    }

    for (int i = 0 ; i < ciphertext.length() ; i++){
        temp = ciphertext[i];
        ciphertext[i] = ciphertext[(i+ (int)hash)%ciphertext.length()];
        ciphertext[(i+(int)hash)%ciphertext.length()] = temp;
    }


}
void decryptSuperAlphabetVigenere(string& ciphertext, string& plaintext, string& key){
    
    char hash = (char) 0x00;
    char temp;

    for (int i = 0; i < key.length() ; i++){
        hash = hash^key[i];
    }

    for (int i=ciphertext.length()-1 ; i >= 0; i--){
        temp = ciphertext[i];
        ciphertext[i] = ciphertext[(i+(int)hash)%ciphertext.length()];
        ciphertext[(i+(int)hash)%ciphertext.length()] = temp;
    }


    decryptAlphabetVigenere(ciphertext, plaintext, key);


}

void encryptAsciiVigenere(string& plaintext, string& ciphertext, string& key){

    int ascii_dec;
    ciphertext.clear();
    for (int i=0 ; i < plaintext.length() ; i++){

        ascii_dec = ((int)plaintext[i] + (int) key[i%key.length()])%256;
        ciphertext.push_back((char) ascii_dec);
    }

}
void decryptAsciiVigenere(string& ciphertext, string& plaintext, string& key){

    int mod_result;
    plaintext.clear();

    for (int i=0 ; i < ciphertext.length() ; i++){
        mod_result = ((int) ciphertext[i] - (int) key[i%key.length()])%256;
        if (mod_result < 0) mod_result += 256;
        plaintext.push_back((char) mod_result);
    }
}

void encryptFullVigenere(string& plaintext, string& ciphertext, string& key){

    int idx_row, idx_col,key_idx;

    toUpper(plaintext);
    toUpper(key);

    // Assume alphabet only key
    toAlphabet(key);

    ciphertext.clear();
    

    key_idx = 0;

    for (int i=0; i < plaintext.length(); i++){
        if(isAlphabet(plaintext[i])){

            idx_col = (int) plaintext[i] - 65;
            idx_row = (int) key[key_idx%key.length()] - 65;
            ciphertext.push_back(tabula[idx_row][idx_col]);
            key_idx++;

        } else {

            ciphertext.push_back((char) plaintext[i]);
        }

    }

}
void decryptFullVigenere(string& ciphertext, string& plaintext, string& key){
    
    int idx_row, key_idx ;

    
    // Validate
    toUpper(ciphertext);
    toUpper(key);
    toAlphabet(key);

    plaintext.clear();
    key_idx=0;

    for(int i=0; i < ciphertext.length(); i++){
        if(isAlphabet(ciphertext[i])){
            idx_row = (int) key[key_idx%key.length()] - 65;
            // Search for corresponding alphabet
            for (int col=0; col < 26; col++){
                if(tabula[idx_row][col]==ciphertext[i]){
                    plaintext.push_back((char) col+65);
                    break;
                }
            }     
            key_idx++;
        } else {
            plaintext.push_back((char) ciphertext[i]);
        }
        
    }
}
