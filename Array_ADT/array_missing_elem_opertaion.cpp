#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int length;
    int min;
    int max;

public:
    Array()
    {
        A = new int[100];
        min = 0;
        max = 0;
        length = 0;
    }
    int addArray(int);
    void display();
    void missing_single_sorted();
    void missing_mult_sorted();
    void missing_mult_unsorted();
    void min_max_single_Scan();
    ~Array()
    {
        delete[] A;
    }
};

void Array::min_max_single_Scan()
{
    int minVal = A[0];
    int maxVal = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] < minVal)
        {
            minVal = A[i];
        }
        else if (A[i] > maxVal)
        {
            maxVal = A[i];
        }
    }
    min = minVal;
    max = maxVal;
}

int Array::addArray(int m)
{
    cout << "Enter " << m << " elements of Array" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
        length++;
    }
    min_max_single_Scan();
    return 0;
}

void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::missing_single_sorted()
{
    int diff = min - 0;
    for (int i = 0; i < max; i++)
    {
        if (A[i] - i != diff)
        {
            cout << i + diff << " ";
            break;
        }
    }
}

void Array::missing_mult_sorted()
{
    int diff = min;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
    cout << endl;
}

void Array::missing_mult_unsorted()
{
    int *H;
    H = new int[max + 1]; // Added 1 to max to allocate proper memory
    for (int i = 0; i <= max; i++) // Corrected the loop condition
    {
        H[i] = 0; // Initialize array elements to 0
    }
    for (int i = 0; i < length; i++)
    {
        H[A[i]]++;
    }
    for (int i = min; i <= max; i++)
    {
        if (H[i] == 0) // Corrected indexing
        {
            cout << i << " ";
        }
    }
    delete[] H;
    cout << endl;
}

int main()
{
    int length = 0;
    Array A;
    int choice;
    while (1)
    {
        cout << "1. Add Array" << endl
             << "2. Display Array" << endl
             << "3. Finding single missing element in sorted array." << endl
             << "4. Finding multiple missing elements in sorted array." << endl
             << "5. Finding multiple missing element in an unsorted array." << endl
             << "6. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter size of Array : ";
            cin >> length;
            A.addArray(length);
            break;
        case 2:
            A.display();
            break;
        case 3:
            A.missing_single_sorted();
            break;
        case 4:
            A.missing_mult_sorted();
            break;
        case 5:
            A.missing_mult_unsorted();
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "Entered Invalid option" << endl;
            break;
        }
    }
}
