# Write your MySQL query tatement below
SELECT E1.Name
FROM Employee E1, Employee E2
WHERE E1.ManagerID = E2.Id AND
      E1.Salary > E2.Salary
