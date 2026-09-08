-- Last updated: 08/09/2026, 11:34:53
# Write your MySQL query statement below
SELECT contest_id,
ROUND(COUNT(r.user_id)*100/(SELECT COUNT(*) FROM Users),2) AS percentage
FROM Register r
GROUP BY r.contest_id 
ORDER BY percentage DESC ,r.contest_id ASC;