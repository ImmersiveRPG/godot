

#ifndef STOP_WATCH_H
#define STOP_WATCH_H

#include <cstdint>

struct StopWatch {
	static uint64_t _input_used;
	static uint64_t _phy_used;
	static uint64_t _navigation_used;
	static uint64_t _physics_process_fn_used;
	static uint64_t _process_fn_used;
	static uint64_t _call_deferred_used;
	static uint64_t _timers_used;
	static uint64_t _tweens_used;
	static uint64_t _draw_used;

	uint64_t _start_ticks;
	StopWatch();

	void start();
	uint64_t stop();
	uint64_t clamp_uint64(uint64_t v, uint64_t lo, uint64_t hi);
};

#endif // STOP_WATCH_H
