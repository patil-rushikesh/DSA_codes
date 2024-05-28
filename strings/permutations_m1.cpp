#include <iostream>
#include <cstring> // for strlen
using namespace std;

class string_datatype
{
private:
    char A[100];
    int length = 0;

public:
    void getString()
    {
        cout << "Enter the string : ";
        cin >> A;
        length = strlen(A);
    }

    void perm(char str[], int k)
    {
        static int A[10] = {0};
        static char result[10];
        if (str[k] == '\0')
        {
            result[k] = '\0';
            cout << result << endl;
        }
        else
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                if (A[i] == 0)
                {
                    result[k] = str[i];
                    A[i] = 1;
                    perm(str, k + 1);
                    A[i] = 0;
                }
            }
        }
    }

    void generatePermutations()
    {
        perm(A, 0);
    }
};

int main()
{
    string_datatype str;
    str.getString();
    str.generatePermutations();
    return 0;
}
