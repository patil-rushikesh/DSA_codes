#include <iostream>
using namespace std;
class array
{
private:
    int *A;

public:
    int length;
    array()
    {
        A = new int[100];
        length = 0;
    }
    int append(int);
    void delete_elem(int);
    void display();
    bool is_sorted();
    void insert_in_sorted_arr(int);
    void take_negative_to_left();
    ~array()
    {
        delete[] A;
    }
};
int array::append(int value)
{
    A[length] = value;
    length++;
}
void array::delete_elem(int index)
{
    for (int i = index; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    length--;
}
bool array::is_sorted(){
    for(int i = 0; i<length-1; i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;
}
void array::insert_in_sorted_arr(int value){
    int i = length - 1;
    while(A[i]>value){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = value;
    length++;
}
void array::take_negative_to_left(){
    int i = 0;
    int j = length - 1;
    while(i<j){
        while(A[i]<0){
            i++;
        }
        while(A[j]>=0){
            j--;
        }
        if(i<j){
            swap(A[i],A[j]);
        }
    }
}
void array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int index = 0;
    int value = 0;
    array A;
    int choice;
    while (1)
    {
        cout << "1. Append Element\n2. Delete element\n3. Check Sorting\n4. Insert element in Sorted array\n5. Take all negative elements on the left side and positive on right\n6. Display Array\n7. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1: // APPEND
            cout << "Enter the element : ";
            cin >> value;
            A.append(value);
            break;
        case 2: // DELETE
            cout << "Enter the Index : ";
            cin >> index;
            A.delete_elem(index);
            break;
        case 3:
            if(A.is_sorted()){
                cout<<"Array is sorted"<<endl;
            }else{
                cout<<"Array is Not Sorted"<<endl;
            }
            A.display();
            break;
        case 4:
            cout<<"Enter the Element to be inserted : ";
            cin>>value;
            A.insert_in_sorted_arr(value);
            A.display();
            break;
        case 5:
            A.take_negative_to_left();
            A.display();
            break;
        case 6:
            A.display();
            break;
        case 7: // EXIT
            return 0;
            break;
        default:
            cout << "Entered Invalid option" << endl;
            break;
        }
    }
}