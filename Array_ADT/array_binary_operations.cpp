#include <iostream>
using namespace std;
class array
{
private:
    int *A;
    int *B;
    int *C;

public:
    int lengthA;
    int lengthB;
    int lengthC;
    array()
    {
        A = new int[100];
        B = new int[100];
        C = new int[100];
        lengthA = 0;
        lengthB = 0;
        lengthC = 0;
    }
    void addarrays(int, int);
    void display();
    void Merge();
    void Union();
    void Intersection();
    void Difference();

    ~array()
    {
        delete[] A;
    }
};
void array::addarrays(int m, int n)
{
    lengthC = 0;
    cout << "Enter elements of array A" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    lengthA = m;
    cout << "Enter elemetns of Array B" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    lengthB = n;
}
void array::display()
{
    cout << "Array A : ";
    for (int i = 0; i < lengthA; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Array B : ";
    for (int i = 0; i < lengthB; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    cout << "Array C : ";
    for (int i = 0; i < lengthC; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
}
void array::Merge()
{
    lengthC = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < lengthA && j < lengthB)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
            lengthC++;
        }
        else
        {
            C[k++] = B[j++];
            lengthC++;
        }
    }
    for (; i < lengthA; i++)
    {
        C[k++] = A[i];
        lengthC++;
    }
    for (; j < lengthB; j++)
    {
        C[k++] = B[j];
        lengthC++;
    }
}
void array::Union()
{
    lengthC = 0;
    int i = 0, j = 0, k = 0;
    while (i < lengthA && j < lengthB)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
            lengthC++;
        }
        else if (A[i] > B[j])
        {
            C[k++] = B[j++];
            lengthC++;
        }
        else
        {
            C[k++] = A[i++];
            j++;
            lengthC++;
        }
    }
    while (i < lengthA)
    {
        C[k++] = A[i++];
        lengthC++;
    }
    while (j < lengthB)
    {
        C[k++] = B[j++];
        lengthC++;
    }
}

void array::Intersection()
{
    lengthC = 0;
    int i = 0, j = 0, k = 0;
    while (i < lengthA && j < lengthB)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            C[k++] = A[i];
            i++;
            j++;
            lengthC++;
        }
    }
}

void array::Difference()
{
    lengthC = 0;
    int i = 0, j = 0, k = 0;
    while (i < lengthA && j < lengthB)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
            lengthC++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            while (i < lengthA && A[i] == B[j])
                i++;
        }
    }
    while (i < lengthA)
    {
        C[k++] = A[i++];
        lengthC++;
    }
}

int main()
{
    int a = 0;
    int b = 0;
    array A;
    int choice;
    while (1)
    {
        cout << "1. Add Arrays\n2. Display Arrays\n3. Merge Arrays\n4. Union\n5. Intersection\n6. Difference\n7. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Size of Array A : ";
            cin >> a;
            cout << "Enter size of Array B : ";
            cin >> b;
            A.addarrays(a, b);
            break;
        case 2:
            A.display();
            break;
        case 3:
            A.Merge();
            A.display();
            break;
        case 4:
            A.Union();
            A.display();
            break;
        case 5:
            A.Intersection();
            A.display();
            break;
        case 6:
            A.Difference();
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