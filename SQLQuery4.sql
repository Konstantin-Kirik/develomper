SELECT *FROM Customers
SELECT *FROM Orders
SELECT *FROM Employees
SELECT AVG(Freight) AS 'sred' FROM Orders
SELECT MIN(Freight) FROM Orders;

SELECT * FROM Orders
WHERE Freight > (SELECT AVG (Freight) FROM Orders);

SELECT ShipVia, COUNT(*) as 'Ship'  FROM Orders Group by ShipVia  

--вывести количество инструкторов по каждой секции;  

SELECT Country, COUNT(Country) AS 'CompanyQuantity' FROM Customers GROUP BY Country  --готово
SELECT ShipCity, COUNT (*) AS 'CompanyQuantity' FROM Orders GROUP BY ShipCity


--вывести количество посетителей фитнес клуба, ко-
--торые пользуются услугами определенного мобиль-
--ного оператора;
--select * from Customers where Phone LIKE '(11)%'

SELECT COUNT(*) AS 'CountOperator'FROM Customers WHERE Phone LIKE '(11)%' 
 

--получить количество посетителей, у которых фа-
--милия совпадает с фамилиями из определенного
--списка;
          --HAVING
		  
SELECT SUM(v.Company) FROM (SELECT c.CompanyName,COUNT(c.CompanyName) AS 'Company' FROM Employees e, Orders o, Customers c 
WHERE e.EmployeeID = o.EmployeeID AND o.CustomerID = c.CustomerID AND e.LastName = 'King' GROUP BY c.CompanyName) v 
WHERE v.Company > 1



--показать количество людей с одинаковыми именами,
--которых занимаются у определенного инструктора;


SELECT v.LastName, v.Companyes FROM (SELECT e.LastName, COUNT(c.CompanyName) AS 'Companyes' 
FROM Employees e, Orders o, Customers c
WHERE e.EmployeeID = o.EmployeeID AND o.CustomerID = c.CustomerID GROUP BY e.LastName) v WHERE v.LastName = 'King' 

--получить информацию о людях, которые посетили
--фитнес зал минимальное количество раз;

SELECT c.CompanyName, COUNT(c.CompanyName) FROM Employees e, Orders o, Customers c
WHERE e.EmployeeID = o.EmployeeID AND o.CustomerID = c.CustomerID GROUP BY c.CompanyName 
HAVING COUNT(c.CompanyName) = (SELECT MIN(v.Company) FROM (SELECT c.CompanyName,COUNT(c.CompanyName) AS 'Company' 
FROM Employees e, Orders o, Customers c 
WHERE e.EmployeeID = o.EmployeeID AND o.CustomerID = c.CustomerID GROUP BY c.CompanyName) v)

--вывести количество посетителей, которые зани-
--мались в определенной секции за первую полови-
--ну текущего года;

-- Можно так?
SELECT COUNT(*) AS 'OrdersSixMonth'FROM (SELECT * FROM Orders WHERE YEAR(OrderDate) BETWEEN 1997 AND 1997) v  
       WHERE MONTH(v.OrderDate) BETWEEN 1 AND 6
 
SELECT COUNT(c.CompanyName) AS 'OrdersSixMonth' FROM Employees e, Orders o, Customers c 
WHERE e.EmployeeID = o.EmployeeID AND 
o.CustomerID = c.CustomerID AND YEAR(OrderDate) = 1997 AND MONTH(OrderDate) BETWEEN 1 AND 6 -- AND e.EmployeeID = 4

--определить общее количество людей, посетивших
--фитнес зал за прошлый год.

-- Можно так?
SELECT COUNT(*) AS 'ALL ORDERS' FROM Orders WHERE YEAR(OrderDate) BETWEEN 1997 AND 1997

SELECT COUNT(c.CompanyName) AS 'ALL ORDERS' FROM Orders o, Customers c 
WHERE c.CustomerID=o.CustomerID AND YEAR (OrderDate) = 1997


