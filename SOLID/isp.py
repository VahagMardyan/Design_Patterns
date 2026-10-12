# Interface Segregation Principle

# Without ISP
from abc import ABC, abstractmethod

class Machine(ABC):
    @abstractmethod
    def print_document(self, document: str):
        pass

    @abstractmethod
    def scan_document(self, document: str):
        pass

class SimplePrinter(Machine):
    """
    This printer can only print documents, but it must have scan method too.
    """

    def print_document(self, document: str):
        print(f"Printing document {document}...")

    def scan_document(self, document: str):
        raise NotImplementedError("Scan not supported")

# With ISP
class Printer(ABC):
    @abstractmethod
    def print_document(self, document: str):
        pass

class Scanner(ABC):
    @abstractmethod
    def scan_document(self, document: str):
        pass

class SimplePrinter(Printer):
    def print_document(self, document):
        print(f"Printing: {document}...")

class MultiPrinter(Printer, Scanner):
    def print_document(self, document):
        print(f"Printing: {document}...")

    def scan_document(self, document):
        print(f"Scanning: {document}...")

# Usage

printer = SimplePrinter() 
printer.print_document("Report.pdf") 
device = MultiPrinter() 
device.print_document("Report.pdf")
device.scan_document("Report.pdf") 
