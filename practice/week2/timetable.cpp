#include <bits/stdc++.h>

using namespace std;

struct Teacher
{
    vector<int> preferenceList;
    int load = 0;
};

vector<Teacher> teachers;
vector<vector<int>> conflicts;
vector<int> courseAssignments;
int maxLoad = 0;

bool isConflict(int course, int assignedCourse)
{
    for (auto &conflict : conflicts)
    {
        if ((conflict[0] == course && conflict[1] == assignedCourse) || (conflict[0] == assignedCourse && conflict[1] == course))
        {
            return true;
        }
    }
    return false;
}

bool assignCourses(int courseIndex)
{
    if (courseIndex == courseAssignments.size())
    {
        maxLoad = (*min_element(teachers.begin(), teachers.end(), [](const Teacher &t1, const Teacher &t2){ return t1.load > t2.load; })).load;

        return true;
    }

    for (int i = 0; i < teachers.size(); ++i)
    {
        if (find(teachers[i].preferenceList.begin(), teachers[i].preferenceList.end(), courseIndex+1) != teachers[i].preferenceList.end())
        {
            bool conflict = false;
            for (int j = 0; j < courseAssignments.size(); ++j)
            {
                if (courseAssignments[j] != -1 && isConflict(courseIndex+1, courseAssignments[j]))
                {
                    conflict = true;
                    break;
                }
            }
            if (!conflict)
            {
                teachers[i].load++;
                courseAssignments[courseIndex] = i;
                if (assignCourses(courseIndex + 1))
                    return true;
                teachers[i].load--;
                courseAssignments[courseIndex] = -1;
            }
        }
    }
    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;

    teachers.resize(m);
    courseAssignments.assign(n, -1);

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        teachers[i].preferenceList.resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> teachers[i].preferenceList[j];
        }
    }

    int k;
    cin >> k;
    conflicts.resize(k);
    for (int i = 0; i < k; i++)
    {
        int course1, course2;
        cin >> course1 >> course2;
        conflicts[i] = {course1, course2};
    }

    if (assignCourses(0))
    {
        cout << maxLoad << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}