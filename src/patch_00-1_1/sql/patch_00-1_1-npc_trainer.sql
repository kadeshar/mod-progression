UPDATE `npc_trainer` SET `MoneyCost` = 900000, `ReqLevel` = 40 WHERE `SpellID` = 33388;
UPDATE `npc_trainer` SET `MoneyCost` = 9000000, `ReqLevel` = 60 WHERE `SpellID` = 33391;
UPDATE `npc_trainer` SET `MoneyCost` = 8000000, `ReqLevel` = 70 WHERE `SpellID` = 34090;
UPDATE `npc_trainer` SET `ReqLevel` = 68 WHERE `SpellID` = 33950;
DELETE FROM `npc_trainer` WHERE `ID` = 200002 AND `SpellID` IN (25286, 25288, 25289);
DELETE FROM `npc_trainer` WHERE `ID` = 200004 AND `SpellID` IN (25290, 25291, 25292, 31789, 62124);
DELETE FROM `npc_trainer` WHERE `ID` = 200006 AND `SpellID` IN (21849, 21850, 25297, 25298, 25299, 31018, 31709, 33950);
DELETE FROM `npc_trainer` WHERE `ID` = 200008 AND `SpellID` IN (23028, 25304, 25306, 25345, 27090, 27127, 28609, 28612);
DELETE FROM `npc_trainer` WHERE `ID` = 200010 AND `SpellID` IN (1710, 23161, 25307, 25309, 25311, 28610);
DELETE FROM `npc_trainer` WHERE `ID` = 200012 AND `SpellID` IN (21562, 21564, 25314, 25315, 25316, 27683);
DELETE FROM `npc_trainer` WHERE `ID` = 200014 AND `SpellID` IN (25294, 25295, 25296);
DELETE FROM `npc_trainer` WHERE `ID` = 200016 AND `SpellID` IN (25300, 25302, 31016);
DELETE FROM `npc_trainer` WHERE `ID` = 200018 AND `SpellID` IN (25357, 25361, 29228, 36936, 51730, 51988, 51991, 51992, 51993, 51994, 66842, 66843, 66844);
DELETE FROM `npc_trainer` WHERE `ID` = 200020 AND `SpellID` IN (13820, 23214);
DELETE FROM `npc_trainer` WHERE `ID` = 200021 AND `SpellID` IN (34767, 34768, 53736);
DELETE FROM `npc_trainer` WHERE `ID` IN (201009, 201011) AND `SpellID` = 63746;
DELETE FROM `npc_trainer` WHERE `ID` = 201012 AND `SpellID` = 63750;
DELETE FROM `npc_trainer` WHERE `ID` = 201024 AND `SpellID` = 63743;
DELETE FROM `npc_trainer` WHERE `ID` = 201026 AND `SpellID` IN (64725, 64726, 64727, 64728);
DELETE FROM `npc_trainer` WHERE `ID` = 201039 AND `SpellID` = 63742;
DELETE FROM `npc_trainer` WHERE `ID` = 202001 AND `SpellID` IN (18249, 54083);
DELETE FROM `npc_trainer` WHERE `ID` = 202007 AND `SpellID` = 10847;
