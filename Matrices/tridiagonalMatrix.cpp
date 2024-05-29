#include <iostream>
using namespace std;

class matrix
{
private:
    int *A;
    int n;

public:
    matrix(int n);
    int index(int i, int j);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~matrix();
};

matrix::matrix(int n)
{
    this->n = n;
    A = new int[3 * n - 2]; // Allocate memory for tridiagonal matrix
}

// Calculate the index for storing elements in the array
int matrix::index(int i, int j)
{
    if (i - j == 1)
    {
        return i - 2; // Lower diagonal
    }
    else if (i - j == 0)
    {
        return n - 1 + i - 1; // Main diagonal
    }
    else if (i - j == -1)
    {
        return 2 * n - 1 + i - 1; // Upper diagonal
    }
    return -1; // This case should not occur for a tridiagonal matrix
}

void matrix::set(int i, int j, int x)
{
    if (i - j == 1 || i - j == 0 || i - j == -1)
    {
        A[index(i, j)] = x;
    }
}

int matrix::get(int i, int j)
{
    if (i - j == 1 || i - j == 0 || i - j == -1)
    {
        return A[index(i, j)];
    }
    else
    {
        return 0;
    }
}

void matrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 1 || i - j == 0 || i - j == -1)
            {
                cout << A[index(i, j)] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

matrix::~matrix()
{
    delete[] A;
}

int main()
{
    int n;
    cout << "Enter Dimension: ";
    cin >> n;
    matrix m(n);

    int i, j, x;

    cout << "Enter all elements row by row:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            m.set(i, j, x);
        }
    }

    cout << "\nMatrix:\n";
    m.display();

    return 0;
}