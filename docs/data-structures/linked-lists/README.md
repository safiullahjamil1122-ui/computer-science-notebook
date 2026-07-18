# Linked Lists

Linked lists are a fundamental linear data structure used to model ordered data with frequent insertions and deletions. They trade direct indexing for flexible node-based growth, which makes them useful when memory movement would be expensive.

---

## Table of Contents

- [Overview](#overview)
- [Why It Matters](#why-it-matters)
- [Theory](#theory)
- [Visual Explanation](#visual-explanation)
- [Time and Space Complexity](#time-and-space-complexity)
- [Implementation Overview](#implementation-overview)
- [Code Overview](#code-overview)
- [Applications](#applications)
- [Interview Questions](#interview-questions)
- [Common Mistakes](#common-mistakes)
- [Practice Problems](#practice-problems)
- [Cheat Sheet](#cheat-sheet)
- [References](#references)

---

## Overview

A linked list is a linear data structure made of nodes. Each node stores data and a reference to the next node, and in doubly linked lists also a reference to the previous node.

Unlike arrays, linked lists do not require contiguous memory. That makes insertion and deletion at known positions more flexible, but random access is slower because nodes must be traversed one by one.

---

## Why It Matters

Software engineers use linked lists when data changes often and preserving contiguous memory is not worth the cost.

Linked lists appear in:

- memory allocators and free lists,
- graph and tree adjacency representations,
- undo and redo systems,
- queue and deque implementations,
- kernel and runtime internals,
- cache eviction structures such as LRU lists.

For interviews, linked lists test pointer reasoning, traversal logic, and the ability to choose the right data structure for the workload.

---

## Theory

### Definition

A linked list is a chain of nodes where each node stores a value and a link to the next node. In a doubly linked list, each node also links back to the previous node.

### Memory Layout

Nodes may be scattered throughout memory. The structure is connected through pointers rather than by physical adjacency.

### Contiguous Memory

Linked lists do not depend on contiguous memory. This avoids copying large blocks when the structure changes, but it reduces cache locality compared with arrays.

### Indexing

Linked lists do not support constant-time indexing. To reach the node at position $i$, the list must be traversed from the head.

### Fixed Size

Linked lists are not fixed-size in the same way arrays are. Nodes can be allocated as needed until memory is exhausted.

### Advantages

- Efficient insertion and deletion when the node location is already known.
- No need for contiguous memory.
- Flexible growth.
- Natural fit for pointer-based algorithms.

### Disadvantages

- Slow random access.
- Extra memory overhead for node references.
- Poor cache locality.
- More complex pointer handling.

### Trade-offs

Linked lists improve structural flexibility but sacrifice fast indexing and cache-friendly traversal. They are a better fit for workloads that mutate frequently and a poor fit for read-heavy indexed access.

---

## Visual Explanation

```text
Singly linked list

[10 | next] -> [20 | next] -> [30 | next] -> null
```

Traversal follows pointers from left to right:

```text
head -> node1 -> node2 -> node3 -> null
```

Insertion at the front is constant time:

```text
Before: head -> [20] -> [30]
Insert 10:
After:  head -> [10] -> [20] -> [30]
```

---

## Time and Space Complexity

### Common Operations

| Operation | Time Complexity | Space Complexity | Why |
|---|---:|---:|---|
| Access by index | $O(n)$ | $O(1)$ | The list must be traversed node by node. |
| Search | $O(n)$ | $O(1)$ | The target may be anywhere in the chain. |
| Insert at head | $O(1)$ | $O(1)$ | Only a few pointers must be updated. |
| Insert at tail | $O(1)$ with tail pointer, otherwise $O(n)$ | $O(1)$ | Tail access may require traversal unless a tail reference exists. |
| Delete at head | $O(1)$ | $O(1)$ | The head pointer moves to the next node. |
| Delete in middle | $O(n)$ | $O(1)$ | The predecessor node must be found first. |
| Traversal | $O(n)$ | $O(1)$ | Each node is visited once. |

### Why These Costs Occur

- Traversal is linear because nodes are visited in sequence.
- Searching is linear because linked lists do not provide direct addressing.
- Head operations are constant because only a small number of pointers change.
- Middle operations are slower when the target node must first be located.

---

## Implementation Overview

### Traversal

Start at the head and follow next pointers until null is reached.

### Searching

Compare each node value while walking the list. This is necessary because the list does not support direct indexing.

### Insertion

To insert before or after a node, adjust the surrounding pointers so the chain remains connected.

### Deletion

To delete a node, bypass it by reconnecting its neighbors, then release its memory if the language requires manual management.

### Resizing

Linked lists do not resize as arrays do. Instead, new nodes are allocated individually as the structure grows.

---

## Code Overview

Reference implementations are stored separately under:

- [C++](code/cpp/linked_list_examples.cpp)
- [Python](code/python/linked_list_examples.py)
- [Pseudocode](code/pseudocode/linked_list_examples.pseudo)

What each example demonstrates:

- The C++ example shows node allocation, traversal, and insertion at the head.
- The Python example shows list node structure and traversal logic.
- The pseudocode example shows pointer-based operations without language syntax.

---

## Applications

Linked lists are used in:

- operating system free lists and scheduler queues,
- browser history and undo stacks,
- LRU cache implementations,
- adjacency lists for graphs,
- memory management systems,
- runtime and interpreter internals.

---

## Interview Questions

1. What is a linked list?
   A linked list is a node-based linear structure where each node points to the next node.

2. Why use a linked list instead of an array?
   When frequent insertions and deletions matter more than random access.

3. What is the disadvantage of linked lists?
   Random access is slow and pointer management is more complex.

4. What is the time complexity of searching in a linked list?
   $O(n)$.

5. What is the time complexity of inserting at the head?
   $O(1)$.

6. What is the time complexity of deleting the head?
   $O(1)$.

7. Why is insertion in the middle usually $O(n)$?
   Because the list must first be traversed to find the insertion point.

8. What is the difference between singly and doubly linked lists?
   Doubly linked lists store both next and previous references.

9. Why do linked lists have poor cache locality?
   Their nodes may be scattered in memory.

10. When is a linked list a bad choice?
    When fast indexing is required.

11. What is a tail pointer?
    A reference to the last node, which can make tail insertion faster.

12. What is a sentinel node?
    A dummy node used to simplify boundary cases.

13. What is the main memory cost of linked lists?
    Extra pointer storage per node.

14. Why are linked lists useful in graphs?
    They can represent adjacency efficiently.

15. What should you check before choosing a linked list?
    Whether the workload favors updates over random access.

---

## Common Mistakes

- Losing the reference to the next node during insertion or deletion.
- Forgetting to update the head when operating on the first node.
- Assuming linked lists support indexing efficiently.
- Ignoring the extra memory cost of node pointers.
- Using a linked list when the workload is mostly reads and indexing.

---

## Practice Problems

### Easy

- Traverse a singly linked list.
- Insert a node at the head.
- Count the number of nodes.

### Medium

- Reverse a singly linked list.
- Detect whether a linked list contains a cycle.
- Find the middle node.

### Hard

- Merge two sorted linked lists.
- Remove the nth node from the end.
- Implement a doubly linked list with insert and delete operations.

---

## Cheat Sheet

- Linked lists store nodes connected by pointers.
- Random access is $O(n)$.
- Head insertion and deletion are $O(1)$.
- Tail insertion is $O(1)$ if a tail pointer exists.
- Linked lists trade cache locality for structural flexibility.

---

## References

- Cormen, Leiserson, Rivest, and Stein, *Introduction to Algorithms*.
- cppreference: https://en.cppreference.com/
- Python Documentation: https://docs.python.org/3/
- MIT OpenCourseWare: https://ocw.mit.edu/
