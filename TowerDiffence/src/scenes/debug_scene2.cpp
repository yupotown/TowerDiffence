
#include "debug_scene2.h"
#include <DxLib.h>

// next scenes
#include "debug_scene.h"

namespace Scene {

DebugScene2::DebugScene2() {
}

DebugScene2::~DebugScene2() {
}

Base *DebugScene2::Update() {
	if (DxLib::CheckHitKey(KEY_INPUT_B))
		return new DebugScene();
	return this;
}

void DebugScene2::Draw() {
	DxLib::DrawBox(0, 0, 640, 480, DxLib::GetColor(255, 255, 255), TRUE);
	DxLib::DrawGraph(160, 120, graph_debug.GetHandle(), FALSE);
}

void DebugScene2::Initialize() {
	graph_debug.Load("../TowerDiffence/data/debug.bmp");
}

}
