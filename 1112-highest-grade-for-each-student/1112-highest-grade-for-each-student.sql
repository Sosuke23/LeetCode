# Write your MySQL query statement below
select t.student_id as student_id, t.course_id as course_id, t.grade as grade
from (
    select student_id, course_id, grade,
    row_number() over(partition by student_id order by grade desc,course_id ASC) as highest
    from enrollments
) t
where highest = 1