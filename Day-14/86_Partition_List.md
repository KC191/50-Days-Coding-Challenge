<!-- problem:start -->

# [86. Partition List](https://leetcode.com/problems/partition-list)

[KC191](86_Partition_List.md)

## Description

<!-- description:start -->

<p>Given the <code>head</code> of a linked list and a value <code>x</code>, partition it such that all nodes <strong>less than</strong> <code>x</code> come before nodes <strong>greater than or equal</strong> to <code>x</code>.</p>

<p>You should <strong>preserve</strong> the original relative order of the nodes in each of the two partitions.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/partition.jpg" style="width: 662px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,4,3,2,5,2], x = 3
<strong>Output:</strong> [1,2,2,4,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [2,1], x = 2
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 200]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>-200 &lt;= x &lt;= 200</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Simulation

We create two linked lists $l$ and $r$, one to store nodes less than $x$ and the other to store nodes greater than or equal to $x$. Then we concatenate them.

The time complexity is $O(n)$, where $n$ is the length of the original linked list. The space complexity is $O(1)$.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l = new ListNode();
        ListNode* r = new ListNode();
        ListNode* tl = l;
        ListNode* tr = r;
        for (; head; head = head->next) {
            if (head->val < x) {
                tl->next = head;
                tl = tl->next;
            } else {
                tr->next = head;
                tr = tr->next;
            }
        }
        tr->next = nullptr;
        tl->next = r->next;
        return l->next;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
