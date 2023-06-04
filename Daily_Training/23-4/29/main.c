#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 定义课程结构体
typedef struct Course
{
  char name;                        // 课程名称
  struct Course *prerequisites[50]; // 前驱课程
  int num_prerequisites;            // 前驱课程数量
  struct Course *successors[50];    // 后继课程
  int num_successors;               // 后继课程数量
} Course;
// 查找课程
Course *find_course(Course *course_dict[], char name)
{
  if (course_dict[name - 'A'] == NULL)
  {
    Course *course = (Course *)malloc(sizeof(Course));
    course->name = name;
    course->num_prerequisites = 0;
    course->num_successors = 0;
    course_dict[name - 'A'] = course;
  }
  return course_dict[name - 'A'];
}
// 拓扑排序输出课程安排
void topological_sort(Course *course_dict[], char teaching_plan[], int *teaching_plan_index, char visited[], char current_course_name)
{
  visited[current_course_name - 'A'] = 1;
  for (int i = 0; i < course_dict[current_course_name - 'A']->num_successors; i++)
  {
    char successor_name = course_dict[current_course_name - 'A']->successors[i]->name;
    if (!visited[successor_name - 'A'])
    {
      topological_sort(course_dict, teaching_plan, teaching_plan_index, visited, successor_name);
    }
  }
  teaching_plan[*teaching_plan_index] = current_course_name;
  (*teaching_plan_index)++;
}
// 课程安排排序
void sort_arrangement_order(Course *course_dict[], char teaching_plan[], char arrangement_order[])
{
  int teaching_plan_index = 0;
  char visited[26] = {0};
  for (int i = strlen(teaching_plan) - 1; i >= 0; i--)
  {
    char current_course_name = teaching_plan[i];
    if (!visited[current_course_name - 'A'])
    {
      topological_sort(course_dict, arrangement_order, &teaching_plan_index, visited, current_course_name);
    }
  }
}
int main()
{
  // 输入课程信息
  Course *course_dict[26] = {NULL};
  char input_str[1000];
  printf("Please input the course information and its predecessor and successor relationship (e.g., A B means offering course A before offering course B, separate multiple courses with spaces, and enter 'end' to end):\n");
  while (1)
  {
    fgets(input_str, 1000, stdin);
    if (strcmp(input_str, "end\n") == 0)
    {
      break;
    }
    int len = strlen(input_str) - 1;
    char courses[50] = {0};
    int courses_index = 0;
    for (int i = 0; i < len; i++)
    {
      if (input_str[i] != ' ')
      {
        courses[courses_index] = input_str[i];
        courses_index++;
      }
    }
    for (int i = 0; i < strlen(courses); i++)
    {
      Course *course = find_course(course_dict, courses[i]);
      if (i > 0)
      {
        course->prerequisites[course->num_prerequisites] = find_course(course_dict, courses[i - 1]);
        course->num_prerequisites++;
      }
      if (i < strlen(courses) - 1)
      {
        course->successors[course->num_successors] = find_course(course_dict, courses[i + 1]);
        course->num_successors++;
      }
    }
  }
  // 拓扑排序输出课程安排
  char teaching_plan[26] = {0};
  int teaching_plan_index = 0;
  char visited[26] = {0};
  for (int i = 0; i < 26; i++)
  {
    if (course_dict[i] != NULL && !visited[i])
    {
      topological_sort(course_dict, teaching_plan, &teaching_plan_index, visited, 'A' + i);
    }
  }
  printf("The teaching plan is:\n");
  printf("%s\n", teaching_plan);
  // 课程安排排序
  char arrangement_order[26] = {0};
  sort_arrangement_order(course_dict, teaching_plan, arrangement_order);
  printf("The arrangement order is:\n");
  printf("%s\n", arrangement_order);
  // 释放内存
  for (int i = 0; i < 26; i++)
  {
    if (course_dict[i] != NULL)
    {
      free(course_dict[i]);
    }
  }
  return 0;
}