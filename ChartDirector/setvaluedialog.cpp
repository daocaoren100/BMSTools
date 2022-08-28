#include "setvaluedialog.h"
#include "ui_setvaluedialog.h"

#include "../Core/Public.h"

enum setColumnList{
    SET_VALUE_VID = 0,  //vid
    SET_VALUE_NAME,     //名称
    SET_VALUE_UNIT,     //单位
    SET_VALUE_FACTOR,   //因数
    SET_VALUE_OFFSET,   //偏移量
    SET_VALUE_COLOR,    //颜色
    SET_VALUE_RELEVANCE,//关联
    COLUMU_NUM          //总行数
};

SetValueDialog::SetValueDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetValueDialog)
{
    ui->setupUi(this);

    ui->tabWidget->setTabText(0, tr("Chart VID"));
    ui->tabWidget->setTabText(1, tr("Chart config"));

    //VID数据初始化
    for(int i = 0; i < 20; i++)
    {
        m_chartData[i].vid = 0;
        ZeroMemory(m_chartData[i].name, name_SIZE);
        ZeroMemory(m_chartData[i].unit, unit_SIZE);
        m_chartData[i].factor = 1;
        m_chartData[i].offset = 0;
        m_chartData[i].color = 0;
        m_chartData[i].relevance = 0;
    }

    TableInit();
}

SetValueDialog::~SetValueDialog()
{
    delete ui;
}

void SetValueDialog::TableInit()
{
    ui->tableWidget->setColumnCount(COLUMU_NUM);//设置列数
    //ui->tableWidget_main->setRowCount(3000);//设置行数

    /*设置列名*/
    QStringList headers;
    headers<<QString_C("VID")
           <<QString_C("NAME")
           <<QString_C("Unit")
           <<QString_C("Factor")
           <<QString_C("Offset")
           <<QString_C("Color")
           <<QString_C("Relevance");
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->setColumnWidth(SET_VALUE_VID, 50);
    ui->tableWidget->setColumnWidth(SET_VALUE_NAME, 100);
    ui->tableWidget->setColumnWidth(SET_VALUE_UNIT, 50);
    ui->tableWidget->setColumnWidth(SET_VALUE_FACTOR, 80);
    ui->tableWidget->setColumnWidth(SET_VALUE_OFFSET, 80);
    ui->tableWidget->setColumnWidth(SET_VALUE_COLOR, 80);
    ui->tableWidget->setColumnWidth(SET_VALUE_RELEVANCE, 100);

    ui->tableWidget->setAlternatingRowColors(true);//打开交替背景色
    ui->tableWidget->setStyleSheet("alternate-background-color: rgb(170, 255, 255);");//设置偶数行颜色
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑表格
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格为选择整行
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);//设置允许多个选中
    ui->tableWidget->verticalHeader()->setVisible(true); //显示垂直表头
    ui->tableWidget->horizontalHeader()->setVisible(true); //显示水平表头
    ui->tableWidget->setShowGrid(true);//显示表格线
    //ui->tableWidget->resizeColumnsToContents(); //设置行大小与内容匹配
    ui->tableWidget->resizeRowsToContents(); //设置列大小与内容匹配

//    //右键菜单槽：表头
//    ui->tableWidget->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(ui->tableWidget->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)),
//            this, SLOT(Header_contextmenu(const QPoint&)));//this是datatable所在窗口

//    //右键菜单槽：内容
//    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(const QPoint&)),
//            this, SLOT(Table_contextmenu(const QPoint&)));//this是datatable所在窗口
}

void SetValueDialog::fillColorList(QComboBox *cbb)//设置下拉框显示颜色
{
    QStringList colorNameList = QColor::colorNames();

    QString colorName;
    foreach(colorName,colorNameList)
    {
        QPixmap pix_color(70,20);
        pix_color.fill(QColor(colorName));

        cbb->addItem(QIcon(pix_color),NULL);
        cbb->setIconSize(QSize(70,20));
        cbb->setSizeAdjustPolicy(QComboBox::AdjustToContents);	//设置下拉列表的尺寸符合内容的大小
    }
}


void SetValueDialog::setData(ChartData* data, int num, ChartCfg cfg)
{
    if(num > 20)
    {
        num = 20;
    }

    //绘图数据信息
    QTableWidgetItem *item;
    QComboBox *comBox;
    QStringList *sList;

    chartDataNum = num;
    ui->tableWidget->setRowCount(chartDataNum);//设置行数
    for(int i = 0; i < num; i++)
    {
        m_chartData[i].vid = data[i].vid;
        memcpy(m_chartData[i].name, data[i].name, name_SIZE);
        memcpy(m_chartData[i].unit, data[i].unit, unit_SIZE);
        m_chartData[i].factor = data[i].factor;
        m_chartData[i].offset = data[i].offset;
        m_chartData[i].color = data[i].color;
        m_chartData[i].relevance = data[i].relevance;

        item = new QTableWidgetItem(QString::number(m_chartData[i].vid));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_VID, item);

        item = new QTableWidgetItem(m_chartData[i].name);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_NAME, item);

        item = new QTableWidgetItem(m_chartData[i].unit);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_UNIT, item);

        item = new QTableWidgetItem(QString::number(m_chartData[i].factor));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_FACTOR, item);

        item = new QTableWidgetItem(QString::number(m_chartData[i].offset));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_OFFSET, item);

        comBox = new QComboBox(ui->tableWidget);
        fillColorList(comBox);
        QStringList colorList = QColor::colorNames();
        QColor color((QRgb)(m_chartData[i].color | 0xFF000000));
        int index = 0;
        for(int i = 0; i < colorList.size(); i++)
        {
            QColor colorL(colorList[i]);
            if(colorL == color)
            {
                index = i;
            }
        }
        comBox->setCurrentIndex(index);
        ui->tableWidget->setCellWidget(i, SET_VALUE_COLOR, comBox);

        comBox = new QComboBox(ui->tableWidget);
        sList = new QStringList();
        *sList<<QString_C("YAxis")
              <<QString_C("YAxis2");
        comBox->addItems(*sList);
        comBox->setCurrentIndex(m_chartData[i].relevance);
        ui->tableWidget->setCellWidget(i, SET_VALUE_RELEVANCE, comBox);
    }

    //绘图配置信息
    m_chartCfg.ref_rate = cfg.ref_rate;
    m_chartCfg.onlyMode = cfg.onlyMode;
    memcpy(m_chartCfg.yAxis1, cfg.yAxis1, yAxis1_SIZE);
    memcpy(m_chartCfg.yAxis2, cfg.yAxis2, yAxis2_SIZE);
    ui->lineEdit_ref_rate->setText(QString::number(m_chartCfg.ref_rate));
    ui->checkBox_query_mode->setChecked(m_chartCfg.onlyMode);
    ui->lineEdit_yAxis1->setText(m_chartCfg.yAxis1);
    ui->lineEdit_yAxis2->setText(m_chartCfg.yAxis2);
}

void SetValueDialog::on_pushButton_set_chert_clicked()//设置数据个数
{
    int a = ui->lineEdit_chert_num->text().toInt();
    if(a < 0 || a > 20)
    {
        QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("输入数据错误！\n请重新输入。"), QMessageBox::Ok, this);
        msgBox.exec();
        return;
    }

    QTableWidgetItem *item;
    QComboBox *comBox;
    QStringList *sList;

    chartDataNum = a;
    ui->tableWidget->setRowCount(a);//设置行数
    for(int i = 0; i < a; i++)
    {
        if(ui->tableWidget->item(i, SET_VALUE_VID) != NULL
                && ui->tableWidget->item(i, SET_VALUE_VID)->text() != "")
        {
            continue;
        }

        item = new QTableWidgetItem(QString::number(m_chartData[i].vid));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_VID, item);

        item = new QTableWidgetItem(m_chartData[i].name);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_NAME, item);

        item = new QTableWidgetItem(m_chartData[i].unit);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_UNIT, item);

        item = new QTableWidgetItem(QString::number(m_chartData[i].factor));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_FACTOR, item);

        item = new QTableWidgetItem(QString::number(m_chartData[i].offset));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, SET_VALUE_OFFSET, item);

        comBox = new QComboBox(ui->tableWidget);
        fillColorList(comBox);
        QStringList colorList = QColor::colorNames();
        QColor color((QRgb)(m_chartData[i].color | 0xFF000000));
        int index = 0;
        for(int i = 0; i < colorList.size(); i++)
        {
            QColor colorL(colorList[i]);
            if(colorL == color)
            {
                index = i;
            }
        }
        comBox->setCurrentIndex(index);
        ui->tableWidget->setCellWidget(i, SET_VALUE_COLOR, comBox);

        comBox = new QComboBox(ui->tableWidget);
        sList = new QStringList();
        *sList<<QString_C("YAxis")
              <<QString_C("YAxis2");
        comBox->addItems(*sList);
        comBox->setCurrentIndex(m_chartData[i].relevance);
        ui->tableWidget->setCellWidget(i, SET_VALUE_RELEVANCE, comBox);
    }
}

void SetValueDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text() == "OK")
    {
        for(int i = 0; i < chartDataNum; i++)
        {
            if(ui->tableWidget->item(i, SET_VALUE_VID) != NULL
                    && ui->tableWidget->item(i, SET_VALUE_VID)->text() != ""
                    && ui->tableWidget->item(i, SET_VALUE_VID)->text().toUInt() < 0
                    && ui->tableWidget->item(i, SET_VALUE_VID)->text().toUInt() > 0)
            {
                QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("输入VID数据错误！\n请重新输入。"), QMessageBox::Ok, this);
                msgBox.exec();
                return;
            }

            m_chartData[i].vid = ui->tableWidget->item(i, SET_VALUE_VID)->text().toUInt();

            Str2Char(m_chartData[i].name, ui->tableWidget->item(i, SET_VALUE_NAME)->text(), name_SIZE);

            Str2Char(m_chartData[i].unit, ui->tableWidget->item(i, SET_VALUE_UNIT)->text(), unit_SIZE);

            m_chartData[i].factor = ui->tableWidget->item(i, SET_VALUE_FACTOR)->text().toDouble();

            m_chartData[i].offset = ui->tableWidget->item(i, SET_VALUE_OFFSET)->text().toDouble();

            QStringList colorList = QColor::colorNames();
            QColor color = QColor(colorList[((QComboBox*)ui->tableWidget->cellWidget(i, SET_VALUE_COLOR))->currentIndex()]);
            m_chartData[i].color = color.rgb() & 0xFFFFFF;

            m_chartData[i].relevance = ((QComboBox*)ui->tableWidget->cellWidget(i, SET_VALUE_RELEVANCE))->currentIndex();
        }
        m_chartCfg.ref_rate = ui->lineEdit_ref_rate->text().toInt();
        m_chartCfg.onlyMode = ui->checkBox_query_mode->checkState();
        isApply = true;
    }
    else if(button->text() == "Apply")
    {
        for(int i = 0; i < chartDataNum; i++)
        {
            if(ui->tableWidget->item(i, SET_VALUE_VID) != NULL
                    && ui->tableWidget->item(i, SET_VALUE_VID)->text() != ""
                    && ui->tableWidget->item(i, SET_VALUE_VID)->text().toUInt() < 0
                    && ui->tableWidget->item(i, SET_VALUE_VID)->text().toUInt() > 0)
            {
                QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("输入VID数据错误！\n请重新输入。"), QMessageBox::Ok, this);
                msgBox.exec();
                return;
            }

            m_chartData[i].vid = ui->tableWidget->item(i, SET_VALUE_VID)->text().toUInt();

            Str2Char(m_chartData[i].name, ui->tableWidget->item(i, SET_VALUE_NAME)->text(), name_SIZE);

            Str2Char(m_chartData[i].unit, ui->tableWidget->item(i, SET_VALUE_UNIT)->text(), unit_SIZE);

            m_chartData[i].factor = ui->tableWidget->item(i, SET_VALUE_FACTOR)->text().toDouble();

            m_chartData[i].offset = ui->tableWidget->item(i, SET_VALUE_OFFSET)->text().toDouble();

            QStringList colorList = QColor::colorNames();
            QColor color = QColor(colorList[((QComboBox*)ui->tableWidget->cellWidget(i, SET_VALUE_COLOR))->currentIndex()]);
            m_chartData[i].color = color.value();

            m_chartData[i].relevance = ((QComboBox*)ui->tableWidget->cellWidget(i, SET_VALUE_RELEVANCE))->currentIndex();
        }
        m_chartCfg.ref_rate = ui->lineEdit_ref_rate->text().toInt();
        m_chartCfg.onlyMode = ui->checkBox_query_mode->checkState();
        isApply = true;
    }
}
