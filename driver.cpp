#include <iostream>
#include <string>
#include <vector>
#include <openssl/md5.h>
#include <iomanip>
#include <sstream>
#include <unordered_set>
using namespace std;

string generateMD5(const string& password);
void generatePasswordIt(int length, string* passes, string* hashes, string* found);

int main(){
string knownPasses[5] = {"unr", "password123", "NIST", "covid", "known5"};
string knownHashes[5] = {"f241b830d1944e06d9786f18ed4a431f", "918317f46fd5fed8e46c876c7c957a04", "517372dae26e82b7867a4513cad6e50e", 
                        "557884242e3eec9563556678e912307f", "bc85ae1dd7e5e9916e87cf71416399ce"};
string foundPasses[5] = {" ", " ", " ", " ", " "};

    generatePasswordIt(5, knownPasses, knownHashes, foundPasses);

    return 1;
}

string generateMD5(const string& password) {
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)password.c_str(), password.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    
    return ss.str();
}

void generatePasswordIt(int length, string* passes, string* hashes, string* found){
	const string allCharacters = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
    int numCharacters = characters.size(), tracker = 0;
    unordered_set<int> foundHashes;
    vector<int> indices(length, 0);

    while (tracker < 5) {
        // Build the current prefix
        string prefix;
        for (int i = 0; i < length; ++i) {
            prefix += characters[indices[i]];
        }

        cout << prefix << endl;

        // Try each password in the list and check its hash
        for (int i = 0; i < 5; i++) { //checks each password
            string combinedPassword = prefix + passes[i];
            string md5Hash = generateMD5(combinedPassword);

            for(int j = 0; j < 5; j++){ //checks each hash for each password
                if (md5Hash == hashes[j]) {
                    //cout << "###";
                    found[tracker] = combinedPassword;
                    tracker++;
                    cout << "Match found for hash " << hashes[i] << ": " << combinedPassword << endl;
                }
            }
        }

        // Increment indices to generate the next prefix
        int pos = 0;
        while (pos < length) {
            indices[pos]++;
            if (indices[pos] < numCharacters) {
                break;
            }
            indices[pos] = 0;
            pos++;
        }

        if (pos == length) {
            cout << endl;
            break;
        }
    }

    for(int i = 0; i < 5; i++){
        if(found[i] != " "){
            cout << "Pass: " << found[i] << endl;
            cout << "   Hash: " << generateMD5(found[i]) << endl;
        }
    }
}
