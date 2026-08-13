# Write your MySQL query statement below
select e.name from
(select count(*) as c,managerId from Employee
group by managerId having count(*)>=5) t
join Employee e
where e.id = t.managerId;