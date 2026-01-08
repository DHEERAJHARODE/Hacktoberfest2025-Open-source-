การใส่หมายเลขแถวด้วยฟังก์ชัน row_number()

select * from province_info;

-- window function 
select row_number() over (order by area_km2) row_num,
* from province_info;

select row_number() over (order by area_km2 desc) row_num,
* from province_info;

-- Split-Apply-Combine (Split ตาม partition เช่น ภาคกลางจะเป็น 1 window และ ภาคตะวันออกก็จะเป็นอีกหนึ่ง window  
-- และ ทำการ apply row_number() เพื่อใส่หมายเลขเแถว  สุดท้าย combine จะรวมเอาแต่ละ partition หรือแต่ละ window มารวมกันให้ได้ผลลัพท์) 
select row_number() over (partition by region order by area_km2 desc) row_num,
* from province_info;

select row_number() over (partition by substr(abbr, 1, 1) order by area_km2 desc) row_num, -- substr() เป็นการ partition ด้วยตัวอักษร
* from province_info;

select row_number() over (partition by region, substr(abbr, 1, 1) order by area_km2 desc) row_num, -- ภาคกลางที่ขึ้น้นด้วย ก, ภาคกลางที่ขึ้นต้นด้วย ช, ภาคกลางที่ขึ้นต้นด้วย น เป็นต้น
* from province_info;

select row_number() over (partition by region, substr(abbr, 1, 1) order by region, abbr desc) row_num,
* from province_info;