#include <iostream>
using namespace std;
class array
{
private:
    int *A;
    int length;

public:
    array()
    {
        A = new int[100];
        length = 0;
    }
    int append(int);
    int delete_elem(int);
    int get(int);
    int set(int, int);
    int max();
    int min();
    void display();
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
int array::delete_elem(int index)
{
    for (int i = index; i < length; i++)
    {
        A[i] = A[i + 1];
    }
}
int array::get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    else
    {
        return -1;
    }
}
int array::set(int index, int value)
{
    if (index >= 0 && index < length)
    {
        A[index] = value;
        return 0;
    }
    else
    {
        return -1;
    }
}
int array::max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
int array::min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (min > A[i])
        {
            min = A[i];
        }
    }
    return min;
}
void array::display(){
    for(int i=0 ; i< length ; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int index = 0;
    int value = 0;
    array A;
    int choice;
    while (1)
    {
        cout << "1. Append Element\n2. Delete element\n3. Get Element\n4. Set Element\n5. Find Maximum\n6. Find Minimum\n7. Display Array\n8. Exit\n";
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
        case 3: // GET
            cout << "Enter the Index : ";
            cin >> index;
            cout<<A.get(index);
            break;
        case 4: // SET
            cout << "Enter the Index : ";
            cin >> index;
            cout << "Enter the Value : ";
            cin >> value;
            A.set(index, value);
            break;
        case 5: // MAXIMUM
            cout << A.max() << " is the maximum element" << endl;
            break;
        case 6: // MINIMUM
            cout << A.min() << " is the minimum element" << endl;
            break;
        case 7:
            A.display();
            break;
        case 8: // EXIT
            return 0;
            break;
        default:
            cout << "Entered Invalid option" << endl;
            break;
        }
    }
}