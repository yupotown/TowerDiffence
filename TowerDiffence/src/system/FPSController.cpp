
#include "FPSController.h"
#include <DxLib.h>
#include <string>
#include <sstream>

FPSController::FPSController()
:fps(60),
real_fps(0),
prev_count(DxLib::GetNowCount()),
remaining_frames(fps) {
}

FPSController::FPSController(int fps)
:fps(fps),
real_fps(0),
prev_count(DxLib::GetNowCount()),
remaining_frames(fps) {
}

FPSController::~FPSController() {
}

void FPSController::SetFPS(int fps) {
	if (fps>0) {
		this->fps = fps;
		remaining_frames = fps;
	}
}

int FPSController::GetFPS() const {
	return fps;
}

int FPSController::GetRealFPS() const {
	return real_fps;
}

void FPSController::Update() {
	const int nowCount = DxLib::GetNowCount();
	// Ÿ‚Ì‹æØ‚è‚Ü‚Å‚Ìƒ~ƒŠ•b”
	const int remaining_time = prev_count + 1000 - nowCount;
	--remaining_frames;
	if (remaining_time <= 0) {
		real_fps = fps - remaining_frames;
		remaining_frames = fps;
		prev_count = nowCount;
	}
	//debug
	//{
	//	std::stringstream ss;
	//	ss << "(" << (fps - remaining_frames) << "/" << fps << ")";
	//	DxLib::DrawBox(60, 0, 100, 20, DxLib::GetColor(0, 0, 0), TRUE);
	//	DxLib::DrawString(60, 0, ss.str().c_str(), DxLib::GetColor(0, 0, 255));
	//}
	if (remaining_frames == 0)
		return;
	const int wait_time = remaining_time / remaining_frames;
	if (wait_time > 0)
		DxLib::WaitTimer(wait_time);
}
