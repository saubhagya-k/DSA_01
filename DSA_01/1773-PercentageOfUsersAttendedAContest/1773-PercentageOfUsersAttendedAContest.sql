-- Last updated: 07/08/2026, 22:21:41
# Write your MySQL query statement below
SELECT contest_id,
ROUND(COUNT(r.user_id)*100/(SELECT COUNT(*) FROM Users),2) AS percentage
FROM Register r
GROUP BY r.contest_id 
ORDER BY percentage DESC ,r.contest_id ASC;