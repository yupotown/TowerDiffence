
#pragma once

class FPSController {
public:
	FPSController();
	FPSController(int fps);
	~FPSController();

	void SetFPS(int fps);
	int GetFPS() const;
	int GetRealFPS() const;

	void Update();

private:
	FPSController(const FPSController& rhs);
	const FPSController& operator =(const FPSController& rhs);

	int fps, real_fps;
	int prev_count;
	int remaining_frames;
};
