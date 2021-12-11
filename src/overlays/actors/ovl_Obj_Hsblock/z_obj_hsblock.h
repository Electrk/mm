#ifndef Z_OBJ_HSBLOCK_H
#define Z_OBJ_HSBLOCK_H

#include "global.h"

struct ObjHsblock;

typedef void (*ObjHsblockActionFunc)(struct ObjHsblock*, GlobalContext*);

#define OBJHSBLOCK_GET_3(thisx) ((thisx)->dyna.actor.params & 3)
#define OBJHSBLOCK_GET_20(thisx) (((thisx)->dyna.actor.params >> 5) & 1)
#define OBJHSBLOCK_GET_C0(thisx) (((thisx)->dyna.actor.params >> 6) & 3)
#define OBJHSBLOCK_GET_7F00(thisx) (((thisx)->dyna.actor.params >> 8) & 0x7F)

typedef struct ObjHsblock {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x015C */ ObjHsblockActionFunc actionFunc;
} ObjHsblock; // size = 0x160

extern const ActorInit Obj_Hsblock_InitVars;

#endif // Z_OBJ_HSBLOCK_H
