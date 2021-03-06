#include <QTextStream>
#define STR_EQUAL 0

void sample()
{
    QTextStream out{stdout};

    QString a{"love"};

    a.append(" chess");
    a.prepend("I ");

    out << a << endl;
    out << "The a string has " << a.count()
        << " characters" << endl;

    out << a.toUpper() << endl;
    out << a.toLower() << endl;
}

void init_str()
{
    QTextStream out{stdout};

    QString str1 = "The night train";
    out << str1 << endl;

    QString str2{"A yellow rose"};
    out << str2 << endl;

    std::string s1 = "A blue sky";
    QString str3 = s1.c_str();
    out << str3 << endl;

    std::string s2 = "A thick fog";
    QString str4 = QString::fromLatin1(s2.data(), s2.size());
    out << str4 << endl;

    char s3[] = "A deep forest";
    QString str5(s3);
    out << str5 << endl;
}

void access_str()
{
    QTextStream out{stdout};

    QString a{"Eagle"};

    out << a[0] << endl;
    out << a[4] << endl;

    out << a.at(0) << endl;
}

void length_str()
{
    QTextStream out{stdout};

    QString s1{"Eagle"};
    QString s2{"Eagle\n"};
    QString s3{"Eagle "};
    QString s4{"орел"};

    out << s1.length() << endl;
    out << s2.length() << endl;
    out << s3.length() << endl;
    out << s4.length() << endl;
}

void build_str()
{
    QTextStream out{stdout};

    QString s1{"There are %1 white roses"};
    int n = 12;

    out << s1.arg(n) << endl;

    QString s2{"The tree is %1 m high"};
    double h = 5.65;

    out << s2.arg(h) << endl;

    QString s3{"We have %1 lemons and %2 oranges"};
    int ln = 12;
    int on = 4;

    out << s3.arg(ln).arg(on) << endl;
}

void sub_str()
{
    QTextStream out{stdout};

    QString str{"The night train"};

    out << str.right(5) << endl;
    out << str.left(9) << endl;
    out << str.mid(4, 5) << endl;

    QString str2{"The big apple"};
    QStringRef sub{&str2, 0, 7};

    out << sub.toString() << endl;
}

void loop_str()
{
    QTextStream out{stdout};

    QString str{"There are many stars."};

    foreach (QChar qc, str) {
        out << qc << " ";
    }
    out << endl;

    for (QChar *it=str.begin(); it!=str.end(); ++it) {
        out << *it << " " ;
    }
    out << endl;

    for (int i = 0; i < str.size(); ++i) {
        out << str.at(i) << " ";
    }
    out << endl;
}

void compare_str()
{
    QTextStream out{stdout};

    QString a{"Rain"};
    QString b{"rain"};
    QString c{"rain\n"};

    if (QString::compare(a, b) == STR_EQUAL) {
        out << "a, b are equal" << endl;
    } else {
        out << "a, b are not equal" << endl;
    }

    out << "In case insensitive comparison:" << endl;

    if (QString::compare(a, b, Qt::CaseInsensitive) == STR_EQUAL) {
        out << "a, b are equal" << endl;
    } else {
        out << "a, b are not equal" << endl;
    }

    if (QString::compare(b, c) == STR_EQUAL) {
        out << "b, c are equal" << endl;
    } else {
        out << "b, c are not equal" << endl;
    }

    c.chop(1);

    out << "After removing the new line character" << endl;

    if (QString::compare(b, c) == STR_EQUAL) {
        out << "b, c are equal" << endl;
    } else {
        out << "b, c are not equal" << endl;
    }
}

void convert_str()
{
    QTextStream out{stdout};

    QString s1{"12"};
    QString s2{"15"};
    QString s3, s4;

    out << s1.toInt() + s2.toInt() << endl;

    int n1{30};
    int n2{40};

    out << s3.setNum(n1) + s4.setNum(n2) << endl;
    out << "Int: " << n1 + n2 << endl;
}

void letter_str()
{
    QTextStream out{stdout};

    int digits  = 0;
    int letters = 0;
    int spaces  = 0;
    int puncts  = 0;

    QString str{"7 white, 3 red roses."};

    foreach(QChar s, str) {

        if (s.isDigit()) {
            digits++;
        } else if (s.isLetter()) {
            letters++;
        } else if (s.isSpace()) {
            spaces++;
        } else if (s.isPunct()) {
            puncts++;
        }
    }

    out << QString("There are %1 characters").arg(str.count()) << endl;
    out << QString("There are %1 letters").arg(letters) << endl;
    out << QString("There are %1 digits").arg(digits) << endl;
    out << QString("There are %1 spaces").arg(spaces) << endl;
    out << QString("There are %1 punctuation characters").arg(puncts) << endl;
}

void modify_str()
{
    QTextStream out{stdout};

    QString str{"Lovely"};
    str.append(" season");

    out << str << endl;

    str.remove(10, 3);
    out << str << endl;

    str.replace(7, 3, "girl");
    out << str << endl;

    str.clear();

    if (str.isEmpty()) {
        out << "The string is empty" << endl;
    }
}

void right_align_str()
{
    QTextStream out{stdout};

    QString field1{"Name: "};
    QString field2{"Occupation: "};
    QString field3{"Residence: "};
    QString field4{"Marital status: "};

    int width = field4.size();

    out << field1.rightJustified(width, ' ') << "Robert\n";
    out << field2.rightJustified(width, ' ') << "programmer\n";
    out << field3.rightJustified(width, ' ') << "New York\n";
    out << field4.rightJustified(width, ' ') << "single\n";
}

int test_str(void) {
//    sample();
//    init_str();
//    access_str();
//    length_str();
//    build_str();
//    sub_str();
//    loop_str();
//    compare_str();
//    convert_str();
//    letter_str();
//    modify_str();
    right_align_str();

    return 0;
}
