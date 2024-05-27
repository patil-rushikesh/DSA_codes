#include <iostream>
#include <cstring>
using namespace std;

class str
{
private:
    char *A;

public:
    str();
    void getstr();
    void reverse();
    void displaystr();
    void chk_palindrome();
    ~str();
};

str::str()
{
    A = new char[100];
}

void str::getstr()
{
    cout << "Enter string: ";
    cin.getline(A, 100);
}

void str::reverse()
{
    int len = strlen(A);
    char *B = new char[len + 1]; 
    strcpy(B, A);


    for (int i = 0; i < len; i++)
    {
        A[i] = B[len - 1 - i];
    }
    A[len] = '\0'; 

    delete[] B;
}

void str::displaystr()
{
    cout << "You entered: " << A << endl;
}

void str::chk_palindrome()
{
    int len = strlen(A);
    char *B = new char[len + 1]; 
    for (int i = 0, j = len - 1; i < len; i++, j--)
    {
        B[j] = A[i];
    }
    B[len] = '\0'; 
    for (int i = 0; i < len; i++)
    {
        if (A[i] != B[i])
        {
            cout << "Not palindrome" << endl;
            delete[] B; 
            return;
        }
    }

    cout << "Palindrome" << endl;
    delete[] B; 
}

str::~str()
{
    delete[] A;
}

int main()
{
    str s;
    s.getstr();
    s.displaystr();
    s.chk_palindrome();
    s.reverse();
    return 0;
}
