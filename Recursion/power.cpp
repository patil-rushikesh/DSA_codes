#include<iostream>
using namespace std;
int pow(int m, int n){
    if(n == 0){
        return 1;
    }else{
        return pow(m,n-1)*m;
    }
}
int pow(int m, int n){
    if(n == 0){
        return 1;
    }else{
        return pow(m,n-1)*m;
    }
}
int main(){
    int x,y;
    cout<<"Enter Base : ";
    cin>>x;
    cout<<"Enter Power : ";
    cin>>y;
    cout<<"Result : "<<pow(x,y);
}