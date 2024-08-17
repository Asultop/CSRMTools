#ifndef SMOKEHELPER_H
#define SMOKEHELPER_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QMap>
#include <QRegularExpression>
#include <QComboBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class SmokeHelper;
}
QT_END_NAMESPACE

class SmokeHelper : public QMainWindow
{
    Q_OBJECT

public:
    SmokeHelper(QWidget *parent = nullptr);
    ~SmokeHelper();
    struct returnMSG{
        QString StandardOutput,StandardError;
        returnMSG NothingReturn(){
            returnMSG msg;
            msg.StandardOutput="",msg.StandardError="";
            return msg;
        }
    };

private slots:
    void on_relocateVersionButton_clicked();

    void on_locateCSPathButton_clicked();

    void on_replaceButton_clicked();

    void on_locatePerfectPathButton_clicked();

    void on_DebugButton_clicked();

    void on_D2_clicked();

private:
    Ui::SmokeHelper *ui;
    void selfInit();
    void saveResourecFile(QString resProfiex,QString resFileName,QString destFullPathFileName);
    void comboInit();

    bool UnCompressFiles(QString zipFile, QString sDestPath);
    bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);

    returnMSG startSTH(QString command,bool DetachMode=false);
    QString steamPath;
    QString perfectPath;
    QString versionPath="temp\\res.zip";

    bool checknap1=false,checknap2=false;

    QString generateCFGFile();

    QString findLibraryPathForAppId(const QString &vdfContent, const QString &appId);
    QString getPath(QString vdfFile);
    QString getValueFromKey(QString Key);
    QStringList addItms=
        QString("分号键 "
                "飘号键 "
                "逗号键 "
                "斜杠键 "
                ".(主键盘) "
                "鼠标按键左键 "
                "鼠标按键右键 "
                "鼠标按键中键 "
                "鼠标按键侧键4 "
                "鼠标按键侧键5 "
                "Tab "
                "回车 "
                "ESC "
                "空格键 "
                "退格键 "
                "方向上 "
                "方向下 "
                "方向左 "
                "方向右 "
                "ALT "
                "CTRL "
                "SHIFT "
                "INS "
                ". "
                "PGUP "
                "PGDN "
                "HOME "
                "END "
                "大小写锁 "
                "暂停键 "
                "数字锁 "
                "/(小键盘) "
                "*(小键盘) "
                "-(小键盘) "
                ".(小键盘) "
                "回车(小键盘) "
                "0(小键盘) "
                "1(小键盘) "
                "2(小键盘) "
                "3(小键盘) "
                "4(小键盘) "
                "5(小键盘) "
                "6(小键盘) "
                "7(小键盘) "
                "8(小键盘) "
                "9(小键盘)").split(" ");
    QStringList addItmsforMain=QString("默认开启道具轮盘页面 默认开启CFG主页面").split(" ");
    QStringList addItmsforOutput=QString("默认不输出 默认输出至队内聊天 默认输出至控制台,即仅自己可见 默认输出至所有人,包括对手,慎用").split(" ");
    QStringList addItmsforDuckjump=QString("默认开启空格大跳 默认关闭空格大跳").split(" ");
    QStringList addItmsforIMStop=QString("默认全向急停 默认无冲急停 默认旧式急停 默认仅双键急停 默认仅WS急停 默认不启用自动急停").split(" ");
    QStringList addItmsforWJSwitcher=QString("默认开启滚轮连跳增强 默认*仅按下空格时*开启滚轮连跳增强 默认关闭滚轮连跳增强").split(" ");

    QStringList addItmsforShiftDeIMStop=QString("默认开启静步时禁用急停CFG 默认关闭静步时禁用急停CFG").split(" ");
    QStringList addItmsforAttackDeDefuse=QString("默认开启拆包时开火自动取消拆包 默认关闭拆包时开火自动取消拆包").split(" ");
    QStringList addItmsforKPMap=QString("默认开启小键盘切换地图 默认关闭小键盘切换地图").split(" ");


};
#endif // SMOKEHELPER_H
