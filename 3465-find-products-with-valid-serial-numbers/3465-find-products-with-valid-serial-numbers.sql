/* Write your T-SQL query statement below */
select * 
from products
where description collate Latin1_General_100_CS_AS
    like '% SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9] %' 
    or
    description collate Latin1_General_100_CS_AS like '% SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]'
    or
    description collate Latin1_General_100_CS_AS like 'SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9] %'
    or
    description collate Latin1_General_100_CS_AS like 'SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]'
order by product_id;