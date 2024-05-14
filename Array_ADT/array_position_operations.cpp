#include <iostream>
using namespace std;
class array
{
private:
    int *A;
    int *B;

public:
    int length;
    array()
    {
        A = new int[100];
        length = 0;
    }
    int append(int);
    void delete_elem(int);
    void reverse_m1();
    void reverse_m2();
    void leftshift();
    void rightshift();
    void leftrotate();
    void rightrotate();
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
void array::delete_elem(int index)
{
    for (int i = index; i < length; i++)
    {
        A[i] = A[i + 1];
    }
}
void array::reverse_m1()
{
    B = new int[length - 1];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    for (int i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
    delete[] B;
}
void array::reverse_m2()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
void array::leftshift()
{
    for (int i = 0; i < length - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = 0;
}
void array::rightshift()
{
    for (int i = length - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = 0;
}
void array::leftrotate()
{
    int temp = A[0];
    for (int i = 1; i < length; i++)
    {
        A[i - 1] = A[i];
    }
    A[length - 1] = temp;
}

void array::rightrotate()
{
    int temp = A[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = temp;
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
        cout << "1. Append Element\n2. Delete element\n3. Left Shift\n4. Right Shift\n5. Left Rotate\n6. Right rotate\n7. Display Array\n8. Exit\n";
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
            A.leftshift();
            A.display();
            break;
        case 4:
            A.rightshift();
            A.display();
            break;
        case 5:
            A.leftrotate();
            A.display();
            break;
        case 6:
            A.rightrotate();
            A.display();
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