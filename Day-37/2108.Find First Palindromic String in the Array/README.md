<!-- problem:start -->

# [2108. Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array)

[KC191](/2108.Find%20First%20Palindromic%20String%20in%20the%20Array/README.md)

## Description

<!-- description:start -->

<p>Given an array of strings <code>words</code>, return <em>the first <strong>palindromic</strong> string in the array</em>. If there is no such string, return <em>an <strong>empty string</strong> </em><code>&quot;&quot;</code>.</p>

<p>A string is <strong>palindromic</strong> if it reads the same forward and backward.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;car&quot;,&quot;ada&quot;,&quot;racecar&quot;,&quot;cool&quot;]
<strong>Output:</strong> &quot;ada&quot;
<strong>Explanation:</strong> The first string that is palindromic is &quot;ada&quot;.
Note that &quot;racecar&quot; is also palindromic, but it is not the first.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;notapalindrome&quot;,&quot;racecar&quot;]
<strong>Output:</strong> &quot;racecar&quot;
<strong>Explanation:</strong> The first and only string that is palindromic is &quot;racecar&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;def&quot;,&quot;ghi&quot;]
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> There are no palindromic strings, so the empty string is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Simulation

We iterate through the array `words`, for each string `w`, we determine if it is a palindrome. If it is, then we return `w`; otherwise, we continue to iterate.

To determine if a string is a palindrome, we can use two pointers, one pointing to the start and the other to the end of the string, moving towards the center, and checking if the corresponding characters are equal. If, after traversing the entire string, no unequal characters are found, then the string is a palindrome.

The time complexity is $O(L)$, where $L$ is the sum of the lengths of all strings in the array `words`. The space complexity is $O(1)$.

<!-- tabs:start -->

#### C++

```cpp
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& w : words) {
            bool ok = true;
            for (int i = 0, j = w.size() - 1; i < j; ++i, --j) {
                if (w[i] != w[j]) {
                    ok = false;
                }
            }
            if (ok) {
                return w;
            }
        }
        return "";
    }
};
```

#### Python3

```python
class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        return next((w for w in words if w == w[::-1]), "")
```

#### Java

```java
class Solution {
    public String firstPalindrome(String[] words) {
        for (var w : words) {
            boolean ok = true;
            for (int i = 0, j = w.length() - 1; i < j && ok; ++i, --j) {
                if (w.charAt(i) != w.charAt(j)) {
                    ok = false;
                }
            }
            if (ok) {
                return w;
            }
        }
        return "";
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
