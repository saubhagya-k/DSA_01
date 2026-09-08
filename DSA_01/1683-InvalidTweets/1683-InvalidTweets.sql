-- Last updated: 08/09/2026, 11:34:49
# Write your MySQL query statement below
SELECT tweet_id FROM Tweets
WHERE CHAR_LENGTH(content) > 15