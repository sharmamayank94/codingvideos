class Solution {
public:
    int expand(string&s, int lc, int rc)
    {
        int n = s.size();
        while(lc >= 0 && rc < n && s[lc] == s[rc])
        {
            lc--;
            rc++;
        }
        
        return rc - lc -1;
    }
    string longestPalindrome(string s) {
     
        if(s.size()<2) return s;
        
        int start = 0, end = 0, n = s.size();
        
        for(int i = 0; i<n; i++)
        {
            int leno = expand(s, i, i);
            int lene = expand(s, i, i+1);
            
            int len  = max(leno, lene);
            
            if(len > end - start + 1)
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};