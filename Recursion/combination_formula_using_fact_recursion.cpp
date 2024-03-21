#include<iostream>
using namespace std;
int fact(int n){
    if(n == 1){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}
int c(int n, int r){
    int t1,t2,t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/(t2*t3);
}
int main(){
    int n,r;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"Enter the value of r : ";
    cin>>r;
    cout<<"Combinations : "<<c(n,r)<<endl;
    return 0;
}