#include "smokehelper.h"
#include "ui_smokehelper.h"

SmokeHelper::SmokeHelper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmokeHelper)
{
    ui->setupUi(this);
    comboInit();
    selfInit();
    setWindowTitle("CSRM 可视化CFG部署工具");
}
SmokeHelper::~SmokeHelper()
{
    QDir *tempFile=new QDir("temp");
    tempFile->removeRecursively();
    delete ui;
}
QString SmokeHelper::getValueFromKey(QString Key){
    if(Key=="分号键") return QString("semicolon");
    if(Key=="飘号键") return QString("'");
    if(Key=="逗号键") return QString(",");
    if(Key=="斜杠键") return QString("/");
    if(Key==".(主键盘)") return QString(".");
    if(Key=="鼠标按键左键") return QString("mouse1");
    if(Key=="鼠标按键右键") return QString("mouse2");
    if(Key=="鼠标按键中键") return QString("mouse3");
    if(Key=="鼠标按键侧键4") return QString("mouse4");
    if(Key=="鼠标按键侧键5") return QString("mouse5");
    if(Key=="Tab") return QString("tab");
    if(Key=="回车") return QString("enter");
    if(Key=="ESC") return QString("esc");
    if(Key=="空格键") return QString("space");
    if(Key=="回车键") return QString("backspace");
    if(Key=="方向上") return QString("uparrow");
    if(Key=="方向下") return QString("downarrow");
    if(Key=="方向左") return QString("leftarrow");
    if(Key=="方向右") return QString("leftarrow");
    if(Key=="ALT") return QString("alt");
    if(Key=="CTRL") return QString("CTRL");
    if(Key=="SHIFT") return QString("shift");
    if(Key=="ins") return QString("INS");
    if(Key==".") return QString("del");
    if(Key=="PGUP") return QString("pgup");
    if(Key=="PGDN") return QString("PGDN");
    if(Key=="HOME") return QString("home");
    if(Key=="END") return QString("end");
    if(Key=="大小写锁") return QString("capslock");
    if(Key=="暂停键") return QString("pause");
    if(Key=="数字锁") return QString("NUMLOCK");
    if(Key=="/(小键盘)") return QString("kp_slash");
    if(Key=="*(小键盘)") return QString("kp_multiply");
    if(Key=="-(小键盘)") return QString("kp_minus");
    if(Key==".(小键盘)") return QString("kp_del");
    if(Key=="回车(小键盘)") return QString("kp_enter");
    if(Key=="0(小键盘)") return QString("kp_ins");
    if(Key=="1(小键盘)") return QString("kp_end");
    if(Key=="2(小键盘)") return QString("kp_downarrow");
    if(Key=="3(小键盘)") return QString("kp_pgdn");
    if(Key=="4(小键盘)") return QString("kp_leftarrow");
    if(Key=="5(小键盘)") return QString("kp_5");
    if(Key=="6(小键盘)") return QString("kp_rightarrow");
    if(Key=="7(小键盘)") return QString("kp_home");
    if(Key=="8(小键盘)") return QString("kp_uparrow");
    if(Key=="9(小键盘)") return QString("kp_pgup");
    if(Key=="默认开启道具轮盘页面") return QString("RadioPrefer_Grenade");
    if(Key=="默认开启CFG主页面") return QString("RadioPrefer_CFGMain");
    //
    if(Key=="默认不输出") return QString("OutputSwitcherNone");
    if(Key=="默认输出至队内聊天") return QString("OutputSwitcherTeam");
    if(Key=="默认输出至控制台,即仅自己可见") return QString("OutputSwitcherEcho");
    if(Key=="默认输出至所有人,包括对手,慎用") return QString("OutputSwitcherAll");
    //
    if(Key=="默认开启空格大跳") return QString("DuckJumpSwitcherOn");
    if(Key=="默认关闭空格大跳") return QString("DuckJumpSwitcherOff");
    //
    if(Key=="默认全向急停") return QString("IMStopSwitcherFull");
    if(Key=="默认无冲急停") return QString("IMStopSwitcherWC");
    if(Key=="默认仅双键急停") return QString("IMStopSwitcherDB");
    if(Key=="默认旧式急停") return QString("IMStopSwitcherOld");
    if(Key=="默认仅WS急停") return QString("IMStopSwitcherOnlyWS");
    if(Key=="默认不启用自动急停") return QString("IMStopSwitcherNone");
    //
    if(Key=="默认开启滚轮连跳增强") return QString("WJSwitcherOn");
    if(Key=="默认*仅按下空格时*开启滚轮连跳增强") return QString("WJSwitcherOnly");
    if(Key=="默认关闭滚轮连跳增强") return QString("WJSwitcherOff");
    //
    if(Key=="默认开启静步时禁用急停CFG") return QString("EnableShiftDeIMStop");
    if(Key=="默认关闭静步时禁用急停CFG") return QString("DisableShiftDeIMStop");
    //
    if(Key=="默认开启拆包时开火自动取消拆包") return QString("AttackDeDefuseSwitcherOn");
    if(Key=="默认关闭拆包时开火自动取消拆包") return QString("AttackDeDefuseSwitcherOff");
    //
    if(Key=="默认开启小键盘切换地图") return QString("SetKPMapOn");
    if(Key=="默认关闭小键盘切换地图") return QString("SetKPMapOff");

    return QString(Key);
}
QString SmokeHelper::generateCFGFile(){
    QString generateContent="";
    generateContent.append(QString("// === GEN BY SmokeHelper FROM ASULTOP ===\n"));
    generateContent.append(QString("alias StopGrenade \"sensitivity %1;m_yaw %2;m_pitch %3\" \n")
                               .arg(ui->sensitiveLine->text())
                               .arg(ui->yawLine->text())
                               .arg(ui->pitchLine->text()));
    generateContent.append(QString("bind %1 +Radio\n").arg(getValueFromKey(ui->LPTrigger->currentText())));
    // generateContent.append(QString("bind %1 +ResetAngleKey\n").arg(getValueFromKey(ui->LPReturn->currentText())));
    generateContent.append(QString("//修改 \"瞄准键\", 默认为 [ 键 (P键右侧)\n"
                                    "//修改 \"投掷键\", 默认为 ] 键 (P键右侧)\n"
                                    "//你需要修改下面 *所有的 [ 和 ] 符号*\n"
                                    "//除非你知道你在做什么, 请不要修改其他内容, 否则 CFG 会错误运行\n"
                                    "bind [ +GrenadeTask\n"
                                    "alias ClearThrow bind ] NoneAimedUse\n"
                                    "alias SetT bind ] +ST\n"
                                    "alias SetDBT bind ] +DBT\n"
                                    "alias SetJP bind ] +JPT\n"
                                    "alias SetFJP bind ] +FJPT\n"));
    generateContent.append(QString("bind %1 +RevS\n").arg(getValueFromKey(ui->PutSmoke->currentText())));
    generateContent.append(QString("bind [ +GrenadeTask\n"));

    generateContent.append(getValueFromKey(ui->CFGDefaultMain->currentText())+"\n");
    generateContent.append(QString("bind %1 ResetCFG\n").arg(getValueFromKey(ui->CFGClean->currentText())));
    generateContent.append(QString("bind %1 ResetRadioPage\n").arg(getValueFromKey(ui->CFGRetrunToMain->currentText())));
    //Output
    generateContent.append(getValueFromKey(ui->CFGDefaultOutputMode->currentText())+"\n");
    //DuckJump
    generateContent.append(getValueFromKey(ui->enableDuckjump->currentText())+"\n");
    //IMStop
    generateContent.append(getValueFromKey(ui->defaultMStop->currentText())+"\n");
    //DisableIMStop
    generateContent.append(QString("bind %1 +DisableIMStop\n").arg(getValueFromKey(ui->disableIMStop->currentText())));
    //ShifeDeIMStop
    generateContent.append(getValueFromKey(ui->disableShiftDeIMStop->currentText())+"\n");
    //AttackDeDefuse
    generateContent.append(getValueFromKey(ui->attackDeDefuseSwitcher->currentText())+"\n");
    //WJSwitcher
    generateContent.append(getValueFromKey(ui->defaultWJSwitcher->currentText())+"\n");
    //SetKPMap
    generateContent.append(getValueFromKey(ui->SetKPMapON->currentText())+"\n");
    //
    generateContent.append("bind MWHEELUP MWHEELUPTotal\n"
                            "bind MWHEELDOWN MWHEELDOWNTotal\n");
    //Shift
    generateContent.append(QString("bind %1 +ShiftTotal\n").arg(getValueFromKey(ui->CSShift->currentText())));
    //Ctrl
    generateContent.append(QString("bind %1 +CtrlTotal\n").arg(getValueFromKey(ui->CSDuck->currentText())));
    //Fire
    generateContent.append(QString("bind %1 +MOUSE1TOTAL\n").arg(getValueFromKey(ui->CSFire->currentText())));
    //1
    generateContent.append(QString("bind %1 +1Total\n").arg(getValueFromKey(ui->CS1->currentText())));
    //2
    generateContent.append(QString("bind %1 +2Total\n").arg(getValueFromKey(ui->CS2->currentText())));
    //3
    generateContent.append(QString("bind %1 +3Total\n").arg(getValueFromKey(ui->CS3->currentText())));
    //4
    generateContent.append(QString("bind %1 +4Total\n").arg(getValueFromKey(ui->CS4->currentText())));
    //5
    generateContent.append(QString("bind %1 +5Total\n").arg(getValueFromKey(ui->CS5->currentText())));
    //Q
    generateContent.append(QString("bind %1 +QTotal\n").arg(getValueFromKey(ui->CSQ->currentText())));
    //e
    generateContent.append(QString("bind %1 +ETotal\n").arg(getValueFromKey(ui->CSDefuse->currentText())));
    //w
    generateContent.append(QString("bind %1 +_forward\n").arg(getValueFromKey(ui->CSForward->currentText())));
    //a
    generateContent.append(QString("bind %1 +_left\n").arg(getValueFromKey(ui->CSLeft->currentText())));
    //s
    generateContent.append(QString("bind %1 +_back\n").arg(getValueFromKey(ui->CSBack->currentText())));
    //d
    generateContent.append(QString("bind %1 +_right\n").arg(getValueFromKey(ui->CSRight->currentText())));
    //space
    generateContent.append(QString("bind %1 +SpaceTotal\n").arg(getValueFromKey(ui->CSSpace->currentText())));
    /*
    //再次强调, 如果你不对下列内容进行修改, *完全可以* 正常使用, 代价是文字说明有可能会与你的个人设置不匹配
    alias NoneAimedUse "alias DoSayEchoWork echoln 请先按 [;alias DoSayAllWork say 请先按 [;alias DoSayTeamWork say_team 请先按 [;DoOutput"
    alias CFGGuide1 alias DoSayEchoWork "echoln 先按 [键 瞄准, 再按 ]键 投掷, 按 分号键 选择道具, 按 句号键 返回CFG主页面, 按 问号键 重置CFG, 按 引号键 进行视角回正+智能推荐(方便爆弹);"
    alias CFGGuide2 alias DoSayAllWork "say 先按 [键 瞄准, 再按 ]键 投掷, 按 分号键 选择道具, 按 句号键 返回CFG主页面, 按 问号键 重置CFG, 按 引号键 进行视角回正+智能推荐(方便爆弹);"
    alias CFGGuide3 alias DoSayTeamWork "say_team 先再按 [键 瞄准, 再按 ]键 投掷, 按 分号键 选择道具, 按 句号键 返回CFG主页面, 按 问号键 重置CFG, 按 引号键 进行视角回正+智能推荐(方便爆弹);"
    alias CFGGuideText "CFGGuide1;CFGGuide2;CFGGuide3;DoOutput"
    alias DeAlias_OutputForSetwait "alias DoSayEchoWork echoln 投掷物未指定, 请按 : 选择投掷物;alias DoSayAllWork say 投掷物未指定, 请按 : 选择投掷物;alias DoSayTeamWork say_team 投掷物未指定, 请按 : 选择投掷物;DoOutput"
    */
    generateContent.append(QString("//再次强调, 如果你不对下列内容进行修改, *完全可以* 正常使用, 代价是文字说明有可能会与你的个人设置不匹配\n"
                                   "alias NoneAimedUse \"alias DoSayEchoWork echoln 请先按 [;alias DoSayAllWork say 请先按 [;alias DoSayTeamWork say_team 请先按 [;DoOutput\"\n"
                                   "alias CFGGuide1 alias DoSayEchoWork \"echoln 先按 [键 瞄准, 再按 ]键 投掷, 按 分号键 选择道具, 按 句号键 返回CFG主页面, 按 问号键 重置CFG, 按 引号键 进行视角回正+智能推荐(方便爆弹);\"\n"
                                   "alias CFGGuide2 alias DoSayAllWork \"say 先按 [键 瞄准, 再按 ]键 投掷, 按 分号键 选择道具, 按 句号键 返回CFG主页面, 按 问号键 重置CFG, 按 引号键 进行视角回正+智能推荐(方便爆弹);\"\n"
                                   "alias CFGGuide3 alias DoSayTeamWork \"say_team 先再按 [键 瞄准, 再按 ]键 投掷, 按 分号键 选择道具, 按 句号键 返回CFG主页面, 按 问号键 重置CFG, 按 引号键 进行视角回正+智能推荐(方便爆弹);\"\n"
                                   "alias CFGGuideText \"CFGGuide1;CFGGuide2;CFGGuide3;DoOutput\"\n"
                                   "alias DeAlias_OutputForSetwait \"alias DoSayEchoWork echoln 投掷物未指定, 请按 : 选择投掷物;alias DoSayAllWork say 投掷物未指定, 请按 : 选择投掷物;alias DoSayTeamWork say_team 投掷物未指定, 请按 : 选择投掷物;DoOutput\"\n"
                                   )
                           );

    generateContent.append(QString("// === End ===\n"));
    return generateContent;
}
void SmokeHelper::comboInit(){

    ui->LPTrigger->addItems(addItms);
    ui->LPTrigger->setCurrentIndex(0);

    ui->LPReturn->addItems(addItms);
    ui->LPReturn->setCurrentIndex(1);

    ui->PutSmoke->addItems(addItms);
    ui->PutSmoke->setCurrentIndex(2);

    ui->CFGDefaultMain->addItems(addItmsforMain);
    ui->CFGDefaultMain->setCurrentIndex(1);

    ui->CFGClean->addItems(addItms);
    ui->CFGClean->setCurrentIndex(3);

    ui->CFGRetrunToMain->addItems(addItms);
    ui->CFGRetrunToMain->setCurrentIndex(4);

    ui->CFGDefaultOutputMode->addItems(addItmsforOutput);
    ui->CFGDefaultOutputMode->setCurrentIndex(1);

    ui->enableDuckjump->addItems(addItmsforDuckjump);
    ui->enableDuckjump->setCurrentIndex(1);

    ui->defaultMStop->addItems(addItmsforIMStop);
    ui->defaultMStop->setCurrentIndex(0);

    ui->defaultWJSwitcher->addItems(addItmsforWJSwitcher);
    ui->defaultWJSwitcher->setCurrentIndex(0);

    ui->disableIMStop->addItems(addItms);
    ui->disableIMStop->setCurrentIndex(28);

    ui->disableShiftDeIMStop->addItems(addItmsforShiftDeIMStop);
    ui->disableShiftDeIMStop->setCurrentIndex(1);

    ui->attackDeDefuseSwitcher->addItems(addItmsforAttackDeDefuse);
    ui->attackDeDefuseSwitcher->setCurrentIndex(0);

    ui->SetKPMapON->addItems(addItmsforKPMap);
    ui->SetKPMapON->setCurrentIndex(0);
    //
    ui->CSForward->addItems(addItms);
    ui->CSForward->setCurrentText("w");

    ui->CSBack->addItems(addItms);
    ui->CSBack->setCurrentText("s");

    ui->CSLeft->addItems(addItms);
    ui->CSLeft->setCurrentText("a");

    ui->CSRight->addItems(addItms);
    ui->CSRight->setCurrentText("d");

    ui->CSShift->addItems(addItms);
    ui->CSShift->setCurrentText("SHIFT");

    ui->CSDuck->addItems(addItms);
    ui->CSDuck->setCurrentText("CTRL");

    ui->CSSpace->addItems(addItms);
    ui->CSSpace->setCurrentText("空格键");

    ui->CSFire->addItems(addItms);
    ui->CSFire->setCurrentText("鼠标按键左键");

    ui->CS1->addItems(addItms);
    ui->CS1->setCurrentText("1");

    ui->CS2->addItems(addItms);
    ui->CS2->setCurrentText("2");

    ui->CS3->addItems(addItms);
    ui->CS3->setCurrentText("3");

    ui->CS4->addItems(addItms);
    ui->CS4->setCurrentText("4");

    ui->CS5->addItems(addItms);
    ui->CS5->setCurrentText("5");

    ui->CSQ->addItems(addItms);
    ui->CSQ->setCurrentText("q");

    ui->CSDefuse->addItems(addItms);
    ui->CSDefuse->setCurrentText("e");
}
void SmokeHelper::selfInit(){
    // steamPath
    QString regPath = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Classes\\steam\\Shell\\Open\\Command";
    QSettings *reg=new QSettings (regPath,QSettings::NativeFormat);
    steamPath = reg->value(".").toString();
    qDebug()<<QString(steamPath.split("\"")[1])+QString("\\..\\");
    steamPath =QString(steamPath.split("\"")[1])+QString("\\..\\");
    //

    //释放文件
    QDir GlobalDir(QDir::currentPath());
    if(!GlobalDir.exists("temp")){
        GlobalDir.mkdir("temp");
    }

    saveResourecFile("/","res.zip","temp\\res.zip");
    saveResourecFile("/","7z.dll","temp\\7z.dll");
    saveResourecFile("/","7z.exe","temp\\7z.exe");
    saveResourecFile("/","getPerfectPath.bat","C:\\getPerfectPath.bat");

    //获取到cfg目录
    QString libraryFoldersFile = steamPath + "/steamapps/libraryfolders.vdf";
    ui->CSPathLine->setText(getPath(libraryFoldersFile));
    //获取完美目录
    QProcess execBat;
    execBat.start("cmd.exe",QString("/c C:\\getPerfectPath.bat").split(" "));
    execBat.waitForFinished();

    QString perfectPath=execBat.readAllStandardOutput();
    bool perfectOnProcess=false;
    foreach(QString var,perfectPath.split("\n")){
        if(var.contains("perfectworldarena")) perfectPath=var,perfectOnProcess=true;
    }
    if(perfectOnProcess){
        // ui->perfectPathLine->setText();
        QString beforePath="";
        perfectPath=perfectPath.replace("\\","/");
        QStringList perfectPathSplitList=perfectPath.split("/");
        for(int i=0;i<perfectPathSplitList.length()-1;i++){

            beforePath.append(perfectPathSplitList[i]);
            beforePath.append("/");
        }
        beforePath=beforePath+"plugin/resource";
        ui->perfectPathLine->setText(beforePath);
    }else{
        QMessageBox::warning(this,"欸","完美未启动，请启动完美后再试");
    }

}

void SmokeHelper::on_relocateVersionButton_clicked()
{
    QString verPath = QFileDialog::getOpenFileName(this,"选择Smoke文件","./",tr("Smoke版本文件 (*.zip)"));
    if(!verPath.isEmpty()){
        versionPath=verPath;
        QStringList versionName=verPath.split("/");
        QString versionFileName;
        foreach (QString var,versionName){
            versionFileName=var;
        }

        ui->relocateVersionButton->setText(QString("已选择 %1").arg(versionFileName));
    }
}




void SmokeHelper::saveResourecFile(QString resProfiex,QString resFileName,QString destFullPathFileName) {

    //组装资源文件中的文件
    QString resFile;
    resFile=":/"+resProfiex+"/"+resFileName;

    QFile file;
    file.copy(resFile,destFullPathFileName);
}


bool SmokeHelper::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    toDir=toDir.replace("\\","/");
    sourceDir=sourceDir.replace("\\","/");
    QFile file(sourceDir);
    if (sourceDir == toDir){
        return true;
    }
    if (!file.exists()){
        return false;
    }
    QDir *createfile = new QDir;
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if
    if(!file.copy(toDir)){
        qDebug() << "Failed to copy file from" << sourceDir << "to" << toDir;
        qDebug() << "Error:" << file.errorString();
        return false;
    }
    return true;
}
// bool SmokeHelper::copyFileToPath(QString sourceDir, QString toDir, bool overwrite) {
//     QFile file(sourceDir);
//     if (!file.exists()) {
//         qDebug() << "Error: Source file does not exist.";
//         return false;
//     }

//     if (!file.copy(toDir)) {
//         QFile::remove(toDir); // 如果复制失败且目标文件已存在，可以选择删除它
//         qDebug() << "Error: Failed to copy file from" << sourceDir << "to" << toDir << ": " << file.errorString();
//         return false;
//     }

//     return true;
// }
bool SmokeHelper::UnCompressFiles(QString zipFile, QString sDestPath)
{
    QStringList sParams;
    sParams.append("x");												// 在当前目录中，使用完整路径从压缩档案中释放文件.或者到指定的输出文件夹
    sParams.append(zipFile);
    sParams.append(QString("-o%1").arg(sDestPath));						// 指定压缩文件格式
    sParams.append("-aoa");												// 不提示，直接覆盖同名文件

    QProcess process;
    QString strPath ="temp\\7z.exe";
    process.start(strPath, sParams);
    process.waitForFinished();
    QString A=process.readAllStandardError();
    QString B=process.readAllStandardOutput();
    qDebug()<<A;
    qDebug()<<B;
    process.close();
    return (A+B).isEmpty()?false:true;
}
SmokeHelper::returnMSG SmokeHelper::startSTH(QString command, bool Detach){
    QProcess *tmp=new QProcess();
    if(Detach){
        tmp->startDetached(command);
        return SmokeHelper::returnMSG().NothingReturn();
    }
    else{
        tmp->start(command);
        tmp->waitForFinished();
        SmokeHelper::returnMSG msg;
        msg.StandardOutput=tmp->readAllStandardOutput();
        msg.StandardError=tmp->readAllStandardError();
        return msg;
    }
}
QString SmokeHelper::getPath(QString vdfFile){
    QFile file(vdfFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString buffer(file.readAll());
    QString path;
    QStringList reader = buffer.split("\n");
    foreach(QString var,reader){
        if(var.contains("path")){
            path=var.split("\"")[3];
        }
        if(var.contains("730")) break;
    }

    //path -> steamapps -> common -> Counter-Strike Global Offensive ->game ->csgo -> cfg
    path=path.replace("\\\\","\\");
    path = path+"\\steamapps\\common\\Counter-Strike Global Offensive\\game\\csgo\\cfg";
    path.replace("\\","/");
    return path;
}

void SmokeHelper::on_locateCSPathButton_clicked()
{
    ui->CSPathLine->setText(QFileDialog::getExistingDirectory());
    qDebug()<<"CSPath="<<ui->CSPathLine->text();
}

void SmokeHelper::on_locatePerfectPathButton_clicked()
{
    ui->perfectPathLine->setText(QFileDialog::getExistingDirectory());
}
void SmokeHelper::on_replaceButton_clicked()
{
    if(ui->sensitiveLine->text().isEmpty()){
        QMessageBox::information(ui->replaceButton,tr("未完成"),tr("当前并未填写Sensitivity值"));
    }else if (ui->yawLine->text().isEmpty()){
        QMessageBox::information(ui->replaceButton,tr("未完成"),tr("当前并未填写m_yaw值"));
    }else if (ui->pitchLine->text().isEmpty()){
        QMessageBox::information(ui->replaceButton,tr("未完成"),tr("当前并未填写m_pitch值"));
    }else if(ui->CSPathLine->text().isEmpty()){
        QMessageBox::information(ui->replaceButton,tr("未完成"),tr("当前并未填写CFG目标位置"));
    }else{
        QStringList checkFileLocation=ui->CSPathLine->text().split("/");
        bool csgoDirOK=false,cfgDirOK=false;
        foreach(QString var,checkFileLocation){
            if(var=="csgo") csgoDirOK=true;
            if(var=="cfg") cfgDirOK=true;
        }
        if(!csgoDirOK||!cfgDirOK){
            QMessageBox::information(ui->replaceButton,tr("未完成"),tr("当前填写的CFG目标位置无效"));
        }else{
            checknap1=UnCompressFiles(versionPath,ui->CSPathLine->text());
            // QMessageBox::information(this,"",unZipProcess->readAllStandardError());
            // QMessageBox::information(this,"",unZipProcess->readAllStandardOutput());
            if(!ui->perfectPathLine->text().isEmpty()){
                QStringList checkPerfectLocation=ui->perfectPathLine->text().split("/");
                bool pluginDirOK=false,resourceDirOK=false;
                foreach(QString var,checkPerfectLocation){
                    if(var=="plugin") pluginDirOK=true;
                    if(var=="resource") resourceDirOK=true;
                }
                //解压resource到cfg/../resource
                checknap2=UnCompressFiles(ui->CSPathLine->text()+QString("/CSRM/resource.zip"),ui->CSPathLine->text()+"/../resource");

                // to do 待重构
                // //配置SmokeRegedit
                // QFile SmokeRegedit(ui->CSPathLine->text()+QString("/CSRM/SmokeRegedit.cfg"));
                // if (!SmokeRegedit.open(QIODevice::Append | QIODevice::Text)) {
                //     qDebug() << "Error:" << SmokeRegedit.errorString();
                //     return;
                // }
                // QTextStream outRegedit(&SmokeRegedit);
                // QString appendMix=QString("alias StopSmoke \"sensitivity %1;m_yaw %2;m_pitch %3\"")
                //                         .arg(ui->sensitiveLine->text())
                //                         .arg(ui->yawLine->text())
                //                         .arg(ui->pitchLine->text());
                // outRegedit<<Qt::endl<<appendMix<<Qt::endl;
                // SmokeRegedit.close();
                // qDebug()<<appendMix;

                //配置Preference.cfg
                QFile::remove(ui->CSPathLine->text()+QString("/CSRM/Preference.cfg"));

                QFile Preference(ui->CSPathLine->text()+QString("/CSRM/Preference.cfg"));
                if (!Preference.open(QIODevice::ReadWrite | QIODevice::Text)) {
                    qDebug() << "[Preference]Error:" << Preference.errorString();
                    return;
                }
                QTextStream outRegedit(&Preference);

                outRegedit<<Qt::endl<<generateCFGFile()<<Qt::endl;
                Preference.close();

                //配置AutoExec
                if(ui->autoExecMode->isChecked()){
                    QFile AutoExec(ui->CSPathLine->text()+"/autoexec.cfg");
                    if (!AutoExec.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        qDebug() << "[AutoExec]Error:" << AutoExec.errorString();
                        return;
                    }
                    QTextStream outAuto(&AutoExec);

                    if(!AutoExec.exists()){
                        QMessageBox::information(this,tr("欸"),"虽然你没有AutoExec文件\n但是我还是给你加进去了\n如需使用请添加AutoExec.cfg的启动项");
                    }
                    QString autoExecContext=AutoExec.readAll();
                    qDebug()<<autoExecContext;
                    if(!autoExecContext.contains("exec CSRM/Main")){

                        outAuto<<"//=== Created by SmokeHelper === SmokeHelper"<<Qt::endl<<"exec CSRM/Main"<<Qt::endl<<"//=== End SmokeHelper ==="<<Qt::endl;
                    }
                    AutoExec.close();
                }
                //检测+提示

                if(checknap1 && checknap2){
                    QMessageBox::information(this,tr("恭喜"),tr("成功配置 游戏内轮盘快捷键\n若无效请在控制台中输入\nexec CSRM\\Main"));
                }
                else{
                    QMessageBox::warning(this,tr("失败"),tr("联系Q群获取帮助"));
                }


                if(pluginDirOK && resourceDirOK){
                    qDebug()<<copyFileToPath(ui->CSPathLine->text()+QString("/CSRM/resource.zip"),ui->perfectPathLine->text()+"/resource.zip",true);
                }
                else QMessageBox::information(ui->replaceButton,tr("已完成"),tr("当前填写的完美平台resource目标位置无效\r\n但是我们完成了任务\r\n因为完美平台并不是必选项"));
            }
        }
    }
}
QString SmokeHelper::findLibraryPathForAppId(const QString &vdfContent, const QString &appId) {
    QString path;
    QRegularExpression regKey("\"path\"\\s+\"(.*?)\"");
    QRegularExpression regAppId("\"\\d+\"\\s+\"" + appId + "\"");

    bool inAppsSection = false;
    QString currentPath;

    QStringList lines = vdfContent.split('\n');
    for (const QString &line : lines) {
        if (line.trimmed().isEmpty() || line.startsWith("{") || line.endsWith("}")) {
            // 忽略空行或括号行
            continue;
        }

        if (line.contains("\"apps\"")) {
            inAppsSection = true;
            continue;
        }

        if (inAppsSection) {
            if (regAppId.match(line).hasMatch()) {
                // 找到了包含指定appId的行
                if (!currentPath.isEmpty()) {
                    // 如果之前已经找到了path，则返回它
                    return currentPath;
                }
            } else if (regKey.match(line).hasMatch()) {
                // 提取path值
                QRegularExpressionMatch match = regKey.match(line);
                if (match.hasMatch()) {
                    currentPath = match.captured(1);
                }
            }
        }
    }

    // 如果没有找到匹配的path，返回空字符串
    return path;
}





void SmokeHelper::on_DebugButton_clicked()
{
    QFile file("GenerateCFGDebugFile.asul");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Error:" << file.errorString();
        return;
    }
    QTextStream outRegedit(&file);
    outRegedit<<Qt::endl<<generateCFGFile()<<Qt::endl;
    file.close();
    qDebug()<<generateCFGFile();
}


void SmokeHelper::on_D2_clicked()
{
    QFile::remove("GenerateCFGDebugFile.asul");
}

