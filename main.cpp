#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



void alphabetVignere(string& plaintext, string& key);
void asciiVignere(string &plaintext, string&key);
int main(){

    string in_plaintext;
    string key;

    cin >> in_plaintext;
    cin >> key;

    transform(key.begin(), key.end(), key.begin(), ::toupper);
    transform(in_plaintext.begin(), in_plaintext.end(), in_plaintext.begin(), ::toupper);

    asciiVignere(in_plaintext,key);
    return 0;
}



void alphabetVignere(string& plaintext, string& key){

    for (int i=0; i < plaintext.length() ; i++) {
        plaintext[i] = (char) (((int) plaintext[i] + (int) key[i%key.length()])%26 + 65);
    }

    cout << plaintext << endl;


}

void asciiVignere(string& plaintext, string& key){

    for (int i=0; i<plaintext.length(); i++){
        plaintext[i] = (char) ((int)plaintext[i] + (int) key[i%key.length()])%256;
    }

    cout << plaintext << endl;


}