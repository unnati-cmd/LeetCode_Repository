# Write your MySQL query statement below
Select distinct t.num as ConsecutiveNums
from(
    SELECT 
    id,
    num,
    LAG(num) OVER (ORDER BY id) AS previous_day,
    LEAD(num) OVER (ORDER BY id) AS next_day
FROM Logs)t
where t.num = t.previous_day and t.num = t.next_day;