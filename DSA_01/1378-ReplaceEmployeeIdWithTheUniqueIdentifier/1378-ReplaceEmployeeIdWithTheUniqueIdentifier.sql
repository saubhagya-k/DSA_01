-- Last updated: 08/09/2026, 11:36:12
# Write your MySQL query statement below

SELECT u.unique_id,e.name FROM Employees e
LEFT JOIN EmployeeUNI u
ON  e.id = u.id
