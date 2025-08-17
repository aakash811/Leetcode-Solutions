# Write your MySQL query statement below
SELECT 
    mngr.employee_id, 
    mngr.name, 
    COUNT(emp.employee_id) AS reports_count,
    ROUND(AVG(emp.age)) AS average_age
FROM employees emp 
JOIN employees mngr ON emp.reports_to = mngr.employee_id
GROUP BY employee_id
ORDER BY employee_id