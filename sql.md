CREATE VIEW Dim_Property AS
SELECT property_id,
       property_type,
       square_feet,
       year_built,
       facing,
       furnished_status,
       owner_type
FROM Property_View;


CREATE VIEW Dim_Location AS
SELECT property_id,
       city,
       locality,
       crime_rate_index,
       green_cover_percentage,
       nearby_hospitals,
       nerby_malls,
       nearby_schools
FROM Property_View;


CREATE VIEW Dim_Amenities AS
SELECT property_id,
       bathrooms,
       bedrooms,
       parking_spaces,
       loan_available
FROM Property_View;


CREATE VIEW Dim_Sale AS
SELECT property_id,
       sale_status,
       year_feet   -- looks like year of sale? (please confirm)
FROM Property_View;


CREATE OR REPLACE VIEW Fact_PropertyPricing AS
SELECT
    p.property_type,
    p.owner_type,
    p.property_size_category,
    l.city,
    l.locality,
    COUNT(pv.property_id) AS total_properties,
    ROUND(AVG(pv.price), 2) AS avg_price,
    ROUND(MIN(pv.price), 2) AS min_price,
    ROUND(MAX(pv.price), 2) AS max_price,
    ROUND(AVG(pv.price / NULLIF(pv.square_feet,0)), 2) AS avg_price_per_sqft

FROM Property_View pv
JOIN Dim_Property p ON pv.property_type = p.property_type
                   AND pv.owner_type = p.owner_type
                   AND (CASE 
                          WHEN pv.square_feet < 600 THEN 'Small'
                          WHEN pv.square_feet BETWEEN 600 AND 1200 THEN 'Medium'
                          ELSE 'Large'
                        END) = p.property_size_category
JOIN Dim_Location l ON pv.property_id = l.property_id

GROUP BY
    p.property_type,
    p.owner_type,
    p.property_size_category,
    l.city,
    l.locality

ORDER BY l.city, p.property_type;


CREATE OR REPLACE VIEW Fact_PropertyAgeSale AS
SELECT
    s.sale_status,
    s.sale_year,
    s.property_age AS property_age_group,
    COUNT(pv.property_id) AS total_properties_sold,
    ROUND(AVG(pv.price), 2) AS avg_price,
    ROUND(AVG(pv.price / NULLIF(pv.square_feet,0)), 2) AS avg_price_per_sqft,
    ROUND(MIN(pv.price), 2) AS min_price,
    ROUND(MAX(pv.price), 2) AS max_price

FROM Property_View pv
JOIN Dim_Sale s ON pv.property_id = s.property_id
JOIN Dim_Property p ON pv.property_type = p.property_type
                   AND pv.owner_type = p.owner_type

GROUP BY
    s.sale_status,
    s.sale_year,
    s.property_age

ORDER BY s.sale_year, s.property_age;



CREATE OR REPLACE VIEW Fact_PropertyFeatures AS
SELECT
    a.bedrooms,
    a.bathrooms,
    a.parking_spaces,
    a.loan_available,
    f.furnished_status,
    f.facing,
    COUNT(pv.property_id) AS total_properties,
    ROUND(AVG(pv.price), 2) AS avg_price,
    ROUND(AVG(pv.square_feet), 2) AS avg_square_feet,
    ROUND(AVG(pv.price / NULLIF(pv.square_feet,0)), 2) AS avg_price_per_sqft

FROM Property_View pv
JOIN Dim_Amenities a ON pv.bedrooms = a.bedrooms
                   AND pv.bathrooms = a.bathrooms
                   AND pv.parking_spaces = a.parking_spaces
                   AND pv.loan_available = a.loan_available
JOIN Dim_Furnishing f ON pv.furnished_status = f.furnished_status
                     AND pv.facing = f.facing

GROUP BY
    a.bedrooms,
    a.bathrooms,
    a.parking_spaces,
    a.loan_available,
    f.furnished_status,
    f.facing

ORDER BY a.bedrooms, a.bathrooms;

