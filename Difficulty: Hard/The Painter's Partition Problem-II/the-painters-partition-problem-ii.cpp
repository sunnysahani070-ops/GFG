class Solution {
    int sum(vector<int>& arr) {
        int total = 0;
        for (int i = 0; i < arr.size(); i++) {
            total += arr[i];
        }
        return total;
    }

    int calc(vector<int>& arr, int mid) {
        int painter = 1;
        int subarea = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (subarea + arr[i] <= mid) {
                subarea += arr[i];
            } else {
                painter++;
                subarea = arr[i];
            }
        }

        return painter;
    }

public:
    int minTime(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = sum(arr);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int m = calc(arr, mid);

            if (m <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
