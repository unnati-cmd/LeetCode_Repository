/* Write your T-SQL query statement below */
with cte as (
    select 
        r.contest_id,
        count(u.user_id) as user_count
    from users u
    join register r
        on u.user_id = r.user_id
    group by r.contest_id
),
cte2 as (
    select count(distinct user_id) as total_count
    from users
)
select 
    contest_id,
    round((user_count*100.0)/total_count,2) as percentage
from cte cross join cte2
order by percentage desc, contest_id asc