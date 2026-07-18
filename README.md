# Arrays

Arrays are one of the most fundamental data structures in computer science. They provide a simple, efficient way to store ordered collections of elements and form the basis for many higher-level abstractions used in software systems, interview problems, and performance-critical code.

---

## Table of Contents

- [Overview](#overview)
- [Why It Matters](#why-it-matters)
- [Theory](#theory)
- [Visual Explanation](#visual-explanation)
- [Time & Space Complexity](#time--space-complexity)
- [Implementation Overview](#implementation-overview)
- [Code Examples](#code-examples)
- [Real-World Applications](#real-world-applications)
- [Interview Questions](#interview-questions)
- [Common Mistakes](#common-mistakes)
- [Practice Problems](#practice-problems)
- [Cheat Sheet](#cheat-sheet)
- [References](#references)

---

## Overview

An array is a linear data structure that stores a fixed-size sequence of elements in contiguous memory. Each element is accessible through an index, which makes arrays ideal when fast lookup and predictable memory access are important.

Arrays are easy to reason about, efficient for sequential traversal, and widely supported across programming languages. They are also the foundation for many other structures, including strings, matrices, vectors, stacks, and queues.

---

## Why It Matters

Software engineers use arrays because they offer a strong balance of simplicity, speed, and memory efficiency. When the size of the data is known or changes infrequently, arrays often provide the best practical representation.

Arrays appear in real systems everywhere:

- Rendering pipelines use arrays for pixel buffers, vertex lists, and image data.
- Operating systems use arrays to manage tables, descriptors, and cached state.
- Databases use array-like structures internally for pages, buffers, and in-memory records.
- AI and machine learning systems use arrays and tensors for numerical computation.
- Game engines use arrays for entities, animation frames, collision data, and spatial grids.
- Scientific computing relies on arrays for matrix operations, simulation state, and numerical methods.

For interviews, arrays are essential because they test core understanding of indexing, memory layout, complexity analysis, and trade-offs between read-heavy and write-heavy workloads.

---

## Theory

### Definition

An array is an indexed collection of elements stored in a single, continuous block of memory. Most arrays contain values of the same type, which allows the runtime or compiler to calculate the address of any element efficiently.

### Memory Layout

Arrays are laid out sequentially in memory. If the first element starts at address $B$ and each element has size $S$, then the element at index $i$ is typically located at:

`address = B + (i * S)`

This is the reason array access is fast: the location of any element can be computed directly instead of being searched.

### Contiguous Memory

Contiguous memory means that all elements are stored next to each other without gaps between logical elements. This improves cache locality, which often leads to better performance in practice because CPUs can fetch neighboring data efficiently.

### Indexing

Arrays use zero-based indexing in many languages, meaning the first element is at index 0. Indexing provides direct access to any valid element in constant time.

### Fixed Size

Classic arrays usually have a fixed capacity decided at creation time. If more space is needed, a new larger array must be allocated and the existing elements copied into it. Dynamic array implementations automate this process.

### Advantages

- Constant-time random access by index.
- Excellent cache performance due to contiguous memory.
- Simple representation and predictable behavior.
- Low overhead compared with pointer-heavy structures.
- Efficient traversal and bulk processing.

### Disadvantages

- Fixed size in many implementations.
- Insertion and deletion in the middle require shifting elements.
- Resizing can be expensive when capacity is exceeded.
- Wasted space may occur if capacity is reserved but unused.

### Trade-offs

Arrays optimize for fast reads and predictable layout, but they are less flexible for frequent structural changes. In practice, the best choice depends on whether the workload is read-heavy, write-heavy, or size-unpredictable.

---

## Visual Explanation

An array of integers may look like this in memory:

```text
Index:   0      1      2      3      4
  +------+------+------+------+------+
Value:  | 12   | 27   | 31   | 45   | 58   |
  +------+------+------+------+------+
Address: B    B+S   B+2S   B+3S   B+4S
```

Direct access uses the index to jump straight to the correct slot:

```text
array[3]

Start at B
  + 3 * S
  = address of value 45
```

If an element is inserted in the middle, later elements must move:

```text
Before:
[10][20][30][40]

Insert 25 at index 2:

[10][20][25][30][40]
  ^ shift right
```

---

## Time & Space Complexity

### Common Operations

| Operation | Time Complexity | Space Complexity | Why |
|---|---:|---:|---|
| Access by index | $O(1)$ | $O(1)$ | The element address is computed directly from the base address and index. |
| Update by index | $O(1)$ | $O(1)$ | Once the element is located, overwriting it takes constant time. |
| Traverse | $O(n)$ | $O(1)$ | Every element must be visited once. |
| Linear search | $O(n)$ | $O(1)$ | In the worst case, every element may need to be checked. |
| Insert at end | $O(1)$ amortized for dynamic arrays | $O(1)$ | Appending usually writes into available capacity; occasional resize makes some operations more expensive. |
| Insert in middle | $O(n)$ | $O(1)$ | Elements after the insertion point must be shifted to make room. |
| Delete in middle | $O(n)$ | $O(1)$ | Elements after the removed item must be shifted left to close the gap. |
| Resize | $O(n)$ | $O(n)$ | A larger block must be allocated and all existing elements copied. |

### Why These Costs Occur

- Direct indexing is constant time because array addresses are computed, not discovered.
- Traversal and search are linear because arrays do not know which element you want unless you provide its index.
- Insertions and deletions in the middle are expensive because memory remains contiguous, so neighboring values must be moved.
- Dynamic resizing is costly because it creates a new block of memory and copies existing data into it.

### Practical Note

Dynamic arrays often provide excellent real-world performance because expensive resizes happen infrequently. That is why append-heavy workloads still perform well even though the worst-case append operation is linear.

---

## Implementation Overview

Arrays are usually implemented in one of two ways: as fixed-size native arrays provided by the language runtime, or as dynamic arrays built on top of fixed-size storage.

### Traversal

Traversal starts at index 0 and visits each element in order until the last index is reached. This is the most common way to process array data.

### Searching

Searching can be done with a linear scan when the array is unsorted. If the array is sorted, binary search can be used to reduce the search cost significantly.

### Insertion

Insertion at a specific position requires shifting elements to the right. If the array is full, the storage must first be expanded before insertion can occur.

### Deletion

Deletion removes the target element and shifts later elements left to preserve the contiguous layout and logical order.

### Resizing

Resizing is commonly implemented by allocating a larger block of memory, copying the existing elements, and then replacing the old storage. Many dynamic arrays grow geometrically to reduce the frequency of copying.

---

## Code Examples

Reference implementations are stored separately under:

- `code/cpp/`
- `code/python/`
- `code/pseudocode/`

These examples are intended to demonstrate the same concepts in multiple forms:

- C++ examples show low-level array behavior, indexing, and memory-sensitive operations.
- Python examples show readable implementations and dynamic array usage patterns.
- Pseudocode examples show algorithm structure without language-specific syntax.

---

## Real-World Applications

- Image Processing: pixel buffers, convolution windows, and image channels.
- Game Development: sprite sheets, animation frames, physics state, and entity storage.
- Databases: page caches, result buffers, and internal record arrays.
- AI: feature vectors, embeddings, tensors, and training batches.
- Operating Systems: process tables, interrupt tables, and kernel buffers.
- Graphics: vertex arrays, index buffers, color arrays, and transformation data.
- Scientific Computing: matrices, numerical grids, simulation state, and time series.

---

## Interview Questions

1. What is an array?
  An array is an ordered collection of elements stored in contiguous memory.

2. Why is array access fast?
  Because the address of an element can be computed directly from its index.

3. What does contiguous memory mean?
  It means array elements are stored back-to-back in memory.

4. Why are arrays often fixed size?
  Because their memory is allocated as one continuous block.

5. What is the time complexity of accessing an array element by index?
  $O(1)$.

6. Why is insertion in the middle expensive?
  Because elements after the insertion point must be shifted.

7. Why is deletion in the middle expensive?
  Because elements must be shifted left to fill the gap.

8. When is linear search used?
  When the array is unsorted or when no better index structure exists.

9. When is binary search possible?
  When the array is sorted and random access is available.

10. What is the main advantage of arrays over linked lists?
  Faster direct access and better cache locality.

11. What is the main disadvantage of arrays over linked lists?
  Costly insertions and deletions in the middle.

12. What is a dynamic array?
  An array that grows automatically by allocating larger storage and copying elements.

13. Why does dynamic array append have amortized $O(1)$ complexity?
  Because most appends are constant time, and resizing happens occasionally.

14. Why do arrays often perform well in practice?
  Because contiguous memory improves cache efficiency.

15. Where are arrays commonly used?
  In graphics, operating systems, databases, scientific computing, and AI systems.

---

## Common Mistakes

- Off-by-one errors when iterating from the first to the last index. Use consistent loop bounds and verify whether the upper bound is inclusive or exclusive.
- Confusing array length with the last valid index. The last valid index is always `length - 1`.
- Assuming insertion and deletion are constant time. They are only constant at the end in some dynamic array implementations.
- Forgetting that arrays may be fixed size. Check whether the language uses native arrays or a resizable abstraction.
- Ignoring cache behavior. Arrays can outperform more flexible structures because they preserve locality.
- Using arrays when frequent middle insertions are required. In that case, a different structure may be more appropriate.

---

## Practice Problems

### Easy

- Traverse an array and print each element.
- Find the maximum and minimum values in an array.
- Count how many times a value appears in an array.

### Medium

- Rotate an array by $k$ positions.
- Remove duplicates from a sorted array.
- Find the second largest element in an array.

### Hard

- Implement an array-based dynamic buffer with resizing.
- Solve maximum subarray sum.
- Merge two sorted arrays in-place.

---

## Cheat Sheet

- Arrays store elements in contiguous memory.
- Index-based access is $O(1)$.
- Traversal and search are $O(n)$.
- Insertion and deletion in the middle are $O(n)$.
- Appending to a dynamic array is amortized $O(1)$.
- Arrays are best for fast reads, predictable layout, and cache-friendly workloads.
- Arrays are less suitable when the size changes frequently or middle insertions dominate.

---

## References

- Cormen, Leiserson, Rivest, and Stein, *Introduction to Algorithms*.
- *Introduction to Algorithms* (CLRS), MIT Press.
- cppreference: https://en.cppreference.com/
- Python Documentation: https://docs.python.org/3/
- MIT OpenCourseWare: https://ocw.mit.edu/
