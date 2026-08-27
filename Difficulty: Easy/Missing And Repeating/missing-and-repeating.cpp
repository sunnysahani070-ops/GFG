class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans;

        for(int i = 0; i < arr.size(); i++) {
            int val = abs(arr[i]);

             
            if(arr[val - 1] < 0) {
                ans.push_back(val);
            } else {
                arr[val - 1] = -arr[val - 1];
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            
            if(arr[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};