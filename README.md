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
  - [Post Transition](#post-transition-hard)

# Introduction

## "Hello World!" in C: Easy

### Objective

In this challenge, we will learn some basic concepts of C that will get you started with the language. You will need to use the same syntax to read input and write output in many C challenges. As you work through these problems, review the code stubs to learn about reading from stdin and writing to stdout.

### Task

This challenge requires you to print `Hello, World!` on a single line, and then print the already provided input string to [stdout](https://en.wikipedia.org/wiki/Standard_streams#Standard_output_.28stdout.29). If you are not familiar with C, you may want to read about the printf() command.

#### [Solution](./Introduction/Easy/hello_world_in_c.c)

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

#### [Solution](./Introduction/Easy/playing_with_characters.c)

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

#### [Solution](./Structs%20and%20Enums/Easy/boxes_through_a_tunnel.c)

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

#### [Solution](./Structs%20and%20Enums/Medium/small_triangles_large_triangles.c)

## Post Transition: Hard

We live in a big country. This country has towns `towns_count` in it. 
Each town has some post offices in which packages are stored and transferred.

Post offices have different inner structure. Specifically, each of them has some limitations on the packages it can store - their weight should be between
`min_weight` and `max_weight` inclusively, where `min_weight` and `max_weight` are fixed for each office.

Packages are stored in some order in the office queue. That means, that they are processed using this order when sending and receiving.

Sometimes two post offices, even in different towns, may organize the following transaction: the first one sends all 
its packages to the second one. The second one accepts the packages that satisfy the weight condition for the second 
office and rejects all other ones. These rejected packages return to the first office back and are stored in the same 
order they were stored before they were sent. The accepted packages move to the tail of the second office's queue in the 
same order they were stored in the first office.

You should process several queries in your program. You'll be provided with structures `package`,
`post_office` and `town`. In order to complete this task, you should fill the following functions:

`print_all_packages` given the town `t`, print all packages in this town. They should be printed as follows:

```
Town_name:
	0:
		id_0
		id_1
		...
	1:
		id_2
		id_3
		...
	...
```

where `0`, `1` etc. are the numbers of post offices and $id_0$, $id_1$ ... are the
ids of packages from the `0th` post office in the order of its queue, $id_2$, $id_3$ are
from the `1st` one etc. There should be one '\t' symbol before post office numbers and two '\t'
symbols before the ids.

`send_all_acceptable_packages` - given the towns `source` and `target` and post office indices
`source_office_index` and `target_office_index`, manage the transaction described above between the
post office #`source_office_index` in town `source` and the post office #`target_office_index` in 
town `target`.

`town_with_most_packages` -  given all towns, find the one with the most number of packages in all 
post offices altogether. If there are several of them, find the first one from the collection `towns`.

`find_towns` - given all towns and a string `name`, find the town with the name `name`. 
It's guaranteed that the town exists.

### Input Format

First line of the input contains a single integer `towns_count`. `towns_count` blocks follow, each describing a town.

Every town block contains several lines. On the first line there is a string `town_name` - the name of the town. 
On the second line there is an integer `offices_count` - the number of the offices in the town. 
`offices_count` blocks follow then, each describing an office.

Every office block also contains several lines. On the first line there are three integers separated by single spaces: 
`packages_count` (the number of packages in the office), `min_weight` and `max_weight` (described above). 
`packages_count` blocks follow, each describing a package.

Every package block contains exactly two lines. On the first line there is a string `id` which is an id of the package. 
On the second line there is an integer `weight` which is the weight of the package.

Then, there is a single integer `queries` on the line which is the number of queries. 
`queries` blocks follow, each describing a query.

Every query block contains several lines. On the first line there is an integer `1`, `2`, or `3`. 
If this integer is `1`, on the second line there is a string `town_name` - the name of town for which all packages should be 
printed. If this integer is `2`, on the second line there are string `source_name`, integer `source_office_index`, string 
`target_name` and integer `target_office_index` separated by single spaces. That means transactions between post 
office #`source_office_index` in the town `source_name` and post office #`target_office_index` in the town `target_name 
should be processed.

If the integer is `3`, no lines follow and the town with the most number of packages should be found.

### Constraints

* All integer are between `0` and `10`.
* 'towns_count' $\gt 0$, `offices_count` $\gt 0$.
* All strings have length $\leq 5$
* All towns' names have only uppercase english letters and are unique.
* All packages' ids have only lowercase english letters and are unique.
* For each post office, `min_weight` $\leq$ `max_weight`.
* All queries are valid, that means, towns with the given names always exist, post offices with the given indices always exist.

### Output Format

For queries of type `1`, print all packages in the format provided in the problem statement. 
For queries of type `3`, print "Town with the most number of packages is `town_name`" on a separate line.

#### [Solution](./Structs%20and%20Enums/Hard/post_transition.c)





