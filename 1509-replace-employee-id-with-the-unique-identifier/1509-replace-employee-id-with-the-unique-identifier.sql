# Write your MySQL query statement below
select coalesce(unique_id, null) as unique_id,
       name
from Employees a
left join EmployeeUNI b
on a.id = b.id