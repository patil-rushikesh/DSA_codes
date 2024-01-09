#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,10,20,0};
    int target = 10;
    for(int  i = 0; i< sizeof(arr) / sizeof(arr[0]) ; i++){         //time complexity  O(n)

        for(int  j = i + 1; j < sizeof(arr) / sizeof(arr[0]) ; j++){    //time complexity O(n)
            if(arr[i] + arr[j] == target){
                cout<<"Pair "<<arr[i]<<"+"<<arr[j]<<endl;
            }
        }
    }

    //Overall time complexity
    //O(n)* O(n) = O(n^2)
}