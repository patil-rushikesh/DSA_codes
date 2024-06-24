#include <iostream>
using namespace std;

// Class definition for a min heap
class heap {
    int *H;       // Pointer to array of elements in the heap
    int n;        // Current number of elements in the heap
    int capacity; // Maximum possible number of elements in the heap

public:
    heap(int capacity = 100); // Constructor with default capacity
    void create();            // Function to create a heap from user input
    void heapify(int i);      // Function to maintain the heap property
    void insert(int key);     // Function to insert a new element into the heap
    void deleteNode();        // Function to delete the root element from the heap
    void display();           // Function to display the heap elements
    void sort();              // Function to sort the elements of the heap
    ~heap();                  // Destructor to free allocated memory
};

// Constructor to initialize heap with given capacity
heap::heap(int capacity) {
    this->capacity = capacity; // Set the capacity of the heap
    H = new int[capacity];     // Allocate memory for the heap array
    n = 0;                     // Initialize the number of elements in the heap to zero
}

// Function to create a heap from user input
void heap::create() {
    int x;
    cout << "Enter Total No. of elements: ";
    cin >> n; // Read the number of elements to be added to the heap
    for (int i = 0; i < n; i++) {
        cout << "Enter Element " << i << ": ";
        cin >> x; // Read each element
        H[i] = x; // Insert element into the heap array
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(i); // Call heapify for each non-leaf node
    }
}

// Function to maintain the heap property for a subtree rooted at index i
void heap::heapify(int i) {
    int smallest = i;     // Initialize smallest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (left < n && H[left] < H[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && H[right] < H[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(H[i], H[smallest]); // Swap root with the smallest element

        // Recursively heapify the affected sub-tree
        heapify(smallest);
    }
}

// Function to insert a new element into the heap
void heap::insert(int key) {
    if (n == capacity) {
        cout << "Heap overflow! Cannot insert key." << endl;
        return; // If heap is full, print an error message and return
    }

    // First insert the new key at the end
    n++;
    int i = n - 1;
    H[i] = key;

    // Fix the heap property if it is violated
    while (i != 0 && H[(i - 1) / 2] > H[i]) {
        swap(H[i], H[(i - 1) / 2]); // Swap with parent if necessary
        i = (i - 1) / 2;            // Move to parent index
    }
}

// Function to delete the root element from the heap
void heap::deleteNode() {
    if (n <= 0) {
        cout << "Heap underflow! Cannot delete key." << endl;
        return; // If heap is empty, print an error message and return
    }
    if (n == 1) {
        n--; // If only one element, remove it
        return;
    }

    // Move the last element to root and reduce the size of the heap
    H[0] = H[n - 1];
    n--;
    heapify(0); // Call heapify to restore the heap property
}

// Function to display the heap elements
void heap::display() {
    for (int i = 0; i < n; ++i)
        cout << H[i] << " "; // Print each element
    cout << endl;
}

// Function to sort the elements of the heap
void heap::sort() {
    int originalSize = n; // Store the original size of the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(H[0], H[i]);

        // Reduce the size of the heap
        n--;

        // Restore the heap property
        heapify(0);
    }

    // Restore the original heap size
    n = originalSize;
}

// Destructor to free allocated memory
heap::~heap() {
    delete[] H; // Deallocate memory for the heap array
}

// Main function to demonstrate heap operations
int main() {
    heap h;
    h.create(); // Create heap from user input
    cout << "Heap array: ";
    h.display(); // Display heap elements

    h.insert(50); // Insert a new element
    cout << "After inserting 50: ";
    h.display(); // Display heap elements

    h.deleteNode(); // Delete the root element
    cout << "After deleting root: ";
    h.display(); // Display heap elements

    h.sort(); // Sort the heap elements
    cout << "Heap array after sorting: ";
    h.display(); // Display sorted elements

    return 0;
}
