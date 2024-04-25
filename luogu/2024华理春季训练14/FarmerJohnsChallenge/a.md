# Farmer John's Challenge

## 题目描述

[Trade Winds - Patrick Deng](https://soundcloud.com/patrick-deng-392681004/trade-winds-ft-alex-zhu)

⠀



Let's call an array $ a $ sorted if $ a_1 \leq a_2 \leq \ldots \leq a_{n - 1} \leq a_{n} $ .

You are given two of Farmer John's favorite integers, $ n $ and $ k $ . He challenges you to find any array $ a_1, a_2, \ldots, a_{n} $ satisfying the following requirements:

- $ 1 \leq a_i \leq 10^9 $ for each $ 1 \leq i \leq n $ ;
- Out of the $ n $ total cyclic shifts of $ a $ , exactly $ k $ of them are sorted. $ ^\dagger $

If there is no such array $ a $ , output $ -1 $ .

 $ ^\dagger $ The $ x $ -th ( $ 1 \leq x \leq n $ ) cyclic shift of the array $ a $ is $ a_x, a_{x+1} \ldots a_n, a_1, a_2 \ldots a_{x - 1} $ . If $ c_{x, i} $ denotes the $ i $ 'th element of the $ x $ 'th cyclic shift of $ a $ , exactly $ k $ such $ x $ should satisfy $ c_{x,1} \leq c_{x,2} \leq \ldots \leq c_{x, n - 1} \leq c_{x, n} $ .

For example, the cyclic shifts for $ a = [1, 2, 3, 3] $ are the following:

- $ x = 1 $ : $ [1, 2, 3, 3] $ (sorted);
- $ x = 2 $ : $ [2, 3, 3, 1] $ (not sorted);
- $ x = 3 $ : $ [3, 3, 1, 2] $ (not sorted);
- $ x = 4 $ : $ [3, 1, 2, 3] $ (not sorted).

## 输入格式

The first line contains $ t $ ( $ 1 \leq t \leq 10^3 $ ) — the number of test cases.

Each test case contains two integers $ n $ and $ k $ ( $ 1 \leq k \leq n \leq 10^3 $ ) — the length of $ a $ and the number of sorted cyclic shifts $ a $ must have.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 10^3 $ .

## 输出格式

For each test case, print a single line:

- if there is a valid array $ a $ , output $ n $ integers, representing $ a_1, a_2, \ldots, a_{n} $ ;
- otherwise, output $ -1 $ .

If there are multiple solutions, print any of them.

## 样例 #1

### 样例输入 #1

```
3
2 2
3 1
3 2
```

### 样例输出 #1

```
1 1
69420 69 420
-1
```

## 提示

In the first testcase, $ a = [1, 1] $ satisfies $ n = 2, k = 2 $ :

The two cyclic shifts of $ a $ are $ [a_1, a_2] $ and $ [a_2, a_1] $ , which are both $ [1, 1] $ and are sorted.

In the second testcase, $ a = [69\,420, 69, 420] $ satisfies $ n = 3, k = 1 $ :

The three cyclic shifts of $ a $ are $ [a_1, a_2, a_3] $ , $ [a_2, a_3, a_1] $ , $ [a_3, a_1, a_2] $ , which are $ [69\,420, 69, 420] $ , $ [69, 420, 69\,420] $ , and $ [420, 69\,420, 69] $ , respectively.

Only $ [69, 420, 69\,420] $ is sorted.


# 农夫约翰的挑战
## 题目描述
Trade Winds - Patrick Deng

让我们称一个数组 $a$ 为有序的，如果 $a_1 \leq a_2 \leq \ldots \leq a_{n-1} \leq a_n$。

你将得到农夫约翰最喜欢的两个整数，$n$ 和 $k$。他挑战你找到任意一个数组 $a_1, a_2, \ldots, a_n$，满足以下要求：

- 对于每个 $1 \leq i \leq n$，有 $1 \leq a_i \leq 10^9$；
- 在数组 $a$ 的 $n$ 个总循环位移中，恰好有 $k$ 个是有序的。

如果不存在这样的数组 $a$，输出 $-1$。

循环位移的定义是，数组 $a$ 的第 $x$ 次（$1 \leq x \leq n$）循环位移是 $a_x, a_{x+1}, \ldots a_n, a_1, a_2, \ldots a_{x-1}$。如果用 $c_{x,i}$ 表示数组 $a$ 的第 $x$ 次循环位移的第 $i$ 个元素，恰好有 $k$ 个这样的 $x$ 应该满足 $c_{x,1} \leq c_{x,2} \leq \ldots \leq c_{x,n-1} \leq c_{x,n}$。

例如，数组 $a = [1, 2, 3, 3]$ 的循环位移如下：

- $x=1$：$[1, 2, 3, 3]$（有序）；
- $x=2$：$[2, 3, 3, 1]$（无序）；
- $x=3$：$[3, 3, 1, 2]$（无序）；
- $x=4$：$[3, 1, 2, 3]$（无序）。

## 输入格式
第一行包含 $t$（$1 \leq t \leq 10^3$）—— 测试用例的数量。

每个测试用例包含两个整数 $n$ 和 $k$（$1 \leq k \leq n \leq 10^3$）—— 数组 $a$ 的长度和数组 $a$ 必须有的有序循环位移的数量。

保证所有测试用例中 $n$ 的总和不超过 $10^3$。

## 输出格式
对于每个测试用例，打印单独的一行：

- 如果存在有效的数组 $a$，输出 $n$ 个整数，代表 $a_1, a_2, \ldots, a_n$；
- 否则，输出 $-1$。

如果有多个解决方案，打印其中任何一个。

## 样例 #1
样例输入 #1
```
3
2 2
3 1
3 2
```
样例输出 #1
```
1 1
69420 69 420
-1
```
##  提示
在第一个测试用例中，$a = [1, 1]$ 满足 $n=2, k=2$：

数组 $a$ 的两个循环位移是 $[a_1, a_2]$ 和 $[a_2, a_1]$，它们都是 $[1, 1]$ 并且都是有序的。

在第二个测试用例中，$a = [69420, 69, 420]$ 满足 $n=3, k=1$：

数组 $a$ 的三个循环位移是 $[a_1, a_2, a_3]$，$[a_2, a_3, a_1]$，$[a_3, a_1, a_2]$，分别是 $[69420, 69, 420]$，$[69, 420, 69420]$ 和 $[420, 69420, 69]$。

只有 $[69, 420, 69420]$ 是有序的。