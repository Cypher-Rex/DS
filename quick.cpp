#include <iostream>
#define max 100
using namespace std;

int n, arr[max], i = 0;

class quicksort {
   public:
    void input() {
        cout << "Enter how many elements you want to enter: " << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter element for position " << i + 1 << ": " << endl;
            cin >> arr[i];
        }
        cout << "The Given Array is: " << endl;
        output();
    }

    void quick(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);
            i++;
            cout << "The Array after pass no " << i << " is: " << endl;
            output();
            quick(low, pivotIndex - 1);
            quick(pivotIndex + 1, high);
        }
    }

    int partition(int low, int high) {
        int pivot = arr[low];
        int ipos = low + 1;
        int jpos = high;

        while (ipos <= jpos) {
            while (ipos <= jpos && arr[ipos] <= pivot) {
                ipos++;
            }
            while (ipos <= jpos && arr[jpos] > pivot) {
                jpos--;
            }
            if (ipos < jpos) {
                swap(arr[ipos], arr[jpos]);
            }
        }
        swap(arr[low], arr[jpos]);
        return jpos;
    }

    void output() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    quicksort sort;
    sort.input();
    sort.quick(0, n - 1);
    cout << "The Final Sorted Array Is: " << endl;
    sort.output();
    return 0;
}
