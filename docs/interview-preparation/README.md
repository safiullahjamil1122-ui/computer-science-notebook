# Interview Preparation

This section consolidates behavioral and architectural patterns designed to help you pass the non-coding portions of technical interviews (e.g., System Design, Behavioral/Leadership, and General Engineering Principles).

---

## Table of Contents

1. [The STAR Method](#the-star-method)
2. [Architectural Principles](#architectural-principles)
3. [System Design Core Concepts](#system-design-core-concepts)
4. [Common Behavioral Questions](#common-behavioral-questions)

---

## The STAR Method

When answering behavioral questions (e.g., "Tell me about a time you..."), always structure your response using the **STAR** framework to ensure clarity and impact.

- **S - Situation:** Set the scene. Give the necessary context (e.g., "At my last job, our database was experiencing frequent timeouts...").
- **T - Task:** Describe your responsibility in that situation (e.g., "I was tasked with identifying the bottleneck and resolving it before the holiday traffic spike.").
- **A - Action:** Explain exactly what *you* did. Do not use "we." Focus on your specific technical contributions (e.g., "I implemented a Redis caching layer for our most frequent read queries and added a composite index to the users table.").
- **R - Result:** Share the outcome, preferably with metrics (e.g., "As a result, API response times dropped by 400ms and we handled the holiday traffic with zero downtime.").

---

## Architectural Principles

During technical discussions, referencing these principles demonstrates a senior-level understanding of software engineering:

### SOLID Principles
- **S** - Single Responsibility Principle: A class should have one, and only one, reason to change.
- **O** - Open/Closed Principle: Software entities should be open for extension, but closed for modification.
- **L** - Liskov Substitution Principle: Objects in a program should be replaceable with instances of their subtypes without altering the correctness of the program.
- **I** - Interface Segregation Principle: Many client-specific interfaces are better than one general-purpose interface.
- **D** - Dependency Inversion Principle: Depend upon abstractions, not concretions.

### DRY (Don't Repeat Yourself)
Avoid duplicating code. If you write the same logic twice, abstract it into a reusable function or component.

### YAGNI (You Aren't Gonna Need It)
Do not build features or abstract layers "just in case" you might need them in the future. Build exactly what is required for the current requirements to avoid premature optimization and technical debt.

---

## System Design Core Concepts

When designing a system on a whiteboard, ensure you cover these fundamental layers:

1. **Scalability:** 
   - *Vertical Scaling (Scale Up):* Adding more power (CPU, RAM) to an existing machine.
   - *Horizontal Scaling (Scale Out):* Adding more machines to the resource pool.
2. **Load Balancing:** Distributing incoming network traffic across a group of backend servers to ensure high availability and reliability.
3. **Caching:** Storing copies of frequently accessed data in a temporary storage location (like Redis or Memcached) to reduce database load and latency.
4. **Database Sharding:** Dividing a massive database into smaller, faster, more easily managed parts called data shards.
5. **CAP Theorem:** In a distributed system, you can only guarantee two out of three: Consistency, Availability, and Partition Tolerance.

---

## Common Behavioral Questions

Prepare 3-4 distinct stories that can be adapted to answer the following:

1. Tell me about a time you had a conflict with a coworker. How did you resolve it?
2. Describe a project that failed. What did you learn?
3. Tell me about a time you had to learn a new technology on the fly.
4. Give an example of a time you received difficult feedback. How did you handle it?
5. Describe a time you went above and beyond your standard responsibilities.
