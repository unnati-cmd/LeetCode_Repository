/* Write your T-SQL query statement below */
with count_of_nums as (
    select
        num,
        count(num) as cnt
    from mynumbers
    group by num
)
select max(num) as num
from count_of_nums
where cnt = 1