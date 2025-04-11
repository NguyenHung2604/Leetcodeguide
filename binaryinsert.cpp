#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm kiếm nhị phân để tìm vị trí chèn
int binarySearch(vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < item)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

// Hàm sắp xếp chèn nhị phân
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Tìm vị trí chèn cho phần tử hiện tại
        int loc = binarySearch(arr, key, 0, j);

        // Dịch chuyển các phần tử để chèn key vào đúng vị trí
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
    binaryInsertionSort(arr);

    cout << "Mang sau khi sap xep giam dan: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}