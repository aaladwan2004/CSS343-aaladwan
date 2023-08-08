class Solution {
public:
    bool isIsomorphic(string s, string t) {

    unordered_map<char, char> ST; // map s to t
    unordered_map<char, char> TS; // map t to s

    for (int i = 0; i < s.size(); ++i) {
        if (ST.count(s[i]) > 0 && ST[s[i]] != t[i])
            return false; // mismatch in s

        if (TS.count(t[i]) > 0 && TS[t[i]] != s[i])
            return false; // mismatch in t

        // Update mapping
        ST[s[i]] = t[i]; 
        TS[t[i]] = s[i]; 
    }

    return true; // S and T are isomorphic
    }
};
