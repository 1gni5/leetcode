class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) {return false;}
        if (s == t) {return true;}

        int i = 0;
        for (int j=0; j<t.size(); j++) {
            if (t[j] == s[i]) {i++;}
            if (i == s.size()) {return true;}
        }

        return false;
    }
};
