#include <QVector>
#include <QList>
#include <QSet>
#include <QMap>
#include <QTextStream>
#include <algorithm>
#include "book.h"

void vector_ctn()
{
    QTextStream out{stdout};

    QVector<int> vals{1, 2, 3, 4, 5};

    out << "The size of the vector is: " << vals.size() << endl;

    out << "The first item is: " << vals.first() << endl;
    out << "The last item is: " << vals.last() << endl;

    vals.append(6);
    vals.prepend(0);

    out << "Elements: ";

    for (int val : vals) {
        out << val << " ";
    }

    out << endl;
}

void list_ctn()
{
    QTextStream out{stdout};

    QList<QString> authors = {"Balzac", "Tolstoy",
                              "Gulbranssen", "London"};

    for (int i=0; i < authors.size(); ++i) {
        out << authors.at(i) << endl;
    }

    authors << "Galsworthy" << "Sienkiewicz";

    out << "***********************" << endl;

    std::sort(authors.begin(), authors.end());

    out << "Sorted:" << endl;
    for (QString author : authors) {
        out << author << endl;
    }
}

void list_string_ctn()
{
    QTextStream out{stdout};

    QString string{"coin, book, cup, pencil, clock, bookmark"};
    QStringList items = string.split(",");
    QStringListIterator it(items);

    while (it.hasNext()) {
        out << it.next().trimmed() << endl;
    }
}

void set_ctn()
{
    QTextStream out{stdout};

    QSet<QString> cols1{"yellow", "red", "blue"};
    QSet<QString> cols2{"blue", "pink", "orange"};

    out << "There are " << cols1.size() << " values in the set" << endl;

    cols1.insert("brown");

    out << "There are " << cols1.size() << " values in the set" << endl;

    cols1.unite(cols2);

    out << "There are " << cols1.size() << " values in the set" << endl;

    for (QString val : cols1) {
        out << val << endl;
    }

    QList<QString> lcols{cols1.values()};
    std::sort(lcols.begin(), lcols.end());

    out << "*********************" << endl;
    out << "Sorted:" << endl;

    for (QString val : lcols) {
        out << val << endl;
    }
}

void map_ctn()
{
    QTextStream out{stdout};

    QMap<QString, int> items{ {"coins", 5}, {"books", 3} };

    items.insert("bottles", 7);

    QList<int> values{items.values()};

    out << "Values:" << endl;

    for (int val : values) {
        out << val << endl;
    }

    QList<QString> keys{items.keys()};

    out << "Keys:" << endl;
    for (QString key : keys) {
        out << key << endl;
    }

    QMapIterator<QString, int> it(items);

    out << "Pairs:" << endl;

    while (it.hasNext()) {
        it.next();
        out << it.key() << ": " << it.value() << endl;
    }
}

bool compareByTitle(const Book &b1, const Book &b2) {
    return b1.getTitle() < b2.getTitle();
}

void custom_sort_ctn()
{
    QTextStream out{stdout};

    QList<Book> books = {
        Book("Jack London", "The Call of the Wild"),
        Book("Honoré de Balzac", "Father Goriot"),
        Book("Leo Tolstoy", "War and Peace"),
        Book("Gustave Flaubert", "Sentimental education"),
        Book("Guy de Maupassant", "Une vie"),
        Book("William Shakespeare", "Hamlet")
    };

    std::sort(books.begin(), books.end(), compareByTitle);

    for (Book book : books) {
        out << book.getAuthor() << ": " << book.getTitle() << endl;
    }
}

//int test_ctn(void) {
int test_ctn(void) {
//    vector_ctn();
//    list_ctn();
//    list_string_ctn();
//    set_ctn();
//    map_ctn();
    custom_sort_ctn();

    return 0;
}
