#include "EyeBone.h"

#include <cstdlib>

EyeBone::EyeBone(int port): UdpReceiver(port, "EyeBone"){
}

EyeBone::~EyeBone() {
}

int EyeBone::parsePacket(char* recv_buffer, int received_bytes) {
    char* end = recv_buffer;
    double next;
    for(int i = 0; i < 5; i++){
        next=strtod(end,&end);
        parsed[i] = next;
    }
    return 0;
}

double EyeBone::getTargetX() {
    return parsed[0];
}

double EyeBone::getTargetY() {
    return parsed[1];
}

double EyeBone::getTargetWidth() {
    return parsed[2];
}

double EyeBone::getTargetHeight() {
    return parsed[3];
}

double EyeBone::getTargetAngle() {
    return parsed[4];
}
