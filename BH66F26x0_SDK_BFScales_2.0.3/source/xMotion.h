/*******************************************************************************/
 /**
  ******************************************************************************
  * @file    xMotion.h
  * @author  ycwang@miramems.com
  * @version 1.6.0
  * @date    2019-05-29
  * @brief
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MiraMEMS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2014-2017 MiraMEMS</center></h2>
  */
/*******************************************************************************/
#ifndef __XMOTION_h
#define __XMOTION_h

/*******************************************************************************
Includes
********************************************************************************/
#include "mira_std.h"

/*******************************************************************************
Macro definitions - Algorithm Build Options
********************************************************************************/
#define ANDROID             0

#define PEDOMETER_ENABLE    1
#define FALL_ENABLE         0
#define SLEEP_ENABLE        0
#define SEDENTARY_ENABLE    0
#define FLIP_ENABLE         0
#define RAISE_ENABLE        0
#define SHAKE_ENABLE        0
#define TURN_ENABLE         0

#if PEDOMETER_ENABLE
#define CALORIE_ENABLE      1
#define ACTION_ENABLE       1
#endif
/*******************************************************************************
Typedef definitions
********************************************************************************/
typedef enum {
  EVENT_NONE,
  EVENT_STEP_NOTIFY,
  EVENT_FALL_NOTIFY,
  EVENT_SLEEP_NOTIFY,
  EVENT_ACTION_NOTIFY,
  EVENT_SEDENTARY_NOTIFY,
  EVENT_CALORIE_NOTIFY,
  EVENT_FLIP_NOTIFY,
  EVENT_RAISE_NOTIFY,
  EVENT_TURN_NOTIFY,
  EVENT_SHAKE_NOTIFY
}XMOTION_EVENT;

typedef enum {
  NONE_X,
  PEDOMETER_X,
  FALL_X,
  SLEEP_X,
  ACTION_X,
  SEDENTARY_X,
  CALORIE_X,
  FLIP_X,
  RAISE_X,
  TURN_X,
  SHAKE_X
}Algorithm;

typedef enum {
  DISABLE_X,
  ENABLE_X
}SwitchCmd;

typedef enum {
  SLEEP_AWAKE,
  SLEEP_LIGHT_1,
  SLEEP_DEEP,
  SLEEP_LIGHT_2,
  SLEEP_UNWEAR
}Tsleep;	//sleep state

typedef enum {
  MOTIONLESS,
  WALK,
  RUN
}Taction;	//action state

typedef enum {
  RAISE_NONE = 0,
  RAISE_ON   = 1,
  RAISE_OFF  = -1
}Traise;	//raise state

typedef enum {
  SHAKE_NONE  = 0,
  SHAKE_RIGHT = 1,
  SHAKE_LEFT  = 1<<1,
  SHAKE_FRONT = 1<<2,
  SHAKE_BACK  = 1<<3,
  SHAKE_UP    = 1<<4,
  SHAKE_DOWN  = 1<<5
}Tshake;	//shake state

typedef enum {
  TURN_NONE = 0,
  TURN_NEXT = 1,
  TURN_LAST = -1,
}Tturn;	//turn state

typedef enum{
  DEBUG_ERR = 1,	
  DEBUG_MSG = 1<<1,
  DEBUG_DATA= 1<<2,
  DEBUG_RAW = 1<<3,
}Tdebug;

typedef enum{
  MODE_I2C,	
  MODE_SPI_3,
  MODE_SPI_4,
}Tmode;

extern s8_m mir3da_event_send(XMOTION_EVENT event, s32_m data_m);
extern s8_m mir3da_register_read(u8_m addr, u8_m *data_m, u8_m len);
extern s8_m mir3da_register_write(u8_m addr, u8_m data_m);

/*******************************************************************************
Global variables and functions
********************************************************************************/

/*******************************************************************************
* Function Name: xMotion_Init
* Description  : This function initializes the xMotion.
* Arguments    : *ops - the point to the xMotion_op_s structure
* Return Value : 0: OK; -1: Type Error; -2: OP Error; -3: Chip Error
********************************************************************************/
s8_m xMotion_Init(void);

#if PEDOMETER_ENABLE
/*******************************************************************************
* Function Name: xMotion_Clear_Pedometer_Value
* Description  : This function clears pedometer value.
* Arguments    : None
* Return Value : None
********************************************************************************/
void xMotion_Clear_Pedometer_Value(void);

/*******************************************************************************
* Function Name: xMotion_Set_Pedometer_Param
* Description  : This function set pedometer's param.
* Arguments    : debounce_step start steps' recording at least defined steps found
* Return Value : None
********************************************************************************/
void xMotion_Set_Pedometer_Param(u8_m debounce_step);
#endif

#if SEDENTARY_ENABLE
/*******************************************************************************
* Function Name: xMotion_Set_Sedentary_Parma
* Description  : This function sets sedentary parmas.
* Arguments    : time - the time to monitor sedentary, default is 30 mins(1~120)
                 interval - the interval to report event, default is 0 mins(0~30)
* Return Value : None
********************************************************************************/
void xMotion_Set_Sedentary_Parma(u16_m time, u16_m interval);
#endif

#if CALORIE_ENABLE
/*******************************************************************************
* Function Name: xMotion_Set_Calorie_Parma
* Description  : This function sets calorie parmas.
* Arguments    : height - the user's height, default is 180 cm
                 weight - the user's weight, default is 70 kg
* Return Value : None
********************************************************************************/
void xMotion_Set_Calorie_Parma(u16_m height, u16_m weight);

/*******************************************************************************
* Function Name: xMotion_Clear_Calorie_Value
* Description  : This function clears calorie value.
* Arguments    : None
* Return Value : None
********************************************************************************/
void xMotion_Clear_Calorie_Value(void);
#endif

#if RAISE_ENABLE
/*******************************************************************************
* Function Name: xMotion_Set_Raise_Parma
* Description  : This function sets raise parmas.
* Arguments    : dir - direction of coordinate axes, default is 0 (0~15)
* Return Value : None
********************************************************************************/
void xMotion_Set_Raise_Parma(u8_m dir);
#endif

#if SHAKE_ENABLE
/*******************************************************************************
* Function Name: xMotion_Set_Shake_Parma
* Description  : This function sets shark parmas.
* Arguments    : level - the sensitivity(1~6), default is 2
* Return Value : None
********************************************************************************/
void xMotion_Set_Shake_Parma(u8_m level);
#endif

#if FALL_ENABLE
/*******************************************************************************
* Function Name: xMotion_Set_Fall_Parma
* Description  : This function sets fall parmas.
* Arguments    : level - the sensitivity(1~5), default is 3
* Return Value : None
********************************************************************************/
void xMotion_Set_Fall_Parma(u8_m level);
#endif

#if FLIP_ENABLE
/*******************************************************************************
* Function Name: xMotion_Set_Flip_Parma
* Description  : This function sets flip parmas.
* Arguments    : dir - direction of coordinate axes, default is 0 (0~15)
* Return Value : None
********************************************************************************/
void xMotion_Set_Flip_Parma(u8_m dir);
#endif

#if TURN_ENABLE
/*******************************************************************************
* Function Name: xMotion_Set_Turn_Parma
* Description  : This function sets turn parmas.
* Arguments    : dir - direction of coordinate axes, default is 0 (0~15)
* Return Value : None
********************************************************************************/
void xMotion_Set_Turn_Parma(u8_m dir);
#endif
/*******************************************************************************
* Function Name: xMotion_Control
* Description  : This function initializes the xMotion.
* Arguments    : name - select which algorithm to control
                 cmd - enable/disable
* Return Value : None
********************************************************************************/
void xMotion_Control(Algorithm name, SwitchCmd cmd);

#if ANDROID
/*******************************************************************************
* Function Name: xMotion_Process_Data
* Description  : This function runs the xMotion at 20Hz.
* Arguments    : pData: acceleration data
* Return Value : None
********************************************************************************/
void xMotion_Process_Data(AccData* pData);
#else
/*******************************************************************************
* Function Name: xMotion_Process_Data
* Description  : This function runs the xMotion at 20Hz.
* Arguments    : None
* Return Value : None
********************************************************************************/
void xMotion_Process_Data(void);
#endif 
/*******************************************************************************
* Function Name: xMotion_Get_Version
* Description  : This function gets xMotion version.
* Arguments    : *ver - the point to char string of the version Num
* Return Value : None
********************************************************************************/
void xMotion_Get_Version(u8_m *ver);

/*******************************************************************************
* Function Name: xMotion_QueryControl
* Description  : This function gets algorithm state.
* Arguments    : name - select which algorithm
* Return Value : SwitchCmd - enable/disable
********************************************************************************/
SwitchCmd xMotion_QueryControl(Algorithm name);

/*******************************************************************************
* Function Name: xMotion_QueryEvent
* Description  : This function gets algorithm value.
* Arguments    : event - select which event
* Return Value : Correspond event value
********************************************************************************/
s32_m xMotion_QueryEvent(XMOTION_EVENT event);

/*******************************************************************************
* Function Name: xMotion_Set_Debug_Level
* Description  : This function sets the debug log level
* Arguments    : Log level
* Return Value : None
********************************************************************************/
void xMotion_Set_Debug_Level(Tdebug level);

#if !ANDROID
/*******************************************************************************
* Function Name: xMotion_Set_SPI_I2C
* Description  : This function set the communication mode.
* Arguments    : Default is I2C mode.
* Return Value : None
********************************************************************************/
void xMotion_Set_SPI_I2C(Tmode mod);

/*******************************************************************************
* Function Name: xMotion_Chip_Read_XYZ
* Description  : This function reads the chip xyz.
* Arguments    : x, y, z - acc data
* Return Value : 0: OK; -1: Error
********************************************************************************/
s8_m xMotion_Chip_Read_XYZ(s16_m *x,s16_m *y,s16_m *z);

/*******************************************************************************
* Function Name: xMotion_Buffer_Read_XYZ
* Description  : This function reads the buffer xyz.
* Arguments    : x, y, z - acc data
* Return Value : None
********************************************************************************/
void xMotion_Buffer_Read_XYZ(s16_m *x,s16_m *y,s16_m *z);

/*******************************************************************************
* Function Name: xMotion_Chip_Calibrate_Offset
* Description  : This function calibrates the offset.
* Arguments    : None
* Return Value : 0: OK; -1: Error
********************************************************************************/
s8_m xMotion_Chip_Calibrate_Offset(void);

/*******************************************************************************
* Function Name: xMotion_Chip_Power_On
* Description  : This function enables the chip.
* Arguments    : None
* Return Value : 0: OK; -1: Error
********************************************************************************/
s8_m xMotion_Chip_Power_On(void);

/*******************************************************************************
* Function Name: xMotion_Chip_Power_Off
* Description  : This function disables on the chip.
* Arguments    : None
* Return Value : 0: OK; -1: Error
********************************************************************************/
s8_m xMotion_Chip_Power_Off(void);

/*******************************************************************************
* Function Name: xMotion_Open_Low_Power
* Description  : This function only supports da270.
* Arguments    : num - 0:INT1 or 1:INT2
* Return Value : 0: OK; -1: Error
********************************************************************************/
s8_m xMotion_Open_Low_Power(u8_m num);

/*******************************************************************************
* Function Name: xMotion_Close_Low_Power
* Description  : This function only supports da270.
* Arguments    : num - 0:INT1 or 1:INT2
* Return Value : 0: OK; -1: Error
********************************************************************************/
s8_m xMotion_Close_Low_Power(u8_m num);

/*******************************************************************************
* Function Name: xMotion_INT_Process_Data
* Description  : This function is used in conjunction with low power interrupt.
* Arguments    : None
* Return Value : None
********************************************************************************/
void xMotion_INT_Process_Data(void);

/*******************************************************************************
* Function Name: xMotion_FIFO_Read_XYZ
* Description  : This function reads the FIFO xyz.
* Arguments    : x, y, z - acc data
* Return Value : Data num
********************************************************************************/
u8_m xMotion_FIFO_Read_XYZ(s16_m x[32],s16_m y[32],s16_m z[32]);
#endif 

#endif 
