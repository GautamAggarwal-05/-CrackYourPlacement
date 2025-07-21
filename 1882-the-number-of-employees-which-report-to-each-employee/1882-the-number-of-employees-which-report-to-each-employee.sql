# Write your MySQL query statement below
select e1.employee_id, e1.name, count(e1.name) as reports_count, Round(AVG(e2.age)) as average_age
from Employees e1
join Employees e2 on e1.employee_id=e2.reports_to 
group by e1.employee_id,e1.name
order by e1.employee_id;