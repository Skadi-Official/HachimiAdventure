#pragma once

#include <functional>

class Timer
{
public:
	Timer() = default;
	~Timer() = default;

	void restart()
	{
		pass_time = 0;
		shotted = false;
	}

	void set_wait_time(float val)
	{
		wait_time = val;
	}

	void set_one_shot(bool flag)
	{
		on_shot = flag;
	}

	void set_on_timeout(std::function<void()> on_timeout)
	{
		this->on_timeout = on_timeout;
	}

	void pause()
	{
		paused = true;
	}

	void resume()
	{
		paused = false;
	}

	void on_update(float delta)
	{
		if (paused) return;

		pass_time += delta;
		if (pass_time >= wait_time)
		{
			bool can_shot = false;
			if (on_shot == false || (on_shot == true && shotted == false))
			{
				can_shot = true;
			}
		}
	}
private:
	float pass_time = 0;
	float wait_time = 0;
	bool paused = false;
	bool shotted = false;
	bool on_shot = false;
	std::function<void()> on_timeout;

};