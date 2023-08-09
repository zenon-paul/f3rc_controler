#ifndef RECV_INCLUDE
#define RECV_INCLUDE
#include<mbed.h>
#include<stdio.h>
#include<string.h>

asm(".global _printf_float");
using ThisThread::sleep_for;

#define RATE 115200
#define BUFFER_SIZE 64
#define STICK_MAX 512.0
#define ALL_BUTTONS 12
#define RECEIVED 1
#define NOT_RECEIVED 0

struct t_gamepad{
    double stick_l[2];
    double stick_r[2];
    int dpad;
    int buttons[ALL_BUTTONS];
};

extern t_gamepad Con;
extern unsigned int RecvCount;

void InitCon();
void InitSerial();

#endif