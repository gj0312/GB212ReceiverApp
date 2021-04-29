/********************************************************************************
** Form generated from reading UI file 'hj212dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HJ212DIALOG_H
#define UI_HJ212DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_HJ212Dialog
{
public:
    QGroupBox *hj212groupBox;
    QLabel *labelFlag;
    QLabel *labelMN;
    QLineEdit *lineEditFlag;
    QLineEdit *lineEditST;
    QLabel *labelST;
    QLineEdit *lineEditCN;
    QLabel *labelCN;
    QLineEdit *lineEditMN;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *labelDataTime;
    QLineEdit *lineEditDataTime;
    QLabel *labelQN;
    QLineEdit *lineEditQN;
    QGroupBox *tcpServerGroupBox;
    QLabel *labelPort;
    QPushButton *btnStop;
    QPushButton *btnListen;
    QLineEdit *lineEditPort;
    QGroupBox *logGroupBox;
    QTextEdit *textEditRead;

    void setupUi(QDialog *HJ212Dialog)
    {
        if (HJ212Dialog->objectName().isEmpty())
            HJ212Dialog->setObjectName(QString::fromUtf8("HJ212Dialog"));
        HJ212Dialog->resize(1302, 895);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HJ212Dialog->sizePolicy().hasHeightForWidth());
        HJ212Dialog->setSizePolicy(sizePolicy);
        hj212groupBox = new QGroupBox(HJ212Dialog);
        hj212groupBox->setObjectName(QString::fromUtf8("hj212groupBox"));
        hj212groupBox->setGeometry(QRect(10, 70, 711, 791));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hj212groupBox->sizePolicy().hasHeightForWidth());
        hj212groupBox->setSizePolicy(sizePolicy1);
        labelFlag = new QLabel(hj212groupBox);
        labelFlag->setObjectName(QString::fromUtf8("labelFlag"));
        labelFlag->setGeometry(QRect(20, 190, 41, 16));
        labelMN = new QLabel(hj212groupBox);
        labelMN->setObjectName(QString::fromUtf8("labelMN"));
        labelMN->setGeometry(QRect(20, 70, 31, 16));
        lineEditFlag = new QLineEdit(hj212groupBox);
        lineEditFlag->setObjectName(QString::fromUtf8("lineEditFlag"));
        lineEditFlag->setGeometry(QRect(90, 190, 111, 20));
        lineEditST = new QLineEdit(hj212groupBox);
        lineEditST->setObjectName(QString::fromUtf8("lineEditST"));
        lineEditST->setGeometry(QRect(90, 140, 113, 20));
        labelST = new QLabel(hj212groupBox);
        labelST->setObjectName(QString::fromUtf8("labelST"));
        labelST->setGeometry(QRect(20, 160, 31, 16));
        lineEditCN = new QLineEdit(hj212groupBox);
        lineEditCN->setObjectName(QString::fromUtf8("lineEditCN"));
        lineEditCN->setGeometry(QRect(90, 110, 113, 20));
        labelCN = new QLabel(hj212groupBox);
        labelCN->setObjectName(QString::fromUtf8("labelCN"));
        labelCN->setGeometry(QRect(20, 110, 31, 16));
        lineEditMN = new QLineEdit(hj212groupBox);
        lineEditMN->setObjectName(QString::fromUtf8("lineEditMN"));
        lineEditMN->setGeometry(QRect(90, 70, 113, 20));
        lineEditMN->setReadOnly(true);
        tableWidget = new QTableWidget(hj212groupBox);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 290, 701, 481));
        label = new QLabel(hj212groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 270, 101, 16));
        labelDataTime = new QLabel(hj212groupBox);
        labelDataTime->setObjectName(QString::fromUtf8("labelDataTime"));
        labelDataTime->setGeometry(QRect(10, 240, 71, 16));
        lineEditDataTime = new QLineEdit(hj212groupBox);
        lineEditDataTime->setObjectName(QString::fromUtf8("lineEditDataTime"));
        lineEditDataTime->setGeometry(QRect(90, 240, 281, 20));
        labelQN = new QLabel(hj212groupBox);
        labelQN->setObjectName(QString::fromUtf8("labelQN"));
        labelQN->setGeometry(QRect(20, 40, 54, 12));
        lineEditQN = new QLineEdit(hj212groupBox);
        lineEditQN->setObjectName(QString::fromUtf8("lineEditQN"));
        lineEditQN->setGeometry(QRect(90, 40, 331, 20));
        tcpServerGroupBox = new QGroupBox(HJ212Dialog);
        tcpServerGroupBox->setObjectName(QString::fromUtf8("tcpServerGroupBox"));
        tcpServerGroupBox->setGeometry(QRect(20, 0, 431, 71));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tcpServerGroupBox->sizePolicy().hasHeightForWidth());
        tcpServerGroupBox->setSizePolicy(sizePolicy2);
        labelPort = new QLabel(tcpServerGroupBox);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setGeometry(QRect(1, 31, 71, 16));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelPort->sizePolicy().hasHeightForWidth());
        labelPort->setSizePolicy(sizePolicy3);
        btnStop = new QPushButton(tcpServerGroupBox);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(330, 30, 91, 31));
        sizePolicy3.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy3);
        btnListen = new QPushButton(tcpServerGroupBox);
        btnListen->setObjectName(QString::fromUtf8("btnListen"));
        btnListen->setGeometry(QRect(230, 30, 80, 31));
        sizePolicy3.setHeightForWidth(btnListen->sizePolicy().hasHeightForWidth());
        btnListen->setSizePolicy(sizePolicy3);
        lineEditPort = new QLineEdit(tcpServerGroupBox);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(80, 30, 131, 22));
        sizePolicy3.setHeightForWidth(lineEditPort->sizePolicy().hasHeightForWidth());
        lineEditPort->setSizePolicy(sizePolicy3);
        logGroupBox = new QGroupBox(HJ212Dialog);
        logGroupBox->setObjectName(QString::fromUtf8("logGroupBox"));
        logGroupBox->setGeometry(QRect(760, 80, 511, 761));
        sizePolicy1.setHeightForWidth(logGroupBox->sizePolicy().hasHeightForWidth());
        logGroupBox->setSizePolicy(sizePolicy1);
        textEditRead = new QTextEdit(logGroupBox);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setGeometry(QRect(10, 20, 471, 591));

        retranslateUi(HJ212Dialog);

        QMetaObject::connectSlotsByName(HJ212Dialog);
    } // setupUi

    void retranslateUi(QDialog *HJ212Dialog)
    {
        HJ212Dialog->setWindowTitle(QCoreApplication::translate("HJ212Dialog", "HJ212-2017\346\234\215\345\212\241\345\231\250\347\253\257", nullptr));
        hj212groupBox->setTitle(QCoreApplication::translate("HJ212Dialog", "HJ212\346\212\245\346\226\207\350\247\243\346\236\220\346\230\276\347\244\272", nullptr));
        labelFlag->setText(QCoreApplication::translate("HJ212Dialog", "Flag\357\274\232", nullptr));
        labelMN->setText(QCoreApplication::translate("HJ212Dialog", "MN\357\274\232", nullptr));
        labelST->setText(QCoreApplication::translate("HJ212Dialog", "ST\357\274\232", nullptr));
        labelCN->setText(QCoreApplication::translate("HJ212Dialog", "CN\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("HJ212Dialog", "\350\257\267\346\261\202\346\227\266\351\227\264QN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("HJ212Dialog", "\346\225\260\346\215\256\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("HJ212Dialog", "\345\233\240\345\255\220\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("HJ212Dialog", "\347\233\221\346\265\213\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("HJ212Dialog", "\346\225\260\346\215\256\346\240\207\350\256\260", nullptr));
        label->setText(QCoreApplication::translate("HJ212Dialog", "\347\233\221\346\265\213\346\225\260\346\215\256\357\274\232", nullptr));
        labelDataTime->setText(QCoreApplication::translate("HJ212Dialog", "\346\225\260\346\215\256\346\227\266\351\227\264\357\274\232", nullptr));
        labelQN->setText(QCoreApplication::translate("HJ212Dialog", "QN\357\274\232", nullptr));
        tcpServerGroupBox->setTitle(QCoreApplication::translate("HJ212Dialog", "TCP\346\234\215\345\212\241\345\231\250", nullptr));
        labelPort->setText(QCoreApplication::translate("HJ212Dialog", "\347\233\221\345\220\254\347\253\257\345\217\243:", nullptr));
        btnStop->setText(QCoreApplication::translate("HJ212Dialog", "\346\226\255\345\274\200", nullptr));
        btnListen->setText(QCoreApplication::translate("HJ212Dialog", "\347\233\221\345\220\254", nullptr));
        logGroupBox->setTitle(QCoreApplication::translate("HJ212Dialog", "\346\216\245\346\224\266\346\227\245\345\277\227\346\212\245\346\226\207\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HJ212Dialog: public Ui_HJ212Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HJ212DIALOG_H
