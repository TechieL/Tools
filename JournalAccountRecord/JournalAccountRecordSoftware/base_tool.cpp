#include "base_tool.h"
#include <QFile>
#include <QString>
#include <QDir>
bool BaseTool::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir createfile;
    bool exist = createfile.exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile.remove(toDir);
        }
    }//end if
    if(!QFile::copy(sourceDir, toDir))     {
        return false;
    }
    QFile f(toDir);
    f.setPermissions(QFile::WriteOwner);
    return true;
}
