class Solution(object):
    def isValid(self, s):
        # An odd-length string can never be valid
        if len(s) % 2 != 0:
            return False
            
        # Map closing brackets to their corresponding opening brackets
        bracket_map = {
            ')': '(',
            ']': '[',
            '}': '{'
        }
        
        stack = []
        
        for char in s:
            # If it's a closing bracket
            if char in bracket_map:
                # Pop the top element if stack is not empty, else use a dummy value
                top_element = stack.pop() if stack else '#'
                
                # If the mapping doesn't match the popped element, it's invalid
                if bracket_map[char] != top_element:
                    return False
            else:
                # If it's an opening bracket, push it onto the stack
                stack.append(char)
                
        # If the stack is empty, all brackets were matched correctly
        return len(stack) == 0
        