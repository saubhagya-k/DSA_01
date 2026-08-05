-- Last updated: 05/08/2026, 16:59:34
# Write your MySQL query statement below
SELECT 
d.name AS Department,
e.name AS Employee,
e.salary AS Salary
FROM 
Employee e
INNER JOIN
Department d ON 
e.departmentId = d.id
WHERE e.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentId = e.departmentId
)
