// Mach3Led.h

#define G92_LED					10		// G92 LED 10 
#define	SPINDLE_CW_LED			11		// Spindle CW LED 11
#define	MIST_LED				12		// Mist LED 12 
#define	FLOOD_LED				13		// Flood LED 13
#define	JOG_MODE_CONT_LED		14		// Jog mode Cont LED 14
#define	JOG_MODE_INCR_LED		15		// Jog mode Incr LED 15
#define	MACH_COORDS_WARN_LED	16		// Mach coords warn LED 16
#define	FEED_OVERRIDE_LED		17		// Feed override LED 17
#define	ESTIMATING_LED			18		// Estimating LED 18
#define	EMERGENCY_LED			19		// Emergency LED 19
#define	A_RAD_CORR_LED			20		// A radius corr. LED 20
#define	B_RAD_CORR_LED			21		// B radius corr. LED 21
#define	C_RAD_CORR_LED			22		// C radius corr. LED 22
#define	SOFT_LIMITS_LED			23		// Software limits LED 23 
#define	TORCH_ENABLE_LED		24		// Torch En LED 24

#define	TRUE_SPINDLE_ACC_LED	25		// True spindle Acc LED 25 
#define	TRUE_SPINDLE_DEC_LED	26		// True spindle Dec LED 26
#define	TOOL_PATH_LED			27		// Tool Path LED 27
#define	TOOL_OFFSET_ON_LED		28		// Tool Offset on LED 28
#define	PART_OFFSET_ON_LED		29		// Part Offset on LED (always in 6.11) 29 
#define	THROTTLE_SLOW_JOG_LED	30		// Throttle is Slow Jog LED 30
#define	THROTTLE_FEEDRATE_LED	31		// Throttle is Feedrate LED 31
										// reserved	32
#define	AUTO_LIM_OVERRIDE_LED	33		// Auto Lim override LED 33
#define	OVERRIDE_LIM_HOME_LED	34		// Override Limits/home switches LED 34
#define	SS_ON_ACT4_LED			35		// SS on Act4 LED 35
#define	THC_ARC_GOOD_LED		36		// THC Arc Good LED 36
#define	TORCH_UP_ACTIVE_LED		37		// Torch Up active LED 37
#define	TORCH_DOWN_ACTIVE_LED	38		// Torch Down active LED 38
#define	FEED_PER_REV_LED		39		// Feed per Rev LED 39
#define	FEED_PER_MIN_LED		40		// Feed per Min LED 40 
#define	X_SCALE_LED				41		// X Scale LED 41
#define	Y_SCALE_LED				42		// Y Scale LED 42
#define	Z_SCALE_LED				43		// Z Scale LED 43
#define	A_SCALE_LED				44		// A Scale LED 44
#define	B_SCALE_LED				45		// B Scale LED 45
#define	C_SCALE_LED				46		// C Scale LED 46
										// reserved	47
#define	ABS_COORD_MODE_LED		48		// Abs Coordinate Mode LED 48
#define	INC_COORD_MODE_LED		49		// Incremental Coordinate Mode LED 49 
#define	THREAD_SYNC_MODE_LED	50		// Threading Sync Mode LED (Turn) 50
#define	LASER_PROBE_EN_LED		51		// Laser Probe enabled LED 51
#define	Z_INHIBIT_ON_LED		52		// Z-Inhibit ON LED 52
#define	IGNORE_TOOL_CHG_ON_LED	53		// Ignore Tool Change ON LED 53
#define	CV_MODE_ON_LED			54		// CV Mode ON LED 54
#define	M30_REPEATS_EN_LED		55		// M30 Repeats Enabled LED 55
#define	CV_MODE_OFF_LED			56		// CV mode OFF LED 56
#define	MPG_JOG_ON_LED			57		// MPG Jog On LED 57
#define	CONT_JOG_FULL_SPD_LED	58		// Cont. Jog is at full speed LED 58
#define	MPG_1_JOGS_X_LED		59		// MPG 1 Jogs X axis LED 59
#define	MPG_1_JOGS_Y_LED		60		// MPG 1 Jogs Y axis LED 60
#define	MPG_1_JOGS_Z_LED		61		// MPG 1 Jogs Z axis LED 61
#define	MPG_1_JOGS_A_LED		62		// MPG 1 Jogs A axis LED 62
#define	MPG_1_JOGS_B_LED		63		// MPG 1 Jogs B axis LED 63  
#define	MPG_1_JOGS_C_LED		64		// MPG 1 Jogs C axis LED 64 
#define	OPTIONAL_STOP_ON_LED	65		// Optional Stop On LED 65
#define	BLOCK_DEL_ON_LED		66		// Block Delete On LED 66
#define	OFFLINE_IND_ON_LED		67		// Offline indicator LED 67
#define	THREAD_SPD_TR_SPIN_LED	68		// Threading feed related to true Spindle speed LED 68

#define	IDX_SIG_AWAITED_LED		69		// Index signal awaited LED (Turn) 69  
#define	ANTI_DIVE_EN_LED		70		// Anti-dive enabled LED 70  
#define	SPIN_SPD_STABLE_LED		71		// Spindle speed stable LED 71  
#define	IJ_MODE_ABS_LED			72		// IJ Mode is Absolute LED 72  
#define	IJ_MODE_INC_LED			73		// IJ Mode is Incremental LED 73  
#define	GCODE_TEACH_OPEN_LED	74		// G-code teaching file is open LED 74  
#define	OFF_ATLEAST_ONEAXIS_LED	75		// Offset in effect on at least one axis LED 75  
										// reserved 76  
#define	OUTPUT_4_ACTIVE_LED		77		// Output 4 Active LED 77  
#define	OUTPUT_5_ACTIVE_LED		78		// Output 4 Active LED 78  
#define	OUTPUT_6_ACTIVE_LED		79		// Output 4 Active LED 79  
#define	PAUSE_ACTIVE_LED		80		// Pause Active LED 80  
#define	TAN_CTRL_ACTIVE_LED		81		// Tangential control Active LED 81  
#define	SNGL_STEP_ACTIVE_LED	82		// Single Step mode Active LED 82  
#define	JOGGING_ENABLED_LED		83		// Jogging enabled LED 83  
#define	CV_FEED_ENABLED_LED		84		// CV feed enabled LED 84  
#define	NOT_ENHANCED_PULSE_LED	85		// Enhanced Pulsing NOT in use LED 85  
#define	X_INHIBITED_LED			86		// Axis inhibited X LED 86  
#define	Y_INHIBITED_LED			87		// Axis inhibited X LED 86  
#define	Z_INHIBITED_LED			88		// Axis inhibited X LED 86  
#define	A_INHIBITED_LED			89		// Axis inhibited X LED 86  
#define	B_INHIBITED_LED			90		// Axis inhibited X LED 86  
#define	C_INHIBITED_LED			91		// Axis inhibited X LED 86  

#define	DIA_MODE_ACTIVE_LED		92		// Diameter mode active (Turn) LED 92  
#define	TIMING_SIG_ACTIVE_LED	93		// Timing signal active (Turn) LED 93  
#define	HOTKEYS_ENABLED_LED		94		// Hotkeys enabled LED 94  
#define	UNITS_PER_MIN_LED		95		// Units per minute mode LED 95  
#define	UNITS_PER_REV_LED		96		// Units per rev mode LED 96  
#define	RUNNING_REVERSE_LED		97		// Running in reverse (duplicated by 112) LED 97  
#define	MPG2_JOGS_X_LED			98		// MPG 2 Jogs X axis LED 98  
#define	MPG2_JOGS_Y_LED			99		// MPG 2 Jogs Y axis LED 99  
#define	MPG2_JOGS_Z_LED			100		// MPG 2 Jogs Z axis LED 100  
#define	MPG2_JOGS_A_LED			101		// MPG 2 Jogs A axis LED 101 
#define	MPG2_JOGS_B_LED			102		// MPG 2 Jogs B axis LED 102 
#define	MPG2_JOGS_C_LED			103		// MPG 2 Jogs C axis LED 103 

#define	MPG2_TAPER_MODE_LED		104		// MPG 2 in taper mode LED 104  
#define	TWO_MPGS_INUSE_LED		105		// Two MPGs in use LED 105  
#define	SHUTTLE_MODE_INUSE_LED	106		// Shuttle mode in use LED 106  
#define	SPINDLE_G96_CSS_LED		107		// Spindle is in CSS (G96) mode LED 107  
#define	XY_COORDS_ROTATED_LED	108		// X/Y coordinate system is currently rotated LED 108  
#define	RAPIDS_OVERRIDDEN_LED	109		// Rapids being overidden LED 109  
#define	AXIS_FORMULA_MAP_LED	110		// Axis formula mapping ON LED 110  
#define	FH_REMAIN_PEND_LED		111		// Feedhold when part of a block executed - remainder pending LED 111  
#define	RUNNIG_REVERSE2_LED		112		// Running in reverse (duplicate) LED - do not use 112  
#define	ALT_FEED_DRO122_LED		113		// Alternative feedrate in use (see OEM DRO 122) LED 113  
#define	FRONT_TP_SEL_LED		114		// Front tool post selected LED 114  
#define	REAR_TP_SEL_LED			115		// Rear tool post selected LED 115  
#define	SPINDLE_RUNNING_LED		116		// Spindle is running LED 116  
#define	MPG_JOG_VEL_MODE_LED	117		// MPG jog Velocity mode selected LED 117  
#define	MPG_JOG_VEL_STEP_LED	118		// MPG jog Velocity/Step mode selected LED 118  
#define	MPG_JOG_SNGL_EXACT_LED	119		// MPG jog single exact step mode selected LED 119  
#define	MPG_JOG_MULT_LED		120		// MPG jog multiple steps selected LED 120  
#define	X_PLUS_JOGSW_ACT_LED	121		// X++ jogging switch active LED 121  
#define	X_MINUS_JOGSW_ACT_LED	122		// X-- jogging switch active LED 122  
#define	Y_PLUS_JOGSW_ACT_LED	123		// X++ jogging switch active LED 121  
#define	Y_MINUS_JOGSW_ACT_LED	124		// X-- jogging switch active LED 122  
#define	Z_PLUS_JOGSW_ACT_LED	125		// X++ jogging switch active LED 121  
#define	Z_MINUS_JOGSW_ACT_LED	126		// X-- jogging switch active LED 122  
#define	A_PLUS_JOGSW_ACT_LED	127		// X++ jogging switch active LED 121  
#define	A_MINUS_JOGSW_ACT_LED	128		// X-- jogging switch active LED 122  
#define	MOUSE_ZOOMS_TP_LED		129		// Mouse in tool path Zooms LED 129  
#define	MOUSE_PANS_TP_LED		130		// Mouse in tool path Pans LED 130  

/* ??????
#define	MPG3_JOGS_X_LED			// MPG 3 Jogs X axis LED 130  
// MPG 3 Jogs Y axis LED 131  
// MPG 3 Jogs Z axis LED 132  
// MPG 3 Jogs A axis LED 133  
// MPG 3 Jogs B axis LED 134  
// MPG 3 Jogs C axis LED 135  
// MPG 3 Jogs X axis LED 130  
*/
										// reserved 130 - 161  

#define	MACRO_RUNNING_LED		162		// A macro is running LED 162  
#define	AXIS_DRO_DIST_TOGO_LED	163		// Distance to go display in Axis DROs LED 163  
#define	SPINDLE_ROT_CW_LED		164		// Spindle rotating CW LED 164  
#define	SPINDLE_ROT_CCW_LED		165		// Spindle rotating CCW LED 165  
#define	ABNORMAL_COND_LED		166		// Conditions are abnormal LED 166  
										// reserved 167  
#define	CV_DIST_TOL_ON_LED		168		// CV Distance tolerance is ON LED 168  

#define	RESET_LED				800		// Reset LED 800  
#define	INCH_LED				801		// Inch LED 801  
#define	MM_LED					802		// MMs LED 802  
#define	IDLE_LED				803		// Idle LED 803  
#define	START_LED				804		// Start LED 804  
#define	PAUSE_LED				805		// Pause LED 805  
#define	TOOL_CHG_LED			806		// Tool change LED 806  
#define	X_REF_LED				807		// X ref LED 807  
#define	Y_REF_LED				808		// X ref LED 808  
#define	Z_REF_LED				809		// X ref LED 809  
#define	A_REF_LED				810		// X ref LED 810  
#define	B_REF_LED				811		// X ref LED 811  
#define	C_REF_LED				812		// X ref LED 812  
#define	DWELL_LED				813		// Dwell LED 813  
#define	JOYSTICK_EN_LED			814		// Joystick enable LED 814  
										// reserved 815
#define	FIXTURE_LED				816		// Fixture LED 816  
										// reserved 817-820
#define	ACTIVE_1_LED			821		// Active 1 LED 821  
#define	ACTIVE_2_LED			822		// Active 2 LED 822  
#define	ACTIVE_3_LED			823		// Active 3 LED 823  
#define	ACTIVE_4_LED			824		// Active 4 LED 824  
#define	DIGITIZE_IN_LED			825		// Digitise In LED 825  
#define	INDEX_LED				826		// Index LED 826  
#define	LIMIT_OV_LED			827		// Limit OV LED 827  
#define	X_PLUS_LIMIT_LED		828		// X++ Limit LED 828  
#define	X_MINUS_LIMIT_LED		829		// X-- Limit LED 829  
#define X_MINUS_HOME_LED		830		// X-- Home LED 830  
#define	Y_PLUS_LIMIT_LED		831		// X++ Limit LED 831  
#define	Y_MINUS_LIMIT_LED		832		// X-- Limit LED 832  
#define Y_MINUS_HOME_LED		833		// X-- Home LED 833 
#define	Z_PLUS_LIMIT_LED		834		// X++ Limit LED 834  
#define	Z_MINUS_LIMIT_LED		835		// X-- Limit LED 835  
#define Z_MINUS_HOME_LED		836		// X-- Home LED 836 
#define	A_PLUS_LIMIT_LED		837		// X++ Limit LED 827  
#define	A_MINUS_LIMIT_LED		838		// X-- Limit LED 838  
#define A_MINUS_HOME_LED		839		// X-- Home LED 839  
#define	B_PLUS_LIMIT_LED		840		// X++ Limit LED 840  
#define	B_MINUS_LIMIT_LED		841		// X-- Limit LED 841  
#define B_MINUS_HOME_LED		842		// X-- Home LED 842 
#define	C_PLUS_LIMIT_LED		843		// X++ Limit LED 843  
#define	C_MINUS_LIMIT_LED		844		// X-- Limit LED 844  
#define C_MINUS_HOME_LED		845		// X-- Home LED 845  
#define	ENABLE_1_LED			846		// Enable 1 LED 846  
#define	ENABLE_2_LED			847		// Enable 1 LED 847  
#define	ENABLE_3_LED			848		// Enable 1 LED 848  
#define	ENABLE_4_LED			849		// Enable 1 LED 849  
#define	ENABLE_5_LED			850		// Enable 1 LED 850  
#define	ENABLE_6_LED			851		// Enable 1 LED 851  
#define	OUTPUT_1_LED			852		// Output 1/Extrn1 Active LED 852  
#define	OUTPUT_2_LED			853		// Output 2/Extrn2 Active LED 853  
#define	OUTPUT_3_LED			854		// Output 3/Extrn3 Active LED 854 
#define	DIGITIZE_OUT_LED		855		// Digitise Out LED 855  

#define	SYS_MOVING_LED			999		// System movement in effect or movement imminent LED 999  


