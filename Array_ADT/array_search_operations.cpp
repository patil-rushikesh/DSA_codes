#include <iostream>
using namespace std;
int *p;         // Pointer to refer the array
int length = 0; // variable to store the length of the array

//-------------------------------------  Function to display Array   ---------------------------------------------
void display()
{
    cout << "Array : ";
    if (length == 0)
    {
        cout << "No elements to Display\n";
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            cout << p[i] << "  ";
        }
        cout << endl;
    }
}
//-------------------------------------  Function to append elements   ---------------------------------------------
void append(int element)
{
    p[length] = element;
    length++;
}
//-------------------------------------  Function to delete elements   ---------------------------------------------
void delete_elem(int index)
{
    for (int i = index; i < length - 1; i++)
    {
        p[i] = p[i + 1];
    }
    length--;
}
//-------------------------------------  Function to implement linear search   ---------------------------------------------
int linear_s(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == p[i])
        {
            return i;
        }
    }
    return -1;
}
//--------------------------------  Function to implement linear search  with Transposition  -------------------------------
int linear_transp(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == p[i])
        {
            swap(p[i], p[i - 1]);
            return i - 1;
        }
    }
    return -1;
}
//--------------------------------  Function to implement linear search  with move to head  --------------------------------
int linear_tohead(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == p[i])
        {
            swap(p[i], p[0]);
            return 0;
        }
    }
    return -1;
}
//-------------------------------------  Function to implement Binary search   ---------------------------------------------
int binary_s(int key)
{
    int l = 0;
    int h = length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == p[mid])
        {
            return mid;
        }
        else if (key < p[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
//-------------------------------  Function to implement Binary search using recursion   -----------------------------------
int binary_recursive(int l, int h, int key)
{
    if (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (key == p[mid])
        {
            return mid;
        }
        else if (key < p[mid])
        {
            return binary_recursive(l, mid - 1, key);
        }
        else
        {
            return binary_recursive(mid + 1, h, key);
        }
    }
    return -1; // Return -1 if the element is not found
}

//---------------------------------------------------------------------------------------------------------------
int main()
{
    p = new int[100];
    int choice;
    int x;
    int y;
    int position;
    while (1)
    {
        cout << "1. Insert Element\n2.Delete Element\n3. Linear Search\n4. Linear Search and Transposition\n5. Linear Search and Move to Head\n6. Binary Search\n7. Binary Search using recursive\n8. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1: // INSERT ELEMENTS
            cout << "Enter value to append : ";
            cin >> x;
            append(x);
            break;
        case 2: // DELETE ELEMENTS
            cout << "Enter Position of the element : ";
            cin >> x;
            delete_elem(x);
            break;
        case 3: // LINEAR SEARCH
            cout << "Enter Element to be searched : ";
            cin >> x;
            position = linear_s(x);
            if (position == -1)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                cout << "Element " << x << " found at " << position << endl;
            }
            break;
        case 4: // LINEAR SEARCH USING TRANSPOSITION
            cout << "Enter Element to be searched : ";
            cin >> x;
            position = linear_transp(x);
            if (position == -1)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                cout << "Element " << x << " found at " << position << endl;
                cout << "Array Modified." << endl;
                display();
            }
            break;
        case 5: // LINEAR SEARCH USING MOVE TO HEAD
            cout << "Enter Element to be searched : ";
            cin >> x;
            position = linear_tohead(x);
            if (position == -1)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                cout << "Element " << x << " found at " << position << endl;
                cout << "Array Modified." << endl;
                display();
            }
            break;
        case 6: // BINARY SEARCH
            cout << "Enter Element to be searched : ";
            cin >> x;
            position = binary_s(x);
            if (position == -1)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                cout << "Element " << x << " found at " << position << endl;
            }
            break;
        case 7: // BINARY SEARCH USING RECURSIVE FUCNTION
            cout << "Enter Element to be searched : ";
            cin >> x;
            position = binary_recursive(0, length, x);
            if (position == -1)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                cout << "Element " << x << " found at " << position << endl;
            }
            break;
        case 8:
            delete[] p;
            return 0;
        default:
            cout << "Invalid Choice!!\n";
            break;
        }
    }
}