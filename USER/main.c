#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "TFT.h"
#include "Picture.h"
#include "lv_obj.h"
#include "lv_indev.h"
#include "lv_refr.h"
#include "lv_group.h"
#include "lv_disp.h"
#include "lv_demo_widgets.h"
#include "lv_port_disp.h"
#include "lv_conf.h"
#include "MY_UI.h"
#include "key.h"
#include "rtc.h"


lv_obj_t * number1;
char numb_data = '0';


void lv_example_obj_1(void)
{
    lv_obj_t * obj1;
    obj1 = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_size(obj1, 100, 50);
    lv_obj_align(obj1,NULL ,LV_ALIGN_CENTER, 0, 0);

    static lv_style_t style_shadow;
    lv_style_init(&style_shadow);


    lv_obj_t * obj2;
    obj2 = lv_obj_create(lv_scr_act(),NULL);
    lv_obj_add_style(obj2, (uint8_t)&style_shadow, 0);
    lv_obj_align(obj2, NULL ,LV_ALIGN_CENTER, 60, 30);
}



//实现对组件背景色彩填充，并且实现渐变色
void lvgl_style_bg_properties_test(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, LV_STATE_DEFAULT, 1);                    //设置背景的半径
 
    /*Make a gradient*/ 
    lv_style_set_bg_opa(&style, LV_STATE_DEFAULT, LV_OPA_COVER);          //设置背景的透明度
    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLUE);        //设置背景的颜色
    lv_style_set_bg_grad_color(&style, LV_STATE_DEFAULT, LV_COLOR_GREEN);  //设置背景渐变的颜色
    lv_style_set_bg_grad_dir(&style, LV_STATE_DEFAULT, LV_GRAD_DIR_HOR);  //设置渐变颜色的方向
 
    /*Shift the gradient to the bottom*/
    lv_style_set_bg_main_stop(&style, LV_STATE_DEFAULT, 0);               //指定渐变应从何处开始
    lv_style_set_bg_grad_stop(&style, LV_STATE_DEFAULT, 255);             //指定渐变应在何处停止

 
 
    /*Create an object with the new style*/
    lv_obj_t* obj = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &style);
	  lv_obj_set_size(obj, 90, 90);
    lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);
}

void example_change()
{
	

	
		lv_obj_t* one = lv_obj_create(lv_scr_act(), NULL);  //在默认屏上创建obj对象
    lv_obj_t* label = lv_label_create(one, NULL);        // 创建label  
    lv_obj_set_size(one, LV_HOR_RES, LV_VER_RES);       // 设置到屏幕大小
    lv_obj_align(label, one, LV_ALIGN_CENTER, 0, 0);    // label居屏幕中心对齐
    lv_obj_set_style_local_bg_color(one, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 
    LV_COLOR_YELLOW);       // obj背景色设成黄色
    lv_label_set_text(label, "ONE");    // label显示ONE

	
	  lv_obj_t* two = lv_obj_create(NULL, NULL);   // 创建新屏幕但未加载到显示
    label = lv_label_create(two, NULL);         // 创建label
    lv_obj_set_size(two, LV_HOR_RES, LV_VER_RES);  //设置到屏幕大小
    lv_obj_align(label, two, LV_ALIGN_CENTER, 0, 0);  // 居中对齐
    lv_obj_set_style_local_bg_color(two, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 
    LV_COLOR_BLUE);    // 背影色设成蓝色
    lv_label_set_text(label, "TWO");  // label上显示TWO

	  lv_scr_load_anim(two, LV_SCR_LOAD_ANIM_FADE_ON, 500, 2000, true); // 加载屏幕TWO,动画效果为LV_SCR_LOAD_ANIM_FADE_ON,切换时间为500ms,延迟5000ms后从第一屏开始切换，切换完成后删除屏幕一
	
}


void pic_example()
{
	  //创建盒子
	  lv_obj_t * Box = lv_obj_create(lv_scr_act(),NULL);
	  lv_obj_set_size(Box, 130, 130);
	  lv_obj_set_pos(Box, -1, -1);
	
	  //定义样式
		static lv_style_t style1;
    lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	
  	lv_obj_add_style(Box, LV_BTN_PART_MAIN, &style1);      /*Default button style*/
	
    static lv_obj_t * img_bg = NULL;
    LV_IMG_DECLARE(clock);
    img_bg = lv_img_create(Box,NULL);
    lv_img_set_src(img_bg,&clock);
    lv_obj_align(img_bg,NULL,LV_ALIGN_CENTER,0,0);

    lv_obj_t * img2 = lv_img_create(Box,NULL);
    lv_img_set_src(img2, LV_SYMBOL_OK "time");
    lv_obj_align(img2, img_bg ,LV_ALIGN_IN_BOTTOM_MID, 0, 15);
	
	  lv_obj_t * img3 = lv_img_create(Box,NULL);
    lv_img_set_src(img3, LV_SYMBOL_BATTERY_FULL);
   	lv_obj_set_pos(img3, 108, 0);		 
}


void func(lv_obj_t * obj,char nub1,char nub2)
{
	   char col[11] = "#FF4500 00#";
	   col[8] = nub1;
	   col[9] = nub2;	
     lv_label_set_text(obj,col);
}



void My_UI1()
{
	          lv_obj_t * window1;
	          window1 = lv_obj_create(lv_scr_act(), NULL);
	          lv_obj_set_size(window1,30,30);
	          lv_obj_set_pos(window1,0,40);
	
						lv_obj_t * window2;
						window2 = lv_obj_create(lv_scr_act(), NULL);
						lv_obj_set_size(window2,30,30);
						lv_obj_set_pos(window2,30,40);

						lv_obj_t * window3;
						window3 = lv_obj_create(lv_scr_act(), NULL);
						lv_obj_set_size(window3,30,30);
						lv_obj_set_pos(window3,68,40);

						lv_obj_t * window4;
						window4 = lv_obj_create(lv_scr_act(), NULL);
						lv_obj_set_size(window4,30,30);
						lv_obj_set_pos(window4,98,40);
	
			      static lv_style_t style;
            lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
           	lv_obj_add_style(lv_scr_act(), LV_BTN_PART_MAIN, &style);      /*Default button style*/
	
				    static lv_style_t style_t;
            lv_style_set_bg_color(&style_t, LV_STATE_DEFAULT, LV_COLOR_BLACK);
           	lv_obj_add_style(window1, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
						lv_obj_add_style(window2, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
						lv_obj_add_style(window3, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
						lv_obj_add_style(window4, LV_BTN_PART_MAIN, &style_t);      /*Default button style*/
	          lv_style_set_border_color(&style_t,LV_STATE_DEFAULT,LV_COLOR_BLACK);        //设置样式边框颜色
						
	
            lv_obj_t * cont;
            cont = lv_cont_create(window1, NULL);
						//lv_obj_set_x(cont, 128);
						lv_obj_set_size(cont,30,300);
            lv_obj_set_pos(cont,0,0);	
	
            lv_obj_t * cont1;
            cont1 = lv_cont_create(window2, NULL);
						//lv_obj_set_x(cont, 128);
						lv_obj_set_size(cont1,30,300);
            lv_obj_set_pos(cont1,0,0);	
	
            lv_obj_t * cont2;
            cont2 = lv_cont_create(window3, NULL);
						//lv_obj_set_x(cont, 128);
						lv_obj_set_size(cont2,30,300);
            lv_obj_set_pos(cont2,0,0);	
						
            lv_obj_t * cont3;
            cont3 = lv_cont_create(window4, NULL);
						//lv_obj_set_x(cont, 128);
						lv_obj_set_size(cont3,30,300);
            lv_obj_set_pos(cont3,0,0);	

					
							  //定义样式
		        static lv_style_t style1;
            lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	
  	        lv_obj_add_style(cont, LV_BTN_PART_MAIN, &style1);      /*Default button style*/
						//lv_obj_add_style(lv_scr_act(), LV_BTN_PART_MAIN, &style1);      /*Default button style*/
						  
						uint32_t t;
						
						lv_obj_t * img_bg = NULL;
            LV_IMG_DECLARE(pic0);
            img_bg = lv_img_create(cont,NULL);
            lv_img_set_src(img_bg,&pic0);						
						lv_obj_set_pos(img_bg,0,0);
						
						lv_obj_t * img_bg1 = NULL;
            LV_IMG_DECLARE(pic1);
            img_bg1 = lv_img_create(cont1,NULL);
            lv_img_set_src(img_bg1,&pic1);						
						lv_obj_set_pos(img_bg1,0,0);
						
						lv_obj_t * img_bg2 = NULL;
            LV_IMG_DECLARE(pic2);
            img_bg2 = lv_img_create(cont2,NULL);
            lv_img_set_src(img_bg2,&pic2);						
						lv_obj_set_pos(img_bg2,0,0);
						
						lv_obj_t * img_bg3 = NULL;
            LV_IMG_DECLARE(pic3);
            img_bg3 = lv_img_create(cont3,NULL);
            lv_img_set_src(img_bg3,&pic0);						
						lv_obj_set_pos(img_bg3,0,0);
						
						
            lv_obj_t * lable = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_align(lable, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lable, true);
            lv_label_set_text(lable,"#8B2500 :#");
            lv_obj_set_pos(lable,63,46);						
						
						lv_obj_t * day1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_align(day1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day1, true);
            lv_label_set_text(day1,"#FA8072 2022#");
            lv_obj_set_pos(day1,0,20);	
						
						lv_obj_t * day2 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_align(day2, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day2, true);
            lv_label_set_text(day2,"#FA8072 02#");
            lv_obj_set_pos(day2,43,20);	
						
						lv_obj_t * day3 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_align(day3, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(day3, true);
            lv_label_set_text(day3,"#FA8072 01#");
            lv_obj_set_pos(day3,70,20);	
						
						lv_obj_t * lab1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_align(lab1, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lab1, true);
            lv_label_set_text(lab1,"#FFB90F /#");
            lv_obj_set_pos(lab1,36,21);
						
						lv_obj_t * lab2 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_align(lab2, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(lab2, true);
            lv_label_set_text(lab2,"#FFB90F /#");
            lv_obj_set_pos(lab2,63,21);
						
						lv_obj_t * weekday = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_align(weekday, LV_LABEL_ALIGN_CENTER);       /*Center aligned lines*/
						lv_label_set_recolor(weekday, true);
            lv_label_set_text(weekday,"#00F5FF WED#");
            lv_obj_set_pos(weekday,90,20);	
						
//						lv_obj_t * img_bg1 = NULL;
//						LV_IMG_DECLARE(pic2);
//            img_bg1 = lv_img_create(cont,NULL);
//            lv_img_set_src(img_bg1,&pic2);
//						lv_obj_set_pos(img_bg1,0,60);

//						lv_obj_t * img_bg2 = NULL;
//						LV_IMG_DECLARE(pic3);
//            img_bg2 = lv_img_create(cont,NULL);
//            lv_img_set_src(img_bg2,&pic3);
//						lv_obj_set_pos(img_bg2,0,124);
						
//					  lv_refr_now(NULL);
//            t = lv_tick_get();
//            while(lv_tick_elaps(t) < 2000);
//						
//            //lv_obj_set_pos(cont,-1,-66);
//						lv_anim_t a;
//						lv_anim_init(&a);						
//		        /* 设置“动画制作”功能 */
//            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
//						lv_anim_set_var(&a, cont);
//						lv_anim_set_values(&a, 2, -58);						
//            /* 动画时长[ms] */
//            lv_anim_set_time(&a, 1000);
//						
//						//设置动画路径
//					  lv_anim_path_t path;
//            lv_anim_path_init(&path);
//            lv_anim_path_set_cb(&path, lv_anim_path_linear);
//            /* 在动画中设置路径 */
//            lv_anim_set_path(&a, &path);
//						lv_anim_start(&a);		//开始动画
}



int main(void)
{ 
  bool aa=true;
	bool bb=true;
	u8 tbuf[40];
	u8 t=0;
	RTC_TimeTypeDef RTC_TimeStruct;
	RTC_DateTypeDef RTC_DateStruct;
	int a=-1;
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);		  	        
	Lcd_Init();
	TIM3_Int_Init(999, 83);	   //用来给lvgl提供时钟(1ms)
	//First_show();            //播放开机画面
	KEY_Init();
	lv_init();
	lv_port_disp_init();	 
	//number();
	My_pic();             //显示时间界面
	uart_init(115200);		//串口初始化
	My_RTC_Init();	
	RTC_Set_WakeUp(RTC_WakeUpClock_CK_SPRE_16bits,0);		
 	TIM4_Int_Init(999, 167);
	flag_time=1;
	while(1)
	{	 
    if(KEY_Scan(0)==1)
    {  
			flag_time=0;     //关闭时间更新  
			time_gui_clear();//删除时间界面
			time_change_gui();//显示修改时间界面
		} 		
		else if(KEY_Scan(0)==2)
    {
//       bb=!bb;			
//			 if(bb==true)
//					 time_show();  
//       else
//				   time_gui_clear();
			   select_cont();
			
		}
		else if(KEY_Scan(0)==4)
    {
         change_time();
		}
		   
    //time_call();
//		t++;
//		if((t%20)==0)LED0=!LED0;	//Ã¿200ms,·­×ªÒ»´ÎLED0 
//		delay_ms(20);
	}
}

