# Write your MySQL query statement below
with voters as (
    select voter, 
        round(pow(count(candidate), -1), 2) as vote
    from Votes
    where candidate is not null
    group by voter
), candidates as (
    select v.candidate, 
        sum(vote) as vote
    from Votes v
        join voters vr on vr.voter = v.voter
    group by v.candidate
)
select candidate
from candidates
where vote = (select max(vote) from candidates)
order by candidate;