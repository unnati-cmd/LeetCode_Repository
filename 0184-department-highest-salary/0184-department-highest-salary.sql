# Write your MySQL query statement below
SELECT t.Department,t.Employee,t.Salary
FROM
(
    SELECT
        d.name AS Department,
        e.name AS Employee,
        e.salary,
        Dense_rank()
        OVER(
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) AS highest_employee
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id
) t
WHERE highest_employee = 1;