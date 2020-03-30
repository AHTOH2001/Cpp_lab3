#include "student.h"

student::student()
{

}
int student::SetName1(QByteArray s)
{
    if (NameCheck(s)) return -1;
    _name1 = s;
    return 0;
}
int student::SetName2(QByteArray s)
{
    if (NameCheck(s)) return -1;

    _name2 = s;
    return 0;
}
int student::SetName3(QByteArray s)
{
    if (NameCheck(s)) return -1;
    _name3 = s;
    return 0;
}
int student::SetScore1(char* s)
{
    if (ScoreCheck(s)) return -1;
    _score1 = atoi(s);
    return 0;
}
int student::SetScore2(char* s)
{
    if (ScoreCheck(s)) return -1;
    _score2 = atoi(s);
    return 0;
}
int student::SetScore3(char* s)
{
    if (ScoreCheck(s)) return -1;
    _score3 = atoi(s);
    return 0;
}
QByteArray student::GetName1()
{
    return _name1;
}
QByteArray student::GetName2()
{
    return _name2;
}
QByteArray student::GetName3()
{
    return _name3;
}
int student::GetScore1()
{
    return _score1;
}
int student::GetScore2()
{
    return _score2;
}
int student::GetScore3()
{
    return _score3;
}








