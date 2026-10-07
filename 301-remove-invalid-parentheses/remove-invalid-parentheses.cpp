class Solution {
public:
    vector<string> ans;
    int minRemoved;

    void solve(string &s, int i, int o, int c,
               int removed, string &temp) {

        if (removed > minRemoved)
            return;

        if (i == s.size()) {
            if (o == c) {

                if (removed < minRemoved) {
                    minRemoved = removed;
                    ans.clear();
                }

                if (removed == minRemoved) {
                    ans.push_back(temp);
                }
            }
            return;
        }

        // Remove current character
        solve(s, i + 1, o, c,
              removed + 1, temp);

        // Keep current character
        temp.push_back(s[i]);

        if (s[i] == '(') {

            solve(s, i + 1, o + 1, c,
                  removed, temp);

        }
        else if (s[i] == ')') {

            if (c < o) {
                solve(s, i + 1, o, c + 1,
                      removed, temp);
            }

        }
        else {

            solve(s, i + 1, o, c,
                  removed, temp);
        }

        temp.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {

        // Calculate minimum removals
        int balance = 0;
        minRemoved = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {

                if (balance > 0)
                    balance--;
                else
                    minRemoved++;
            }
        }

        minRemoved += balance;

        string temp = "";
        solve(s, 0, 0, 0, 0, temp);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};