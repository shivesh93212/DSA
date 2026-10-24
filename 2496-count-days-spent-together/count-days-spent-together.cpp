class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        unordered_map<string, int> mp = {
            {"01", 31}, {"02", 28}, {"03", 31},
            {"04", 30}, {"05", 31}, {"06", 30},
            {"07", 31}, {"08", 31}, {"09", 30},
            {"10", 31}, {"11", 30}, {"12", 31}
        };

        auto convert = [&](string date) {
            int days = 0;

            string month = date.substr(0, 2);
            int day = stoi(date.substr(3, 2));

            for (int i = 1; i < stoi(month); i++) {
                string m = (i < 10 ? "0" : "") + to_string(i);
                days += mp[m];
            }

            return days + day;
        };

        int adA = convert(arriveAlice);
        int ldA = convert(leaveAlice);
        int adB = convert(arriveBob);
        int ldB = convert(leaveBob);

        int start = max(adA, adB);
        int end = min(ldA, ldB);

        if (end < start) {
            return 0;
        }

        return end - start + 1;
    }
};