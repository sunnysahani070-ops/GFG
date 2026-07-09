class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        if(a==2 && (b==1 || b==3)){
            return true;
        }else if(b==2 && (a==1 || a==3)){
            return true;
        }else{
            return false;
        }
        return false;
    }
};