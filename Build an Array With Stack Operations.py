class Solution(object):
    def buildArray(self, target, n):
        result = []
        current = 1  # Initialize current number to 1
        
        for num in target:
            # Push numbers from the stream to the stack until we reach the target
            while current < num:
                result.append("Push")
                result.append("Pop")  # To mimic the "Pop" operation
                current += 1
            result.append("Push")  # Push the current number to the stack
            current += 1

        return result
