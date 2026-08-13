-- Last updated: 13/08/2026, 19:30:30
# Write your MySQL query statement below
SELECT  class
FROM Courses

GROUP BY class
HAVING COUNT(student)>=5