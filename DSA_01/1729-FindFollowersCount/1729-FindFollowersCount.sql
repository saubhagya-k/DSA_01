-- Last updated: 08/09/2026, 11:34:43
# Write your MySQL query statement below
SELECT user_id,COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id ASC
