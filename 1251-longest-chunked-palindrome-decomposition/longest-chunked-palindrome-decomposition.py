class Solution:
    def longestDecomposition(self, s: str) -> int:
        left, right, chunk_count = 0, len(s) - 1, 0
        
        while left < right:
            # Check if the start and end substrings match
            if s[:left + 1] == s[right:]:
                chunk_count += 2  # Two matching chunks found
                s = s[left + 1:right]  # Update s to remaining substring
                left, right = 0, len(s) - 1  # Reset pointers
            else:
                left += 1
                right -= 1
        
        # Add one if there's any substring left (middle character)
        if s:
            chunk_count += 1
        
        return chunk_count