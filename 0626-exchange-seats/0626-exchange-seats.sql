/* Write your T-SQL query statement below */
with cte as(
    select *,
        row_number() over(order by id desc) as rn
    from seat
)
select
    case 
        when id%2=0 then id-1
        when rn = 1 and id%2!=0 then id
        else id+1
    end as id,
    student
from cte
order by id