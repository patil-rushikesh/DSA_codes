#include<iostream>
using namespace std;
int fact(int n){
    if(n == 1){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}
int main(){
    int x;
    cout<<"Enter the value : ";
    cin>>x;
    cout<<"Factorial : "<<fact(x)<<endl;
    return 0;
}