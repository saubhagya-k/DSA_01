-- Last updated: 05/08/2026, 16:59:31
WITH RankedEmployees AS (
    SELECT 
        name AS Employee,
        salary AS Salary,
        departmentId,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rk
    FROM Employee
)
SELECT 
    d.name AS Department,
    e.Employee,
    e.Salary
FROM RankedEmployees e
JOIN Department d ON e.departmentId = d.id
WHERE e.rk <= 3;
