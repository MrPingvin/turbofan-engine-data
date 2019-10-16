#ifndef FORMULS_H
#define FORMULS_H

#include "iostream"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "fstream"
#include <QString>
#include "string"
#include <stdlib.h>
#include <QDebug>

using namespace std;

double FindARG(QString NumberElem)
{
    QString fortext = "C:\\Users\\roman\\Desktop\\QT\\lab2_2\\Ishodnie.txt";
    string answ="";
    QString buf = "";
    ifstream fileIN(fortext.toStdString());

    if (fileIN.is_open())
    {
        while (getline(fileIN, answ))
        {
            int i = 0;
            buf = ""; // буфер с названием переменной
            QString a = QString::fromStdString(answ); // преобразуем string в QString
            while (a.at(i) != "-")// указатель идет до знака "-"
                i++;
            i = i + 2; // доходим до буквы пропуская пробел и перезодим к самой букве
            while ( i != a.length()) // от начала слова до конца строки
            {
                buf.append(a.at(i)); // записываем в буфер слово
                i++;
            }
            if (buf == NumberElem) // если слово соответствует требуемому , ищем число
            {
                buf = "";// используем этот же буфер, но для числа
                i = 0;
                while (a.at(i) != ' ') // до пробела заполняем буфер цифрами
                {
                    buf.append(a.at(i));
                    i++;
                }
                fileIN.close();
                return buf.toDouble(); // преобразуем лежащее в буфере к даблу
            }
        }
    }
    fileIN.close();
    return 0; // если не нашел вернет -1
}

double Lvent(double K,double R, double Tn, double Pv, double Nven)//1
{
    return round((K/(K-1)*R*Tn*(pow(Pv,((K-1)/K))-1)*(1/Nven))*100)/100;
}
double TKVDvh(double Tn, double Lvent, double K, double R)//2
{
    return round((Tn+(Lvent/((K/(K-1))*R)))*100)/100;
}
double RKVDvh(double Pv, double Pn, double qvh, double qVNA, double qpereh)//3
{
    return round((Pv*Pn*(qvh*qVNA/qpereh))*100)/100;
}
double LKVD(double K, double R, double TKVDvh, double PKVD, double NKVD)//4
{
    return round(((K/(K-1))*R*TKVDvh*(pow(PKVD,(K-1)/K)-1)*(1/NKVD))*100)/100;
}
double LTVD(double LKVD, double KT)//5
{
    return round((LKVD/KT)*100)/100;
}
double Cad(double LTVD, double NTVD)//6
{
    return round((sqrt((2*LTVD)/NTVD))*100)/100;
}
double UTVDsr(double Y, double Cad, double ZstTVD)// 7 нет исходных данных для ZstTVD
{
    return round((Y*Cad*sqrt(1/ZstTVD))*100)/100;
}
double TTVDvih(double Tg, double LTVD, double Kg, double Rg) //8
{
    return round((Tg-(LTVD/((Kg/(Kg-1))*Rg)))*100)/100;
}
double Tl(double TTVDvih, double UTVDsr, double Kg, double Rg) //9
{
    return round((0.95*(TTVDvih+(UTVDsr*UTVDsr/(2*Kg*Rg/(Kg-1)))))*100)/100;
}
double Tohl(double TKVDvh, double LKVD)
{
    return round((TKVDvh+(LKVD/1005))*100)/100;
}
double Tlohl(double Tl, double Q, double Tohl) // 11
{
    return round((Tl/0.95 - Q*(Tl/0.95 - Tohl))*100)/100;
}
double DTVDsrhrl(double UTVDsr, double Pm, double F, double Kq, double qTVD) //12
{
    return round(((2*UTVDsr*Pm*F*Kq)/(qTVD*pow(10,6)))*100)/100;
}
double PgPtTVD(double LTVD, double Kg, double Rg, double Tg, double NTVD)//13 Rg/RtTVD
{
    return round((1/((1-(LTVD/(Kg/(Kg-1))*Rg*Tg*NTVD))))*100)/100;
}
double Pg(double PKVDvh, double PKVD, double qKS)//14
{
    return round((PKVDvh*PKVD*qKS)*100)/100;
}
double PtTVD(double Pg, double PgPtTVD)//15 из номера 13 взять
{
    return round((Pg/PgPtTVD)*100)/100;
}
double qL2TVD(double Kg, double L2TVD)//16
{
    return round((pow((Kg+1)/2,1/(Kg-1))*pow(1-((Kg-1)/(Kg+1))*L2TVD*L2TVD,1/(Kg-1))*L2TVD)*100)/100;
}
double FtTVD(double GgTVD, double GohlTVD, double GvKVD, double TTVDvih, double Sg, double RtTVD, double qL2TVD, double a2TVD) //17
{
    return round((((GgTVD+GohlTVD*GvKVD)*sqrt(TTVDvih))/(Sg*RtTVD*qL2TVD*sin(a2TVD)))*100)/100;
}
double hTVDvih(double FtTVD, double DTVDsr, double hrl) // 18
{
    return round((sqrt(FtTVD/(M_PI*(DTVDsr/hrl))))*100)/100;
}
double DvihTVDsr(double hTVDvih, double DTVDsr, double hrl) // 19
{
    return round((hTVDvih*(DTVDsr/hrl))*100)/100;
}
double DvihTVDnaruj(double DvihTVDsr, double FtTVD)//20
{
    return round((sqrt(DvihTVDsr*DvihTVDsr+(2/M_PI)*FtTVD))*100)/100;
}
double DTVDvtul(double DvihTVDsr, double FtTVD)//21
{
    return round((sqrt(DvihTVDsr*DvihTVDsr-(2/M_PI)*FtTVD))*100)/100;
}
double dvihTVD(double DTVDvtul, double DvihTVDnaruj)//22
{
    return round((DTVDvtul/DvihTVDnaruj)*100)/100;
}
double qLg(double Kg, double Lg)//23
{
    return round((pow((Kg+1)/2,1/(Kg-1))*pow(1-((Kg-1)/(Kg+1))*Lg*Lg,1/(Kg-1))*Lg)*100)/100;
}
double FgTVD(double GgTVD, double Tg, double Sg, double Pg, double qLg)//24
{
    return round(((GgTVD*sqrt(Tg))/(Sg*Pg*qLg))*100)/100;
}
double DvihTVDsr(double Dgsr)//25
{
    return round(Dgsr*100)/100;
}
double Dgnar(double Dgsr, double FgTVD)//26
{
    return round((sqrt(Dgsr*Dgsr+(2/M_PI)*FgTVD))*100)/100;
}
double Dgvt(double Dgsr, double FgTVD)//27
{
    return round((sqrt(Dgsr*Dgsr-(2/M_PI)*FgTVD))*100)/100;
}
double ngg(double UTVDsr, double Dgsr)//28
{
    return round(((60*UTVDsr)/(M_PI*Dgsr))*100)/100;
}
double TvihKVD(double TvhKVD, double LKVD)//29
{
    return round((TvhKVD+LKVD/1005)*100)/100;
}
double RvihKVD(double PKVD, double RvhKVD)//30
{
    return round((PKVD*RvhKVD)*100)/100;
}
double akrKVDvih(double K, double R, double TvihKVD)//31
{
    return round((sqrt(2*(K/(K+1))*R*TvihKVD))*100)/100;
}
double CvihKVD(double LvihKVD, double akrKVDvih)//32
{
    return round((LvihKVD*akrKVDvih)*100)/100;
}
double qLvihKVD(double K, double LvihKVD)//33
{
    return round((pow(((K+1)/2),1/(K-1))*pow(1-(K-1)/(K+1)*LvihKVD*LvihKVD,1/(K-1))*LvihKVD)*100)/100;
}
double FvihKVD(double GvKVD, double GohlTVD, double TvihKVD, double Sv, double RvihKVD, double qLvihKVD, double KG)
{
    return round((((GvKVD-GohlTVD*GvKVD)*sqrt(TvihKVD))/(Sv*RvihKVD*qLvihKVD*KG))*100)/100;
}
double NKVDmin1(double PKVD, double TvihKVD, double TvhKVD) // 35 NKVD = NKVD/(NKVD-1)
{
    return round((log(PKVD)/(log(TvihKVD/TvhKVD)))*100)/100;
}
double FKVD(double PKVD, double NKVD, double qLvihkvd, double qLvhKVD)//36 FKVD = FvhKVD/FvihKVD
{
    return round((pow(PKVD,(NKVD+1)/(2*NKVD))*(qLvihkvd/qLvhKVD))*100)/100;
}
double FvhKVD(double FKVD, double FvihKVD)//37
{
    return round((FKVD*FvihKVD)*100)/100;
}
double DkKVDvh(double FvhKVD, double dvtKVDvh)//38
{
    return round((sqrt((4*FvhKVD)/(M_PI*(1-dvtKVDvh*dvtKVDvh))))*100)/100;
}
double DvtKVDvh(double dvtKVDvh, double DKVDvh)//39
{
    return round((dvtKVDvh*DKVDvh)*100)/100;
}
double DsrKVDvh(double DKVDvh, double dvtKVDvh)//40
{
    return round((DKVDvh*sqrt((1+dvtKVDvh*dvtKVDvh)/2))*100)/100;
}
double hkKVDDk(double dvtKVDvih, double DKVDvh) //41.1
{
    return round((((1-dvtKVDvih)/2)*DKVDvh)*100)/100;
}
double hkKVDDsr(double FvihKVD, double DsrKVDvh)//41.2
{
    return round((FvihKVD/DsrKVDvh)*100)/100;
}
double hkKVDDvt(double dvtKVDvih, double DKVDvh)//41.3
{
    return round(((1/2)*((1/dvtKVDvih)-1)*DKVDvh)*100)/100;
}
double UkKVD(double DKVDvh, double ngg)//42
{
    return round(((M_PI*DKVDvh*ngg)/60)*100)/100;
}
double DKVDsrvihDk(double DkKVDvh, double hkKVD) // 43.1
{
    return round((DkKVDvh-hkKVD)*100)/100;
}
double DKVDsrvihDsr(double DsrKVDvh) //43.2
{
    return round((DsrKVDvh)*100)/100;
}
double DKVDsrvihDvt(double DvtKVDvh, double hkKVD)//43.3
{
    return round((DvtKVDvh+hkKVD)*100)/100;
}
double DTVDsr(double DvihTVDsr)//44
{
    return round((DvihTVDsr)*100)/100;
}
double ZKVD(double DTVDsr, double DKVDsr, double ZstTVD, double Kgg)
{
    return round((pow((DTVDsr/DKVDsr),2)*(ZstTVD/(Kgg*Kgg)))*100)/100;
}
// //////////////////////////////////////////////////////////
double DkKNDvh(double GvE, double Tn, double Sv, double Pn, double dvtvent, double qLvhvent, double KGvent, double qvh, double qVHA)
{
    return round(2*sqrt((GvE*sqrt(Tn))/(M_PI*Sv*Pn*(1-dvtvent*dvtvent)*qLvhvent*KGvent*qvh*qVHA))*100)/100;
}
double DsrKNDvh(double DkKNDvh, double DvtKNDvh)//2
{
    return round(((DkKNDvh+DvtKNDvh)/2)*100)/100;
}
double DvtKNDvh(double DkKNDvh, double dvtvent)//3
{
    return round((DkKNDvh*dvtvent)*100)/100;
}
double nKND(double Pv, double TvihKND, double Tn)//4
{
    return round((log10(Pv)/(log10(TvihKND/Tn)))*100)/100;
}
double FKND(double Pv, double nKND)//5
{
    return round((pow(Pv,((nKND+1)/(2*nKND))))*100)/100;
}
double FvihKND(double GvE, double Tn, double Sv, double Pn, double KGKND, double qLvhKND, double FKND, double qvh, double qVHA)//6
{
    return round(((GvE*sqrt(Tn))/(Sv*Pn*qvh*qVHA*qLvhKND*KGKND*FKND))*100)/100;
}
double DnarTNDvih()
{
    return 0.74;
}
double LTND(double m, double Lvent, double KT)
{
    return round((((m+1)*Lvent)/KT)*100)/100;
}
//double ()
//{
//    return round(()*100)/100;
//}
//double ()
//{
//    return round(()*100)/100;
//}
//double ()
//{
//    return round(()*100)/100;
//}
//double ()
//{
//    return round(()*100)/100;
//}
//double ()
//{
//    return round(()*100)/100;
//}
//double ()
//{
//    return round(()*100)/100;
//}
//double ()
//{
//    return round(()*100)/100;
//}
//double ()
//{
//    return round(()*100)/100;
//}

#endif // FORMULS_H
