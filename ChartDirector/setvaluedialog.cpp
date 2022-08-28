#include "setvaluedialog.h"
#include "ui_setvaluedialog.h"

#include "../Core/Public.h"

enum setColumnList{
    SET_VALUE_VID = 0,  //vid
    SET_VALUE_NAME,     //����
    SET_VALUE_UNIT,     //��λ
    SET_VALUE_FACTOR,   //����
    SET_VALUE_OFFSET,   //ƫ����
    SET_VALUE_COLOR,    //��ɫ
    SET_VALUE_RELEVANCE,//����
    COLUMU_NUM          //������
};

SetValueDialog::SetValueDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetValueDialog)
{
    ui->setupUi(this);

    ui->tabWidget->setTabText(0, tr("Chart VID"));
    ui->tabWidget->setTabText(1, tr("Chart config"));

    //VID���ݳ�ʼ��
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
    ui->tableWidget->setColumnCount(COLUMU_NUM);//��������
    //ui->tableWidget_main->setRowCount(3000);//��������

    /*��������*/
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

    ui->tableWidget->setAlternatingRowColors(true);//�򿪽��汳��ɫ
    ui->tableWidget->setStyleSheet("alternate-background-color: rgb(170, 255, 255);");//����ż������ɫ
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//��ֹ�༭���
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//���ñ��Ϊѡ������
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);//����������ѡ��
    ui->tableWidget->verticalHeader()->setVisible(true); //��ʾ��ֱ��ͷ
    ui->tableWidget->horizontalHeader()->setVisible(true); //��ʾˮƽ��ͷ
    ui->tableWidget->setShowGrid(true);//��ʾ�����
    //ui->tableWidget->resizeColumnsToContents(); //�����д�С������ƥ��
    ui->tableWidget->resizeRowsToContents(); //�����д�С������ƥ��

//    //�Ҽ��˵��ۣ���ͷ
//    ui->tableWidget->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(ui->tableWidget->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)),
//            this, SLOT(Header_contextmenu(const QPoint&)));//this��datatable���ڴ���

//    //�Ҽ��˵��ۣ�����
//    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(const QPoint&)),
//            this, SLOT(Table_contextmenu(const QPoint&)));//this��datatable���ڴ���
}

void SetValueDialog::fillColorList(QComboBox *cbb)//������������ʾ��ɫ
{
    QStringList colorNameList = QColor::colorNames();

    QString colorName;
    foreach(colorName,colorNameList)
    {
        QPixmap pix_color(70,20);
        pix_color.fill(QColor(colorName));

        cbb->addItem(QIcon(pix_color),NULL);
        cbb->setIconSize(QSize(70,20));
        cbb->setSizeAdjustPolicy(QComboBox::AdjustToContents);	//���������б�ĳߴ�������ݵĴ�С
    }
}


void SetValueDialog::setData(ChartData* data, int num, ChartCfg cfg)
{
    if(num > 20)
    {
        num = 20;
    }

    //��ͼ������Ϣ
    QTableWidgetItem *item;
    QComboBox *comBox;
    QStringList *sList;

    chartDataNum = num;
    ui->tableWidget->setRowCount(chartDataNum);//��������
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

    //��ͼ������Ϣ
    m_chartCfg.ref_rate = cfg.ref_rate;
    m_chartCfg.onlyMode = cfg.onlyMode;
    memcpy(m_chartCfg.yAxis1, cfg.yAxis1, yAxis1_SIZE);
    memcpy(m_chartCfg.yAxis2, cfg.yAxis2, yAxis2_SIZE);
    ui->lineEdit_ref_rate->setText(QString::number(m_chartCfg.ref_rate));
    ui->checkBox_query_mode->setChecked(m_chartCfg.onlyMode);
    ui->lineEdit_yAxis1->setText(m_chartCfg.yAxis1);
    ui->lineEdit_yAxis2->setText(m_chartCfg.yAxis2);
}

void SetValueDialog::on_pushButton_set_chert_clicked()//�������ݸ���
{
    int a = ui->lineEdit_chert_num->text().toInt();
    if(a < 0 || a > 20)
    {
        QMessageBox msgBox(QMessageBox::Warning, QString_C("����"), QString_C("�������ݴ���\n���������롣"), QMessageBox::Ok, this);
        msgBox.exec();
        return;
    }

    QTableWidgetItem *item;
    QComboBox *comBox;
    QStringList *sList;

    chartDataNum = a;
    ui->tableWidget->setRowCount(a);//��������
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
                QMessageBox msgBox(QMessageBox::Warning, QString_C("����"), QString_C("����VID���ݴ���\n���������롣"), QMessageBox::Ok, this);
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
                QMessageBox msgBox(QMessageBox::Warning, QString_C("����"), QString_C("����VID���ݴ���\n���������롣"), QMessageBox::Ok, this);
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
