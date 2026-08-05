-- Last updated: 05/08/2026, 16:59:42
# Write your MySQL query statement below

SELECT email AS Email 
from Person
GROUP BY email
HAVING COUNT(email)>1;

