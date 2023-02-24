![License](https://img.shields.io/github/license/aardzark/hackerrank_c_solutions?color=%236295CB&style=flat)
![HitCount](https://img.shields.io/endpoint?color=%236295CB&url=https%3A%2F%2Fhits.dwyl.com%2Faardzark%2FHackerRank_C_Solutions.json)
![Languages](https://img.shields.io/github/languages/count/aardzark/hackerrank_c_solutions?color=%236295CB&style=flat)
![Top Language](https://img.shields.io/github/languages/top/aardzark/hackerrank_c_solutions?color=%236295CB&style=flat)
![Last Commit](https://img.shields.io/github/last-commit/aardzark/hackerrank_c_solutions?color=%236295CB&style=flat)
<div>
<h1>
  <div align="center">
    <a href="https://www.hackerrank.com/zacharyromepera1"><img src="https://repository-images.githubusercontent.com/231893793/cec60480-04a9-11eb-80c4-df7359d94047" width="200"></a>
    <br>
    <a href="https://www.hackerrank.com">HackerRank</a> C Challenge Solutions
  </div>
  <br>
  <div align="left">
    Index
  </div>
</h1>
</div>

- [Introduction](#introduction)
  - ["Hello World!" in C](#hello-world-in-c-easy)
  - [Playing with Characters](#playing-with-characters-c-easy)
- [Structs and Enums](#structs-and-enums)
  - [Boxes through a Tunnel](#boxes-through-a-tunnel-easy)
  - [Small Triangles, Large Triangles](#small-triangles-large-triangles-medium)

# Introduction

## "Hello World!" in C: Easy

### Objective

In this challenge, we will learn some basic concepts of C that will get you started with the language. You will need to use the same syntax to read input and write output in many C challenges. As you work through these problems, review the code stubs to learn about reading from stdin and writing to stdout.

### Task

This challenge requires you to print `Hello, World!` on a single line, and then print the already provided input string to [stdout](https://en.wikipedia.org/wiki/Standard_streams#Standard_output_.28stdout.29). If you are not familiar with C, you may want to read about the printf() command.

#### [Solution](./Introduction/hello_world_in_c.c)

## Playing With Characters: Easy

### Objective

This challenge will help you to learn how to take a character, a string and a sentence as input in C.

To take a single character `ch` as input, you can use `scanf("%c", &ch );` and `printf("%c", ch)` writes a character specified by the argument char to stdout.

```
char ch;
scanf("%c", &ch);
printf("%c", ch);
```

This piece of code prints the character `ch`.

You can take a string as input in C using `scanf(“%s”, s)`. But, it accepts string only until it finds the first space.

In order to take a line as input, you can use `scanf("%[^\n]%*c", s);` where ```s``` is defined as `char s[MAX_LEN]`
where `MAX_LEN` is the maximum size of `s`. Here, `[]` is the scanset character. `^\n` stands for taking input until a newline isn't
encountered. Then, with this `%*c`, it reads the newline character and here, the used * indicates that this newline character is discarded.

Note: The statement: `scanf("%[^\n]%*c", s);` will not work because the last statement will read a newline character, `\n`, from the previous line.
This can be handled in a variety of ways. One way is to use `scanf("\n");` before the last statement.

### Task

You have to print the character, `ch`, in the first line. Then print `s` in next line. In the last line print the sentence, `sen`.

### Input Format

First, take a character, `ch` as input.
Then take the string, `s` as input.
Lastly, take the sentence `sen` as input.

### Constraints

Strings for `s` and `sen` will have fewer than 100 characters, including the newline.

### Output Format

Print three lines of output. The first line prints the character, `ch`.
The second line prints the string, `s`.
The third line prints the sentence, `sen`.

#### [Solution](./Introduction/playing_with_characters.c)

# Structs and Enums

## Boxes through a Tunnel: Easy

You are transporting some boxes through a tunnel, where each box is a parallelepiped, and is characterized by its length, width and 
height. The height of the tunnel `41` feet and the width can be assumed to be infinite. A box can be carried through the tunnel only 
if its height is strictly less than the tunnel's height. Find the volume of each box that can be successfully transported to the other 
end of the tunnel. Note: Boxes cannot be rotated.

### Input Format

The first line contains a single integer `n`, denoting the number of boxes.
`n` lines follow with three integers on each separated by single spaces — ${length_i}$, ${width_i}$, and ${height_i}$ 
which are length, width and height in feet of the *i*-th box.

### Constraints

* $1 \leq n \leq 100$
* $1 \leq length_i, width_i, height_i \leq 100$

### Output Format

For every box from the input which has a height lesser than `41` feet, print its volume in a separate line.

#### [Solution](./Structs%20and%20Enums/boxes_through_a_tunnel.c)

## Small Triangles, Large Triangles: Medium

You are given `n` triangles, specifically, their sides $a_i$, $b_i$, and $c_i$.
Print them in the same style but sorted by their areas from the smallest one to the largest one. 
It is guaranteed that all the areas are different.

The best way to calculate a area of a triangle with sides `a`, `b`, and `c` is Heron's formula:

$S = \sqrt{p \times (p - a) \times (p - b) \times (p - c)}$ where $p = \frac{(a+b+c)}{2}$.

### Input Format

The first line of each test file contains a single integer `n`. lines follow with three space-separated integers, $a_i$, $b_i$, and $c_i$.

### Constraints

* $1 \leq n \leq 100$
* $1 \leq a_i, b_i, c_i \leq 70$
* $a_i + b+i \gt c_i,a_i + c_i \gt b_i$ and $b_i + c_i \gt a_i$

#### [Solution](./Structs%20and%20Enums/small_triangles_large_triangles.c)
