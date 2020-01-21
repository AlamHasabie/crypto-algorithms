#include <iostream>
#include <string>

using namespace std;


int main(){

    string in_plaintext;

    cin >> in_plaintext;

    for(int i=0 ; i<in_plaintext.length(); i++){
        cout << in_plaintext[i] << endl;
    }
    return 0;
}