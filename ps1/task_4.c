#include <superkarel.h>

void turn_right();
void make_wall();
void put_beeper2();
void check_create_wall();

int main(){

    turn_on("task_4.kw");
    set_step_delay(350);
    
    while(front_is_clear()){
        check_create_wall();
        turn_left();
        check_create_wall();
        turn_left();
        step();
   }
    check_create_wall();
    turn_left();
    check_create_wall();
    turn_left();
    turn_off();
    return 0;
}

void put_beeper2(){
    if(!beepers_present())
        put_beeper();
}

void turn_right(){ 
    for(int i=0; i<3; i++){
        turn_left();
    }
}

void check_create_wall(){
   turn_left();
   while(front_is_clear()){
        if(beepers_present()){
            while(front_is_clear()){
            put_beeper2();
            step();
            put_beeper2();
            }
        }
        if(front_is_clear())
            step();
   }
}
