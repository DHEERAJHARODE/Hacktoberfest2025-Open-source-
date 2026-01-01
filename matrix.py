def add_matrices(matrix1, matrix2):
    rows = len(matrix1)
    cols = len(matrix1[0])
    result = []

    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)

    return result


# Example usage
A = [
    [1, 2, 3],
    [4, 5, 6]
]

B = [
    [7, 8, 9],
    [1, 2, 3]
]

sum_matrix = add_matrices(A, B)
print("Matrix Addition Result:")
for r in sum_matrix:
    print(r)

