-- Last updated: 05/08/2026, 16:59:38
SELECT c.name AS Customers
FROM Customers AS c
LEFT JOIN Orders AS o
ON c.id = o.customerId 
WHERE o.customerId IS NULL;
