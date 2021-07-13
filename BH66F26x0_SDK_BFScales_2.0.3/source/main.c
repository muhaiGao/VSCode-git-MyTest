//  Copyright (C) 2020 New Wave Electronics (ShenZhen) LTD.

//*******************************************************************************************
//																							*
//                    ProductName:	BH66F2650-48LQFP_JPD-BFS200-LED蓝牙人体脂肪秤_NW1986   	*
//                    MCU Body:		BH66F2650-48LQFP-A		               	       		    *
//                    HT-IDE3000: 	V8.01	                                           		*
//                    Date:         2019/08/20                                    	   		*
//                    Author:       ghg                                      				*
//                    Company:		New Wave Eelectronics (ShenZhen) LTD.					*
//																							*
//*******************************************************************************************
//																							*
//              	 	Files Required: Omitted												*
//																							*
//*******************************************************************************************
//   Configuration Option Setting:                                                     		*
//*******************************************************************************************
//																							*
//   		 		Notes: 	1.Fsys = 4MHz(Extern) @3.3V									    *
//						   	2.WDT ENABLE (1S)												*
//							3.coding:UTF-8													*
//																							*
//*******************************************************************************************
//
//	Revision History:
//			1.Initial on 2019.08.20
//			2.在BH66F2650的基础上修改为BH66F2660 2020.07.10
//			  	a)更改库为BH66F2660_BFScales_NWA.lib
//				b)更改头文件为BH66F2660.h
//				c)送样checksum:C0BFH - 默认单位kg
//		第二次送样：
//    	送样原因：更新固件体重默认单位为lb.
//    	送样数量：5个IC
//    	CHECKSUM:  C15EH
//    	时    间：2020-07-23
//    	送样程序：《BH66F2660-48LQFP_京柏 BFS200 LED蓝牙体脂秤_NW1987_C15EH_单位LB_V00.MTP》
//#include "common.h"

#include "xMotion.h"

s8_m i2c_bus;
s8_m ic_addr;

s8_m I2C_Read(s8_m i2c_bus, s8_m ic_addr, u8_m addr, u8_m *data_m, u8_m len)
{
	
	return 1;	
}

 s8_m mir3da_event_send(XMOTION_EVENT event, s32_m data_m)
 {
 	 switch(event)
	 {
		 case EVENT_STEP_NOTIFY:
		 //printf(" [ step = %ld ].\r\n",data_m);//当前总步数
		 break;
		 
		 default:
		 	break;
	 }
	 
 	return 0;
 }
 
 s8_m mir3da_register_read(u8_m addr, u8_m *data_m, u8_m len)
 {
 	 s8_m ret;
 
	 ret = I2C_Read(1, 1, addr,data_m, len);//I2C_Read(i2c_bus, ic_addr, addr,data_m, len);
	 if(!ret)
	 	return -1;

 	return 0;	
 }
 
 s8_m mir3da_register_write(u8_m addr, u8_m data_m)
 {
 	return 0;	
 }
 
int main(void)
{
//    /* 1.Power on reset or abnormal reset. */
//    /* 2.WDT overflow reset. */
//	if (_to == 0 || _pdf ==0)
//	{
//        /* 1.Power on reset or abnormal reset. */
//		poweron_system_init();
//		// 上電后調用fun_BodyFatScalesSDK_PowerOn()函數
//		fun_BodyFatScalesSDK_PowerOn();
//		user_initial();
//	}
//	else
//	{
//		/* 2.WDT overflow reset.*/
//		GCC_CLRWDT();
//		/* 睡眠唤醒后进入TASK_SCALES模式检测上称状态 */
//		gu8_worktasks = TASK_SCALES;
//	}
//	//主循環
//	while(1)
//	{
//		GCC_CLRWDT();
//		// 主LOOP循環調用 fun_BodyFatScalesSDK()
//		fun_BodyFatScalesSDK();
//
//		switch(gu8_worktasks)
//		{
//			case TASK_STARTUP:
//				task_scalesstartup();
//				break;
//
//			case TASK_LOWBATTERY:
//				task_scaleslowbattry();
//				break;
//
//			case TASK_SCALES:
//				task_bodyfatscales();
//				fun_UserProtocol();
//    			key_scan();
//				break;
//
//			case TASK_SLEEP:
//				task_scales2sleep();
//				break;
//
//			case TASK_WEIGHT_AUTOON:
//				task_scaleswakeup();
//				break;
//
//			default:
//				gu8_worktasks = TASK_SCALES;
//				break;
//		}
//
//		/* LED display mode and set display content */
//		fun_diaplay_mode();
//
//		/* Is it time to shut down ? */
//		is_timedshutdown();


		/* For Debug */
	
		xMotion_Init();
		xMotion_Clear_Pedometer_Value();
//	}

	return 0;
}
