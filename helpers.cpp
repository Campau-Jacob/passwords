#include "helpers.h"

void generatePassword(string password, int length){
    if(!password.empty()){
        cout << password << endl;
    }

    if(password.length() == length){
        return;
    }

    const string characters = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for(char c : characters){
        generatePassword(password + c, length);
    }
}