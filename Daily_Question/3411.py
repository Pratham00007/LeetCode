class Solution:
    def maxLength(self, nums):
        best = 2  
        left = 0
        window_product = 1
        for right, num in enumerate(nums):
            while gcd(window_product, num) > 1:  
                window_product //= nums[left]
                left += 1
            window_product *= num
            best = max(best, right - left + 1)
        return best