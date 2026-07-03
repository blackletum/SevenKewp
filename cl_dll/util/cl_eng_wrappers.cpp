#include "cl_dll.h"
#include "cl_util.h"
#include "cl_eng_wrappers.h"

tempent_s* CL_TentEntAllocCustom(const float* origin, int modelindex, int high, tent_callback callback) {
	model_s* model = gEngfuncs.hudGetModelByIndex(modelindex);

	if (!model) {
		return NULL;
	}

	tempent_s* ent = gEngfuncs.pEfxAPI->CL_TentEntAllocCustom(origin, model, high, callback);

	ent->entity.curstate.modelindex = modelindex;
	if (is_software_renderer && g_broken_software_sprites[modelindex]) {
		ent->flags |= FTENT_CUSTOM_SPR_RENDER;
	}

	return ent;
}

tempent_s* CL_TentEntAllocCustom(const float* origin, model_s* model, int high, tent_callback callback) {
	tempent_s* ent = gEngfuncs.pEfxAPI->CL_TentEntAllocCustom(origin, model, high, callback);
	
	ent->entity.curstate.modelindex = MODEL_INDEX(model->name);
	if (is_software_renderer && g_broken_software_sprites[ent->entity.curstate.modelindex]) {
		ent->flags |= FTENT_CUSTOM_SPR_RENDER;
	}
	
	return ent;
}