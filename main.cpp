#include <iostream>
using namespace std;

const int timeSlots = 3;
int const V = 10;

int graph[V][V] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0}};

// function to check if a vertex can be assigned a certain color
bool isSafe(int vertex, int color[][timeSlots], int currentColor, int currentTimeSlot)
{

    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] && color[i][currentTimeSlot] == currentColor)
        {
            return false;
        }
    }

    return true;
}

// function to solve exam scheduling problem using backtracking
bool scheduleExamsUtil(int color[][timeSlots], int vertex)
{
    if (vertex == V)
    {
        return true;
    }
    for (int c = 0; c < 6; c++)
    {
        for (int t = 0; t < timeSlots; t++)
        {
            if (isSafe(vertex, color, c, t))
            {
                color[vertex][t] = c;
                if (scheduleExamsUtil(color, vertex + 1))
                    return true;
                color[vertex][t] = -1;
            }
        }
    }
    return false;
}

void printSchedule(int color[][timeSlots])
{
    cout << "Exam Schedule:" << endl;
    cout << "Monday:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < timeSlots; j++)
        {
            if (color[i][j] == 0)
            {
                cout << "Exam " << i << " in timeslot ";
                if (j == 0)
                {
                    cout << "9:00 AM - 11:00 AM\n";
                }
                else if (j == 1)
                {
                    cout << "11:30 AM - 1:30 PM\n";
                }
                else
                {
                    cout << "2:00 PM - 4:00 PM\n";
                }
            }
        }
    }

    cout << "\nTuesday:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < timeSlots; j++)
        {
            if (color[i][j] == 1)
            {
                cout << "Exam " << i << " in timeslot ";
                if (j == 0)
                {
                    cout << "9:00 AM - 11:00 AM\n";
                }
                else if (j == 1)
                {
                    cout << "11:30 AM - 1:30 PM\n";
                }
                else
                {
                    cout << "2:00 PM - 4:00 PM\n";
                }
            }
        }
    }

    cout << "\nWednesday:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < timeSlots; j++)
        {
            if (color[i][j] == 2)
            {
                cout << "Exam " << i << " in timeslot ";
                if (j == 0)
                {
                    cout << "9:00 AM - 11:00 AM\n";
                }
                else if (j == 1)
                {
                    cout << "11:30 AM - 1:30 PM\n";
                }
                else
                {
                    cout << "2:00 PM - 4:00 PM\n";
                }
            }
        }
    }

    cout << "\nThursday:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < timeSlots; j++)
        {
            if (color[i][j] == 3)
            {
                cout << "Exam " << i << " in timeslot ";
                if (j == 0)
                {
                    cout << "9:00 AM - 11:00 AM\n";
                }
                else if (j == 1)
                {
                    cout << "11:30 AM - 1:30 PM\n";
                }
                else
                {
                    cout << "2:00 PM - 4:00 PM\n";
                }
            }
        }
    }

    cout << "\nFriday:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < timeSlots; j++)
        {
            if (color[i][j] == 4)
            {
                cout << "Exam " << i << " in timeslot ";
                if (j == 0)
                {
                    cout << "9:00 AM - 11:00 AM\n";
                }
                else if (j == 1)
                {
                    cout << "11:30 AM - 1:30 PM\n";
                }
                else
                {
                    cout << "2:00 PM - 4:00 PM\n";
                }
            }
        }
    }

    cout << "\nSaturday:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < timeSlots; j++)
        {
            if (color[i][j] == 5)
            {
                cout << "Exam " << i << " in timeslot ";
                if (j == 0)
                {
                    cout << "9:00 AM - 11:00 AM\n";
                }
                else if (j == 1)
                {
                    cout << "11:30 AM - 1:30 PM\n";
                }
                else
                {
                    cout << "2:00 PM - 4:00 PM\n";
                }
            }
        }
    }
}
// function to solve exam scheduling problem using backtracking
void scheduleExams()
{
    int color[V][timeSlots];          // create a 2D color array for each vertex and time slot
    memset(color, -1, sizeof(color)); // initialize color array to -1

    // assign colors (days and time slots) to all nodes using backtracking
    if (scheduleExamsUtil(color, 0))
    {
        printSchedule(color);
    }
    else
    {
        cout << "No valid schedule possible." << endl;
    }
}

int main()
{
    scheduleExams();
    return 0;
}
