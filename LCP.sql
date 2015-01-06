--SQLite Maestro 14.3.0.6
------------------------------------------
--Host     : localhost
--Database : LCP


CREATE TABLE BuildingInfo (
  Id                  blob NOT NULL,
  Shape               nvarchar(50),
  RoomPlacement       text,
  RoomCount           integer,
  FrontFloorCount     integer,
  BackFloorCount      integer,
  FrontBay            nvarchar(50),
  SideBay             nvarchar(50),
  BuildDate           date,
  ArchitecturalStyle  nvarchar(50),
  Doors               text,
  Windows             text,
  BasementVault       text,
  Roof                text,
  Ceiling             text,
  Pinion              text,
  /* Keys */
  PRIMARY KEY (Id)
);

CREATE TABLE BuildingNotes (
  BuildingInfoId  blob,
  Note            text,
  /* Foreign keys */
  CONSTRAINT FK_BuildinInfoNotes_BuildingInfo
    FOREIGN KEY (BuildingInfoId)
    REFERENCES BuildingInfo(Id)
);

CREATE TABLE Counties (
  Id      blob NOT NULL,
  NameId  blob NOT NULL,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_Counties_Names
    FOREIGN KEY (NameId)
    REFERENCES Names(Id)
);

CREATE TABLE Deaneries (
  Id      blob NOT NULL,
  NameId  blob NOT NULL,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_Deaneries_Names
    FOREIGN KEY (NameId)
    REFERENCES Names(Id)
);

CREATE TABLE HouseFunction (
  Id             blob NOT NULL,
  Original       nvarchar(50),
  Current        nvarchar(50),
  HouseStatusId  integer,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_HouseFunction_HouseStatus
    FOREIGN KEY (HouseStatusId)
    REFERENCES HouseStatus(Id)
);

CREATE TABLE HouseImages (
  HouseId  blob NOT NULL,
  ImageId  blob NOT NULL,
  /* Foreign keys */
  CONSTRAINT FK_HouseImages_Images
    FOREIGN KEY (ImageId)
    REFERENCES Images(Id), 
  CONSTRAINT FK_HouseImages_House
    FOREIGN KEY (HouseId)
    REFERENCES Houses(Id)
);

CREATE TABLE HousePositions (
  Id          blob NOT NULL,
  FromChurch  text,
  FromRoad    text,
  FromGarden  text,
  Declivity   text,
  /* Keys */
  PRIMARY KEY (Id)
);

CREATE TABLE HouseStatus (
  Id    integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  Name  nvarchar(50) NOT NULL
);

CREATE TABLE HouseTaxes (
  HouseId  blob,
  TaxId    blob,
  /* Foreign keys */
  CONSTRAINT FK_HouseTaxes_Taxes
    FOREIGN KEY (TaxId)
    REFERENCES Taxes(Id), 
  CONSTRAINT FK_HouseTaxes_Houses
    FOREIGN KEY (HouseId)
    REFERENCES Houses(Id)
);

CREATE TABLE HouseTenures (
  HouseId   blob,
  TenureId  blob,
  /* Foreign keys */
  CONSTRAINT FK_HouseTenures_Tenures
    FOREIGN KEY (TenureId)
    REFERENCES Tenures(Id), 
  CONSTRAINT FK_HouseTenures_Houses
    FOREIGN KEY (HouseId)
    REFERENCES Houses(Id)
);

CREATE TABLE Houses (
  Id               blob NOT NULL,
  Name             nvarchar(50),
  Description      text,
  Dating           text,
  LocationId       blob,
  HouseFunctionId  blob,
  HousePositionId  blob,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_Houses_HousePositions
    FOREIGN KEY (HousePositionId)
    REFERENCES HousePositions(Id), 
  CONSTRAINT FK_Houses_Locations
    FOREIGN KEY (LocationId)
    REFERENCES Locations(Id), 
  CONSTRAINT FK_Houses_HouseFunction
    FOREIGN KEY (HouseFunctionId)
    REFERENCES HouseFunction(Id)
);

CREATE TABLE Images (
  Id           blob NOT NULL,
  Path         nvarchar(255) NOT NULL,
  Name         nvarchar(50),
  Description  text,
  /* Keys */
  PRIMARY KEY (Id)
);

CREATE TABLE Languages (
  Id    blob NOT NULL,
  Name  nvarchar(50) NOT NULL,
  /* Keys */
  PRIMARY KEY (Id)
);

CREATE TABLE Localities (
  Id        blob NOT NULL,
  NameId    blob NOT NULL,
  CountyId  blob NOT NULL,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_Localities_Counties
    FOREIGN KEY (CountyId)
    REFERENCES Counties(Id), 
  CONSTRAINT FK_Localities_Names
    FOREIGN KEY (NameId)
    REFERENCES Names(Id)
);

CREATE TABLE Locations (
  Id             blob NOT NULL,
  NameId         blob,
  LocalityId     blob,
  ShireId        blob,
  DeaneryId      blob,
  InventoryDate  date,
  OldStatus      text,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_Locations_Deaneries
    FOREIGN KEY (DeaneryId)
    REFERENCES Deaneries(Id), 
  CONSTRAINT FK_Locations_Shires
    FOREIGN KEY (ShireId)
    REFERENCES Shires(Id), 
  CONSTRAINT FK_Locations_Locality
    FOREIGN KEY (LocalityId)
    REFERENCES Localities(Id), 
  CONSTRAINT FK_Locations_Names
    FOREIGN KEY (NameId)
    REFERENCES Names(Id)
);

CREATE TABLE Names (
  Id        blob NOT NULL,
  Language  blob NOT NULL,
  Name      nvarchar(50) NOT NULL,
  /* Keys */
  PRIMARY KEY (Id)
);

CREATE TABLE Priests (
  Id         blob NOT NULL,
  FirstName  nvarchar(50),
  LastName   nvarchar(50),
  /* Keys */
  PRIMARY KEY (Id)
);

CREATE INDEX Priests_Index01
  ON Priests
  (Id);

CREATE TABLE Shires (
  Id      blob NOT NULL,
  NameId  blob NOT NULL,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_Shires_Names
    FOREIGN KEY (NameId)
    REFERENCES Names(Id)
);

CREATE TABLE Taxes (
  Id           blob NOT NULL,
  Name         nvarchar(50) NOT NULL,
  Description  text,
  Formula      text NOT NULL,
  /* Keys */
  PRIMARY KEY (Id)
);

CREATE TABLE Tenures (
  Id        blob NOT NULL,
  PriestId  blob NOT NULL,
  Start     date,
  "End"     date,
  /* Keys */
  PRIMARY KEY (Id),
  /* Foreign keys */
  CONSTRAINT FK_Tenures_Priests
    FOREIGN KEY (PriestId)
    REFERENCES Priests(Id)
);

