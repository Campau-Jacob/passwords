#include <iostream>
#include <string>
using namespace std;

void generatePasswordRec(string password, int length);
void generatePasswordIt(int length);

int main(){
    for(int j = 1; j < 6; j++){
        generatePasswordRec("", j);
    }

    for(int j = 1; j < 6; j++){
        generatePasswordIt(j);
    }

    return 1;
}

void generatePasswordRec(string password, int length){
    if(!password.empty()){
        cout << password << endl;
    }

    if(password.length() == length){
        return;
    }

    const string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
    const string allCharacters = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(char c : characters){
        generatePassword(password + c, length);
    }
}

void generatePasswordIt(int length){
    vector<char> password(length, characters[0]);
}