#include <iostream>
#include <string>
#include <vector>

std::string encrypt(const std::string& text) {
    int n = text.length();
    int rows = (n + 2) / 3; 
    std::vector<std::string> table(3, std::string(rows, ' ')); 
    
    for (int i = 0; i < n; ++i) {
        table[i % 3][i / 3] = text[i];
    }
    
    std::string encrypted;
    for (int col = 0; col < 3; ++col) {
        encrypted += table[col];
    }
    
    return encrypted;
}

std::string decrypt(const std::string& encrypted_text) {
    int n = encrypted_text.length();
    int rows = (n + 2) / 3;
    
    std::vector<std::string> table(3, std::string(rows, ' '));
    
    int index = 0;
    for (int col = 0; col < 3; ++col) {
        for (int row = 0; row < rows && index < n; ++row) {
            table[col][row] = encrypted_text[index++];
        }
    }
    
    std::string decrypted;
    for (int i = 0; i < n; ++i) {
        decrypted += table[i % 3][i / 3];
    }
    
    return decrypted;
}

int main() {
    std::string text;
    
    std::cout << "Enter the text to encrypt: ";
    std::getline(std::cin, text);
    
    std::string encrypted = encrypt(text);
    std::cout << "Encrypted text: " << encrypted << std::endl;
    
    std::string decrypted = decrypt(encrypted);
    std::cout << "Decrypted text: " << decrypted << std::endl;
    
    return 0;
}