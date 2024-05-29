#include <iostream>
using namespace std;
class matrix
{
private:
    int *A; // Pointer to stroe matrix
    int n;  // var to store dimension
public:
    matrix(int);             // Pass dimension in param constructor
    void set(int, int, int); // Param = row,column, element
    int get(int, int);       // Param = row,column. It returns integer element
    void display();
    ~matrix();
};
matrix::matrix(int n)
{
    this->n = n;
    A = new int[n];
}
void matrix::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}
int matrix::get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return 0;
    }
}
void matrix::display()
{
    // Pass matrix directly
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
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
    matrix m(4);
    m.set(1, 1, 5);
    m.set(2, 2, 8);
    m.set(3, 3, 9);
    m.set(4, 4, 12);
    cout << m.get(2, 2) << endl;
    m.display();
    return 0;
}