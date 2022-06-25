//
// Created by Deer on 2022/6/20.
//

#ifndef MCATOOLS_GETFILES_H
#define MCATOOLS_GETFILES_H

#include "../include.h"
#include <dirent.h>

using namespace std;

namespace McaTools {
    struct FileInfo {
        string name;
        bool isDirectory;
    };

    /*!
     * @brief 获取目录下文件列表
     * @param FilePath 目录路径
     * @param Files 返回的文件列表
     * @param NeedFile 是否需要文件
     * @param NeedDir 是否需要目录
     */
    void GetFiles(const string &FilePath,
                  vector<FileInfo> &Files,
                  bool NeedFile = true,
                  bool NeedDir = true);
} // McaTools

#endif //MCATOOLS_GETFILES_H
