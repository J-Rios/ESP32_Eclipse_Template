#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define PIN_LED 13

void blink_task(void *pvParameter)
{
	printf("Blink Task initialized\n");

	printf("Configuring LED Pin\n");
    gpio_pad_select_gpio(PIN_LED);
    gpio_set_direction(PIN_LED, GPIO_MODE_OUTPUT);
    gpio_set_level(PIN_LED, 0);
    printf("LED Pin configured to digital output\n");

    while(1)
    {
    	printf("LED Pin off\n");
        gpio_set_level(PIN_LED, 0);
        vTaskDelay(1000/portTICK_PERIOD_MS);

        printf("LED Pin on\n");
        gpio_set_level(PIN_LED, 1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
	printf("\n\n----------------\n\n");
	printf("\nSystem Start\n");
	printf("\nCreating tasks...\n");
    xTaskCreate(&blink_task, "blink_task", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
}
