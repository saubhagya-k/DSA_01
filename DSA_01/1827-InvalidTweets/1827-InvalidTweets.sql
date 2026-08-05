-- Last updated: 05/08/2026, 16:53:04
# Write your MySQL query statement below
SELECT tweet_id FROM Tweets
WHERE CHAR_LENGTH(content) > 15