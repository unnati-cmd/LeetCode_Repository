/* Write your T-SQL query statement below */
with cte as (
    select
        c.customer_id,
        count(distinct product_key) as cnt
    from customer c
    group by c.customer_id
),
cte2 as (
    select count(product_key) as keys
    from product
)
select
    customer_id
from cte cross join cte2
where cnt = keys