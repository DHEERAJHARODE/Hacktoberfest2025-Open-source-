# ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

# Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

## This implementation only applies to letters in alphabet a-z 
## Need to fix and include special characters/ numbers 

def rot13 string, final_string_arr = []
    alphabet_arr = ('a'..'z').to_a
    string_arr = string.split ""
    ref_obj = {}
    rot_13 = 13
    # intial construction of object cypher
    alphabet_arr.each_with_index do |letter, indx|
        if indx <= 12
            ref_obj[letter] = alphabet_arr[indx + rot_13]
        elsif
            ref_obj[letter] = alphabet_arr[indx - rot_13]
        end
    end
    # constructing a string from key value parirs to encrypt message
    string_arr.each do |letter|
        if is_upper?(letter)
            final_string_arr.push ref_obj[letter.downcase].upcase
        else 
            final_string_arr.push ref_obj[letter]
        end
    end
    final_string_arr.join ""
end

def is_upper? char
    if char.downcase != char
        true
    end 
end

p rot13 "TEst"
