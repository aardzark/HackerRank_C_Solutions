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
- [Structs and Enums]
  - [Boxes through a Tunnel](#boxes-through-a-Tunnel-easy)

# Introduction
## "Hello World!" in C: Easy
### Objective

In this challenge, we will learn some basic concepts of C that will get you started with the language. You will need to use the same syntax to read input and write output in many C challenges. As you work through these problems, review the code stubs to learn about reading from stdin and writing to stdout.

### Task

This challenge requires you to print `Hello, World!` on a single line, and then print the already provided input string to [stdout](https://en.wikipedia.org/wiki/Standard_streams#Standard_output_.28stdout.29). If you are not familiar with C, you may want to read about the printf() command.

#### [Solution](./Introduction/hello_world_in_c.c)

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

* $(1 \leq n \leq 100)$
* $(1 \leq length_i, width_i, height_i, \leq 100)$

### Output Format

For every box from the input which has a height lesser than `41` feet, print its volume in a separate line.

#### [Solution](./Structs and Enums/boxes_through_a_tunnel.c)