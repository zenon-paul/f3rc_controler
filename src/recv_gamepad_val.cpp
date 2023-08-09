#include"recv_gamepad_val.hpp"

t_gamepad Con;
static UnbufferedSerial RecvSerial(D1,D0);
unsigned int RecvCount;
char buf;
char RecvBuffer[BUFFER_SIZE];
int RecvData[6] = {0};

void received(){//受信割込み    
    RecvCount++;
    int i = 0;
    while(1){
        RecvSerial.read(&buf,1);
        if((i>=BUFFER_SIZE)||(buf == '\n')){
            break;
        }
        RecvBuffer[i] = buf;
        i++;
    }
    RecvBuffer[i] = '\n';
    sscanf(RecvBuffer,"%d,%d,%d,%d,%d,%d\n",&RecvData[0],&RecvData[1],&RecvData[2],&RecvData[3],&RecvData[4],&RecvData[5]);
    Con.stick_l[0] = RecvData[0]/STICK_MAX;
    Con.stick_l[1] = RecvData[1]/STICK_MAX;
    Con.stick_r[0] = RecvData[2]/STICK_MAX;
    Con.stick_r[1] = RecvData[3]/STICK_MAX;
    Con.dpad = RecvData[4];
    for(int j = 0;j<ALL_BUTTONS;j++){
        Con.buttons[j] = (RecvData[5]>>j)&1;
    }
    memset(RecvBuffer,'\0',BUFFER_SIZE);
}


void InitCon(){
    memset(&Con,0,sizeof(t_gamepad));
}

void InitSerial(){
    RecvSerial.baud(RATE);
    RecvSerial.attach(received,SerialBase::RxIrq);
    RecvSerial.format(8,SerialBase::None,1);
    memset(RecvBuffer,'\0',BUFFER_SIZE);
}
