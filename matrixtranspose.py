def transpose(mat):
    rn = len(mat)
    cn = len(mat[0])
    tmat = []
    for i in range(cn):
        col = []
        for j in range(rn):
            col.append(mat[j][i])
        tmat.append(col)
    return tmat
