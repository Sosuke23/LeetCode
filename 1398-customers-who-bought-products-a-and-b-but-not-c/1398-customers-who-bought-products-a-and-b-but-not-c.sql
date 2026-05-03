# Write your MySQL query statement below
select a.customer_id, b.customer_name
from orders a inner join customers b
on a.customer_id = b.customer_id
group by a.customer_id
having count(distinct case when product_name in ("A", "B") then product_name else null end) = 2
and count(case when product_name = "C" then product_name else null end) = 0 