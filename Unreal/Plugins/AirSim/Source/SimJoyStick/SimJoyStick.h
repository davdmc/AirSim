// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <cstdint>
#include <memory>

class SimJoyStick
{
public:
    struct State {
        short left_x, left_y, right_x, right_y;
        bool left_trigger, right_trigger;
        unsigned short buttons;
        bool is_connected;
    };

    static void setEnabled(bool enabled);

    void getJoyStickState(unsigned int index, State& state);

    SimJoyStick();
    ~SimJoyStick();    //required for pimpl
private:
    static bool enabled_;

    struct impl;
    std::unique_ptr<impl> pimpl_;
};
