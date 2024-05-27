#include <iostream>
using namespace std;
class str
{
private:
    char *A;

public:
    str();
    void getStr();
    void count_vowels();
    ~str();
};
str::str()
{
    A = new char[100];
}
void str::getStr()
{
    cout << "Enter String : ";
    cin >> A;
}
void str::count_vowels()
{
    int v_count = 0;
    int c_count = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U'){
            v_count++;
        }else if(A[i] > 'a' && A[i] <= 'z' || A[i] > 'A' && A[i] <= 'Z'){
            c_count++;
        }
    }
    cout<<"No. of Vowels : "<<v_count<<endl;
    cout<<"No. of Consonants  : "<<c_count<<endl;
}
str::~str()
{
    delete[] A;
}
int main()
{
    str A;
    A.getStr();
    A.count_vowels();
    return 0;
}