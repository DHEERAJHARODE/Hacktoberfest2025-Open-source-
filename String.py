from collections import Counter
 
 
def find_dup_char(input):
 
    # now create dictionary using counter method
    # which will have strings as key and their
    # frequencies as value
    WC = Counter(input)
 
    # Finding no. of  occurrence of a character
    # and get the index of it.
    for letter, count in WC.items():
        if (count > 1):
            print(letter)
 
 
# Driver program
if __name__ == "__main__":
    input = 'geeksforgeeks'
    find_dup_char(input)
