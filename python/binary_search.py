def binary_search(list, target):
    first = 0
    last = len(list) - 1

    while first <= last:
        midPoint = (first + last) // 2

        if list[midPoint] == target:
            return midPoint
        elif list[midPoint] < target:
            first = midPoint + 1
        else:
            last = midPoint - 1
    return None


def verify(index):
    if index is not None:
        print("Tsarget found on index", index)
    else:
        print("Target not found in list")


numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

result = binary_search(numbers, 6)
verify(result)
