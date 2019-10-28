-- CREATE TABLE SQL REQUESTS
CREATE TABLE output_signals (Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, name VARCHAR(32), memo VARCHAR(128));
CREATE TABLE imitator_biu_input_signals AS SELECT Id, name FROM input_signals;
CREATE TABLE A403_biu_input_signals AS SELECT Id, name, signal, PXI_A, PXI_RELAY FROM A402_biu_input_signals;
CREATE TABLE A404_biu_output_signals AS SELECT Id, name, signal, PXI_A, PXI_B FROM A403_biu_output_signals;

-- INSERT DATA TO TABLE
INSERT INTO output_signals (Id, name, memo) VALUES (NULL, "BottomSwitch01", "Ключ нижний 1");
INSERT INTO output_signals VALUES (NULL, "name", "memo", "socket");

-- UPDATE DATA IN TABLE
UPDATE output_signals SET  name = "StrongOut06", memo = "Выход сил. 6" WHERE Id = 13;
UPDATE A403_biu_output_signals SET signal = "", PXI_A = "", PXI_B = "" WHERE signal LIKE "2%";

-- ADD FIELD TO TABLE
ALTER TABLE output_signals ADD socket VARCHAR(16);

-- GET NUMBER OF RECORDS IN TABLE
SELECT COUNT(*) AS num  FROM operations_ks;

-- DROP TABLE
DROP TABLE test;

-- SELECT DATA
SELECT * FROM person WHERE age BETWEEN 10 AND 30;
SELECT * FROM person LIMIT 10;
SELECT * FROM person WHERE (age BETWEEN 10 AND 30) AND (gender LIKE "м%");
SELECT * FROM person WHERE (age BETWEEN 10 AND 30) OR (name LIKE "Ста%");
SELECT * FROM person WHERE age IN (77, 78, 25);
SELECT * FROM person WHERE age NOT IN (77, 78, 25);
SELECT * FROM person WHERE (age NOT BETWEEN 10 AND 30) AND (gender LIKE "м%");
SELECT * FROM person WHERE family LIKE 'Субботин_'; -- женские фамилии от 'Cубботин'
SELECT * FROM person WHERE name LIKE '______'; -- имя из шести букв
SELECT * FROM person WHERE name LIKE '[АЛ]%'; -- наборы символов в SQLite не работают!!!

-- Выборка из таблицы relationships, где отношение не "отец" и пол для объекта мужской 
SELECT * FROM relationships WHERE (relationships.relation != 1) AND (SELECT gender FROM person WHERE person.Id = relationships.object) LIKE "м%";
--SELECT * FROM person WHERE (Id = (SELECT object FROM relationships WHERE (relationships.relation != 1) AND (SELECT gender FROM person WHERE person.Id = relationships.object) LIKE "м%"))

-- DISTINCT CLAUSE
SELECT DISTINCT name FROM person WHERE name LIKE "А%";

-- Вычисляемые поля
-- Конкатенация
SELECT name || '  ' || family  AS имя  FROM person LIMIT 10;
SELECT name || ' ' || family || ' ' || age || ' лет пол: ' || gender  AS record  FROM person LIMIT 10;
SELECT 'имя>' || name || ' объект>' || object || ' дата>' || date || ' примечание> ' || memo  AS record  FROM events LIMIT 10;
SELECT (name || ' ' || family) AS Person FROM person WHERE Id = (SELECT object FROM relationships WHERE Id = 1) ; 
SELECT person.name || ' ' ||  person.family AS Object, relations.name AS ' является'  FROM person, relations WHERE relations.Id = 1 OR person.Id = 1; 
SELECT DISTINCT (SELECT name || ' ' ||  family || ' это' FROM person WHERE Id = (SELECT object FROM relationships WHERE Id = 1))  AS ' ', (SELECT name FROM relations WHERE Id = (SELECT relation FROM relationships WHERE Id = 1)) AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = (SELECT subject FROM relationships WHERE Id = 1)) AS ' '  FROM person, relations; 
SELECT 'Имя>' || name || ' Фамилия>' || family || ' Число записей>' || (SELECT COUNT(*) FROM person AS ' ') AS Person  FROM person;

-- Недоделанные рабочие запросы к таблице events
SELECT 'имя>' || (SELECT name FROM person WHERE Id = 1) || ' объект>' || object || ' дата>' || date || ' примечание> ' || memo  AS record  FROM events LIMIT 10;
SELECT 'объект>' || (SELECT name || ' ' || family FROM person WHERE Id = 1) || ' дата>' || date || ' субъект>' || (SELECT name || ' ' || family FROM person WHERE Id = 21)  || ' примечание> ' || memo  AS record  FROM events LIMIT 10;
SELECT person.name || ' ' ||  person.family || ' это' AS ' ', relations.name AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = 2) AS ' '  FROM person, relations WHERE relations.Id = 1 OR person.Id = 1; 
SELECT (SELECT name || ' ' ||  family || ' это' FROM person WHERE Id = 1)  AS ' ', (SELECT name FROM relations WHERE Id = 2) AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = 3) AS ' '  FROM person, relations; 
SELECT (SELECT name || ' ' ||  family || ' это' FROM person WHERE Id = (SELECT object FROM relationships WHERE Id = 1))  AS ' ', (SELECT name FROM relations WHERE Id = (SELECT relation FROM relationships WHERE Id = 1)) AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = (SELECT subject FROM relationships WHERE Id = 1)) AS ' '  FROM person, relations; 
CREATE TABLE patriarchs AS SELECT  person.Id, (person.name || ' ' || person.family || ' ') AS 'memo' FROM person WHERE (Id IN(SELECT Id FROM fathers)) AND (Id NOT IN (SELECT Id FROM sons));

-- РАБОТА С БАЗОЙ ДАННЫХ QtSQL0

-- Выборка всех фамилий из таблицы person
SELECT DISTINCT family FROM person ORDER BY family;
-- Выборка всех фамилий из таблицы person
SELECT DISTINCT name FROM person ORDER BY name;

-- Проверка полноты записи отец
SELECT * FROM relationships WHERE (object = 1 AND relation = 1) OR (subject = 1 AND relation IN (9, 10));
-- Проверка полноты записи мать
SELECT * FROM relationships WHERE (object = 2 AND relation = 2) OR (subject = 2 AND relation IN (9, 10));
-- Проверка полноты записи сын
SELECT * FROM relationships WHERE (object = 1 AND relation = 9) OR (subject = 1 AND relation IN (1, 2));
-- Проверка полноты записи супруг - супруга
SELECT * FROM relationships WHERE (object = 25 AND relation IN (13, 14)) OR (subject = 25 AND relation IN (13, 14));
-- Проверка полноты записи муж - жена
SELECT * FROM relationships WHERE (object = 1 AND relation IN (11, 12)) OR (subject = 1 AND relation IN (11, 12));
-- Проверка на основателя рода (патриарх)
SELECT COUNT(*) AS num  FROM relationships WHERE (object = 9 AND relation = 9) OR (subject = 9 AND relation IN (1, 2));
-- Выборка всех отцов
SELECT * FROM person WHERE (Id IN (SELECT object FROM relationships WHERE relation = 1));
-- Создание таблицы отцов
CREATE TABLE fathers AS SELECT  person.Id, (person.name || ' ' || person.family || ' ') AS 'memo' FROM person WHERE Id IN(SELECT object from relationships WHERE relation = 1);
-- Создание таблицы сыновей
CREATE TABLE sons AS SELECT  person.Id, (person.name || ' ' || person.family || ' ') AS 'memo' FROM person WHERE Id IN(SELECT object from relationships WHERE relation = 9);
-- Выборка патриархов
SELECT * FROM person WHERE (Id NOT IN (SELECT object FROM relationships WHERE relation = 9)) AND (Id IN (SELECT object FROM relationships WHERE relation = 1));
-- Выборка событий по конкретному человеку
SELECT * FROM events WHERE object IN (SELECT Id FROM person WHERE family = "Киселев" AND name = "Игорь");
SELECT Id, date, subject, (SELECT name FROM events_types WHERE Id = events.name) AS Name FROM events WHERE object IN (SELECT Id FROM person WHERE Id = 1);
-- Выборка всей детей объекта
SELECT subject FROM relationships WHERE object = 1 AND relation = 1;
-- Выборка всех сыновей коллекции отцов (элементы следующего уровня)
SELECT * FROM relationships WHERE subject IN (9, 12, 19, 20, 30) AND relation = 9;