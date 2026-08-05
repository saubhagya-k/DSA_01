-- Last updated: 05/08/2026, 16:59:53
# Write your MySQL query statement below


SELECT firstName,lastName,city,state
FROM Person
LEFT JOIN Address ON  Person.personId = Address.personId;
