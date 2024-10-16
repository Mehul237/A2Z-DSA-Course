
## Note to remember:

[Quick recap - heap](https://www.scaler.com/topics/data-structures/heap-data-structure/)

<hr>

### <i> (1) Min heap property </i>
- The root of a min-heap is the smallest element in the heap
- In a min-heap, each node is smaller than its child nodes

![min-heap property](https://www.scaler.com/topics/media/Min-heap-in-data-structure-841x1024.webp)

<hr>

### <i> (2) Max heap property </i>
- The root of a max-heap is the largest element in the heap
- In a max-heap, each node is greater than its child nodes

![max-heap property](https://www.scaler.com/topics/media/Max-heap-in-data-structure-842x1024.webp)

<hr>

<img width="749" alt="image" src="https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/123a60ea-81a2-4f50-a229-da6f946f90ee">

<hr>

| No | Problem Name      | Observation       |
|----|-------------------|-------------------|
| 1  | [Basic stuff to remember](https://github.com/Mehul237/A2Z-DSA-Course/blob/main/STEP-11/L1.md) | Intro, Insertion and deletion, Heapify, Heap Sort, Priority Queue |
| 2 | [Kth largest and smallest element](https://github.com/Mehul237/A2Z-DSA-Course/blob/main/STEP-11/01_Kth%20Smallest_Largest.md) | Min-heap, Max-heap (Implementation, STL) |
| Most Important (Think: sorted, k -- min heap) | [Merge k sorted arrays](https://github.com/Mehul237/A2Z-DSA-Course/blob/main/STEP-11/Merge_K_Sorted_Arrays.md) | Sorted (1, 2, 3) -- Triggerred into mind that use min heap |
| --- | [MinCost of N ropes](https://github.com/Mehul237/A2Z-DSA-Course/blob/main/STEP-11/MinCost_of_N_Ropes.md) | Take 2 element consecutive which having the first min value, Take sum and push into pq and add up to ropesCost which give the ans for that Problem -- Logic: Min-heap |
| How to think about the problem? Optimized the problem related to time and space. Here, Space ^+ | [Kth Largest sum subarray](https://github.com/Mehul237/A2Z-DSA-Course/blob/main/STEP-11/Kth_LargetSum_Subarray.md) | Generate the subarray sum for all the elements, Check if mini.size() < k then insert into mini and also check for if sum > mini.top() then pop the element and insert the sum into mini -- (Kth, Largest -- min heap) |
| 3  | [Merge 2 binary heaps](https://github.com/Mehul237/A2Z-DSA-Course/blob/main/STEP-11/Merge_2_BinaryMax_HEAP.md) | Heapify algo (0 or 1 based indexing), Merge logic (Two different thing push into one) |
| --- |                          | ...   |
| --- |                          | ...   |

<hr>
