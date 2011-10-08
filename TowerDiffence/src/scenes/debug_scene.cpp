
#include "debug_scene.h"
#include <boost/make_shared.hpp>
#include <DxLib.h>

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
	return this;
}

void DebugScene::Draw() {
	DxLib::DrawBox(0, 0, 640, 480, DxLib::GetColor(0, 0, 0), TRUE);
}

}
