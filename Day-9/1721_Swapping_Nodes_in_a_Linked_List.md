<!-- problem:start -->

# [1721. Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list)

[KC191](1721_Swapping_Nodes_in_a_Linked_List.md)

## Description

<!-- description:start -->

<p>You are given the <code>head</code> of a linked list, and an integer <code>k</code>.</p>

<p>Return <em>the head of the linked list after <strong>swapping</strong> the values of the </em><code>k<sup>th</sup></code> <em>node from the beginning and the </em><code>k<sup>th</sup></code> <em>node from the end (the list is <strong>1-indexed</strong>).</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg" style="width: 400px; height: 112px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [1,4,3,2,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [7,9,6,6,7,8,3,0,9,5], k = 5
<strong>Output:</strong> [7,9,6,6,8,7,3,0,9,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Two Pointers

We can first use a fast pointer `fast` to find the $k$th node of the linked list, and use a pointer `p` to point to it. Then, we use a slow pointer `slow` to start from the head node of the linked list, and move both pointers forward at the same time. When the fast pointer reaches the last node of the linked list, the slow pointer `slow` points to the $k$th node from the end of the linked list, and we use a pointer `q` to point to it. At this point, we only need to swap the values of `p` and `q`.

The time complexity is $O(n)$, where $n$ is the length of the linked list. The space complexity is $O(1)$.

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        while (--k) {
            fast = fast->next;
        }
        ListNode* slow = head;
        ListNode* p = fast;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* q = slow;
        swap(p->val, q->val);
        return head;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
