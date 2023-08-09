#include"recv_gamepad_val.hpp"

int main(){
    InitCon();
    InitSerial();
    while(1){
        if(RecvCount >= 1){
            /*適当な処理*/
            RecvCount--;
        }
        sleep_for(500);
    }
}