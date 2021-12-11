/*
 * File: z_obj_hsblock.c
 * Overlay: ovl_Obj_Hsblock
 * Description: Hookshot Block
 */

#include "z_obj_hsblock.h"

#define FLAGS 0x00000000

#define THIS ((ObjHsblock*)thisx)

void ObjHsblock_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjHsblock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjHsblock_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjHsblock_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8093E0A0(ObjHsblock* this, GlobalContext* globalCtx);

void ObjHsblock_SetupAction(ObjHsblock* this, ObjHsblockActionFunc actionFunc);

const ActorInit Obj_Hsblock_InitVars = {
    ACTOR_OBJ_HSBLOCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_D_HSBLOCK,
    sizeof(ObjHsblock),
    (ActorFunc)ObjHsblock_Init,
    (ActorFunc)ObjHsblock_Destroy,
    (ActorFunc)ObjHsblock_Update,
    (ActorFunc)ObjHsblock_Draw,
};

// static InitChainEntry sInitChain[] = {
static InitChainEntry D_8093E33C[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 200, ICHAIN_STOP),
};

UNK_TYPE D_8093E330[] = { 0x42AA0000, 0x42AA0000, 0x00000000 };
CollisionHeader* D_8093E34C[] = { 0x06000730, 0x06000730, 0x06000578 };
UNK_TYPE D_8093E358[] = { 0x06000210, 0x06000210, 0x06000470 };
UNK_TYPE D_8093E364[] = { 0x3C3C7878, 0x64466496, 0x78FFFFFF };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/ObjHsblock_SetupAction.s")

void func_8093DEAC(ObjHsblock* this, GlobalContext* globalCtx) {
    if (OBJHSBLOCK_GET_20(this)) {
        Actor_SpawnAsChild(
            &globalCtx->actorCtx,
            &this->dyna.actor,
            globalCtx,
            ACTOR_OBJ_ICE_POLY,
            this->dyna.actor.world.pos.x,
            this->dyna.actor.world.pos.y,
            this->dyna.actor.world.pos.z,
            this->dyna.actor.world.rot.x,
            this->dyna.actor.world.rot.y,
            this->dyna.actor.world.rot.z,
            0xFF64
        );
    }
}

void ObjHsblock_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjHsblock* this = THIS;

    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(globalCtx, &this->dyna, D_8093E34C[OBJHSBLOCK_GET_3(this)]);
    Actor_ProcessInitChain(&this->dyna.actor, D_8093E33C);

    func_8093DEAC(this, globalCtx);

    // This is needed to match
    if (0) {}

    switch (OBJHSBLOCK_GET_3(this)) {
        case 0:
        case 2:
            func_8093E03C(this);
            break;

        case 1:
            if (Flags_GetSwitch(globalCtx, OBJHSBLOCK_GET_7F00(this))) {
                func_8093E03C(this);
                return;
            }

            func_8093E05C(this);
            break;
    }
}

void ObjHsblock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjHsblock* this = THIS;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, this->dyna.bgId);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/func_8093E03C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/func_8093E05C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/func_8093E0A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/func_8093E0E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/func_8093E10C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/ObjHsblock_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Hsblock/ObjHsblock_Draw.s")
