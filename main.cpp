//====================================================
//              Study With Motaz Project
//====================================================

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

//====================================================
// Enums
//====================================================

enum enMainMenuOption
{
    AddNewCourse = 1,
    DisplayAllCourses = 2,
    SearchForACourse = 3,
    UpdateCourseInformation = 4,
    DeleteACourse = 5,
    DisplayChannelStatistics = 6,
    Exit = 7
};

enum enCourseStatus
{
    Planned = 1,
    InProgress = 2,
    Completed = 3
};

//====================================================
// Structs
//====================================================

struct stCourseInfo
{
    short CourseID = 0;
    string CourseName = "";
    string CourseDept = "";
    short NumberOfVideos = 0;
    enCourseStatus CourseStatus = enCourseStatus::Planned;
};

//====================================================
// Global Variables
//====================================================

const short CHANNELVIEWSSTATISTICS = 13430;
const short CHANNELVIDEOSSTATISTICS = 260;
const short CHANNELSUBSCRIBERSSTATISTICS = 181;

const short MAX_COURSES = 100;

stCourseInfo Courses[MAX_COURSES];

short CoursesCount = 0;

//====================================================
// Function Declarations
//====================================================

void PrintMainMenu();
void PerformMainMenuOption(enMainMenuOption MainMenuOption);
void PerformSystemExit();
void PerformAddNewCourse(stCourseInfo Courses[], short& CoursesCount);
void PerformDisplayAllCourses(stCourseInfo Courses[], short CoursesCount);
short FindACourseByID(stCourseInfo Courses[],short CoursesCount,short CourseID);
bool DoesCourseIDExist(stCourseInfo Courses[],short CoursesCount,short CourseID);
void PerformSearchForACourse(stCourseInfo Courses[],short CoursesCount);
void PerformUpdateCourseInformation(stCourseInfo Courses[],short CoursesCount);
void PerformDeleteCourse(stCourseInfo Courses[],short& CoursesCount);
void PerformDisplayChannelStatistics(stCourseInfo Courses[],short CoursesCount);
void GoBackToMainMenu();
short ReadMainMenuOption();
short ReadCourseStatus();
void ReadCourseInfo(stCourseInfo& CourseInfo);
void ReadCourseInfoForUpdate(stCourseInfo& CourseInfo);
void PrintCourseInfo(stCourseInfo CourseInfo);
string GetCourseStatusText(enCourseStatus CourseStatus);

//====================================================
// Main
//====================================================

int main()
{
    while (true)
    {
        PrintMainMenu();

        enMainMenuOption Choice =
            enMainMenuOption(ReadMainMenuOption());

        PerformMainMenuOption(Choice);
    }

    return 0;
}

//====================================================
// Main Menu
//====================================================

void PrintMainMenu()
{
    cout << "====================================================\n";
    cout << "\t\tStudy With Motaz\n";
    cout << "\t\tProg. Motaz Husain\n";
    cout << "\t\tHello Programmers ;-)\n";
    cout << "====================================================\n";
    cout << "(1). Add New Course.\n";
    cout << "(2). Display All Courses.\n";
    cout << "(3). Search For a Course.\n";
    cout << "(4). Update Course Information.\n";
    cout << "(5). Delete A Course.\n";
    cout << "(6). Display Channel Statistics.\n";
    cout << "(7). Exit.\n";
    cout << "====================================================\n";
}

//====================================================
// Perform Main Menu Option
//====================================================

void PerformMainMenuOption(enMainMenuOption MainMenuOption)
{
    switch (MainMenuOption)
    {

    case enMainMenuOption::AddNewCourse:

        PerformAddNewCourse(Courses, CoursesCount);
        GoBackToMainMenu();
        break;


    case enMainMenuOption::DisplayAllCourses:

        PerformDisplayAllCourses(Courses,CoursesCount);
        GoBackToMainMenu();
        break;


    case enMainMenuOption::SearchForACourse:

        PerformSearchForACourse(Courses,CoursesCount);
        GoBackToMainMenu();
        break;


    case enMainMenuOption::UpdateCourseInformation:

        PerformUpdateCourseInformation(Courses,CoursesCount);
        GoBackToMainMenu();
        break;


    case enMainMenuOption::DeleteACourse:

        PerformDeleteCourse(Courses,CoursesCount);
        GoBackToMainMenu();
        break;


    case enMainMenuOption::DisplayChannelStatistics:

        PerformDisplayChannelStatistics(Courses,CoursesCount);
        GoBackToMainMenu();
        break;


    case enMainMenuOption::Exit:
        PerformSystemExit();
        break;

    default:

        cout << "Invalid Choice!\n";
        cout << "Please Choose From 1 To 7.\n";
        GoBackToMainMenu();
        break;
    }
}

//====================================================
// Exit System
//====================================================

void PerformSystemExit()
{
    cout << "====================================================\n";
    cout << "\t\tSystem Exit.\n";
    cout << "====================================================\n";

    exit(0);
}

//====================================================
// Go Back To Main Menu
//====================================================

void GoBackToMainMenu()
{
    cout << "\nPress Enter To Go Back To Main Menu..........";

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n');

    cin.get();

    cout << endl;
}

//====================================================
// Read Main Menu Option
//====================================================

short ReadMainMenuOption()
{
    short Num;

    cout << "Plz Enter Your Choice [From 1 --> 7]: ";

    cin >> Num;

    cout << endl;

    return Num;
}

//====================================================
// Read Course Status
//====================================================

short ReadCourseStatus()
{
    short CourseStatusNum;

    do
    {
        cout << "Course Status:\n";

        cout << "[1] Planned\n";
        cout << "[2] In Progress\n";
        cout << "[3] Completed\n";

        cout << "Plz Enter Course Status [1 --> 3]: ";

        cin >> CourseStatusNum;

        if (CourseStatusNum < 1 ||
            CourseStatusNum > 3)
        {
            cout << "Invalid Course Status!\n";
            cout << "Please Try Again.\n\n";
        }

    } while (
        CourseStatusNum < 1 ||
        CourseStatusNum > 3);

    return CourseStatusNum;
}

//====================================================
// Read Course Information
//====================================================

void ReadCourseInfo(stCourseInfo& CourseInfo)
{
    cout << "Plz Enter Course ID : ";

    cin >> CourseInfo.CourseID;

    cout << endl;


    cout << "Plz Enter Course Name : ";

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n');

    getline(
        cin,
        CourseInfo.CourseName);

    cout << endl;


    cout << "Plz Enter Course Department : ";

    getline(
        cin,
        CourseInfo.CourseDept);

    cout << endl;


    do
    {
        cout
            << "Plz Enter The Number of Videos "
            << "in the Study With Motaz Channel : ";

        cin >> CourseInfo.NumberOfVideos;

        if (CourseInfo.NumberOfVideos < 0)
        {
            cout
                << "Number Of Videos "
                << "Cannot Be Negative!\n";
        }

    } while (CourseInfo.NumberOfVideos < 0);

    cout << endl;


    CourseInfo.CourseStatus =
        enCourseStatus(
            ReadCourseStatus());

    cout << endl;
}

//====================================================
// Read Course Information For Update
//====================================================

void ReadCourseInfoForUpdate(stCourseInfo& CourseInfo)
{
    cout << "Plz Enter New Course Name : ";

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n');

    getline(
        cin,
        CourseInfo.CourseName);

    cout << endl;


    cout
        << "Plz Enter New Course Department : ";

    getline(
        cin,
        CourseInfo.CourseDept);

    cout << endl;


    do
    {
        cout
            << "Plz Enter New Number Of Videos : ";

        cin >> CourseInfo.NumberOfVideos;

        if (CourseInfo.NumberOfVideos < 0)
        {
            cout
                << "Number Of Videos "
                << "Cannot Be Negative!\n";
        }

    } while (CourseInfo.NumberOfVideos < 0);

    cout << endl;


    CourseInfo.CourseStatus =
        enCourseStatus(
            ReadCourseStatus());
}

//====================================================
// Get Course Status As Text
//====================================================

string GetCourseStatusText(enCourseStatus CourseStatus)
{
    switch (CourseStatus)
    {

    case enCourseStatus::Planned:

        return "Planned";


    case enCourseStatus::InProgress:

        return "In Progress";


    case enCourseStatus::Completed:

        return "Completed";


    default:

        return "Unknown";
    }
}

//====================================================
// Print Course Information
//====================================================

void PrintCourseInfo(stCourseInfo CourseInfo)
{
    cout << "====================================================\n";

    cout
        << "\t"
        << CourseInfo.CourseName
        << "\n";

    cout << "====================================================\n";

    cout
        << "Course ID              : "
        << CourseInfo.CourseID
        << endl;

    cout
        << "Course Department      : "
        << CourseInfo.CourseDept
        << endl;

    cout
        << "Course's Num of Videos : "
        << CourseInfo.NumberOfVideos
        << endl;

    cout
        << "Course Status          : "
        << GetCourseStatusText(
            CourseInfo.CourseStatus)
        << endl;

    cout << "====================================================\n";
}

//====================================================
// Find Course By ID
//====================================================

short FindACourseByID(stCourseInfo Courses[],short CoursesCount,short CourseID)
{
    for (short i = 0; i < CoursesCount; i++) 
    {
        if (Courses[i].CourseID == CourseID)
        {
            return i;
        }
    }

    return -1;
}

//====================================================
// Check If Course ID Already Exists
//====================================================

bool DoesCourseIDExist(stCourseInfo Courses[],short CoursesCount,short CourseID)
{
    return
        FindACourseByID(Courses,CoursesCount,CourseID) != -1;
}

//====================================================
// Add New Course
//====================================================

void PerformAddNewCourse(stCourseInfo Courses[],short& CoursesCount)
{
    if (CoursesCount >= MAX_COURSES)
    {
        cout << "====================================================\n";

        cout << "Cannot Add More Courses.\n"
             << "The Courses List Is Full!\n";

        cout << "====================================================\n";

        return;
    }


    stCourseInfo NewCourse;


    cout << "====================================================\n";
    cout << "Adding New Course.....\n";
    cout << "====================================================\n";


    ReadCourseInfo(NewCourse);


    if (
        DoesCourseIDExist(
            Courses,
            CoursesCount,
            NewCourse.CourseID))
    {
        cout << "====================================================\n";

        cout
            << "Course ID Already Exists!\n"
            << "Course Was Not Added.\n";

        cout << "====================================================\n";

        return;
    }


    Courses[CoursesCount] =
        NewCourse;

    CoursesCount++;


    cout << "====================================================\n";
    cout << "Course Added Successfully.\n";
    cout << "====================================================\n";
}

//====================================================
// Display All Courses
//====================================================

void PerformDisplayAllCourses(stCourseInfo Courses[],short CoursesCount)
{
    if (CoursesCount == 0)
    {
        cout << "====================================================\n";
        cout << "No Available Courses!\n";
        cout << "====================================================\n";

        return;
    }


    cout << "====================================================\n";
    cout << "\t\tAll Courses\n";
    cout << "====================================================\n";


    for (
        short i = 0;
        i < CoursesCount;
        i++)
    {
        PrintCourseInfo(
            Courses[i]);
    }
}

//====================================================
// Search For A Course
//====================================================

void PerformSearchForACourse(stCourseInfo Courses[],short CoursesCount)
{
    short CourseID;


    cout << "====================================================\n";
    cout << "\t\tSearch For A Course\n";
    cout << "====================================================\n";


    cout << "Plz Enter Course ID : ";

    cin >> CourseID;

    cout << endl;


    short CourseIndex =
        FindACourseByID(
            Courses,
            CoursesCount,
            CourseID);


    if (CourseIndex != -1)
    {
        cout
            << "The Course You Are Searching For Is:\n";

        PrintCourseInfo(
            Courses[CourseIndex]);
    }
    else
    {
        cout << "Course Not Found!\n";
    }
}

//====================================================
// Update Course Information
//====================================================

void PerformUpdateCourseInformation(stCourseInfo Courses[],short CoursesCount)
{
    short CourseID;


    cout << "====================================================\n";
    cout << "\t\tUpdate Course Information\n";
    cout << "====================================================\n";


    cout << "Plz Enter Course ID To Update : ";

    cin >> CourseID;

    cout << endl;


    short CourseIndex =
        FindACourseByID(
            Courses,
            CoursesCount,
            CourseID);


    if (CourseIndex == -1)
    {
        cout << "Course Not Found!\n";

        return;
    }


    cout << "Current Course Information:\n";

    PrintCourseInfo(
        Courses[CourseIndex]);


    cout << "Enter New Course Information:\n";


    ReadCourseInfoForUpdate(
        Courses[CourseIndex]);


    cout << "====================================================\n";
    cout << "Course Updated Successfully!\n";
    cout << "====================================================\n";
}

//====================================================
// Delete Course
//====================================================

void PerformDeleteCourse(stCourseInfo Courses[],short& CoursesCount)
{
    short CourseID;


    cout << "====================================================\n";
    cout << "\t\tDelete A Course\n";
    cout << "====================================================\n";


    cout << "Plz Enter Course ID To Delete : ";

    cin >> CourseID;

    cout << endl;


    short CourseIndex =
        FindACourseByID(
            Courses,
            CoursesCount,
            CourseID);


    if (CourseIndex == -1)
    {
        cout << "Course Not Found!\n";

        return;
    }


    for (
        short i = CourseIndex;
        i < CoursesCount - 1;
        i++)
    {
        Courses[i] =
            Courses[i + 1];
    }


    CoursesCount--;


    // Reset last unused element.
    Courses[CoursesCount] =
        stCourseInfo();


    cout
        << "Course Deleted Successfully!\n";
}

//====================================================
// Display Channel Statistics
//====================================================

void PerformDisplayChannelStatistics(stCourseInfo Courses[],short CoursesCount)
{
    short CompletedCoursesCount = 0;


    for (
        short i = 0;
        i < CoursesCount;
        i++)
    {
        if (
            Courses[i].CourseStatus ==
            enCourseStatus::Completed)
        {
            CompletedCoursesCount++;
        }
    }


    cout << "====================================================\n";
    cout << "\t\tChannel Statistics\n";
    cout << "====================================================\n";


    cout
        << "Channel Views Statistics       : "
        << CHANNELVIEWSSTATISTICS
        << endl;

    cout
        << "Channel Videos Statistics      : "
        << CHANNELVIDEOSSTATISTICS
        << endl;

    cout
        << "Channel Subscribers Statistics : "
        << CHANNELSUBSCRIBERSSTATISTICS
        << endl;

    cout
        << "Courses Stored In System       : "
        << CoursesCount
        << endl;

    cout
        << "Completed Courses              : "
        << CompletedCoursesCount
        << endl;


    cout
        << "(As Of 26/7/2026 by Prog. Motaz Husain)"
        << endl;


    cout << "====================================================\n";
}