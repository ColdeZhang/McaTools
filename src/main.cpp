#include "include.h"
#include "BasicComponent/SingleIndexItem.h"
#include "BasicComponent/FormFileIndexContainer.h"
#include "FunctionModule/GetFiles.h"

#include "BasicComponent/FileIndexPicker.h"

int main() {
    using namespace ftxui;
    using namespace McaTools;

    std::string path = "/";

    auto contain = Container::Vertical({});

    contain = FormFileIndexContainer(path);

    auto rend = Renderer (contain, [&]{
        return vbox({
            text(path)
                | size(WIDTH, EQUAL, 30)
                | size(HEIGHT, EQUAL, 1),
            separator(),
            contain->Render()
                | vscroll_indicator
                | frame,
        }) | border;
    });

    rend = rend | size(WIDTH, LESS_THAN, 40);

    auto screen = ScreenInteractive::Fullscreen();

    screen.Loop(rend);


    return 0;
}
