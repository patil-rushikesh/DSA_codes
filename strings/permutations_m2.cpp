#include <iostream>
#include <cstring> 
using namespace std;

class string_datatype
{
private:
    char A[100];
    int length = 0;

public:
    void getString()
    {
        cout << "Enter the string: ";
        cin >> A;
        length = strlen(A);
    }

    void perm(int l, int h)
    {
        int i;
        if (l == h)
        {
            cout << A << endl;
        }
        else
        {
            for (i = l; i <= h; i++)
            {
                swap(A[l], A[i]);
                perm(l + 1, h);
                swap(A[i], A[l]); 
            }
        }
    }

    void generatePermutations()
    {
        perm(0, length - 1);
    }
};

int main()
{
    string_datatype str;
    str.getString();
    str.generatePermutations();
    return 0;
}
