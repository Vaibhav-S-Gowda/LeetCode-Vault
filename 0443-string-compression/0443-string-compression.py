class Solution(object):
    def compress(self, chars):
        write = 0
        read = 0
        
        while read < len(chars):
            char = chars[read]
            count = 0
            
            # Count consecutive occurrences of current character
            while read < len(chars) and chars[read] == char:
                read += 1
                count += 1
            
            # Write character to array
            chars[write] = char
            write += 1
            
            # Write count digits if count > 1
            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1
                    
        return write