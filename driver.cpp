#include "helpers.h"

int main(){
    string pass = "";

    for(int j = 0; j < 5; j++){
        generatePassword(pass, j);
    }

    return 1;
}