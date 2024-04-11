#include<iostream>
using namespace std;
//Print Sum of N using recursion
int fun(int n){
    if(n == 0){
        return 0; 
    }else{
        return fun(n-1) + n;
    }
}
int main(){
    int x;
    cin>>x;
    cout<<fun(x)<<endl;
    return 0;
}