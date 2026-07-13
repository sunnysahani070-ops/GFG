<h2><a href="https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1">Page Faults in LRU</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a sequence of pages in an array <strong>pages[]</strong> of length <strong>n</strong> and memory capacity <strong>c</strong>, find the number of page faults using the <a href="https://www.geeksforgeeks.org/system-design/lru-cache-implementation/" target="_blank" rel="noopener">Least Recently Used (LRU)</a> page replacement algorithm.</span></p>
<p><span style="font-size: 18px;">A page fault occurs when a referenced page is not present in memory. When memory is full, the least recently used page is replaced by the new page.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> c = 4, pages[] = [5, 0, 1, 3, 2, 4, 1, 0, 5]
<strong>Output:</strong> 8
<strong>Explanation:</strong> </span><span style="font-size: 18px;">Page 5: not in memory, fault, memory = [5], faults = 1
Page 0: fault, memory = [5, 0], faults = 2
Page 1: fault, memory = [5, 0, 1], faults = 3
Page 3: fault, memory = [5, 0, 1, 3], faults = 4
Page 2: fault, replaces LRU page 5, memory = [0, 1, 3, 2], faults = 5
Page 4: fault, replaces LRU page 0, memory = [1, 3, 2, 4], faults = 6
Page 1: already in memory, memory = [3, 2, 4, 1], faults = 6
Page 0: fault, replaces LRU page 3, memory = [2, 4, 1, 0], faults = 7
Page 5: fault, replaces LRU page 2, memory = [4, 1, 0, 5], faults = 8</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> c = 4, pages[] = [1, 1, 1, 1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Page fault occurs only for the first 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 ≤ n ≤ 10<sup>5</sup><br></span><span style="font-size: 18px;">1 ≤ c ≤ 10<sup>4</sup><br></span><span style="font-size: 18px;">1 ≤ pages[i] ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Greedy</code>&nbsp;<code>Algorithms</code>&nbsp;