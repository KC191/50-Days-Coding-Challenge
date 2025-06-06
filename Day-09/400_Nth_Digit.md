<!-- problem:start -->

# [400. Nth Digit](https://leetcode.com/problems/nth-digit)

[KC191](400_Nth_Digit.md)

## Description

<!-- description:start -->

<p>Given an integer <code>n</code>, return the <code>n<sup>th</sup></code> digit of the infinite integer sequence <code>[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 11
<strong>Output:</strong> 0
<strong>Explanation:</strong> The 11<sup>th</sup> digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Mathematics

The smallest and largest integers with $k$ digits are $10^{k-1}$ and $10^k-1$ respectively, so the total number of digits for $k$-digit numbers is $k \times 9 \times 10^{k-1}$.

We use $k$ to represent the number of digits of the current number, and $cnt$ to represent the total number of numbers with the current number of digits. Initially, $k=1$, $cnt=9$.

Each time we subtract $cnt \times k$ from $n$, when $n$ is less than or equal to $cnt \times k$, it means that the number corresponding to $n$ is within the range of numbers with the current number of digits. At this time, we can calculate the corresponding number.

The specific method is to first calculate which number of the current number of digits corresponds to $n$, and then calculate which digit of this number it is, so as to get the number on this digit.

The time complexity is $O(\log_{10} n)$.

<!-- tabs:start -->

#### C++

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        int k = 1, cnt = 9;
        while (1ll * k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }
        int num = pow(10, k - 1) + (n - 1) / k;
        int idx = (n - 1) % k;
        return to_string(num)[idx] - '0';
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
