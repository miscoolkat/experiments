
# Experiments
This is a repository where my dad and I can have fun with programming together.

Dad was here :) ...

## Repository Structure


### C Programs

- [`c/cash/`](c/cash): Cash-related programs ([cash.c](c/cash/cash.c), [cash2.c](c/cash/cash2.c))
- [`c/credit/`](c/credit): Credit card validator ([credit.c](c/credit/credit.c))
- [`c/pyramid/`](c/pyramid): Prints a pyramid ([pyramid.c](c/pyramid/pyramid.c))
- [`c/tree/`](c/tree): Christmas tree generators ([tree.c](c/tree/tree.c), [tree2.c](c/tree/tree2.c))

#### How to Compile and Run C Programs

Navigate to the folder containing the `.c` file and run:

```bash
gcc filename.c -o outputname
./outputname
```

For example, to compile and run the credit card validator:

```bash
cd c/credit
gcc credit.c -o credit
./credit
```

For the animated tree (requires a terminal that supports ANSI escape codes):

```bash
cd c/tree
gcc tree2.c -o tree2
./tree2
```

#### Notes
- Some programs (like `credit.c`) may require the CS50 library. See instructions above for installing and linking CS50.
- The animated tree uses ANSI escape codes for color and animation.


### JavaScript Programs

- [`javascript/`](javascript): Christmas tree generators and animations ([christmas_tree.js](javascript/christmas_tree.js), [christmas_tree2.js](javascript/christmas_tree2.js))

To run a JavaScript program:

```bash
cd javascript
node christmas_tree2.js
```

---
Have fun experimenting!