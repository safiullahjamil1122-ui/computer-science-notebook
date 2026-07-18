# Sorting Algorithms

Sorting is the process of rearranging a sequence of elements into a specific order (numerical, lexicographical, etc.). It is one of the most rigorously studied domains in computer science because efficiently ordered data is a prerequisite for fast searching algorithms.

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

Sorting algorithms take an unsorted list and return it in a monotonically increasing (or decreasing) order. While languages provide built-in `sort()` functions, understanding *how* data is sorted dictates which algorithm is best suited for memory constraints, nearly-sorted data, or massive datasets that cannot fit in RAM.

---

## Why It Matters

Sorting reduces the complexity of downstream algorithms. A classic example: finding a target element in an unsorted array takes $O(n)$ time. If the array is sorted first, it takes $O(\log n)$ time using Binary Search. 

Additionally, rendering engines sort polygons by depth, databases sort query results, and data pipelines sort logs chronologically.

---

## Theory

### Key Properties

1. **In-place vs. Out-of-place:** 
   - *In-place* algorithms sort the array by swapping elements within the original memory block ($O(1)$ extra space).
   - *Out-of-place* algorithms require allocating additional memory (e.g., Merge Sort requires $O(n)$ extra space).
2. **Stability:** 
   - A *stable* sort preserves the relative order of equal elements. If you sort a list of students by Grade, and then sort by Age, a stable sort ensures that students of the same Age remain sorted by Grade.
3. **Comparison-based vs. Non-comparison:**
   - *Comparison sorts* (Merge, Quick, Bubble) evaluate elements against each other. Their theoretical limit is $O(n \log n)$.
   - *Non-comparison sorts* (Counting Sort, Radix Sort) use integer properties to bypass comparisons, achieving $O(n)$ time under specific constraints.

### Core Algorithms
- **Bubble Sort:** Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. ($O(n^2)$).
- **Merge Sort:** A Divide and Conquer algorithm that recursively splits the array in half, sorts each half, and merges them back together. ($O(n \log n)$, Stable).
- **Quick Sort:** A Divide and Conquer algorithm that picks a "pivot", partitions the array into elements less than and greater than the pivot, and recursively sorts the partitions. ($O(n \log n)$ average, In-place).

---

## Visual Explanation

```text
Merge Sort (Divide and Conquer)

[ 38, 27, 43, 3 ]
       |
  [ 38, 27 ]      [ 43, 3 ]     <- Divide
    |    |          |    |
  [38]  [27]      [43]  [3]     <- Base cases
    \    /          \    /
  [ 27, 38 ]      [ 3, 43 ]     <- Merge & Sort
       \             /
     [ 3, 27, 38, 43 ]          <- Final Merge
```

---

## Time and Space Complexity

### Comparison Table

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable? |
|---|---|---|---|---|---|
| Bubble Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| Insertion Sort| $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| Merge Sort | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Yes |
| Quick Sort | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | No |
| Heap Sort | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(1)$ | No |

### Why These Costs Exist

- **Merge Sort:** Always divides the array in half ($\log n$ levels) and merges them ($n$ work per level). Result: strictly $O(n \log n)$. Requires $O(n)$ space for the temporary merge array.
- **Quick Sort:** On average, the pivot splits the array evenly ($O(n \log n)$). If the pivot is consistently the maximum or minimum (e.g., sorting an already sorted array with a naive pivot), it degrades to $O(n^2)$.

---

## Implementation Overview

### Merge Sort Logic
1. If array length $\le 1$, return.
2. Find the midpoint. Recursively call Merge Sort on `left` and `right`.
3. Create a temporary array. Use two pointers to iterate through `left` and `right`, appending the smaller element to the temp array.
4. Copy the temp array back into the original array.

### Quick Sort Logic
1. Pick a pivot (e.g., the last element).
2. Partition the array: Iterate through, moving elements smaller than the pivot to the left side.
3. Place the pivot exactly between the smaller and larger elements.
4. Recursively call Quick Sort on the left and right partitions.

---

## Code Overview

Reference implementations are stored separately under:

- [C++](code/cpp/)
- [Python](code/python/)
- [Pseudocode](code/pseudocode/)

What each example demonstrates:
- **C++:** Demonstrates an in-place Quick Sort and an out-of-place Merge Sort using standard library vectors.
- **Python:** Demonstrates the conceptual elegance of Quick Sort using list comprehensions (though not strictly in-place).
- **Pseudocode:** Shows the algorithmic swap logic for Bubble Sort.

---

## Applications

- **E-commerce:** Sorting products by price or relevance.
- **Databases:** `ORDER BY` clauses in SQL queries.
- **OS Schedulers:** Sorting processes by priority.
- **Data Compression:** Burrows-Wheeler Transform (used in bzip2) heavily relies on sorting.

---

## Interview Questions

1. **Why is Quick Sort usually preferred over Merge Sort in practice?**
   Quick Sort is in-place ($O(1)$ extra space if we ignore the call stack) and has excellent cache locality, making the constant factors smaller than Merge Sort, which requires allocating and copying to $O(n)$ temporary arrays.

2. **When would you prefer Merge Sort over Quick Sort?**
   When you need a *stable* sort, or when sorting linked lists (where Merge Sort requires no extra space and performs beautifully).

3. **What is the theoretical lower bound for comparison-based sorting?**
   $O(n \log n)$. You cannot sort an arbitrary array faster than this using comparisons.

4. **Is Bubble Sort ever useful?**
   Practically, no. However, Insertion Sort (a similar $O(n^2)$ algorithm) is extremely fast for very small arrays or nearly-sorted arrays, and is often used as the base case in hybrid algorithms like Timsort (Python's default sort).

---

## Common Mistakes

- **Assuming built-in sorts are always Quick Sort:** Many modern languages (Python, Java, Rust) use Timsort (a hybrid of Merge and Insertion sort) because it is stable and highly optimized for real-world data.
- **Naively picking a Quick Sort pivot:** Picking the first or last element as a pivot on an already sorted array triggers the $O(n^2)$ worst case. Always use a random pivot or median-of-three.
- **Forgetting about Stability:** If you sort objects by multiple fields sequentially, using an unstable sort will destroy the previous sort's grouping.

---

## Practice Problems

### Easy
- Sort an Array (Use an $O(n \log n)$ algorithm).
- Merge Intervals.

### Medium
- Sort Colors (Dutch National Flag problem - $O(n)$ time, $O(1)$ space).
- Kth Largest Element in an Array (Quickselect).
- Top K Frequent Elements.

### Hard
- Merge k Sorted Lists.
- Count of Smaller Numbers After Self.

---

## Cheat Sheet

- **Merge Sort:** $O(n \log n)$ time, $O(n)$ space. Stable. Divide & Conquer.
- **Quick Sort:** $O(n \log n)$ avg time, $O(n^2)$ worst. $O(\log n)$ space. Unstable. Fast in practice.
- **Stability:** Maintains relative order of equal elements.
- **In-place:** Uses $O(1)$ auxiliary space.

---

## References

- *Introduction to Algorithms* (CLRS), MIT Press.
- Wikipedia: [Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
