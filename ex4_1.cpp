#include <iostream> 
#include <string> 
#include <unordered_map> 
 
using namespace std; 

void caesarCipher() { 
    string text; 
    int shift; 
     
    cout << "Enter the text for Caesar Cipher: "; 
    cin.ignore(); 
    getline(cin, text); 
    cout << "Enter shift value: "; 
    cin >> shift; 
 
    for (char &c : text) { 
        if (isalpha(c)) { 
            char base = islower(c) ? 'a' : 'A'; 
            c = (c - base + shift) % 26 + base; 
        } 
    } 
     
    cout << "Encrypted Text: " << text << endl; 
} 
 
void simpleReplacement() { 
    string text; 
    unordered_map<char, char> replacementMap = { 
        {'a', 'b'}, {'b', 'c'}, {'c', 'd'}, {'d', 'e'}, 
        {'e', 'f'}, {'f', 'g'}, {'g', 'h'}, {'h', 'i'}, 
        {'i', 'j'}, {'j', 'k'}, {'k', 'l'}, {'l', 'm'}, 
        {'m', 'n'}, {'n', 'o'}, {'o', 'p'}, {'p', 'q'}, 
        {'q', 'r'}, {'r', 's'}, {'s', 't'}, {'t', 'u'}, 
        {'u', 'v'}, {'v', 'w'}, {'w', 'x'}, {'x', 'y'}, 
        {'y', 'z'}, {'z', 'a'} 
    }; 
 
    cout << "Enter the text for Simple Replacement Algorithm: "; 
    cin.ignore();
    getline(cin, text); 
     
    for (char &c : text) { 
        if (replacementMap.find(tolower(c)) != replacementMap.end()) { 
            c = isupper(c) ? toupper(replacementMap[tolower(c)]) : replacementMap[tolower(c)]; 
        } 
    } 
 
    cout << "Transformed Text: " << text << endl; 
} 

void runLengthEncoding() { 
    string text; 
     
    cout << "Enter the text for Run-Length Encoding: "; 
    cin.ignore(); 
    getline(cin, text); 
     
    string encoded = ""; 
    int count = 1; 
 
    for (size_t i = 1; i <= text.length(); i++) { 
        if (text[i] == text[i - 1]) { 
            count++; 
        } else { 
            encoded += text[i - 1] + to_string(count); 
            count = 1; 
        } 
    } 
 
    cout << "Run-Length Encoded Text: " << encoded << endl; 
} 
 
int main() { 
    int choice; 
 
    cout << "Choose an algorithm to solve the problem:" << endl; 
    cout << "1. Caesar Cipher" << endl; 
    cout << "2. Simple Replacement Algorithm" << endl; 
    cout << "3. Run-Length Encoding" << endl; 
    cout << "Enter your choice (1-3): "; 
    cin >> choice; 
 
    switch (choice) { 
        case 1: 
            caesarCipher(); 
            break; 
        case 2: 
            simpleReplacement(); 
            break; 
        case 3: 
            runLengthEncoding(); 
            break; 
        default: 
            cout << "Invalid choice!" << endl; 
    } 
 
    return 0; 
}