# Write your MySQL query statement below
select e.name as Employee
from Employee e
join Employee d
on d.id = e.managerId 
where e.salary>d.salary;