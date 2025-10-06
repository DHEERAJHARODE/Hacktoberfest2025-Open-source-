def set_zeroes(matrix: list[list[int]]) -> None:
    """
    Modifies the input matrix in place such that if an element is 0,
    its entire row and column are set to 0.
    """
    rows, cols = len(matrix), len(matrix[0])
    first_row_has_zero = any(matrix[0][j] == 0 for j in range(cols))
    first_col_has_zero = any(matrix[i][0] == 0 for i in range(rows))

    # Mark zeros using first row and first column
    for i in range(1, rows):
        for j in range(1, cols):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0

    # Set rows and columns to zero based on marks
    for i in range(1, rows):
        if matrix[i][0] == 0:
            for j in range(cols):
                matrix[i][j] = 0

    for j in range(1, cols):
        if matrix[0][j] == 0:
            for i in range(rows):
                matrix[i][j] = 0

    # Handle first row and column separately
    if first_row_has_zero:
        for j in range(cols):
            matrix[0][j] = 0

    if first_col_has_zero:
        for i in range(rows):
            matrix[i][0] = 0


if __name__ == "__main__":
    mat = [
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1]
    ]

    print("Before:")
    for row in mat:
        print(row)

    set_zeroes(mat)

    print("\nAfter:")
    for row in mat:
        print(row)
