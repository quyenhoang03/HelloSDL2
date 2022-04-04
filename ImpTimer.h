//
// Created by Quyen on 4/5/2022.
//

#ifndef HELLOSDL2_IMPTIMER_H
#define HELLOSDL2_IMPTIMER_H

class ImpTimer {
public:
    ImpTimer();

    ~ImpTimer();

    void start();

    void stop();

    void paused();

    void unpaused();

    int get_ticks();

    bool is_started();

    bool is_paused();

private:
    int start_tick_;
    int paused_tick_;

    bool is_paused_;
    bool is_started_;
};

#endif //HELLOSDL2_IMPTIMER_H
