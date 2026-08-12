with cte1 as (
    select distinct product_id
    from Products
),
cte2 as(
    select product_id,
    max(change_date) as change_date
    from Products
    where change_date<='2019-08-16'
    group by product_id
)

select cte1.product_id,
isnull(p.new_price,10) as price
from cte1
left join cte2
on cte1.product_id = cte2.product_id
left join Products p
on cte2.change_date = p.change_date and p.product_id = cte2.product_id;