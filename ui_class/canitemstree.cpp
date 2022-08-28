//�󵼺���
#include "canitemstree.h"
#include "ui_canitemstree.h"

canItemsTree::canItemsTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canItemsTree)
{
    ui->setupUi(this);

#ifdef USE_LOCAL_FONT
    if(_USE_LOCAL_FONT == TRUE)
    {
        QString localFontString = loadFontFamilyFromTTF();
        QFont localFont;
        localFont.setFamily(localFontString);
        setFont(localFont);
    }
#endif

    ui->treeWidget->setStyleSheet("alternate-background-color: rgb(170, 255, 255);");//����ż������ɫ
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("BMS"));
    //ui->treeWidget->setHeaderHidden(true);
    treeRoot = new QTreeWidgetItem(ui->treeWidget, QStringList(QString_C("ȫ���豸")));
    treeRoot->setExpanded(true);

    m_batNum = 0;
    m_bsuNum = 0;
    m_nTimerID = startTimer(150);//�½���ʱ��
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *,int)), this, SLOT(slotItemClicked(QTreeWidgetItem *,int)));
}

canItemsTree::~canItemsTree()
{
    killTimer(m_nTimerID);
    delete ui;
}

void canItemsTree::timerEvent(QTimerEvent *)
{
    if ((m_batNum == g_pCommunicate->m_nBatNum) && (m_bsuNum == g_pCommunicate->m_nBsuNum))
    {
        return;
    }
    for (int i = (treeRoot->childCount() -1) ; i >=0 ; i--)
    {
        treeRoot->removeChild(treeRoot->child(i));
    }

    QTreeWidgetItem *treepLeaf1;
    QString str = "BMU";
    treepLeaf1 = new QTreeWidgetItem(treeRoot, QStringList(QString(str)));
    treepLeaf1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    treeRoot->addChild(treepLeaf1);
    QTreeWidgetItem *treepSubLeaf;
    str = "BAT";
    treepSubLeaf = new QTreeWidgetItem(treepLeaf1, QStringList(QString(str)));
    treepSubLeaf->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    treepLeaf1->addChild(treepSubLeaf);

    QTreeWidgetItem *treepLeafBTS;
    str = "BTS";
    treepLeafBTS = new QTreeWidgetItem(treeRoot, QStringList(QString(str)));
    treepLeafBTS->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    treeRoot->addChild(treepLeafBTS);
    //for(int i = 0; i < 25; i++)
    for(int i = 0; i < 5; i++)
    {
        //if(g_pCommunicate->b_Addr_state[100+i])
        {
            QTreeWidgetItem *treepSubLeafBTS;
            QString str = QString::number(i+1);
            str = str + "#BTS";
            treepSubLeafBTS = new QTreeWidgetItem(treepLeafBTS, QStringList(QString(str)));
            treepSubLeafBTS->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            treepLeafBTS->addChild(treepSubLeafBTS);
        }
    }

    m_batNum = g_pCommunicate->m_nBatNum;//�������
    m_bsuNum = g_pCommunicate->m_nBsuNum;//ÿ���ص�BSU����
    if (m_batNum != 0)    //�������
    {
        if (m_bsuNum != 0)  //ÿ���ص�BSU����
        {
            for (int i = 1 ; i <= m_batNum * m_bsuNum ; i++)
            {
                QTreeWidgetItem *treepLeaf;
                QString str = QString::number(i);
                str = str + "#BSU";
                treepLeaf = new QTreeWidgetItem(treeRoot, QStringList(QString(str)));
                treepLeaf->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                treeRoot->addChild(treepLeaf);

                QTreeWidgetItem *treepSubLeafBSU;
                str = "BSU";
                treepSubLeafBSU = new QTreeWidgetItem(treepLeaf, QStringList(QString(str)));
                treepSubLeafBSU->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                treepLeaf->addChild(treepSubLeafBSU);
                QTreeWidgetItem *treepSubLeafBSUVID;
                str = "BSU-VID";
                treepSubLeafBSUVID = new QTreeWidgetItem(treepLeaf, QStringList(QString(str)));
                treepSubLeafBSUVID->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                treepLeaf->addChild(treepSubLeafBSUVID);
                QTreeWidgetItem *treepSubLeafBSUPID;
                str = "BSU-PID";
                treepSubLeafBSUPID = new QTreeWidgetItem(treepLeaf, QStringList(QString(str)));
                treepSubLeafBSUPID->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                treepLeaf->addChild(treepSubLeafBSUPID);
            }
        }
    }
}

void canItemsTree::slotItemClicked(QTreeWidgetItem *item, int columns)
{
    //qDebug()<<"QTreeWidgetItem:"<<item->text(columns);
    QTreeWidgetItem *parent = item->parent();
    if(NULL==parent)  //ע�⣺�������û�и��ڵ�ģ�˫����Щ��ʱע��(����)
    {
        //qDebug()<<"QTreeWidgetItemcol:parent";
        emit sigSetCurrentBMU(-1 , 0 , 0);
        return;
    }
    QTreeWidgetItem *parentParent = parent->parent();
    int col = parent->indexOfChild(item);    //item�ڸ����еĽڵ��к�(��0��ʼ)
    if(NULL==parentParent)  //ע�⣺�������û�и��ڵ�ģ�˫����Щ��ʱע��(����)
    {
        //qDebug()<<"QTreeWidgetItemparentcol:parentParent"<<col;
        emit sigSetCurrentBMU(0 , col , -1);
        return;
    }
    int parentcol = parentParent->indexOfChild(parent);    //item�ڸ����еĽڵ��к�(��0��ʼ)
    //qDebug()<<"QTreeWidgetItemcol:"<<parentcol<<col;
    emit sigSetCurrentBMU(0 , parentcol , col);
}
