<!-- problem:start -->

# [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii)

[KC191](82_Remove_Duplicates_from_Sorted_List_II.md)

## Description

<!-- description:start -->

<p>Given the <code>head</code> of a sorted linked list, <em>delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list</em>. Return <em>the linked list <strong>sorted</strong> as well</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg" style="width: 500px; height: 142px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,3,4,4,5]
<strong>Output:</strong> [1,2,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg" style="width: 500px; height: 205px;" />
<pre>
<strong>Input:</strong> head = [1,1,1,2,3]
<strong>Output:</strong> [2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 300]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>The list is guaranteed to be <strong>sorted</strong> in ascending order.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Single Pass

First, we create a dummy head node $dummy$, and set $dummy.next = head$. Then we create a pointer $pre$ pointing to $dummy$, and a pointer $cur$ pointing to $head$, and start traversing the linked list.

When the node value pointed by $cur$ is the same as the node value pointed by $cur.next$, we let $cur$ keep moving forward until the node value pointed by $cur$ is different from the node value pointed by $cur.next$. At this point, we check whether $pre.next$ is equal to $cur$. If they are equal, it means there are no duplicate nodes between $pre$ and $cur$, so we move $pre$ to the position of $cur$; otherwise, it means there are duplicate nodes between $pre$ and $cur$, so we set $pre.next$ to $cur.next$. Then we continue to move $cur$ forward. Continue the above operation until $cur$ is null, and the traversal ends.

Finally, return $dummy.next$.

The time complexity is $O(n)$, and the space complexity is $O(1)$. Here, $n$ is the length of the linked list.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            if (pre->next == cur) {
                pre = cur;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
