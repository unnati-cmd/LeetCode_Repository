# Write your MySQL query statement below
select 
    t.request_at as Day,
    round((sum( 
            case
                when t.status like 'cancelled%' then 1
                else 0
            end) / count(*)),2) as `Cancellation Rate`
from Trips t
join Users client
    on t.client_id = client.users_id
join Users driver
    on t.driver_id = driver.users_id
where client.banned = 'No' and driver.banned = 'No' and t.request_at between "2013-10-01" and "2013-10-03"
group by t.request_at
