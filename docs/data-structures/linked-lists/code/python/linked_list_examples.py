class Node:
    def __init__(self, value: int, next_node: "Node | None" = None) -> None:
        self.value = value
        self.next = next_node


def insert_front(head: Node | None, value: int) -> Node:
    return Node(value, head)


def traverse(head: Node | None) -> None:
    current = head
    while current is not None:
        print(current.value, end=" ")
        current = current.next
    print()


def main() -> None:
    head: Node | None = None
    head = insert_front(head, 30)
    head = insert_front(head, 20)
    head = insert_front(head, 10)

    traverse(head)


if __name__ == "__main__":
    main()