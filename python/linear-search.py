def liniear_Search(list, target):
    for i in range(0, len(list)):
        if list[i] == target:
            return i
        return None


def verify(index):
    if index is not None:
        print("Tsarget foung on index", index)
    else:
        print("Target not foung in list")


numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

result = liniear_Search(numbers, 6)
verify(result)
