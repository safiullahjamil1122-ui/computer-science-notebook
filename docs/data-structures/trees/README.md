# Trees

Trees are a foundational, non-linear hierarchical data structure. Unlike arrays, stacks, and queues which are strictly linear, trees organize data relationally, branching outward to represent hierarchies.

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

A tree is a connected, acyclic graph. In the rooted-tree variant, one node is designated as the root and edges are usually treated as pointing away from that root.

The most common variant in software engineering is the **Binary Tree**, where each node has at most two children. An extension of this is the **Binary Search Tree (BST)**, which enforces a sorted property on the nodes to enable rapid searching.

---

## Why It Matters

Trees are essential when data naturally forms a hierarchy or when operations require logarithmic $O(\log n)$ performance.

They are the backbone of the Document Object Model (DOM) in web browsers, file systems in operating systems, B-Trees in database indexes, and Abstract Syntax Trees (ASTs) in compilers.

---

## Theory

### Definition
A tree is a non-linear data structure consisting of a root node and zero or more subtrees, connected by edges.

### Terminology
- **Root:** The topmost node.
- **Node:** An entity containing data and pointers to children.
- **Edge:** The connection between two nodes.
- **Leaf:** A node with no children.
- **Height of a Node:** The number of edges on the longest path from the node to a leaf.
- **Depth of a Node:** The number of edges from the root to the node.

### Binary Search Tree (BST) Invariant
In a BST, for any given node:
- All values in the **left subtree** are strictly less than the node's value.
- All values in the **right subtree** are strictly greater than the node's value.

### Trade-offs
- **Advantages:** BSTs provide $O(\log n)$ search, insertion, and deletion on average. They naturally maintain sorted order, allowing for easy range queries.
- **Disadvantages:** If elements are inserted in a sorted order, a standard BST degrades into a linked list with $O(n)$ operations. This necessitates complex self-balancing trees (AVL, Red-Black Trees).

---

## Visual Explanation

```text
Binary Search Tree Example:

        [ 10 ]          <- Root
       /      \
    [ 5 ]    [ 15 ]
   /    \       \
[ 2 ]  [ 7 ]   [ 20 ]   <- Leaves (2, 7, 20)

Traversal Orders:
- Inorder (Left, Node, Right): 2, 5, 7, 10, 15, 20  (Yields sorted order!)
- Preorder (Node, Left, Right): 10, 5, 2, 7, 15, 20
- Postorder (Left, Right, Node): 2, 7, 5, 20, 15, 10
```

---

## Time and Space Complexity (Binary Search Tree)

### Common Operations

| Operation | Average Case (Balanced) | Worst Case (Unbalanced) | Space Complexity |
|---|---:|---:|---|
| Search | $O(\log n)$ | $O(n)$ | $O(n)$ |
| Insertion | $O(\log n)$ | $O(n)$ | $O(n)$ |
| Deletion | $O(\log n)$ | $O(n)$ | $O(n)$ |
| Traversal | $O(n)$ | $O(n)$ | $O(h)$ (Stack space, where h is height) |

### Why These Costs Exist

- **Average $O(\log n)$:** In a balanced tree, every comparison cuts the search space in half.
- **Worst Case $O(n)$:** If the tree becomes skewed (e.g., inserting 1, 2, 3, 4, 5 sequentially), it acts exactly like a Linked List.
- **Space $O(h)$ for Traversal:** Recursive traversals utilize the call stack. The maximum depth of the stack is bounded by the height of the tree ($h$).

---

## Implementation Overview

### Traversal
1. **Depth-First Search (DFS):** Inorder, Preorder, Postorder. Usually implemented using recursion or an explicit Stack.
2. **Breadth-First Search (BFS):** Level-order traversal. Implemented using a Queue.

### Deletion in a BST
Deleting a leaf is trivial. Deleting a node with one child involves replacing the node with its child. Deleting a node with two children is complex: you must find the **Inorder Successor** (the smallest value in the right subtree), replace the target node's value with it, and recursively delete the successor.

---

## Code Overview

This chapter currently focuses on conceptual explanation, traversal theory, and interview preparation.

Implementation files can be added later under a topic-local `code/` directory if the chapter expands into worked source examples.

---

## Applications

- **Databases:** B-Trees and B+ Trees are used extensively to structure indexes on disk to minimize read operations.
- **Routing:** Tries (Prefix Trees) are used for routing tables and autocomplete dictionaries.
- **3D Graphics:** BSP (Binary Space Partitioning) trees are used for rendering engines and collision detection.
- **Compilers:** Parsers generate Abstract Syntax Trees (ASTs) to understand code structure.
- **Compression:** Huffman Coding trees are used to compress data efficiently.

---

## Interview Questions

1. **What is the difference between a Tree and a Graph?**
   A tree is a specialized graph that is acyclic, connected, and has a strict hierarchical root.

2. **Why is an Inorder Traversal of a BST important?**
   Because visiting Left -> Node -> Right in a BST guarantees that you visit nodes in strictly ascending sorted order.

3. **What is a self-balancing tree?**
   A BST that automatically restructures itself (via rotations) during insertions and deletions to guarantee $O(\log n)$ height. Examples include AVL Trees and Red-Black Trees.

4. **How do you find the maximum depth of a binary tree?**
   Using recursion: `1 + max(depth(left), depth(right))`.

---

## Common Mistakes

- **Assuming a standard BST is always $O(\log n)$:** A standard BST offers no balancing guarantees. In an interview, always mention this worst-case $O(n)$ scenario.
- **Overcomplicating BFS/DFS:** DFS requires a Stack (or recursion). BFS requires a Queue. Mixing these up is a fatal error in traversal problems.
- **Mishandling pointers on Deletion:** In C/C++, deleting a node without properly updating its parent's pointers leads to segfaults and dangling pointers.

---

## Practice Problems

### Easy
- Maximum Depth of Binary Tree.
- Invert Binary Tree.
- Symmetric Tree.

### Medium
- Validate Binary Search Tree.
- Lowest Common Ancestor of a Binary Tree.
- Construct Binary Tree from Preorder and Inorder Traversal.

### Hard
- Binary Tree Maximum Path Sum.
- Serialize and Deserialize Binary Tree.

---

## Cheat Sheet

- **Property:** Hierarchical, acyclic.
- **BST Invariant:** Left < Node < Right.
- **Time Complexity:** $O(\log n)$ average, $O(n)$ worst.
- **DFS Traversals:** Preorder, Inorder (sorted), Postorder.
- **BFS Traversal:** Level-order (Queue).

---

## References

- *Introduction to Algorithms* (CLRS), MIT Press.
- Wikipedia: [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
