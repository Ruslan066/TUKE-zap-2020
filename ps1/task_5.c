#include <superkarel.h>

void turn_right();
void go_to_centr();
void create_border();
void a();
void test3();

int main()
{

    turn_on("task_5.kw");
    set_step_delay(50);

    create_border();
    go_to_centr();
    turn_off();
    return 0;
}

void create_border()
{
    while (not_facing_east())
    {
        turn_left();
    }
    while (front_is_clear())
    {
        step();
    }
    while (not_facing_south())
    {
        turn_left();
    }
    while (front_is_clear())
    {
        step();
    }

    turn_left();
    turn_left();

    while (no_beepers_present())
    {
        while (front_is_clear())
        {
            set_step_delay(50);
            put_beeper();
            step();
        }
        turn_left();
    }
}

void go_to_centr()
{
    //-------3x3
    step();
    step();
    if (front_is_blocked())
    {
        turn_left();
        step();
        step();
        if (front_is_blocked())
        {
            turn_left();
            step();
            turn_left();
            step();
            while (not_facing_north())
            {
                turn_left();
            }
            turn_off();
        }
        else
    {
        turn_left();
        turn_left();
        step();
        step();
        turn_right();
        step();
        step();
        turn_left();
        turn_left();
    }
    }
    else
    {
        turn_left();
        turn_left();
        step();
        step();
        turn_left();
        turn_left();
    }
    //-------------
    /*step();
    step();
    if (front_is_blocked())
    {
        turn_left();
        step();
        step();
        if (!front_is_blocked())
        {
            turn_left();
            turn_left();
            step();
            step();
            turn_right();
            step();
            turn_right();

            do
            {
                a();
            } while (no_beepers_present());
            turn_left();
            turn_left();
            step();
            pick_beeper();

            while (not_facing_north())
            {
                turn_left();
            }
            turn_left();
        }
    }
    else
    {
        turn_left();
        turn_left();
        step();
        step();
        turn_right();
        step();
        step();
        turn_left();
        turn_left();
    }*/
    
    //------------




    while (front_is_clear())
    {
        if (beepers_present())
            pick_beeper();
        step();
        if (beepers_present())
            pick_beeper();
    }
    put_beeper();
    turn_left();
    turn_left();
    while (front_is_clear())
    {
        step();
    }
    put_beeper();
    turn_left();
    turn_left();
    //step();
    do
    {
        a();
    } while (no_beepers_present());
    turn_left();
    turn_left();
    step();
    turn_left();

    do
    {
        a();
    } while (no_beepers_present());
    turn_left();
    turn_left();
    step();
    pick_beeper();

    while (not_facing_north())
    {
        turn_left();
    }
    turn_left();
    //------------- 3xn
    step();
    if (front_is_blocked())
    {
        turn_left();
        turn_left();
        step();
        /*pick_beeper();*/

        while (not_facing_north())
        {
            turn_left();
        }
        turn_off();
    }
    else
    {
        turn_left();
        turn_left();
        step();
        turn_left();
        turn_left();
    }

    //----------------------------nxn

    if (front_is_clear())
    {
        step();
    }
    set_step_delay(250);
    while (front_is_clear())
    {
        pick_beeper();
        step();
    }
    turn_left();
    turn_left();
    while (front_is_clear())
    {
        step();
    }
    turn_left();
    turn_left();

    step();
    do
    {

        pick_beeper();
        step();
    } while (beepers_present());

    while (not_facing_north())
    {
        turn_left();
    }
    turn_off();
}

void a()
{
    do
    {
        step();
    } while (no_beepers_present());
    turn_left();
    turn_left();
    step();
    put_beeper();
    step();
}

void turn_right()
{
    for (int i = 0; i < 3; i++)
    {
        turn_left();
    }
}
