from abc import abstractmethod, ABC

class Button(ABC):
    def __init__(self):
        self._clicked = False

    @abstractmethod
    def render(self):
        pass

    def on_click(self):
        self._clicked = not self._clicked

    @property
    def is_clicked(self) -> bool:
        return self._clicked

class Checkbox(ABC):
    def __init__(self):
        self._checked = False

    @abstractmethod
    def render(self):
        pass

    def toggle(self):
        self._checked = not self._checked

    @property
    def is_checked(self) -> bool:
        return self._checked

class WinButton(Button):
    def render(self):
        return "Windows Button"

class WinCheckbox(Checkbox):
    def render(self):
        return "Windows Checkbox"

class MacButton(Button):
    def render(self):
        return "MacOS Button"


class MacCheckbox(Checkbox):
    def render(self):
        return "MacOS Checkbox"

# Abstract Factory
class UIFactory(ABC):
    @abstractmethod
    def create_button(self) -> Button:
        pass

    @abstractmethod
    def create_checkbox(self) -> Checkbox:
        pass

class WinFactory(UIFactory):
    def create_button(self):
        return WinButton()

    def create_checkbox(self):
        return WinCheckbox()

class MacFactory(UIFactory):
    def create_button(self):
        return MacButton()

    def create_checkbox(self):
        return MacCheckbox()

# Usage

class Application:
    def __init__(self, factory: UIFactory):
        self._button = factory.create_button()
        self._checkbox = factory.create_checkbox()

    def render_ui(self):
        print(f"Rendering: {self._button.render()}")
        print(f"Rendering: {self._checkbox.render()}")

    def interact(self):
        self._button.on_click()
        self._checkbox.toggle()
        print(f"Button clicked status: {self._button.is_clicked}")
        print(f"Checkbox checked status: {self._checkbox.is_checked}")

if __name__ == '__main__':
    os_name = input("OS (Windows / MacOS): ")
    match os_name.lower():
        case "windows" | "win":
            factory = WinFactory()
        case "macos" | 'mac':
            factory = MacFactory()
        case _:
            raise NotImplementedError(f"OS '{os_name}' not supported")

    app = Application(factory)
    app.render_ui()
    app.interact()

