-- Last updated: 27/08/2026, 12:52:00
# Write your MySQL query statement below
(SELECT  u.name AS results
FROM Users u
LEFT JOIN MovieRating m
ON u.user_id = m.user_id
GROUP BY u.user_id, u.name 
ORDER BY
COUNT(m.movie_id) DESC,
u.name ASC

LIMIT 1

)

UNION ALL

(SELECT m.title AS results

FROM Movies m
LEFT JOIN MovieRating mr
ON m.movie_id = mr.movie_id

WHERE mr.created_at >= '2020-02-01' AND mr.created_at <= '2020-02-29'


GROUP BY 
m.movie_id
ORDER BY AVG(mr.rating) DESC,
m.title ASC
LIMIT 1

)





