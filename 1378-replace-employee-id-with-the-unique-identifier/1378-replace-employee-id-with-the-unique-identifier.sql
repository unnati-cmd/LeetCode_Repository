# Write your MySQL query statement below
select (
    select unique_id
    from EmployeeUNI u
    where e.id = u.id
) as unique_id, e.name
from Employees e;