# Write your MySQL query statement below
select c.name as Customers
from Customers c
where not exists (
    select customerID
    from Orders
    where c.id = customerId
)