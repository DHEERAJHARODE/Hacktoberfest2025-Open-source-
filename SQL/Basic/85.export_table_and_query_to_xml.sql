-- การ export table/query ไปเป็น XML ด้วย query_to_xml()
-- database: saturn
-- table: province
-- topic: table/query results to XML

select * from province;

select table_to_xml('province', true, false, '');

select query_to_xml('select p_id, name from province', true, false, '');

-- need to put E (Escape) in front of select command text, ใส่ E เพื่อ Escape ใส่ \'S\ ของตัว single quote เพื่อผสมเงื่อนไขของตัวที่เป็น text string ข้างใน
select query_to_xml(E'select p_id, name from province where region=\'S\'', true, false, ''); -- จังหวัดที่อยู่ในภาคใต้อย่างเดียว S

select query_to_xml(E'select p_id, name, area_km2 from province where area_km2 > 15000', true, false, '');

-- each line ends with '\n', save เป็น file
copy (
    select query_to_xml(E'select p_id, name, area_km2 from province where area_km2 > 15000', true, false, '')
) to 'c:/temp/pv.xml';

-- whole results were enclosed with double quote
copy (
    select query_to_xml(E'select p_id, name, area_km2 from province where area_km2 > 15000', true, false, '')
) to 'c:/temp/pv2.xml' csv;