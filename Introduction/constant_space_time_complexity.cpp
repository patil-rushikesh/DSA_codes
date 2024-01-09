#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    //add 10 to first element in the array
    arr[0] = arr[0] + 10; //time complexity -> O(1)
    int num = arr[sizeof(arr) / sizeof(arr[0]) - 1];  //space complexity - int 4 bytes O(4)
    cout<<arr[0];
    cout<<num;
    //O(1) + O(1) = O(2) == O(1)  //constant time complexity
    //O(4 bytes) = O(1)     //constant space complexity 
}