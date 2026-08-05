-- Last updated: 05/08/2026, 16:59:43
# Write your MySQL query statement below

SELECT DISTINCT l1.num AS ConsecutiveNums
FROM logs l1
JOIN logs l2 ON l1.id+1 = l2.id AND l1.num = l2.num
JOIN logs l3 ON l1.id+2 = l3.id AND l1.num = l3.num;
