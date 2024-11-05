#include <iostream>
#include <string>
#include <vector>
#include <openssl/md5.h>
#include <iomanip>
#include <sstream>
using namespace std;

string generateMD5(const string& password);
void generatePasswordIt(int length, const string* passes, const string* hashes, string* found);

int main(){
string knownPasses[5] = {"unr", 
                        "password123", 
                        "known3", 
                        "known4", 
                        "known5"};

string knownHashes[5] = {"f241b830d1944e06d9786f18ed4a431f", 
                        "918317f46fd5fed8e46c876c7c957a04", 
                        "517372dae26e82b7867a4513cad6e50e", 
                        "557884242e3eec9563556678e912307f", 
                        "bc85ae1dd7e5e9916e87cf71416399ce"};

string foundPasses[5];

    for(int j = 1; j < 6; j++){
        generatePasswordIt(j, knownPasses, knownHashes, foundPasses);
    }

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

void generatePasswordIt(int length, const string* passes, const string* hashes, string* found){
	const string allCharacters = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
    int numCharacters = characters.size();
    vector<int> indices(length, 0);

    while (true) {
        // Build the current prefix
        string prefix;
        for (int i = 0; i < length; ++i) {
            prefix += characters[indices[i]];
        }

        system("clear");
        for(int i = 0; i < 5; i++){
            if(found[i].length() != 0){
                cout << found << endl;
            }
        }
        cout << endl << prefix << endl;

        // Append prefix to each known password and check the hash
        for (int i = 0; i < 5; ++i) {
            string combinedPassword = prefix + passes[i];
            string md5Hash = generateMD5(combinedPassword);

            // Compare generated hash with known hash
            if (md5Hash == hashes[i]) {
                found[i] = combinedPassword;
                cout << "Match found for hash " << hashes[i] << ": " << combinedPassword << endl;
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
            break;
        }
    }
}