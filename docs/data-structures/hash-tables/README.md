# Hash Tables

Hash Tables (or Hash Maps) are a foundational data structure that map keys to values for highly efficient lookups. They represent one of the most important time-space trade-offs in computer science.

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

A Hash Table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. It uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found.

---

## Why It Matters

Hash Tables are arguably the most used data structure in practical software engineering. Whenever a developer needs to look up a record by an identifier, count frequencies, or cache results (memoization), a hash table is typically the tool of choice.

They power databases (hash indexes), caches (Redis, Memcached), programming language objects (Python dictionaries, JavaScript objects), and routing algorithms.

---

## Theory

### Definition
A Hash Table maps keys to values using a Hash Function to compute an array index.

### Key Properties
- **Hash Function:** A mathematical algorithm that maps data of arbitrary size to a fixed-size integer. A good hash function is deterministic, fast, and uniformly distributes keys to minimize collisions.
- **Collisions:** Because the number of possible keys is theoretically infinite and the array size is finite, two different keys will eventually hash to the same index (Pigeonhole Principle).
- **Load Factor:** The ratio of the number of stored elements to the capacity of the array ($n/k$). As this ratio increases, collisions become more frequent.

### Collision Resolution
1. **Chaining (Open Hashing):** Each bucket is a linked list (or another structure like a BST). Colliding elements are appended to the list at that bucket.
2. **Open Addressing (Closed Hashing):** All elements are stored in the array itself. If a collision occurs, the table probes for the next empty slot using techniques like Linear Probing, Quadratic Probing, or Double Hashing.

### Trade-offs
- **Advantages:** $O(1)$ average-case access, insertion, and deletion.
- **Disadvantages:** $O(n)$ worst-case performance if many collisions occur. High memory overhead compared to simple arrays. They generally do not preserve insertion or sorted order.

---

## Visual Explanation

```text
Key -> Hash Function -> Index -> Bucket (Array)

"apple"  -> hash() % 5 -> 2 -> [ Empty ]
"banana" -> hash() % 5 -> 0 -> [ "banana": 40 ]
"orange" -> hash() % 5 -> 2 -> [ "apple": 20 ] -> [ "orange": 30 ] (Chaining)

Array Buckets:
[0] -> [ "banana": 40 ]
[1] -> Empty
[2] -> [ "apple": 20 ] -> [ "orange": 30 ]
[3] -> Empty
[4] -> Empty
```

---

## Time and Space Complexity

### Common Operations

| Operation | Average Case | Worst Case | Space Complexity |
|---|---:|---:|---|
| Access | $O(1)$ | $O(n)$ | $O(n)$ |
| Search | $O(1)$ | $O(n)$ | $O(n)$ |
| Insertion | $O(1)$ | $O(n)$ | $O(n)$ |
| Deletion | $O(1)$ | $O(n)$ | $O(n)$ |

### Why These Costs Exist

- **Average Case $O(1)$:** A good hash function distributes keys evenly. The constant time includes hashing the key and accessing the array index.
- **Worst Case $O(n)$:** Occurs when every key hashes to the same index, effectively degrading the hash table into a single linked list (if using chaining).
- **Amortized Resizing:** When the load factor exceeds a threshold (e.g., 0.75), the table must be resized and all elements rehashed. This operation is $O(n)$, making insertions *amortized* $O(1)$.

---

## Implementation Overview

### Core Operations
1. **Put(key, value):** Hash the key. Modulo by array capacity to get the index. If empty, insert. If occupied, handle collision (e.g., traverse chain and update if key exists, else append).
2. **Get(key):** Hash the key. Go to the index. Traverse the chain (or probe) until the exact key matches. Return value.
3. **Remove(key):** Hash the key. Go to the index. Traverse the chain (or probe) to find the key and delete it, patching up the links.

---

## Code Overview

This chapter currently focuses on conceptual explanation, collision-handling theory, and interview preparation.

Implementation files can be added later under a topic-local `code/` directory if the chapter expands into worked source examples.

---

## Applications

- **Database Indexing:** Hash indexes for exact-match queries.
- **Caching:** Distributed caches (Redis, Memcached) use hash maps to store stringified objects in memory.
- **Symbol Tables:** Compilers use hash tables to track variable declarations and scope.
- **Sets:** A Set is essentially a Hash Table that only stores keys (no values) to guarantee uniqueness in $O(1)$ time.

---

## Interview Questions

1. **What is a Hash Collision and how do you handle it?**
   A collision occurs when two distinct keys hash to the same index. Handled via Chaining (linked lists at the index) or Open Addressing (finding the next available slot).

2. **Why do Hash Tables resize, and when?**
   They resize to maintain $O(1)$ lookups. As the load factor increases, collisions become more probable, degrading performance. Resizing occurs when the load factor exceeds a set threshold (e.g., 0.75).

3. **What makes a good Hash Function?**
   It must be deterministic (same input = same output), fast to compute, and uniformly distribute keys across the array space to minimize collisions.

4. **When would you choose a Hash Table over a Binary Search Tree (BST)?**
   When you need absolute fastest $O(1)$ lookups and don't care about the order of the data. Use a BST if you need to query ranges, find the closest value, or iterate in sorted order.

---

## Common Mistakes

- **Using mutable objects as keys:** If a key's data changes after it is inserted into the hash table, its hash code changes, making it impossible to retrieve. Keys must be immutable (e.g., Strings, Tuples).
- **Ignoring the load factor:** A poorly configured hash table without automatic resizing will degrade to $O(n)$ time complexity.
- **Assuming order is preserved:** Standard hash tables do not guarantee insertion order (though some modern languages, like Python 3.7+, implement ordered dictionaries by default).

---

## Practice Problems

### Easy
- Two Sum (The classic $O(n)$ hash map solution).
- Contains Duplicate.
- Valid Anagram.

### Medium
- Group Anagrams.
- Longest Consecutive Sequence.
- Subarray Sum Equals K.

### Hard
- Minimum Window Substring.
- LFU Cache.

---

## Cheat Sheet

- **Core Idea:** Key -> Hash Function -> Array Index.
- **Time Complexity:** $O(1)$ average, $O(n)$ worst.
- **Collision Resolution:** Chaining (Linked Lists) or Open Addressing (Probing).
- **Load Factor:** Items / Buckets. Determines when to reallocate memory.
- **Keys:** Must be immutable and hashable.

---

## References

- *Introduction to Algorithms* (CLRS), MIT Press.
- C++ `std::unordered_map`: https://en.cppreference.com/w/cpp/container/unordered_map
- Python `dict`: https://docs.python.org/3/tutorial/datastructures.html#dictionaries
