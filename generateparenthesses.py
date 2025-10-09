def generateParenthesis(n):
    result = []

    def backtrack(current, open_count, close_count):
        # Base case: when the string is complete
        if len(current) == 2 * n:
            result.append(current)
            return
        
        # Add '(' if we still can
        if open_count < n:
            backtrack(current + '(', open_count + 1, close_count)
        
        # Add ')' only if it won't make it invalid
        if close_count < open_count:
            backtrack(current + ')', open_count, close_count + 1)
    
    backtrack("", 0, 0)
    return result


# Example usage:
print(generateParenthesis(3))
