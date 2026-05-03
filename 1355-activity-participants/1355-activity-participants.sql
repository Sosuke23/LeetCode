# Write your MySQL query statement below
WITH user_by_activity AS
    (
    SELECT activity, COUNT(DISTINCT id) AS user_cnts
    FROM Friends
    GROUP BY activity
    )
SELECT activity
FROM user_by_activity
WHERE user_cnts NOT IN (SELECT MAX(user_cnts) FROM user_by_activity)
AND user_cnts NOT IN (SELECT MIN(user_cnts) FROM user_by_activity)