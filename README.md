# Data Structure

A collection of classic data structure implementations written from scratch in C.

## Structures

| Structure | Folder | Backing storage |
|---|---|---|
| Singly Linked List | [`Linked List V2`](./Linked%20List%20V2) | Dynamically allocated nodes |
| Queue | [`Queue`](./Queue) | Singly linked list (front/tail pointers) |
| Stack | [`Stack V2`](./Stack%20V2) | Dynamic array with fixed capacity |

### Linked List

Implemented in [`Linked List V2/main.c`](./Linked%20List%20V2/main.c).

- `create_node` / `free_list` — node creation and full-list cleanup
- `append_node` / `prepend_node` — insert at the end or the start
- `insert_at_position` — insert at an arbitrary index
- `delete_node` — remove the first node matching a value
- `list_length` — count nodes
- `print_list` — print the list as `[a -> b -> c]`
- `reverse_list` — iterative in-place reversal
- `reverse_list_recursive` — recursive in-place reversal

### Queue

Implemented in [`Queue/main.c`](./Queue/main.c) as a FIFO built on a singly linked list, with `front` and `tail` pointers for O(1) enqueue/dequeue.

- `create_queue` / `free_queue`
- `enqueue` — add to the tail
- `dequeue` — remove and return the front value
- `peek` — read the front value without removing it
- `is_empty`

### Stack

Implemented in [`Stack V2/main.c`](./Stack%20V2/main.c) as a fixed-capacity array-backed LIFO.

- `create_stack` / `free_stack`
- `push` / `pop`
- `peek`
- `isEmpty` / `isFull`

## Building and running

Each structure lives in its own folder with a self-contained `main.c` that includes a small demo in `main()`. Compile and run any one of them with GCC:

```bash
gcc "Linked List V2/main.c" -o linked_list && ./linked_list
gcc "Queue/main.c" -o queue && ./queue
gcc "Stack V2/main.c" -o stack && ./stack
```

## Notes

- Each `main.c` is standalone (no shared headers), so you can compile and read them independently.
- This repo is a personal learning project for practicing data structures and pointer manipulation in C — expect some functions to be commented out or mid-experiment in `main()`.

## License

No license specified.
