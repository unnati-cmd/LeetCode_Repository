/* Write your T-SQL query statement below */
with cte as (
    select
        lag(num) over(order by id) as lag,
        num,
        lead(num) over(order by id) as lead
    from logs
)
select distinct num as ConsecutiveNums
from cte
where lag = num and num = lead;