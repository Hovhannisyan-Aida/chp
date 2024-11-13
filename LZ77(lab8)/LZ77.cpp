#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<int, int, char>> LZ77_Compress(const string &input) {
    vector<tuple<int, int, char>> compressedData;
    int n = input.length();
    int searchBufferSize = 20; 
    int lookaheadBufferSize = 15;

    int i = 0;
    while (i < n) {
        int matchLength = 0;
        int matchDistance = 0;
        
        for (int j = max(0, i - searchBufferSize); j < i; j++) {
            int length = 0;
            while (length < lookaheadBufferSize && i + length < n && input[j + length] == input[i + length]) {
                length++;
            }
            if (length > matchLength) {
                matchLength = length;
                matchDistance = i - j;
            }
        }

        if (matchLength > 0) {
            compressedData.push_back(make_tuple(matchDistance, matchLength, input[i + matchLength]));
            i += matchLength + 1; 
        } else {
            compressedData.push_back(make_tuple(0, 0, input[i]));
            i++;
        }
    }
    return compressedData;
}
string LZ77_Decompress(const vector<tuple<int, int, char>> &compressedData) {
    string decompressedString;
    
    for (const auto &t : compressedData) {
        int distance, length;
        char nextChar;
        tie(distance, length, nextChar) = t;
        
        if (distance > 0 && length > 0) {
            int startIdx = decompressedString.length() - distance;
            for (int i = 0; i < length; i++) {
                decompressedString.push_back(decompressedString[startIdx + i]);
            }
        }
        
        decompressedString.push_back(nextChar);
    }

    return decompressedString;
}

void displayCompressedData(const vector<tuple<int, int, char>> &compressedData) {
    for (const auto &t : compressedData) {
        int distance, length;
        char nextChar;
        tie(distance, length, nextChar) = t;
        cout << "(" << distance << ", " << length << ", '" << nextChar << "') ";
    }
    cout << endl;
}

int main() {
    string input = "The compression and the decompression leave an impression. Hahahahaha!";
    cout << "Original string: " << input << endl;
    vector<tuple<int, int, char>> compressedData = LZ77_Compress(input);

    cout << "Compressed data: ";
    displayCompressedData(compressedData);
    cout << endl;

    string decompressedData = LZ77_Decompress(compressedData);

    cout << "Decompressed string: " << decompressedData << endl;

    if (decompressedData == input) {
        cout << "Success! The decompressed string matches the original." << endl;
    } else {
        cout << "Something went wrong! The decompressed string doesn't match the original." << endl;
    }

    return 0;
}
