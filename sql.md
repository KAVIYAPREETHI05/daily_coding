

using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;
using System.Text.Json;
using Snowflake.Data.Client;
using System.Data;

namespace weatherDataProcessing
{
    public class SnowflakeFunction
    {
        private readonly ILogger _logger;

        public SnowflakeFunction(ILoggerFactory loggerFactory)
        {
            _logger = loggerFactory.CreateLogger<SnowflakeFunction>();
        }

        [Function("FetchFromSnowflake")]
        public async Task<HttpResponseData> Run(
            [HttpTrigger(AuthorizationLevel.Function, "get")] HttpRequestData req)
        {
            _logger.LogInformation("Snowflake function triggered.");

            // ✅ Replace with your Snowflake connection details
            string connectionString = "account=<your_account>;" +
                                      "user=<your_username>;" +
                                      "password=<your_password>;" +
                                      "db=<your_db>;" +
                                      "schema=<your_schema>;" +
                                      "warehouse=<your_warehouse>;" +
                                      "role=<your_role>";

            List<Dictionary<string, object>> results = new();

            try
            {
                using (var conn = new SnowflakeDbConnection())
                {
                    conn.ConnectionString = connectionString;
                    conn.Open();

                    using (var cmd = conn.CreateCommand())
                    {
                        cmd.CommandText = "SELECT CURRENT_TIMESTAMP AS NOW, CURRENT_VERSION() AS VERSION;"; 
                        using (IDataReader reader = cmd.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                var row = new Dictionary<string, object>();
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    row[reader.GetName(i)] = reader.GetValue(i);
                                }
                                results.Add(row);

                                // print to console
                                Console.WriteLine(JsonSerializer.Serialize(row));
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                _logger.LogError($"Snowflake query failed: {ex.Message}");
                var errorRes = req.CreateResponse(System.Net.HttpStatusCode.InternalServerError);
                await errorRes.WriteStringAsync($"Error: {ex.Message}");
                return errorRes;
            }

            var response = req.CreateResponse(System.Net.HttpStatusCode.OK);
            await response.WriteStringAsync(JsonSerializer.Serialize(results, new JsonSerializerOptions { WriteIndented = true }));
            return response;
        }
    }
}
----------_------------









using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;
using System.IO;
using System.Text.Json;

namespace weatherDataProcessing
{
    public class Function1
    {
        private readonly ILogger _logger;

        public Function1(ILoggerFactory loggerFactory)
        {
            _logger = loggerFactory.CreateLogger<Function1>();
        }

        [Function("ProcessWeather")]
        public async Task<HttpResponseData> Run(
            [HttpTrigger(AuthorizationLevel.Function, "get", "post")] HttpRequestData req)
        {
            _logger.LogInformation("Weather function triggered.");

            //string basePath = AppContext.BaseDirectory;

            string projectRoot = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, @"..\..\.."));
            string rawPath = Path.Combine(projectRoot, "data", "raw.json");
            string processedPath = Path.Combine(projectRoot, "data", "processed.json");


            if (!File.Exists(rawPath))
            {
                var res = req.CreateResponse(System.Net.HttpStatusCode.NotFound);
                await res.WriteStringAsync(" raw.json not found.");
                return res;
            }

            string rawJson = await File.ReadAllTextAsync(rawPath);
            var options = new JsonSerializerOptions { PropertyNameCaseInsensitive = true };

            var weatherData = JsonSerializer.Deserialize<List<WeatherRecord>>(rawJson, options)
                              ?? new List<WeatherRecord>();

            foreach (var record in weatherData)
            {
                record.location ??= "Unknown";
                record.weather ??= "Not Available";
                record.date_ = string.IsNullOrWhiteSpace(record.date_)
                              ? DateTime.UtcNow.ToString("yyyy-MM-dd")
                              : record.date_;
            }

            string processedJson = JsonSerializer.Serialize(weatherData, new JsonSerializerOptions { WriteIndented = true });
            await File.WriteAllTextAsync(processedPath, processedJson);

            var response = req.CreateResponse(System.Net.HttpStatusCode.OK);
            await response.WriteStringAsync(" Processed data saved to data/processed.json");
            return response;
        }
    }

    public class WeatherRecord
    {
        public string? location { get; set; }
        public string? date_ { get; set; }
        public string? temp_max { get; set; }
        public string? temp_min { get; set; }
        public string? weather { get; set; }

        public string? wind_speed { get; set; }
        public string? id { get; set; }
    }
}





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






44444444


using System;
using System.IO;
using System.Collections.Generic;
using System.Text.Json;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;

namespace FunctionApp
{
    public class WeatherFunction
    {
        private readonly string dataFolder = Path.Combine(Environment.CurrentDirectory, "Data");
        private readonly string rawFilePath;
        private readonly string processedFilePath;

        public WeatherFunction()
        {
            rawFilePath = Path.Combine(dataFolder, "raw.json");
            processedFilePath = Path.Combine(dataFolder, "processed.json");
        }

        [FunctionName("WeatherDataProcessorHttp")]
        public async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "get", "post")] HttpRequest req,
            ILogger log)
        {
            log.LogInformation($"➡️ HTTP trigger executed at: {DateTime.Now}");

            // ✅ Check if raw.json exists
            if (!File.Exists(rawFilePath))
            {
                log.LogError("❌ raw.json not found.");
                return new NotFoundObjectResult("raw.json not found in Data folder.");
            }

            // ✅ Read raw.json
            string rawJson = await File.ReadAllTextAsync(rawFilePath);
            if (string.IsNullOrWhiteSpace(rawJson))
            {
                log.LogError("❌ raw.json is empty.");
                return new BadRequestObjectResult("raw.json is empty.");
            }

            // ✅ Deserialize JSON
            var options = new JsonSerializerOptions { PropertyNameCaseInsensitive = true };
            var weatherData = JsonSerializer.Deserialize<List<WeatherRecord>>(rawJson, options) ?? new List<WeatherRecord>();

            // ✅ Clean data
            foreach (var record in weatherData)
            {
                record.Location ??= "Unknown";
                record.Weather ??= "Not Available";
                record.Date = string.IsNullOrWhiteSpace(record.Date) ? DateTime.UtcNow.ToString("yyyy-MM-dd") : record.Date;
                record.TempMax ??= "0";
                record.TempMin ??= "0";
                record.Id ??= Guid.NewGuid().ToString(); // if missing, assign new id
            }

            // ✅ Serialize cleaned data
            string processedJson = JsonSerializer.Serialize(weatherData, new JsonSerializerOptions { WriteIndented = true });

            // ✅ Write into processed.json
            Directory.CreateDirectory(dataFolder); // ensure Data folder exists
            await File.WriteAllTextAsync(processedFilePath, processedJson);

            log.LogInformation("✅ Cleaned data written to processed.json");
            return new OkObjectResult("✅ Cleaned data successfully written to processed.json");
        }
    }

    // ✅ Model
    public class WeatherRecord
    {
        public string? Location { get; set; }
        public string? Date { get; set; }
        public string? TempMax { get; set; }
        public string? TempMin { get; set; }
        public string? Weather { get; set; }
        public string? Id { get; set; }
    




___________

using System.Text.Json;
using Azure.Storage.Blobs;
using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;

namespace WeatherFunctionApp
{
    public class WeatherDataProcessor
    {
        private readonly string connectionString = Environment.GetEnvironmentVariable("AzureWebJobsStorage");
        private readonly string containerName = "kaviya";
        private readonly string rawBlobPath = "weather/raw.json";
        private readonly string processedBlobPath = "weather/processed.json";

        [Function("WeatherDataProcessorHttp")]
        public async Task<HttpResponseData> Run(
            [HttpTrigger(AuthorizationLevel.Function, "get", "post")] HttpRequestData req,
            FunctionContext context)
        {
            var logger = context.GetLogger("WeatherDataProcessor");
            logger.LogInformation("➡️ .NET 8 isolated function triggered...");

            var blobServiceClient = new BlobServiceClient(connectionString);
            var containerClient = blobServiceClient.GetBlobContainerClient(containerName);

            // ✅ Get raw blob
            var rawBlobClient = containerClient.GetBlobClient(rawBlobPath);
            if (!await rawBlobClient.ExistsAsync())
            {
                var notFound = req.CreateResponse(System.Net.HttpStatusCode.NotFound);
                await notFound.WriteStringAsync("raw.json not found in blob storage.");
                return notFound;
            }

            // ✅ Read raw JSON
            string rawJson;
            using (var stream = await rawBlobClient.OpenReadAsync())
            using (var reader = new StreamReader(stream))
            {
                rawJson = await reader.ReadToEndAsync();
            }

            var options = new JsonSerializerOptions { PropertyNameCaseInsensitive = true };
            var weatherData = JsonSerializer.Deserialize<List<WeatherRecord>>(rawJson, options) ?? new();

            // ✅ Clean
            foreach (var record in weatherData)
            {
                record.Location ??= "Unknown";
                record.Weather ??= "Not Available";
                record.Date = string.IsNullOrWhiteSpace(record.Date)
                    ? DateTime.UtcNow.ToString("yyyy-MM-dd")
                    : record.Date;
            }

            // ✅ Save processed
            string processedJson = JsonSerializer.Serialize(weatherData, new JsonSerializerOptions { WriteIndented = true });
            var processedBlobClient = containerClient.GetBlobClient(processedBlobPath);

            using (var uploadStream = new MemoryStream(System.Text.Encoding.UTF8.GetBytes(processedJson)))
            {
                await processedBlobClient.UploadAsync(uploadStream, overwrite: true);
            }

            var response = req.CreateResponse(System.Net.HttpStatusCode.OK);
            await response.WriteStringAsync("✅ Cleaned data uploaded to weather/processed.json");
            return response;
        }
    }

    public class WeatherRecord
    {
        public string? Location { get; set; }
        public string? Date { get; set; }
        public string? TempMax { get; set; }
        public string? TempMin { get; set; }
        public string? Weather { get; set; }
        public string? Id { get; set; }
    }
}



1
2
3
4
5
6

using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;

namespace FunctionApp
{
    public class WeatherFunction
    {
        private readonly string rawFilePath = Path.Combine("data", "raw.json");
        private readonly string processedFilePath = Path.Combine("data", "processed.json");

        [FunctionName("WeatherDataProcessorHttp")]
        public async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "get", "post")] HttpRequest req,
            ILogger log)
        {
            log.LogInformation("➡️ HTTP trigger function started.");

            if (!File.Exists(rawFilePath))
            {
                log.LogError("❌ raw.json not found.");
                return new NotFoundObjectResult("raw.json not found in data folder.");
            }

            // ✅ Read raw.json
            string rawJson = await File.ReadAllTextAsync(rawFilePath);
            if (string.IsNullOrWhiteSpace(rawJson))
            {
                log.LogError("❌ raw.json is empty.");
                return new BadRequestObjectResult("raw.json is empty.");
            }

            // ✅ Deserialize into WeatherRecord list
            var options = new JsonSerializerOptions { PropertyNameCaseInsensitive = true };
            var weatherData = JsonSerializer.Deserialize<List<WeatherRecord>>(rawJson, options) ?? new List<WeatherRecord>();

            // ✅ Clean data
            foreach (var record in weatherData)
            {
                record.Location ??= "Unknown";
                record.Weather ??= "Not Available";
                record.Date = string.IsNullOrWhiteSpace(record.Date)
                    ? DateTime.UtcNow.ToString("yyyy-MM-dd")
                    : record.Date;
            }

            // ✅ Serialize cleaned data
            string processedJson = JsonSerializer.Serialize(weatherData, new JsonSerializerOptions { WriteIndented = true });

            // ✅ Write to processed.json
            Directory.CreateDirectory("data"); // ensure folder exists
            await File.WriteAllTextAsync(processedFilePath, processedJson);

            log.LogInformation("✅ Cleaned data saved to data/processed.json");

            return new OkObjectResult("✅ Cleaned data written to data/processed.json");
        }
    }

    // ✅ Model for weather data
    public class WeatherRecord
    {
        public string? Location { get; set; }
        public string? Date { get; set; }
        public string? TempMax { get; set; }
        public string? TempMin { get; set; }
        public string? Weather { get; set; }
        public string? Id { get; set; }
    }
}
