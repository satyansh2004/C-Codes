#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
typedef enum
{
  NORMAL,
  NOT_NORMAL
} Health_state;

typedef union
{
  struct
  {
    int32_t sensor_data;
  } Sensor;

  struct
  {
    char messages[100];
  } Message;

  struct
  {
    Health_state current_health;
  } Health;

} Task;

void read_sensor_data(Task *buffer);
void reciving_messages(Task *task_var);
void check_health(Task *task_var);

int main()
{
  Task buffer[BUFFER_SIZE] = {0};
  Task task_var;

  srand(time(NULL));

  reciving_messages(&task_var);
  check_health(&task_var);

  int32_t timer = 0;
  while (1)
  {
    if (timer != 5 && timer != 10)
    {
      read_sensor_data(buffer);
      for (int32_t i = 0; i < BUFFER_SIZE; i++)
      {
        printf("%d ", buffer[i].Sensor.sensor_data);
      }
      printf("\n");
      sleep(1);
    }

    if (timer == 5)
    {
      reciving_messages(&task_var);
      printf("%s\n", task_var.Message.messages);
      sleep(1);
    }

    if (timer == 10)
    {
      check_health(&task_var);
      if (task_var.Health.current_health == 0) {
        printf("NORMAL\n");
      }
      else if (task_var.Health.current_health == 1) {
        printf("NOT NORMAL\n");
      }
      sleep(1);
      timer = 0;
    }

    timer++;
  }

  return 0;
}

void read_sensor_data(Task *buffer)
{
  for (int32_t i = 0; i < BUFFER_SIZE; i++)
  {
    int32_t random_sensor_data = (rand() % 100) - 10;
    buffer[i].Sensor.sensor_data = random_sensor_data;
  }
}

void reciving_messages(Task *task_var)
{
  char *curr_message = "Message";
  strcpy(task_var->Message.messages, curr_message);
}

void check_health(Task *task_var)
{
  int32_t random_health_check = rand() % 2;

  if (random_health_check == NORMAL) {
    task_var->Health.current_health = NORMAL;
  }
  else if (random_health_check == NOT_NORMAL) {
    task_var->Health.current_health = NOT_NORMAL;
  }
}