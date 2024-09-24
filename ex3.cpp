#include <iostream>
#include <unordered_map>
#include <string>

std::string substitute(const std::string &plaintext, const std::unordered_map<char, char> &substitution) {
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

    std::string plaintext;
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);

    std::string ciphertext = substitute(plaintext, substitution);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
}

