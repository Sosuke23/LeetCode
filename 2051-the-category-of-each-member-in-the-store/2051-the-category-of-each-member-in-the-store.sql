# Write your MySQL query statement below
WITH agg AS (
    SELECT 
        v.member_id,
        COUNT(v.visit_id) AS visit_cnt,
        COUNT(p.visit_id) AS purchase_cnt
    FROM Visits v
    LEFT JOIN Purchases p
        ON v.visit_id = p.visit_id
    GROUP BY v.member_id
)
SELECT 
    m.member_id,
    m.name,
    CASE 
        WHEN a.member_id IS NULL THEN 'Bronze'
        WHEN (100.0 * a.purchase_cnt / a.visit_cnt) >= 80 THEN 'Diamond'
        WHEN (100.0 * a.purchase_cnt / a.visit_cnt) >= 50 THEN 'Gold'
        ELSE 'Silver'
    END AS category
FROM Members m
LEFT JOIN agg a
    ON m.member_id = a.member_id;