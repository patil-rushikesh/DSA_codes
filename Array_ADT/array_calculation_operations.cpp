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
    int delete_elem(int);
    int findsum();
    int sum_recursive(int);
    int findavg();
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
int array::findsum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total = total + A[i];
    }
    return total;
}
int array::sum_recursive(int n)
{
    if (n < 0)
    {
        return 0;
    }
    else
    {
        return sum_recursive(n - 1) + A[n];
    }
}
int array::findavg()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total = total + A[i];
    }
    return total / length;
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
        cout << "1. Append Element\n2. Delete element\n3. Find sum of all elements\n4. Find Sum using recursive\n5. Find Average\n6. Display Array\n7. Exit\n";
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
        case 3: // FIND SUM OF ELEMENTS
            cout << A.findsum() << " is the sum of all the elements" << endl;
            break;
        case 4: // FIND SUM OF ELEMENTS USING RECURSIVE FUNCTION
            cout << A.sum_recursive(A.length) << " is the sum of all the elements" << endl;
            break;
        case 5: // FIND AVERAGE OF ALL ELEMENTS
            cout << A.findavg() << " is the average of all the elements" << endl;
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