class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        # Idea is something like this for the nontrivial xor != 0 case:
        #   if length is even: not all the numbers are the same, otherwise xor would be zero.
        #      in addition: two+ unique numbers, so one+ is != xor. So Alice can delete that number without setting xor to zero
        #      Therefore Alice has a guaranteed play if N % 2 == 0 and xor != 0
        #    Then Bob faces a couple of cases:
        #       1. if each unique number he picks results in xor == 0, he loses
        #       2. if Bob picks a safe number, then he passes it back to Alice with xor != 0 and an even number
        #           we know that Alice always has a safe play from here. She does that safe play: goto (1)

        xor = 0
        for n in nums:
            xor ^= n

        return xor == 0 or len(nums) % 2 == 0