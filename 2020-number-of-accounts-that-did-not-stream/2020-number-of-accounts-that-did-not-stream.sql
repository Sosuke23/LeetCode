# Write your MySQL query statement below
SELECT count(account_id) AS accounts_count
FROM Subscriptions
WHERE year(end_date) = '2021'
AND account_id NOT IN (
    SELECT DISTINCT account_id
    FROM Streams
    WHERE year(stream_date) = '2021'
);