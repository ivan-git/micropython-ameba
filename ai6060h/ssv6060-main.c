/*
 * Copyright (c) 2014, SouthSilicon Valley Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         A very simple Contiki application showing how Contiki programs look
 * \author
 *         Adam Dunkels <adam@sics.se>
 */
#include "contiki.h"
#include <string.h>
#include <stdio.h> /* For printf() */
#include "gpio_api.h"
#include "atcmd.h"

int AT_Customer(stParam *param);
int AT_Customer2(stParam *param);
int AT_TCPSERVER_DEMO(stParam *param);
int AT_WIFIUART_DEMO(stParam *param);

at_cmd_info atcmd_info_tbl[] = 
{
	{"AT+CUSTOMER_CMD",	&AT_Customer},
	{"AT+CUSTOMER_CMD2=",	&AT_Customer2},
	{"AT+TCPSERVER_DEMO=",	&AT_TCPSERVER_DEMO},
	{"AT+WIFIUART_DEMO=",&AT_WIFIUART_DEMO},
    //
    {"",    NULL}
};

//extern void test1();
/*---------------------------------------------------------------------------*/
PROCESS(main_process, "main process");
/*---------------------------------------------------------------------------*/
PROCESS_NAME(tcpServerDemo_process);
PROCESS_NAME(wifiUartDemo_process);
/*---------------------------------------------------------------------------*/
AUTOSTART_PROCESSES(&main_process);
/*---------------------------------------------------------------------------*/
 void TurnOffAllLED()
 {
	 GPIO_CONF conf;
 
	 conf.dirt = OUTPUT;
	 conf.driving_en = 0;
	 conf.pull_en = 0;
 
	 pinMode(GPIO_1, conf);
	 digitalWrite(GPIO_1, 0);	 
	 pinMode(GPIO_3, conf);
	 digitalWrite(GPIO_3, 0);	 
	 pinMode(GPIO_8, conf);
	 digitalWrite(GPIO_8, 0);	 
 
	 return;
 }
/*---------------------------------------------------------------------------*/
 int SetLED (uint8_t nEnable)
 {
 	GPIO_CONF conf;

	conf.dirt = OUTPUT;
	conf.driving_en = 0;
	conf.pull_en = 0;
	
	pinMode(GPIO_1, conf);
 	if(nEnable == 0)
 	{
 		digitalWrite(GPIO_1, 0);
 	}
 	else
 	{
 		digitalWrite(GPIO_1, 1);
 	}
 	return ERROR_SUCCESS;
 }

int AT_Customer(stParam *param)
{
	printf("Call AT_Customer\n");
	return 0;
}
int AT_Customer2(stParam *param)
{
	int i = 0;
	printf("Call AT_Customer2\n");
	for(i=0; i<param->argc; i++)
	{
		printf("Param%d:%s\n", i+1, param->argv[i]);
	}
	return 0;
}
int AT_WIFIUART_DEMO(stParam *param)
{
	int i = 0;
	printf("Call AT_WIFIUART_DEMO\n");
	if(strcmp(param->argv[0] ,"enable") == 0) {
		process_start(&wifiUartDemo_process, NULL);
	} else if(strcmp(param->argv[0] ,"disable") == 0) {
		process_post_synch(&wifiUartDemo_process, PROCESS_EVENT_EXIT, NULL);
	} else {
		printf("wifi uart demo unknown param, please check\n");
	}
	return 0;
}
int AT_TCPSERVER_DEMO(stParam *param)
{
	int i = 0;
	printf("Call AT_TCPSERVER_DEMO\n");
	if(strcmp(param->argv[0] ,"enable") == 0) {
		process_start(&tcpServerDemo_process, NULL);
	} else if(strcmp(param->argv[0] ,"disable") == 0) {
		process_post_synch(&tcpServerDemo_process, PROCESS_EVENT_EXIT, NULL);
	} else {
		printf("tcp server demo unknown param, please check\n");
	}
	return 0;
}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(main_process, ev, data)
{
    //    EVENTMSG_DATA *pMesg = NULL;
    PROCESS_BEGIN();

    //printf("********hello main_process********\n");
    //test1();
  
    TurnOffAllLED();



    PROCESS_END();
}