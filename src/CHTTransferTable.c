/* FreeEMS - the open source engine management system
 *
 * Copyright 2008 Fred Cooke
 *
 * This file is part of the FreeEMS project.
 *
 * FreeEMS software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FreeEMS software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/
 *
 * We ask that if you make any changes to this file you email them upstream to
 * us at admin(at)diyefi(dot)org or, even better, fork the code on github.com!
 *
 * Thank you for choosing FreeEMS to run your engine!
 */


/**	@file CHTTransferTable.c
 * @ingroup dataInitialisers
 *
 * @brief Coolant/Head Temperature Transfer Table
 *
 * This file exists solely to contain the Coolant/Head Temperature thermistor
 * transfer function lookup table.
 *
 * @author Fred Cooke
 */


#include "inc/freeEMS.h"


/** @brief Coolant/Head Temperature Transfer Table
 *
 * Using this table it is possible to accurately and quickly convert
 * a raw ADC reading to a scaled temperature value in degrees Kelvin.
 *
 * @author FreeTherm
 */
const volatile unsigned short CHTTransferTable[1024] LOOKUPD = {
		65535, 56315, 52147, 49952, 48487, 47396, 46534, 45823, 45220, 44698, 44238, 43827, 43457, 43121, 42812, 42527,
		42263, 42016, 41786, 41569, 41365, 41171, 40988, 40814, 40648, 40489, 40337, 40192, 40052, 39918, 39789, 39664,
		39544, 39428, 39315, 39206, 39101, 38998, 38899, 38802, 38709, 38617, 38528, 38441, 38357, 38274, 38193, 38115,
		38038, 37962, 37889, 37816, 37746, 37677, 37609, 37542, 37477, 37413, 37350, 37289, 37228, 37169, 37110, 37053,
		36996, 36941, 36886, 36832, 36779, 36727, 36676, 36625, 36575, 36526, 36477, 36430, 36382, 36336, 36290, 36245,
		36200, 36156, 36112, 36069, 36027, 35985, 35943, 35903, 35862, 35822, 35782, 35743, 35705, 35666, 35629, 35591,
		35554, 35518, 35481, 35445, 35410, 35375, 35340, 35305, 35271, 35237, 35204, 35171, 35138, 35105, 35073, 35041,
		35010, 34978, 34947, 34916, 34886, 34855, 34825, 34795, 34766, 34736, 34707, 34679, 34650, 34621, 34593, 34565,
		34538, 34510, 34483, 34456, 34429, 34402, 34375, 34349, 34323, 34297, 34271, 34246, 34220, 34195, 34170, 34145,
		34120, 34096, 34071, 34047, 34023, 33999, 33975, 33951, 33928, 33904, 33881, 33858, 33835, 33812, 33790, 33767,
		33745, 33723, 33700, 33678, 33657, 33635, 33613, 33592, 33570, 33549, 33528, 33507, 33486, 33465, 33444, 33424,
		33403, 33383, 33363, 33342, 33322, 33302, 33282, 33263, 33243, 33223, 33204, 33185, 33165, 33146, 33127, 33108,
		33089, 33070, 33051, 33033, 33014, 32996, 32977, 32959, 32941, 32922, 32904, 32886, 32868, 32850, 32833, 32815,
		32797, 32780, 32762, 32745, 32727, 32710, 32693, 32676, 32659, 32642, 32625, 32608, 32591, 32574, 32558, 32541,
		32524, 32508, 32492, 32475, 32459, 32443, 32426, 32410, 32394, 32378, 32362, 32346, 32331, 32315, 32299, 32283,
		32268, 32252, 32237, 32221, 32206, 32190, 32175, 32160, 32145, 32129, 32114, 32099, 32084, 32069, 32054, 32040,
		32025, 32010, 31995, 31980, 31966, 31951, 31937, 31922, 31908, 31893, 31879, 31865, 31850, 31836, 31822, 31808,
		31793, 31779, 31765, 31751, 31737, 31723, 31710, 31696, 31682, 31668, 31654, 31641, 31627, 31613, 31600, 31586,
		31573, 31559, 31546, 31532, 31519, 31505, 31492, 31479, 31466, 31452, 31439, 31426, 31413, 31400, 31387, 31374,
		31361, 31348, 31335, 31322, 31309, 31296, 31283, 31270, 31258, 31245, 31232, 31219, 31207, 31194, 31182, 31169,
		31156, 31144, 31131, 31119, 31106, 31094, 31082, 31069, 31057, 31045, 31032, 31020, 31008, 30996, 30983, 30971,
		30959, 30947, 30935, 30923, 30911, 30899, 30887, 30875, 30863, 30851, 30839, 30827, 30815, 30803, 30791, 30780,
		30768, 30756, 30744, 30733, 30721, 30709, 30698, 30686, 30674, 30663, 30651, 30640, 30628, 30616, 30605, 30593,
		30582, 30570, 30559, 30548, 30536, 30525, 30513, 30502, 30491, 30479, 30468, 30457, 30446, 30434, 30423, 30412,
		30401, 30390, 30378, 30367, 30356, 30345, 30334, 30323, 30312, 30301, 30290, 30279, 30268, 30257, 30246, 30235,
		30224, 30213, 30202, 30191, 30180, 30169, 30158, 30147, 30136, 30126, 30115, 30104, 30093, 30082, 30072, 30061,
		30050, 30039, 30029, 30018, 30007, 29997, 29986, 29975, 29965, 29954, 29943, 29933, 29922, 29911, 29901, 29890,
		29880, 29869, 29859, 29848, 29838, 29827, 29817, 29806, 29796, 29785, 29775, 29764, 29754, 29743, 29733, 29722,
		29712, 29702, 29691, 29681, 29670, 29660, 29650, 29639, 29629, 29619, 29608, 29598, 29588, 29578, 29567, 29557,
		29547, 29536, 29526, 29516, 29506, 29495, 29485, 29475, 29465, 29455, 29444, 29434, 29424, 29414, 29404, 29393,
		29383, 29373, 29363, 29353, 29343, 29332, 29322, 29312, 29302, 29292, 29282, 29272, 29262, 29252, 29242, 29231,
		29221, 29211, 29201, 29191, 29181, 29171, 29161, 29151, 29141, 29131, 29121, 29111, 29101, 29091, 29081, 29071,
		29061, 29051, 29041, 29031, 29021, 29011, 29001, 28991, 28981, 28971, 28961, 28951, 28941, 28931, 28921, 28911,
		28901, 28891, 28881, 28871, 28861, 28851, 28841, 28831, 28821, 28812, 28802, 28792, 28782, 28772, 28762, 28752,
		28742, 28732, 28722, 28712, 28702, 28692, 28682, 28672, 28663, 28653, 28643, 28633, 28623, 28613, 28603, 28593,
		28583, 28573, 28563, 28553, 28543, 28534, 28524, 28514, 28504, 28494, 28484, 28474, 28464, 28454, 28444, 28434,
		28424, 28414, 28404, 28395, 28385, 28375, 28365, 28355, 28345, 28335, 28325, 28315, 28305, 28295, 28285, 28275,
		28265, 28255, 28245, 28235, 28225, 28215, 28205, 28195, 28185, 28175, 28165, 28155, 28145, 28135, 28125, 28115,
		28105, 28095, 28085, 28075, 28065, 28055, 28045, 28035, 28025, 28015, 28005, 27995, 27985, 27975, 27965, 27955,
		27944, 27934, 27924, 27914, 27904, 27894, 27884, 27874, 27864, 27853, 27843, 27833, 27823, 27813, 27803, 27792,
		27782, 27772, 27762, 27752, 27741, 27731, 27721, 27711, 27700, 27690, 27680, 27670, 27659, 27649, 27639, 27629,
		27618, 27608, 27598, 27587, 27577, 27567, 27556, 27546, 27536, 27525, 27515, 27504, 27494, 27483, 27473, 27463,
		27452, 27442, 27431, 27421, 27410, 27400, 27389, 27379, 27368, 27358, 27347, 27336, 27326, 27315, 27305, 27294,
		27283, 27273, 27262, 27251, 27241, 27230, 27219, 27209, 27198, 27187, 27176, 27166, 27155, 27144, 27133, 27123,
		27112, 27101, 27090, 27079, 27068, 27057, 27046, 27035, 27024, 27014, 27003, 26992, 26981, 26969, 26958, 26947,
		26936, 26925, 26914, 26903, 26892, 26881, 26869, 26858, 26847, 26836, 26825, 26813, 26802, 26791, 26779, 26768,
		26757, 26745, 26734, 26723, 26711, 26700, 26688, 26677, 26665, 26654, 26642, 26630, 26619, 26607, 26596, 26584,
		26572, 26560, 26549, 26537, 26525, 26513, 26502, 26490, 26478, 26466, 26454, 26442, 26430, 26418, 26406, 26394,
		26382, 26370, 26358, 26346, 26333, 26321, 26309, 26297, 26284, 26272, 26260, 26247, 26235, 26223, 26210, 26198,
		26185, 26173, 26160, 26147, 26135, 26122, 26109, 26097, 26084, 26071, 26058, 26045, 26032, 26019, 26007, 25994,
		25980, 25967, 25954, 25941, 25928, 25915, 25901, 25888, 25875, 25861, 25848, 25835, 25821, 25808, 25794, 25780,
		25767, 25753, 25739, 25726, 25712, 25698, 25684, 25670, 25656, 25642, 25628, 25614, 25600, 25585, 25571, 25557,
		25542, 25528, 25513, 25499, 25484, 25470, 25455, 25440, 25425, 25411, 25396, 25381, 25366, 25351, 25336, 25320,
		25305, 25290, 25275, 25259, 25244, 25228, 25212, 25197, 25181, 25165, 25149, 25133, 25117, 25101, 25085, 25069,
		25053, 25036, 25020, 25003, 24987, 24970, 24953, 24937, 24920, 24903, 24886, 24869, 24851, 24834, 24817, 24799,
		24782, 24764, 24746, 24728, 24710, 24692, 24674, 24656, 24638, 24619, 24601, 24582, 24563, 24544, 24525, 24506,
		24487, 24468, 24449, 24429, 24409, 24390, 24370, 24350, 24330, 24309, 24289, 24268, 24248, 24227, 24206, 24185,
		24164, 24142, 24121, 24099, 24077, 24055, 24033, 24011, 23988, 23965, 23943, 23920, 23896, 23873, 23849, 23826,
		23802, 23777, 23753, 23728, 23704, 23679, 23653, 23628, 23602, 23576, 23550, 23524, 23497, 23470, 23443, 23415,
		23387, 23359, 23331, 23302, 23273, 23244, 23215, 23185, 23154, 23124, 23093, 23061, 23030, 22998, 22965, 22932,
		22899, 22865, 22831, 22796, 22761, 22725, 22689, 22652, 22614, 22577, 22538, 22499, 22459, 22419, 22378, 22336,
		22293, 22250, 22206, 22161, 22115, 22068, 22021, 21972, 21922, 21872, 21820, 21766, 21712, 21656, 21599, 21540,
		21480, 21418, 21355, 21289, 21221, 21152, 21079, 21005, 20928, 20847, 20764, 20677, 20587, 20492, 20393, 20288,
		20178, 20062, 19939, 19807, 19666, 19514, 19349, 19168, 18968, 18744, 18489, 18193, 17837, 17388, 16776, 15780
};
