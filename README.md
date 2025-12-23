<i>This project has been created as part of the 42 curriculum by mnogueir. </i>

# Push Swap

## Description
<b>Push Swap</b> is a program that takes a stack of integers (numbers from -2147483648 to 2147483647) and sorts them, using two stacks and a limited set of operations. Once the integers to be sorted are passed as arguments through the standard input, these are initially stored in <b>stack a</b>. The empty <b>stack b</b> can then serve as temporary storage to facilitate sorting operations. At the end of the program, all items should return to <b>stack a</b>, now sorted in ascending order. During execution, the program will display each instruction used in shorthand (ex. `sa`, for swap a), followed by a newline.
<br>The valid operations avaiable for the program are as follows:

<details><summary>

#### Swap

</summary>
<table align="center">
    <tr>
        <td><code>sa</code></td>
        <td> Swap the first two elements in stack a.</td>
    </tr>
    <tr>
        <td><code>sb</code></td>
        <td> Swap the first two elements in stack b.</td>
    </tr>
    <tr>
        <td><code>ss</code></td>
        <td>Do <b>sa</b> and <b>sb</b>.</td>
    </tr>
</table>
<hr>
</details>
<details><summary>

#### Push

</summary>
<table align="center">
    <tr>
        <td><code>pa</code></td>
        <td> Take the element at top of <b>stack b</b> and put it on top of <b>stack a</b>.</td>
    </tr>
    <tr>
        <td><code>pb</code></td>
        <td> Take the element at top of <b>stack a</b> and put it on top of <b>stack b</b>.</td>
    </tr>
</table>
<hr>
</details>
<details><summary>

#### Rotate

</summary>
<table align="center">
    <tr>
        <td><code>ra</code></td>
        <td>First element of <b>stack a</b> becomes the last.</td>
    </tr>
    <tr>
        <td><code>rb</code></td>
        <td>First element of <b>stack b</b> becomes the last.</td>
    </tr>
    <tr>
        <td><code>rr</code></td>
        <td>Do <b>ra</b> and <b>rb</b>.</td>
    </tr>
</table>
<hr>
</details>
<details><summary>

#### Reverse rotate

</summary>
<table align="center">
    <tr>
        <td><code>rra</code></td>
        <td>Last element of <b>stack a</b> becomes the first.</td>
    </tr>
    <tr>
        <td><code>rrb</code></td>
        <td>Last element of <b>stack b</b> becomes the first.</td>
    </tr>
    <tr>
        <td><code>rrr</code></td>
        <td>Do <b>rra</b> and <b>rrb</b>.</td>
    </tr>
</table>
<hr>
</details>

Ideally, the program should be implemented in such a way as to use the minimum amount of operations possible.
To achieve maximum project validation (100%) and eligibility for bonuses, the program must:
 
- Sort 100 random numbers in fewer than 700 operations.
- Sort 500 random numbers in no more than 5500 operations.<br>

For minimal project validation (which implies a minimum grade of 80%), different thresholds are acceptable:
- 100 numbers in under 1100 operations and 500 numbers in under
8500 operations;
- 100 numbers in under 700 operations and 500 numbers in under
11500 operations;
- 100 numbers in under 1300 operations and 500 numbers in under
5500 operations;

The program will display 'Error' whenever the arguments passed through standard input:
- are not digits;
- are not greater or equal to -2147483648 and lesser or equal to 2147483647;
- contain duplicates.

### Bonus
As a bonus, one can build a simple checker that outputs '<code>OK</code>' if the given set of instructions actually sorts the stack correctly, or '<code>KO</code>' otherwise. This checker must also display '<code>Error</code>' if no instructions are provided or if any of them are malformed.
<br><br>

## Instructions
### Base rules
<h4><code>Make</code></h4>
<hr>
<table>
    <tr>
        <td><code>(empty)</code> | <code>all</code></td>
        <td> Compiles the base program (without checker).</td>
    </tr>
        <tr>
        <td><code>clean</code></td>
        <td>Removes binaries.</td>
    </tr>
        </tr>
        <tr>
        <td><code>fclean</code></td>
        <td>Removes binaries, executable and checker.</td>
    </tr>
        </tr>
        <tr>
        <td><code>bonus</code></td>
        <td>Compiles checker.</td>
    </tr>
        </tr>
        <tr>
        <td><code>re</code></td>
        <td>Does <b>fclean</b> and <b>all</b>.</td>
</table>
<br><br>
Using <code>make</code> with targets <code>500</code>, <code>100</code>, or <code>10</code> will display the total number of operations executed by the program with the given number of random integers. This is done by using the command:
<br><br>
<p align="center">
    <code>./push_swap $(shuf -i 0-2000 -n [number of integers]) | wc -l</code>
</p>
<hr>
<br> 
Whereas using <code>make</code> with targets <code>check_500</code>, <code>check_100</code>, or <code>check_10</code> will run the checker with random values, displaying '<b>OK</b>', '<b>KO</b>', or '<b>Error</b>' accordingly. This is done by using the command:
<br><br>
<p align="center">
    <code>ARG=$(shuf -i 0-2000 -n [number of integers]); ./push_swap $ARG | ./checker $ARG</code>
</p>
<br>
Alternatively, you can use both commands directly in the terminal with different ranges (replacing <code>0-2000</code> with any other limits) or different quantities of integers (replacing the <code>[number of integers]</code> field with any number).  
<br><br>

## How I did it

### Handling the input

We start by receiving the input as an array of strings. To effectively translate them into valid integers, I first assumed that each of these strings could contain a series of numbers separated by white spaces. Therefore, a simple split function was built that - redundancy intended - splits these assortments into valid space-free strings. `cat_array()` then concatenates all these strings into the final array, which will subsequently be converted into a linked list (**stack a**).  
This conversion starts by verifying the validity of the arguments, given the set of constraints discussed earlier. If any of these requirements are not met, the function `error_clear()` is called, freeing the stack and returning `NULL`.

If the argument is a valid integer, `append_node()` will allocate space for a new node and assign the integer to the `value` parameter.  
*While I initially thought of both stacks as integer arrays, adopting the linked list workflow allowed me to better organize the project and simplify my thought process.*

The struct used for my linked list is as follows:

```c
typedef struct s_stack_node
{
    int         value;
    int         index;
    int         push_price;
    int         above_median;
    int         cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;
```

The `prev` pointer of the first node and the `next` pointer of the last node must **ALWAYS** be `NULL`, so we can safely iterate through the list and attach nodes to its head and tail.

---

### Sorting - The Turk algorithm

Once **stack a** is fully initialized, we proceed by checking if it's already sorted using the function `stack_is_sorted`. If it isn't and it contains exactly 3 integers, `tiny_sort()` will be called, since we can easily sort 3 integers by using the `sa`, `ra`, and `rra` operations.  
However, if the stack has more than 3 integers, we will:  
- Use `pb` to push nodes to **stack b**.
- Use `rb` if the value of the node we just pushed to **stack b** is larger than the average of all values in **stack a**—*this small optimization seems crucial to lowering the number of operations to below 5500.*  
- Keep repeating the last two steps until there are only 3 integers in **stack a** or until **stack a** is sorted.

Once we have valid nodes in both **stack a** and **stack b**, we need to push everything back again from **stack b** to **stack a**, but not before prioritizing which nodes must be pushed first and figuring out which operations we have to execute to achieve it.

This can be done by first designating a **target node** - the node before which our current node will be placed. The target node of the current node must be the smallest value node in **stack a** that is still larger than the current node in **stack b**.  

We then assign a **push price** to every node in **stack b**, based on its relative distance to the edges of the stack (head and tail) and its target node's relative distance to the edges of its stack. For example, if a given node is above the median line (in the upper half) of the stack and its target node is also above the median line in its own stack, the push price of **stack b**'s node will be the sum of both nodes' indices.  

After completing the necessary calculations for the push price of every node in **stack b**, we start pushing nodes beginning with the cheapest available - this is determined using `set_cheapest()`.  

We will then rotate both stacks until the cheapest node is at the head of **stack b** and its target is at the head of **stack a** (if that isn't the case already). To minimize the number of operations, we'll use `rr` and `rrr` whenever possible (if both nodes are above the median line or if both nodes are below the median line).  

This process is repeated until every node is pushed from **stack b** to **stack a**, after which we'll rotate **stack a** so that its lowest value node is at the head.

---

### Bonus

The stack should now be sorted. We'll confirm this by using the `get_next_line` function to read the input from our `push_swap` program. `parse_command()` will then check if the input matches any of the available operations and apply it. If everything works as expected and the stack is sorted (confirmed using `stack_is_sorted()`), the checker program will output '`OK`'.

---



<br><br>
## Resources

- On the Turk algorithm: <a href="https://medium.com/@ayogun/push-swap-c1f5d2d41e97">Push Swap — A journey to find most efficient sorting algorithm </a><i>by A. Yigit Ogun;</i>

- Push swap tutorial: <a href="https://www.youtube.com/watch?v=OaG81sDEpVk">
push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)</a><i> by Oceano;</i>
- LIBFT linked list-related exercises.

### AI usage

- Point typos causing bugs;
- Visualizing stack operations via analogies;
- Grammar and spelling check on this very document.