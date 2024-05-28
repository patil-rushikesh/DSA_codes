#include <iostream>
#include <cstring>
using namespace std;

class str {
private:
    char *A;

public:
    str();
    void getstr();
    void dup_individually();
    void dup_hash();
    void dup_bits();
    ~str();
};

str::str() {
    A = new char[100];
}

void str::getstr() {
    cin.ignore(); // Clear input buffer
    cout << "Enter String: ";
    cin.getline(A, 100);
}

void str::dup_individually() {
    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] == -1) {
            continue;
        }

        cout << A[i] << " : ";
        int count = 1;
        for (int j = i + 1; A[j] != '\0'; j++) {
            if (A[j] == A[i]) {
                count++;
                A[j] = -1;
            }
        }
        cout << count << endl;
    }
}

void str::dup_hash() {
    int *H = new int[26](); // Initialize to 0
    for (int i = 0; A[i] != '\0'; i++) {
        if (isalpha(A[i])) {
            char ch = tolower(A[i]); // Convert to lowercase
            H[ch - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (H[i] > 1) {
            char temp = i + 'a';
            cout << temp << " : " << H[i] << endl;
        }
    }

    delete[] H;
}

void str::dup_bits() {
    int seen = 0;
    int duplicates = 0;

    cout << "Duplicate characters: ";
    for (int i = 0; A[i] != '\0'; i++) {
        char ch = A[i];
        if (ch < 'a' || ch > 'z') {
            continue;
        }

        int mask = 1 << (ch - 'a');

        if (seen & mask) {
            if (!(duplicates & mask)) {
                cout << ch << " ";
                duplicates |= mask;
            }
        } else {
            seen |= mask;
        }
    }
    cout << endl;
}

str::~str() {
    delete[] A;
}

int main() {
    str s;
    int choice;
    while (true) {
        cout << "Finding Duplicates:" << endl;
        cout << "1. Individually" << endl;
        cout << "2. Using Hash table" << endl;
        cout << "3. Using Bit operation" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                s.getstr();
                s.dup_individually();
                break;
            case 2:
                s.getstr();
                s.dup_hash();
                break;
            case 3:
                s.getstr();
                s.dup_bits();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
    return 0;
}
