"""
    Returns the nth Fermat number: F_n = 2^(2^n) + 1 for any positive 'n'.
"""


def fermat_number(n):

    if n < 0:
        raise ValueError("n must be a non-negative integer")
    return 2 ** (2 ** n) + 1

# Example usage:
for i in range(6):
    print(f"F_{i} = {fermat_number(i)}")