# Write your MySQL query statement below
select max(m1.num) as num
from MyNumbers as m1
join (select m.num as num
from MyNumbers as m
group by m.num
having count(m.num)=1) as m2
on m2.num = m1.num;