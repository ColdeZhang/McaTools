//
// Created by Deer on 2022/6/20.
//

#include "FormFileIndexContainer.h"

namespace McaTools {
    std::vector<FileInfo> files;
    auto contain = ftxui::Container::Vertical({});

    ftxui::Component FormFileIndexContainer(std::string &path) {
        contain->DetachAllChildren();

        files.clear();
        GetFiles(path, files, false, true);

        for (auto &item : files) {
            auto oneFile = OneIndexItem(item.name, [&] {
                if (item.isDirectory){
                    if (item.name == "..")
                        path = path.substr(0, path.find_last_of('/'));
                    else
                        path += "/" + item.name;
                    contain = FormFileIndexContainer(path);
                }else{
                    path += item.name;
                }
            }, item.isDirectory ? McaTools::IndexItemType::DIRECTORY : McaTools::IndexItemType::FILE);
            contain->Add(oneFile);
        }

        return contain;
    }
} // McaTools