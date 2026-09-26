class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string >mp;
        int n = knowledge.size();
        for( int i=0;i<n;i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        string ans="";
        string temp="";
        bool check=false;
        for(auto & ch : s){
           if(ch=='('){
            check=true;
            continue;
           }
           if(ch==')'){
            check=false;
            if(mp.count(temp)){
                ans+=mp[temp];
                temp="";
            }

            else{
                ans+="?";
            }
            temp="";
            continue;
           }
           if(check){
            temp+=ch;
           }
           else{
            ans+=ch;
           }
        }
        return ans;
    }
};