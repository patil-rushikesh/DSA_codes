#include <iostream>
using namespace std;
class str
{
private:
    char *A;
    char *B;

public:
    str();
    void getstr();
    bool chk_palindrome();
    void display_result();
    ~str();
};
str::str()
{
    A = new char[100];
    B = new char[100];
}
void str::getstr(){
    cout<<"Enter String A : ";
    cin>>A;
    cout<<"Enter String B : ";
    cin>>B;
}
bool str::chk_palindrome()
{
    for (int i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
        {
            return false;
        }
    }
    return true;
}
void str::display_result()
{
    if (chk_palindrome())
    {
        cout << "It is Plaindrome" << endl;
    }
    else
    {
        cout << "It is not Palindrome" << endl;
    }
}
str::~str()
{
    delete[] A;
    delete[] B;
}
int main()
{
    str s;
    s.getstr();
    s.chk_palindrome();
    s.display_result();

    return 0;
}