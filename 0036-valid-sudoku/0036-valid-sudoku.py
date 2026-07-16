class Solution(object):
    def isValidSudoku(self, board):
        seen = set()
        for r in range(9):
            for c in range(9):
                num = board[r][c]
                if num != ".":
                    row_key = (r, num)
                    col_key = (num, c)
                    box_key = (r//3, c//3, num)

                    if row_key in seen or col_key in seen or box_key in seen:
                        return False
                    
                    seen.add(row_key)
                    seen.add(col_key)
                    seen.add(box_key)

        return True
        