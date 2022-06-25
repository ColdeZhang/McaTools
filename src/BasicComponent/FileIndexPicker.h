//
// Created by Deer on 2022/6/20.
//

#ifndef MCATOOLS_FILEINDEXPICKER_H
#define MCATOOLS_FILEINDEXPICKER_H

#include "../include.h"
#include "../FunctionModule/GetFiles.h"
#include "SingleIndexItem.h"

namespace McaTools {

    /*!
     * @brief 生成一个文件选择器
     * @param path 目录地址
     * @return
     */
    ftxui::Component FileIndexPicker(std::string &path);

} // McaTools

#endif //MCATOOLS_FILEINDEXPICKER_H
