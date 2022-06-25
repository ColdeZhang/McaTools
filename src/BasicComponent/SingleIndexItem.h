//
// Created by Deer on 2022/6/19.
//

#ifndef MCATOOLS_SINGLEINDEXITEM_H
#define MCATOOLS_SINGLEINDEXITEM_H

#include "../include.h"

namespace McaTools {
    enum class IndexItemType {
        DIRECTORY,
        FILE
    };

    ftxui::Component OneIndexItem(
            const std::string& Name,
            std::function<void()> OnClick,
            IndexItemType Type);

} // McaTools

#endif //MCATOOLS_SINGLEINDEXITEM_H
