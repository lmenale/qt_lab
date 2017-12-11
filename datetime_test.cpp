#include <QTextStream>
#include <QDate>
#include <QTime>
#include <ctime>

/*
Expression	Output for date
d       The day as a number without a leading zero (1 to 31)
dd      The day as a number with a leading zero (01 to 31)
ddd     The abbreviated localized day name (e.g. 'Mon' to 'Sun'). Uses QDate::shortDayName().
dddd	The long localized day name (e.g. 'Monday' to 'Sunday'). Uses QDate::longDayName().
M       The month as a number without a leading zero (1 to 12)
MM      The month as a number with a leading zero (01 to 12)
MMM     The abbreviated localized month name (e.g. 'Jan' to 'Dec'). Uses QDate::shortMonthName().
MMMM	The long localized month name (e.g. 'January' to 'December'). Uses QDate::longMonthName().
yy      The year as two digit number (00 to 99)
yyyy	The year as four digit number. If the year is negative, a minus sign is prepended in addition.

Expression	Output
h       the hour without a leading zero (0 to 23 or 1 to 12 if AM/PM display)
hh      the hour with a leading zero (00 to 23 or 01 to 12 if AM/PM display)
H       the hour without a leading zero (0 to 23, even with AM/PM display)
HH      the hour with a leading zero (00 to 23, even with AM/PM display)
m       the minute without a leading zero (0 to 59)
mm      the minute with a leading zero (00 to 59)
s       the second without a leading zero (0 to 59)
ss      the second with a leading zero (00 to 59)
z       the milliseconds without leading zeroes (0 to 999)
zzz     the milliseconds with leading zeroes (000 to 999)
AP or A	use AM/PM display. AP will be replaced by either "AM" or "PM".
ap or a	use am/pm display. ap will be replaced by either "am" or "pm".
t       the timezone (for example "CEST")
*/

void init_dt()
{
    QTextStream out{stdout};

    QDate dt1{2017, 12, 11};
    out << "The date is " << dt1.toString() << endl;

    QDate dt2;
    dt2.setDate(1970, 4, 4);
    out << "The date is " << dt2.toString() << endl;

    QTime tm1{17, 30, 12, 55};
    out << "The time is " << tm1.toString("hh:mm:ss.zzz") << endl;

    QTime tm2;
    tm2.setHMS(13, 52, 45, 155);
    out << "The time is " << tm2.toString("hh:mm:ss.zzz") << endl;
}

void current_dt()
{
    QTextStream out{stdout};

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    out << "Current date is: " << cd.toString() << endl;
    out << "Current time is: " << ct.toString() << endl;
}

void compare_dt()
{
    QTextStream out{stdout};

    QDate dt1{2017, 4, 5};
    QDate dt2{2016, 4, 5};

    if (dt1 < dt2) {
        out << dt1.toString() << " comes before "
            << dt2.toString() << endl;
    } else {
        out << dt1.toString() << " comes after "
            << dt2.toString() << endl;
    }
}

void leap_year()
{
    QTextStream out{stdout};

    QList<int> years({2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018});

    foreach (int year, years) {
        if (QDate::isLeapYear(year)) {
            out << year << " is a leap year" << endl;
        } else {
            out << year << " is not a leap year" << endl;
        }
    }
}

void format_dt()
{
    QTextStream out{stdout};

    QDate cd{QDate::currentDate()};

    out << "Today is " << cd.toString(Qt::TextDate) << endl;
    out << "Today is " << cd.toString(Qt::ISODate) << endl;
    out << "Today is " << cd.toString(Qt::SystemLocaleShortDate) << endl;
    out << "Today is " << cd.toString(Qt::SystemLocaleLongDate) << endl;
    out << "Today is " << cd.toString(Qt::DefaultLocaleShortDate) << endl;
    out << "Today is " << cd.toString(Qt::DefaultLocaleLongDate) << endl;
    out << "Today is " << cd.toString(Qt::SystemLocaleDate) << endl;
    out << "Today is " << cd.toString(Qt::LocaleDate) << endl;
}

void custom_fmt_dt()
{
    QTextStream out{stdout};

    QDate cd = QDate::currentDate();

    out << "Today is " << cd.toString("yyyy-MM-dd") << endl;
    out << "Today is " << cd.toString("yy/M/dd") << endl;
    out << "Today is " << cd.toString("d.M.yyyy") << endl;
    out << "Today is " << cd.toString("d-MMMM-yyyy") << endl;
}

void format_time()
{
    QTextStream out{stdout};

    QTime ct{QTime::currentTime()};

    out << "The time is " << ct.toString(Qt::TextDate) << endl;
    out << "The time is " << ct.toString(Qt::ISODate) << endl;
    out << "The time is " << ct.toString(Qt::SystemLocaleShortDate) << endl;
    out << "The time is " << ct.toString(Qt::SystemLocaleLongDate) << endl;
    out << "The time is " << ct.toString(Qt::DefaultLocaleShortDate) << endl;
    out << "The time is " << ct.toString(Qt::DefaultLocaleLongDate) << endl;
    out << "The time is " << ct.toString(Qt::SystemLocaleDate) << endl;
    out << "The time is " << ct.toString(Qt::LocaleDate) << endl;
}

void custom_fmt_time()
{
    QTextStream out{stdout};

    QTime ct{QTime::currentTime()};

    out << "The time is " << ct.toString("hh:mm:ss.zzz") << endl;
    out << "The time is " << ct.toString("h:m:s a") << endl;
    out << "The time is " << ct.toString("H:m:s A") << endl;
    out << "The time is " << ct.toString("h:m AP") << endl;

    out << "The version of Qt5 is " << qVersion() << endl;
}

void week_day()
{
    QTextStream out{stdout};

    QDate cd{QDate::currentDate()};
    int wd{cd.dayOfWeek()};

    out << "Today is " << QDate::shortDayName(wd) << endl;
    out << "Today is " << QDate::longDayName(wd) << endl;
}

void num_days()
{
    QTextStream out{stdout};
    QList<QString> months;

    months.append("January");
    months.append("February");
    months.append("March");
    months.append("April");
    months.append("May");
    months.append("June");
    months.append("July");
    months.append("August");
    months.append("September");
    months.append("October");
    months.append("November");
    months.append("December");

    QDate dt1{2017, 9, 18};
    QDate dt2{2017, 2, 11};
    QDate dt3{2017, 5, 1};
    QDate dt4{2017, 12, 11};
    QDate dt5{2017, 1, 21};

    out << "There are " << dt1.daysInMonth() << " days in "
        << months.at(dt1.month()-1) << endl;
    out << "There are " << dt2.daysInMonth() << " days in "
        << months.at(dt2.month()-1) << endl;
    out << "There are " << dt3.daysInMonth() << " days in "
        << months.at(dt3.month()-1) << endl;
    out << "There are " << dt4.daysInMonth() << " days in "
        << months.at(dt4.month()-1) << endl;
    out << "There are " << dt5.daysInMonth() << " days in "
        << months.at(dt5.month()-1) << endl;

    out << "There are " << dt1.daysInYear() << " days in year "
        << QString::number(dt1.year()) << endl;
}

void valid_dt()
{
    QTextStream out{stdout};

    QList<QDate> dates({QDate(2017, 5, 32), QDate(2017, 8, 1),
                        QDate(2017, 2, 30)});

    for (int i=0; i < dates.size(); i++) {

        if (dates.at(i).isValid()) {
            out << "Date " << i+1 << " is a valid date" << endl;
        } else {
            out << "Date " << i+1 << " is not a valid date" << endl;
        }
    }
}

void to_from_day()
{
    QTextStream out{stdout};

    QDate dt{2017, 10, 11};
    QDate nd{dt.addDays(55)};

    QDate xmas{2017, 12, 24};

    out << "55 days from " << dt.toString() << " is "
        << nd.toString() << endl;
    out << "There are " << QDate::currentDate().daysTo(xmas)
        << " days till Xmas" << endl;
}

void time_dt()
{
    QTextStream out{stdout};
    QDateTime cdt = QDateTime::currentDateTime();

    out << "The current datetime is " << cdt.toString() << endl;
    out << "The current date is " << cdt.date().toString() << endl;
    out << "The current time is " << cdt.time().toString() << endl;
}

void utc_local()
{
    QTextStream out{stdout};

    QDateTime cdt = QDateTime::currentDateTime();

    out << "Universal datetime: " << cdt.toUTC().toString() << endl;
    out << "Local datetime: " << cdt.toLocalTime().toString() << endl;
}

void unix_epoch()
{
    QTextStream out{stdout};

    time_t t{time(0)};
    out << t << endl;

    QDateTime dt;
    dt.setTime_t(t);
    out << dt.toString() << endl;

    QDateTime cd = QDateTime::currentDateTime();
    out << cd.toTime_t() << endl;
}

int main(void) {
//    init_dt();
//    current_dt();
//    compare_dt();
//    leap_year();
//    format_dt();
//    custom_fmt_dt();
//    format_time();
//    custom_fmt_time();
//    week_day();
//    num_days();
//    valid_dt();
//    to_from_day();
//    time_dt();
//    utc_local();
    unix_epoch();

    return 0;
}
