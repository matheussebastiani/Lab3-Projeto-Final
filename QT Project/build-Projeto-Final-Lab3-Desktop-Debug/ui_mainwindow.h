/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *gases_label;
    QLabel *valor_temperatura_label;
    QLabel *valor_UV_label;
    QLabel *temperatura_label;
    QLabel *valor_poeira_label;
    QLabel *poeira_label;
    QLabel *valor_gases_label;
    QLabel *presenca_chuva_label;
    QLabel *chuva_label;
    QLabel *UV_label;
    QHBoxLayout *horizontalLayout;
    QLabel *imagem_1_label;
    QLabel *titulo_label;
    QLabel *imagem_2_label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(946, 465);
        MainWindow->setMinimumSize(QSize(946, 465));
        MainWindow->setMaximumSize(QSize(946, 465));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gases_label = new QLabel(centralwidget);
        gases_label->setObjectName(QString::fromUtf8("gases_label"));
        gases_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(gases_label, 1, 0, 1, 1);

        valor_temperatura_label = new QLabel(centralwidget);
        valor_temperatura_label->setObjectName(QString::fromUtf8("valor_temperatura_label"));
        valor_temperatura_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(valor_temperatura_label, 0, 1, 1, 1);

        valor_UV_label = new QLabel(centralwidget);
        valor_UV_label->setObjectName(QString::fromUtf8("valor_UV_label"));
        valor_UV_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(valor_UV_label, 4, 1, 1, 1);

        temperatura_label = new QLabel(centralwidget);
        temperatura_label->setObjectName(QString::fromUtf8("temperatura_label"));
        temperatura_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(temperatura_label, 0, 0, 1, 1);

        valor_poeira_label = new QLabel(centralwidget);
        valor_poeira_label->setObjectName(QString::fromUtf8("valor_poeira_label"));
        valor_poeira_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(valor_poeira_label, 2, 1, 1, 1);

        poeira_label = new QLabel(centralwidget);
        poeira_label->setObjectName(QString::fromUtf8("poeira_label"));
        poeira_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(poeira_label, 2, 0, 1, 1);

        valor_gases_label = new QLabel(centralwidget);
        valor_gases_label->setObjectName(QString::fromUtf8("valor_gases_label"));
        valor_gases_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(valor_gases_label, 1, 1, 1, 1);

        presenca_chuva_label = new QLabel(centralwidget);
        presenca_chuva_label->setObjectName(QString::fromUtf8("presenca_chuva_label"));
        presenca_chuva_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(presenca_chuva_label, 3, 1, 1, 1);

        chuva_label = new QLabel(centralwidget);
        chuva_label->setObjectName(QString::fromUtf8("chuva_label"));
        chuva_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(chuva_label, 3, 0, 1, 1);

        UV_label = new QLabel(centralwidget);
        UV_label->setObjectName(QString::fromUtf8("UV_label"));
        UV_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(UV_label, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imagem_1_label = new QLabel(centralwidget);
        imagem_1_label->setObjectName(QString::fromUtf8("imagem_1_label"));

        horizontalLayout->addWidget(imagem_1_label);

        titulo_label = new QLabel(centralwidget);
        titulo_label->setObjectName(QString::fromUtf8("titulo_label"));
        QFont font;
        font.setPointSize(31);
        font.setBold(true);
        titulo_label->setFont(font);
        titulo_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(titulo_label);

        imagem_2_label = new QLabel(centralwidget);
        imagem_2_label->setObjectName(QString::fromUtf8("imagem_2_label"));
        imagem_2_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(imagem_2_label);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 946, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Esta\303\247\303\243o Meteorol\303\263gica", nullptr));
        gases_label->setText(QCoreApplication::translate("MainWindow", "Concentra\303\247\303\243o de Gases liquefeitos de petr\303\263leo (ppm):", nullptr));
        valor_temperatura_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        valor_UV_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        temperatura_label->setText(QCoreApplication::translate("MainWindow", "Temperatura Ambiente (\302\272C):", nullptr));
        valor_poeira_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        poeira_label->setText(QCoreApplication::translate("MainWindow", "Concentra\303\247\303\243o de poeira na atmosfera:", nullptr));
        valor_gases_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        presenca_chuva_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        chuva_label->setText(QCoreApplication::translate("MainWindow", "Presen\303\247a de Chuva:", nullptr));
        UV_label->setText(QCoreApplication::translate("MainWindow", "N\303\255vel de Radia\303\247\303\243o UV:", nullptr));
        imagem_1_label->setText(QCoreApplication::translate("MainWindow", "Imagem 1", nullptr));
        titulo_label->setText(QCoreApplication::translate("MainWindow", "ESTA\303\207\303\203O METEOROL\303\223GICA", nullptr));
        imagem_2_label->setText(QCoreApplication::translate("MainWindow", "Imagem_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
