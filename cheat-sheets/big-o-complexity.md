# Big-O Complexity Cheat Sheet

This cheat sheet provides a quick-reference guide for the time and space complexities of common data structures, sorting algorithms, and traversals.

*Use this for rapid revision before technical interviews.*

---

## Data Structures

| Data Structure | Access (Avg) | Search (Avg) | Insertion (Avg) | Deletion (Avg) | Worst Case (All) | Space |
|---|:---:|:---:|:---:|:---:|:---:|:---:|
| **Array** | $O(1)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Stack** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| **Queue** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| **Linked List** | $O(n)$ | $O(n)$ | $O(1)$* | $O(1)$* | $O(n)$ | $O(n)$ |
| **Hash Table** | N/A | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| **Binary Search Tree** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ | $O(n)$ |
| **AVL / Red-Black Tree** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ |

*\*Insertion and Deletion in a Linked List are $O(1)$ only if you already possess a pointer to the target node.*

---

## Sorting Algorithms

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable? | In-Place? |
|---|:---:|:---:|:---:|:---:|:---:|:---:|
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes | Yes |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes | Yes |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Yes | No |
| **Quick Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | No | Yes |
| **Heap Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(1)$ | No | Yes |
| **Counting Sort** | $O(n + k)$ | $O(n + k)$ | $O(n + k)$ | $O(k)$ | Yes | No |

*\*Space complexity for Quick Sort is $O(\log n)$ due to the recursive call stack.*

---

## Searching & Traversals

| Algorithm | Time | Space | Best For |
|---|:---:|:---:|---|
| **Binary Search** | $O(\log n)$ | $O(1)$ | Finding elements in a *sorted* array. |
| **Breadth-First Search (BFS)** | $O(V + E)$ | $O(V)$ | Finding the *shortest path* in unweighted graphs. |
| **Depth-First Search (DFS)** | $O(V + E)$ | $O(V)$ | Exhaustive search, backtracking, topological sort. |

---

## Complexity Rankings

From fastest to slowest (for large $n$):
1. $O(1)$ - Constant
2. $O(\log n)$ - Logarithmic
3. $O(n)$ - Linear
4. $O(n \log n)$ - Linearithmic
5. $O(n^2)$ - Quadratic
6. $O(2^n)$ - Exponential
7. $O(n!)$ - Factorial
