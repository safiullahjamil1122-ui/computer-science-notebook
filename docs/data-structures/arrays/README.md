# Arrays

Arrays are a foundational data structure for ordered data. They trade flexibility for speed: direct index access is fast because values live in contiguous memory, but insertions and deletions in the middle require shifting elements.

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

An array is a linear data structure that stores elements in contiguous memory locations. Each element can be accessed directly by its index, which makes arrays one of the fastest structures for read-heavy workloads.

Arrays are a baseline concept in computer science because they show how memory layout, indexing, and cache behavior affect performance.

---

## Why It Matters

Software engineers use arrays because they are simple, predictable, and efficient.

Arrays are common in systems where:

- random access is important,
- the size is known or changes infrequently,
- memory layout affects performance,
- data must be processed sequentially.

They appear in image buffers, game state, operating system tables, numerical computing, and internal runtime structures. Understanding arrays also helps with interview questions involving indexing, complexity analysis, and trade-offs between read and write performance.

---

## Theory

### Definition

An array is an indexed collection of values stored in a single contiguous block of memory.

### Memory Layout

If the base address is $B$ and each element occupies $S$ bytes, the address of element $i$ is computed as:

`B + (i * S)`

This direct calculation is why indexing is constant time.

### Contiguous Memory

Contiguous memory means all elements are placed next to each other in memory. This improves cache locality and makes traversal fast in practice.

### Indexing

Most languages use zero-based indexing. The first element is at index `0`, and the last valid index is `length - 1`.

### Fixed Size

Classic arrays have a fixed capacity. If the structure must grow, a new block of memory is allocated and existing elements are copied.

### Advantages

- Constant-time access by index.
- Good cache locality.
- Low overhead.
- Simple mental model.
- Efficient sequential traversal.

### Disadvantages

- Insertions and deletions in the middle are costly.
- Fixed-size arrays cannot grow without reallocation.
- Resizing requires copying elements.
- Memory may be wasted if extra capacity is reserved.

### Trade-offs

Arrays are the right choice when the workload is read-heavy and access patterns are predictable. They are a weaker choice when frequent structural changes are expected.

---

## Visual Explanation

```text
Index:   0      1      2      3      4
       +------+------+------+------+------+
Value:  | 12   | 27   | 31   | 45   | 58   |
       +------+------+------+------+------+
Address: B    B+S   B+2S   B+3S   B+4S
```

Access by index jumps directly to the target slot:

```text
array[3]

Start at base address B
Add 3 * element_size
Read the value stored at that address
```

Insertion in the middle shifts later elements:

```text
Before: [10][20][30][40]
Insert:          25
After:  [10][20][25][30][40]
```

---

## Time and Space Complexity

### Common Operations

| Operation | Time Complexity | Space Complexity | Why |
|---|---:|---:|---|
| Access by index | $O(1)$ | $O(1)$ | The address is computed directly from the base address and index. |
| Update by index | $O(1)$ | $O(1)$ | Once the element is located, the value is overwritten in place. |
| Traverse | $O(n)$ | $O(1)$ | Every element must be visited once. |
| Linear search | $O(n)$ | $O(1)$ | In the worst case, every element is checked. |
| Insert at end | $O(1)$ amortized | $O(1)$ | Most appends write into spare capacity; resizing is occasional. |
| Insert in middle | $O(n)$ | $O(1)$ | Elements after the insertion point must shift right. |
| Delete in middle | $O(n)$ | $O(1)$ | Elements after the deleted item must shift left. |
| Resize | $O(n)$ | $O(n)$ | A new block is allocated and all elements are copied. |

### Why These Costs Exist

- Indexing is constant time because the runtime does not search for the element.
- Traversal and linear search are linear because every element may need inspection.
- Middle insertions and deletions are linear because contiguous memory must be preserved.
- Resizing is linear because the contents must be copied into a larger block.

---

## Implementation Overview

### Traversal

Start at index `0` and move to the last index. Traversal is the most common array operation and is the foundation for aggregation, filtering, and transformation.

### Searching

Use linear search when the array is unsorted. Use binary search when the array is sorted and random access is available.

### Insertion

Insertions at a position require shifting later elements right. If capacity is exhausted, a resize must occur first.

### Deletion

Deletion removes an element and shifts later values left to keep the structure compact and contiguous.

### Resizing

Dynamic arrays typically grow by allocating a larger block, copying the elements, and replacing the old storage. This reduces the frequency of expensive full copies.

---

## Code Overview

Reference implementations are stored separately under:

- [C++](code/cpp/array_examples.cpp)
- [Python](code/python/array_examples.py)
- [Pseudocode](code/pseudocode/array_examples.pseudo)

What each example demonstrates:

- The C++ example shows contiguous storage, traversal, and linear search using a fixed-size array.
- The Python example shows index-based operations and common list behavior, which mirrors dynamic array semantics.
- The pseudocode example shows the algorithmic structure without language-specific syntax.

---

## Applications

Arrays are used in production systems for:

- Image Processing: pixel buffers, convolution windows, and channel data.
- Game Development: animation frames, entity lists, and collision grids.
- Databases: page buffers, record batches, and in-memory row storage.
- AI: vectors, embeddings, tensors, and training batches.
- Operating Systems: process tables, interrupt tables, and kernel buffers.
- Graphics: vertex buffers, index buffers, and color arrays.
- Scientific Computing: matrices, numerical grids, and simulation state.

---

## Interview Questions

1. What is an array?
   An array is an ordered collection of values stored in contiguous memory.

2. Why is array access fast?
   Because the target address is computed directly from the index.

3. What does contiguous memory mean?
   It means elements are stored next to each other without gaps in logical order.

4. Why are arrays often fixed size?
   Because the memory is allocated as one continuous block.

5. What is the time complexity of indexing?
   $O(1)$.

6. Why is insertion in the middle expensive?
   Because later elements must be shifted to preserve order.

7. Why is deletion in the middle expensive?
   Because later elements must shift left to fill the gap.

8. When is linear search appropriate?
   When the array is unsorted or the dataset is small.

9. When is binary search appropriate?
   When the array is sorted and random access is available.

10. What is the main advantage of arrays over linked lists?
    Faster indexed access and better cache locality.

11. What is the main disadvantage of arrays over linked lists?
    More expensive insertions and deletions in the middle.

12. What is a dynamic array?
    An array-like structure that grows by reallocating and copying.

13. Why is append often amortized $O(1)$?
    Because most appends use spare capacity and resizing happens occasionally.

14. Why do arrays perform well in practice?
    Because contiguous memory improves cache efficiency.

15. Where are arrays used most often?
    In graphics, operating systems, databases, AI, and scientific computing.

---

## Common Mistakes

- Off-by-one errors when iterating over the first or last element.
- Confusing length with the last valid index.
- Assuming middle insertion is constant time.
- Forgetting that fixed arrays do not grow automatically.
- Using arrays for workloads dominated by structural edits.
- Ignoring cache locality when comparing array-based structures with pointer-heavy ones.

---

## Practice Problems

### Easy

- Traverse an array and print each element.
- Find the maximum and minimum values.
- Count how many times a value appears.

### Medium

- Rotate an array by $k$ positions.
- Remove duplicates from a sorted array.
- Find the second largest element.

### Hard

- Implement a dynamic array with resizing.
- Solve maximum subarray sum.
- Merge two sorted arrays in place.

---

## Cheat Sheet

- Arrays store values in contiguous memory.
- Indexing is $O(1)$.
- Traversal and search are $O(n)$.
- Middle insertion and deletion are $O(n)$.
- Dynamic array append is amortized $O(1)$.
- Arrays are best for fast reads and predictable access.

---

## References

- Cormen, Leiserson, Rivest, and Stein, *Introduction to Algorithms*.
- cppreference: https://en.cppreference.com/
- Python Documentation: https://docs.python.org/3/
- MIT OpenCourseWare: https://ocw.mit.edu/
