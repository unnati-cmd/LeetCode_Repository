/* Write your T-SQL query statement below */
with cte as (
    select
        player_id,
        event_date,
        lead(event_date) over(partition by player_id order by event_date) as leading_date,
        row_number() over(partition by player_id order by event_date) as rn
    from activity
)
select 
    round(sum(
        case 
            when datediff(day,event_date,leading_date)=1 then 1
            else 0
        end
    )*1.0/count(player_id),2) as fraction
from cte
where rn = 1