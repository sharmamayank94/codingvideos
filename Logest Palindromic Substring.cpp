class Solution {
public:
     // function to expand our search around the center that is this function actually checks the length of current palindromic substring
    // lc and rc deones left center and right center which are same in case of odd length palindromes
    int expand(string&s, int lc, int rc)
    {
        int n = s.size();
        while(lc >= 0 && rc < n && s[lc] == s[rc]) //if we are within bounds then move to left and right if lc and rc are same
        {
            lc--;
            rc++;
        }
        
        return rc - lc -1; // length of current palindromic substring
    }

    //main function whick actually treats every character as center for palindrome teporarily 
    string longestPalindrome(string s) { 
     
        if(s.size()<2) return s;
        
        int start = 0, end = 0, n = s.size();
        
        for(int i = 0; i<n; i++) //looping over all the elements that is treating them as centers/center
        {
            int leno = expand(s, i, i); //for palindromes of odd length there's only 1 center
            int lene = expand(s, i, i+1); //for palindromes of even length there are 2 centers
            
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