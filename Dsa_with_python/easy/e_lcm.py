from d_hcf import find_gcd
def lcmAndGcd( A , B):
     # code here 
    gcd=find_gcd(A,B)
    lcm=int(A*B/gcd)
    sol=[lcm,gcd]
    return sol
print(lcmAndGcd(5,6))