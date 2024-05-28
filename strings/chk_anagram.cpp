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
    void chk_anagram();
    ~str();
};
str::str()
{
    A = new char[100];
    B = new char[100];
}
void str::getstr()
{
    cout << "Enter String A: ";
    cin >> A;
    cout << "Enter String B: ";
    cin >> B;
}
void str::chk_anagram()
{
    int i, H[26] = {0};
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 'a'] ++;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 'a'] --;
        if(H[B[i] - 'a'] < 0){
            cout<<"Not anagram"<<endl;
            break;
        }
    }
    if(B[i] == '\0'){
        cout<<"Its Anagram"<<endl;
    }

}
str::~str(){
    delete []A;
    delete []B;
}
int main(){
    str s;
    s.getstr();
    s.chk_anagram();
    return 0;
}