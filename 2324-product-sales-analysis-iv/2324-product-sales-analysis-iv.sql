WITH temp AS (
    SELECT s.user_id, s.product_id, RANK() OVER (PARTITION BY s.user_id ORDER BY SUM(s.quantity * p.price) DESC) AS top_product
    FROM Sales s
    LEFT JOIN Product p ON s.product_id = p.product_id
    GROUP BY s.user_id, p.product_id, p.price
)
SELECT user_id, product_id
FROM temp
WHERE top_product = 1