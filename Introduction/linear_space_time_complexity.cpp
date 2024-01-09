#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};

    //task 1 : adding 10 to first element

    arr[0] = arr[0] + 10;                       // Time complexity -> O(1) | Space complexity -> O(1)

    //task 2 : to print the elements of an array
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){       //Time complexity -> O(n)  | Space Complexity -> O(1) 
       cout<<arr[i];
       cout<<endl;
    }
    cout<<endl;
    //task 3 : copy the elements of one array to another

    int newarr[sizeof(arr) / sizeof(arr[0])];                    //Time complexity -> O(1)  | Space Complexity -> O(n)
    for(int i = 0; i<sizeof(arr) / sizeof(arr[0]); i++){         //Time complexity -> O(n)  | Space Complexity -> O(1)
        newarr[i] = arr[i];
    } 
    
    for(int i = 0; i<sizeof(arr) / sizeof(arr[0]); i++){         ////Time complexity -> O(n)  | Space Complexity -> O(1)
        cout<<newarr[i];
        cout<<endl;
    }


    // Overall
    // Space complexity 
    // 1 + 1 + n + 1 + 1 = O(5+n) = O(n)
    // Time complexity
    // 1+n+1+n+n = O(2+3n) = O(n)

}