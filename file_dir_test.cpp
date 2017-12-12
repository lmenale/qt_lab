#include <QTextStream>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QDateTime>

int check_args(int argc, char *argv[], QString& filename)
{
    if (argc != 2) {
        qWarning("Usage: file_size file");
        return 1;
    }

    filename = argv[1];

    if (!QFile(filename).exists()) {

        qWarning("The file does not exist");
        return 1;
    }

    return 0;
}

void file_size_fd(QString filename)
{
    QTextStream out{stdout};

    QFileInfo fileinfo(filename);

    qint64 size = fileinfo.size();

    QString str = "The size is: %1 bytes";

    out << str.arg(size) << endl;
}

void read_file_fd(QString filename)
{
    QTextStream out{stdout};

    QFile file{filename};

    file.open(QIODevice::ReadOnly);

    QTextStream in{&file};

    while (!in.atEnd()) {

        QString line = in.readLine();
        out << line << endl;
    }

    file.close();
}

void write_file_fd()
{
    QTextStream out{stdout};

    QFile file{"distros.txt"};

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "Xubuntu" << endl;
        out << "Arch" << endl;
        out << "Debian" << endl;
        out << "Redhat" << endl;
        out << "Slackware" << endl;
    } else {
        qWarning("Could not open file");
    }

    file.close();
}

void copy_file_fd(QString filename, QString copy_filename)
{
    QTextStream out{stdout};

    QString source(filename);
    QString destin(copy_filename);

    QFile::copy(source, destin);
}

void info_file_fd(QString filename)
{
    QTextStream out(stdout);

    QFileInfo fileinfo(filename);

    QString group = fileinfo.group();
    QString owner = fileinfo.owner();
    QDateTime last_rea = fileinfo.lastRead();
    QDateTime last_mod = fileinfo.lastModified();
    QString absPath = fileinfo.absoluteFilePath();
    QString baseName = fileinfo.baseName();
    QString compBaseName = fileinfo.completeBaseName();
    QString fileName = fileinfo.fileName();
    QString suffix = fileinfo.suffix();
    QString compSuffix = fileinfo.completeSuffix();

    out << "Group: " << group << endl;
    out << "Owner: " << owner << endl;
    out << "Last read: " << last_rea.toString() << endl;
    out << "Last modified: " << last_mod.toString() << endl;
    out << "Absolute file path: " << absPath << endl;
    out << "Base name: " << baseName << endl;
    out << "Complete base name: " << compBaseName << endl;
    out << "File name: " << fileName << endl;
    out << "Suffix: " << suffix << endl;
    out << "Whole suffix: " << compSuffix << endl;
}

void dir_fd()
{
    QTextStream out{stdout};
    QDir dir;

    if (dir.mkdir("mydir")) {
        out << "mydir successfully created" << endl;
    }

    dir.mkdir("mydir2");

    if (dir.exists("mydir2")) {
        dir.rename("mydir2", "newdir");
    }

    dir.mkpath("temp/newdir");
}

void special_path_fd()
{
    QTextStream out{stdout};

    out << "Current path:" << QDir::currentPath() << endl;
    out << "Home path:" << QDir::homePath() << endl;
    out << "Temporary path:" << QDir::tempPath() << endl;
    out << "Root path:" << QDir::rootPath() << endl;
}

void list_dir_fd()
{
    QTextStream out(stdout);

    QDir dir{"."};

    dir.setFilter(QDir::Files | QDir::AllDirs);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();

    int max_size = 0;

    foreach (QFileInfo finfo, list) {
        QString name = finfo.fileName();
        int size = name.size();

        if (size > max_size) {
            max_size = size;
        }
    }

    int len = max_size + 2;

    out << QString("Filename").leftJustified(len).append("Bytes") << endl;

    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        QString str = fileInfo.fileName().leftJustified(len);
        str.append(QString("%1").arg(fileInfo.size()));
        out << str << endl;
    }
}

int main(int argc, char *argv[]) {
//int test_fd() {
    int result{0};

//    QString filename{""};
//    int result = check_args(argc, argv, filename);

//    if (result != 0) {
//        return 1;
//    }

//    result = file_size_fd(filename); // %{CurrentProject:Path}\LICENSE
//    read_file_fd(filename); // %{CurrentProject:Path}\data\colors.txt
//    write_file_fd(); // %{CurrentProject:Path}\data\colors.txt
//    QString copy_filename{"copy_colors.txt"};
//    copy_file_fd(filename, copy_filename); // %{CurrentProject:Path}\data\colors.txt
//    info_file_fd(filename); // %{CurrentProject:Path}\data\colors.txt
//    dir_fd();
//    special_path_fd();
    list_dir_fd();


    return result;
}
