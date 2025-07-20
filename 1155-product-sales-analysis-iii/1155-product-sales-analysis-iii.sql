# Write your MySQL query statement below
select s1.product_id,s1.year as first_year,s1.quantity,s1.price
from Sales s1
join 
(select min(s.year) as first_year ,s.product_id
from Sales s
group by s.product_id) as s2 
on s2.first_year=s1.year and s2.product_id = s1.product_id;