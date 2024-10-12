#include <iostream>
#define max 100
using namespace std;

int n, arr[max];

class mergesort {
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

    void mergeSort(int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(low, mid);
            mergeSort(mid + 1, high);
            merge(low, mid, high);
        }
    }

    void merge(int low, int mid, int high) {
        int half1 = mid - low + 1;
        int half2 = high - mid;
        int left[half1], right[half2];

        for (int i = 0; i < half1; i++)
            left[i] = arr[low + i];
        for (int i = 0; i < half2; i++)
            right[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = low;
        while (i < half1 && j < half2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < half1) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < half2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    void output() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    mergesort sort;
    sort.input();
    sort.mergeSort(0, n - 1);
    cout << "The Final Sorted Array Is: " << endl;
    sort.output();
    return 0;
}
