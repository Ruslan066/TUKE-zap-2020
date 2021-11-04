#include <superkarel.h>

void go_to_beeper();
void go_back();
void turn_right();
void take_beeper();
void check_beeper();

int main()
{
    turn_on("task_1.kw");
    set_step_delay(150);
    put_beeper();
    turn_left();
    step();
    while (!beepers_in_bag())
    {
        go_to_beeper();
    }
    while (!beepers_present())
    {
        go_back();
    }
    turn_off();
}

void go_to_beeper()
{    
    set_step_delay(10);
    while (front_is_clear())
    {
        step();
    }
    turn_right();
    step();
    turn_right();
    while (front_is_clear())
    {
        step();
    }
    take_beeper();
    turn_left();
    turn_left();       
}

void go_back()
{
    set_step_delay(150);
    while (front_is_clear())
    {
        step();
    }
    turn_left();
    step();
    turn_left();
    while (front_is_clear())
    {
        step();
    }
    check_beeper();
    turn_left();
    turn_left();  
}

void check_beeper(){
    if (beepers_present())
    {
        pick_beeper();
        turn_right();
        turn_off();
    }
}

void take_beeper()
{
    if (beepers_present())
    {        
        pick_beeper();
    }
}

void turn_right()
{
    for (int i = 0; i < 3; i++)
    {
        turn_left();
    }
}
