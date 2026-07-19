# Computer Science Notebook

A structured knowledge base for Computer Science topics, examples, diagrams, implementations, interview preparation, and revision material.

---

## Table of Contents

- [Overview](#overview)
- [Repository Goals](#repository-goals)
- [Repository Structure](#repository-structure)
- [Current Focus](#current-focus)
- [Getting Around](#getting-around)
- [License](#license)

---

## Overview

This repository is organized as a long-term study and portfolio resource for Computer Science. The goal is to keep concepts, worked examples, and interview preparation in one place with a structure that is easy to navigate and easy to extend.

The repository is designed to read like a professional open-source knowledge base rather than a personal note dump.

---

## Repository Goals

- Build durable revision notes for core Computer Science topics.
- Document concepts with diagrams, examples, and implementation notes.
- Prepare for technical interviews with structured practice material.
- Keep a public portfolio that is clear, consistent, and recruiter-friendly.

---

## Repository Structure

| Folder | Purpose |
|---|---|
| `docs/` | Topic documentation organized by subject area. Some chapters include their own `code/`, `assets/`, and `practice/` folders when implementation material is available. |
| `examples/` | Shared examples spanning multiple topics. Prefer topic-level implementation files for topic-specific concepts. |
| `assets/` | Global diagrams, icons, and supporting images. |
| `references/` | Global curated reference material and source links. |
| `templates/` | Reusable documentation templates (e.g., `topic-template.md`). |
| `cheat-sheets/` | Concise revision-focused summaries. |

---

## Topic Index

### Data Structures
- [Arrays](docs/data-structures/arrays/README.md)
- [Linked Lists](docs/data-structures/linked-lists/README.md)
- [Stacks](docs/data-structures/stacks/README.md)
- [Queues](docs/data-structures/queues/README.md)
- [Hash Tables](docs/data-structures/hash-tables/README.md)
- [Trees](docs/data-structures/trees/README.md)

### Algorithms
- [Sorting Algorithms](docs/algorithms/sorting/README.md)
- [Searching Algorithms](docs/algorithms/searching/README.md)

### Interview Preparation & References
- [Big-O Complexity Cheat Sheet](cheat-sheets/big-o-complexity.md)
- [Behavioral & System Design Patterns](docs/interview-preparation/README.md)

Most topic packages include:
- conceptual explanation,
- memory-layout discussion where relevant,
- complexity analysis,
- implementation overview,
- code examples where present,
- interview questions,
- practice problems.

Interview-preparation notes are documentation-first and intentionally do not follow the same implementation layout.

---

## Getting Around

- Explore topics via the **Topic Index** above.
- View code examples within each topic's respective `code/` directory (e.g., `docs/data-structures/arrays/code/`).
- To add new topic packages, duplicate the [Topic Template](templates/topic-template.md) into the appropriate `docs/` subdirectory.
- If a chapter includes implementation files, keep them close to the topic documentation so the navigation stays local and predictable.

---

## License

MIT
