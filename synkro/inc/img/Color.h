//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines RGB color.
//==============================================================================
#ifndef _SYNKRO_IMG_COLOR_
#define _SYNKRO_IMG_COLOR_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace img
{


/**
 * RGB color.
 */
class SYNKRO_API Color
{
public:
	/** Transparent color. */
	static const Color Transparent;

	/** Well-known color. <span class='color' style='background-color:#afbf1a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AcidGreen;

	/** Well-known color. <span class='color' style='background-color:#7cb8e8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Aero;

	/** Well-known color. <span class='color' style='background-color:#c8ffe4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AeroBlue;

	/** Well-known color. <span class='color' style='background-color:#b183bd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AfricanViolet;

	/** Well-known color. <span class='color' style='background-color:#5d8aa8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AirForceBlueRaf;

	/** Well-known color. <span class='color' style='background-color:#002f8e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AirForceBlueUsaf;

	/** Well-known color. <span class='color' style='background-color:#72a0c1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AirSuperiorityBlue;

	/** Well-known color. <span class='color' style='background-color:#af002a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AlabamaCrimson;

	/** Well-known color. <span class='color' style='background-color:#f0f7ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AliceBlue;

	/** Well-known color. <span class='color' style='background-color:#c4620f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AlloyOrange;

	/** Well-known color. <span class='color' style='background-color:#efddcd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Almond;

	/** Well-known color. <span class='color' style='background-color:#e42b50;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Amaranth;

	/** Well-known color. <span class='color' style='background-color:#f09cba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AmaranthPink;

	/** Well-known color. <span class='color' style='background-color:#aa264f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AmaranthPurple;

	/** Well-known color. <span class='color' style='background-color:#d3212d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AmaranthRed;

	/** Well-known color. <span class='color' style='background-color:#3b7957;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Amazon;

	/** Well-known color. <span class='color' style='background-color:#ffbf00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Amber;

	/** Well-known color. <span class='color' style='background-color:#ff7e00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AmberSaeEce;

	/** Well-known color. <span class='color' style='background-color:#ff033d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AmericanRose;

	/** Well-known color. <span class='color' style='background-color:#9966cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Amethyst;

	/** Well-known color. <span class='color' style='background-color:#a3c638;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AndroidGreen;

	/** Well-known color. <span class='color' style='background-color:#f2f2f4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AntiFlashWhite;

	/** Well-known color. <span class='color' style='background-color:#cd9575;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AntiqueBrass;

	/** Well-known color. <span class='color' style='background-color:#665d1d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AntiqueBronze;

	/** Well-known color. <span class='color' style='background-color:#915b83;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AntiqueFuchsia;

	/** Well-known color. <span class='color' style='background-color:#831a2d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AntiqueRuby;

	/** Well-known color. <span class='color' style='background-color:#f9ebd6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AntiqueWhite;

	/** Well-known color. <span class='color' style='background-color:#8cb600;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AppleGreen;

	/** Well-known color. <span class='color' style='background-color:#fbcdb1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Apricot;

	/** Well-known color. <span class='color' style='background-color:#7effd4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Aquamarine;

	/** Well-known color. <span class='color' style='background-color:#cfff13;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ArcticLime;

	/** Well-known color. <span class='color' style='background-color:#4b521f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ArmyGreen;

	/** Well-known color. <span class='color' style='background-color:#3b444b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Arsenic;

	/** Well-known color. <span class='color' style='background-color:#8e9779;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Artichoke;

	/** Well-known color. <span class='color' style='background-color:#e9d66b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ArylideYellow;

	/** Well-known color. <span class='color' style='background-color:#b1bdb5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AshGrey;

	/** Well-known color. <span class='color' style='background-color:#87a86b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Asparagus;

	/** Well-known color. <span class='color' style='background-color:#fded00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Aureolin;

	/** Well-known color. <span class='color' style='background-color:#6e7e80;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Aurometalsaurus;

	/** Well-known color. <span class='color' style='background-color:#d2691e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AutumnMaple;

	/** Well-known color. <span class='color' style='background-color:#568203;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Avocado;

	/** Well-known color. <span class='color' style='background-color:#f0ffff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Azure;

	/** Well-known color. <span class='color' style='background-color:#dbe9f4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color AzureishWhite;

	/** Well-known color. <span class='color' style='background-color:#89cff0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BabyBlue;

	/** Well-known color. <span class='color' style='background-color:#a1caf0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BabyBlueEyes;

	/** Well-known color. <span class='color' style='background-color:#f4c1c1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BabyPink;

	/** Well-known color. <span class='color' style='background-color:#fdfdf9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BabyPowder;

	/** Well-known color. <span class='color' style='background-color:#ff91af;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BakerMillerPink;

	/** Well-known color. <span class='color' style='background-color:#21aacd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BallBlue;

	/** Well-known color. <span class='color' style='background-color:#f9e6b5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BananaMania;

	/** Well-known color. <span class='color' style='background-color:#ffe134;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BananaYellow;

	/** Well-known color. <span class='color' style='background-color:#df218a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BarbiePink;

	/** Well-known color. <span class='color' style='background-color:#7c0a01;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BarnRed;

	/** Well-known color. <span class='color' style='background-color:#98777b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bazaar;

	/** Well-known color. <span class='color' style='background-color:#2d5793;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BedazzledBlue;

	/** Well-known color. <span class='color' style='background-color:#9e8070;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Beaver;

	/** Well-known color. <span class='color' style='background-color:#f4f4db;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Beige;

	/** Well-known color. <span class='color' style='background-color:#9c2442;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BigDipORuby;

	/** Well-known color. <span class='color' style='background-color:#ffe4c4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bisque;

	/** Well-known color. <span class='color' style='background-color:#3d2b1f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bistre;

	/** Well-known color. <span class='color' style='background-color:#957016;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BistreBrown;

	/** Well-known color. <span class='color' style='background-color:#cadf0c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BitterLemon;

	/** Well-known color. <span class='color' style='background-color:#bfff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BitterLime;

	/** Well-known color. <span class='color' style='background-color:#fd6e5e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bittersweet;

	/** Well-known color. <span class='color' style='background-color:#bf4f50;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BittersweetShimmer;

	/** Well-known color. <span class='color' style='background-color:#000000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Black;

	/** Well-known color. <span class='color' style='background-color:#3d0c01;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlackBean;

	/** Well-known color. <span class='color' style='background-color:#243428;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlackLeatherJacket;

	/** Well-known color. <span class='color' style='background-color:#3b3b36;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlackOlive;

	/** Well-known color. <span class='color' style='background-color:#ffebcd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlanchedAlmond;

	/** Well-known color. <span class='color' style='background-color:#a57064;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlastOffBronze;

	/** Well-known color. <span class='color' style='background-color:#318ce6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BleuDeFrance;

	/** Well-known color. <span class='color' style='background-color:#f9f0bd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Blond;

	/** Well-known color. <span class='color' style='background-color:#0000ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Blue;

	/** Well-known color. <span class='color' style='background-color:#a1a1cf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueBell;

	/** Well-known color. <span class='color' style='background-color:#4f85f7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Blueberry;

	/** Well-known color. <span class='color' style='background-color:#1c1cf0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bluebonnet;

	/** Well-known color. <span class='color' style='background-color:#1f75fd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueCrayola;

	/** Well-known color. <span class='color' style='background-color:#6699cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueGray;

	/** Well-known color. <span class='color' style='background-color:#0c98ba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueGreen;

	/** Well-known color. <span class='color' style='background-color:#ace4ed;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueLagoon;

	/** Well-known color. <span class='color' style='background-color:#543491;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueMagentaViolet;

	/** Well-known color. <span class='color' style='background-color:#0093af;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueMunsell;

	/** Well-known color. <span class='color' style='background-color:#0087bd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueNcs;

	/** Well-known color. <span class='color' style='background-color:#0018a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BluePantone;

	/** Well-known color. <span class='color' style='background-color:#333399;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BluePigment;

	/** Well-known color. <span class='color' style='background-color:#0146fd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueRyb;

	/** Well-known color. <span class='color' style='background-color:#116080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueSapphire;

	/** Well-known color. <span class='color' style='background-color:#8a2be2;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueViolet;

	/** Well-known color. <span class='color' style='background-color:#5072a7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BlueYonder;

	/** Well-known color. <span class='color' style='background-color:#dd5d83;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Blush;

	/** Well-known color. <span class='color' style='background-color:#0095b6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BondiBlue;

	/** Well-known color. <span class='color' style='background-color:#e2dac8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bone;

	/** Well-known color. <span class='color' style='background-color:#5e011f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bordeaux;

	/** Well-known color. <span class='color' style='background-color:#cc0000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BostonUniversityRed;

	/** Well-known color. <span class='color' style='background-color:#00694d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BottleGreen;

	/** Well-known color. <span class='color' style='background-color:#873160;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Boysenberry;

	/** Well-known color. <span class='color' style='background-color:#0070ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrandeisBlue;

	/** Well-known color. <span class='color' style='background-color:#b5a542;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Brass;

	/** Well-known color. <span class='color' style='background-color:#ca4154;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrickRed;

	/** Well-known color. <span class='color' style='background-color:#1dacd6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightCerulean;

	/** Well-known color. <span class='color' style='background-color:#66ff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightGreen;

	/** Well-known color. <span class='color' style='background-color:#bf93e4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightLavender;

	/** Well-known color. <span class='color' style='background-color:#d891ef;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightLilac;

	/** Well-known color. <span class='color' style='background-color:#c32148;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightMaroon;

	/** Well-known color. <span class='color' style='background-color:#1874d1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightNavyBlue;

	/** Well-known color. <span class='color' style='background-color:#08e8dd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightTurquoise;

	/** Well-known color. <span class='color' style='background-color:#d19ee8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrightUbe;

	/** Well-known color. <span class='color' style='background-color:#3399ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrilliantAzure;

	/** Well-known color. <span class='color' style='background-color:#ff54a3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrilliantRose;

	/** Well-known color. <span class='color' style='background-color:#fb607e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrinkPink;

	/** Well-known color. <span class='color' style='background-color:#004224;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BritishRacingGreen;

	/** Well-known color. <span class='color' style='background-color:#cd7e31;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bronze;

	/** Well-known color. <span class='color' style='background-color:#727000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BronzeYellow;

	/** Well-known color. <span class='color' style='background-color:#a52a2a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Brown;

	/** Well-known color. <span class='color' style='background-color:#615550;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrownGranite;

	/** Well-known color. <span class='color' style='background-color:#6b4423;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrownNose;

	/** Well-known color. <span class='color' style='background-color:#954b00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrownTraditional;

	/** Well-known color. <span class='color' style='background-color:#cc9966;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BrownYellow;

	/** Well-known color. <span class='color' style='background-color:#ffc1cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BubbleGum;

	/** Well-known color. <span class='color' style='background-color:#e6fdff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Bubbles;

	/** Well-known color. <span class='color' style='background-color:#7bb660;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BudGreen;

	/** Well-known color. <span class='color' style='background-color:#f0db82;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Buff;

	/** Well-known color. <span class='color' style='background-color:#480507;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BulgarianRose;

	/** Well-known color. <span class='color' style='background-color:#80001f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Burgundy;

	/** Well-known color. <span class='color' style='background-color:#ddb887;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BurlyWood;

	/** Well-known color. <span class='color' style='background-color:#cc5400;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BurntOrange;

	/** Well-known color. <span class='color' style='background-color:#8a3324;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color BurntUmber;

	/** Well-known color. <span class='color' style='background-color:#bd33a3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Byzantine;

	/** Well-known color. <span class='color' style='background-color:#702862;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Byzantium;

	/** Well-known color. <span class='color' style='background-color:#526772;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cadet;

	/** Well-known color. <span class='color' style='background-color:#5e9ea0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CadetBlue;

	/** Well-known color. <span class='color' style='background-color:#91a3af;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CadetGrey;

	/** Well-known color. <span class='color' style='background-color:#006b3b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CadmiumGreen;

	/** Well-known color. <span class='color' style='background-color:#ed872d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CadmiumOrange;

	/** Well-known color. <span class='color' style='background-color:#e20021;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CadmiumRed;

	/** Well-known color. <span class='color' style='background-color:#fff600;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CadmiumYellow;

	/** Well-known color. <span class='color' style='background-color:#4b3621;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CafeNoir;

	/** Well-known color. <span class='color' style='background-color:#1d4d2b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CalPolyGreen;

	/** Well-known color. <span class='color' style='background-color:#a3c1ac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CambridgeBlue;

	/** Well-known color. <span class='color' style='background-color:#c19a6b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Camel;

	/** Well-known color. <span class='color' style='background-color:#efbacc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CameoPink;

	/** Well-known color. <span class='color' style='background-color:#77856b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CamouflageGreen;

	/** Well-known color. <span class='color' style='background-color:#ffef00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CanaryYellow;

	/** Well-known color. <span class='color' style='background-color:#ff0800;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CandyAppleRed;

	/** Well-known color. <span class='color' style='background-color:#e47079;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CandyPink;

	/** Well-known color. <span class='color' style='background-color:#59261f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CaputMortuum;

	/** Well-known color. <span class='color' style='background-color:#c41d3a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cardinal;

	/** Well-known color. <span class='color' style='background-color:#00cc99;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CaribbeanGreen;

	/** Well-known color. <span class='color' style='background-color:#950018;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Carmine;

	/** Well-known color. <span class='color' style='background-color:#eb4b42;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CarminePink;

	/** Well-known color. <span class='color' style='background-color:#ff0038;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CarmineRed;

	/** Well-known color. <span class='color' style='background-color:#ffa5c8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CarnationPink;

	/** Well-known color. <span class='color' style='background-color:#56a0d3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CarolinaBlue;

	/** Well-known color. <span class='color' style='background-color:#ed9121;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CarrotOrange;

	/** Well-known color. <span class='color' style='background-color:#00563f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CastletonGreen;

	/** Well-known color. <span class='color' style='background-color:#052a77;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CatalinaBlue;

	/** Well-known color. <span class='color' style='background-color:#703642;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Catawba;

	/** Well-known color. <span class='color' style='background-color:#c85949;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CedarChest;

	/** Well-known color. <span class='color' style='background-color:#91a1cf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ceil;

	/** Well-known color. <span class='color' style='background-color:#ace1af;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Celadon;

	/** Well-known color. <span class='color' style='background-color:#2f837c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CeladonGreen;

	/** Well-known color. <span class='color' style='background-color:#b1ffff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Celeste;

	/** Well-known color. <span class='color' style='background-color:#4997cf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CelestialBlue;

	/** Well-known color. <span class='color' style='background-color:#eb3b83;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CerisePink;

	/** Well-known color. <span class='color' style='background-color:#007ba7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cerulean;

	/** Well-known color. <span class='color' style='background-color:#2a52bd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CeruleanBlue;

	/** Well-known color. <span class='color' style='background-color:#6d9ac3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CeruleanFrost;

	/** Well-known color. <span class='color' style='background-color:#0079a5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CgBlue;

	/** Well-known color. <span class='color' style='background-color:#df3b31;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CgRed;

	/** Well-known color. <span class='color' style='background-color:#a07759;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Chamoisee;

	/** Well-known color. <span class='color' style='background-color:#f7e6cd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Champagne;

	/** Well-known color. <span class='color' style='background-color:#36444f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Charcoal;

	/** Well-known color. <span class='color' style='background-color:#232b2b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CharlestonGreen;

	/** Well-known color. <span class='color' style='background-color:#e68eac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CharmPink;

	/** Well-known color. <span class='color' style='background-color:#7eff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Chartreuse;

	/** Well-known color. <span class='color' style='background-color:#dfff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChartreuseTraditional;

	/** Well-known color. <span class='color' style='background-color:#dd3162;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cherry;

	/** Well-known color. <span class='color' style='background-color:#ffb6c4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CherryBlossomPink;

	/** Well-known color. <span class='color' style='background-color:#954434;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Chestnut;

	/** Well-known color. <span class='color' style='background-color:#944743;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChiliOil;

	/** Well-known color. <span class='color' style='background-color:#dd6ea1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChinaPink;

	/** Well-known color. <span class='color' style='background-color:#a8506e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChinaRose;

	/** Well-known color. <span class='color' style='background-color:#aa381d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChineseRed;

	/** Well-known color. <span class='color' style='background-color:#856087;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChineseViolet;

	/** Well-known color. <span class='color' style='background-color:#d1691d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Chocolate;

	/** Well-known color. <span class='color' style='background-color:#7b3f00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChocolateTraditional;

	/** Well-known color. <span class='color' style='background-color:#ffa700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ChromeYellow;

	/** Well-known color. <span class='color' style='background-color:#98807b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cinereous;

	/** Well-known color. <span class='color' style='background-color:#e24234;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cinnabar;

	/** Well-known color. <span class='color' style='background-color:#9c4722;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CinnamonStick;

	/** Well-known color. <span class='color' style='background-color:#e4cf0a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Citrine;

	/** Well-known color. <span class='color' style='background-color:#9ea81f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Citron;

	/** Well-known color. <span class='color' style='background-color:#7e1634;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Claret;

	/** Well-known color. <span class='color' style='background-color:#34568b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ClassicBlue;

	/** Well-known color. <span class='color' style='background-color:#fbcce6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ClassicRose;

	/** Well-known color. <span class='color' style='background-color:#0046aa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CobaltBlue;

	/** Well-known color. <span class='color' style='background-color:#95593d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Coconut;

	/** Well-known color. <span class='color' style='background-color:#6e4d36;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Coffee;

	/** Well-known color. <span class='color' style='background-color:#c4d8e2;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ColumbiaBlue;

	/** Well-known color. <span class='color' style='background-color:#002d62;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CoolBlack;

	/** Well-known color. <span class='color' style='background-color:#b87233;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Copper;

	/** Well-known color. <span class='color' style='background-color:#ac6e69;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CopperPenny;

	/** Well-known color. <span class='color' style='background-color:#ca6d50;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CopperRed;

	/** Well-known color. <span class='color' style='background-color:#996666;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CopperRose;

	/** Well-known color. <span class='color' style='background-color:#ff3800;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Coquelicot;

	/** Well-known color. <span class='color' style='background-color:#ff7e50;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Coral;

	/** Well-known color. <span class='color' style='background-color:#f78379;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CoralPink;

	/** Well-known color. <span class='color' style='background-color:#ff3f3f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CoralRed;

	/** Well-known color. <span class='color' style='background-color:#893f44;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cordovan;

	/** Well-known color. <span class='color' style='background-color:#fbeb5d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Corn;

	/** Well-known color. <span class='color' style='background-color:#b31a1a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CornellRed;

	/** Well-known color. <span class='color' style='background-color:#6495ed;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CornflowerBlue;

	/** Well-known color. <span class='color' style='background-color:#fff7db;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cornsilk;

	/** Well-known color. <span class='color' style='background-color:#fff7e6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CosmicLatte;

	/** Well-known color. <span class='color' style='background-color:#ffbcd8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CottonCandy;

	/** Well-known color. <span class='color' style='background-color:#80603b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CoyoteBrown;

	/** Well-known color. <span class='color' style='background-color:#fffdcf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cream;

	/** Well-known color. <span class='color' style='background-color:#db133b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Crimson;

	/** Well-known color. <span class='color' style='background-color:#bd0031;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CrimsonGlory;

	/** Well-known color. <span class='color' style='background-color:#990000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CrimsonRed;

	/** Well-known color. <span class='color' style='background-color:#00ffff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Cyan;

	/** Well-known color. <span class='color' style='background-color:#4d82b3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CyanAzure;

	/** Well-known color. <span class='color' style='background-color:#4682bf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CyanBlueAzure;

	/** Well-known color. <span class='color' style='background-color:#28579c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CyanCobaltBlue;

	/** Well-known color. <span class='color' style='background-color:#188ac1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CyanCornflowerBlue;

	/** Well-known color. <span class='color' style='background-color:#00b6eb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CyanProcess;

	/** Well-known color. <span class='color' style='background-color:#57427c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CyberGrape;

	/** Well-known color. <span class='color' style='background-color:#ffd300;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color CyberYellow;

	/** Well-known color. <span class='color' style='background-color:#ffff31;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Daffodil;

	/** Well-known color. <span class='color' style='background-color:#f0e12f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Dandelion;

	/** Well-known color. <span class='color' style='background-color:#00008a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkBlue;

	/** Well-known color. <span class='color' style='background-color:#666699;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkBlueGray;

	/** Well-known color. <span class='color' style='background-color:#644221;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkBrown;

	/** Well-known color. <span class='color' style='background-color:#87644d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkBrownTangelo;

	/** Well-known color. <span class='color' style='background-color:#5d3854;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkByzantium;

	/** Well-known color. <span class='color' style='background-color:#a30000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkCandyAppleRed;

	/** Well-known color. <span class='color' style='background-color:#08447e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkCerulean;

	/** Well-known color. <span class='color' style='background-color:#986960;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkChestnut;

	/** Well-known color. <span class='color' style='background-color:#cd5b44;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkCoral;

	/** Well-known color. <span class='color' style='background-color:#008a8a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkCyan;

	/** Well-known color. <span class='color' style='background-color:#526777;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkElectricBlue;

	/** Well-known color. <span class='color' style='background-color:#b8850a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkGoldenrod;

	/** Well-known color. <span class='color' style='background-color:#a8a8a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkGray;

	/** Well-known color. <span class='color' style='background-color:#006400;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkGreen;

	/** Well-known color. <span class='color' style='background-color:#1f262a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkGunmetal;

	/** Well-known color. <span class='color' style='background-color:#00137e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkImperialBlue;

	/** Well-known color. <span class='color' style='background-color:#1a2421;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkJungleGreen;

	/** Well-known color. <span class='color' style='background-color:#bdb66b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkKhaki;

	/** Well-known color. <span class='color' style='background-color:#483b31;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkLava;

	/** Well-known color. <span class='color' style='background-color:#724f95;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkLavender;

	/** Well-known color. <span class='color' style='background-color:#524b4f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkLiver;

	/** Well-known color. <span class='color' style='background-color:#543d36;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkLiverHorses;

	/** Well-known color. <span class='color' style='background-color:#8a008a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkMagenta;

	/** Well-known color. <span class='color' style='background-color:#003366;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkMidnightBlue;

	/** Well-known color. <span class='color' style='background-color:#495d23;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkMossGreen;

	/** Well-known color. <span class='color' style='background-color:#546b2f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkOliveGreen;

	/** Well-known color. <span class='color' style='background-color:#ff8c00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkOrange;

	/** Well-known color. <span class='color' style='background-color:#9931cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkOrchid;

	/** Well-known color. <span class='color' style='background-color:#779eca;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPastelBlue;

	/** Well-known color. <span class='color' style='background-color:#03bf3b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPastelGreen;

	/** Well-known color. <span class='color' style='background-color:#956ed6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPastelPurple;

	/** Well-known color. <span class='color' style='background-color:#c13b21;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPastelRed;

	/** Well-known color. <span class='color' style='background-color:#e65480;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPink;

	/** Well-known color. <span class='color' style='background-color:#003399;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPowderBlue;

	/** Well-known color. <span class='color' style='background-color:#4f3a3b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPuce;

	/** Well-known color. <span class='color' style='background-color:#2f1834;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkPurple;

	/** Well-known color. <span class='color' style='background-color:#872657;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkRaspberry;

	/** Well-known color. <span class='color' style='background-color:#8a0000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkRed;

	/** Well-known color. <span class='color' style='background-color:#e99579;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkSalmon;

	/** Well-known color. <span class='color' style='background-color:#560318;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkScarlet;

	/** Well-known color. <span class='color' style='background-color:#8ebc8e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkSeaGreen;

	/** Well-known color. <span class='color' style='background-color:#3b1313;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkSienna;

	/** Well-known color. <span class='color' style='background-color:#8cbdd6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkSkyBlue;

	/** Well-known color. <span class='color' style='background-color:#483d8a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkSlateBlue;

	/** Well-known color. <span class='color' style='background-color:#2f4f4f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkSlateGray;

	/** Well-known color. <span class='color' style='background-color:#167244;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkSpringGreen;

	/** Well-known color. <span class='color' style='background-color:#918050;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkTan;

	/** Well-known color. <span class='color' style='background-color:#ffa811;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkTangerine;

	/** Well-known color. <span class='color' style='background-color:#cc4d5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkTerraCotta;

	/** Well-known color. <span class='color' style='background-color:#00cdd1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkTurquoise;

	/** Well-known color. <span class='color' style='background-color:#d1bda8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkVanilla;

	/** Well-known color. <span class='color' style='background-color:#9300d3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkViolet;

	/** Well-known color. <span class='color' style='background-color:#9a870c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DarkYellow;

	/** Well-known color. <span class='color' style='background-color:#00703b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DartmouthGreen;

	/** Well-known color. <span class='color' style='background-color:#545454;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DavysGrey;

	/** Well-known color. <span class='color' style='background-color:#d60a52;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DebianRed;

	/** Well-known color. <span class='color' style='background-color:#3f826d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepAquamarine;

	/** Well-known color. <span class='color' style='background-color:#a81f3d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepCarmine;

	/** Well-known color. <span class='color' style='background-color:#ef2f38;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepCarminePink;

	/** Well-known color. <span class='color' style='background-color:#e9692b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepCarrotOrange;

	/** Well-known color. <span class='color' style='background-color:#da3187;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepCerise;

	/** Well-known color. <span class='color' style='background-color:#f9d6a5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepChampagne;

	/** Well-known color. <span class='color' style='background-color:#b84d48;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepChestnut;

	/** Well-known color. <span class='color' style='background-color:#704241;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepCoffee;

	/** Well-known color. <span class='color' style='background-color:#c154c1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepFuchsia;

	/** Well-known color. <span class='color' style='background-color:#056608;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepGreen;

	/** Well-known color. <span class='color' style='background-color:#0e7c60;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepGreenCyanTurquoise;

	/** Well-known color. <span class='color' style='background-color:#004b49;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepJungleGreen;

	/** Well-known color. <span class='color' style='background-color:#333366;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepKoamaru;

	/** Well-known color. <span class='color' style='background-color:#f4c61a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepLemon;

	/** Well-known color. <span class='color' style='background-color:#9954ba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepLilac;

	/** Well-known color. <span class='color' style='background-color:#cc00cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepMagenta;

	/** Well-known color. <span class='color' style='background-color:#820000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepMaroon;

	/** Well-known color. <span class='color' style='background-color:#345e3b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepMossGreen;

	/** Well-known color. <span class='color' style='background-color:#ff1393;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepPink;

	/** Well-known color. <span class='color' style='background-color:#a85b67;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepPuce;

	/** Well-known color. <span class='color' style='background-color:#850101;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepRed;

	/** Well-known color. <span class='color' style='background-color:#833f5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepRuby;

	/** Well-known color. <span class='color' style='background-color:#ff9933;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepSaffron;

	/** Well-known color. <span class='color' style='background-color:#00bfff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepSkyBlue;

	/** Well-known color. <span class='color' style='background-color:#49646b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepSpaceSparkle;

	/** Well-known color. <span class='color' style='background-color:#7e5e60;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepTaupe;

	/** Well-known color. <span class='color' style='background-color:#66424d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepTuscanRed;

	/** Well-known color. <span class='color' style='background-color:#330066;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DeepViolet;

	/** Well-known color. <span class='color' style='background-color:#ba8759;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Deer;

	/** Well-known color. <span class='color' style='background-color:#1560bd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Denim;

	/** Well-known color. <span class='color' style='background-color:#669999;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DesaturatedCyan;

	/** Well-known color. <span class='color' style='background-color:#edc8af;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DesertSand;

	/** Well-known color. <span class='color' style='background-color:#e93b52;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Desire;

	/** Well-known color. <span class='color' style='background-color:#b8f2ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Diamond;

	/** Well-known color. <span class='color' style='background-color:#696969;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DimGray;

	/** Well-known color. <span class='color' style='background-color:#2d32aa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DirectXDemo;

	/** Well-known color. <span class='color' style='background-color:#9a7552;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Dirt;

	/** Well-known color. <span class='color' style='background-color:#1d90ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DodgerBlue;

	/** Well-known color. <span class='color' style='background-color:#d61867;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DogwoodRose;

	/** Well-known color. <span class='color' style='background-color:#85ba64;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DollarBill;

	/** Well-known color. <span class='color' style='background-color:#664b28;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DonkeyBrown;

	/** Well-known color. <span class='color' style='background-color:#00009c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DukeBlue;

	/** Well-known color. <span class='color' style='background-color:#e4ccc8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DustStorm;

	/** Well-known color. <span class='color' style='background-color:#efdfba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color DutchWhite;

	/** Well-known color. <span class='color' style='background-color:#e1a85e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EarthYellow;

	/** Well-known color. <span class='color' style='background-color:#545d50;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ebony;

	/** Well-known color. <span class='color' style='background-color:#343148;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Eclipse;

	/** Well-known color. <span class='color' style='background-color:#1a1a1a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EerieBlack;

	/** Well-known color. <span class='color' style='background-color:#603f50;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Eggplant;

	/** Well-known color. <span class='color' style='background-color:#f0e9d6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Eggshell;

	/** Well-known color. <span class='color' style='background-color:#0f34a5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EgyptianBlue;

	/** Well-known color. <span class='color' style='background-color:#7cf9ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricBlue;

	/** Well-known color. <span class='color' style='background-color:#ff003f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricCrimson;

	/** Well-known color. <span class='color' style='background-color:#6e00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricIndigo;

	/** Well-known color. <span class='color' style='background-color:#f4baff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricLavender;

	/** Well-known color. <span class='color' style='background-color:#ccff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricLime;

	/** Well-known color. <span class='color' style='background-color:#bf00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricPurple;

	/** Well-known color. <span class='color' style='background-color:#3f00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricUltramarine;

	/** Well-known color. <span class='color' style='background-color:#8e00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricViolet;

	/** Well-known color. <span class='color' style='background-color:#ffff33;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ElectricYellow;

	/** Well-known color. <span class='color' style='background-color:#50c877;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Emerald;

	/** Well-known color. <span class='color' style='background-color:#6b2f82;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Eminence;

	/** Well-known color. <span class='color' style='background-color:#1a4d3d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EnglishGreen;

	/** Well-known color. <span class='color' style='background-color:#b38395;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EnglishLavender;

	/** Well-known color. <span class='color' style='background-color:#aa4b52;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EnglishRed;

	/** Well-known color. <span class='color' style='background-color:#563b5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EnglishViolet;

	/** Well-known color. <span class='color' style='background-color:#95c8a1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color EtonBlue;

	/** Well-known color. <span class='color' style='background-color:#44d6a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Eucalyptus;

	/** Well-known color. <span class='color' style='background-color:#798ea4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FadedDenim;

	/** Well-known color. <span class='color' style='background-color:#801818;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FaluRed;

	/** Well-known color. <span class='color' style='background-color:#b53389;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Fandango;

	/** Well-known color. <span class='color' style='background-color:#dd5285;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FandangoPink;

	/** Well-known color. <span class='color' style='background-color:#f400a1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FashionFuchsia;

	/** Well-known color. <span class='color' style='background-color:#e4aa70;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Fawn;

	/** Well-known color. <span class='color' style='background-color:#4d5d52;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Feldgrau;

	/** Well-known color. <span class='color' style='background-color:#4f7942;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FernGreen;

	/** Well-known color. <span class='color' style='background-color:#ff2800;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FerrariRed;

	/** Well-known color. <span class='color' style='background-color:#6b541d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FieldDrab;

	/** Well-known color. <span class='color' style='background-color:#dd4132;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Fiesta;

	/** Well-known color. <span class='color' style='background-color:#b12121;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FireBrick;

	/** Well-known color. <span class='color' style='background-color:#cd1f28;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FireEngineRed;

	/** Well-known color. <span class='color' style='background-color:#e25721;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Flame;

	/** Well-known color. <span class='color' style='background-color:#fb8eac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FlamingoPink;

	/** Well-known color. <span class='color' style='background-color:#f7e98e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Flavescent;

	/** Well-known color. <span class='color' style='background-color:#eddb82;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Flax;

	/** Well-known color. <span class='color' style='background-color:#a1006d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Flirt;

	/** Well-known color. <span class='color' style='background-color:#fff9f0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FloralWhite;

	/** Well-known color. <span class='color' style='background-color:#ff004f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Folly;

	/** Well-known color. <span class='color' style='background-color:#218a21;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ForestGreen;

	/** Well-known color. <span class='color' style='background-color:#014421;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ForestGreenTraditional;

	/** Well-known color. <span class='color' style='background-color:#a57b5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchBeige;

	/** Well-known color. <span class='color' style='background-color:#856d4d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchBistre;

	/** Well-known color. <span class='color' style='background-color:#0072ba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchBlue;

	/** Well-known color. <span class='color' style='background-color:#fd3f91;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchFuchsia;

	/** Well-known color. <span class='color' style='background-color:#85608e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchLilac;

	/** Well-known color. <span class='color' style='background-color:#9efd38;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchLime;

	/** Well-known color. <span class='color' style='background-color:#d472d4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchMauve;

	/** Well-known color. <span class='color' style='background-color:#fd6b9e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchPink;

	/** Well-known color. <span class='color' style='background-color:#801352;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchPlum;

	/** Well-known color. <span class='color' style='background-color:#4d1608;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchPuce;

	/** Well-known color. <span class='color' style='background-color:#c62b48;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchRaspberry;

	/** Well-known color. <span class='color' style='background-color:#f6498a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchRose;

	/** Well-known color. <span class='color' style='background-color:#77b5fd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchSkyBlue;

	/** Well-known color. <span class='color' style='background-color:#8705cd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchViolet;

	/** Well-known color. <span class='color' style='background-color:#ac1d44;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FrenchWine;

	/** Well-known color. <span class='color' style='background-color:#a5e6ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FreshAir;

	/** Well-known color. <span class='color' style='background-color:#ff77ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FuchsiaPink;

	/** Well-known color. <span class='color' style='background-color:#cc387b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FuchsiaPurple;

	/** Well-known color. <span class='color' style='background-color:#c64275;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FuchsiaRose;

	/** Well-known color. <span class='color' style='background-color:#e48300;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Fulvous;

	/** Well-known color. <span class='color' style='background-color:#cc6666;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color FuzzyWuzzy;

	/** Well-known color. <span class='color' style='background-color:#dbdbdb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Gainsboro;

	/** Well-known color. <span class='color' style='background-color:#e49a0f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Gamboge;

	/** Well-known color. <span class='color' style='background-color:#986600;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GambogeOrangeBrown;

	/** Well-known color. <span class='color' style='background-color:#007e66;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GenericViridian;

	/** Well-known color. <span class='color' style='background-color:#f7f7ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GhostWhite;

	/** Well-known color. <span class='color' style='background-color:#fd591d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GiantsOrange;

	/** Well-known color. <span class='color' style='background-color:#6082b6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Glaucous;

	/** Well-known color. <span class='color' style='background-color:#e6e8f9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Glitter;

	/** Well-known color. <span class='color' style='background-color:#00aa66;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GoGreen;

	/** Well-known color. <span class='color' style='background-color:#ffd600;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Gold;

	/** Well-known color. <span class='color' style='background-color:#996415;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GoldenBrown;

	/** Well-known color. <span class='color' style='background-color:#fbc100;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GoldenPoppy;

	/** Well-known color. <span class='color' style='background-color:#daa51f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Goldenrod;

	/** Well-known color. <span class='color' style='background-color:#ffdf00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GoldenYellow;

	/** Well-known color. <span class='color' style='background-color:#85754d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GoldFusion;

	/** Well-known color. <span class='color' style='background-color:#d4af36;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GoldMetallic;

	/** Well-known color. <span class='color' style='background-color:#a8e4a0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GrannySmithApple;

	/** Well-known color. <span class='color' style='background-color:#6e2da8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Grape;

	/** Well-known color. <span class='color' style='background-color:#808080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Gray;

	/** Well-known color. <span class='color' style='background-color:#465944;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GrayAsparagus;

	/** Well-known color. <span class='color' style='background-color:#8c91ac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GrayBlue;

	/** Well-known color. <span class='color' style='background-color:#bdbdbd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GrayX11Gray;

	/** Well-known color. <span class='color' style='background-color:#008000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Green;

	/** Well-known color. <span class='color' style='background-color:#1164b3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenBlue;

	/** Well-known color. <span class='color' style='background-color:#1cac77;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenCrayola;

	/** Well-known color. <span class='color' style='background-color:#009966;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenCyan;

	/** Well-known color. <span class='color' style='background-color:#00a877;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenMunsell;

	/** Well-known color. <span class='color' style='background-color:#009e6b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenNcs;

	/** Well-known color. <span class='color' style='background-color:#00ac42;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenPantone;

	/** Well-known color. <span class='color' style='background-color:#00a550;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenPigment;

	/** Well-known color. <span class='color' style='background-color:#66af31;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenRyb;

	/** Well-known color. <span class='color' style='background-color:#acff2f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color GreenYellow;

	/** Well-known color. <span class='color' style='background-color:#dc4c46;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Grenadine;

	/** Well-known color. <span class='color' style='background-color:#875718;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Grizzly;

	/** Well-known color. <span class='color' style='background-color:#a89a85;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Grullo;

	/** Well-known color. <span class='color' style='background-color:#af6400;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Grussrel;

	/** Well-known color. <span class='color' style='background-color:#2a3438;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Gunmetal;

	/** Well-known color. <span class='color' style='background-color:#663654;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HalayaUbe;

	/** Well-known color. <span class='color' style='background-color:#446bcf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HanBlue;

	/** Well-known color. <span class='color' style='background-color:#5218f9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HanPurple;

	/** Well-known color. <span class='color' style='background-color:#3fff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Harlequin;

	/** Well-known color. <span class='color' style='background-color:#46ca18;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HarlequinGreen;

	/** Well-known color. <span class='color' style='background-color:#c80016;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HarvardCrimson;

	/** Well-known color. <span class='color' style='background-color:#da9100;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HarvestGold;

	/** Well-known color. <span class='color' style='background-color:#cfb095;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Hazelnut;

	/** Well-known color. <span class='color' style='background-color:#df72ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Heliotrope;

	/** Well-known color. <span class='color' style='background-color:#aa98a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HeliotropeGray;

	/** Well-known color. <span class='color' style='background-color:#aa00ba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HeliotropeMagenta;

	/** Well-known color. <span class='color' style='background-color:#f0fff0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Honeydew;

	/** Well-known color. <span class='color' style='background-color:#006daf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HonoluluBlue;

	/** Well-known color. <span class='color' style='background-color:#49796b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HookersGreen;

	/** Well-known color. <span class='color' style='background-color:#ff1dcd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HotMagenta;

	/** Well-known color. <span class='color' style='background-color:#ff69b3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color HotPink;

	/** Well-known color. <span class='color' style='background-color:#70a5d1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Iceberg;

	/** Well-known color. <span class='color' style='background-color:#fbf75e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Icterine;

	/** Well-known color. <span class='color' style='background-color:#319177;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color IlluminatingEmerald;

	/** Well-known color. <span class='color' style='background-color:#602f6b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Imperial;

	/** Well-known color. <span class='color' style='background-color:#002395;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ImperialBlue;

	/** Well-known color. <span class='color' style='background-color:#66013b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ImperialPurple;

	/** Well-known color. <span class='color' style='background-color:#ed2838;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ImperialRed;

	/** Well-known color. <span class='color' style='background-color:#b1eb5d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Inchworm;

	/** Well-known color. <span class='color' style='background-color:#4b506d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Independence;

	/** Well-known color. <span class='color' style='background-color:#138708;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color IndiaGreen;

	/** Well-known color. <span class='color' style='background-color:#cd5b5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color IndianRed;

	/** Well-known color. <span class='color' style='background-color:#e2a857;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color IndianYellow;

	/** Well-known color. <span class='color' style='background-color:#4b0082;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Indigo;

	/** Well-known color. <span class='color' style='background-color:#081f91;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color IndigoDye;

	/** Well-known color. <span class='color' style='background-color:#594fcf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Iris;

	/** Well-known color. <span class='color' style='background-color:#f4f0eb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Isabelline;

	/** Well-known color. <span class='color' style='background-color:#009000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color IslamicGreen;

	/** Well-known color. <span class='color' style='background-color:#fffff0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ivory;

	/** Well-known color. <span class='color' style='background-color:#00a86b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Jade;

	/** Well-known color. <span class='color' style='background-color:#9c2833;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JapaneseCarmine;

	/** Well-known color. <span class='color' style='background-color:#264248;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JapaneseIndigo;

	/** Well-known color. <span class='color' style='background-color:#5b3156;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JapaneseViolet;

	/** Well-known color. <span class='color' style='background-color:#f7dd7e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Jasmine;

	/** Well-known color. <span class='color' style='background-color:#d63b3d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Jasper;

	/** Well-known color. <span class='color' style='background-color:#a50a5e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JazzberryJam;

	/** Well-known color. <span class='color' style='background-color:#da604d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JellyBean;

	/** Well-known color. <span class='color' style='background-color:#9e1030;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JesterRed;

	/** Well-known color. <span class='color' style='background-color:#343434;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Jet;

	/** Well-known color. <span class='color' style='background-color:#f4ca16;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Jonquil;

	/** Well-known color. <span class='color' style='background-color:#8ab8f0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JordyBlue;

	/** Well-known color. <span class='color' style='background-color:#bdda57;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JuneBud;

	/** Well-known color. <span class='color' style='background-color:#28aa87;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color JungleGreen;

	/** Well-known color. <span class='color' style='background-color:#4bba16;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color KellyGreen;

	/** Well-known color. <span class='color' style='background-color:#7c1c05;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color KenyanCopper;

	/** Well-known color. <span class='color' style='background-color:#3aaf9e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Keppel;

	/** Well-known color. <span class='color' style='background-color:#f0e68c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Khaki;

	/** Well-known color. <span class='color' style='background-color:#8e5b36;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color KiwiBrown;

	/** Well-known color. <span class='color' style='background-color:#8ee43f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color KiwiGreen;

	/** Well-known color. <span class='color' style='background-color:#002fa7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color KleinBlue;

	/** Well-known color. <span class='color' style='background-color:#e69ec4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Kobi;

	/** Well-known color. <span class='color' style='background-color:#34422f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color KombuGreen;

	/** Well-known color. <span class='color' style='background-color:#e8000c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color KuCrimson;

	/** Well-known color. <span class='color' style='background-color:#fda700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LamborghiniYellow;

	/** Well-known color. <span class='color' style='background-color:#d6cadd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LanguidLavender;

	/** Well-known color. <span class='color' style='background-color:#26609c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LapisLazuli;

	/** Well-known color. <span class='color' style='background-color:#08772f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LaSalleGreen;

	/** Well-known color. <span class='color' style='background-color:#ffff66;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LaserLemon;

	/** Well-known color. <span class='color' style='background-color:#a8ba9c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LaurelGreen;

	/** Well-known color. <span class='color' style='background-color:#cf0f1f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lava;

	/** Well-known color. <span class='color' style='background-color:#e6e6f9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lavender;

	/** Well-known color. <span class='color' style='background-color:#ccccff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LavenderBlue;

	/** Well-known color. <span class='color' style='background-color:#fff0f4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LavenderBlush;

	/** Well-known color. <span class='color' style='background-color:#b57edb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LavenderFloral;

	/** Well-known color. <span class='color' style='background-color:#c4c3cf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LavenderGray;

	/** Well-known color. <span class='color' style='background-color:#fbaed1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LavenderPink;

	/** Well-known color. <span class='color' style='background-color:#957bb6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LavenderPurple;

	/** Well-known color. <span class='color' style='background-color:#fba0e2;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LavenderRose;

	/** Well-known color. <span class='color' style='background-color:#7cfb00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LawnGreen;

	/** Well-known color. <span class='color' style='background-color:#fff700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lemon;

	/** Well-known color. <span class='color' style='background-color:#fff9cd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LemonChiffon;

	/** Well-known color. <span class='color' style='background-color:#cca01d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LemonCurry;

	/** Well-known color. <span class='color' style='background-color:#fdff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LemonGlacier;

	/** Well-known color. <span class='color' style='background-color:#e2ff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LemonLime;

	/** Well-known color. <span class='color' style='background-color:#f6e9bd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LemonMeringue;

	/** Well-known color. <span class='color' style='background-color:#fff44f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LemonYellow;

	/** Well-known color. <span class='color' style='background-color:#ba93d8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lenurple;

	/** Well-known color. <span class='color' style='background-color:#5459a7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Liberty;

	/** Well-known color. <span class='color' style='background-color:#1a110f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Licorice;

	/** Well-known color. <span class='color' style='background-color:#fdd4b1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightApricot;

	/** Well-known color. <span class='color' style='background-color:#acd8e6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightBlue;

	/** Well-known color. <span class='color' style='background-color:#fd2d2d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightBrilliantRed;

	/** Well-known color. <span class='color' style='background-color:#b5641d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightBrown;

	/** Well-known color. <span class='color' style='background-color:#e66770;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightCarminePink;

	/** Well-known color. <span class='color' style='background-color:#87acdf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightCobaltBlue;

	/** Well-known color. <span class='color' style='background-color:#f08080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightCoral;

	/** Well-known color. <span class='color' style='background-color:#93cce9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightCornflowerBlue;

	/** Well-known color. <span class='color' style='background-color:#f46991;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightCrimson;

	/** Well-known color. <span class='color' style='background-color:#dfffff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightCyan;

	/** Well-known color. <span class='color' style='background-color:#ff5bcd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightDeepPink;

	/** Well-known color. <span class='color' style='background-color:#c8ac7e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightFrenchBeige;

	/** Well-known color. <span class='color' style='background-color:#f983ef;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightFuchsiaPink;

	/** Well-known color. <span class='color' style='background-color:#f9f9d1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightGoldenrodYellow;

	/** Well-known color. <span class='color' style='background-color:#d3d3d3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightGray;

	/** Well-known color. <span class='color' style='background-color:#cc99cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightGrayishMagenta;

	/** Well-known color. <span class='color' style='background-color:#90ed90;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightGreen;

	/** Well-known color. <span class='color' style='background-color:#ffb3dd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightHotPink;

	/** Well-known color. <span class='color' style='background-color:#d39aca;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightMediumOrchid;

	/** Well-known color. <span class='color' style='background-color:#acdfac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightMossGreen;

	/** Well-known color. <span class='color' style='background-color:#e6a8d6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightOrchid;

	/** Well-known color. <span class='color' style='background-color:#b19cd8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightPastelPurple;

	/** Well-known color. <span class='color' style='background-color:#ffb6c1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightPink;

	/** Well-known color. <span class='color' style='background-color:#e97450;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightRedOchre;

	/** Well-known color. <span class='color' style='background-color:#ffa079;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightSalmon;

	/** Well-known color. <span class='color' style='background-color:#ff9999;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightSalmonPink;

	/** Well-known color. <span class='color' style='background-color:#1fb1aa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightSeaGreen;

	/** Well-known color. <span class='color' style='background-color:#87cdf9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightSkyBlue;

	/** Well-known color. <span class='color' style='background-color:#778799;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightSlateGray;

	/** Well-known color. <span class='color' style='background-color:#afc4dd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightSteelBlue;

	/** Well-known color. <span class='color' style='background-color:#b38a6d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightTaupe;

	/** Well-known color. <span class='color' style='background-color:#ffffdf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LightYellow;

	/** Well-known color. <span class='color' style='background-color:#c8a1c8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lilac;

	/** Well-known color. <span class='color' style='background-color:#00ff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lime;

	/** Well-known color. <span class='color' style='background-color:#31cd31;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LimeGreen;

	/** Well-known color. <span class='color' style='background-color:#bfd641;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LimePunch;

	/** Well-known color. <span class='color' style='background-color:#9cc108;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Limerick;

	/** Well-known color. <span class='color' style='background-color:#185905;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LincolnGreen;

	/** Well-known color. <span class='color' style='background-color:#f9f0e6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Linen;

	/** Well-known color. <span class='color' style='background-color:#6ba0db;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LittleBoyBlue;

	/** Well-known color. <span class='color' style='background-color:#674b46;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Liver;

	/** Well-known color. <span class='color' style='background-color:#987456;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LiverChestnut;

	/** Well-known color. <span class='color' style='background-color:#b86d28;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LiverDogs;

	/** Well-known color. <span class='color' style='background-color:#6b2d1f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color LiverOrgan;

	/** Well-known color. <span class='color' style='background-color:#ffe4cd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lumber;

	/** Well-known color. <span class='color' style='background-color:#e61f1f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Lust;

	/** Well-known color. <span class='color' style='background-color:#ffbd87;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MacaroniAndCheese;

	/** Well-known color. <span class='color' style='background-color:#ff00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Magenta;

	/** Well-known color. <span class='color' style='background-color:#ca1f7b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MagentaDye;

	/** Well-known color. <span class='color' style='background-color:#9e4475;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MagentaHaze;

	/** Well-known color. <span class='color' style='background-color:#cf417e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MagentaPantone;

	/** Well-known color. <span class='color' style='background-color:#cc338a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MagentaPink;

	/** Well-known color. <span class='color' style='background-color:#ff0090;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MagentaProcess;

	/** Well-known color. <span class='color' style='background-color:#aaf0d1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MagicMint;

	/** Well-known color. <span class='color' style='background-color:#f7f4ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Magnolia;

	/** Well-known color. <span class='color' style='background-color:#bf3f00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mahogany;

	/** Well-known color. <span class='color' style='background-color:#6050db;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MajorelleBlue;

	/** Well-known color. <span class='color' style='background-color:#0ada50;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Malachite;

	/** Well-known color. <span class='color' style='background-color:#979aaa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Manatee;

	/** Well-known color. <span class='color' style='background-color:#ff8242;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MangoTango;

	/** Well-known color. <span class='color' style='background-color:#74c364;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mantis;

	/** Well-known color. <span class='color' style='background-color:#870085;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MardiGras;

	/** Well-known color. <span class='color' style='background-color:#e9a121;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Marigold;

	/** Well-known color. <span class='color' style='background-color:#4f84c4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Marina;

	/** Well-known color. <span class='color' style='background-color:#af2f60;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Maroon;

	/** Well-known color. <span class='color' style='background-color:#dfafff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mauve;

	/** Well-known color. <span class='color' style='background-color:#ef98aa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mauvelous;

	/** Well-known color. <span class='color' style='background-color:#72c1fb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MayaBlue;

	/** Well-known color. <span class='color' style='background-color:#4b9141;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MayGreen;

	/** Well-known color. <span class='color' style='background-color:#e4b63b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MeatBrown;

	/** Well-known color. <span class='color' style='background-color:#66ddaa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumAquamarine;

	/** Well-known color. <span class='color' style='background-color:#0000cd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumBlue;

	/** Well-known color. <span class='color' style='background-color:#e2052b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumCandyAppleRed;

	/** Well-known color. <span class='color' style='background-color:#f2e4aa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumChampagne;

	/** Well-known color. <span class='color' style='background-color:#035095;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumElectricBlue;

	/** Well-known color. <span class='color' style='background-color:#1c342d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumJungleGreen;

	/** Well-known color. <span class='color' style='background-color:#ba54d3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumOrchid;

	/** Well-known color. <span class='color' style='background-color:#9370db;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumPurple;

	/** Well-known color. <span class='color' style='background-color:#ba3385;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumRedViolet;

	/** Well-known color. <span class='color' style='background-color:#aa3f69;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumRuby;

	/** Well-known color. <span class='color' style='background-color:#3bb370;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumSeaGreen;

	/** Well-known color. <span class='color' style='background-color:#80daeb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumSkyBlue;

	/** Well-known color. <span class='color' style='background-color:#7b67ed;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumSlateBlue;

	/** Well-known color. <span class='color' style='background-color:#c8db87;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumSpringBud;

	/** Well-known color. <span class='color' style='background-color:#00f99a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumSpringGreen;

	/** Well-known color. <span class='color' style='background-color:#48d1cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumTurquoise;

	/** Well-known color. <span class='color' style='background-color:#79443b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumTuscanRed;

	/** Well-known color. <span class='color' style='background-color:#d8603b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MediumVermilion;

	/** Well-known color. <span class='color' style='background-color:#f7b877;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MellowApricot;

	/** Well-known color. <span class='color' style='background-color:#fdbcb3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Melon;

	/** Well-known color. <span class='color' style='background-color:#0a7e8c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MetallicSeaweed;

	/** Well-known color. <span class='color' style='background-color:#9c7c38;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MetallicSunburst;

	/** Well-known color. <span class='color' style='background-color:#e4007c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MexicanPink;

	/** Well-known color. <span class='color' style='background-color:#181870;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MidnightBlue;

	/** Well-known color. <span class='color' style='background-color:#004952;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MidnightGreen;

	/** Well-known color. <span class='color' style='background-color:#ffc40c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MikadoYellow;

	/** Well-known color. <span class='color' style='background-color:#e2f987;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mindaro;

	/** Well-known color. <span class='color' style='background-color:#36747c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ming;

	/** Well-known color. <span class='color' style='background-color:#3db389;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mint;

	/** Well-known color. <span class='color' style='background-color:#f4fff9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MintCream;

	/** Well-known color. <span class='color' style='background-color:#98ff98;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MintGreen;

	/** Well-known color. <span class='color' style='background-color:#ffe4e1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MistyRose;

	/** Well-known color. <span class='color' style='background-color:#72a8c1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MoonstoneBlue;

	/** Well-known color. <span class='color' style='background-color:#ae0c00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MordantRed19;

	/** Well-known color. <span class='color' style='background-color:#00758f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MosaicBlue;

	/** Well-known color. <span class='color' style='background-color:#8a9a5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MossGreen;

	/** Well-known color. <span class='color' style='background-color:#2fba8e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MountainMeadow;

	/** Well-known color. <span class='color' style='background-color:#99798c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MountbattenPink;

	/** Well-known color. <span class='color' style='background-color:#18443b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MsuGreen;

	/** Well-known color. <span class='color' style='background-color:#2f602f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MughalGreen;

	/** Well-known color. <span class='color' style='background-color:#c44b8c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mulberry;

	/** Well-known color. <span class='color' style='background-color:#ffdb57;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Mustard;

	/** Well-known color. <span class='color' style='background-color:#317772;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color MyrtleGreen;

	/** Well-known color. <span class='color' style='background-color:#f6acc6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NadeshikoPink;

	/** Well-known color. <span class='color' style='background-color:#2a8000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NapierGreen;

	/** Well-known color. <span class='color' style='background-color:#ffddac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NavajoWhite;

	/** Well-known color. <span class='color' style='background-color:#000080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Navy;

	/** Well-known color. <span class='color' style='background-color:#282d3c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NavyBlazer;

	/** Well-known color. <span class='color' style='background-color:#9357eb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NavyPurple;

	/** Well-known color. <span class='color' style='background-color:#ffa342;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NeonCarrot;

	/** Well-known color. <span class='color' style='background-color:#fd4164;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NeonFuchsia;

	/** Well-known color. <span class='color' style='background-color:#38ff13;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NeonGreen;

	/** Well-known color. <span class='color' style='background-color:#214fc6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NewCar;

	/** Well-known color. <span class='color' style='background-color:#d6837e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NewYorkPink;

	/** Well-known color. <span class='color' style='background-color:#578ca9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Niagara;

	/** Well-known color. <span class='color' style='background-color:#a3dded;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NonPhotoBlue;

	/** Well-known color. <span class='color' style='background-color:#059033;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color NorthTexasGreen;

	/** Well-known color. <span class='color' style='background-color:#e9ffdb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Nyanza;

	/** Well-known color. <span class='color' style='background-color:#0077bd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OceanBoatBlue;

	/** Well-known color. <span class='color' style='background-color:#cc7721;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ochre;

	/** Well-known color. <span class='color' style='background-color:#422f2d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OldBurgundy;

	/** Well-known color. <span class='color' style='background-color:#cfb53b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OldGold;

	/** Well-known color. <span class='color' style='background-color:#fdf4e6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OldLace;

	/** Well-known color. <span class='color' style='background-color:#796777;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OldLavender;

	/** Well-known color. <span class='color' style='background-color:#857e36;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OldMossGreen;

	/** Well-known color. <span class='color' style='background-color:#bf8080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OldRose;

	/** Well-known color. <span class='color' style='background-color:#838382;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OldSilver;

	/** Well-known color. <span class='color' style='background-color:#808000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Olive;

	/** Well-known color. <span class='color' style='background-color:#6b8e23;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OliveDrab3;

	/** Well-known color. <span class='color' style='background-color:#3b341f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OliveDrab7;

	/** Well-known color. <span class='color' style='background-color:#9ab872;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Olivine;

	/** Well-known color. <span class='color' style='background-color:#343838;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Onyx;

	/** Well-known color. <span class='color' style='background-color:#b683a7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OperaMauve;

	/** Well-known color. <span class='color' style='background-color:#ffa500;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Orange;

	/** Well-known color. <span class='color' style='background-color:#ff4f00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeAerospace;

	/** Well-known color. <span class='color' style='background-color:#ff7e00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeColorWheel;

	/** Well-known color. <span class='color' style='background-color:#ff7538;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeCrayola;

	/** Well-known color. <span class='color' style='background-color:#ba160c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeEngineering;

	/** Well-known color. <span class='color' style='background-color:#bf362b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeGoldenGateBridge;

	/** Well-known color. <span class='color' style='background-color:#ff5700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangePantone;

	/** Well-known color. <span class='color' style='background-color:#ff9e00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangePeel;

	/** Well-known color. <span class='color' style='background-color:#ff4400;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeRed;

	/** Well-known color. <span class='color' style='background-color:#fb9901;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeRyb;

	/** Well-known color. <span class='color' style='background-color:#f7d467;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrangeYellow;

	/** Well-known color. <span class='color' style='background-color:#da70d6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Orchid;

	/** Well-known color. <span class='color' style='background-color:#f2bdcd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OrchidPink;

	/** Well-known color. <span class='color' style='background-color:#fb4f13;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OriolesOrange;

	/** Well-known color. <span class='color' style='background-color:#41494b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OuterSpace;

	/** Well-known color. <span class='color' style='background-color:#ff6e49;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OutrageousOrange;

	/** Well-known color. <span class='color' style='background-color:#002146;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color OxfordBlue;

	/** Well-known color. <span class='color' style='background-color:#1ca8c8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PacificBlue;

	/** Well-known color. <span class='color' style='background-color:#006600;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PakistanGreen;

	/** Well-known color. <span class='color' style='background-color:#263be2;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PalatinateBlue;

	/** Well-known color. <span class='color' style='background-color:#672860;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PalatinatePurple;

	/** Well-known color. <span class='color' style='background-color:#bcd4e6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleAqua;

	/** Well-known color. <span class='color' style='background-color:#afeded;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleBlue;

	/** Well-known color. <span class='color' style='background-color:#987554;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleBrown;

	/** Well-known color. <span class='color' style='background-color:#af3f34;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleCarmine;

	/** Well-known color. <span class='color' style='background-color:#9ac4e2;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleCerulean;

	/** Well-known color. <span class='color' style='background-color:#ddacaf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleChestnut;

	/** Well-known color. <span class='color' style='background-color:#da8a67;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleCopper;

	/** Well-known color. <span class='color' style='background-color:#aacdef;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleCornflowerBlue;

	/** Well-known color. <span class='color' style='background-color:#87d3f7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleCyan;

	/** Well-known color. <span class='color' style='background-color:#e6bd8a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleGold;

	/** Well-known color. <span class='color' style='background-color:#ede8aa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleGoldenrod;

	/** Well-known color. <span class='color' style='background-color:#98fb98;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleGreen;

	/** Well-known color. <span class='color' style='background-color:#dbcfff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleLavender;

	/** Well-known color. <span class='color' style='background-color:#f983e4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleMagenta;

	/** Well-known color. <span class='color' style='background-color:#ff99cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleMagentaPink;

	/** Well-known color. <span class='color' style='background-color:#f9dadd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PalePink;

	/** Well-known color. <span class='color' style='background-color:#95ddd1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleRobinEggBlue;

	/** Well-known color. <span class='color' style='background-color:#c8bfba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleSilver;

	/** Well-known color. <span class='color' style='background-color:#ebebbd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleSpringBud;

	/** Well-known color. <span class='color' style='background-color:#bc987e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleTaupe;

	/** Well-known color. <span class='color' style='background-color:#cc99ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleViolet;

	/** Well-known color. <span class='color' style='background-color:#db7093;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaleVioletRed;

	/** Well-known color. <span class='color' style='background-color:#771849;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PansyPurple;

	/** Well-known color. <span class='color' style='background-color:#009a7c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PaoloVeroneseGreen;

	/** Well-known color. <span class='color' style='background-color:#ffefd4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PapayaWhip;

	/** Well-known color. <span class='color' style='background-color:#e63d62;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ParadisePink;

	/** Well-known color. <span class='color' style='background-color:#aec6cf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelBlue;

	/** Well-known color. <span class='color' style='background-color:#826952;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelBrown;

	/** Well-known color. <span class='color' style='background-color:#cfcfc4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelGray;

	/** Well-known color. <span class='color' style='background-color:#77dd77;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelGreen;

	/** Well-known color. <span class='color' style='background-color:#f49ac1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelMagenta;

	/** Well-known color. <span class='color' style='background-color:#ffb346;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelOrange;

	/** Well-known color. <span class='color' style='background-color:#dda5a3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelPink;

	/** Well-known color. <span class='color' style='background-color:#b39eb5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelPurple;

	/** Well-known color. <span class='color' style='background-color:#ff6960;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelRed;

	/** Well-known color. <span class='color' style='background-color:#ca99c8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelViolet;

	/** Well-known color. <span class='color' style='background-color:#fdfd95;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PastelYellow;

	/** Well-known color. <span class='color' style='background-color:#ffcaa3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Peach;

	/** Well-known color. <span class='color' style='background-color:#ffcc99;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PeachOrange;

	/** Well-known color. <span class='color' style='background-color:#ffdab8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PeachPuff;

	/** Well-known color. <span class='color' style='background-color:#f9dfac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PeachYellow;

	/** Well-known color. <span class='color' style='background-color:#d1e231;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Pear;

	/** Well-known color. <span class='color' style='background-color:#e9dfc8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Pearl;

	/** Well-known color. <span class='color' style='background-color:#87d8bf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PearlAqua;

	/** Well-known color. <span class='color' style='background-color:#b667a1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PearlyPurple;

	/** Well-known color. <span class='color' style='background-color:#8d9440;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PepperStem;

	/** Well-known color. <span class='color' style='background-color:#e6e200;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Peridot;

	/** Well-known color. <span class='color' style='background-color:#1c38ba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianBlue;

	/** Well-known color. <span class='color' style='background-color:#00a593;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianGreen;

	/** Well-known color. <span class='color' style='background-color:#311179;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianIndigo;

	/** Well-known color. <span class='color' style='background-color:#d89057;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianOrange;

	/** Well-known color. <span class='color' style='background-color:#f77ebd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianPink;

	/** Well-known color. <span class='color' style='background-color:#701c1c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianPlum;

	/** Well-known color. <span class='color' style='background-color:#cc3333;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianRed;

	/** Well-known color. <span class='color' style='background-color:#fd28a1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PersianRose;

	/** Well-known color. <span class='color' style='background-color:#eb5700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Persimmon;

	/** Well-known color. <span class='color' style='background-color:#cd853f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Peru;

	/** Well-known color. <span class='color' style='background-color:#000f89;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PhthaloBlue;

	/** Well-known color. <span class='color' style='background-color:#113424;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PhthaloGreen;

	/** Well-known color. <span class='color' style='background-color:#44b1e8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PictonBlue;

	/** Well-known color. <span class='color' style='background-color:#c30a4d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PictorialCarmine;

	/** Well-known color. <span class='color' style='background-color:#fddde6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PiggyPink;

	/** Well-known color. <span class='color' style='background-color:#563b0c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Pineapple;

	/** Well-known color. <span class='color' style='background-color:#01796e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PineGreen;

	/** Well-known color. <span class='color' style='background-color:#ffbfca;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Pink;

	/** Well-known color. <span class='color' style='background-color:#fb74fd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkFlamingo;

	/** Well-known color. <span class='color' style='background-color:#ffddf4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkLace;

	/** Well-known color. <span class='color' style='background-color:#d8b1d1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkLavender;

	/** Well-known color. <span class='color' style='background-color:#ff9966;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkOrange;

	/** Well-known color. <span class='color' style='background-color:#d64893;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkPantone;

	/** Well-known color. <span class='color' style='background-color:#e6accf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkPearl;

	/** Well-known color. <span class='color' style='background-color:#980036;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkRaspberry;

	/** Well-known color. <span class='color' style='background-color:#f78ea7;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PinkSherbet;

	/** Well-known color. <span class='color' style='background-color:#93c472;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Pistachio;

	/** Well-known color. <span class='color' style='background-color:#e4e4e2;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Platinum;

	/** Well-known color. <span class='color' style='background-color:#dda0dd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Plum;

	/** Well-known color. <span class='color' style='background-color:#bd4f62;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Popstar;

	/** Well-known color. <span class='color' style='background-color:#ff5936;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PortlandOrange;

	/** Well-known color. <span class='color' style='background-color:#afdfe6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PowderBlue;

	/** Well-known color. <span class='color' style='background-color:#f48024;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PrincetonOrange;

	/** Well-known color. <span class='color' style='background-color:#003152;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PrussianBlue;

	/** Well-known color. <span class='color' style='background-color:#df00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PsychedelicPurple;

	/** Well-known color. <span class='color' style='background-color:#cc8799;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Puce;

	/** Well-known color. <span class='color' style='background-color:#644116;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PullmanBrown;

	/** Well-known color. <span class='color' style='background-color:#3b331c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PullmanGreen;

	/** Well-known color. <span class='color' style='background-color:#ff7518;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Pumpkin;

	/** Well-known color. <span class='color' style='background-color:#a01ff0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Purple;

	/** Well-known color. <span class='color' style='background-color:#69349c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PurpleHeart;

	/** Well-known color. <span class='color' style='background-color:#800080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PurpleHtml;

	/** Well-known color. <span class='color' style='background-color:#9577b6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PurpleMountainMajesty;

	/** Well-known color. <span class='color' style='background-color:#9e00c4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PurpleMunsell;

	/** Well-known color. <span class='color' style='background-color:#4d5080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PurpleNavy;

	/** Well-known color. <span class='color' style='background-color:#fd4dda;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PurplePizzazz;

	/** Well-known color. <span class='color' style='background-color:#503f4d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color PurpleTaupe;

	/** Well-known color. <span class='color' style='background-color:#9a4dae;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Purpureus;

	/** Well-known color. <span class='color' style='background-color:#50484f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Quartz;

	/** Well-known color. <span class='color' style='background-color:#426b95;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color QueenBlue;

	/** Well-known color. <span class='color' style='background-color:#e8ccd6;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color QueenPink;

	/** Well-known color. <span class='color' style='background-color:#8e3a59;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color QuinacridoneMagenta;

	/** Well-known color. <span class='color' style='background-color:#ff345e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RadicalRed;

	/** Well-known color. <span class='color' style='background-color:#242124;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RaisinBlack;

	/** Well-known color. <span class='color' style='background-color:#fbaa60;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Rajah;

	/** Well-known color. <span class='color' style='background-color:#e20a5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Raspberry;

	/** Well-known color. <span class='color' style='background-color:#915e6d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RaspberryGlace;

	/** Well-known color. <span class='color' style='background-color:#e25098;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RaspberryPink;

	/** Well-known color. <span class='color' style='background-color:#b3446b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RaspberryRose;

	/** Well-known color. <span class='color' style='background-color:#d68a59;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RawSienna;

	/** Well-known color. <span class='color' style='background-color:#826644;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RawUmber;

	/** Well-known color. <span class='color' style='background-color:#ff33cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RazzleDazzleRose;

	/** Well-known color. <span class='color' style='background-color:#e2246b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Razzmatazz;

	/** Well-known color. <span class='color' style='background-color:#8c4d85;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RazzmicBerry;

	/** Well-known color. <span class='color' style='background-color:#663499;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RebeccaPurple;

	/** Well-known color. <span class='color' style='background-color:#ff0000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Red;

	/** Well-known color. <span class='color' style='background-color:#ed1f4d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedCrayola;

	/** Well-known color. <span class='color' style='background-color:#850111;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedDevil;

	/** Well-known color. <span class='color' style='background-color:#f2003b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedMunsell;

	/** Well-known color. <span class='color' style='background-color:#c40133;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedNcs;

	/** Well-known color. <span class='color' style='background-color:#ff5249;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedOrange;

	/** Well-known color. <span class='color' style='background-color:#ed1c24;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedPigment;

	/** Well-known color. <span class='color' style='background-color:#e40077;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedPurple;

	/** Well-known color. <span class='color' style='background-color:#fd2611;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedRyb;

	/** Well-known color. <span class='color' style='background-color:#c61585;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RedViolet;

	/** Well-known color. <span class='color' style='background-color:#a35952;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Redwood;

	/** Well-known color. <span class='color' style='background-color:#522d80;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Regalia;

	/** Well-known color. <span class='color' style='background-color:#002387;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ResolutionBlue;

	/** Well-known color. <span class='color' style='background-color:#777595;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Rhythm;

	/** Well-known color. <span class='color' style='background-color:#003f3f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichBlack;

	/** Well-known color. <span class='color' style='background-color:#010a13;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichBlackFogra29;

	/** Well-known color. <span class='color' style='background-color:#010103;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichBlackFogra39;

	/** Well-known color. <span class='color' style='background-color:#f0a7fd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichBrilliantLavender;

	/** Well-known color. <span class='color' style='background-color:#d6003f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichCarmine;

	/** Well-known color. <span class='color' style='background-color:#0891cf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichElectricBlue;

	/** Well-known color. <span class='color' style='background-color:#a76bcf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichLavender;

	/** Well-known color. <span class='color' style='background-color:#b666d1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RichLilac;

	/** Well-known color. <span class='color' style='background-color:#444b38;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RifleGreen;

	/** Well-known color. <span class='color' style='background-color:#00cccc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RobinEggBlue;

	/** Well-known color. <span class='color' style='background-color:#8a7e80;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RocketMetallic;

	/** Well-known color. <span class='color' style='background-color:#838995;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RomanSilver;

	/** Well-known color. <span class='color' style='background-color:#ff007e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Rose;

	/** Well-known color. <span class='color' style='background-color:#f9429e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseBonbon;

	/** Well-known color. <span class='color' style='background-color:#674846;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseEbony;

	/** Well-known color. <span class='color' style='background-color:#b66e79;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseGold;

	/** Well-known color. <span class='color' style='background-color:#e22636;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseMadder;

	/** Well-known color. <span class='color' style='background-color:#ff66cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RosePink;

	/** Well-known color. <span class='color' style='background-color:#aa98a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseQuartz;

	/** Well-known color. <span class='color' style='background-color:#c11d56;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseRed;

	/** Well-known color. <span class='color' style='background-color:#905d5d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseTaupe;

	/** Well-known color. <span class='color' style='background-color:#aa4d52;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoseVale;

	/** Well-known color. <span class='color' style='background-color:#64000a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Rosewood;

	/** Well-known color. <span class='color' style='background-color:#d40000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RossoCorsa;

	/** Well-known color. <span class='color' style='background-color:#bc8e8e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RosyBrown;

	/** Well-known color. <span class='color' style='background-color:#0038a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoyalAzure;

	/** Well-known color. <span class='color' style='background-color:#4169e1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoyalBlue;

	/** Well-known color. <span class='color' style='background-color:#ca2b91;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoyalFuchsia;

	/** Well-known color. <span class='color' style='background-color:#7750a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoyalPurple;

	/** Well-known color. <span class='color' style='background-color:#f9da5e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RoyalYellow;

	/** Well-known color. <span class='color' style='background-color:#cd4675;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ruber;

	/** Well-known color. <span class='color' style='background-color:#d10056;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RubineRed;

	/** Well-known color. <span class='color' style='background-color:#df115e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ruby;

	/** Well-known color. <span class='color' style='background-color:#9a111d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RubyRed;

	/** Well-known color. <span class='color' style='background-color:#ff0028;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ruddy;

	/** Well-known color. <span class='color' style='background-color:#ba6428;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RuddyBrown;

	/** Well-known color. <span class='color' style='background-color:#e18e95;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RuddyPink;

	/** Well-known color. <span class='color' style='background-color:#a81c07;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Rufous;

	/** Well-known color. <span class='color' style='background-color:#80461a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Russet;

	/** Well-known color. <span class='color' style='background-color:#679167;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RussianGreen;

	/** Well-known color. <span class='color' style='background-color:#31164d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RussianViolet;

	/** Well-known color. <span class='color' style='background-color:#b6410e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Rust;

	/** Well-known color. <span class='color' style='background-color:#da2b42;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color RustyRed;

	/** Well-known color. <span class='color' style='background-color:#8a4413;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SaddleBrown;

	/** Well-known color. <span class='color' style='background-color:#ff7700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SafetyOrange;

	/** Well-known color. <span class='color' style='background-color:#ff6700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SafetyOrangeBlaze;

	/** Well-known color. <span class='color' style='background-color:#edd101;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SafetyYellow;

	/** Well-known color. <span class='color' style='background-color:#f4c42f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Saffron;

	/** Well-known color. <span class='color' style='background-color:#bcb88a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sage;

	/** Well-known color. <span class='color' style='background-color:#f98072;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Salmon;

	/** Well-known color. <span class='color' style='background-color:#ff91a3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SalmonPink;

	/** Well-known color. <span class='color' style='background-color:#c1b180;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sand;

	/** Well-known color. <span class='color' style='background-color:#ebd43f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sandstorm;

	/** Well-known color. <span class='color' style='background-color:#f4a360;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SandyBrown;

	/** Well-known color. <span class='color' style='background-color:#91000a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sangria;

	/** Well-known color. <span class='color' style='background-color:#507c2a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SapGreen;

	/** Well-known color. <span class='color' style='background-color:#0f52ba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sapphire;

	/** Well-known color. <span class='color' style='background-color:#0067a5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SapphireBlue;

	/** Well-known color. <span class='color' style='background-color:#caa134;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SatinSheenGold;

	/** Well-known color. <span class='color' style='background-color:#fd0e34;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Scarlet;

	/** Well-known color. <span class='color' style='background-color:#478800;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ScheelesGreen;

	/** Well-known color. <span class='color' style='background-color:#ffd800;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SchoolBusYellow;

	/** Well-known color. <span class='color' style='background-color:#75ff79;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ScreaminGreen;

	/** Well-known color. <span class='color' style='background-color:#006993;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SeaBlue;

	/** Well-known color. <span class='color' style='background-color:#2d8a57;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SeaGreen;

	/** Well-known color. <span class='color' style='background-color:#311313;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SealBrown;

	/** Well-known color. <span class='color' style='background-color:#fff4ed;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Seashell;

	/** Well-known color. <span class='color' style='background-color:#ffba00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SelectiveYellow;

	/** Well-known color. <span class='color' style='background-color:#704213;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sepia;

	/** Well-known color. <span class='color' style='background-color:#91a8d0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Serenity;

	/** Well-known color. <span class='color' style='background-color:#005960;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ShadedSpruce;

	/** Well-known color. <span class='color' style='background-color:#8a795d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Shadow;

	/** Well-known color. <span class='color' style='background-color:#778aa5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ShadowBlue;

	/** Well-known color. <span class='color' style='background-color:#ffcff0;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Shampoo;

	/** Well-known color. <span class='color' style='background-color:#009e60;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ShamrockGreen;

	/** Well-known color. <span class='color' style='background-color:#8ed400;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SheenGreen;

	/** Well-known color. <span class='color' style='background-color:#d88595;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ShimmeringBlush;

	/** Well-known color. <span class='color' style='background-color:#fb0fbf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ShockingPink;

	/** Well-known color. <span class='color' style='background-color:#872d16;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sienna;

	/** Well-known color. <span class='color' style='background-color:#bfbfbf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Silver;

	/** Well-known color. <span class='color' style='background-color:#acacac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SilverChalice;

	/** Well-known color. <span class='color' style='background-color:#5d89ba;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SilverLakeBlue;

	/** Well-known color. <span class='color' style='background-color:#c4aeac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SilverPink;

	/** Well-known color. <span class='color' style='background-color:#bfc1c1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SilverSand;

	/** Well-known color. <span class='color' style='background-color:#ca410a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sinopia;

	/** Well-known color. <span class='color' style='background-color:#007474;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Skobeloff;

	/** Well-known color. <span class='color' style='background-color:#87cdeb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SkyBlue;

	/** Well-known color. <span class='color' style='background-color:#cf70af;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SkyMagenta;

	/** Well-known color. <span class='color' style='background-color:#6959cd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SlateBlue;

	/** Well-known color. <span class='color' style='background-color:#708090;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SlateGray;

	/** Well-known color. <span class='color' style='background-color:#c84185;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Smitten;

	/** Well-known color. <span class='color' style='background-color:#728275;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Smoke;

	/** Well-known color. <span class='color' style='background-color:#0f0c08;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SmokyBlack;

	/** Well-known color. <span class='color' style='background-color:#933d41;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SmokyTopaz;

	/** Well-known color. <span class='color' style='background-color:#fff9f9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Snow;

	/** Well-known color. <span class='color' style='background-color:#cdc8ef;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Soap;

	/** Well-known color. <span class='color' style='background-color:#893842;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SolidPink;

	/** Well-known color. <span class='color' style='background-color:#757575;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SonicSilver;

	/** Well-known color. <span class='color' style='background-color:#1d2850;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpaceCadet;

	/** Well-known color. <span class='color' style='background-color:#807531;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishBistre;

	/** Well-known color. <span class='color' style='background-color:#0070b8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishBlue;

	/** Well-known color. <span class='color' style='background-color:#d10046;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishCarmine;

	/** Well-known color. <span class='color' style='background-color:#e41a4b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishCrimson;

	/** Well-known color. <span class='color' style='background-color:#989898;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishGray;

	/** Well-known color. <span class='color' style='background-color:#009150;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishGreen;

	/** Well-known color. <span class='color' style='background-color:#e86000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishOrange;

	/** Well-known color. <span class='color' style='background-color:#f7bfbd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishPink;

	/** Well-known color. <span class='color' style='background-color:#e60026;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishRed;

	/** Well-known color. <span class='color' style='background-color:#4b2882;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishViolet;

	/** Well-known color. <span class='color' style='background-color:#007e5b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpanishViridian;

	/** Well-known color. <span class='color' style='background-color:#9e1316;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpartanCrimson;

	/** Well-known color. <span class='color' style='background-color:#8a5e4d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpicyMix;

	/** Well-known color. <span class='color' style='background-color:#0fbffb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpiroDiscoBall;

	/** Well-known color. <span class='color' style='background-color:#a7fb00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpringBud;

	/** Well-known color. <span class='color' style='background-color:#bc70a4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpringCrocus;

	/** Well-known color. <span class='color' style='background-color:#00ff7e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SpringGreen;

	/** Well-known color. <span class='color' style='background-color:#007bb8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color StarCommandBlue;

	/** Well-known color. <span class='color' style='background-color:#4682b3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SteelBlue;

	/** Well-known color. <span class='color' style='background-color:#cc33cc;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SteelPink;

	/** Well-known color. <span class='color' style='background-color:#4f6669;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Stormcloud;

	/** Well-known color. <span class='color' style='background-color:#232879;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color StPatricksBlue;

	/** Well-known color. <span class='color' style='background-color:#e4d86e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Straw;

	/** Well-known color. <span class='color' style='background-color:#fb598c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Strawberry;

	/** Well-known color. <span class='color' style='background-color:#ffcc33;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sunglow;

	/** Well-known color. <span class='color' style='background-color:#e2aa57;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Sunray;

	/** Well-known color. <span class='color' style='background-color:#fd5e52;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SunsetOrange;

	/** Well-known color. <span class='color' style='background-color:#cf6ba8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color SuperPink;

	/** Well-known color. <span class='color' style='background-color:#d1b38c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tan;

	/** Well-known color. <span class='color' style='background-color:#f94d00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tangelo;

	/** Well-known color. <span class='color' style='background-color:#f28500;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tangerine;

	/** Well-known color. <span class='color' style='background-color:#ffcc00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TangerineYellow;

	/** Well-known color. <span class='color' style='background-color:#8a8589;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TaupeGray;

	/** Well-known color. <span class='color' style='background-color:#cff0bf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TeaGreen;

	/** Well-known color. <span class='color' style='background-color:#008080;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Teal;

	/** Well-known color. <span class='color' style='background-color:#367587;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TealBlue;

	/** Well-known color. <span class='color' style='background-color:#99e6b3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TealDeer;

	/** Well-known color. <span class='color' style='background-color:#00827e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TealGreen;

	/** Well-known color. <span class='color' style='background-color:#cf3475;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Telemagenta;

	/** Well-known color. <span class='color' style='background-color:#cd5700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tenne;

	/** Well-known color. <span class='color' style='background-color:#e2725b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TerraCotta;

	/** Well-known color. <span class='color' style='background-color:#d8bfd8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Thistle;

	/** Well-known color. <span class='color' style='background-color:#fb89ac;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TickleMePink;

	/** Well-known color. <span class='color' style='background-color:#0abab5;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TiffanyBlue;

	/** Well-known color. <span class='color' style='background-color:#df8c3b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TigersEye;

	/** Well-known color. <span class='color' style='background-color:#dbd6d1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Timberwolf;

	/** Well-known color. <span class='color' style='background-color:#ede600;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TitaniumYellow;

	/** Well-known color. <span class='color' style='background-color:#ff6246;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tomato;

	/** Well-known color. <span class='color' style='background-color:#746bbf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Toolbox;

	/** Well-known color. <span class='color' style='background-color:#ffc87c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Topaz;

	/** Well-known color. <span class='color' style='background-color:#00755e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TropicalRainForest;

	/** Well-known color. <span class='color' style='background-color:#cda3dd;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TropicalViolet;

	/** Well-known color. <span class='color' style='background-color:#0072cf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TrueBlue;

	/** Well-known color. <span class='color' style='background-color:#417cc1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TuftsBlue;

	/** Well-known color. <span class='color' style='background-color:#ff878c;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tulip;

	/** Well-known color. <span class='color' style='background-color:#ddaa87;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tumbleweed;

	/** Well-known color. <span class='color' style='background-color:#b57280;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TurkishRose;

	/** Well-known color. <span class='color' style='background-color:#3fdfcf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Turquoise;

	/** Well-known color. <span class='color' style='background-color:#00ffef;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TurquoiseBlue;

	/** Well-known color. <span class='color' style='background-color:#a0d6b3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TurquoiseGreen;

	/** Well-known color. <span class='color' style='background-color:#7c4848;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TuscanRed;

	/** Well-known color. <span class='color' style='background-color:#bf9999;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Tuscany;

	/** Well-known color. <span class='color' style='background-color:#8a496b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color TwilightLavender;

	/** Well-known color. <span class='color' style='background-color:#0033aa;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UaBlue;

	/** Well-known color. <span class='color' style='background-color:#d8004b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UaRed;

	/** Well-known color. <span class='color' style='background-color:#8777c3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ube;

	/** Well-known color. <span class='color' style='background-color:#526795;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UclaBlue;

	/** Well-known color. <span class='color' style='background-color:#ffb300;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UclaGold;

	/** Well-known color. <span class='color' style='background-color:#3bcf70;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UfoGreen;

	/** Well-known color. <span class='color' style='background-color:#110a8e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Ultramarine;

	/** Well-known color. <span class='color' style='background-color:#4166f4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UltramarineBlue;

	/** Well-known color. <span class='color' style='background-color:#ff6eff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UltraPink;

	/** Well-known color. <span class='color' style='background-color:#fb6b85;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UltraRed;

	/** Well-known color. <span class='color' style='background-color:#6b5b95;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UltraViolet;

	/** Well-known color. <span class='color' style='background-color:#625046;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Umber;

	/** Well-known color. <span class='color' style='background-color:#ffddca;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UnbleachedSilk;

	/** Well-known color. <span class='color' style='background-color:#5b91e4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UnitedNationsBlue;

	/** Well-known color. <span class='color' style='background-color:#b68726;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UniversityOfCaliforniaGold;

	/** Well-known color. <span class='color' style='background-color:#f77e00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UniversityOfTennesseeOrange;

	/** Well-known color. <span class='color' style='background-color:#7b1113;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UpMaroon;

	/** Well-known color. <span class='color' style='background-color:#ae1f28;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UpsdellRed;

	/** Well-known color. <span class='color' style='background-color:#e1ac21;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Urobilin;

	/** Well-known color. <span class='color' style='background-color:#004f98;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UsafaBlue;

	/** Well-known color. <span class='color' style='background-color:#d3003f;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color UtahCrimson;

	/** Well-known color. <span class='color' style='background-color:#f28ea8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VanillaIce;

	/** Well-known color. <span class='color' style='background-color:#c4b357;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VegasGold;

	/** Well-known color. <span class='color' style='background-color:#c80815;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VenetianRed;

	/** Well-known color. <span class='color' style='background-color:#42b3ae;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Verdigris;

	/** Well-known color. <span class='color' style='background-color:#d8381d;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Vermilion;

	/** Well-known color. <span class='color' style='background-color:#74bafb;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VeryLightAzure;

	/** Well-known color. <span class='color' style='background-color:#6666ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VeryLightBlue;

	/** Well-known color. <span class='color' style='background-color:#64e985;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VeryLightMalachiteGreen;

	/** Well-known color. <span class='color' style='background-color:#ffaf77;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VeryLightTangelo;

	/** Well-known color. <span class='color' style='background-color:#ffdfbf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VeryPaleOrange;

	/** Well-known color. <span class='color' style='background-color:#ffffbf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VeryPaleYellow;

	/** Well-known color. <span class='color' style='background-color:#ed82ed;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Violet;

	/** Well-known color. <span class='color' style='background-color:#3149b1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VioletBlue;

	/** Well-known color. <span class='color' style='background-color:#7e00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VioletColorWheel;

	/** Well-known color. <span class='color' style='background-color:#f75293;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VioletRed;

	/** Well-known color. <span class='color' style='background-color:#8501af;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VioletRyb;

	/** Well-known color. <span class='color' style='background-color:#009598;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ViridianGreen;

	/** Well-known color. <span class='color' style='background-color:#7c9ed8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VistaBlue;

	/** Well-known color. <span class='color' style='background-color:#cc9900;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividAmber;

	/** Well-known color. <span class='color' style='background-color:#912624;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividAuburn;

	/** Well-known color. <span class='color' style='background-color:#9e1d34;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividBurgundy;

	/** Well-known color. <span class='color' style='background-color:#da1d80;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividCerise;

	/** Well-known color. <span class='color' style='background-color:#00aaed;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividCerulean;

	/** Well-known color. <span class='color' style='background-color:#cc0033;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividCrimson;

	/** Well-known color. <span class='color' style='background-color:#ff9900;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividGamboge;

	/** Well-known color. <span class='color' style='background-color:#a5d608;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividLimeGreen;

	/** Well-known color. <span class='color' style='background-color:#00cc33;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividMalachite;

	/** Well-known color. <span class='color' style='background-color:#b80ce2;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividMulberry;

	/** Well-known color. <span class='color' style='background-color:#ff5e00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividOrange;

	/** Well-known color. <span class='color' style='background-color:#ffa000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividOrangePeel;

	/** Well-known color. <span class='color' style='background-color:#cc00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividOrchid;

	/** Well-known color. <span class='color' style='background-color:#ff006b;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividRaspberry;

	/** Well-known color. <span class='color' style='background-color:#f70c1a;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividRed;

	/** Well-known color. <span class='color' style='background-color:#df6024;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividRedTangelo;

	/** Well-known color. <span class='color' style='background-color:#00ccff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividSkyBlue;

	/** Well-known color. <span class='color' style='background-color:#f07426;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividTangelo;

	/** Well-known color. <span class='color' style='background-color:#ffa089;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividTangerine;

	/** Well-known color. <span class='color' style='background-color:#e46024;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividVermilion;

	/** Well-known color. <span class='color' style='background-color:#9e00ff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividViolet;

	/** Well-known color. <span class='color' style='background-color:#ffe201;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color VividYellow;

	/** Well-known color. <span class='color' style='background-color:#cdff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Volt;

	/** Well-known color. <span class='color' style='background-color:#004242;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WarmBlack;

	/** Well-known color. <span class='color' style='background-color:#a3f4f9;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Waterspout;

	/** Well-known color. <span class='color' style='background-color:#645452;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Wenge;

	/** Well-known color. <span class='color' style='background-color:#f4ddb3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Wheat;

	/** Well-known color. <span class='color' style='background-color:#ffffff;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color White;

	/** Well-known color. <span class='color' style='background-color:#f4f4f4;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WhiteSmoke;

	/** Well-known color. <span class='color' style='background-color:#a1accf;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WildBlueYonder;

	/** Well-known color. <span class='color' style='background-color:#d470a1;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WildOrchid;

	/** Well-known color. <span class='color' style='background-color:#ff42a3;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WildStrawberry;

	/** Well-known color. <span class='color' style='background-color:#fd5700;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WillpowerOrange;

	/** Well-known color. <span class='color' style='background-color:#a75401;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WindsorTan;

	/** Well-known color. <span class='color' style='background-color:#722f36;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Wine;

	/** Well-known color. <span class='color' style='background-color:#673146;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color WineDregs;

	/** Well-known color. <span class='color' style='background-color:#c8a0db;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Wisteria;

	/** Well-known color. <span class='color' style='background-color:#728577;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Xanadu;

	/** Well-known color. <span class='color' style='background-color:#0f4d91;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YaleBlue;

	/** Well-known color. <span class='color' style='background-color:#1c2841;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YankeesBlue;

	/** Well-known color. <span class='color' style='background-color:#ffff00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Yellow;

	/** Well-known color. <span class='color' style='background-color:#fbe883;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YellowCrayola;

	/** Well-known color. <span class='color' style='background-color:#9acd31;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YellowGreen;

	/** Well-known color. <span class='color' style='background-color:#efcc00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YellowMunsell;

	/** Well-known color. <span class='color' style='background-color:#ffae42;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YellowOrange;

	/** Well-known color. <span class='color' style='background-color:#fddf00;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YellowPantone;

	/** Well-known color. <span class='color' style='background-color:#fff000;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YellowRose;

	/** Well-known color. <span class='color' style='background-color:#fdfd33;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color YellowRyb;

	/** Well-known color. <span class='color' style='background-color:#0013a8;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Zaffre;

	/** Well-known color. <span class='color' style='background-color:#2b1608;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color ZinnwalditeBrown;

	/** Well-known color. <span class='color' style='background-color:#38a78e;'>&nbsp;&nbsp;&nbsp;&nbsp;</span> */
	static const Color Zomp;

	/** Color components. */
	Float	R, G, B;

	/** Creates color from component triplet. */
	Color( Float red, Float green, Float blue );

	/** Creates color from a string value. */
	Color( const lang::String& color );

	/** Creates grayscale color from a single value. */
	Color( Float gray );

	/** Creates black color. */
	Color();

	/** Returns true for identical colors. */
	Bool													operator==( const Color& other ) const;

	/** Returns true for distinct colors. */
	Bool													operator!=( const Color& other ) const;

	/** Returns this color multiplied by a scalar. */
	Color													operator*( Float value ) const;

	/** Returns this color modulated with another color. */
	Color													operator*( const Color& other ) const;

	/** Converts color to its string representation. */
	lang::String											ToString() const;

	/** Returns inversion of this color. */
	Color													Inverse() const;

	/** Returns complement of this color. */
	Color													Complementary() const;

	/** Retrieves the next well-known color. */
	static Color											GetNext( UInt& index );

	/** Returns random well-known color. */
	static Color											Random();
};


} // img


} // synkro


#endif // _SYNKRO_IMG_COLOR_
