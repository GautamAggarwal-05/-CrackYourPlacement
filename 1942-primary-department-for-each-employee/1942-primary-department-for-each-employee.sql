# Write your MySQL query statement below
select e.employee_id,e.department_id
from Employee e
where e.employee_id in (
    select employee_id from Employee group by employee_id having count(*)=1
)
OR e.primary_flag='Y';
