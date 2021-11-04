#include <superkarel.h>

void goTo();
void turn_right();
void take_beeper();

int main(){
    turn_on("task_2.kw");
    set_step_delay(10);
    
    while(!beepers_present()){
        goTo();
    }
    pick_beeper();
    turn_left();
 
    do{
        step();
        if(front_is_blocked()){
            turn_right();
        }
    }while(front_is_clear());
    turn_right();
    turn_off();
    return 0;
}

void goTo(){

    while(front_is_clear() && !beepers_present()){
        take_beeper();
        step();
    }
    turn_left();
}

void take_beeper()
{
    if (beepers_present())
        pick_beeper();
}

void turn_right(){
    for(int i=0; i<3; i++){
       turn_left();
   }
}

