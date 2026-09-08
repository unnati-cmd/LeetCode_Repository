# Write your MySQL query statement below
with cte as (
    select 
        player_id,
        device_id,
        event_date,
        lag(event_date) over(partition by player_id order by event_date) as Next_Date,
        row_number() over(partition by player_id order by event_date) as rn
    from Activity
)
select 
    round(count(player_id) / (
        select count(distinct player_id)
        from Activity
    ),2) as fraction
from cte c
where datediff(c.event_date,Next_Date) = 1 and rn = 2