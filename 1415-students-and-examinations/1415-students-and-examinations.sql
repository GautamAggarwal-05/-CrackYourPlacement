# Write your MySQL query statement below
select s.student_id,s.student_name,sb.subject_name,count(e.student_id) AS attended_exams
from Students s
cross join Subjects sb
left join Examinations e on s.student_id=e.student_id and sb.subject_name=e.subject_name
group by s.student_id,sb.subject_name
order by s.student_id,sb.subject_name;