<!-- problem:start -->

# [109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree)

[KC191](/109.Convert%20Sorted%20List%20to%20Binary%20Search%20Tree/README.md)

## Description

<!-- description:start -->

<p>Given the <code>head</code> of a singly linked list where elements are sorted in <strong>ascending order</strong>, convert <em>it to a </em><span data-keyword="height-balanced"><strong><em>height-balanced</em></strong></span> <em>binary search tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/KC191/50-Days-Coding-Challenge@main/Day-44/109.Convert%20Sorted%20List%20to%20Binary%20Search%20Tree/images/linked.jpg" style="width: 500px; height: 388px;" />
<pre>
<strong>Input:</strong> head = [-10,-3,0,5,9]
<strong>Output:</strong> [0,-3,9,-10,null,5]
<strong>Explanation:</strong> One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in <code>head</code> is in the range <code>[0, 2 * 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: DFS

We first convert the linked list to an array $\textit{nums}$, and then use depth-first search to construct the binary search tree.

We define a function $\textit{dfs}(i, j)$, where $i$ and $j$ represent the current interval $[i, j]$. Each time, we choose the number at the middle position $\textit{mid}$ of the interval as the root node, recursively construct the left subtree for the interval $[i, \textit{mid} - 1]$, and the right subtree for the interval $[\textit{mid} + 1, j]$. Finally, we return the node corresponding to $\textit{mid}$ as the root node of the current subtree.

In the main function, we just need to call $\textit{dfs}(0, n - 1)$ and return the result.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Here, $n$ is the length of the linked list.

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def dfs(i: int, j: int) -> Optional[TreeNode]:
            if i > j:
                return None
            mid = (i + j) >> 1
            l, r = dfs(i, mid - 1), dfs(mid + 1, j)
            return TreeNode(nums[mid], l, r)

        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        return dfs(0, len(nums) - 1)
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private List<Integer> nums = new ArrayList<>();

    public TreeNode sortedListToBST(ListNode head) {
        for (; head != null; head = head.next) {
            nums.add(head.val);
        }
        return dfs(0, nums.size() - 1);
    }

    private TreeNode dfs(int i, int j) {
        if (i > j) {
            return null;
        }
        int mid = (i + j) >> 1;
        TreeNode left = dfs(i, mid - 1);
        TreeNode right = dfs(mid + 1, j);
        return new TreeNode(nums.get(mid), left, right);
    }
}
```

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for (; head; head = head->next) {
            nums.push_back(head->val);
        }
        auto dfs = [&](this auto&& dfs, int i, int j) -> TreeNode* {
            if (i > j) {
                return nullptr;
            }
            int mid = (i + j) >> 1;
            TreeNode* left = dfs(i, mid - 1);
            TreeNode* right = dfs(mid + 1, j);
            return new TreeNode(nums[mid], left, right);
        };
        return dfs(0, nums.size() - 1);
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
