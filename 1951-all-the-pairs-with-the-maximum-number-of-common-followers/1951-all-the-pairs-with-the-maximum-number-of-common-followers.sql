# Write your MySQL query statement below
with cte as(
    SELECT r1.user_id as user1_id, r2.user_id as user2_id, COUNT(distinct r1.follower_id) as cn
    FROM Relations r1 JOIN Relations r2 on r1.follower_id = r2.follower_id
    AND r1.user_id < r2.user_id
    GROUP BY r1.user_id, r2.user_id
),
cte1 as(
SELECT *,
RANK()OVER( ORDER BY cn DESC) as rn
FROM cte)

SELECT user1_id, user2_id
FROM cte1
WHERE rn = 1