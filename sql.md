 CREATE TABLE Customer_Details (
    CustomerID INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(100) NOT NULL,
    Email VARCHAR(100) UNIQUE NOT NULL,
    Phone VARCHAR(15) UNIQUE NOT NULL,
    Address VARCHAR(255)
);


CREATE TABLE Car_Details (
    CarID INT PRIMARY KEY AUTO_INCREMENT,
    CarModel VARCHAR(100) NOT NULL,
    RegistrationNumber VARCHAR(20) UNIQUE NOT NULL,
    PricePerDay DECIMAL(10,2) NOT NULL CHECK (PricePerDay > 0),
    AvailabilityStatus VARCHAR(20) DEFAULT 'Available'
);


CREATE TABLE Booking_Details (
    BookingID INT PRIMARY KEY AUTO_INCREMENT,
    CustomerID INT NOT NULL,
    BookingDate DATE NOT NULL,
    ReturnDate DATE,
    Status VARCHAR(20) DEFAULT 'Pending',
    FOREIGN KEY (CustomerID) REFERENCES Customer_Details(CustomerID)
);

-- Junction table for many-to-many (Booking ↔ Cars)
CREATE TABLE Booking_Car (
    BookingID INT,
    CarID INT,
    PRIMARY KEY (BookingID, CarID),
    FOREIGN KEY (BookingID) REFERENCES Booking_Details(BookingID),
    FOREIGN KEY (CarID) REFERENCES Car_Details(CarID)
);


CREATE TABLE Payment_Details (
    PaymentID INT PRIMARY KEY AUTO_INCREMENT,
    BookingID INT NOT NULL,
    PaymentDate DATE NOT NULL,
    AmountPaid DECIMAL(10,2) NOT NULL CHECK (AmountPaid > 0),
    PaymentMethod VARCHAR(50) NOT NULL, -- UPI, Card, Cash
    Status VARCHAR(20) DEFAULT 'Completed',
    FOREIGN KEY (BookingID) REFERENCES Booking_Details(BookingID)
);




 -- Customers
INSERT INTO Customer_Details (Name, Email, Phone, Address) VALUES
('Kaviya', 'kaviya@gmail.com', '9876543210', 'Chennai'),
('Preethi', 'preethi@gmail.com', '8765432109', 'Coimbatore');

-- Cars
INSERT INTO Car_Details (CarModel, RegistrationNumber, PricePerDay) VALUES
('Hyundai i20', 'TN01AB1234', 1200.00),
('Toyota Innova', 'TN02CD5678', 2500.00),
('Honda City', 'TN03EF9101', 1800.00);

-- Booking (Kaviya books 2 cars in one booking → normalized via Booking_Car)
INSERT INTO Booking_Details (CustomerID, BookingDate, ReturnDate, Status) VALUES
(1, '2025-08-28', '2025-08-30', 'Confirmed');

-- Junction table links multiple cars to 1 booking
INSERT INTO Booking_Car VALUES
(1, 1),  -- Booking 1 → Hyundai i20
(1, 2);  -- Booking 1 → Toyota Innova

-- Payment
INSERT INTO Payment_Details (BookingID, PaymentDate, AmountPaid, PaymentMethod, Status) VALUES
(1, '2025-08-28', 3700.00, 'UPI', 'Completed');





 SELECT b.BookingID, c.Name AS CustomerName, car.CarModel, p.AmountPaid, p.PaymentMethod
FROM Booking_Details b
JOIN Customer_Details c ON b.CustomerID = c.CustomerID
JOIN Booking_Car bc ON b.BookingID = bc.BookingID
JOIN Car_Details car ON bc.CarID = car.CarID
JOIN Payment_Details p ON b.BookingID = p.BookingID;




CREATE PROCEDURE DeleteOldRecords
AS
BEGIN
    DECLARE 
        @TableName NVARCHAR(100),
        @SchemaName NVARCHAR(100),
        @NoOfDays INT,
        @SQL NVARCHAR(MAX);

    BEGIN TRY
        BEGIN TRANSACTION;  -- 🚀 Start transaction

        DECLARE DeleteCursor CURSOR FOR
            SELECT TableName, SchemaName, NoOfDays
            FROM TableConfig;

        OPEN DeleteCursor;

        FETCH NEXT FROM DeleteCursor 
        INTO @TableName, @SchemaName, @NoOfDays;

        WHILE @@FETCH_STATUS = 0
        BEGIN
            SET @SQL = '
                DELETE FROM ' + QUOTENAME(@SchemaName) + '.' + QUOTENAME(@TableName) + '
                WHERE DateColumn < DATEADD(DAY, -' + CAST(@NoOfDays AS NVARCHAR(10)) + ', GETDATE());';

            PRINT @SQL;
            EXEC sp_executesql @SQL;

            FETCH NEXT FROM DeleteCursor 
            INTO @TableName, @SchemaName, @NoOfDays;
        END;

        CLOSE DeleteCursor;
        DEALLOCATE DeleteCursor;

        COMMIT TRANSACTION;  -- ✅ Commit only if all succeed
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;  -- ❌ Rollback everything if error occurs
        THROW; -- re-raise error
    END CATCH
END;
GO


 CREATE SCHEMA Demo; -- Just for organizing

-- Table 1
CREATE TABLE Demo.Table1 (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    Data NVARCHAR(100),
    DateColumn DATETIME
);

-- Table 2
CREATE TABLE Demo.Table2 (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    Data NVARCHAR(100),
    DateColumn DATETIME
);

-- Table 3
CREATE TABLE Demo.Table3 (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    Data NVARCHAR(100),
    DateColumn DATETIME
);

-- Table 4
CREATE TABLE Demo.Table4 (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    Data NVARCHAR(100),
    DateColumn DATETIME
);

-- Table 5
CREATE TABLE Demo.Table5 (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    Data NVARCHAR(100),
    DateColumn DATETIME
);




 INSERT INTO TableConfig (SchemaName, TableName, NoOfDays) VALUES
('Demo', 'Table1', 15), -- Keep last 15 days
('Demo', 'Table2', 30),
('Demo', 'Table3', 90),
('Demo', 'Table4', 7),
('Demo', 'Table5', 45);

________
CREATE PROCEDURE DeleteOldRecords
AS
BEGIN
    DECLARE @TableName NVARCHAR(100),
            @SchemaName NVARCHAR(100),
            @NoOfDays INT,
            @SQL NVARCHAR(MAX),
            @RowCount INT;

    BEGIN TRY
        BEGIN TRANSACTION;  -- 🚀 Start transaction

        DECLARE DeleteCursor CURSOR FOR
            SELECT TableName, SchemaName, NoOfDays
            FROM TableConfig;

        OPEN DeleteCursor;

        FETCH NEXT FROM DeleteCursor 
        INTO @TableName, @SchemaName, @NoOfDays;

        WHILE @@FETCH_STATUS = 0
        BEGIN
            SET @SQL = '
                DELETE FROM ' + QUOTENAME(@SchemaName) + '.' + QUOTENAME(@TableName) + '
                WHERE DateColumn < DATEADD(DAY, -' + CAST(@NoOfDays AS NVARCHAR(10)) + ', GETDATE());';

            PRINT @SQL;

            EXEC sp_executesql @SQL;

            -- Get number of deleted rows
            SET @RowCount = @@ROWCOUNT;

            -- Insert into logs
            INSERT INTO DeleteLogs (schema_name, table_name, deleted_rows, status)
            VALUES (@SchemaName, @TableName, @RowCount, 'SUCCESS');

            FETCH NEXT FROM DeleteCursor 
            INTO @TableName, @SchemaName, @NoOfDays;
        END;

        CLOSE DeleteCursor;
        DEALLOCATE DeleteCursor;

        COMMIT TRANSACTION;  -- ✅ Commit only if all succeed
    END TRY
    BEGIN CATCH
        -- Log error
        INSERT INTO DeleteLogs (schema_name, table_name, deleted_rows, status, error_message)
        VALUES (@SchemaName, @TableName, 0, 'FAILED', ERROR_MESSAGE());

        ROLLBACK TRANSACTION;  -- ❌ Rollback everything if error occurs
        THROW; -- re-raise error
    END CATCH
END;
GO






CREATE TABLE DeleteLogs (
    log_id INT IDENTITY PRIMARY KEY,
    schema_name NVARCHAR(100),
    table_name NVARCHAR(100),
    deleted_rows INT,
    deleted_on DATETIME DEFAULT GETDATE(),
    status NVARCHAR(20),
    error_message NVARCHAR(MAX) NULL
);
