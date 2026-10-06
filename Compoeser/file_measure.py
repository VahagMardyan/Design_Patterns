from abc import ABC, abstractmethod
from pathlib import Path

class FileSystemComponent(ABC):
    @abstractmethod
    def get_size(self) -> float:
        pass

    @abstractmethod
    def display(self, indent: int = 0) -> None:
        pass

    @staticmethod
    def _format_size(size_in_bytes: float) -> str:
        for unit in ['B', 'KB', 'MB', 'GB', 'TB']:
            if size_in_bytes < 1024.0:
                return f"{size_in_bytes:.2f} {unit}"
            size_in_bytes /= 1024.0

        return f"{size_in_bytes:.2f} PB"

class File(FileSystemComponent):
    def __init__(self, path: Path):
        self.path = path

    def get_size(self) -> float:
        return float(self.path.stat().st_size)

    def display(self, indent : int = 0):
        spaces = " " * indent
        print(f"{spaces}📄 {self.path.name} ({FileSystemComponent._format_size(self.get_size())})")

class Folder(FileSystemComponent):
    def __init__(self, path: Path):
        self.path = path
        self.children : list[FileSystemComponent] = []

    def add(self, component: FileSystemComponent) -> None:
        self.children.append(component)

    def remove(self, component: FileSystemComponent) -> None:
        self.children.remove(component)

    def get_size(self) -> float:
        return sum(child.get_size() for child in self.children)

    def display(self, indent: int = 0):
        spaces = " " * indent
        print(f"{spaces}📁 {self.path.name}/ ({FileSystemComponent._format_size(self.get_size())})")

        for child in self.children:
            child.display(indent + 4)

    @classmethod
    def from_real_path(cls, path: Path) -> "Folder":
        folder = cls(path)

        for entry in path.iterdir():
            if entry.is_file():
                folder.add(File(entry))
            elif entry.is_dir():
                folder.add(cls.from_real_path(entry))

        return folder

path = Path('./')
root_folder = Folder.from_real_path(path)

root_folder.display()

