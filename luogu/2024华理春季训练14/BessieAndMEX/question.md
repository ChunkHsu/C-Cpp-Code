# Bessie and MEX

## 题面翻译

约翰农夫有一个排列 p1,p2,…,pn
，其中从 0
 到 n-1
 的每个整数恰好出现一次。他给贝西一个长度为 n
 的数组 a
，并挑战她基于 a
 构建 p
。

数组 a
 被构建为 ai
 = MEX(p1,p2,…,pi)-pi
，其中数组的 MEX
 是不在该数组中出现的最小非负整数。例如，MEX(1,2,3)=0
 和 MEX(3,1,0)=2
。

帮助贝西构建满足 a
 的任何有效排列 p
。输入以这样的方式给出，至少存在一个有效的 p
。如果存在多个可能的 p
，只需打印其中一个即可。

## 题目描述

[MOOO! - Doja Cat](https://soundcloud.com/amalaofficial/mooo)

⠀



Farmer John has a permutation $ p_1, p_2, \ldots, p_n $ , where every integer from $ 0 $ to $ n-1 $ occurs exactly once. He gives Bessie an array $ a $ of length $ n $ and challenges her to construct $ p $ based on $ a $ .

The array $ a $ is constructed so that $ a_i $ = $ \texttt{MEX}(p_1, p_2, \ldots, p_i) - p_i $ , where the $ \texttt{MEX} $ of an array is the minimum non-negative integer that does not appear in that array. For example, $ \texttt{MEX}(1, 2, 3) = 0 $ and $ \texttt{MEX}(3, 1, 0) = 2 $ .

Help Bessie construct any valid permutation $ p $ that satisfies $ a $ . The input is given in such a way that at least one valid $ p $ exists. If there are multiple possible $ p $ , it is enough to print one of them.

## 输入格式

The first line contains $ t $ ( $ 1 \leq t \leq 10^4 $ ) — the number of test cases.

The first line of each test case contains an integer $ n $ ( $ 1 \leq n \leq 2 \cdot 10^5 $ ) — the lengths of $ p $ and $ a $ .

The second line of each test case contains $ n $ integers $ a_1, a_2, \ldots, a_n $ ( $ -n \leq a_i \leq n $ ) — the elements of array $ a $ .

It is guaranteed that there is at least one valid $ p $ for the given data.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, output $ n $ integers on a new line, the elements of $ p $ .

If there are multiple solutions, print any of them.

## 样例 #1

### 样例输入 #1

```
3
5
1 1 -2 1 2
5
1 1 1 1 1
3
-2 1 2
```

### 样例输出 #1

```
0 1 4 2 3 
0 1 2 3 4 
2 0 1
```

## 提示

In the first case, $ p = [0, 1, 4, 2, 3] $ is one possible output.

 $ a $ will then be calculated as $ a_1 = \texttt{MEX}(0) - 0 = 1 $ , $ a_2 = \texttt{MEX}(0, 1) - 1 = 1 $ , $ a_3 = \texttt{MEX}(0, 1, 4) - 4 = -2 $ , $ a_4 = \texttt{MEX}(0, 1, 4, 2) - 2 = 1 $ , $ a_5 = \texttt{MEX}(0, 1, 4, 2, 3) - 3 = 2 $ .

So, as required, $ a $ will be $ [1, 1, -2, 1, 2] $ .

-- --


# 贝西和MEX

## 题目翻译

农夫约翰有一个排列 $p_1, p_2, \ldots, p_n$，其中从 $0$ 到 $n-1$ 的每个整数恰好出现一次。他给贝西一个长度为 $n$ 的数组 $a$，并挑战她基于 $a$ 构建 $p$。

数组 $a$ 被构建为 $a_i = \texttt{MEX}(p_1, p_2, \ldots, p_i) - p_i$，其中数组的 $\texttt{MEX}$ 是不在该数组中出现的最小非负整数。例如，$\texttt{MEX}(1, 2, 3) = 0$ 和 $\texttt{MEX}(3, 1, 0) = 2$。

帮助贝西构建满足 $a$ 的任何有效排列 $p$。输入以这样的方式给出，至少存在一个有效的 $p$。如果存在多个可能的 $p$，只需打印其中一个即可。

## 输入格式

第一行包含 $t$（$1 \leq t \leq 10^4$）—— 测试用例的数量。

每个测试用例的第一行包含一个整数 $n$（$1 \leq n \leq 2 \cdot 10^5$）—— $p$ 和 $a$ 的长度。

每个测试用例的第二行包含 $n$ 个整数 $a_1, a_2, \ldots, a_n$（$-n \leq a_i \leq n$）—— 数组 $a$ 的元素。

保证至少存在一个对于给定数据的有效 $p$。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，在新的一行上输出 $n$ 个整数，$p$ 的元素。

如果有多个解决方案，打印其中任何一个。

## 样例 #1

### 样例输入 #1

```
3
5
1 1 -2 1 2
5
1 1 1 1 1
3
-2 1 2
```

### 样例输出 #1

```
0 1 4 2 3
0 1 2 3 4
2 0 1
```

## 提示

在第一个案例中，$p = [0, 1, 4, 2, 3]$ 是一个可能的输出。

然后 $a$ 将被计算为 $a_1 = \texttt{MEX}(0) - 0 = 1$，$a_2 = \texttt{MEX}(0, 1) - 1 = 1$，$a_3 = \texttt{MEX}(0, 1, 4) - 4 = -2$，$a_4 = \texttt{MEX}(0, 1, 4, 2) - 2 = 1$，$a_5 = \texttt{MEX}(0, 1, 4, 2, 3) - 3 = 2$。

因此，正如要求的，$a$ 将是 $[1, 1, -2, 1, 2]$。