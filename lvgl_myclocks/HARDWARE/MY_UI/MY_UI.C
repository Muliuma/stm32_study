#include "MY_UI.h"
#include "lv_obj.h"
#include "lv_indev.h"
#include "lv_refr.h"
#include "lv_group.h"
#include "lv_disp.h"
#include "lv_demo_widgets.h"
#include "lv_port_disp.h"
#include "lv_conf.h"
#include "MY_UI.h"
#include "timer.h"
#include "rtc.h"

lv_obj_t * screen;

lv_obj_t * window1;
lv_obj_t * window2;
lv_obj_t * window3;
lv_obj_t * window4;

lv_obj_t * cont0;
lv_obj_t * cont1;
lv_obj_t * cont2;
lv_obj_t * cont3;

//初始化主界面
void My_pic()
{
		        screen = lv_obj_create(lv_scr_act(), NULL);
	          lv_obj_set_size(screen,130,130);
	          lv_obj_set_pos(screen,-1,-1);
	
	          window1 = lv_obj_create(screen, NULL);
	          lv_obj_set_size(window1,30,30);
	          lv_obj_set_pos(window1,0,40);
	
						window2 = lv_obj_create(screen, NULL);
						lv_obj_set_size(window2,30,30);
						lv_obj_set_pos(window2,30,40);

						window3 = lv_obj_create(screen, NULL);
						lv_obj_set_size(window3,30,30);
						lv_obj_set_pos(window3,68,40);

						window4 = lv_obj_create(screen, NULL);
						lv_obj_set_size(window4,30,30);
						lv_obj_set_pos(window4,98,40);
	
			      static lv_style_t style;
            lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
           	lv_obj_add_style(screen, LV_BTN_PART_MAIN, &style);      /*Default button style*/
	
				    static lv_style_t style_t;
            lv_style_set_bg_color(&style_t, LV_STATE_DEFAULT, LV_COLOR_BLACK);
           	lv_obj_add_style(window1, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
						lv_obj_add_style(window2, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
						lv_obj_add_style(window3, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
						lv_obj_add_style(window4, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
	          lv_style_set_border_color(&style_t,LV_STATE_DEFAULT,LV_COLOR_BLACK);        //设置样式边框颜色
					
					  cont0 = lv_cont_create(window1, NULL);
						lv_obj_set_size(cont0,30,90);
            lv_obj_set_pos(cont0,0,0);	
	
            cont1 = lv_cont_create(window2, NULL);
						lv_obj_set_size(cont1,30,300);
            lv_obj_set_pos(cont1,0,0);	
	
            cont2 = lv_cont_create(window3, NULL);
						lv_obj_set_size(cont2,30,180);
            lv_obj_set_pos(cont2,0,0);	
						
            cont3 = lv_cont_create(window4, NULL);
						lv_obj_set_size(cont3,30,300);
            lv_obj_set_pos(cont3,0,0);	

					
							  //定义样式
		        static lv_style_t style1;
            lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	
  	        lv_obj_add_style(cont0, LV_BTN_PART_MAIN, &style1);      /*Default button style*/
						//lv_obj_add_style(lv_scr_act(), LV_BTN_PART_MAIN, &style1);      /*Default button style*/
						  
						uint32_t t;
						
            My_cont1();
						My_cont2();
						My_cont3();
						My_cont4();
						
            lv_obj_t * lable = lv_label_create(screen, NULL);
            lv_label_set_align(lable, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lable, true);
            lv_label_set_text(lable,"#8B2500 :#");
            lv_obj_set_pos(lable,63,46);						
						
						lv_obj_t * day1 = lv_label_create(screen, NULL);
            lv_label_set_align(day1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day1, true);
            lv_label_set_text(day1,"#FA8072 2022#");
            lv_obj_set_pos(day1,0,20);	
						
						lv_obj_t * day2 = lv_label_create(screen, NULL);
            lv_label_set_align(day2, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day2, true);
            lv_label_set_text(day2,"#FA8072 02#");
            lv_obj_set_pos(day2,43,20);	
						
						lv_obj_t * day3 = lv_label_create(screen, NULL);
            lv_label_set_align(day3, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day3, true);
            lv_label_set_text(day3,"#FA8072 01#");
            lv_obj_set_pos(day3,70,20);	
						
						lv_obj_t * lab1 = lv_label_create(screen, NULL);
            lv_label_set_align(lab1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lab1, true);
            lv_label_set_text(lab1,"#FFB90F /#");
            lv_obj_set_pos(lab1,36,21);
						
						lv_obj_t * lab2 = lv_label_create(screen, NULL);
            lv_label_set_align(lab2, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lab2, true);
            lv_label_set_text(lab2,"#FFB90F /#");
            lv_obj_set_pos(lab2,63,21);
						
						lv_obj_t * weekday = lv_label_create(screen, NULL);
            lv_label_set_align(weekday, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(weekday, true);
            lv_label_set_text(weekday,"#00F5FF WED#");
            lv_obj_set_pos(weekday,90,20);		

						
					  lv_refr_now(NULL);
            t = lv_tick_get();
            while(lv_tick_elaps(t) < 2000);
						
//						
//						
//            //lv_obj_set_pos(cont,-1,-66);
//						lv_anim_t a;
//						lv_anim_init(&a);						
//		        /* 设置“动画制作”功能 */
//            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
//						lv_anim_set_var(&a, cont3);
//						lv_anim_set_values(&a, 0, -270);						
//            /* 动画时长[ms] */
//            lv_anim_set_time(&a, 5000);
//						
//						//设置动画路径
//					  lv_anim_path_t path;
//            lv_anim_path_init(&path);
//            lv_anim_path_set_cb(&path, lv_anim_path_linear);
//            /* 在动画中设置路径 */
//            lv_anim_set_path(&a, &path);
////						lv_anim_set_playback_time(&a, 1000);
////						lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
//						//lv_anim_del(cont3,NULL);
//						lv_anim_start(&a);		//开始动画
						

}

//创建一个cont对象，然后保存0—2的数字
void My_cont1()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont0,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont0,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont0,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
						
}
//创建一个cont对象，然后保存0—5的数字
void My_cont2()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont2,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont2,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont2,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
	
						lv_obj_t * img_bg3 = NULL;
            LV_IMG_DECLARE(pic3);
            img_bg3 = lv_img_create(cont2,NULL);
            lv_img_set_src(img_bg3,&pic3);						
						lv_obj_set_pos(img_bg3,0,90);
						
						lv_obj_t * img_bg4 = NULL;
            LV_IMG_DECLARE(pic4);
            img_bg4 = lv_img_create(cont2,NULL);
            lv_img_set_src(img_bg4,&pic4);						
						lv_obj_set_pos(img_bg4,0,120);
						
						lv_obj_t * img_bg5 = NULL;
            LV_IMG_DECLARE(pic5);
            img_bg5 = lv_img_create(cont2,NULL);
            lv_img_set_src(img_bg5,&pic5);						
						lv_obj_set_pos(img_bg5,0,150);
}
//创建一个cont对象，然后保存0—9的数字
void My_cont3()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
	
						lv_obj_t * img_bg3 = NULL;
            LV_IMG_DECLARE(pic3);
            img_bg3 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg3,&pic3);						
						lv_obj_set_pos(img_bg3,0,90);
						
						lv_obj_t * img_bg4 = NULL;
            LV_IMG_DECLARE(pic4);
            img_bg4 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg4,&pic4);						
						lv_obj_set_pos(img_bg4,0,120);
						
						lv_obj_t * img_bg5 = NULL;
            LV_IMG_DECLARE(pic5);
            img_bg5 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg5,&pic5);						
						lv_obj_set_pos(img_bg5,0,150);
						
						lv_obj_t * img_bg6 = NULL;
            LV_IMG_DECLARE(pic6);
            img_bg6 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg6,&pic6);						
						lv_obj_set_pos(img_bg6,0,180);
						
						lv_obj_t * img_bg7 = NULL;
            LV_IMG_DECLARE(pic7);
            img_bg7 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg7,&pic7);						
						lv_obj_set_pos(img_bg7,0,210);
						
						lv_obj_t * img_bg8 = NULL;
            LV_IMG_DECLARE(pic8);
            img_bg8 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg8,&pic8);						
						lv_obj_set_pos(img_bg8,0,240);
						
						lv_obj_t * img_bg9 = NULL;
            LV_IMG_DECLARE(pic9);
            img_bg9 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg9,&pic9);						
						lv_obj_set_pos(img_bg9,0,270);			
}


void My_cont4()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
	
						lv_obj_t * img_bg3 = NULL;
            LV_IMG_DECLARE(pic3);
            img_bg3 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg3,&pic3);						
						lv_obj_set_pos(img_bg3,0,90);
						
						lv_obj_t * img_bg4 = NULL;
            LV_IMG_DECLARE(pic4);
            img_bg4 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg4,&pic4);						
						lv_obj_set_pos(img_bg4,0,120);
						
						lv_obj_t * img_bg5 = NULL;
            LV_IMG_DECLARE(pic5);
            img_bg5 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg5,&pic5);						
						lv_obj_set_pos(img_bg5,0,150);
						
						lv_obj_t * img_bg6 = NULL;
            LV_IMG_DECLARE(pic6);
            img_bg6 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg6,&pic6);						
						lv_obj_set_pos(img_bg6,0,180);
						
						lv_obj_t * img_bg7 = NULL;
            LV_IMG_DECLARE(pic7);
            img_bg7 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg7,&pic7);						
						lv_obj_set_pos(img_bg7,0,210);
						
						lv_obj_t * img_bg8 = NULL;
            LV_IMG_DECLARE(pic8);
            img_bg8 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg8,&pic8);						
						lv_obj_set_pos(img_bg8,0,240);
						
						lv_obj_t * img_bg9 = NULL;
            LV_IMG_DECLARE(pic9);
            img_bg9 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg9,&pic9);						
						lv_obj_set_pos(img_bg9,0,270);
}


//obj:输入指向的对象参数
//y_pos:输入的参数为显示的数字-1
//例子：y_pos=4时显示数字为5；
void call(lv_obj_t * obj,int y_pos)
{
	
	          y_pos*=-30;
            lv_anim_del(obj,NULL);
	 					lv_anim_t a;
						lv_anim_init(&a);						
		        /* 设置“动画制作”功能 */
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
						lv_anim_set_var(&a, obj);
						lv_anim_set_values(&a, y_pos, y_pos-30);						
            /* 动画时长[ms] */
            lv_anim_set_time(&a, 1000);
						//设置动画路径
					  lv_anim_path_t path;
            lv_anim_path_init(&path);
            lv_anim_path_set_cb(&path, lv_anim_path_linear);
            /* 在动画中设置路径 */
            lv_anim_set_path(&a, &path);
//						lv_anim_set_playback_time(&a, 1000);
//						lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
						//lv_anim_del(cont3,NULL);
						lv_anim_start(&a);		//开始动画
}

void call_back(lv_obj_t * cont)
{
            lv_anim_del(cont,NULL);
	 					lv_anim_t a;
						lv_anim_init(&a);						
		        /* 设置“动画制作”功能 */
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
						lv_anim_set_var(&a, cont);
						lv_anim_set_values(&a, -60, 0);						
            /* 动画时长[ms] */
            lv_anim_set_time(&a, 1000);
						//设置动画路径
					  lv_anim_path_t path;
            lv_anim_path_init(&path);
            lv_anim_path_set_cb(&path, lv_anim_path_linear);
            /* 在动画中设置路径 */
            lv_anim_set_path(&a, &path);
//						lv_anim_set_playback_time(&a, 1000);
//						lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
						//lv_anim_del(cont3,NULL);
						lv_anim_start(&a);		//开始动画

}

RTC_TimeTypeDef RTC_TimeStruct;
int time[4];
int time_late[4]={-1,-1,-1,-1};

//时间回调函数，定期调用，显示时间
void time_call()
{
	lv_obj_t * cont[4]={cont0,cont1,cont2,cont3};
  RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
  //获得当前时间的数值
	time[0]=RTC_TimeStruct.RTC_Hours/10;
	time[1]=RTC_TimeStruct.RTC_Hours%10;
	time[2]=RTC_TimeStruct.RTC_Minutes/10;
	time[3]=RTC_TimeStruct.RTC_Minutes%10;
  for(int i=0;i<4;i++)
  {
		 if(time[i]!=time_late[i])
     {
		    if(time[i]!=0)
           call(cont[i],time[i]-1);
		    else
			     call_back(cont[i]);
		 }
	}
  for(int i=0;i<4;i++)
     time_late[i]=time[i];
}

//删除时间显示界面
void time_gui_clear()
{
   lv_obj_clean(screen);
}

//再次显示时间显示界面
void time_show()
{
	  flag_time=1;         //设置标志位，打开定时器里面的时间刷新函数
   	My_pic();
	  for(int i=0;i<4;i++)
        time_late[i]=-1;
	  time_call();
}

/*------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
-----------------------------------以上函数是用于处理时间显示界面---------------------------------------------
-----------------------------------以下函数是用于处理时间修改界面---------------------------------------------
--------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------*/

int chioce_time[4];

lv_obj_t * window_1;
lv_obj_t * window_2;
lv_obj_t * window_3;
lv_obj_t * window_4;

lv_obj_t * cont_0;
lv_obj_t * cont_1;
lv_obj_t * cont_2;
lv_obj_t * cont_3;

int i_cont=0;       

void time_change_gui()
{           
	          for(int i=0;i<4;i++)
	              chioce_time[i]=0;          
	
	          window_1 = lv_obj_create(screen, NULL);
	          lv_obj_set_size(window_1,30,30);
	          lv_obj_set_pos(window_1,0,40);
	
						window_2 = lv_obj_create(screen, NULL);
						lv_obj_set_size(window_2,30,30);
						lv_obj_set_pos(window_2,30,40);

						window_3 = lv_obj_create(screen, NULL);
						lv_obj_set_size(window_3,30,30);
						lv_obj_set_pos(window_3,68,40);

						window_4 = lv_obj_create(screen, NULL);
						lv_obj_set_size(window_4,30,30);
						lv_obj_set_pos(window_4,98,40);
	
			      static lv_style_t style;
            lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
           	lv_obj_add_style(screen, LV_BTN_PART_MAIN, &style);      /*Default button style*/
             
            cont_0 = lv_cont_create(window_1, NULL);
						lv_obj_set_size(cont_0,30,90);
            lv_obj_set_pos(cont_0,0,0);	
	
            cont_1 = lv_cont_create(window_2, NULL);
						lv_obj_set_size(cont_1,30,300);
            lv_obj_set_pos(cont_1,0,0);	
	
            cont_2 = lv_cont_create(window_3, NULL);
						lv_obj_set_size(cont_2,30,180);
            lv_obj_set_pos(cont_2,0,0);	
						
            cont_3 = lv_cont_create(window_4, NULL);
						lv_obj_set_size(cont_3,30,300);
            lv_obj_set_pos(cont_3,0,0);		
						
						My_cont_1();
						My_cont_2();
						My_cont_3();
						My_cont_4();
						
						lv_obj_t * lable = lv_label_create(screen, NULL);
            lv_label_set_align(lable, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lable, true);
            lv_label_set_text(lable,"#8B2500 :#");
            lv_obj_set_pos(lable,63,46);						
						
						lv_obj_t * day1 = lv_label_create(screen, NULL);
            lv_label_set_align(day1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day1, true);
            lv_label_set_text(day1,"#FA8072 2022#");
            lv_obj_set_pos(day1,0,20);	
						
						lv_obj_t * day2 = lv_label_create(screen, NULL);
            lv_label_set_align(day2, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day2, true);
            lv_label_set_text(day2,"#FA8072 02#");
            lv_obj_set_pos(day2,43,20);	
						
						lv_obj_t * day3 = lv_label_create(screen, NULL);
            lv_label_set_align(day3, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day3, true);
            lv_label_set_text(day3,"#FA8072 26#");
            lv_obj_set_pos(day3,70,20);	
						
						lv_obj_t * lab1 = lv_label_create(screen, NULL);
            lv_label_set_align(lab1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lab1, true);
            lv_label_set_text(lab1,"#FFB90F /#");
            lv_obj_set_pos(lab1,36,21);
						
						lv_obj_t * lab2 = lv_label_create(screen, NULL);
            lv_label_set_align(lab2, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lab2, true);
            lv_label_set_text(lab2,"#FFB90F /#");
            lv_obj_set_pos(lab2,63,21);
						
						lv_obj_t * weekday = lv_label_create(screen, NULL);
            lv_label_set_align(weekday, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(weekday, true);
            lv_label_set_text(weekday,"#00F5FF WED#");
            lv_obj_set_pos(weekday,90,20);		
}

//创建一个cont对象，然后保存0—2的数字
void My_cont_1()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont_0,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont_0,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont_0,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
						
}
//创建一个cont对象，然后保存0—5的数字
void My_cont_2()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont_2,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont_2,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont_2,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
	
						lv_obj_t * img_bg3 = NULL;
            LV_IMG_DECLARE(pic3);
            img_bg3 = lv_img_create(cont_2,NULL);
            lv_img_set_src(img_bg3,&pic3);						
						lv_obj_set_pos(img_bg3,0,90);
						
						lv_obj_t * img_bg4 = NULL;
            LV_IMG_DECLARE(pic4);
            img_bg4 = lv_img_create(cont_2,NULL);
            lv_img_set_src(img_bg4,&pic4);						
						lv_obj_set_pos(img_bg4,0,120);
						
						lv_obj_t * img_bg5 = NULL;
            LV_IMG_DECLARE(pic5);
            img_bg5 = lv_img_create(cont_2,NULL);
            lv_img_set_src(img_bg5,&pic5);						
						lv_obj_set_pos(img_bg5,0,150);
}
//创建一个cont对象，然后保存0—9的数字
void My_cont_3()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
	
						lv_obj_t * img_bg3 = NULL;
            LV_IMG_DECLARE(pic3);
            img_bg3 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg3,&pic3);						
						lv_obj_set_pos(img_bg3,0,90);
						
						lv_obj_t * img_bg4 = NULL;
            LV_IMG_DECLARE(pic4);
            img_bg4 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg4,&pic4);						
						lv_obj_set_pos(img_bg4,0,120);
						
						lv_obj_t * img_bg5 = NULL;
            LV_IMG_DECLARE(pic5);
            img_bg5 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg5,&pic5);						
						lv_obj_set_pos(img_bg5,0,150);
						
						lv_obj_t * img_bg6 = NULL;
            LV_IMG_DECLARE(pic6);
            img_bg6 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg6,&pic6);						
						lv_obj_set_pos(img_bg6,0,180);
						
						lv_obj_t * img_bg7 = NULL;
            LV_IMG_DECLARE(pic7);
            img_bg7 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg7,&pic7);						
						lv_obj_set_pos(img_bg7,0,210);
						
						lv_obj_t * img_bg8 = NULL;
            LV_IMG_DECLARE(pic8);
            img_bg8 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg8,&pic8);						
						lv_obj_set_pos(img_bg8,0,240);
						
						lv_obj_t * img_bg9 = NULL;
            LV_IMG_DECLARE(pic9);
            img_bg9 = lv_img_create(cont_1,NULL);
            lv_img_set_src(img_bg9,&pic9);						
						lv_obj_set_pos(img_bg9,0,270);			
}


void My_cont_4()
{
						lv_obj_t * img_bg0 = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg0 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg0,&pic0);						
						lv_obj_set_pos(img_bg0,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,30);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,60);
	
						lv_obj_t * img_bg3 = NULL;
            LV_IMG_DECLARE(pic3);
            img_bg3 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg3,&pic3);						
						lv_obj_set_pos(img_bg3,0,90);
						
						lv_obj_t * img_bg4 = NULL;
            LV_IMG_DECLARE(pic4);
            img_bg4 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg4,&pic4);						
						lv_obj_set_pos(img_bg4,0,120);
						
						lv_obj_t * img_bg5 = NULL;
            LV_IMG_DECLARE(pic5);
            img_bg5 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg5,&pic5);						
						lv_obj_set_pos(img_bg5,0,150);
						
						lv_obj_t * img_bg6 = NULL;
            LV_IMG_DECLARE(pic6);
            img_bg6 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg6,&pic6);						
						lv_obj_set_pos(img_bg6,0,180);
						
						lv_obj_t * img_bg7 = NULL;
            LV_IMG_DECLARE(pic7);
            img_bg7 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg7,&pic7);						
						lv_obj_set_pos(img_bg7,0,210);
						
						lv_obj_t * img_bg8 = NULL;
            LV_IMG_DECLARE(pic8);
            img_bg8 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg8,&pic8);						
						lv_obj_set_pos(img_bg8,0,240);
						
						lv_obj_t * img_bg9 = NULL;
            LV_IMG_DECLARE(pic9);
            img_bg9 = lv_img_create(cont_3,NULL);
            lv_img_set_src(img_bg9,&pic9);						
						lv_obj_set_pos(img_bg9,0,270);
}

//选择操作的数字位置
lv_obj_t * cont_now;
void select_cont()
{          
            lv_obj_t * cont_array[4]={cont_0,cont_1,cont_2,cont_3};
	          i_cont++;
	          if(i_cont==5) i_cont=1;
            cont_now=cont_array[i_cont-1];
}

//调整相应的时间
void change_time()
{
            if(cont_now==cont_0)
            {    
							   chioce_time[0]++;
							   if(chioce_time[0]==3)
									      chioce_time[0]=0;
							   if(chioce_time[0]!=0)
						            call(cont_now,chioce_time[0]-1);
								 else
									      call_back(cont_now);
						}
						else if(cont_now==cont_1)
            {
							   chioce_time[1]++;
							   if(chioce_time[1]==10)
									      chioce_time[1]=0;
							   if(chioce_time[1]!=0)
						            call(cont_now,chioce_time[1]-1);
								 else
									      call_back(cont_now);
						}
						else if(cont_now==cont_2)
            {
							   chioce_time[2]++;
							   if(chioce_time[2]==6)
									      chioce_time[2]=0;
							   if(chioce_time[2]!=0)
						            call(cont_now,chioce_time[2]-1);
								 else
									      call_back(cont_now);
						}
						else
						{
							   chioce_time[3]++;
							   if(chioce_time[3]==10)
									      chioce_time[3]=0;
							   if(chioce_time[3]!=0)
						            call(cont_now,chioce_time[3]-1);
								 else
									      call_back(cont_now);
						}
}

//设置相关的时间
void Set_now_time()
{
            Set_time(chioce_time[0],chioce_time[1],chioce_time[2],chioce_time[3]);
}