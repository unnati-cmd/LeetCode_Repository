/* Write your T-SQL query statement below */
with cte1 as(
    select 
        visited_on,
        sum(amount) as amount
    from customer
    group by visited_on
), 
cte as (
    select 
        visited_on,
        sum(amount) over(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount,
        avg(cast(amount as FLOAT)) over(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as average_amount,
        row_number() over(order by visited_on) as rn
    from cte1
)
select 
    visited_on,
    amount,
    round(average_amount,2) as average_amount
from cte
where rn>6