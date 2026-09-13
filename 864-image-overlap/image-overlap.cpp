class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m = img1[0].size();

        int ans = 0;

        // Down + Right
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = 0;

                for(int k = i; k < n; k++) {
                    for(int l = j; l < m; l++) {
                        if(img1[k-i][l-j] == 1 && img2[k][l] == 1) {
                            temp++;
                        }
                    }
                }

                ans = max(ans, temp);
            }
        }

        // Up + Left
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = 0;

                for(int k = 0; k < n-i; k++) {
                    for(int l = 0; l < m-j; l++) {
                        if(img1[k+i][l+j] == 1 && img2[k][l] == 1) {
                            temp++;
                        }
                    }
                }

                ans = max(ans, temp);
            }
        }

        // Down + Left
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = 0;

                for(int k = i; k < n; k++) {
                    for(int l = 0; l < m-j; l++) {
                        if(img1[k-i][l+j] == 1 && img2[k][l] == 1) {
                            temp++;
                        }
                    }
                }

                ans = max(ans, temp);
            }
        }

        // Up + Right
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = 0;

                for(int k = 0; k < n-i; k++) {
                    for(int l = j; l < m; l++) {
                        if(img1[k+i][l-j] == 1 && img2[k][l] == 1) {
                            temp++;
                        }
                    }
                }

                ans = max(ans, temp);
            }
        }

        return ans;
    }
};