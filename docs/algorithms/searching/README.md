# Searching Algorithms

Searching is the algorithmic process of finding a specific target item within a collection of data. It is a fundamental operation that dictates how we index, traverse, and retrieve information.

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

Searching algorithms are broadly divided into two categories based on the underlying data structure:
1. **Sequential/Interval Searches (Arrays):** Linear Search and Binary Search.
2. **Graph/Tree Traversals:** Breadth-First Search (BFS) and Depth-First Search (DFS).

Choosing the right search depends entirely on whether the data is sorted, unstructured, or strictly relational (graphs/trees).

---

## Why It Matters

Efficient searching is the backbone of user experience. Searching for a user in a database of a billion records using a linear search would take seconds; using binary search (or a B-Tree index) takes microseconds.

BFS and DFS are arguably the two most important algorithms in coding interviews, heavily utilized in pathfinding, AI state exploration, and network analysis.

---

## Theory

### Binary Search
Requires a **sorted** array. It works by repeatedly dividing the search interval in half. If the value of the target is less than the item in the middle, the search continues in the lower half. Otherwise, it searches the upper half.

### Breadth-First Search (BFS)
Explores a tree or graph level by level. It visits all direct neighbors of the starting node before moving deeper.
- **Data Structure:** Queue (FIFO).
- **Primary Use:** Finding the shortest path in an unweighted graph.

### Depth-First Search (DFS)
Explores as far down a single branch as possible before backtracking.
- **Data Structure:** Stack (LIFO) or Recursion (Call Stack).
- **Primary Use:** Topological sorting, detecting cycles, exploring all possible states (backtracking).

---

## Visual Explanation

```text
Binary Search (Target: 7)

[ 2, 4, 5, 7, 9, 12, 15 ]
          ^ Mid (7 == Target? Yes!) -> $O(\log n)$


BFS vs DFS Traversal (Starting at A)

      A
    /   \
   B     C
  / \     \
 D   E     F

BFS Order (Level by Level): A, B, C, D, E, F
DFS Order (Branch by Branch): A, B, D, E, C, F
```

---

## Time and Space Complexity

| Algorithm | Time Complexity | Space Complexity | Notes |
|---|---|---|---|
| Linear Search | $O(n)$ | $O(1)$ | Works on unsorted data. |
| Binary Search | $O(\log n)$ | $O(1)$ | Data **must** be sorted. |
| DFS (Graph) | $O(V + E)$ | $O(V)$ | V = Vertices, E = Edges. Space is for recursion stack/visited set. |
| BFS (Graph) | $O(V + E)$ | $O(V)$ | Space is for the Queue (max width of graph). |

### Why These Costs Exist

- **Binary Search:** Every comparison eliminates half the remaining elements. $N \rightarrow N/2 \rightarrow N/4 \dots$ leading to $\log_2(n)$ steps.
- **Graph Searches ($O(V+E)$):** In the worst case, every node (Vertex) and every connection (Edge) must be visited exactly once.

---

## Implementation Overview

### Binary Search
Use two pointers, `left` and `right`. Calculate `mid = left + (right - left) / 2`. Compare `array[mid]` to target. If smaller, `left = mid + 1`. If larger, `right = mid - 1`. Loop while `left <= right`.

### BFS
1. Push the starting node into a Queue. Mark it as visited.
2. While the Queue is not empty:
   - Pop the front node.
   - For all unvisited neighbors, mark them as visited and push them to the Queue.

### DFS
1. Mark the current node as visited.
2. For all unvisited neighbors, recursively call DFS on them.
*(Alternatively, use a manual Stack instead of recursion).*

---

## Code Overview

Reference implementations are stored separately under:

- [C++](code/cpp/)
- [Python](code/python/)
- [Pseudocode](code/pseudocode/)

What each example demonstrates:
- **C++:** Demonstrates Binary Search avoiding integer overflow on the `mid` calculation.
- **Python:** Demonstrates BFS using `collections.deque` and DFS using a `set` for visited nodes.
- **Pseudocode:** Highlights the purely structural differences between BFS (Queue) and DFS (Stack).

---

## Applications

- **Binary Search:** Git bisect (finding the exact commit that introduced a bug), database lookups, finding roots of mathematical functions.
- **BFS:** GPS navigation (shortest path on maps), web crawlers, social network "degrees of separation".
- **DFS:** Solving mazes, Sudoku solvers, dependency resolution (npm install, Makefiles).

---

## Interview Questions

1. **Why do we use `left + (right - left) / 2` instead of `(left + right) / 2` in Binary Search?**
   To prevent integer overflow in languages like C/C++ or Java if `left` and `right` are very large numbers.

2. **If you need to find the shortest path in a maze, do you use BFS or DFS?**
   BFS. Because it expands radially level-by-level, the first time it hits the destination, it is guaranteed to be the shortest path. DFS might find a long, winding path first.

3. **Can you do Binary Search on a Linked List?**
   Technically yes, but finding the middle element takes $O(n)$ time, destroying the $O(\log n)$ performance benefit.

---

## Common Mistakes

- **Off-by-one errors in Binary Search:** Incorrectly setting `while (left < right)` instead of `<=`, or setting `left = mid` instead of `mid + 1`, resulting in infinite loops.
- **Forgetting a Visited Set in Graphs:** If the graph has cycles, a naive BFS/DFS will loop infinitely. Always track visited nodes.
- **Applying Binary Search to unsorted data:** The algorithm will silently return false negatives.

---

## Practice Problems

### Easy
- Binary Search.
- First Bad Version.
- Flood Fill.

### Medium
- Search in Rotated Sorted Array.
- Find First and Last Position of Element in Sorted Array.
- Number of Islands (DFS/BFS).
- Word Ladder (BFS).

### Hard
- Median of Two Sorted Arrays.
- Alien Dictionary (Topological Sort / DFS).

---

## Cheat Sheet

- **Binary Search:** Requires sorted data. $O(\log n)$ time. 
- **BFS:** Uses a Queue. Best for Shortest Path.
- **DFS:** Uses a Stack / Recursion. Best for Exhaustive Search / Backtracking.
- **Graph Complexity:** Both BFS and DFS are $O(V + E)$.

---

## References

- *Introduction to Algorithms* (CLRS), MIT Press.
- Wikipedia: [Binary Search](https://en.wikipedia.org/wiki/Binary_search_algorithm)
