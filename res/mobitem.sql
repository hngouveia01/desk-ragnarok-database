drop table if exists `drop1`;
drop table if exists `drop2`;
drop table if exists `drop3`;
drop table if exists `drop4`;
drop table if exists `drop5`;
drop table if exists `drop6`;
drop table if exists `drop7`;
drop table if exists `drop8`;
drop table if exists `drop9`;
drop table if exists `carddrop`;
drop table if exists `mob_drop`;

create temporary table drop1
SELECT m.id as monsterId, m.iName as monster, i.name_japanese as drop1, TRIM(ROUND(m.Drop1per/100, 2))+0 as rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop1id = i.id ORDER BY i.id;
    
create temporary table drop2
SELECT m.id as id2, i.name_japanese as drop2, TRIM(ROUND(m.Drop2per/100, 2))+0 as drop2rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop2id = i.id ORDER BY m.id;

create temporary table drop3
SELECT m.id as id3, i.name_japanese as drop3, TRIM(ROUND(m.Drop3per/100, 2))+0 as drop3rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop3id = i.id ORDER BY m.id;

create temporary table drop4
SELECT m.id as id4, i.name_japanese as drop4, TRIM(ROUND(m.Drop4per/100, 2))+0 as drop4rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop4id = i.id ORDER BY m.id;
    
create temporary table drop5
SELECT m.id as id5, i.name_japanese as drop5, TRIM(ROUND(m.Drop5per/100, 2))+0 as drop5rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop5id = i.id ORDER BY m.id;
    
    create temporary table drop6
SELECT m.id as id6, i.name_japanese as drop6, TRIM(ROUND(m.Drop6per/100, 2))+0 as drop6rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop6id = i.id ORDER BY m.id;
    
    create temporary table drop7
SELECT m.id as id7, i.name_japanese as drop7, TRIM(ROUND(m.Drop7per/100, 2))+0 as drop7rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop7id = i.id ORDER BY m.id;
    
    create temporary table drop8
SELECT m.id as id8, i.name_japanese as drop8, TRIM(ROUND(m.Drop8per/100, 2))+0 as drop8rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop8id = i.id ORDER BY m.id;
    
    create temporary table drop9
SELECT m.id as id9, i.name_japanese as drop9, TRIM(ROUND(m.Drop9per/100, 2))+0 as drop9rate
FROM mob_db m
  INNER JOIN item_db i
    ON m.Drop9id = i.id ORDER BY m.id;
    
create temporary table carddrop
SELECT m.id as idcard, i.name_japanese as card, TRIM(ROUND(m.DropCardid/100, 2))+0 as cardrate
FROM mob_db m
  INNER JOIN item_db i
    ON m.DropCardid = i.id ORDER BY m.id;

create table mob_drop
select *
FROM drop1 d1 
inner join drop2 d2 
  on d1.monsterId = d2.id2
inner join drop3 d3
  on d1.monsterId = d3.id3
inner join drop4 d4
  on d1.monsterId = d4.id4
inner join drop5 d5
  on d1.monsterId = d5.id5;

ALTER TABLE mob_drop 
DROP column id2,
DROP column id3,
DROP column id4,
DROP column id5;
  
select * from mob_drop;
  