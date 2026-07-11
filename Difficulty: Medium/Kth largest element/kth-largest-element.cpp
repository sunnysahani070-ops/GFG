class Solution {
public:
    void maxheapify(vector<int>& arr, int i, int n) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxheapify(arr, largest, n);
        }
    }

    int KthLargest(vector<int>& arr, int k) {
        int n = arr.size();

       
        for (int i = n / 2 - 1; i >= 0; i--)
            maxheapify(arr, i, n);

        
        for (int i = n - 1; i >= n - k + 1; i--) {
            swap(arr[0], arr[i]);
            maxheapify(arr, 0, i);
        }

        return arr[0];
    }
};