
#include <QtCore/QCoreApplication>
#include <qcopydirrecursively.h>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QString path1("C:\\Users\\jieji\\Documents\\My Experiments\\Samples\\PictureRT");
	QString path2("C:\\Users\\jieji\\Desktop\\11");
	QCopyDirRecursively::copy(path1, path2);
	return a.exec();
}
