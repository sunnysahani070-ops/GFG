<h2><a href="https://www.geeksforgeeks.org/problems/replace-the-bit3212/1">Unset Kth Bit</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;"><span style="font-family: arial, helvetica, sans-serif;">Given two numbers<strong> n</strong> and <strong>k</strong>, change the <strong>kth </strong>bit (1-based indexing, counted from the left) of <strong>n's</strong> binary representation to <strong>0</strong> if it is currently <strong>1</strong>. </span></span></p>
<p><span style="font-size: 14pt;"><span style="font-family: arial, helvetica, sans-serif;">No changes is made in the following cases:</span></span></p>
<ul>
<li><span style="font-size: 14pt;"><span style="font-family: arial, helvetica, sans-serif;">If kth bit is already<strong> 0 </strong></span></span></li>
<li><span style="font-size: 14pt;"><span style="font-family: arial, helvetica, sans-serif;"><strong>k</strong> exceeds the total number of bits in <strong>n</strong></span></span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>n = 13, k = 2<strong>
Output: </strong>9<strong>
Explanation: </strong>Binary representation of 13 is 1101. the 2nd bit from the left is 1, so it becomes 0, giving 1001 = 9.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>n = 13, k = 6<strong>
Output: </strong>13<strong>
Explanation: </strong>Binary representation of 13 is 1101, which only has 4 bits. there's no 6th bit from the left, so n is returned unchanged.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:<br></strong>1 ≤ n ≤ 10<sup>6</sup><br>1 ≤ k ≤ 20</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Bit Magic</code>&nbsp;