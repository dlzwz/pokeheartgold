#include "constants/scrcmd.h"
#include "fielddata/script/scr_seq/event_T25R1004.h"
#include "msgdata/msg/msg_0595_T25R1004.h"
	.include "asm/macros/script.inc"

	.rodata

	scrdef scr_seq_T25R1004_000
	scrdef scr_seq_T25R1004_001
	scrdef scr_seq_T25R1004_002
	scrdef scr_seq_T25R1004_003
	scrdef scr_seq_T25R1004_004
	scrdef_end

scr_seq_T25R1004_000:
	play_se SEQ_SE_DP_SELECT
	lockall
	faceplayer
	callstd std_mart_intro
	holdmsg
	setvar VAR_SPECIAL_x8004, 6
	callstd std_special_mart
	releaseall
	end

scr_seq_T25R1004_001:
	play_se SEQ_SE_DP_SELECT
	lockall
	faceplayer
	compare VAR_SCENE_ROCKET_TAKEOVER, 3
	goto_if_ne _0050
	npc_msg msg_0595_T25R1004_00001
	goto _0053

_0050:
	npc_msg msg_0595_T25R1004_00000
_0053:
	wait_button_or_walk_away
	closemsg
	releaseall
	end

scr_seq_T25R1004_002:
	play_se SEQ_SE_DP_SELECT
	lockall
	faceplayer
	compare VAR_SCENE_ROCKET_TAKEOVER, 3
	goto_if_ne _0079
	npc_msg msg_0595_T25R1004_00003
	goto _007C

_0079:
	npc_msg msg_0595_T25R1004_00002
_007C:
	wait_button_or_walk_away
	closemsg
	releaseall
	end

scr_seq_T25R1004_003:
	play_se SEQ_SE_DP_SELECT
	lockall
	faceplayer
	compare VAR_SCENE_ROCKET_TAKEOVER, 3
	goto_if_ne _T25R1004_003_main
	npc_msg msg_0595_T25R1004_00005
	wait_button_or_walk_away
	closemsg
	releaseall
	end

_T25R1004_003_main:
	npc_msg msg_0595_T25R1004_00004
	touchscreen_menu_hide
	getmenuchoice VAR_SPECIAL_RESULT
	touchscreen_menu_show
	compare VAR_SPECIAL_RESULT, 0
	goto_if_eq _T25R1004_003_select
	goto _T25R1004_003_no

_T25R1004_003_select:
	closemsg
	fade_screen 6, 1, 0, RGB_BLACK
	wait_fade
	scrcmd_566
	get_party_selection VAR_SPECIAL_RESULT
	restore_overworld
	fade_screen 6, 1, 1, RGB_BLACK
	wait_fade
	compare VAR_SPECIAL_RESULT, 255
	goto_if_eq _T25R1004_003_no
	copyvar VAR_SPECIAL_x8004, VAR_SPECIAL_RESULT
	buffer_mon_species_name 0, VAR_SPECIAL_x8004
	npc_msg msg_0595_T25R1004_00007
	touchscreen_menu_hide
	getmenuchoice VAR_SPECIAL_RESULT
	touchscreen_menu_show
	compare VAR_SPECIAL_RESULT, 0
	goto_if_eq _T25R1004_003_do
	goto _T25R1004_003_no

_T25R1004_003_do:
	closemsg
	reset_mon_evs VAR_SPECIAL_x8004
	npc_msg msg_0595_T25R1004_00008
	wait_button_or_walk_away
	closemsg
	releaseall
	end

_T25R1004_003_no:
	npc_msg msg_0595_T25R1004_00009
	wait_button_or_walk_away
	closemsg
	releaseall
	end

scr_seq_T25R1004_004:
	play_se SEQ_SE_DP_SELECT
	lockall
	npc_msg msg_0595_T25R1004_00006
	wait_button_or_walk_away
	closemsg
	releaseall
	end
	.balign 4, 0
