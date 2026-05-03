select customer_name, customer_id, order_id, order_date 
from (
    select c.name as customer_name, o.customer_id, o.order_id, o.order_date, 
       dense_rank() over (partition by o.customer_id order by o.order_date desc) as ranking
    from Orders o join Customers c on o.customer_id=c.customer_id 
) as temp
where ranking <= 3
order by customer_name asc, customer_id asc, order_date desc