# Write your MySQL query statement below

select s.id, s.name from Students s where s.department_id  not in (select d.id from Departments d);