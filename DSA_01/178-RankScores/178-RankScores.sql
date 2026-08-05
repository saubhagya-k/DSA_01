-- Last updated: 05/08/2026, 16:59:48
SELECT
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
FROM 
    Scores;
