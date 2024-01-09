#include <iostream>
using namespace std;
int main()
{
    int arr[] = {2, 3, 4, 5, 6, 40, 48};

    // Linear search 40 element
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) // T.C -> O(n)
    {
        if (arr[i] == 40)
        {
            cout << "found at " << i;
        }
    }

    cout<<endl;
    // Binary search 40 element

    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while (start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == 40){
            cout<<"found at "<<mid;
            break;
        }else if(arr[mid]<40){
            start = mid +1;
        }else{
            end = mid -1;
        }
    }           //T.C. -> O(log n)


    
}