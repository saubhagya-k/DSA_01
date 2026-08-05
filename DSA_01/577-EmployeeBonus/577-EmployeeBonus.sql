-- Last updated: 05/08/2026, 16:56:37
# Write your MySQL query statement below

SELECT name , bonus FROM Employee
LEFT JOIN 
Bonus ON Employee.empId = Bonus.empId
WHERE
bonus<1000 OR bonus is NULL;
