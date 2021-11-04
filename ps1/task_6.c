#include <superkarel.h>

void turn_right();

int main()
{

    turn_on("task_6.kw");
    set_step_delay(150);

    while (no_beepers_present())
    {
        step();

        if (beepers_present())
        {
            //1 сборка смотреть на север
            pick_beeper();
            if (facing_east())
            {
                turn_left();
            }
            else if (facing_south())
            {
                turn_left();
                turn_left();
            }
            else if (facing_west())
            {
                turn_right();
            }
            if (beepers_present())
            {
                //2 сборки смотреть на запад
                pick_beeper();
                if (facing_east())
                {
                    turn_left();
                    turn_left();
                }
                else if (facing_south())
                {
                    turn_right();
                }
                else if (facing_north())
                {
                    turn_left();
                }

                if (beepers_present())
                {
                    //3 сборки смотреть на юг
                    pick_beeper();
                    if (facing_east())
                    {
                        turn_right();
                    }
                    else if (facing_north())
                    {
                        turn_left();
                        turn_left();
                    }
                    else if (facing_west())
                    {
                        turn_left();
                    }
                    if (beepers_present())
                    {
                        //4 сборки смотреть на восток
                        pick_beeper();
                        if (facing_north())
                        {
                            turn_right();
                        }
                        else if (facing_south())
                        {
                            turn_left();
                        }
                        else if (facing_west())
                        {
                            turn_left();
                            turn_left();
                        }
                        if (beepers_present())
                        {
                            pick_beeper();
                            turn_off();
                        }
                        
                    }
                }
            }
        }
    }   
    return 0;
}

void turn_right()
{
    for (int i = 0; i < 3; i++)
    {
        turn_left();
    }
}
