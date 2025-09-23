


CREATE OR REPLACE TABLE fact_hospital_admissions AS
SELECT
    p.Patient_ID,
    d.Doctor_ID,
    dept.Department_ID,
    v.Admitted_Date,
    v.Stayed_Days,
    v.Total_Amount,

    -- Derived Measures
    (v.Total_Amount / NULLIF(v.Stayed_Days, 0)) AS Avg_Cost_Per_Day, -- avoid divide by zero
    CASE 
        WHEN v.Stayed_Days > 10 THEN 'Long Stay'
        WHEN v.Stayed_Days BETWEEN 5 AND 10 THEN 'Medium Stay'
        ELSE 'Short Stay'
    END AS Stay_Category

FROM stg_admissions_v v
JOIN dim_patient p ON v.Patient_ID = p.Patient_ID
JOIN dim_doctor d ON v.Doctor_ID = d.Doctor_ID
JOIN dim_department dept ON v.Department_ID = dept.Department_ID;
-------

SELECT dept.Department_Name, SUM(f.Total_Amount) AS Total_Revenue
FROM fact_hospital_admissions f
JOIN dim_department dept ON f.Department_ID = dept.Department_ID
GROUP BY dept.Department_Name;



Average Stay Days by Doctor

SELECT d.Doctor_Name, AVG(f.Stayed_Days) AS Avg_Stay
FROM fact_hospital_admissions f
JOIN dim_doctor d ON f.Doctor_ID = d.Doctor_ID
GROUP BY d.Doctor_Name;


Patient Cost Trend (per month)

SELECT DATE_TRUNC('month', f.Admitted_Date) AS Month, SUM(f.Total_Amount) AS Monthly_Revenue
FROM fact_hospital_admissions f
GROUP BY Month
ORDER BY Month;


Stay Category Distribution

SELECT Stay_Category, COUNT(*) AS Count
FROM fact_hospital_admissions
GROUP BY Stay_Category;








CREATE OR REPLACE VIEW hospital_analytics AS
WITH dept_revenue AS (
    SELECT d.Department_Name, SUM(f.Treatment_Cost) AS total_revenue
    FROM fact_admissions f
    JOIN dim_department d ON f.Department_ID = d.Department_ID
    GROUP BY d.Department_Name
),
doctor_stay AS (
    SELECT doc.Doctor_Name, AVG(f.Days_Stayed) AS avg_days
    FROM fact_admissions f
    JOIN dim_doctor doc ON f.Doctor_ID = doc.Doctor_ID
    GROUP BY doc.Doctor_Name
),
city_spending AS (
    SELECT p.City, SUM(f.Treatment_Cost) AS city_spending
    FROM fact_admissions f
    JOIN dim_patient p ON f.Patient_ID = p.Patient_ID
    GROUP BY p.City
)
SELECT
    dr.Department_Name,
    dr.total_revenue,
    ds.Doctor_Name,
    ds.avg_days,
    cs.City,
    cs.city_spending
FROM dept_revenue dr
LEFT JOIN doctor_stay ds ON 1=1   -- cross join to combine outputs
LEFT JOIN city_spending cs ON 1=1;



CREATE OR REPLACE VIEW fact_admissions AS
SELECT 
    Admission_ID,
    Patient_ID,
    Doctor_ID,
    Department_ID,
    TO_DATE(REPLACE("Date", '''', ''), 'YYYY-MM-DD') AS Admission_Date,
    CAST(Treatment_Cost AS NUMBER) AS Treatment_Cost,
    CAST(Days_Stayed AS INT) AS Days_Stayed
FROM raw_hospital_data;





A function app lets you group functions as a logical unit for easier management, deployment, scaling and sharing of resources. It runs code in a serverless environment without having to create a virtual machine or publish a web application. 
Basically, it's a piece of code that runs on Microsoft's cloud computing platform and can be written in various languages (JavaScript, C#, or Java, to name a few). It will work the same whether you use Windows or Linux as your operating system.

Features:
•	It is built on the Azure app service and supports features such as authentication, source control integration, monitoring, and application insights integration.
•	We can create complex orchestrations using Azure functions by writing code and using the durable functions extension. 
•	There are about a dozen built-in binding types for connection; we only need to write code if we need custom bindings. 
•	We can monitor it using Azure Application Insights and manage them using REST API and visual studio. 
•	We can run it locally or in the cloud. 
•	Azure functions offer more developer productivity, development environments, pricing, and programming languages than WebJobs and Azure App Service do.

Common types of triggers include:
HTTP Trigger
An HTTP trigger is used to invoke a function whenever an HTTP request is received. It supports different request methods like GET, POST, PUT, and DELETE, making it very flexible for building services. 
This trigger is widely used for creating lightweight APIs that external applications or users can call directly. It is also useful for handling webhooks where third-party services send real-time data.
Timer Trigger
The Timer trigger allows a function to run automatically based on a predefined schedule. The schedule is defined using a CRON expression, which specifies exact times or intervals for execution. 
This is especially useful for recurring jobs such as data cleanups, scheduled backups, or sending daily notifications. Since it runs without user interaction, it ensures automation of background tasks. It helps maintain systems by executing functions at fixed, predictable times.

Blob Trigger
A Blob trigger executes a function when a file (blob) is created or modified in Azure Blob Storage. This makes it highly effective for file processing workflows such as automatically resizing images, converting documents, or scanning files for security threats. 
Whenever a new blob is uploaded, the function gets activated without manual intervention.
 It enables real-time reaction to storage changes and helps automate file management. In short, it is best suited for event-driven scenarios involving file uploads or updates.

Queue Trigger
The Queue trigger starts a function when a new message is added to an Azure Storage Queue. It is commonly used to handle background jobs or tasks that do not need immediate user interaction.
 For example, after a user submits a request, a message can be placed in the queue for later processing by the function. This allows applications to remain fast and responsive while heavy tasks are handled asynchronously. It ensures reliability and scalability in distributed applications.

Event Hub Trigger
An Event Hub trigger executes a function whenever events are published into Azure Event Hub. Event Hub is designed for high-throughput event streaming, meaning it can handle millions of events per second. This makes it suitable for IoT solutions, telemetry collection, and real-time data analytics.
 Functions can process incoming streams of data instantly, ensuring up-to-date insights. It is best suited for scenarios requiring large-scale event ingestion and real-time monitoring.


 COST MANAGEMENT

 Azure Cost Management is a free solution offered to Azure cloud customers via the Azure portal. It provides information about our overall costs and utilization across all Azure services and Azure Marketplace products. 

To manage and monitor Azure costs effectively, it is important to review the spending for the current month and see how much has been consumed across different services. 
•	This includes checking whether various cost entities, such as departments, projects, or teams, are staying within their allocated budgets. 
•	It is also crucial to identify any cost anomalies, such as abnormal usage patterns, unexpected surges, or spikes in service consumption, to ensure that costs remain reasonable and aligned with normal operations.
•	Additionally, comparing the invoiced amount with actual service usage helps verify that billing matches expectations and allows detection of any significant changes compared to previous months. 
•	Finally, analyzing and splitting costs between departments, projects, or individuals ensures accurate allocation and accountability, enabling better financial planning and cost management within the organization.
AZURE PRICING CALCULATORS
The Azure Pricing Calculator is a tool that helps estimate the cost of using various Azure services before deploying them. It allows users to select services, configure specifications such as virtual machine size, storage, or networking, and view an estimated monthly or yearly cost. This helps organizations plan and forecast expenses accurately and make informed decisions about which services to use.
AZURE BUDGETS
 Azure Budgets, on the other hand, enable setting spending limits for subscriptions, resource groups, or specific services. They allow tracking actual costs against the defined budget, sending alerts when spending approaches or exceeds the limit, and ensuring better financial control. Together, the Pricing Calculator and Budgets provide visibility, predictability, and governance over Azure expenses, helping organizations optimize costs and avoid unexpected charges.

How to use efficiently
Underutilized virtual machines, particularly those with low CPU or network usage, should be identified so that organizations can decide whether to shut them down or resize them to better match their workload.
 For virtual machines that have been running consistently over a long period, purchasing Reserved Instances (RIs) can provide significant cost savings.
 Similarly, unused network resources, such as ExpressRoute circuits, virtual network gateways, or public IP addresses, should be removed to avoid unnecessary charges. 
Database usage can also be optimized by right-sizing instances for MariaDB, MySQL, or PostgreSQL based on actual demand. Overall, these practices help in reducing waste, improving efficiency, and lowering cloud costs.

Features
Expense Evaluation – Monitor and display your expenditures across subscriptions, resource categories, and services to identify the sources of costs.
Budgets and Alerts – Establish budgets for subscriptions or departments and get notified when expenditures near or surpass the specified threshold.
Cost Distribution – Allocate expenses among departments, initiatives, or teams to maintain precise billing and responsibility.
Suggestions and Enhancements – Pinpoint resources that are not fully utilized, recommend resizing or decommissioning VMs, and offer strategies to lower total expenses.
Forecasting and Reporting – Anticipate upcoming expenditures by analyzing past consumption and create comprehensive reports for stakeholders to aid in financial planning.



