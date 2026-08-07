# Write your MySQL query statement below
select e.name as Employee
from Employee e
where salary>(
    select d.salary
    from Employee d
    where d.id = e.managerId
)