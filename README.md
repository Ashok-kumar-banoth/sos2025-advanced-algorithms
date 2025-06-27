# SOC_2025-Advanced-Algorithms(Competitive Programming)
List of topics covered
->Prefix Sums, Binary Search
->Dynamic Programming (0/1 Knapsack)
->Graph Algorithms: BFS, DFS, Dijkstra, Kruskal + DSU, SCC (Kosaraju)
->String Matching: KMP Algorithm
->Range Query Processing: Mo’s Algorithm

Links 
1) https://cses.fi/problemset/task/1646
3) https://cses.fi/problemset/task/1158
5) https://cses.fi/problemset/task/1671
6) https://codeforces.com/problemset/problem/609/E
7) https://cses.fi/problemset/task/1682
8) https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
9) https://codeforces.com/problemset/problem/86/D


Explanation of Algorithms

Kruskal’s Algorithm + DSU (Disjoint Set Union)
What it does:
it finds a Minimum Spanning Tree (MST) — a way to connect all nodes with minimum total edge cost without forming cycles.

How it works:
->Sort all edges by weight.
->Start picking edges from the smallest weight.
->Use DSU to check if adding an edge creates a cycle.
->If not, include the edge and merge the two sets.
Example:
For nodes 1-2-3 with edges:
1-2 (weight 1)
2-3 (weight 2)
1-3 (weight 10)
The MST includes edges 1-2 and 2-3 → total cost = 3


KMP (Knuth–Morris–Pratt) String Matching
What it does:
Searches for all occurrences of a pattern in a text in linear time, avoiding redundant comparisons.
How it works:
->Preprocess the pattern to build the LPS array (Longest Prefix Suffix).
->While matching, if a mismatch occurs, use LPS to jump forward instead of restarting from scratch.
Example:
Text: "ababcabcabababd"
Pattern: "ababd"
→ KMP finds the pattern at index 10.


Mo’s Algorithm (√ Decomposition for Offline Queries)
What it does:
Efficiently answers multiple range queries like “count of distinct elements from l to r”.
How it works:
->Sort the queries cleverly by blocks of size √n.
->Move two pointers (left and right) and keep updating the answer.
->Avoids recomputation by only adjusting a few elements at a time.
Example:
Array: [1, 1, 2, 1, 3]
Query: [0,4] → Answer: 3 distinct (1,2,3)
