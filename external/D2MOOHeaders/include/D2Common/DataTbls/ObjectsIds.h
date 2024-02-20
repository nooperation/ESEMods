#pragma once 

enum D2Objects
{
	OBJECT_CASKET5 = 1,
	OBJECT_CASKET6 = 3,
	OBJECT_URN1 = 4,
	OBJECT_LARGE_CHEST_RIGHT = 5,
	OBJECT_LARGE_CHEST_LEFT = 6,
	OBJECT_BARREL = 7,
	OBJECT_TOWERTOME = 8,
	OBJECT_URN2 = 9,
	OBJECT_EXPLODING_BARREL = 11,
	OBJECT_ROGUEFOUNTAIN = 12,
	OBJECT_DOORGATELEFT = 13,
	OBJECT_DOORGATERIGHT = 14,
	OBJECT_DOORWOODENLEFT = 15,
	OBJECT_DOORWOODENRIGHT = 16,
	OBJECT_STONEALPHA = 17,
	OBJECT_STONEBETA = 18,
	OBJECT_STONEGAMMA = 19,
	OBJECT_STONEDELTA = 20,
	OBJECT_STONELAMBDA = 21,
	OBJECT_STONETHETA = 22,
	OBJECT_DOORCOURTYARDLEFT = 23,
	OBJECT_DOORCOURTYARDRIGHT = 24,
	OBJECT_DOORCATHEDRALDOUBLE = 25,
	OBJECT_CAINGIBBET = 26,
	OBJECT_DOORMONASTERYDOUBLERIGHT = 27,
	OBJECT_INIFUSS_TREE = 30,
	OBJECT_ROGUEBONFIRE = 39,
	OBJECT_RIVER1 = 40,
	OBJECT_RIVER2 = 41,
	OBJECT_RIVER3 = 42,
	OBJECT_RIVER4 = 43,
	OBJECT_RIVER5 = 44,
	OBJECT_CRATE = 46,
	OBJECT_ANDARIELS_DOOR = 47,
	OBJECT_URN3 = 52,
	OBJECT_ROGUE_ON_STICK1 = 57,
	OBJECT_ROGUE_ON_STICK2 = 58,
	OBJECT_TOWN_PORTAL = 59,
	OBJECT_PERMANENT_TOWN_PORTAL = 60,
	OBJECT_INVISIBLE_OBJECT = 61,
	OBJECT_DOORCATHEDRALLEFT = 62,
	OBJECT_DOORCATHEDRALRIGHT = 63,
	OBJECT_DOORWOODENLEFT2 = 64,
	OBJECT_INVISIBLE_RIVER_SOUND1 = 65,
	OBJECT_INVISIBLE_RIVER_SOUND2 = 66,
	OBJECT_TRAP_DOOR = 74,
	OBJECT_CASKET3 = 79,
	OBJECT_OBELISK = 80,
	OBJECT_HEALINGWELL = 84,
	OBJECT_TOMB_CHEST_LEFT = 87,
	OBJECT_TOMB_CHEST_RIGHT = 88,
	OBJECT_MUMMY_COFFIN_LEFT = 89,
	OBJECT_DESERT_OBELISK = 90,
	OBJECT_TOMBDOORLEFT = 91,
	OBJECT_TOMBDOORRIGHT = 92,
	OBJECT_URN4 = 94,
	OBJECT_URN5 = 95,
	OBJECT_PORTAL_TO_DURIELS_LAIR = 100,
	OBJECT_FLIES = 103,
	OBJECT_ARMOR_STAND_RIGHT = 104,
	OBJECT_ARMOR_STAND_LEFT = 105,
	OBJECT_WEAPON_RACK_RIGHT = 106,
	OBJECT_WEAPON_RACK_LEFT = 107,
	OBJECT_MALUS = 108,
	OBJECT_WAYPOINT_PORTAL = 119,
	OBJECT_JERHYN_PLACEHOLDER1 = 121,
	OBJECT_JERHYN_PLACEHOLDER2 = 122,
	OBJECT_VILE_DOG_AFTERGLOW = 131,
	OBJECT_DESERT_SHRINE1 = 136,
	OBJECT_CHEST_RIGHT_LARGE_ACT1 = 139,
	OBJECT_CHEST_RIGHT_TALLSKINNY_ACT1 = 140,
	OBJECT_CHEST_RIGHT_MEDIUM_ACT1 = 141,
	OBJECT_LEFT_CHEST_ACT1 = 144,
	OBJECT_TAINTEDSUNALTAR = 149,
	OBJECT_ORIFICE = 152,
	OBJECT_TYRAELS_DOOR = 153,
	OBJECT_FIRE_SMALL = 160,
	OBJECT_FIRE_MEDIUM = 161,
	OBJECT_FIRE_LARGE = 162,
	OBJECT_CHEST_LEFT_MEDIUM = 176,
	OBJECT_CHEST_LEFT_LARGE = 177,
	OBJECT_JUNGLE_CHEST_ACT3 = 181,
	OBJECT_CHEST_LEFT_MEDIUM_JUNGLE = 183,
	OBJECT_CAINPORTAL = 189,
	OBJECT_TELEPORTATION_PAD = 192,
	OBJECT_LAM_ESENS_TOME = 193,
	OBJECT_FLOORTRAP = 196,
	OBJECT_CHEST_LEFT_TALLSKINNY = 198,
	OBJECT_BASKET1 = 208,
	OBJECT_BASKET2 = 209,
	OBJECT_SLIMEDOOR1 = 229,
	OBJECT_SLIMEDOOR2 = 230,
	OBJECT_ACT3WAYPOINT_TOWN = 237,
	OBJECT_GENERAL_CHEST_LEFT1 = 240,
	OBJECT_GENERAL_CHEST_RIGHT2 = 241,
	OBJECT_GENERAL_CHEST_RIGHT3 = 242,
	OBJECT_GENERAL_CHEST_LEFT3 = 243,
	OBJECT_EXPLODING_COW = 250,
	OBJECT_GIDBINN_ALTAR = 251,
	OBJECT_GIDBINN_DECOY = 252,
	OBJECT_TOMBFLOORTRAP = 261,
	OBJECT_STASH = 267,
	OBJECT_WIRTSBODY = 268,
	OBJECT_GOLD_PLACEHOLDER = 269,
	OBJECT_IRONGRATEDOORLEFT = 290,
	OBJECT_IRONGRATEDOORRIGHT = 291,
	OBJECT_WOODENGRATEDOORLEFT = 292,
	OBJECT_WOODENGRATEDOORRIGHT = 293,
	OBJECT_WOODENDOORLEFT = 294,
	OBJECT_WOODENDOORRIGHT = 295,
	OBJECT_ARCANE_SANCTUARY_PORTAL = 298,
	OBJECT_HAREM_GUARD_1 = 314,
	OBJECT_HAREM_GUARD_2 = 315,
	OBJECT_HAREM_GUARD_3 = 316,
	OBJECT_HAREM_GUARD_4 = 317,
	OBJECT_EUNUCH_HAREM_BLOCKER = 318,
	OBJECT_MEPHISTO_CHEST_LARGE_LEFT = 329,
	OBJECT_MEPHISTO_CHEST_LARGE_RIGHT = 330,
	OBJECT_MEPHISTO_CHEST_MEDIUM_LEFT = 331,
	OBJECT_MEPHISTO_CHEST_MEDIUM_RIGHT = 332,
	OBJECT_STEEG_STONE = 337,
	OBJECT_GUILD_VAULT = 338,
	OBJECT_TROPHY_CASE = 339,
	OBJECT_MESSAGE_BOARD = 340,
	OBJECT_MEPHISTOBRIDGE = 341,
	OBJECT_HELLGATE_PORTAL = 342,
	OBJECT_HORADRIC_CUBE_CHEST = 354,
	OBJECT_HORADRIC_SCROLL_CHEST = 355,
	OBJECT_STAFF_OF_KINGS_CHEST = 356,
	OBJECT_YET_ANOTHER_TOME = 357,
	OBJECT_SEWER_STAIRS = 366,
	OBJECT_ACT3SEWERLEVER = 367,
	OBJECT_DARKWANDERER_STARTPOSITION = 368,
	OBJECT_CHEST = 371,
	OBJECT_HELLFORGE = 376,
	OBJECT_GUILD_PORTAL = 377,
	OBJECT_HRATLI_START = 378,
	OBJECT_HRATLI_END = 379,
	OBJECT_NATALYA_START = 382,
	OBJECT_CAIN_START_POSITION = 385,
	OBJECT_ARCANE_SANCTUARY_BIG_CHEST_LEFT = 387,
	OBJECT_ARCANE_SANCTUARY_BIG_CHEST_RIGHT = 389,
	OBJECT_ARCANE_SANCTUARY_SMALL_CHEST_LEFT = 390,
	OBJECT_ARCANE_SANCTUARY_SMALL_CHEST_RIGHT = 391,
	OBJECT_DIABLO_SEAL1 = 392,
	OBJECT_DIABLO_SEAL2 = 393,
	OBJECT_DIABLO_SEAL3 = 394,
	OBJECT_DIABLO_SEAL4 = 395,
	OBJECT_DIABLO_SEAL5 = 396,
	OBJECT_COMPELLING_ORB = 404,
	OBJECT_KHALIM_CHEST1 = 405,
	OBJECT_KHALIM_CHEST2 = 406,
	OBJECT_KHALIM_CHEST3 = 407,
	OBJECT_SIEGE_CONTROL = 410,
	OBJECT_HARROGATH_TOWN_MAIN_GATE = 449,
	OBJECT_DREHYA_START_IN_TOWN = 459,
	OBJECT_DREHYA_START_OUTSIDE_TOWN = 460,
	OBJECT_NIHLATHAK_START_IN_TOWN = 461,
	OBJECT_NIHLATHAK_START_OUTSIDE_TOWN = 462,
	OBJECT_CAGEDWUSSIE1 = 473,
	OBJECT_ANCIENTSTATUE3 = 474,
	OBJECT_ANCIENTSTATUE1 = 475,
	OBJECT_ANCIENTSTATUE2 = 476,
	OBJECT_LARZUK_GREETING = 542,
	OBJECT_LARZUK_STANDARD = 543,
	OBJECT_ANCIENTSALTAR = 546,
	OBJECT_ANCIENTSDOOR = 547,
	OBJECT_BAALS_LAIR = 557,
	OBJECT_FROZEN_ANYA = 558,
	OBJECT_BBQ_BUNNY = 559,
	OBJECT_INVISIBLE_ANCIENT = 561,
	OBJECT_INVISIBLE_BASE = 562,
	OBJECT_BAALS_PORTAL_WORLDSTONECHAMBER = 563,
	OBJECT_SUMMIT_DOOR = 564,
	OBJECT_LAST_PORTAL = 565,
	OBJECT_HARROGATH_LAST_LAST_PORTAL = 566,
	OBJECT_ZOO = 567,
	OBJECT_KEEPER = 568,
	OBJECT_BAALS_PORTAL_THRONEOFDESTRUCTION = 569,
};

enum D2C_ObjModes
{
	OBJMODE_NEUTRAL,	// NU
	OBJMODE_OPERATING,	// OP
	OBJMODE_OPENED,		// ON
	OBJMODE_SPECIAL1,	// S1
	OBJMODE_SPECIAL2,	// S2
	OBJMODE_SPECIAL3,	// S3
	OBJMODE_SPECIAL4,	// S4
	OBJMODE_SPECIAL5	// S5
};

enum D2C_ShrineTypes
{
	SHRINE_NONE,
	SHRINE_REFILL,
	SHRINE_HPBOOST,
	SHRINE_MANABOOST,
	SHRINE_HPXCHANGE,
	SHRINE_MANAXCHANGE,
	SHRINE_ARMOR,
	SHRINE_COMBAT,
	SHRINE_RESFIRE,
	SHRINE_RESCOLD,
	SHRINE_RESLITE,
	SHRINE_RESPOIS,
	SHRINE_SKILL,
	SHRINE_MANAREGEN,
	SHRINE_STAM,
	SHRINE_EXP,
	SHRINE_ENIRHS,
	SHRINE_PORTAL,
	SHRINE_GEM,
	SHRINE_STORM,
	SHRINE_WARP,
	SHRINE_EXPLOSION,
	SHRINE_POISON
};