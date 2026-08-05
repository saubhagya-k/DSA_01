-- Last updated: 05/08/2026, 22:45:40
# Write your MySQL query statement below

SELECT u.unique_id,e.name FROM Employees e
LEFT JOIN EmployeeUNI u
ON  e.id = u.id
