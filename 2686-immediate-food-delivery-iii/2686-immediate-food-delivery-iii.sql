# Write your MySQL query statement below
SELECT order_date, ROUND(AVG(is_immediate) * 100, 2) AS immediate_percentage
FROM (
    SELECT order_date, DATEDIFF(customer_pref_delivery_date, order_date) = 0 AS is_immediate
    FROM Delivery
) T1
GROUP BY order_date
ORDER BY order_date ASC;