#include <iostream>
#include <cmath>
#define max 100
using namespace std;

int n, arr[max], pass = 0;

class radixsort {
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

    int getMax() {
        int maxVal = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    void countingSort(int exp) {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    void radixSort() {
        int maxVal = getMax();

        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            countingSort(exp);
            pass++;
            cout << "The Array after pass no " << pass << " (sorting by " << exp << "'s place) is: " << endl;
            output();
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
    radixsort sort;
    sort.input();
    sort.radixSort();
    cout << "The Final Sorted Array Is: " << endl;
    sort.output();
    return 0;
}
