#pragma once

static constexpr int CAMERA_ORIGINAL_X = 0;
static constexpr int CAMERA_ORIGINAL_Y = 0;

class Camera {
public:
	unsigned long x;
	unsigned long y;
	Camera();
	~Camera();

	inline void reset() {
		x = CAMERA_ORIGINAL_X;
		y = CAMERA_ORIGINAL_Y;
	}
};
