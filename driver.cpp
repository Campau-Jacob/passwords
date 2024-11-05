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
	const string allCharacters = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int numCharacters = allCharacters.size();
    
    // Initialize indices for each character position to 0
    vector<int> indices(length, 0);

    while (true) {
        // Build and print the current password
        string password;
        for (int i = 0; i < length && indices[i] != -1; ++i) {
            password += allCharacters[indices[i]];
        }
        cout << password << endl;

        // Increment the rightmost index
        int pos = 0;
        while (pos < length) {
            indices[pos]++;
            if (indices[pos] < numCharacters) {
                break; // No carry, so we can stop
            }
            // Carry over to the next position
            indices[pos] = 0;
            pos++;
        }
        
        // If we've carried over all positions, we are done
        if (pos == length) {
            break;
        }
    }
}