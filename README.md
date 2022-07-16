# STM Liquid Climb
> A platformer game implemented in C using STM32 HAL library and drawn on character LCD

* [Introduction](#Introduction)
* [Game Flow and Screenshots](#Game-Flow-and-Screenshots)
* [Required Hardware](#Required-Hardware)
* [Dependencies](#Dependencies)
* [Building](#Building)



# Introduction
This repo contains the code for a platformer game implemented in C. The game is inspired by the classic [Doodle Jump](https://en.wikipedia.org/wiki/Doodle_Jump) game and was designed and tested on an STM32F303 Discovery Board. The player has to climb up the procedurally generated platforms and try to avoid monsters and black holes; the higher it climbs the more score it gets. The game ends when the player has either fallen out of the map or has been hit by a monster or sucked into a black hole.

The code is heavily commented and I highly encourage new learners to take a peek at it. The logic is distributed between `main.c` and `stm32f3xx_it.c`. I recommend starting at the handler of the main timer which is `TIM4 handler` in `stm32f3xx_it.c`.

# Game Flow and Screenshots
When the game starts, you are greeted with a welcome page. This page contains the name and a preview of the game. In order to get to the main menu, you have to press the blue button on the board.

![intro](/screenshots/intro.png)

In the main menu you can do three things:
* press `1` on the keypad to start the game
* press `2` on the keypad to see the current time using RTC and the creators' names
* send a string via UART to change the name of the player

![menu](/screenshots/menu.png)

In the game, the player keeps jumping up and down on a platform. You can use the numbers `13` and `16` on the keypad to move it left and right. In order to shoot the monsters, you can use `14` on the keypad. The bullets are generated efficiently and the player has a capacity of up to 20 bullets.

* If the player hits a monster it gets dizzy and falls out of the map without being able to hit any platforms; the buzzer also goes off while being dizzy.
* If the player jumps on a spring platform it starts cruising and climbs up to 25 levels in one go.
* If the player gets sucked into a black hole, the game is over.
* If the player falls out of the map, the game is over.
* If the player reaches a certain threshold on the LCD, the game start to shift the map until the last platform that the player was on is now at the end of the map. While shifting, the velocity of the player is zero in either direction.

Every time a shift occurs the score increases based of the current difficulty. The difficulty is configured using the volume module and is displayed on one of the digits of the 7-segment. The other 3 digits of the 7-segment show the current score.

After the game is over you are shown your username and your score. You have to press `3` on the keypad to go back to the main menu.


# Required Hardware
* STM32F303 Discovery Board
* Variable Resistor (potentiometer)
* 4x4 Matrix Buttong Keypad 
* UART Cable
* 4 digit 7-Segment
* 7448 BCD to 7-Segment Decoder
* Buzzer
* Character LCD

# Dependencies
* STM32F3xx HAL Driver provided by STM32CubeMX
* [STM32LiquidCrystal](https://github.com/SayidHosseini/STM32LiquidCrystal)

# Building
If using STM32CubeIDE, simply create a new project for the specified microcontroller and import these files. Otherwise, install the necessary toolchains and compile and flash as you normally would using your favorite build system and flashing tool.
