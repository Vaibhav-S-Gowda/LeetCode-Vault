/* Method 1 */

SELECT
MAX(salary) AS SecondHighestSalary
FROM(
    SELECT
    salary,
    DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
) t 
WHERE rnk = 2;


/* Method 2 */
/*
SELECT
MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);
*/

/* Method 3 */

/* SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1, 1
   ) AS SecondHighestSalary;
*/