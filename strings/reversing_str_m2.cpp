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
