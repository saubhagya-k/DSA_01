-- Last updated: 23/08/2026, 18:27:34
# Write your MySQL query statement below
SELECT t.x,t.y,t.z,


CASE
WHEN (t.x+t.y<=t.z)
THEN "No"
WHEN (t.y+t.z<=t.x)
THEN "No"
WHEN (t.z+t.x<=t.y)
THEN "No"
ELSE "Yes"
END AS triangle

FROM Triangle t