
#include "debug_scene.h"
#include <DxLib.h>
#include <cmath>

// next scenes
#include "debug_scene2.h"

namespace Scene {

DebugScene::DebugScene() {
}

DebugScene::~DebugScene() {
}

Base *DebugScene::Update() {
	if (DxLib::CheckHitKey(KEY_INPUT_A)) {
		return new DebugScene2();
	}
	x = static_cast< int >(std::cos(t * n) * 100);
	y = static_cast< int >(std::sin(t * m) * 100);
	t += 1.0 / 60.0;
	return this;
}

void DebugScene::Draw() {
	DxLib::DrawBox(0, 0, 640, 100, DxLib::GetColor(0, 0, 0), TRUE);
	DxLib::DrawGraph(0, 0, graph_debug.GetHandle(), FALSE);
	DxLib::DrawCircle(x + 320, y + 240, 3, DxLib::GetColor(0, 0, 255));
}

void DebugScene::Initialize() {
	graph_debug.Load("../TowerDiffence/data/debug.bmp");
	n = 1;
	m = 1.8;
	t = 0;
	x = static_cast< int >(std::cos(t * n) * 100);
	y = static_cast< int >(std::sin(t * m) * 100);
	DxLib::DrawBox(0, 0, 640, 480, DxLib::GetColor(0, 0, 0), TRUE);
}

}
