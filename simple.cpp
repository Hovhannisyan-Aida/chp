#include <iostream>
#include <unordered_map>
#include <string>

std::string encrypt(const std::string &plaintext, const std::unordered_map<char, char> &substitution) {
    std::string ciphertext;
    for (char c : plaintext) {
        if (substitution.find(c) != substitution.end()) {
            ciphertext += substitution.at(c);
        } else {
            ciphertext += c; 
        }
    }
    return ciphertext;
}

std::string decrypt(const std::string &ciphertext, const std::unordered_map<char, char> &substitution) {
    std::unordered_map<char, char> inverse_substitution;
    
    for (const auto &pair : substitution) {
        inverse_substitution[pair.second] = pair.first;
    }

    std::string plaintext;
    for (char c : ciphertext) {
        if (inverse_substitution.find(c) != inverse_substitution.end()) {
            plaintext += inverse_substitution.at(c);
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    std::unordered_map<char, char> substitution = {
        {'a', 'd'}, {'b', 'e'}, {'c', 'f'},
        {'d', 'g'}, {'e', 'h'}, {'f', 'i'},
        {'g', 'j'}, {'h', 'k'}, {'i', 'l'},
        {'j', 'm'}, {'k', 'n'}, {'l', 'o'},
        {'m', 'p'}, {'n', 'q'}, {'o', 'r'},
        {'p', 's'}, {'q', 't'}, {'r', 'u'},
        {'s', 'v'}, {'t', 'w'}, {'u', 'x'},
        {'v', 'y'}, {'w', 'z'}, {'x', 'a'},
        {'y', 'b'}, {'z', 'c'}
    };

    std::string input;
    char choice;

    std::cout << "Do you want to (E)ncrypt or (D)ecrypt? ";
    std::cin >> choice;
    std::cin.ignore();

    std::cout << "Enter text: ";
    std::getline(std::cin, input);

    if (choice == 'E' || choice == 'e') {
        std::string ciphertext = encrypt(input, substitution);
        std::cout << "Ciphertext: " << ciphertext << std::endl;
    } else if (choice == 'D' || choice == 'd') {
        std::string plaintext = decrypt(input, substitution);
        std::cout << "Plaintext: " << plaintext << std::endl;
    } else {
        std::cout << "Invalid option!" << std::endl;
    }

    return 0;
}