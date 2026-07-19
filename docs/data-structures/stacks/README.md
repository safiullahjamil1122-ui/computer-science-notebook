# Stacks

Stacks are a foundational, linear data structure operating on a Last-In, First-Out (LIFO) principle. They trade random access for strictly controlled insertion and removal at a single end.

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

A stack is a restricted-access, linear data structure. Elements are added to and removed from the exact same location, known as the "top" of the stack. This inherently results in a Last-In, First-Out (LIFO) ordering. 

Because operations only occur at one end, stacks are incredibly efficient for state management, history tracking, and depth-first traversals.

---

## Why It Matters

Software engineers use stacks when they need to reverse the order of items, backtrack through a sequence of states, or parse recursive structures without using the Call Stack.

They are critical in compilers (syntax parsing), browsers (history/back button), and algorithms (Depth-First Search, backtracking). Recognizing a LIFO pattern is a core competency for technical interviews.

---

## Theory

### Definition
A stack is a collection of elements with two principal operations: `push`, which adds an element to the collection, and `pop`, which removes the most recently added element that was not yet removed.

### Key Properties
- **LIFO (Last-In, First-Out):** The last element pushed is the first to be popped.
- **Restricted Access:** You cannot randomly access elements in the middle of a true stack; you can only interact with the `top`.

### Trade-offs
- **Advantages:** $O(1)$ insertions and deletions. Very low memory overhead.
- **Disadvantages:** Cannot access or search elements arbitrarily without popping everything above them.

---

## Visual Explanation

```text
Operations: Push(10), Push(20), Push(30), Pop()

1. Empty Stack    2. Push(10)     3. Push(20)     4. Push(30)     5. Pop() -> returns 30
                                                               
                                      |    |          | 30 |          |    |
                      |    |          |    |          | 20 |          | 20 |
|    |                | 10 |          | 10 |          | 10 |          | 10 |
+----+                +----+          +----+          +----+          +----+
```

---

## Time and Space Complexity

### Common Operations

| Operation | Time Complexity | Space Complexity | Why |
|---|---:|---:|---|
| Push | $O(1)$ | $O(1)$ | Element is added directly to the pre-tracked top pointer/index. |
| Pop | $O(1)$ | $O(1)$ | Element is removed directly from the top pointer/index. |
| Peek/Top | $O(1)$ | $O(1)$ | Simply returns the value at the top index without modifying it. |
| Search | $O(n)$ | $O(1)$ | Requires popping elements or iterating underlying structure. |

### Why These Costs Exist

- Push and Pop are strictly boundary operations. If the underlying data structure is a dynamic array (with capacity) or a linked list (with a head pointer), updating the boundary takes constant time.

---

## Implementation Overview

Stacks are typically implemented in one of two ways:

### 1. Array-based Stack
Uses a dynamic array with a `top` index. 
- **Pros:** Excellent cache locality. Lower memory overhead per element.
- **Cons:** Occasional $O(n)$ resize when capacity is reached.

### 2. Linked List-based Stack
Uses a singly linked list where elements are inserted/removed at the `head`.
- **Pros:** Truly $O(1)$ push/pop (no resizing). Never wastes memory.
- **Cons:** Poor cache locality. Extra memory overhead for pointers.

---

## Code Overview

This chapter currently focuses on conceptual explanation, implementation trade-offs, and interview preparation.

Implementation files can be added later under a topic-local `code/` directory if the chapter expands into worked source examples.

---

## Applications

- **Call Stack:** Managing function executions, arguments, and local variables in programming languages.
- **Backtracking Algorithms:** Pathfinding, maze solving, and N-Queens.
- **Expression Evaluation:** Parsing postfix (Reverse Polish Notation) or evaluating mathematical strings.
- **Syntax Parsing:** Matching parentheses in compilers and code editors.
- **Undo Mechanisms:** Text editors and software state histories.

---

## Interview Questions

1. **How do you implement a Stack using Queues?**
   By using two queues and making either `push` or `pop` an $O(n)$ operation to simulate LIFO behavior.

2. **How can you design a stack that supports `push`, `pop`, and `getMin()` all in $O(1)$ time?**
   By maintaining a parallel "min stack" that pushes the minimum value seen so far alongside the main stack.

3. **What is a Stack Overflow?**
   An error that occurs when a program exhausts the bounded memory allocated for the call stack, usually due to infinite recursion.

---

## Common Mistakes

- **Popping an empty stack:** Forgetting to check `isEmpty()` before calling `pop()`, leading to runtime exceptions (Underflow).
- **Using a stack when random access is needed:** Stacks are the wrong choice if you frequently need to check what is in the middle.
- **Relying on Python's lists without caution:** Python lists are great stacks, but using `insert(0, val)` turns it into an $O(n)$ operation instead of $O(1)$. Always use `append()` and `pop()`.

---

## Practice Problems

### Easy
- Valid Parentheses.
- Implement Queue using Stacks.
- Next Greater Element.

### Medium
- Min Stack.
- Daily Temperatures.
- Evaluate Reverse Polish Notation.

### Hard
- Largest Rectangle in Histogram.
- Basic Calculator.

---

## Cheat Sheet

- **LIFO:** Last-In, First-Out.
- **Core Ops:** `push()`, `pop()`, `peek()`.
- **Complexity:** $O(1)$ core ops.
- **Best Use Case:** History, reversing order, backtracking, DFS.

---

## References

- *Introduction to Algorithms* (CLRS), MIT Press.
- C++ `std::stack`: https://en.cppreference.com/w/cpp/container/stack
- Python Lists as Stacks: https://docs.python.org/3/tutorial/datastructures.html#using-lists-as-stacks
