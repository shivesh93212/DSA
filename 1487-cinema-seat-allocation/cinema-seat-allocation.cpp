class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, vector<int>> mp;

        for(auto &x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }

        long long ans = 2LL * n;

        for(auto &[row, seats] : mp) {
            
            bool left = true;
            bool middle = true;
            bool right = true;

            for(int seat : seats) {
                if(seat >= 2 && seat <= 5)
                    left = false;

                if(seat >= 4 && seat <= 7)
                    middle = false;

                if(seat >= 6 && seat <= 9)
                    right = false;
            }

            // Initially assume this row has 2 families.
            // If both left and right are not possible,
            // remove one family.
            if(left && right) {
                // 2 families possible
            }
            else if(left || middle || right) {
                ans--;
            }
            else {
                ans -= 2;
            }
        }

        return ans;
    }
};