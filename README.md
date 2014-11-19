StringProc
==========

String processing for FSQL-server

CREATE TABLE armamento ID:8 Tipo:16 Especificacion:32 Precio:16
CREATE TABLE armamento ID:8 Tipo:16 Especificacion:32 Precio:16 USING RAID 0

INSERT INTO armamento ID:01 Tipo:Espada Especificacion:Larga Precio:600
INSERT INTO armamento ID:02 Tipo:Lanza Especificacion:Romana Precio:250
INSERT INTO armamento ID:03 Tipo:Martillo Especificacion:Normal Precio:10
INSERT INTO armamento ID:04 Tipo:Espada Especificacion:Vikinga Precio:350
INSERT INTO armamento ID:05 Tipo:Arco Especificacion:Compuesto Precio:700
INSERT INTO armamento ID:06 Tipo:Escudo Especificacion:Plancha1346 Precio: 600

SELECT * FROM armamento
SELECT Precio FROM armamento

UPDATE armamento SET Tipo TO Arco
UPDATE armamento SET Precio TO 5

DELETE FROM armamento Especifiación Normal
DELETE FROM armamento Especifiación Plancha1346

CREATE INDEX ON armamento ID
COMPRESS TABLE armamento
BACKUP TABLE armamento
RESTORE TABLE armamento

DROP USER Daniel
GRANT fullaccess ON armamento TO Josafat
REVOKE fullaccess ON armamento TO Luis
