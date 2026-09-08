-- Last updated: 08/09/2026, 11:38:02
# Write your MySQL query statement below

SELECT DISTINCT author_id AS id FROM Views 
WHERE author_id = viewer_id ORDER BY id ASC