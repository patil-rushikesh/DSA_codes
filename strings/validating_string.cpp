#include<iostream>
using namespace std;
class str{
    private:
        char *A;
    public:
        str();
        void getstr();
        void display_result();
        bool check_password();
        ~str();
};
str::str(){
    A = new char[100];
}
void str:: getstr(){
    cout<<"Enter String :";
    cin.getline(A, 100);
}
void str::display_result(){
    if(check_password()){
        cout<<"Entered password is in correct format"<<endl;
    }else{
        cout<<"Wrong format"<<endl;
    }
}
bool str::check_password() {
    for (int i = 0; A[i] != '\0'; i++) {
        if (!((A[i] >= 'a' && A[i] <= 'z') ||
              (A[i] >= 'A' && A[i] <= 'Z') ||
              (A[i] >= '0' && A[i] <= '9'))) {
            return false;
        }
    }
    return true;
}

str::~str(){
    delete []A;
}
int main(){
    str A;
    A.getstr();
    A.display_result();
    return 0;
}