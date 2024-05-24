#include <iostream>
using namespace std;
class string_operation
{
private:
    char *A;

public:
    string_operation();
    void getStr();
    void toggleCase();
    void displayStr();
    ~string_operation();
};
string_operation::string_operation()
{
    A = new char[100];
}
void string_operation::getStr()
{
    cout << "Enter String : ";
    cin.getline(A, 100);
}
void string_operation::toggleCase()
{
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)
        {
            A[i] = A[i] + 32;
        }
        else if (A[i] >= 97 && A[i] <= 122)
        {
            A[i] = A[i] - 32;
        }
    }
    cout << "Case of the entered string has been changed." << endl;
}
void string_operation::displayStr()
{
    cout << "String : ";
    cout << A << endl;
}
string_operation::~string_operation()
{
    delete[] A;
}
int main()
{
    string_operation x;
    x.getStr();
    x.displayStr();
    x.toggleCase();
    x.displayStr();
    return 0;
}