# Write your MySQL query statement below
select u.unique_id,e.name from Employees e LEFT JOIN EmployeeUNI u on e.id = u.id;