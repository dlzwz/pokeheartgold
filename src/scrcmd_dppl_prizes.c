#include "scrcmd.h"

static const u16 sDPPlGameCornerPrizeMap[][2] = {
    { ITEM_SILK_SCARF, 10    },
    { ITEM_WIDE_LENS,  10    },
    { ITEM_ZOOM_LENS,  10    },
    { ITEM_METRONOME,  10    },
    { ITEM_TM90,       20    },
    { ITEM_TM58,       20    },
    { ITEM_TM75,       40    },
    { ITEM_TM32,       40    },
    { ITEM_TM44,       60    },
    { ITEM_TM89,       60    },
    { ITEM_TM10,       60    },
    { ITEM_TM27,       80    },
    { ITEM_TM21,       80    },
    { ITEM_TM35,       100   },
    { ITEM_TM24,       100   },
    { ITEM_TM13,       100   },
    { ITEM_TM29,       100   },
    { ITEM_TM74,       150   },
    { ITEM_TM68,       200   },
};

BOOL ScrCmd_GetDPPlPrizeItemIdAndCost(ScriptContext *ctx) {
    u16 prize_id = ScriptGetVar(ctx);
    u16 *prize_item_id = ScriptGetVarPointer(ctx);
    u16 *prize_cost = ScriptGetVarPointer(ctx);

    *prize_item_id = sDPPlGameCornerPrizeMap[prize_id][0];
    *prize_cost = sDPPlGameCornerPrizeMap[prize_id][1];

    return FALSE;
}
