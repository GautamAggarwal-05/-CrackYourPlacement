# Write your MySQL query statement below
select max(m1.num) as num
from (select m.num as num
from MyNumbers as m
group by m.num
having count(m.num)=1) AS m1