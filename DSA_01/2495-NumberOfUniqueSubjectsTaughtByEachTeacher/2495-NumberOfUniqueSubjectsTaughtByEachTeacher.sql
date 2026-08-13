-- Last updated: 13/08/2026, 10:59:14
# Write your MySQL query statement below
SELECT teacher_id,COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id