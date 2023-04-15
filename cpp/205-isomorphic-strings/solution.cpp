class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()){return false;}

        array<int, 256> hs = {0};
        array<int, 256> ht = {0};

        for (int i=0; i<s.size(); i++) {
            char tc = t[i], sc = s[i];
            if (hs[sc] != ht[tc]) {
                return false;
            }
            hs[sc] = i+1;
            ht[tc] = i+1;
        }

        return true;
    }
};
