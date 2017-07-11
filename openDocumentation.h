#ifndef FILE_WIDGET_H
#define FILE_WIDGET_H
#include <QFileDialog>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
#include <QIODevice>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTextStream>
#include <QMessageBox>

class FileWidget : public QWidget
{
        Q_OBJECT
public:
    explicit FileWidget(QWidget *parent = 0);

public slots:
   void slotOpenFileDialog();
private:
   QPushButton *openBtn;
   QLabel *tipsLabel;
   QTextEdit *showText;
};

#endif // FILE_WIDGET_H
