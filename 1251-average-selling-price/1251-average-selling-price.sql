# Write your MySQL query statement below
select p.product_id,
    CASE
        WHEN SUM(units) IS NOT NULL
        THEN ROUND(SUM(price * units) / SUM(units),2)
        ELSE 0
    END as average_price 
from Prices p
left join UnitsSold u
on p.product_id = u.product_id and u.purchase_date between p.start_date and p.end_date
group by p.product_id;