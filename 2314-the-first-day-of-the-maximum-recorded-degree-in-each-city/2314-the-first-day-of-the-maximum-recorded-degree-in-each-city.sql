# Write your MySQL query statement below
SELECT city_id, day, degree
FROM (
SELECT city_id, day, degree,
ROW_NUMBER() over (partition by city_id order by degree desc, day asc) rnk
FROM Weather
) A
WHERE rnk = 1
ORDER BY 1