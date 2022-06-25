//
// Created by Deer on 2022/6/19.
//

#include "SingleIndexItem.h"

#include <utility>

namespace McaTools {

    ftxui::Component OneIndexItem(
            const std::string& Name,
            std::function<void()> OnClick,
            IndexItemType Type) {
        using namespace ftxui;
        class Impl : public ComponentBase {
        public:
            Impl(std::string Name, std::function<void()> OnClick, IndexItemType Type)
                    :  _name(std::move(Name)), _on_click(std::move(OnClick)), _type(Type){
                if (_type == IndexItemType::DIRECTORY)
                    _type_prefix = " > ";
                else if (_type == IndexItemType::FILE)
                    _type_prefix = "   ";
                else
                    _type_prefix = " ? ";
            }

            // Component implementation:
            Element Render() override {
                auto style = Focused() ? (Decorator(inverted) | focus) : nothing;
                return hbox({
                    text(_type_prefix),
                    text(_name),
                    }) | style
                    | color(Color::Grey11)
                    | bgcolor(Color::White)
                    | reflect(_box)
                    | size(Direction::HEIGHT, Constraint::EQUAL, 1);
            }

            bool OnEvent(Event event) override {
                if (event.is_mouse() && _box.Contain(event.mouse().x, event.mouse().y)) {
                    if (!CaptureMouse(event))
                        return false;

                    TakeFocus();

                    if (event.mouse().button == Mouse::Left &&
                        event.mouse().motion == Mouse::Pressed) {
                        _on_click();
                        return true;
                    }

                    return false;
                }

                if (event == Event::Return) {
                    _on_click();
                    return true;
                }
                return false;
            }

            bool Focusable() const final { return true; }

        private:
            std::function<void()> _on_click;
            std::string _name;
            IndexItemType _type;
            Box _box;
            std::string _type_prefix;
        };

        return Make<Impl>(Name, std::move(OnClick), Type);
    }

} // McaTools