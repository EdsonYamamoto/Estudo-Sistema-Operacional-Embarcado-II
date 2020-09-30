/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

/* Used as a loop counter to create a very crude delay. */
#define mainDELAY_LOOP_COUNT		( 0xffffff )

/* The task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

void vTaskFunction(void* pvParameters);

const char* pcTextForTask1 = "Task 1 is running \r\n";
const char* pcTextForTask2 = "Task 2 is running \r\n";

/*-----------------------------------------------------------*/

int main( void )
{
	/* Create one of the two tasks. */

	//xTaskCreate(	vTask1,		/* Pointer to the function that implements the task. */
	//				"Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
	//				1000,		/* Stack depth - most small microcontrollers will use much less stack than this. */
	//				NULL,		/* We are not using the task parameter. */
	//				1,			/* This task will run at priority 1. */
	//				NULL );		/* We are not using the task handle. */

	/* Create the other task in exactly the same way. */
	// xTaskCreate( vTask2, "Task 2", 1000, NULL, 3, NULL );


	xTaskCreate(vTaskFunction,"task 1", 1000, (void*)pcTextForTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "task 2", 1000, (void*)pcTextForTask2, 1, NULL);

	/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();	

	/* The following line should never be reached because vTaskStartScheduler() 
	will only return if there was not enough FreeRTOS heap memory available to
	create the Idle and (if configured) Timer tasks.  Heap management, and
	techniques for trapping heap exhaustion, are described in the book text. */
	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
const char *pcTaskName = "Task 1 is running\r\n";
volatile uint32_t ul;

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( pcTaskName );

		/* Delay for a period. */
		//for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
		//{
			/* This loop is just a very crude delay implementation.  There is
			nothing to do in here.  Later exercises will replace this crude
			loop with a proper delay/sleep function. */
		//}

		//vTaskDelay(500, portTICK_PERIOD_MS);
	}
}
/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{
const char *pcTaskName = "Task 2 is running\r\n";
volatile uint32_t ul;

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( pcTaskName );

		///* Delay for a period. */
		//for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
		//{
			/* This loop is just a very crude delay implementation.  There is
			nothing to do in here.  Later exercises will replace this crude
			loop with a proper delay/sleep function. */
		//}

		vTaskDelay(1000, portTICK_PERIOD_MS);
	}
}

void vTaskFunction(void *pvParameters){
	char* pcTaskName;
	const TickType_t xDelay250ms = pdMS_TO_TICKS( (unsigned long) 250UL);

	pcTaskName = (char*)pvParameters;
	for (;;)
	{
		vPrintString(pcTaskName);
		vTaskDelay(xDelay250ms);
	}
	return;
}
