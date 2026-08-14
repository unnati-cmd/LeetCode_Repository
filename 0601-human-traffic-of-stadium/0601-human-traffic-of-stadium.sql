# Write your MySQL query statement below
with cte as (
    select id,visit_date,people,
    id - row_number() over(order by id) as g
    from Stadium
    where people>99
),
cte2 as(
    select g
    from cte
    group by (g)
    having count(g)>2
)

select id,visit_date,people
from cte join cte2
where cte.g = cte2.g
order by (visit_date);