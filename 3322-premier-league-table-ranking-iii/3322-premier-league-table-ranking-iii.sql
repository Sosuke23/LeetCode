# Write your MySQL query statement below
select season_id, team_id, team_name, wins * 3 + draws points, goals_for - goals_against goal_difference,
rank() over (partition by season_id order by wins * 3 + draws desc, goals_for - goals_against desc, team_name) position
from seasonstats
order by season_id, position, team_name