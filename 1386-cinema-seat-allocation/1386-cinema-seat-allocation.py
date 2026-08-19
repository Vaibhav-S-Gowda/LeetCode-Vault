from collections import defaultdict

class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        # Map row -> bitmask of reserved seats (bits 0 to 7 corresponding to seats 2 to 9)
        reserved_rows = defaultdict(int)
        
        for row, seat in reservedSeats:
            if 2 <= seat <= 9:
                # Map seat index 2..9 to bit 0..7
                reserved_rows[row] |= (1 << (seat - 2))
                
        # Base count: Each completely unreserved row can fit 2 groups
        ans = (n - len(reserved_rows)) * 2
        
        # Bitmasks representing required clear seats
        left_mask = 0b00001111   # Seats 2,3,4,5
        middle_mask = 0b00111100 # Seats 4,5,6,7
        right_mask = 0b11110000  # Seats 6,7,8,9
        
        for mask in reserved_rows.values():
            left_possible = (mask & left_mask) == 0
            right_possible = (mask & right_mask) == 0
            
            if left_possible and right_possible:
                ans += 2
            elif left_possible or right_possible or ((mask & middle_mask) == 0):
                ans += 1
                
        return ans