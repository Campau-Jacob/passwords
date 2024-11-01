//#include "helpers.h"
#include <iostream>
#include <string>
using namespace std;

void generatePassword(string password, int length);

int main(){
    for(int j = 1; j < 6; j++){
        generatePassword("", j);
    }

    return 1;
}

void generatePassword(string password, int length){
    if(!password.empty()){
        cout << password << endl;
    }

    if(password.length() == length){
        return;
    }

    const string characters = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(char c : characters){
        generatePassword(password + c, length);
    }
}