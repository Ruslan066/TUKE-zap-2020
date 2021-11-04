#include <superkarel.h>

void turn_right();
void go();
void take_beeper();
void go_right_take_beeper();
void go_up();
void put_beeper2();
void go_back_pick_beeper();
void go_down();
void go_home();

int main()
{
    turn_on("task_3.kw");
    set_step_delay(150);

    go();

    turn_off();
    return 0;
}

void go()
{

    //1 строка направо сбор
    go_right_take_beeper();
    //разворот
    if (facing_east() && front_is_blocked())
    {
        turn_left();
        turn_left();
    }
    //обратно/ставим биперы
    while (front_is_clear())
    {
        if (right_is_blocked() && beepers_in_bag())
            put_beeper();
        step();
    }
    //наниз на 1(одну) строку
    turn_left();
    step();
    while (front_is_clear())
    {
        set_step_delay(350);
        turn_left();
        go_right_take_beeper();
        go_up();
        go_back_pick_beeper();
        go_down();
    }
    if (front_is_blocked())
    {
        turn_left();
        go_right_take_beeper();
        go_up();
        go_back_pick_beeper();
        go_down();
    }
    
    //turn_off();
    turn_left();
    set_step_delay(250);
    while (front_is_clear())
    {
        go_home();
    }   
}

void go_home()
{    
    step();
    turn_left();
    while (front_is_clear())
    {
        step();
    }
    if (front_is_blocked() && beepers_present())
    {
        turn_left();
        while (front_is_clear())
        {
            step();
        }
        turn_left();
        turn_left();
        turn_off();
    }
    else
    {
        turn_left();
        turn_left();
        while (front_is_clear())
        {
            step();
        }
    }
    turn_left();
   // step();
    //turn_left();
}

void go_down()
{
    if (not_facing_east() && front_is_blocked())
    {
        turn_left();
        if (front_is_clear())
            step();
        if (front_is_clear())
            step();
    }
}

void go_up()
{
    if (facing_east() && front_is_blocked())
    {
        turn_left();
        step();
        turn_left();
    }
}

void put_beeper2()
{
    if (beepers_present())
    {
        turn_left();
        step();
        put_beeper();
        turn_left();
        turn_left();
        step();
        turn_left();
    }
}

void go_back_pick_beeper()
{
    while (front_is_clear())
    {
        if (beepers_in_bag())
            put_beeper2();
        step();
    }
}

void take_beeper()
{
    if (beepers_present())
        pick_beeper();
}

void go_right_take_beeper()
{
    while (front_is_clear())
    {
        take_beeper();
        step();
        take_beeper();
    }
}

void turn_right()
{
    for (int i = 0; i < 3; i++)
    {
        turn_left();
    }
}
