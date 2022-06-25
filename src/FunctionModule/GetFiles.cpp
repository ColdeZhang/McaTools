//
// Created by Deer on 2022/6/20.
//

#include "GetFiles.h"

namespace McaTools {
    void GetFiles(const string &FilePath, vector<FileInfo> &Files, bool NeedFile, bool NeedDir) {

        // 打开目录，dir_ptr为句柄
        auto *dir_ptr = opendir(FilePath.c_str());
        if (dir_ptr == nullptr)
            cout << "[ERROR] Bad file path." << endl;

        // file_info存储获取到的文件信息
        struct dirent *file_info = nullptr;

        // 一行一行的读目录下的东西,这个东西的属性放到dirent的变量中
        while ((file_info = readdir(dir_ptr)) != nullptr) {
            // 忽略 "."
            if ((strcmp(file_info->d_name, ".") == 0)) continue;

            // 如果是根目录就忽略 ".."
            if ((strcmp(file_info->d_name, "..") == 0) && FilePath == "/") continue;

            // 添加目录
            if (file_info->d_type == DT_DIR && NeedDir) {
                auto oneFile = FileInfo{file_info->d_name, true};
                Files.push_back(oneFile);
            }

            // 添加文件
            if (file_info->d_type == DT_REG && NeedFile) {
                auto oneFile = FileInfo{file_info->d_name, false};
                Files.push_back(oneFile);
            }
        }
    }
} // McaTools