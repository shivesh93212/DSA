class Solution {
public:
    bool isValidSerialization(string preorder) {
        int ans = 1;

        stringstream ss(preorder);
        string s;

        while (getline(ss, s, ',')) {

       
            if (ans == 0)
                return false;

            if (s == "#") {
                ans--;
            }
            else {
    
                ans++;
            }
        }

        return ans == 0;
    }
};