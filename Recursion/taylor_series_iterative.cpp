#include<iostream>
using namespace std;
double e(int x, int n){
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    for(i = 1; i <= n; i++){
        num = num * x;
        den = den * i;
        s = s + num/den;
    }
    return s;
}
int main(){
    int x,n;
    cout<<"Enter value of x : "<<endl;
    cin>>x;
    cout<<"Enter value of n : "<<endl;
    cin>>n;
    cout<<e(x,n);
    return 0;
}