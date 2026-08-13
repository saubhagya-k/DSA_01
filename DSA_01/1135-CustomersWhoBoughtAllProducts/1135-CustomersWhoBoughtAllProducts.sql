-- Last updated: 13/08/2026, 19:29:34
# Write your MySQL query statement below
SELECT c.customer_id
FROM Customer c,Product p
GROUP BY customer_id
HAVING COUNT(DISTINCT(c.product_key)) = COUNT(DISTINCT (p.product_key))