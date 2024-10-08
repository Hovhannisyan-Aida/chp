#include <iostream> 
#include <vector> 
#include <string> 
 
void createTableAndTransform(const std::string& input) { 
     
    std::vector<std::string> table; 
     
    for (size_t i = 0; i < input.length(); i += 3) { 
        table.push_back(input.substr(i, 3)); 
    } 
     
    
    std::string output; 
     
    
    size_t maxRows = table.size(); 
    for (size_t col = 0; col < 3; ++col) { 
        for (size_t row = 0; row < maxRows; ++row) { 
            if (col < table[row].length()) { 
                output += table[row][col]; 
            } 
        } 
    } 
 
    std::cout << "Transformed line:\n" << output << std::endl; 
} 
 
int main() { 
    std::string inputLine; 
     
    std::cout << "Enter a line of text (including spaces): "; 
    std::getline(std::cin, inputLine); 
     
    createTableAndTransform(inputLine); 
     
    return 0; 
}