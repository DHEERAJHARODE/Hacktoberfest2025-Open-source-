-- การใช้ STRING_AGG (String Aggregation) เพื่อรวมข้อมูลในคอลัมน์เข้าด้วยกัน

select * from province

-- ข้อมูลที่ออกมาจะเรียงต่อกันยาวๆๆ
select string_agg(name_en, ',')
    from province
    where region = 'S'

select region,string_agg(name_en, ',')
    from province
    group by region

select region,string_agg(name_en, ',' order by name_en)
    from province
    group by region
-- result
C	Ang Thong,Bangkok,Chachoengsao,Chainat,Chanthaburi,Chonburi,Kanchanaburi,Lopburi,Nakhon Nayok,Nakhon Pathom,Nonthaburi,Pathum Thani,Phetchaburi,Phra Nakhon Si Ayutthaya,Prachinburi,Prachuap Khiri Khan,Ratchaburi,Rayong,Sa Kaeo,Samut Prakan,Samut Sakhon,Samut Songkhram,Saraburi,Sing Buri,Suphan Buri,Trat
N	Chiang Mai,Chiang Rai,Kamphaeng Phet,Lampang,Lamphun,Mae Hong Son,Nakhon Sawan,Nan,Phayao,Phetchabun,Phichit,Phitsanulok,Phrae,Sukhothai,Tak,Uthai Thani,Uttaradit
NE	Amnat Charoen,Bueng Kan,Buriram,Chaiyaphum,Kalasin,Khon Kaen,Loei,Maha Sarakham,Mukdahan,Nakhon Phanom,Nakhon Ratchasima,Nong Bua Lamphu,Nong Khai,Roi Et,Sakon Nakhon,Sisaket,Surin,Ubon Ratchathani,Udon Thani,Yasothon
S	Chumphon,Krabi,Nakhon Si Thammarat,Narathiwat,Pattani,Phang Nga,Phattalung,Phuket,Ranong,Satun,Songkhla,Surat Thani,Trang,Yala
