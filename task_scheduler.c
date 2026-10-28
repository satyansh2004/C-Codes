#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

typedef union
{
  struct
  {
    int sensor_data;
  } Sensor;

  struct
  {
    char messages[100];
  } Message;

  struct
  {
    enum
    {
      NORMAL,
      NOT_NORMAL
    } Health_state;
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

  int timer = 0;
  while (1)
  {
    if (timer != 5 && timer != 10) {
      read_sensor_data(buffer);
      for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%dC ", buffer[i].Sensor.sensor_data);
      }
      printf("\n");
    }

    if (timer == 5) {
      reciving_messages(&task_var);
      printf("%s\n", task_var.Message.messages);
    }

    if (timer == 10) {
      check_health(&task_var);
      if (task_var.Health.Health_state == NORMAL){
        printf("NORMAL\n");
      }
      else if (task_var.Health.Health_state == NOT_NORMAL) {
        printf("NOT NORMAL\n");
      }
      timer = 0;
    }

    sleep(1);
    timer++;
  }

  return 0;
}

void read_sensor_data(Task *buffer)
{
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    int random_sensor_data = (rand() % 100) - 10;
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
  int random_health_check = rand() % 2;

  if (random_health_check == 0)
  {
    task_var->Health.Health_state = NORMAL;
  } 
  else if (random_health_check == 1)
  {
    task_var->Health.Health_state = NOT_NORMAL;
  }
}
