# Write your MySQL query statement below
with cte as(
    select state,
           count(*) as matching_letter_count
    from cities
    where substr(state,1,1) = substr(city,1,1)
    group by state
)
select state,
       group_concat(city order by city separator ', ') as cities,
       matching_letter_count
from cities left join cte using(state)
where matching_letter_count is not null
group by state
having count(city) >= 3
order by 3 desc,1;