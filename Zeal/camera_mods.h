#pragma once
#include "memory.h"
#include <chrono>
#include "vectors.h"

class CameraMods
{
public:
	std::chrono::steady_clock::time_point prevTime; 
	float sensitivity_x = 0.7f;
	float sensitivity_y = 0.4f;
	int eq_ptr = 0;
	bool smoothing;
	float height;
	float fps;
	float current_zoom = 0;
	float zoom_speed = 5.f;
	void set_smoothing(bool val);
	void callback_main();
	bool update_cam(); //returns true on collision
	void mouse_wheel(int delta);
	void update_zoom(float zoom);
	void toggle_zeal_cam(bool enabled);
	void proc_mouse();
	void reset_cam();
	CameraMods(class ZealService* pHookWrapper);
	~CameraMods();
private:

	POINT previous_mouse_pos;
	Vec2 mouse_delta;
	BYTE original_cam[6] = { 0 };
	std::chrono::steady_clock::time_point lastTime;
};
	
