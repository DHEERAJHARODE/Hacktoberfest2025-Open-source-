from collections import Counter

def max_distinct_after_removals(nums, k):
    freq = Counter(nums)
    duplicates = []
    distinct_count = 0
    for val, count in freq.items():
        if count == 1:
            distinct_count += 1
        else:
            duplicates.append(count - 1)
    duplicates.sort()
    for dup_count in duplicates:
        if k >= dup_count:
            k -= dup_count
        else:
            return distinct_count
    if k > 0:
        distinct_count -= k
        distinct_count = max(0, distinct_count)
    return distinct_count


if __name__ == "__main__":
    nums = list(map(int, input("Enter elements of array: ").split()))
    k = int(input("Enter k: "))
    print(max_distinct_after_removals(nums, k))
