class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while(n>=1){
            if((n&1)!=0){
                count++;
            };
            n=n>>1;
        }
        return count;
    }
};