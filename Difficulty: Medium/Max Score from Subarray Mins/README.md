<h2><a href="https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1?_gl=1*1nxcp65*_up*MQ..*_gs*MQ..&gclid=Cj0KCQjw953DBhCyARIsANhIZoZmrubyYXplwuqpJn6wca6k-NHay-fQdG5Z2L19ZY_rAAL3JceRrNkaAl48EALw_wcB&gbraid=0AAAAAC9yBkCO9QQqAP6_1iDz3Tap-Quv1">Max Score from Subarray Mins</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p data-start="133" data-end="195"><span style="font-size: 14pt;">You are given an array <strong>arr[] </strong>of integers. Your task is to find the <strong>maximum</strong> <strong>sum </strong>of the <strong>smallest</strong> and <strong>second smallest</strong> elements across all subarrays (of size &gt;= 2) of the given array.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input:</strong><span style="font-size: 14pt;"> arr[] = [4, 3, 5, 1]
</span><strong style="font-size: 14pt;">Output:</strong><span style="font-size: 14pt;"> 8
</span><strong style="font-size: 14pt;">Explanation: </strong>A<span style="font-size: 18.6667px;">ll subarrays with at least 2 elements and find the two smallest numbers in each:
[4, 3] → 3 + 4 = 7
[4, 3, 5] → 3 + 4 = 7
[4, 3, 5, 1] → 1 + 3 = 4
[3, 5] → 3 + 5 = 8
[3, 5, 1] → 1 + 3 = 4
[5, 1] → 1 + 5 = 6<br></span></span><span style="font-size: 14pt;"><span style="font-size: 14pt;">Maximum Score is 8.</span></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [1, 2, 3]
<strong>Output:</strong> 5<br><strong>Explanation: </strong>All subarray with at least 2 elements and find the two smallest numbers in each:<strong><br></strong></span><span style="font-size: 14pt;">[1, 2] → 1 + 2 = 3<br></span><span style="font-size: 14pt;">[1, 2, 3] → 1 + 2 = 3<br>[2, 3] → 2 + 3 = 5<br>Maximum Score is 5</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>2 ≤ arr.size() ≤ 10<sup>5</sup><br>1 ≤ arr[i] ≤ 10<sup>6</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;