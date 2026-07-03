#pragma once
struct tempent_s;

typedef void (*tent_callback)(tempent_s* ent, float frametime, float currenttime);

tempent_s* CL_TentEntAllocCustom(const float* origin, int modelindex, int high, tent_callback callback);
tempent_s* CL_TentEntAllocCustom(const float* origin, model_s* model, int high, tent_callback callback);