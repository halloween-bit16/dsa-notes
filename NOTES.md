## Abstract Data Type Specification

An **Abstract Data Type (ADT)** is a mathematical model of a data structure that defines a set of data objects and the operations that can be performed on them, independent of their implementation.

The **specification** of an ADT formally describes:

1. **Data objects** – the type of values stored.
2. **Operations** – the functions/procedures available on the data.
3. **Behavioral rules** – how operations affect the data and their constraints.

⚡ In essence, an ADT specification focuses on **what operations are performed and their effects**, rather than **how these operations are implemented**.

# Differences between- Array and- Linked List

### Definition
-- Array: Collection of elements stored in contiguous memory locations.
-- Linked List: Collection of nodes where each node contains data and a pointer to the next node (non-contiguous memory).

### Memory Allocation
-- Array: Static (fixed size at compile/run time).
-- Linked List: Dynamic (size can grow or shrink at runtime).

### Access Time
- Array: Direct/Random access using index in O(1).
- Linked List: Sequential access, requires traversal in O(n).

### Insertion/Deletion
- Array: Costly (requires shifting elements) → O(n).
- Linked List: Efficient (pointer changes only) → O(1) for beginning/end (if pointer known).

### Memory Utilization
- Array: May waste memory if oversized; overflow if undersized.
- Linked List: No wastage (dynamic allocation), but needs extra memory for pointers.

### Cache Friendliness
- Array: High (contiguous memory).
- Linked List: Low (nodes scattered in memory).

### Implementation Complexity
- Array: Simple to implement.
- Linked List: More complex (requires pointer handling).

### Overhead
- Array: No overhead (stores only data).
- Linked List: Extra memory overhead for storing pointers.

### Resizing
- Array: Difficult (requires new array + copying).
- Linked List: Easy (add/remove nodes dynamically).

### Insertion at End
- Array: O(1) if space available, else O(n) (resize needed).
- Linked List: O(1) if tail maintained, else O(n).

### Deletion at End
- Array: O(1) (just reduce size).
- Linked List: O(n) unless tail + previous pointer maintained.

### Suitable For
- Array: Applications needing fast indexing and fixed-size data.
- Linked List: Applications requiring frequent insertions/deletions and dynamic size.

# Sorting

### Bubble Sort
- Repeatedly swaps adjacent elements if they are in the wrong order.
- Largest element "bubbles" to the end in each pass.
- Number of passes: n-1.
- Best case (already sorted): O(n) (with optimization).
- Worst case: O(n²).
- In-place algorithm, but many swaps → inefficient.

### Selection Sort
- Finds the minimum element in the unsorted part and places it at the beginning.
- Always makes exactly n-1 swaps (efficient swap count).
- Number of comparisons: O(n²) regardless of input order.
- Best case = Worst case = O(n²).
- Good when swaps are costly, bad when comparisons matter.

### Insertion Sort
- Builds the sorted portion one element at a time.
- Takes the next element and inserts it into its correct position among the sorted elements.
- Best case (already sorted): O(n).
- Worst case (reverse order): O(n²).
- Efficient for small arrays or partially sorted arrays.
- Adaptive (performance improves with sorted input).

### Quick Summary:
- Bubble → many swaps, simple but slow.
- Selection → fewer swaps, but always many comparisons.
- Insertion → fast on nearly sorted/small data, adaptive.