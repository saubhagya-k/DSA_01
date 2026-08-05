-- Last updated: 05/08/2026, 16:53:48
# Write your MySQL query statement below

SELECT DISTINCT author_id AS id FROM Views 
WHERE author_id = viewer_id ORDER BY id ASC