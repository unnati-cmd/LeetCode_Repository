# Write your MySQL query statement below
with cte as(
    select 
        accepter_id as id,
        count(*) as num
    from RequestAccepted
    group by accepter_id

    union all

    select 
        requester_id as id,
        count(*) as num
    from RequestAccepted
    group by requester_id
)
select
    id, sum(cte.num) as num
from cte
group by cte.id
having max(num)
order by num desc
limit 1