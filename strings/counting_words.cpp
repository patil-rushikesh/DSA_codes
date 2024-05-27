#include <iostream>
using namespace std;
class str
{
private:
    char *A;

public:
    str();
    void getstr();
    void count_words();
    ~str();
};
str::str(){
    A = new char[100];
}
void str::getstr(){
    cout << "Enter String : ";
    cin.getline(A, 100);
}
void str::count_words(){
    int w_count = 1;
    for(int i = 0 ; A[i] != '\0' ; i++){
         if(A[i] == ' ' && A[i-1] != ' '){
            w_count++;
         }
    }
    cout<<"No. of words : "<<w_count<<endl;
}
str::~str(){
    delete []A;
}
int main()
{
    str A;
    A.getstr();
    A.count_words();
    return 0;
}