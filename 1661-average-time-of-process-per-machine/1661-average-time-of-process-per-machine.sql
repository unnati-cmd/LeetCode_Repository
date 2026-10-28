/* Write your T-SQL query statement below */
with cte as (
    select
        machine_id,
        sum(case
            when activity_type = 'start' then timestamp*-1
            end
        ) as timestamp_start,
        sum (case
            when activity_type = 'end' then timestamp*1
            end 
        )as timestamp_end,
        count(distinct process_id) as count
    from Activity
    group by machine_id
)
select 
    machine_id,
    round((timestamp_end + timestamp_start)/ count,3) as processing_time
from cte