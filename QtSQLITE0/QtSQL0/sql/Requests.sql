-- CREATE TABLE SQL REQUESTS
CREATE TABLE output_signals (Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, name VARCHAR(32), memo VARCHAR(128));
CREATE TABLE imitator_biu_input_signals AS SELECT Id, name FROM input_signals;
CREATE TABLE A403_biu_input_signals AS SELECT Id, name, signal, PXI_A, PXI_RELAY FROM A402_biu_input_signals;
CREATE TABLE A404_biu_output_signals AS SELECT Id, name, signal, PXI_A, PXI_B FROM A403_biu_output_signals;

-- INSERT DATA TO TABLE
INSERT INTO output_signals (Id, name, memo) VALUES (NULL, "BottomSwitch01", "���� ������ 1");
INSERT INTO output_signals VALUES (NULL, "name", "memo", "socket");

-- UPDATE DATA IN TABLE
UPDATE output_signals SET  name = "StrongOut06", memo = "����� ���. 6" WHERE Id = 13;
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
SELECT * FROM person WHERE (age BETWEEN 10 AND 30) AND (gender LIKE "�%");
SELECT * FROM person WHERE (age BETWEEN 10 AND 30) OR (name LIKE "���%");
SELECT * FROM person WHERE age IN (77, 78, 25);
SELECT * FROM person WHERE age NOT IN (77, 78, 25);
SELECT * FROM person WHERE (age NOT BETWEEN 10 AND 30) AND (gender LIKE "�%");
SELECT * FROM person WHERE family LIKE '��������_'; -- ������� ������� �� 'C�������'
SELECT * FROM person WHERE name LIKE '______'; -- ��� �� ����� ����
SELECT * FROM person WHERE name LIKE '[��]%'; -- ������ �������� � SQLite �� ��������!!!

-- ������� �� ������� relationships, ��� ��������� �� "����" � ��� ��� ������� ������� 
SELECT * FROM relationships WHERE (relationships.relation != 1) AND (SELECT gender FROM person WHERE person.Id = relationships.object) LIKE "�%";
--SELECT * FROM person WHERE (Id = (SELECT object FROM relationships WHERE (relationships.relation != 1) AND (SELECT gender FROM person WHERE person.Id = relationships.object) LIKE "�%"))

-- DISTINCT CLAUSE
SELECT DISTINCT name FROM person WHERE name LIKE "�%";

-- ����������� ����
-- ������������
SELECT name || '  ' || family  AS ���  FROM person LIMIT 10;
SELECT name || ' ' || family || ' ' || age || ' ��� ���: ' || gender  AS record  FROM person LIMIT 10;
SELECT '���>' || name || ' ������>' || object || ' ����>' || date || ' ����������> ' || memo  AS record  FROM events LIMIT 10;
SELECT (name || ' ' || family) AS Person FROM person WHERE Id = (SELECT object FROM relationships WHERE Id = 1) ; 
SELECT person.name || ' ' ||  person.family AS Object, relations.name AS ' ��������'  FROM person, relations WHERE relations.Id = 1 OR person.Id = 1; 
SELECT DISTINCT (SELECT name || ' ' ||  family || ' ���' FROM person WHERE Id = (SELECT object FROM relationships WHERE Id = 1))  AS ' ', (SELECT name FROM relations WHERE Id = (SELECT relation FROM relationships WHERE Id = 1)) AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = (SELECT subject FROM relationships WHERE Id = 1)) AS ' '  FROM person, relations; 
SELECT '���>' || name || ' �������>' || family || ' ����� �������>' || (SELECT COUNT(*) FROM person AS ' ') AS Person  FROM person;

-- ������������ ������� ������� � ������� events
SELECT '���>' || (SELECT name FROM person WHERE Id = 1) || ' ������>' || object || ' ����>' || date || ' ����������> ' || memo  AS record  FROM events LIMIT 10;
SELECT '������>' || (SELECT name || ' ' || family FROM person WHERE Id = 1) || ' ����>' || date || ' �������>' || (SELECT name || ' ' || family FROM person WHERE Id = 21)  || ' ����������> ' || memo  AS record  FROM events LIMIT 10;
SELECT person.name || ' ' ||  person.family || ' ���' AS ' ', relations.name AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = 2) AS ' '  FROM person, relations WHERE relations.Id = 1 OR person.Id = 1; 
SELECT (SELECT name || ' ' ||  family || ' ���' FROM person WHERE Id = 1)  AS ' ', (SELECT name FROM relations WHERE Id = 2) AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = 3) AS ' '  FROM person, relations; 
SELECT (SELECT name || ' ' ||  family || ' ���' FROM person WHERE Id = (SELECT object FROM relationships WHERE Id = 1))  AS ' ', (SELECT name FROM relations WHERE Id = (SELECT relation FROM relationships WHERE Id = 1)) AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = (SELECT subject FROM relationships WHERE Id = 1)) AS ' '  FROM person, relations; 
CREATE TABLE patriarchs AS SELECT  person.Id, (person.name || ' ' || person.family || ' ') AS 'memo' FROM person WHERE (Id IN(SELECT Id FROM fathers)) AND (Id NOT IN (SELECT Id FROM sons));

-- ������ � ����� ������ QtSQL0

-- ������� ���� ������� �� ������� person
SELECT DISTINCT family FROM person ORDER BY family;
-- ������� ���� ������� �� ������� person
SELECT DISTINCT name FROM person ORDER BY name;

-- �������� ������� ������ ����
SELECT * FROM relationships WHERE (object = 1 AND relation = 1) OR (subject = 1 AND relation IN (9, 10));
-- �������� ������� ������ ����
SELECT * FROM relationships WHERE (object = 2 AND relation = 2) OR (subject = 2 AND relation IN (9, 10));
-- �������� ������� ������ ���
SELECT * FROM relationships WHERE (object = 1 AND relation = 9) OR (subject = 1 AND relation IN (1, 2));
-- �������� ������� ������ ������ - �������
SELECT * FROM relationships WHERE (object = 25 AND relation IN (13, 14)) OR (subject = 25 AND relation IN (13, 14));
-- �������� ������� ������ ��� - ����
SELECT * FROM relationships WHERE (object = 1 AND relation IN (11, 12)) OR (subject = 1 AND relation IN (11, 12));
-- �������� �� ���������� ���� (��������)
SELECT COUNT(*) AS num  FROM relationships WHERE (object = 9 AND relation = 9) OR (subject = 9 AND relation IN (1, 2));
-- ������� ���� �����
SELECT * FROM person WHERE (Id IN (SELECT object FROM relationships WHERE relation = 1));
-- �������� ������� �����
CREATE TABLE fathers AS SELECT  person.Id, (person.name || ' ' || person.family || ' ') AS 'memo' FROM person WHERE Id IN(SELECT object from relationships WHERE relation = 1);
-- �������� ������� �������
CREATE TABLE sons AS SELECT  person.Id, (person.name || ' ' || person.family || ' ') AS 'memo' FROM person WHERE Id IN(SELECT object from relationships WHERE relation = 9);
-- ������� ����������
SELECT * FROM person WHERE (Id NOT IN (SELECT object FROM relationships WHERE relation = 9)) AND (Id IN (SELECT object FROM relationships WHERE relation = 1));
-- ������� ������� �� ����������� ��������
SELECT * FROM events WHERE object IN (SELECT Id FROM person WHERE family = "�������" AND name = "�����");
SELECT Id, date, subject, (SELECT name FROM events_types WHERE Id = events.name) AS Name FROM events WHERE object IN (SELECT Id FROM person WHERE Id = 1);
-- ������� ���� ����� �������
SELECT subject FROM relationships WHERE object = 1 AND relation = 1;
-- ������� ���� ������� ��������� ����� (�������� ���������� ������)
SELECT * FROM relationships WHERE subject IN (9, 12, 19, 20, 30) AND relation = 9;