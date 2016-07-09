#include "qcopydirrecursively.h"

QCopyDirRecursively::QCopyDirRecursively(QObject *parent)
	: QObject(parent)
{

}

QCopyDirRecursively::~QCopyDirRecursively()
{

}

bool QCopyDirRecursively::copy(QString oldPath, QString newPath)
{
	qDebug() << oldPath;
	QList<QFileInfo> qfi = QDir(oldPath).entryInfoList();
	qDebug() << qfi.size();
	for (int i = 0; i < qfi.size(); ++i) {
		if (qfi[i].fileName() == "." || qfi[i].fileName() == "..") {
			continue;
		}
		else if (qfi[i].isDir()) {
			QDir(newPath).mkdir(qfi[i].fileName());
			copy(qfi[i].absoluteFilePath(), newPath + "/" + qfi[i].fileName());

		}
		else{
			QFile::copy(qfi[i].absoluteFilePath(), newPath + "/" + qfi[i].fileName());
		}
	}
	//qDebug() << QDir(oldPath).entryInfoList(QDir::NoDotAndDotDot);
	return true;
}
