<!-- problem:start -->

# [367. Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square)

[KC191](367_Valid_Perfect_Square.md)

## Description

<!-- description:start -->

<p>Given a positive integer num, return <code>true</code> <em>if</em> <code>num</code> <em>is a perfect square or</em> <code>false</code> <em>otherwise</em>.</p>

<p>A <strong>perfect square</strong> is an integer that is the square of an integer. In other words, it is the product of some integer with itself.</p>

<p>You must not use any built-in library function, such as <code>sqrt</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 16
<strong>Output:</strong> true
<strong>Explanation:</strong> We return true because 4 * 4 = 16 and 4 is an integer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 14
<strong>Output:</strong> false
<strong>Explanation:</strong> We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Binary Search

We can use binary search to solve this problem. Define the left boundary $l = 1$ and the right boundary $r = num$ of the binary search, then find the smallest integer $x$ that satisfies $x^2 \geq num$ in the range $[l, r]$. Finally, if $x^2 = num$, then $num$ is a perfect square.

The time complexity is $O(\log n)$, where $n$ is the given number. The space complexity is $O(1)$.

<!-- tabs:start -->

#### C++

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (1LL * mid * mid >= num) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return 1LL * l * l == num;
    }
};
```
<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Mathematics

Since $1 + 3 + 5 + \cdots + (2n - 1) = n^2$, we can gradually subtract $1, 3, 5, \cdots$ from $num$. If $num$ finally equals $0$, then $num$ is a perfect square.

The time complexity is $O(\sqrt n)$, and the space complexity is $O(1)$.

<!-- tabs:start -->

#### C++

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; num > 0; i += 2) {
            num -= i;
        }
        return num == 0;
    }
};
```
<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
