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
