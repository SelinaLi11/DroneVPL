#include "openDocumentation.h"

FileWidget::FileWidget(QWidget *parent /*= 0*/) : QWidget(parent)
{
    //---按钮与label
  //  openBtn = new QPushButton("OPEN", this);
   // connect(openBtn, SIGNAL(clicked()), this, SLOT(slotOpenFileDialog()));
    tipsLabel = new QLabel("open file...", this);

    //----showText
    showText = new QTextEdit();

    //---按钮与label布局
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addStretch();
    vLayout->addWidget(tipsLabel);
    vLayout->addWidget(openBtn);
    vLayout->addStretch();
    vLayout->setSpacing(10);
//  hLayout->setContentsMargins(10, 2, 10, 2);

    //---3个控件整体布局
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addLayout(vLayout);
    hLayout->addWidget(showText);
    hLayout->setSpacing(10);
    hLayout->setContentsMargins(10, 2, 10, 2);

    //--显示布局
    setLayout(hLayout);

    //---窗口属性
    resize(400, 300);
    setWindowTitle("help");
}

//------打开文件对话框
void FileWidget::slotOpenFileDialog()
{

   QString fileName = QFileDialog :: getOpenFileName(this, NULL, NULL, "*.h *.cpp *.txt");

   //---打开文件并读取文件内容
    QFile file(fileName);

    //--打开文件成功
   if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))
    {
        QTextStream textStream(&file);
      while (!textStream.atEnd())
       {
           //---QtextEdit按行显示文件内容
          showText->append(textStream.readLine());
      }
   }
  else    //---打开文件失败

      QMessageBox ::information(NULL, NULL, "open file error");
   }

