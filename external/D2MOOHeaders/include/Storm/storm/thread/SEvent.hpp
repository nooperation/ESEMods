#ifndef STORM_THREAD_S_EVENT_HPP
#define STORM_THREAD_S_EVENT_HPP

#include "storm/thread/SSyncObject.hpp"
#include <cstdint>

class SEvent : public SSyncObject {
    public:
    // Member functions
    SEvent(int32_t manualReset, int32_t initialValue);
    int32_t Reset();
    int32_t Set();
};

#endif
