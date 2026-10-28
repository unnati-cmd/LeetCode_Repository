/* Write your T-SQL query statement below */
with cte as (
    select id,
        recordDate,
        temperature,
        lag(recordDate) over(order by recordDate) as lagDate,
        lag(temperature) over (order by recordDate) as lagTemp
    from weather
)
select id as Id
from cte
where datediff(day,recordDate,lagDate) = -1 and lagTemp<temperature;