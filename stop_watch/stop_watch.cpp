

#include "stop_watch/stop_watch.h"
#include "core/os/os.h"

uint64_t StopWatch::_input_used = 0;
uint64_t StopWatch::_phy_used = 0;
uint64_t StopWatch::_navigation_used = 0;
uint64_t StopWatch::_physics_process_fn_used = 0;
uint64_t StopWatch::_process_fn_used = 0;
uint64_t StopWatch::_call_deferred_used = 0;
uint64_t StopWatch::_physics_timers_used = 0;
uint64_t StopWatch::_process_timers_used = 0;
uint64_t StopWatch::_physics_tweens_used = 0;
uint64_t StopWatch::_process_tweens_used = 0;
uint64_t StopWatch::_draw_used = 0;

StopWatch::StopWatch() {
	this->start();
}

void StopWatch::start() {
	_start_ticks = OS::get_singleton()->get_ticks_usec();
}

uint64_t StopWatch::stop() {
	uint64_t end_ticks = OS::get_singleton()->get_ticks_usec();
	uint64_t ticks = this->clamp_uint64(end_ticks - _start_ticks, 0, UINT64_MAX);
	return ticks;
}

// FIXME: Replace this with standard clamp function
uint64_t StopWatch::clamp_uint64(uint64_t v, uint64_t lo, uint64_t hi) {
	if (v < lo) {
		return lo;
	} else if (v > hi) {
		return hi;
	} else {
		return v;
	}
}