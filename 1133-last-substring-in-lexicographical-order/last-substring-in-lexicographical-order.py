class Solution:
    def lastSubstring(self, s: str) -> str:
        s = list(s)
        n = len(s)
        
        # Initialize pointers
        start = max(s)
        i = s.index(start)
        j = i + 1
        
        while j < n:
            # Find the next candidate where s[j] >= s[i]
            while j < n and s[j] < s[i]:
                j += 1
            
            if j >= n:
                # If we have reached the end, return the substring from i
                return "".join(s[i:])
            
            # Compare substrings starting from i and j
            l, r = i + 1, j + 1
            while r < n and s[l] == s[r] and l < j:
                l += 1
                r += 1
            
            if r == n:
                # If r reached the end, the substring from i is the result
                return "".join(s[i:])
            
            # Update the index i or j based on the comparison
            if s[l] < s[r]:
                i = j
            else:
                j = r
        
        return "".join(s[i:])