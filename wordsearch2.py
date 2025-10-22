class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None  # Store the word when we reach its end

class Solution:
    def findWords(self, board, words):
        # Step 1: Build Trie
        root = TrieNode()
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.word = word  # mark the end of the word

        rows, cols = len(board), len(board[0])
        found = set()

        # Step 2: Define DFS function
        def dfs(r, c, node):
            char = board[r][c]
            if char not in node.children:
                return

            next_node = node.children[char]
            if next_node.word:
                found.add(next_node.word)

            # mark visited
            board[r][c] = '#'

            # explore neighbors (up, down, left, right)
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != '#':
                    dfs(nr, nc, next_node)

            # restore after exploring
            board[r][c] = char

            # optimization: remove the word if it’s already found
            if not next_node.children:
                node.children.pop(char)

        # Step 3: Search each cell
        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root)

        return list(found)
