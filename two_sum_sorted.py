def two_sum(numbers: list[int], target: int) -> list[int]:
    """
    Given a sorted list of numbers, returns the 1-based indices of two elements
    whose sum equals the target using two-pointer approach.
    """
    left, right = 0, len(numbers) - 1

    while left < right:
        current_sum = numbers[left] + numbers[right]
        if current_sum == target:
            return [left + 1, right + 1]  # 1-based indices
        elif current_sum < target:
            left += 1
        else:
            right -= 1

    return []  # No solution found


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    print("Input:", nums)
    print("Target:", target)
    print("Output:", two_sum(nums, target))
