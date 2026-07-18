def linear_search(values: list[int], target: int) -> int:
    for index, value in enumerate(values):
        if value == target:
            return index
    return -1


def main() -> None:
    values = [12, 27, 31, 45, 58]

    print("Traversal:", end=" ")
    for value in values:
        print(value, end=" ")
    print()

    target = 31
    index = linear_search(values, target)

    if index != -1:
        print(f"Found {target} at index {index}")
    else:
        print(f"{target} was not found")

    values.insert(2, 25)
    print("After insertion:", values)

    del values[2]
    print("After deletion:", values)


if __name__ == "__main__":
    main()