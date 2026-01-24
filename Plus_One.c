int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int carry = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i] += carry;
            carry = 0;
            break;
        }
    }

    if (carry) {
        *returnSize = digitsSize + 1;
        int* result = malloc(*returnSize * sizeof(int));
        result[0] = 1;
        for (int i = 1; i < *returnSize; i++) {
            result[i] = 0;
        }
        return result;

    } else {
        *returnSize = digitsSize;
        return digits;
    }
}
