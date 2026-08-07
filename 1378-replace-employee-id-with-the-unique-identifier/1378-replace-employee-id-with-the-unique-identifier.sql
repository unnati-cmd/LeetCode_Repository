# Write your MySQL query statement below
select (
    select unique_id 
    from EmployeeUNI e
    where e.id = d.id
) as unique_id, d.name
from Employees d;