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
    void pair_of_sum_k_unsorted(int);
    void pair_of_sum_k_unsorted_hashing(int);
    void pair_of_sum_k_sorted(int);
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
void Array::pair_of_sum_k_unsorted(int k)
{
    // Finding pair of elements whose sum is k from unsorted Array.
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " and " << A[j] << endl;
            }
        }
    }
}

void Array::pair_of_sum_k_unsorted_hashing(int k)
{
    // Finding pair of elements whose sum is k from unsorted Array using hashing method.
    int *H;
    H = new int[max]{};

    for (int i = 0; i < length; i++)
    {
        if (A[i] <= k)
        {
            if (H[k - A[i]] != 0)
            {
                cout << A[i] << " and " << k - A[i] << endl;
            }
            else
            {
                H[A[i]]++;
            }
        }
    }
    delete[] H;
}

void Array::pair_of_sum_k_sorted(int k)
{
    // Finding pair of elements whose sum is k from sorted Array.
    int i = 0, j = max - 1;
    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            cout << A[i] << " and " << A[j] << endl;
            i++;
            j--;
        }
        else if (A[i] + A[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
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
             << "3. Finding pair of elements whose sum is k from unsorted Array." << endl
             << "4. Finding pair of elements whose sum is k from unsorted Array using hashing method." << endl
             << "5. Finding pair of elements whose sum is k from sorted Array." << endl
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
            cout << "Enter the Sum : ";
            cin >> x;
            A.pair_of_sum_k_unsorted(x);
            break;
        case 4:
            cout << "Enter the Sum : ";
            cin >> x;
            A.pair_of_sum_k_unsorted_hashing(x);
            break;
        case 5:
            cout << "Enter the Sum : ";
            cin >> x;
            A.pair_of_sum_k_sorted(x);
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
