#ifndef _My_UI_
#define _My_UI_
#include "lv_obj.h"
#include "rtc.h"

extern lv_obj_t * cont0;
extern lv_obj_t * cont1;
extern lv_obj_t * cont2;
extern lv_obj_t * cont3;
extern int time_late[4];


void My_pic();
void My_cont1();
void My_cont2();
void My_cont3();
void My_cont4();

void call(lv_obj_t * obj,int y_pos);
void call_back(lv_obj_t * cont);
void time_call();
void time_gui_clear();
void time_show();

void My_cont_1();
void My_cont_2();
void My_cont_3();
void My_cont_4();
void time_change_gui();

void select_cont();
void change_time();
void Set_now_time();

#endif