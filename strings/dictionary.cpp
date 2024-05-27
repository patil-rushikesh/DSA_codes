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
    void chk_pos();
    ~str();
};
str::str()
{
    A = new char[100];
    B = new char[100];
}
void str::getstr()
{
    cout << "Enter String A : ";
    cin >> A;
    cout << "Enter String B : ";
    cin >> B;
}
void str::chk_pos()
{
    int i, j;
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
        {
            break;
        }
    }
    if (A[i] == B[i])
    {
        cout << "Strings ate equal" << endl;
    }
    else if (A[i] > B[i])
    {
        cout << "String B comes first" << endl;
    }
    else
    {
        cout << "String A comes first" << endl;
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
    s.chk_pos();

    return 0;
}