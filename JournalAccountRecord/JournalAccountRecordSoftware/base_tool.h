#pragma once
class QString;
class BaseTool {
public:
    static bool copyFileToPath(QString sourceDir,
                               QString toDir, bool coverFileIfExist);
};
