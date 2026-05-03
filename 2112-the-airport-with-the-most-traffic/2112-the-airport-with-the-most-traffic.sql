# Write your MySQL query statement below
WITH
trips AS (
    SELECT departure_airport AS airport_id, flights_count
    FROM Flights
    UNION ALL
    SELECT arrival_airport AS airport_id, flights_count
    FROM Flights
),
counts AS (
    SELECT airport_id,
    SUM(flights_count) AS total
    FROM trips
    GROUP BY airport_id
)
SELECT airport_id
FROM counts
WHERE total = (SELECT MAX(total) FROM counts);