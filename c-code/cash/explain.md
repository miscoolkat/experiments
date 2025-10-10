# Understanding the Modulo Operator (%) and Coin Change Example in C

## 🧠 The Idea

The **modulo operator** (`%`) gives you the **remainder** after doing integer division.

Think of it like this:

> If you divide *A* by *B*, the result is how many times *B* fits into *A* —  
> and the **remainder** is what’s *left over* that didn’t fit.

---

## 🔢 Example

Let’s take:

```c
int a = 17;
int b = 5;
int result = a % b;
```

How many times does 5 fit into 17?  
→ 3 times (because 5×3 = 15)  
What’s left over?  
→ 2  

✅ So `17 % 5 == 2`

---

## ⚙️ Division vs. Modulo

| Expression | Meaning | Result |
|-------------|----------|---------|
| `17 / 5` | Integer division | `3` |
| `17 % 5` | Remainder | `2` |

If they were **floats**, `17.0 / 5.0` = `3.4`, but `%` doesn’t work with floats in C.  
For floats, you use `fmod(17.0, 5.0)` from `<math.h>`.

---

## 💰 In Your Example (the “cents” Case)

Imagine you’re making change with coins.  
You want to see what’s *left* after using as many coins of one denomination as possible.

```c
cents %= denominations[i];
```

That line means:

> “Keep only what’s left after using the biggest possible number of coins of value `denominations[i]`.”

### Example:
If you have `cents = 41` and `denominations[i] = 25`  
(quarters are 25 cents)

```c
cents = cents % 25;
```

`41 / 25` = `1` (you can take one quarter)  
`41 % 25` = `16` (you have 16 cents left over)

So now `cents` becomes `16`.

---

## 🧩 In Plain English

`%` = “what’s left after division”

Some analogies:

- 17 % 5 → 2  
  “If you put 17 apples into boxes of 5, you’ll have 2 apples left over.”
- 41 % 25 → 16  
  “If you pay with quarters, you’ll have 16 cents left.”

---

## 🧩 Example: Division vs Remainder in C

```c
#include <stdio.h>

int main(void) {
    int a = 41;
    int b = 25;

    int quotient = a / b;    // integer division
    int remainder = a % b;   // remainder after division

    printf("a = %d, b = %d\n", a, b);
    printf("Quotient (a / b)  = %d\n", quotient);
    printf("Remainder (a %% b) = %d\n", remainder);

    return 0;
}
```

**Output:**

```
a = 41, b = 25
Quotient (a / b)  = 1
Remainder (a % b) = 16
```

---

## 🧩 The Coin Change Example

Here’s the code again:

```c
for (int i = 0; i < n; i++)
{
    coins += cents / denominations[i];
    cents %= denominations[i];
}

printf("%d\n", coins);
```

### Explanation

Let’s assume:

```c
int cents = 41;
int denominations[] = {25, 10, 5, 1};
int n = 4;
int coins = 0;
```

### Step by Step

**i = 0 → denomination = 25**  
```
coins += 41 / 25 → 1
cents %= 25 → 16
```

**i = 1 → denomination = 10**  
```
coins += 16 / 10 → 1
cents %= 10 → 6
```

**i = 2 → denomination = 5**  
```
coins += 6 / 5 → 1
cents %= 5 → 1
```

**i = 3 → denomination = 1**  
```
coins += 1 / 1 → 1
cents %= 1 → 0
```

✅ Total coins used = 4

---

## 🧠 Concept Recap

| Symbol | Meaning | Example | Result |
|---------|----------|----------|---------|
| `/` | Integer division | `41 / 25` | `1` |
| `%` | Remainder (modulo) | `41 % 25` | `16` |

**Together**, they let you compute “how many times” something fits and “what’s left over.”

---

## ✅ In Plain English

> “For each coin type, take as many coins as possible.  
> Add that number to your total count.  
> Then keep only the leftover cents for the next smaller coin.”
