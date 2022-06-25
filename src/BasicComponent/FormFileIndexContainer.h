//
// Created by Deer on 2022/6/20.
//

#ifndef MCATOOLS_FORMFILEINDEXCONTAINER_H
#define MCATOOLS_FORMFILEINDEXCONTAINER_H

#include "../FunctionModule/GetFiles.h"
#include "SingleIndexItem.h"

namespace McaTools {

    /*!
     * @brief 生成包含了文件列表的容器（Container）
     * @param path 目录路径
     */
    ftxui::Component FormFileIndexContainer(std::string &path);

} // McaTools

#endif //MCATOOLS_FORMFILEINDEXCONTAINER_H
