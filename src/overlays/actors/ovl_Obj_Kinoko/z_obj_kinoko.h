#ifndef Z_OBJ_KINOKO_H
#define Z_OBJ_KINOKO_H

#include "global.h"

struct ObjKinoko;

typedef struct ObjKinoko {
    /* 0x000 */ Actor actor;
} ObjKinoko; // size = 0x144

extern const ActorInit Obj_Kinoko_InitVars;

#endif // Z_OBJ_KINOKO_H
