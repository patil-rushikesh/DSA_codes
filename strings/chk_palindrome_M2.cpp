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

void str::displaystr()
{
    cout << "You entered: " << A << endl;
}

void str::chk_palindrome()
{
    int len = strlen(A);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (A[i] != A[j])
        {
            cout << "It is not a palindrome" << endl;
            return;
        }
    }
    cout << "It is a palindrome" << endl;
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
    return 0;
}
