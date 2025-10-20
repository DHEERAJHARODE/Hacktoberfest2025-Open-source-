def matrix_multiply_recursive(A, B):
    # check if matrices can be multiplied
    if len(A[0]) != len(B):
        raise ValueError("Invalid matrix dimensions")

    # initialize result matrix with zeros
    result = [[0 for j in range(len(B[0]))] for i in range(len(A))]

    # recursive multiplication of matrices
    def multiply(A, B, result, i, j, k):
        if i >= len(A):
            return
        if j >= len(B[0]):
            return multiply(A, B, result, i+1, 0, 0)
        if k >= len(B):
            return multiply(A, B, result, i, j+1, 0)
        result[i][j] += A[i][k] * B[k][j]
        multiply(A, B, result, i, j, k+1)

    # perform matrix multiplication
    multiply(A, B, result, 0, 0, 0)
    return result


# example usage
A = [[12, 7, 3], [4, 5, 6], [7, 8, 9]]
B = [[5, 8, 1, 2], [6, 7, 3, 0], [4, 5, 9, 1]]

result = matrix_multiply_recursive(A, B)
for row in result:
    print(row)
