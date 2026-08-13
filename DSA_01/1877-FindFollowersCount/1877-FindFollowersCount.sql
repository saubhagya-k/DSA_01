-- Last updated: 13/08/2026, 19:28:44
# Write your MySQL query statement below
SELECT user_id,COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id ASC
