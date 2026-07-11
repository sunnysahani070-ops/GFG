class Solution {
    void minheapify(vector<int>& arr, int i, int n) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < n && arr[l] < arr[smallest])
            smallest = l;

        if (r < n && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minheapify(arr, smallest, n);
        }
    }
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();

       
        for (int i = n / 2 - 1; i >= 0; i--)
            minheapify(arr, i, n);
            
        for (int i = n - 1; i >= n - k + 1; i--) {
            swap(arr[0], arr[i]);
            minheapify(arr, 0, i);
        } 
        return arr[0];
        
    }
};