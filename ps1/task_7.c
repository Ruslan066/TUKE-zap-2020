#include <superkarel.h>

void turn_right();
void two_put_beeper();
void paste_beeper();
void take_beeper();
void put_beeper2();
void pick_beeper2();


int main()
{
    turn_on("task_7.kw");
    set_step_delay(150);

while (front_is_clear())
    {
        put_beeper2();
        step();
        put_beeper2();

    }
    turn_left();
    turn_left();
    while (front_is_clear())
    {
        pick_beeper2();
        step();
        pick_beeper2();
    }
    turn_left();
    turn_left();


    paste_beeper();
    while (not_facing_north())
    {
        turn_left();
    }
    while (no_beepers_present())
    {
        if (front_is_blocked())
        {
            while (front_is_blocked())
            {
                turn_left();
            }
            step();
        }
        if (front_is_clear() && not_facing_north())
        {
            turn_left();
            if (front_is_blocked())
            {
                turn_right();
                turn_right();
            }
        }
        take_beeper();
    }
    if (left_is_clear())
    {
        turn_left();
        step();
        two_put_beeper();
        turn_left();
        turn_left();
        step();
    }
    while (not_facing_west())
    {
        turn_left();
    }
    while (front_is_clear())
    {
        step();
    }
    while (not_facing_west())
    {
        turn_left();
    }
    while (no_beepers_present() || front_is_blocked() || front_is_clear())
    {
        if (beepers_present())
        {
            if (beepers_present())
            {
                pick_beeper();
                if (right_is_clear())
                {
                    turn_right();
                    if (front_is_clear())
                    {
                        step();
                        turn_left();
                    }
                }
            }
            if (front_is_blocked() && right_is_blocked() && facing_east() && beepers_present() && left_is_clear())
            {
                break;
            }
        }
        while (front_is_blocked())
        {
            turn_right();
        }
        if (front_is_clear())
        {
            step();
            if (front_is_blocked() && right_is_blocked() && facing_east() && beepers_present())
            {
                break;
            }
        }
        turn_left();
    }
    if (left_is_clear())
    {
        turn_left();
        step();
        if (beepers_present())
        {
            pick_beeper();
            if (beepers_present())
            {
                pick_beeper();
            }
            else
            {
                put_beeper();
            }
        }
        turn_left();
        turn_left();
        step();
        turn_left();
    }
    while (beepers_present())
    {
        pick_beeper();
    }

    turn_off();
    return 0;
}


void two_put_beeper()
{
    put_beeper();
    put_beeper();
}

void paste_beeper()
{
    while (front_is_clear())
    {
        step();
    }
    two_put_beeper();
    turn_left();
    turn_left();
    while (front_is_clear())
    {
        step();
    }
}

void take_beeper()
{
    if (front_is_clear() && facing_north())
    {
        step();
        two_put_beeper();
        turn_right();
        turn_right();
    }
    if (front_is_clear())
    {
        step();
        turn_left();
        step();
    }
}

void put_beeper2(){
    if (no_beepers_present())
    {
        put_beeper();
    }
    
}

void pick_beeper2(){
    if (beepers_present())
    {
        pick_beeper();
    }
    
}

void turn_right()
{
    turn_left();
    turn_left();
    turn_left();
}
