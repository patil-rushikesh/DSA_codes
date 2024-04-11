#include<iostream>
using namespace std;
double e(int x, int n){
    static double s = 1;
    if(n == 0){
        return s;
    }else{
        s = 1 + x*s/n;
        return e(x,n-1);
    }
}
int main(){
    double x,n;
    cout<<"Enter value of x : ";
    cin>>x;
    cout<<"Enter value of n : ";
    cin>>n;
    cout<<e(x,n);
}