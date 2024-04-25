# Find B

## 题面翻译

定义一个长为 $m$ 的正整数序列 $a$ 是好的，当且仅当存在长为 $m$ 的正整数序列 $b$ 满足以下条件：

- $\displaystyle\sum_{i=1}^m a_i=\sum_{i=1}^m b_i;$
- $\forall i\in[1,m],a_i\ne b_i.$

给定一个长为 $n$ 的正整数序列 $c$ 和 $q$ 个询问，每次询问给出 $l_i,r_i$，要求判断 $c_{l_i},c_{l_i+1},\dots,c_{r_i-1},c_{r_i}$ 是否是好的序列。每个测试点 $t$ 组测试用例。

Translated by [Luzhuoyuan](https://www.luogu.com.cn/user/388940).

## 题目描述

An array $ a $ of length $ m $ is considered good if there exists an integer array $ b $ of length $ m $ such that the following conditions hold:

1. $ \sum\limits_{i=1}^{m} a_i = \sum\limits_{i=1}^{m} b_i $ ;
2. $ a_i \neq b_i $ for every index $ i $ from $ 1 $ to $ m $ ;
3. $ b_i > 0 $ for every index $ i $ from $ 1 $ to $ m $ .

You are given an array $ c $ of length $ n $ . Each element of this array is greater than $ 0 $ .

You have to answer $ q $ queries. During the $ i $ -th query, you have to determine whether the subarray $ c_{l_{i}}, c_{l_{i}+1}, \dots, c_{r_{i}} $ is good.

## 输入格式

The first line contains one integer $ t $ ( $ 1 \le t \le 10^4 $ ) — the number of test cases.

The first line of each test case contains two integers $ n $ and $ q $ ( $ 1 \le n, q \le 3 \cdot 10^5 $ ) — the length of the array $ c $ and the number of queries.

The second line of each test case contains $ n $ integers $ c_1, c_2, \dots, c_n $ ( $ 1 \le c_i \le 10^9 $ ).

Then $ q $ lines follow. The $ i $ -th of them contains two integers $ l_i $ and $ r_i $ ( $ 1 \le l_i \le r_i \le n $ ) — the borders of the $ i $ -th subarray.

Additional constraints on the input: the sum of $ n $ over all test cases does not exceed $ 3 \cdot 10^5 $ ; the sum of $ q $ over all test cases does not exceed $ 3 \cdot 10^5 $ .

## 输出格式

For each query, print YES if the subarray is good. Otherwise, print NO.

You can output each letter of the answer in any case (upper or lower). For example, the strings yEs, yes, Yes, and YES will all be recognized as positive responses.

## 样例 #1

### 样例输入 #1

```
1
5 4
1 2 1 4 5
1 5
4 4
3 4
1 3
```

### 样例输出 #1

```
YES
NO
YES
NO
```

-- --
# 找出序列 B

## 题目翻译

定义一个长度为 $m$ 的正整数序列 $a$ 为“好的序列”，当且仅当存在一个同样长度为 $m$ 的正整数序列 $b$ 满足以下条件：

- 序列 $a$ 与序列 $b$ 的元素之和相等，即 $\displaystyle\sum_{i=1}^m a_i=\sum_{i=1}^m b_i$；
- 对于所有 $i \in [1, m]$，有 $a_i \ne b_i$；
- 对于所有 $i \in [1, m]$，有 $b_i > 0$。

给定一个长度为 $n$ 的正整数序列 $c$ 和 $q$ 个查询，每个查询给出两个整数 $l_i, r_i$，要求判断子序列 $c_{l_i}, c_{l_i+1}, \dots, c_{r_i-1}, c_{r_i}$ 是否为“好的序列”。每个测试点包含 $t$ 组测试用例。

## 题目描述

一个长度为 $m$ 的数组 $a$ 被认为是好的，如果存在一个同样长度为 $m$ 的整数数组 $b$，使得以下条件成立：

1. 数组 $a$ 与数组 $b$ 的元素之和相等，即 $\sum\limits_{i=1}^{m} a_i = \sum\limits_{i=1}^{m} b_i$；
2. 对于每个索引 $i$（从 $1$ 到 $m$），有 $a_i \neq b_i$；
3. 对于每个索引 $i$（从 $1$ 到 $m$），有 $b_i > 0$。

给定一个长度为 $n$ 的数组 $c$，数组中的每个元素都大于 $0$。

你需要回答 $q$ 个查询。在第 $i$ 个查询中，你需要确定子数组 $c_{l_{i}}, c_{l_{i}+1}, \dots, c_{r_{i}}$ 是否是好的。

## 输入格式

第一行包含一个整数 $t$（$1 \le t \le 10^4$）——测试用例的数量。

每个测试用例的第一行包含两个整数 $n$ 和 $q$（$1 \le n, q \le 3 \cdot 10^5$）——数组 $c$ 的长度和查询的数量。

每个测试用例的第二行包含 $n$ 个整数 $c_1, c_2, \dots, c_n$（$1 \le c_i \le 10^9$）。

接下来是 $q$ 行。其中第 $i$ 行包含两个整数 $l_i$ 和 $r_i$（$1 \le l_i \le r_i \le n$）——第 $i$ 个子数组的边界。

对输入的额外约束：所有测试用例中 $n$ 的总和不超过 $3 \cdot 10^5$；所有测试用例中 $q$ 的总和不超过 $3 \cdot 10^5$。

## 输出格式

对于每个查询，如果子数组是好的，则打印 YES。否则，打印 NO。

你可以以任何大小写输出答案中的每个字母（大写或小写）。例如，字符串 yEs, yes, Yes 和 YES 都将被识别为肯定的回答。

## 样例 #1

### 样例输入 #1

```
1
5 4
1 2 1 4 5
1 5
4 4
3 4
1 3
```

### 样例输出 #1

```
YES
NO
YES
NO
```