//
// Created by Deer on 2022/6/20.
//

#include "FileIndexPicker.h"

namespace McaTools {

    ftxui::Component FileIndexPicker(std::string &path){

        using namespace ftxui;

        class Impl : public ComponentBase {
        public:
            Impl(std::string &path) : _path(std::ref(path)) {
                FormFileIndexContainer();
            }

            Element Render() override{
                return vbox({
                    Input(&_path, _path)->Render(),
                    separator(),
                    Renderer(_list_container,[&]{
                        return _list_container->Render();
                    })->Render()
                        | vscroll_indicator
                        | frame
                        | size(HEIGHT, LESS_THAN, 10),
                }) | border;
            }

            void FormFileIndexContainer() {
                _list_container->DetachAllChildren();
                _files.clear();

                GetFiles(_path, _files, false, true);
                for (auto &item : _files) {
                    auto oneFile = OneIndexItem(item.name, [&] {
                        if (item.isDirectory){
                            if (item.name == "..")
                                _path = _path.substr(0, _path.find_last_of('/'));
                            else
                                _path = _path + "/" + item.name;
                            FormFileIndexContainer();
                        }else{
                            _path = _path + item.name;
                        }
                    }, item.isDirectory ? IndexItemType::DIRECTORY : IndexItemType::FILE);
                    _list_container->Add(oneFile);
                }
            }

        private:
            std::string _path;
            std::vector<FileInfo> _files;
            Component _list_container = Container::Vertical({});
        };

        return Make<Impl>(std::ref(path));
    }

} // McaTools