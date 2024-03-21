#include<iostream>
using namespace std;
double result(int x,int n){
    static double p, f;
    p = 1;
    f = 1;
    double r;
    if(n == 0){
        return 1;
    }else{
        r = result(x,n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}
int main(){
    int x,y;
    cout<<"Enter the term : ";
    cin>>x;
    cout<<"Enter the no. of terms : ";
    cin>>y;    
    cout<<"Result : "<<result(x,y)<<endl;
}