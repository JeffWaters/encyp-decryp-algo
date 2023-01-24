#include <iostream>
#include <string>

const int ALPHABET_SIZE = 26;

std::string encrypt(std::string plaintext, int key) {
    std::string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char shift = isupper(c) ? 'A' : 'a';
            ciphertext += (c - shift + key) % ALPHABET_SIZE + shift;
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

std::string decrypt(std::string ciphertext, int key) {
    std::string plaintext = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char shift = isupper(c) ? 'A' : 'a';
            plaintext += (c - shift - key + ALPHABET_SIZE) % ALPHABET_SIZE + shift;
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    std::string plaintext = "Hello World!";
    int key = 3;
    std::string ciphertext = encrypt(plaintext, key);
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    std::cout << "Decrypted Text: " << decrypt(ciphertext, key) << std::endl;
    return 0;
}
