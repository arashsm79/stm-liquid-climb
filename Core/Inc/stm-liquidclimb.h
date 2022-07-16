/*
 * common.h
 *
 *  Created on: Apr 14, 2022
 *      Author: arashsm79
 */

#ifndef INC_STM_LIQUIDCLIMB_H_
#define INC_STM_LIQUIDCLIMB_H_

#define JUMP_HEIGHT 4
#define ROW_SIZE 4
#define COLUMN_SIZE 20
#define MAX_BULLETS 20
#define MAX_REACH 8
#define MAX_DIFFICULTY 10
#define SPRING_PLATFORM_JUMP 10
#define MV_AVG_SIZE 5




typedef enum {
	NOTHING, PLATFORM, BROKEN_PLATFORM, MONSTER, PLAYER, BLACKHOLE, BULLET, SPRING_PLATFORM
} liquidclimb_t;

typedef enum {
	RUNNING, GAMEOVER, DYING, INTRO, MENU, ABOUT, CRUISING
} liquidclimb_game_state_t;

typedef struct {
	int8_t x;
	int8_t y;
} vector_t;

typedef struct {
	vector_t position;
	vector_t velocity;
	liquidclimb_t type;
	uint32_t tick;
} entity_t;


// Function prototypes
float cal_avg(float *arr, size_t size);
void strclear(char str[]);
void seven_segment_update(uint8_t num);
void uint_to_seven_segment(uint32_t number);
void place_point(uint8_t x, uint8_t y, liquidclimb_t c);
void place_entity(entity_t* en);
void clear_point(uint8_t x, uint8_t y);
void clear_entity(entity_t* en);
void update_positions(entity_t *en);
uint8_t check_collision(entity_t *en);
void display_menu();
void shift_board();
void update_bullets();
uint8_t bullet_collision(entity_t *en);
void update_entity(entity_t *en);
void init_board();
liquidclimb_t generate_new_entity(uint8_t row, uint8_t col);
void PWM_Change_Tone(TIM_HandleTypeDef *pwm_timer, uint32_t pwm_channel,uint16_t pwm_freq, uint16_t volume);
#endif /* INC_STM_LIQUIDCLIMB_H_ */
