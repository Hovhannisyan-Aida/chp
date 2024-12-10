#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "\nMenu Options:\n";
    cout << "1. Print the IPv4 and IPv6 addresses of this computer\n";
    cout << "2. Trace network path to a hostname\n";
    cout << "3. Get IP address of a hostname\n";
    cout << "4. Encrypt a file/text\n";
    cout << "5. Decrypt a file/text\n";
    cout << "6. Compress a file/text\n";
    cout << "7. Restore a file/text\n";
    cout << "8. Calculate the value of a file\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

void printIP() {
    cout << "\nFetching IP addresses...\n";
    system("ipconfig");
}

void traceRoute() {
    cout << "\nEnter hostname or URL: ";
    string hostname;
    cin >> hostname;
    string command = "tracert " + hostname;
    system(command.c_str());
}

void getIP() {
    cout << "\nEnter hostname or URL: ";
    string hostname;
    cin >> hostname;
    string command = "nslookup " + hostname;
    system(command.c_str());
}

void encryptText() {
    cout << "\nEnter text to encrypt: ";
    string text;
    cin.ignore();
    getline(cin, text);
    for (char &c : text) {
        c += 3;
    }
    cout << "Encrypted text: " << text << "\n";
}

void decryptText() {
    cout << "\nEnter text to decrypt: ";
    string text;
    cin.ignore();
    getline(cin, text);
    for (char &c : text) {
        c -= 3;
    }
    cout << "Decrypted text: " << text << "\n";
}

void compressFile() {
    cout << "\nFeature not implemented yet (placeholder).\n";
}

void restoreFile() {
    cout << "\nFeature not implemented yet (placeholder).\n";
}

void calculateFileValue() {
    cout << "\nEnter file name: ";
    string filename;
    cin >> filename;
    ifstream file(filename, ios::binary | ios::ate);
    if (file.is_open()) {
        cout << "File size: " << file.tellg() << " bytes\n";
        file.close();
    } else {
        cout << "Error: File not found.\n";
    }
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                printIP();
                break;
            case 2:
                traceRoute();
                break;
            case 3:
                getIP();
                break;
            case 4:
                encryptText();
                break;
            case 5:
                decryptText();
                break;
            case 6:
                compressFile();
                break;
            case 7:
                restoreFile();
                break;
            case 8:
                calculateFileValue();
                break;
            case 9:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}




