-- Last updated: 01/09/2026, 23:18:06
with CombinedFriends AS (

    SELECT requester_id AS id FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS id FROM RequestAccepted
)
SELECT id,COUNT(*) AS num
FROM CombinedFriends
GROUP BY id
ORDER BY num DESC
LIMIT 1




