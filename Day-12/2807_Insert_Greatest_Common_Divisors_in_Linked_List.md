<!-- problem:start -->

# [2807. Insert Greatest Common Divisors in Linked List](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list)

[KC191](2807_Insert_Greatest_Common_Divisors_in_Linked_List.md)

## Description

<!-- description:start -->

<p>Given the head of a linked list <code>head</code>, in which each node contains an integer value.</p>

<p>Between every pair of adjacent nodes, insert a new node with a value equal to the <strong>greatest common divisor</strong> of them.</p>

<p>Return <em>the linked list after insertion</em>.</p>

<p>The <strong>greatest common divisor</strong> of two numbers is the largest positive integer that evenly divides both numbers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/07/18/ex1_copy.png" style="width: 641px; height: 181px;" />
<pre>
<strong>Input:</strong> head = [18,6,10,3]
<strong>Output:</strong> [18,6,6,2,10,1,3]
<strong>Explanation:</strong> The 1<sup>st</sup> diagram denotes the initial linked list and the 2<sup>nd</sup> diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1<sup>st</sup> and the 2<sup>nd</sup> nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2<sup>nd</sup> and the 3<sup>rd</sup> nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3<sup>rd</sup> and the 4<sup>th</sup> nodes.
There are no more adjacent nodes, so we return the linked list.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/07/18/ex2_copy1.png" style="width: 51px; height: 191px;" />
<pre>
<strong>Input:</strong> head = [7]
<strong>Output:</strong> [7]
<strong>Explanation:</strong> The 1<sup>st</sup> diagram denotes the initial linked list and the 2<sup>nd</sup> diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 5000]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Simulation

We use two pointers $pre$ and $cur$ to point to the current node and the next node respectively. We only need to insert a new node between $pre$ and $cur$. Therefore, each time we calculate the greatest common divisor $x$ of $pre$ and $cur$, we insert a new node with value $x$ between $pre$ and $cur$. Then we update $pre = cur$ and $cur = cur.next$, and continue to traverse the linked list until $cur$ is null.

The time complexity is $O(n \times \log M)$, where $n$ is the length of the linked list, and $M$ is the maximum value of the nodes in the linked list. Ignoring the space consumption of the result linked list, the space complexity is $O(1)$.

<!-- tabs:start -->

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pre = head;
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            int x = gcd(pre->val, cur->val);
            pre->next = new ListNode(x, cur);
            pre = cur;
        }
        return head;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
