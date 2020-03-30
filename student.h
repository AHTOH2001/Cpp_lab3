#ifndef STUDENT_H
#define STUDENT_H
#include <QByteArray>
#include <QDebug>

class student
{
public:
    student();
    int SetName1(QByteArray s);
    int SetName2(QByteArray s);
    int SetName3(QByteArray s);
    int SetScore1(char* s);
    int SetScore2(char* s);
    int SetScore3(char* s);
    static int NameCheck(QByteArray s)
    {
        if (strlen(s)<=1) return -1;
        if (!(s[0]>='A' && s[0]<='Z')) return -1;
        for (unsigned int i = 1;i<strlen(s);i++)
            if (!(s[i]>='a' && s[i]<='z')) return -1;
        return 0;
    }
    static int ScoreCheck(char* s)
    {
        if (strlen(s)==0 || strlen(s)>3) return -1;
        for (unsigned int i = 0;i<strlen(s);i++)
            if (!(s[i]>='0' && s[i]<='9')) return -1;
        if (strlen(s)!=1 && s[0]=='0') return -1;
        if (atoi(s)>100) return -1;
        return 0;
    }
    QByteArray GetName1();
    QByteArray GetName2();
    QByteArray GetName3();
    int GetScore1();
    int GetScore2();
    int GetScore3();
    student *next = NULL;
private:
    QByteArray _name1,_name2,_name3;
    int _score1,_score2,_score3;
};

#endif // STUDENT_H
