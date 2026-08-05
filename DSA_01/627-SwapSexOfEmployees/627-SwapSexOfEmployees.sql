-- Last updated: 05/08/2026, 16:56:25
UPDATE Salary
SET sex = CASE 
    WHEN sex = 'm' THEN 'f' 
    ELSE 'm' 
END;
