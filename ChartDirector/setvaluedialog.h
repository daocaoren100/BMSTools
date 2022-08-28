#ifndef SetValueDialog_H
#define SetValueDialog_H

#include <QDialog>
#include <QAbstractButton>
#include <QComboBox>

#define name_SIZE 20
#define unit_SIZE 20
typedef struct st_chartData{
    quint16 vid = 0;
    char name[name_SIZE];
    char unit[unit_SIZE];
    double factor = 1;
    double offset = 0;
    int color = 0x000000;
    int relevance = 0;
} ChartData;

#define yAxis1_SIZE 50
#define yAxis2_SIZE 50
typedef struct st_chartCfg{
    int ref_rate = 1000;//刷新频率(ms)
    char yAxis1[yAxis1_SIZE];
    char yAxis2[yAxis2_SIZE];
    bool onlyMode = false;
} ChartCfg;

#define Str2Char(chr, str, len)     {memset(chr, '\0', len);                \
                                    UINT size = str.toLocal8Bit().size();   \
                                    QByteArray byteA = str.toLocal8Bit();   \
                                    if(size > len)                          \
                                    {                                       \
                                        size = len - 2;                     \
                                    }                                       \
                                    memcpy(chr, byteA.data(), size);        \
                                    }

namespace Ui {
class SetValueDialog;
}

class SetValueDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetValueDialog(QWidget *parent = 0);
    ~SetValueDialog();

    void setData(ChartData* data, int num, ChartCfg cfg);

    bool isApply = false;
    int chartDataNum = 0;
    ChartData m_chartData[20];
    ChartCfg m_chartCfg;


private slots:
    void on_pushButton_set_chert_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::SetValueDialog *ui;

    void TableInit();
    void fillColorList(QComboBox *cbb);//设置下拉框显示颜色
};

#endif // SetValueDialog_H
