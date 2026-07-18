# Queues

Queues are a foundational, linear data structure operating on a First-In, First-Out (FIFO) principle. They model real-world waiting lines and are essential for fairness, order preservation, and breadth-first traversals.

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

A queue is a restricted-access, linear data structure where elements are added at one end (the "rear") and removed from the other (the "front"). This results in a First-In, First-Out (FIFO) ordering. 

Because queues preserve the exact order of insertion, they are the structure of choice for buffering, scheduling, and processing pipelines.

---

## Why It Matters

Software engineers use queues to manage asynchronous data processing, decouple system components, and enforce order fairness.

They are critical in operating systems (task scheduling), networking (packet buffering), messaging systems (RabbitMQ, Kafka), and algorithms (Breadth-First Search). Understanding queues is essential for system design and concurrent programming.

---

## Theory

### Definition
A queue is a collection of elements with two principal operations: `enqueue` (or push), which adds an element to the rear, and `dequeue` (or pop), which removes the element from the front.

### Key Properties
- **FIFO (First-In, First-Out):** The first element enqueued is the first to be dequeued.
- **Two Boundaries:** Unlike a stack which only tracks the top, a queue must maintain pointers to both the front (for removal) and the rear (for insertion).

### Trade-offs
- **Advantages:** $O(1)$ insertions and deletions. Perfectly preserves chronological order.
- **Disadvantages:** Strict boundaries prevent random access. Array-based implementations require careful circular logic to prevent memory waste.

---

## Visual Explanation

```text
Operations: Enqueue(10), Enqueue(20), Enqueue(30), Dequeue()

1. Empty Queue
   [ Front: NULL, Rear: NULL ]

2. Enqueue(10)
   [ Front -> | 10 | <- Rear ]

3. Enqueue(20)
   [ Front -> | 10 | 20 | <- Rear ]

4. Enqueue(30)
   [ Front -> | 10 | 20 | 30 | <- Rear ]

5. Dequeue() -> returns 10
   [ Front -> | 20 | 30 | <- Rear ]
```

---

## Time and Space Complexity

### Common Operations

| Operation | Time Complexity | Space Complexity | Why |
|---|---:|---:|---|
| Enqueue | $O(1)$ | $O(1)$ | Element is added directly at the rear pointer. |
| Dequeue | $O(1)$ | $O(1)$ | Element is removed directly from the front pointer. |
| Peek/Front | $O(1)$ | $O(1)$ | Returns the value at the front without removing it. |
| Search | $O(n)$ | $O(1)$ | Requires iterating through the entire underlying structure. |

### Why These Costs Exist

- Queue operations operate strictly at the boundaries. Regardless of whether the queue holds 10 or 10,000 items, updating the front/rear references takes constant time.

---

## Implementation Overview

Queues are typically implemented in two ways:

### 1. Circular Array
Uses a fixed-size or dynamic array with two index pointers (`front` and `rear`) that wrap around using the modulo operator (`%`).
- **Pros:** Excellent cache locality. No pointer overhead.
- **Cons:** Tricky to implement correctly (circular wrap-around logic). Needs occasional $O(n)$ resizing.

### 2. Singly Linked List (with Tail Pointer)
Uses a linked list where `head` acts as the Front, and `tail` acts as the Rear.
- **Pros:** Conceptually simple. Truly $O(1)$ operations with no resizing required.
- **Cons:** Poor cache locality. Memory overhead for pointers.

*(Note: Dequeuing from a standard array by shifting elements left is $O(n)$ and is an anti-pattern).*

---

## Code Overview

Reference implementations are stored separately under:

- [C++](code/cpp/)
- [Python](code/python/)
- [Pseudocode](code/pseudocode/)

What each example demonstrates:
- **C++:** Demonstrates `std::queue` adapter and a custom Circular Array queue implementation.
- **Python:** Demonstrates `collections.deque` (Double-Ended Queue) because standard Python `list.pop(0)` is $O(n)$.
- **Pseudocode:** Shows the pointer logic for linked-list based Enqueue/Dequeue.

---

## Applications

- **CPU Scheduling:** Operating systems use queues to manage processes waiting for CPU time.
- **Network Buffers:** Routers place incoming packets into queues before processing.
- **Breadth-First Search (BFS):** Graph traversal algorithms use queues to explore level-by-level.
- **Asynchronous Processing:** Message brokers (Kafka, SQS) queue events for asynchronous workers.
- **Print Spooling:** Managing documents sent to a printer.

---

## Interview Questions

1. **How do you implement a Queue using Stacks?**
   By using two stacks: one for enqueuing and one for dequeuing. When the dequeue stack is empty, you pop everything from the enqueue stack into the dequeue stack to reverse the order.

2. **What is a Priority Queue?**
   A specialized queue where elements are dequeued based on priority (usually implemented via a Heap), not strictly FIFO.

3. **Why shouldn't you use a standard array/list as a Queue?**
   Removing the first element (e.g., `list.pop(0)` in Python or shifting an array) is $O(n)$ because all subsequent elements must be shifted over in memory.

---

## Common Mistakes

- **Using a naive array:** Removing from the front of a standard array forces an $O(n)$ shift. You must use a circular array or a Linked List.
- **Memory Leaks in Array Queues:** In a non-circular array queue, the `front` pointer just moves forward. Eventually, you hit the end of the array even if the front of the array is completely empty.
- **Dequeuing an empty queue:** Forgetting to check `isEmpty()`, leading to Underflow exceptions.

---

## Practice Problems

### Easy
- Implement Stack using Queues.
- Number of Recent Calls.
- First Unique Character in a String.

### Medium
- Design Circular Queue.
- Binary Tree Level Order Traversal (BFS).
- Rotten Oranges.

### Hard
- Sliding Window Maximum (using Deque).
- Shortest Path in a Grid with Obstacles Elimination.

---

## Cheat Sheet

- **FIFO:** First-In, First-Out.
- **Core Ops:** `enqueue()`, `dequeue()`, `front()`.
- **Complexity:** $O(1)$ core ops.
- **Best Use Case:** Buffering, scheduling, fairness, BFS.
- **Implementation Warning:** Use Linked List + Tail Pointer, or a Circular Array. *Never shift a standard array.*

---

## References

- *Introduction to Algorithms* (CLRS), MIT Press.
- C++ `std::queue`: https://en.cppreference.com/w/cpp/container/queue
- Python `collections.deque`: https://docs.python.org/3/library/collections.html#collections.deque
