# Write your MySQL query statement below
with cte as (
    select *,
        case
            when change_date<='2019-08-16' then new_price
            else 10
        end as price
    from products
    where change_date<='2019-08-16'
),
cte2 as (
    select 
        p.product_id,
        case
            when c.price is null then 10
            else c.price
        end as price,
        row_number() over(partition by p.product_id order by c.change_date desc) as rn
    from products p
    left join cte c
        on p.product_id = c.product_id
)
select 
    product_id,
    price
from cte2
where rn = 1