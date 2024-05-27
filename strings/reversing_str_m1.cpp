#include <iostream>
#include <cstring> // For strlen
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
    ~str();
};

str::str()
{
    A = new char[100];
}

void str::getstr()
{
    cout << "Enter a string: ";
    cin.getline(A, 100);
}

void str::reverse()
{
    int len = strlen(A);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = A[i];
        A[i] = A[len - 1 - i];
        A[len - 1 - i] = temp;
    }
}

void str::displaystr()
{
    cout << "The string is: " << A << endl;
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
    s.reverse();
    s.displaystr();
    return 0;
}
