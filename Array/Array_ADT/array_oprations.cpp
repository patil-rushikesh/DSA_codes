#include <iostream>
using namespace std;
    int *p;
    int length = 0;
void display()
{
    cout<<"Array : ";
    if(length == 0){
        cout<<"No elements to Display\n";
    }else{
        for(int i = 0; i < length; i++){
            cout<<p[i]<<"  ";
        }
        cout<<endl;
    }
}
void append(int element)
{
    p[length] = element;
    length++;
}
void insert(int index, int element)
{
    for(int i = length; i < index; i--){
        p[i] = p[i-1];
    }
    p[index] = element;
    length++;
}
void delete_elem(int index)
{
    for(int i = index; i < length-1; i++){
        p[i] = p[i+1];
    }
    length--;
}
int linear_s(int const key)
{
    for(int i = 0; i < length; i++){
        if(key == p[i]){
            return i;
        }
    }
    return -1;
}
int linear_transp(int key)
{
    for(int i = 0; i < length; i++){
        if(key == p[i]){
            swap(p[i],p[i-1]);
            return i-1;
        }
    }
    return -1;
}
int linear_tohead(int key)
{
        for(int i = 0; i < length; i++){
        if(key == p[i]){
            swap(p[i],p[0]);
            return 0;
        }
    }
    return -1;
}
int main()
{
    p = new int[100];
    int choice;
    int x;
    int y;
    int position;
    while (1)
    {
        cout << "\n1. Display Array\n2. Append Array\n3. Insert Element\n4. Delete Element\n5. Linear Search\n6. Linear Search and Transposition\n7. Linear Search and Move to Head\n8. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1: // Display Array
            display();
            break;
        case 2: // Apped Element
            
            cout << "Enter Element to append : ";
            cin >> x;
            append(x);
            cout << "Element Added\n";
            display();
            break;
        case 3: // Insert Element
            
            cout << "Enter Index : ";
            cin >> x;
            cout << "Enter Data : ";
            cin >> y;
            insert(x, y);
            cout << "Element Inserted\n";
            display();
            break;
        case 4: // Delete Element
            
            cout << "Enter Index : ";
            cin >> x;
            delete_elem(x);
            cout << "Element Deleted\n";
            display();
            break;
        case 5: // Linear Search only
            
            position = linear_s(x);
            if (position != -1)
            {
                cout << "Element found at : " << position;
            }
            else
            {
                cout << "Element Not found\n";
            }
            break;
        case 6: // Linear Search and transposition
            
            position = linear_transp(x);
            if (position != -1)
            {
                cout << "Element found at : " << position;
                cout << "Array Modified !\n";
                display();
            }
            else
            {
                cout << "Element Not found\n";
            }
            break;
        case 7: // Linear Search and move to head
            
            position = linear_tohead(x);
            if (position != -1)
            {
                cout << "Element found at : " << position;
                cout << "Array Modified !\n";
                display();
            }
            else
            {
                cout << "Element Not found\n";
            }
            break;
        case 8:
            delete []p;
            return 0;
        default:
            cout << "Invalid Choice!!\n";
            break;
        }
    }
}