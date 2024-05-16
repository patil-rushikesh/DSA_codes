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
    void min_max_single_Scan();
    void duplicates_sorted();
    void count_duplicates_sorted();
    void duplicates_sorted_hashing();
    void duplicates_unsorted();
    void duplicates_unsorted_hashing();
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
void Array::duplicates_sorted()
{
    int last_Duplicate = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] == A[i + 1] && A[i] != last_Duplicate)
        {
            cout << A[i] << " ";
            last_Duplicate = A[i];
        }
    }
    cout << endl;
}
void Array::count_duplicates_sorted()
{
    int j = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            j = j + 1;
            while (A[j] == A[i])
            {
                j++;
            }
            cout << A[i] << " is repeated for " << j - 1 << " times";
            i = j - 1;
        }
    }
    cout << endl;
}
void Array::duplicates_sorted_hashing()
{
    int *H;
    H = new int[max]{};
    for (int i = 0; i < length; i++)
    {
        H[A[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        if (H[i] > 1)
        {
            cout << i << " is repeated for " << H[i] << " times";
        }
    }
    delete[] H;
    cout << endl;
}
void Array::duplicates_unsorted()
{
    int count;
    for (int i = 0; i < length; i++)
    {
        count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
            {
                cout << A[i] << " is repeated for " << count << " times";
            }
        }
    }
    cout << endl;
}
void Array::duplicates_unsorted_hashing()
{
    int *H;
    H = new int[max]{};
    for (int i = 0; i < length; i++)
    {
        H[A[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        if (H[i] > 1)
        {
            cout << i << " is repeated for " << H[i] << " times";
        }
    }
    delete[] H;
    cout << endl;
}
int main()
{
    int length = 0;
    int x;
    Array A;
    int choice;
    while (1)
    {
        cout << "1. Add Array" << endl
             << "2. Display Array" << endl
             << "3. Finding Duplicate elements from Sorted Array." << endl
             << "4. Finding Count of Duplicates from sorted Array." << endl
             << "5. Finding Duplicate elements from Sorted Array using Hashing method." << endl
             << "6. Finding Duplicate elements from unsorted Array." << endl
             << "7. Finding Duplicate elements from unsorted Array using Hashing method." << endl
             << "8. Exit" << endl;
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
            A.duplicates_sorted();
            break;
        case 4:
            A.count_duplicates_sorted();
            break;
        case 5:
            A.duplicates_sorted_hashing();
            break;
        case 6:
            A.duplicates_unsorted();
            break;
        case 7:
            A.duplicates_unsorted_hashing();
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "Entered Invalid option" << endl;
            break;
        }
    }
}
